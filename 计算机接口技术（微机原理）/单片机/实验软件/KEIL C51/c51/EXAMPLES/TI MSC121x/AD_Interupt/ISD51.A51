$NOMOD51    
;------------------------------------------------------------------------------
;  ISD51  In-System Debugger for 8051 based microcontrollers
;  Copyright KEIL ELEKTRONIK GmbH and Keil Software, Inc. 2000 - 2003
;  Version 2.05
;------------------------------------------------------------------------------
;  ISD51.A51:  This module needs to be added to the user application
;
;  Copy this file to your project folder and add the copy to your uVision2
;  project.  You can customize several parameters of the ISD51 In-System 
;  Monitor within this configuration file.
;
;  ISD51 V2.00: added new features like user I/O and hardware breakpoints.
;  ISD51 V2.02: fixed a problem when single stepping through putchar
;
;  ISD51 V2.03: adapted for TI AUX Interupt (EAI Bit save/restore added)
;  ISD51 V2.04: 'Stop' command did not break program execution on targets that
;               do not have hardware breakpoints
;  ISD51 V2.05: when ISD51 is not started, getkey return value was not in R7.
;------------------------------------------------------------------------------

#include "ISD51.H"   /* ISD51 Configuration Parameters */

;------------------------------------------------------------------------------
;----------------- !!! Do not modify code sections below !!! ------------------
;------------------------------------------------------------------------------

NAME ISD51_CONFIGURATION


SBYTE    MACRO             ; Transmit Byte in ACC via serial UART
         JNB_TI $
         CLR_TI
         WR_SBUF           ; MOV SBUF,A
         ENDM

RBYTE    MACRO             ; Read one Byte from serial UART to ACC
         RD_SBUF           ; MOV A,SBUF
         CLR_RI
         ENDM

GBYTE    MACRO             ; Receive one Character from 8051 Serial Interface
         JNB_RI $
         RBYTE
         ENDM


/* 8051 SFR Register addresses */
sfr P0     = 0x80;
sfr P1     = 0x90;
sfr P2     = 0xA0;
sfr P3     = 0xB0;
sfr PSW    = 0xD0;
sfr ACC    = 0xE0;
sfr B      = 0xF0;
sfr SP     = 0x81;
sfr DPL    = 0x82;
sfr DPH    = 0x83;
sfr AUXR   = 0x8E;
sfr PH_FMCON  = 0xE4;  // for Philips LPC900 devices
sfr PH_FMADRL = 0xE6;  // for Philips LPC900 devices


?ISD?RAMTOP     EQU     RAMSIZE-1
?ISD?CMP_S      EQU     CMP_START
?ISD?CMP_E      EQU     CMP_END

EXTRN NUMBER (?ISD?CORE)

PUBLIC ?ISD?RAMTOP
PUBLIC ?ISD?RESTART
PUBLIC ?ISD?CMDLOOP
PUBLIC ?ISD?GETBYTE
PUBLIC ?ISD?SENDBYTE
PUBLIC ?ISD?READSFR00
PUBLIC ?ISD?READSFR01
PUBLIC ?ISD?READSFR02
PUBLIC ?ISD?READSFR03
PUBLIC ?ISD?READSFR04
PUBLIC ?ISD?READSFR05
PUBLIC ?ISD?READSFR06
PUBLIC ?ISD?READSFR07
PUBLIC ?ISD?READSFR08
PUBLIC ?ISD?READSFR09
PUBLIC ?ISD?READSFR10
PUBLIC ?ISD?READSFR11
PUBLIC ?ISD?READSFR12
PUBLIC ?ISD?READSFR13
PUBLIC ?ISD?READSFR14
PUBLIC ?ISD?READSFR15
PUBLIC ?ISD?READSFR16
PUBLIC ?ISD?READSFR17
PUBLIC ?ISD?READSFR18
PUBLIC ?ISD?WRITESFR00
PUBLIC ?ISD?WRITESFR01
PUBLIC ?ISD?WRITESFR02
PUBLIC ?ISD?WRITESFR03
#ifdef PHILIPS_LPC900
PUBLIC ?ISD?WRITESFR04
PUBLIC ?ISD?WRITESFR05
#endif
PUBLIC ?ISD?VERSION
PUBLIC ?ISD?CMP_S
PUBLIC ?ISD?CMP_E
PUBLIC __isd_init


PUBLIC ?ISD?CBLK_SIZE  ; block size for FLASH IAP Routine

?ISD?CBLK_SIZE  EQU     CBLK_SZ
CBLK            EQU     10H             ; Start address for FLASH buffer

?ISD?VERSION    EQU     204             ; Version 2.04

#ifdef TI_MSC1210                       // added for TI MSC121x
?BI?ISD51       SEGMENT BIT
                RSEG    ?BI?ISD51
SaveEAI:        DBIT    1               ; Save TI AUX Interrupt Enable bit
#endif                                  // for TI MSC121x


?PR?ISD51       SEGMENT CODE INBLOCK

                CSEG AT SINTRVEC    ; Serial Interrupt
                LJMP    SerialInterrupt


#ifdef TI_MSC1210_BREAKS
;-------- Chip Specific Break Features -----------------------
PUBLIC          ?ISD?HWBREAKS
PUBLIC          ?ISD?SETHWBREAK

BREAK_CODE      EQU     0x8000
BREAK_XDATA     EQU     0x4000

?ISD?HWBREAKS   EQU     (BREAK_CODE OR BREAK_XDATA) + 2

BPCTRL          DATA    0A9H  ; BPCTRL.7  := breakpoint interrupt request
                              ; BPCTRL.1  := 0=code break, 1=xdata break
                              ; BPCTRL.0  := breakpoint enable 
BREAKL          DATA    0AAH  ; break low  address
BREAKH          DATA    0ABH  ; break high address
MEMCTRL         DATA    095H  ; MEMCTRL.7 := breakpoint select
PIREG           DATA    096H  ; PIREG.0   := breakpoint interrupt enable
EICON           DATA    0D8H  ; Extended Interrupt CONtrol register
PFI             BIT     0DCH  ; Interrupt Request Flag for power fail and debug

                CSEG    AT    33H       ; interupt vector for breakpoints
                LJMP    HWBreakEntry


                RSEG    ?PR?ISD51
                USING   0               ; Assume Registerbank 0 for ARx symbols

; Entry Point for HW Breakpoint
HWBreakEntry:   PUSH    PSW
                PUSH    ACC
                MOV     A,BPCTRL
                JB      ACC.7,HWBreakpoint
                POP     ACC
                POP     PSW
                LJMP    06BH            ; Other interrupt sources such as A/D Converter
                                        ; SPI, PFI and (milli)second timer sharing the 
                                        ; interrupt vector at address 33H must be 
                                        ; relocated to address 6BH (interrupt 13)!

HWBreakpoint:   MOV     PSW,#0          ; Select Register Bank 0
                PUSH    AR0
                PUSH    AR1
                MOV     A,MEMCTRL       ; Get Breakpoint reason
                RLC     A
                MOV     A,#0F8H/2
                RLC     A               ; 0F8H->Break 0, 0F9H->Break 1
                ORL     BPCTRL,#80H     ; Clear Breakpoint interrupt
                CLR     PFI
                SET_TI
                SJMP    Send7Bytes

;--------------------------------------------------------------------------
; Command: Set Hardware Break Register
;  LOW (?ISD?SETHWBREAK), HIGH (?ISD?SETHWBREAK), BPcode, LOW (bp_addr), HIGH (bp_addr)
;     BPcode.0..2  :=  select hardware break register 0..7
;     BPcode.3     :=  reserved, currently set to 0
;     BPcode.4     :=  0  disable breakpoint,  1 enable breakpoint
;     BPcode.5     :=  0  xdata breakpoint,    1 code   breakpoint
;     BPcode.6     :=  reserved, currently set to 0
;     BPcode.7     :=  reserved, currently set to 0
              
?ISD?SETHWBREAK:
                XCH     A,R0
                SWAP    A
                ORL     MEMCTRL,#80H    ; BPSEL=1; select hw breakpoint 1
                JBC     ACC.4,SelectHWbp1
                ANL     MEMCTRL,#7FH    ; BPSEL=0; select hw breakpoint 0
SelectHWbp1:    XCH     A,R0
                MOV     BPCTRL,#80H     ; disable breakpoint, clear pending breakpoints
                MOV     BREAKL,A
                ACALL   ?ISD?GETBYTE
                MOV     BREAKH,A
                MOV     BPCTRL,R0
                AJMP    ?ISD?CMDLOOP
;--------------------------------------------------------------------------
#endif


                RSEG    ?PR?ISD51
                USING   0               ; Assume Registerbank 0 for ARx symbols

#if CBLK_SZ != 0                        /* Hareware Breakpoints */
PUBLIC ?ISD?HWCALL
?ISD?HWCALL:    PUSH    PSW
                PUSH    ACC
                MOV     A,#0FDH         ; Call Break
                SJMP    CallBreak        
#endif

SerialInterrupt:
                PUSH    PSW
                PUSH    ACC
                JNB_RI  NoSerBreak
                RBYTE                        ; Check for 0A5H Break Code
#if ISD_GETKEY
                MOV     _ISD_CHAR,A
#endif
                CJNE    A,#0A5H,ReturnI
#if CBLK_SZ == 0                        /* Software Breakpoints */
                SET_TI
                MOV     PSW,#0          ; Select Register Bank 0
                PUSH    AR0
                PUSH    AR1
                SJMP    SoftBreak
#endif
NoSerBreak:     MOV     A,#0FFH
CallBreak:      MOV     PSW,#0          ; Select Register Bank 0
                PUSH    AR0
                PUSH    AR1
                MOV     R0,#?ISD?RAMTOP
#if CBLK_SZ == 0                        /* Software Breakpoints */
                MOV     AR0,@R0         ; Load Start Address of Break Table
                CJNE    R0,#0xFF,CheckBreaks
#else                                   /* Hardware Breakpoints */
                JBC     EA,ChkEA
                ANL     A,#0FBH
ChkEA:          
#ifdef TI_MSC1210                       // added for TI MSC121x
EAI             BIT     0DDH            ; Enable bit for AUX Interrupt
                SETB    SaveEAI
                JBC     EAI,ChkEAI
                CLR     SaveEAI
ChkEAI:         
#endif                                  // for TI MSC121x
                MOV     @R0,A
                SET_TI
#endif
; Called when a Breakpoint is reached or in Single Stepping Mode

; Sends Break-Idenfier, R0, ACC, PSW, PCH, PCL, R1
#if CBLK_SZ == 0                        /* Software Breakpoints */
SoftBreak:      MOV     A,#0F7H         ; Send Idenifier
#endif
Send7Bytes:     SBYTE                   ; Send Byte
                POP     AR1
                MOV     R0,#5
SendStackFrame: POP     ACC
                ACALL   ?ISD?SENDBYTE
                DJNZ    R0,SendStackFrame
                MOV     A,R1
?ISD?CMDLOOP2:  ACALL   ?ISD?SENDBYTE

; Wait for Command
;  CmdAddrL, CmdAddrH, R0, ACC

?ISD?CMDLOOP:   ACALL   ?ISD?GETBYTE            ; Command Address
                PUSH    ACC
                ACALL   ?ISD?GETBYTE
                PUSH    ACC
                ACALL   ?ISD?GETBYTE
                MOV     R0,A
;;;             ACALL   ?ISD?GETBYTE
;;;             RET

?ISD?GETBYTE:   GBYTE
                RET

#if CBLK_SZ == 0                        /* Software Breakpoints */
; Check Soft Breaks in Memory
CheckBreaks:    MOV     A,SP
                ADD     A,#-4
                MOV     R1,A            ; Address to PCH/PCL
                SJMP    CheckBreak1
CheckBreak:     INC     R0
                DEC     R1
                MOV     A,@R0           ; Compare Low Part
                XRL     A,@R1
                INC     R0
                INC     R1
                JNZ     CheckBreak1
                MOV     A,@R0           ; Compare High Part
                XRL     A,@R1
                JZ      SoftBreak
CheckBreak1:    CJNE    R0,#?ISD?RAMTOP-1,CheckBreak

                POP     AR1
RestartUser:    POP     AR0
#endif

ReturnI:        POP     ACC
                POP     PSW
                RETI



?ISD?SENDBYTE:  SBYTE
                RET

;--------------------------------------------------------------------------
; Command: Restart User Program
;  LOW (?ISD?RESTART), HIGH (?ISD?RESTART), R0, PCL, PCH, PSW, R1, ACC
;
;
?ISD?RESTART:   PUSH    ACC          ; PCL Content of User Program
                ACALL   ?ISD?GETBYTE
                PUSH    ACC          ; PCH Content of User Program
                ACALL   ?ISD?GETBYTE
                PUSH    ACC          ; PSW Content of User Program
                ACALL   ?ISD?GETBYTE
                MOV     R1,A         ; R1  Content of User Program
                ACALL   ?ISD?GETBYTE ; ACC Content of User Program
                PUSH    ACC
                PUSH    AR0
                MOV     R0,#?ISD?RAMTOP
                MOV     A,@R0
#if CBLK_SZ != 0                        /* Flash Breakpoints */
                SET_ES      
                POP     AR0
                RRC     A        
                JNC     StepMode
                CLR_TI               ; Go Mode

#ifdef TI_MSC1210                    // added for TI MSC121x
                MOV     C,SaveEAI
                MOV     EAI,C
                RRC     A
                JNC     RetMode
                POP     ACC
                POP     PSW
                SETB    EA
                RETI
StepMode:       RRC     A
                JNC     StepModeRet
                POP     ACC
                MOV     C,SaveEAI
                MOV     EAI,C
                POP     PSW
                SETB    EA
                RETI

StepModeRet:    POP     ACC
                MOV     C,SaveEAI
                MOV     EAI,C
                POP     PSW
                SETB    EA
                RET
#else
StepMode:       RRC     A
                JNC     RetMode
                POP     ACC
                POP     PSW
                SETB    EA
                RETI
#endif                               // end for TI MSC121x

RetMode:        RRC     A
                POP     ACC
                JNC     EAClr
                POP     PSW
                SETB    EA
                RET

EAClr:          POP     PSW
                RET
#else
                JNZ     RestartSS
                CLR_TI
RestartSS:      AJMP    RestartUser
#endif

;--------------------------------------------------------------------------;
; Insert HW Breakpoints
#if CBLK_SZ != 0                        /* Hareware Breakpoints */

; Command: Write IData Memory Bytes
;  LOW (?ISD?WR_IMEMN), HIGH (?ISD?WR_IMEMN), Adr, Cnt, ContBytes [...]
PUBLIC ?ISD?WR_IMEMN
?ISD?WR_IMEMN:  MOV     R1,A
IMEM2LOOP:      ACALL   ?ISD?GETBYTE
                MOV     @R0,A
                INC     R0
                DJNZ    R1,IMEM2LOOP
                AJMP    ?ISD?CMDLOOP


;--------------------------------------------------------------------------
; Command: Write Code Flash
;  LOW (?ISD?WR_FLASH), HIGH (?ISD?WR_FLASH), FlashAdrL, FlashAdrH
PUBLIC ?ISD?WR_FLASH
?ISD?WR_FLASH:  CWRITE
                AJMP    ?ISD?CMDLOOP2

#endif
;--------------------------------------------------------------------------
; Command: Write SFR DPL, DPH
;  LOW (?ISD?WRITESFR00), HIGH (?ISD?WRITESFR00), DPL, DPH
;
;
?ISD?WRITESFR00:
                MOV     DPL,R0
                MOV     DPH,A
                AJMP    ?ISD?CMDLOOP

;--------------------------------------------------------------------------
; Command: Write SFR SP, B
;  LOW (?ISD?WRITESFR01), HIGH (?ISD?WRITESFR01), SP, B
;
?ISD?WRITESFR01:
                MOV     SP,R0
                MOV     B,A
                AJMP    ?ISD?CMDLOOP

;--------------------------------------------------------------------------
; Command: Write SFR02:  P0
;  LOW (?ISD?WRITESFR02), HIGH (?ISD?WRITESFR02), dummy, P0
;
?ISD?WRITESFR02:
                MOV     P0,A
                AJMP    ?ISD?CMDLOOP

;--------------------------------------------------------------------------
; Command: Write SFR03:  P3
;  LOW (?ISD?WRITESFR03), HIGH (?ISD?WRITESFR03), dummy, P3
;
?ISD?WRITESFR03:
                MOV     P3,A
                AJMP    ?ISD?CMDLOOP

#ifdef PHILIPS_LPC900
;--------------------------------------------------------------------------
; Command: Write SFR04:  FMCON
;  LOW (?ISD?WRITESFR04), HIGH (?ISD?WRITESFR04), dummy, FMCON
;
?ISD?WRITESFR04:
                MOV     PH_FMCON,A
                AJMP    ?ISD?CMDLOOP

;--------------------------------------------------------------------------
; Command: Write SFR05:  FMADRL
;  LOW (?ISD?WRITESFR05), HIGH (?ISD?WRITESFR05), dummy, FMADRL
;
?ISD?WRITESFR05:
                MOV     PH_FMADRL,A
                AJMP    ?ISD?CMDLOOP
#endif

;--------------------------------------------------------------------------
; 0 Read CPU Core SFR registers:
;  LOW (?ISD?READCORESFR), HIGH (?ISD?READCORESFR), dummy, dummy
;  Sends: dummy, dummy, B, AUXR, DPL, DPH, SP
?ISD?READSFR00: MOV     A,SP
                PUSH    DPH
                PUSH    DPL
                PUSH    AUXR
                PUSH    B
                PUSH    ACC   ; Dummy
                PUSH    ACC   ; Dummy
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 1 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR01), HIGH (?ISD?READSFR01), dummy, dummy
;  Sends: S:80, S:84, S:85, S:86, S:87, S:88, S:89
;   
?ISD?READSFR01:
                MOV     A,0x89  ; S:89
                PUSH    0x88    ; S:88
                PUSH    0x87
                PUSH    0x86
                PUSH    0x85
                PUSH    0x84
                PUSH    0x80
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 2 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR02), HIGH (?ISD?READSFR02), dummy, dummy
;  Sends: S:8A, S:8B, S:8C, S:8D, S:8E, S:8F, S:90
;  
?ISD?READSFR02:
                MOV     A,0x90
                PUSH    0x8F    
                PUSH    0x8E
                PUSH    0x8D
                PUSH    0x8C
                PUSH    0x8B
                PUSH    0x8A
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 3 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR03), HIGH (?ISD?READSFR03), dummy, dummy
;  Sends: S:91, S:92, S:93, S:94, S:95, S:96, S:97
;   
?ISD?READSFR03:
                MOV     A,0x97
                PUSH    0x96    
                PUSH    0x95
                PUSH    0x94
                PUSH    0x93
                PUSH    0x92
                PUSH    0x91
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 4 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR04), HIGH (?ISD?READSFR04), dummy, dummy
;  Sends: S:8A, S:8B, S:8C, S:8D, S:8E, S:8F, S:90
;  
?ISD?READSFR04:
                MOV     A,0x9E
                PUSH    0x9D    
                PUSH    0x9C
                PUSH    0x9B
                PUSH    0x9A
                PUSH    0x99
                PUSH    0x98
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 5 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR05), HIGH (?ISD?READSFR05), dummy, dummy
;  
?ISD?READSFR05:
                MOV     A,0xA5
                PUSH    0xA4    
                PUSH    0xA3
                PUSH    0xA2
                PUSH    0xA1
                PUSH    0xA0
                PUSH    0x9F
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 6 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR06), HIGH (?ISD?READSFR06), dummy, dummy
;  
?ISD?READSFR06:
                MOV     A,0xAC
                PUSH    0xAB    
                PUSH    0xAA
                PUSH    0xA9
                PUSH    0xA8
                PUSH    0xA7
                PUSH    0xA6
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 7 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR07), HIGH (?ISD?READSFR07), dummy, dummy
;  
?ISD?READSFR07:
                MOV     A,0xB3
                PUSH    0xB2    
                PUSH    0xB1
                PUSH    0xB0
                PUSH    0xAF
                PUSH    0xAE
                PUSH    0xAD
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 8 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR08), HIGH (?ISD?READSFR08), dummy, dummy
;  
?ISD?READSFR08:
                MOV     A,0xBA
                PUSH    0xB9    
                PUSH    0xB8
                PUSH    0xB7
                PUSH    0xB6
                PUSH    0xB5
                PUSH    0xB4
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
; 9 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR09), HIGH (?ISD?READSFR09), dummy, dummy
;  
?ISD?READSFR09:
                MOV     A,0xC1
                PUSH    0xC0    
                PUSH    0xBF
                PUSH    0xBE
                PUSH    0xBD
                PUSH    0xBC
                PUSH    0xBB
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;10 Read CPU Core SFR registers:
;  LOW (?ISD?READSFRC8), HIGH (?ISD?READSFRC8), dummy, dummy
;  
?ISD?READSFR10:
                MOV     A,0xC8
                PUSH    0xC7    
                PUSH    0xC6
                PUSH    0xC5
                PUSH    0xC4
                PUSH    0xC3
                PUSH    0xC2
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;11 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR11), HIGH (?ISD?READSFR11), dummy, dummy
;  
?ISD?READSFR11:
                MOV     A,0xCF
                PUSH    0xCE    
                PUSH    0xCD
                PUSH    0xCC
                PUSH    0xCB
                PUSH    0xCA
                PUSH    0xC9
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;12 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR12), HIGH (?ISD?READSFR12), dummy, dummy
;  
?ISD?READSFR12:
                MOV     A,0xD7
                PUSH    0xD6    
                PUSH    0xD5
                PUSH    0xD4
                PUSH    0xD3
                PUSH    0xD2
                PUSH    0xD1
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;13 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR13), HIGH (?ISD?READSFR13), dummy, dummy
;  
?ISD?READSFR13:
                MOV     A,0xDE
                PUSH    0xDD    
                PUSH    0xDC
                PUSH    0xDB
                PUSH    0xDA
                PUSH    0xD9
                PUSH    0xD8
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;14 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR14), HIGH (?ISD?READSFR14), dummy, dummy
;  
?ISD?READSFR14:
                MOV     A,0xE6
                PUSH    0xE5    
                PUSH    0xE4
                PUSH    0xE3
                PUSH    0xE2
                PUSH    0xE1
                PUSH    0xDF
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;15 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR15), HIGH (?ISD?READSFR15), dummy, dummy
;  
?ISD?READSFR15:
                MOV     A,0xED
                PUSH    0xEC    
                PUSH    0xEB
                PUSH    0xEA
                PUSH    0xE9
                PUSH    0xE8
                PUSH    0xE7
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;16 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR16), HIGH (?ISD?READSFR16), dummy, dummy
;  
?ISD?READSFR16:
                MOV     A,0xF5
                PUSH    0xF4    
                PUSH    0xF3
                PUSH    0xF2
                PUSH    0xF1
                PUSH    0xEF
                PUSH    0xEE
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;17 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR17), HIGH (?ISD?READSFR17), dummy, dummy
;  
?ISD?READSFR17:
                MOV     A,0xFC
                PUSH    0xFB    
                PUSH    0xFA
                PUSH    0xF9
                PUSH    0xF8
                PUSH    0xF7
                PUSH    0xF6
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------
;18 Read CPU Core SFR registers:
;  LOW (?ISD?READSFR18), HIGH (?ISD?READSFR18), dummy, dummy
;  
?ISD?READSFR18:
                MOV     A,0xFF
                PUSH    0xFE
                PUSH    0xFD
                PUSH    ACC        ; dummy      
                PUSH    ACC        ; dummy
                PUSH    ACC        ; dummy
                PUSH    ACC        ; dummy
                AJMP    Send7Bytes
;
;--------------------------------------------------------------------------;
; putchar:  transmit a character via the serial interface
#if ISD_PUTCHAR
PUBLIC _putchar   ; C-Prototype:  char putchar (char c);
PUBLIC ?ISD?PUTCHAR, ?ISD?PUTCHAR_END

?ISD?PUTCHAR:
_putchar:       CJNE    R7,#0A7H,$+3
                JNC     pc_end
                MOV     A,R7
                XRL     A,#0AH
                SAVE_ES
                CLR_ES
                JNZ     pc_char
                MOV     A,#0DH
                CLR_TI
                WR_SBUF
                JNB_TI  $
pc_char:        MOV     A,R7
                CLR_TI
                WR_SBUF
                JNB_TI  $
                JNC     pc_char1        ; ISD51 is not initialized
                MOV     R0,#?ISD?RAMTOP
                MOV     A,@R0
#if CBLK_SZ == 0                        /* no Hareware Breakpoints */
                JNZ     pc_char1
#else
                JNB     ACC.0,pc_char1
#endif
                CLR_TI
pc_char1:
                RESTO_ES
?ISD?PUTCHAR_END:
pc_end:         RET     

#endif

;--------------------------------------------------------------------------
; _getkey:  waits for a character to be received from the serial port
#if ISD_GETKEY

PUBLIC _getkey  ; C-Prototype:  char _getkey (void);

_getkey:        JNB_ES _getkey2
                MOV     A,_ISD_CHAR
                XRL     A,#0A5H
                JZ      _getkey                ; no character available
                MOV     A,#0A5H
                XCH     A,_ISD_CHAR
                MOV     R7,A
                RET

_getkey2:       JNB_RI  $
                RD_SBUF
                CJNE    A,#0A5H,gk_clrRI
                CALL    __isd_init
                SJMP    _getkey

gk_clrRI:       MOV	R7,A
		CLR_RI
                RET
                

PUBLIC _iskey   ; C-Prototype:  bit  _iskey (void);
_iskey:         JNB_ES  _iskey2
                MOV     A,_ISD_CHAR
                CJNE    A,#0A5H,ik_on
                CLR     C        
                RET
                
_iskey2:        CLR     C
                JNB_RI  ik_end
                RD_SBUF
                CJNE    A,#0A5H,ik_on
                CALL    __isd_init
                SJMP    _iskey
ik_on:          SETB    C
ik_end:         RET


?DT?ISD51       SEGMENT DATA
                RSEG    ?DT?ISD51

PUBLIC          _ISD_CHAR
_ISD_CHAR:      DS      1                ; current user input character


                RSEG    ?PR?ISD51
#endif

;--------------------------------------------------------------------------
; __isd_init:  prepare idata RAM for ISD51
__isd_init:     
                MOV     R0,#?ISD?RAMTOP
                MOV     @R0,#0xFF
#if ISD_GETKEY
                MOV     _ISD_CHAR,#0A5H        ; no character available
#endif
                SET_ES      
                RET
                NOP

                END



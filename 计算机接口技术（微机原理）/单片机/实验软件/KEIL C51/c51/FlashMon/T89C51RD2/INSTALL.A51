$TITLE ('Configuration for MONITOR-51   (C) 1987-2003 KEIL')
;***********************************************************************
;*                                                                     *
;* MONITOR 8051  Configuration                                         *
;* COPYRIGHT KEIL ELEKTRONIK GmbH 1987 - 2003                          *
;*                                                                     *
;* written by:     RK  11.06.1987                                      *
;* updated by:     RK  23.10.1989                                      *
;* updated by:     HS  02.09.1991                                      *
;* updated by:     HS  11.04.1995                                      *
;* updated by:     HS  07.09.1997                                      *
;* updated by:     HS  14.03.2003  Flash download added                *
;*                                                                     *
;*                                                                     *
;***********************************************************************


NAME    CONFIG

$INCLUDE (CONFIG.INC)
#include <89c51rd2.H>

PUBLIC  INCHAR          ; CHARACTER INPUT-ROUTINE 
PUBLIC  OUTCHAR         ; CHARACTER OUTPUT-ROUTINE 
PUBLIC  INSTAT          ; INPUT STATUS OF SERIAL INTERFACE
PUBLIC  OUTSTAT         ; OUTPUT STATUS OF SERIAL INTERFACE
PUBLIC  CLR_TI          ; CLEAR SERIAL TRANSMIT INTERRUPT FLAG
PUBLIC  SET_TI          ; SET SERIAL TRANSMIT INTERRUPT FLAG
PUBLIC  CLR_RI          ; CLEAR SERIAL RECEIVE INTERRUPT FLAG
PUBLIC  CLR_SER_IE      ; CLEAR SERIAL INTERRUPT ENABLE FLAG
PUBLIC  SET_SER_IE      ; SET SERIAL INTERRUPT ENABLE FLAG
PUBLIC  SER_INT_ADR     ; ADDRESS OF SERIAL INTERRUPT VECTOR
PUBLIC  SER_INT_ADR_OFF ; ADDRESS OF SERIAL INTERRUPT VECTOR + INT_ADR_OFF
PUBLIC  BEFORE_GO       ; DO SOME THINGS BEFORE STARTING USER PROGRAM
PUBLIC  AFTER_GO        ; DO SOME THINGS AFTER TERMINATION OF USER PROGRAM
PUBLIC  DEF_PC_VAL      ; DEFAULT PC VALUE AFTER START UP
PUBLIC  WR_CODE         ; WRITE CODE BYTE
PUBLIC  PRE_PROG        ; Prepare for Flash programming
PUBLIC  LD_FPAGE        ; Load Flash Page
PUBLIC  POST_PROG       ; Finish Flash programming
PUBLIC  CODE_START_ADR  ; Monitor code start address
PUBLIC  FLASH_PAGESIZE  ; flash page size
PUBLIC  FLASH_MAXBYTES  ; max number of bytes to load in one flash page 
                        ; before programming (workaround for chip bug)
PUBLIC  XDATA_START_ADR ; start of xdata area used by Monitor-51
PUBLIC  EXECBUFF        ; Buffer for SFR access and single step
EXTRN   CODE (MON51)    ; START OF MONITOR-51
EXTRN   CODE (SER_ISR)  ; SERIAL INTERRUPT SERVICE ROUTINE


USING 0

INITSEG SEGMENT CODE AT CODE_START
                RSEG    INITSEG
CODE_START_ADR: LJMP    InitSerial
IF (CODE_START = 0)     ; generate interrupt relocation table only when 
                LJMP    INT_ADR_OFF + 0x03
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 13H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 1BH
                NOP
                NOP
                NOP
                NOP
                NOP
IF ((SERIAL = 0) OR (SERIAL = 1))
                LJMP    INT_ADR_OFF + 23H
ELSE
                LJMP    SER_ISR
ENDIF
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 2BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 33H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 3BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 43H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 4BH
ENDIF


INSTALLCODE     SEGMENT CODE
                RSEG INSTALLCODE


IF (SERIAL = 0)
;********************************************************************
;*  Using TIMER 1 to Generate Baud Rates                            *
;********************************************************************

InitSerial:
IF (BAUDRATE = 0)                       ; when baudrate=0 calculate timer reload value
                CLR     TR1             ; based on the received 0x11 character from uVision
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,#010H
L4:             JB      RXD,L4          ; wait for start bit (negative edge)
L6:             JNB     RXD,L6          ; wait for end of start bit (positive edge)
L7:             SETB    TR1             ; start timer
L8:             JNB     RXD,L10         ; wait until end of first bit
                JNB     TF1,L8          ; or timer overflow
L10:            JNB     RXD,L10         ; wait for bit 5 (high-bit)
L12:            JNB     RXD,L14         ; wait until end of bit 5
                JNB     TF1,L12         ; or timer overflow
L14:            JNB     RXD,L14         ; wait until stop bit
L15:            CLR     TR1
                JB      TF1,InitSerial
                MOV     R7,TL1
                MOV     R6,TH1

                MOV     A,R7
                ADD     A,#040H         ; add 64 for rounding
                MOV     R7,A
                CLR     A
                ADDC    A,R6
                MOV     R6,A

                MOV     A,R7            ; divide by 128
                RLC     A
                MOV     A,R6
                RLC     A
                MOV     R7,A
                CLR     C
                CLR     A
                SUBB    A,R7
                MOV     TH1,A
                CLR     A
                MOV     TL1,A
                MOV     TMOD,#00100000B ; C/T = 0, Mode = 2
                SETB    TR1             ; start timer
                ORL     PCON,#080H      ; set SMOD1 to double baudrate
                MOV     SCON,#01011010B ; Init Serial Interface

L16:            CLR     RI
                JNB     RI,$            ; wait for next character
                MOV     A,SBUF
                CJNE    A,#011H,L16     ; is it a 0x11?
ELSE
IF (CPU_X2 = 1)
DIVFACTOR       EQU     6*BAUDRATE*16
ELSE
DIVFACTOR       EQU     12*BAUDRATE*16
ENDIF
TH1REL          EQU     100H-((CPU_CLOCK+(DIVFACTOR/2))/DIVFACTOR)

                MOV     TMOD,#00100000B ;C/T = 0, Mode = 2
                MOV     TH1,#TH1REL
                ORL     PCON,#080H      ; set SMOD1 to double baudrate
                SETB    TR1             ; start timer
                MOV     SCON,#01011010B ; Init Serial Interface
ENDIF
                MOV     AUXR,#_AUXR     ; Configure T89C51RC2
                JMP     Mon51
ENDIF

IF (SERIAL = 1)
;********************************************************************
;*  Using TIMER 2 to Generate Baud Rates                            *
;********************************************************************

InitSerial:
IF (BAUDRATE = 0)                       ; when baudrate=0 calculate timer reload value
                CLR     A
                MOV     RCAP2H,A
                MOV     RCAP2L,A
                MOV     TL2,A
                MOV     TH2,A
                MOV     T2MOD,A
                MOV     T2CON,A
L4:             JB      RXD,L4
L6:             JNB     RXD,L6
L7:             SETB    TR2
L8:             JNB     RXD,L10
                JNB     TF2,L8
L10:            JNB     RXD,L10
L12:            JNB     RXD,L14
                JNB     TF2,L12
L14:            JNB     RXD,L14
L15:            CLR     TR2
                JB      TF2,InitSerial
                MOV     R7,TL2
                MOV     R6,TH2

                MOV     A,R6
                CLR     C
                RRC     A
                MOV     R4,A
                MOV     A,R7
                RRC     A
                ADD     A,R7
                MOV     R7,A
                MOV     A,R4
                ADDC    A,R6
                MOV     R6,A

                MOV     A,R7
                ADD     A,#010H
                MOV     R7,A
                CLR     A
                ADDC    A,R6
                MOV     R6,A

                MOV     A,R7
                MOV     R0,#05H
L22:            XCH     A,R6
                CLR     C
                RRC     A
                XCH     A,R6
                RRC     A
                DJNZ    R0,L22
                MOV     R7,A
                CLR     C
                CLR     A
                SUBB    A,R7
                MOV     RCAP2L,A
                MOV     TL2,A
                CLR     A
                SUBB    A,R6
                MOV     RCAP2H,A
                MOV     TH2,A

                MOV     T2CON,#034H
                MOV     SCON,#05AH
L16:            CLR     RI
                JNB     RI,$
                MOV     A,SBUF
                CJNE    A,#011H,L16
ELSE                                    ; fixed baudrate
IF (CPU_X2 = 1)
DIVFACTOR       EQU     BAUDRATE*16
ELSE
DIVFACTOR       EQU     BAUDRATE*32
ENDIF
T2REL           EQU     10000H-((CPU_CLOCK+(DIVFACTOR/2))/DIVFACTOR)

                MOV     RCAP2H,#HIGH(T2REL)
                MOV     TH2,#HIGH(T2REL)
                MOV     RCAP2L,#LOW(T2REL)
                MOV     TL2,#LOW(T2REL)
                MOV     T2CON,#34H      ; set RCLK/TCLK/TR2
                MOV     SCON,#01011010B ; Init Serial Interface
ENDIF
                MOV     AUXR,#_AUXR     ; Configure T89C51RC2
                JMP     Mon51
ENDIF



IF (SERIAL = 2)
;********************************************************************
;*  Using external UART 16450/16550                                 *
;********************************************************************

DIVFACTOR       EQU     BAUDRATE*16
BAUDDIV         EQU     (EX_UART_CLK+(DIVFACTOR/2))/DIVFACTOR

InitSerial:
                MOV     DPTR,#EX_UART_ADR+3
                MOV     A,#83H          ; Select Baudrate Registers
                MOVX    @DPTR,A
                MOV     DPTR,#EX_UART_ADR
                MOV     A,#LOW (BAUDDIV)
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,#HIGH (BAUDDIV)
                MOVX    @DPTR,A
                MOV     DPTR,#EX_UART_ADR+3
                MOV     A,#03H          ; Mode: 8-bit, 1 stop, no parity
                MOVX    @DPTR,A
                MOV     DPTR,#EX_UART_ADR+1
                CLR     A
                MOVX    @DPTR,A         ; disable all interrupts
                MOV     DPTR,#EX_UART_ADR+4
                MOVX    @DPTR,A
                MOV     AUXR,#_AUXR     ; Configure T89C51RC2
                MOV     P1,#01H

                JMP     Mon51
ENDIF

IF (SERIAL = 2)
;********************************************************************
;*  Interface via external UART 16450/16550                         *
;********************************************************************
SER_INT_ADR     EQU     000H            ; ADDRESS OF SERIAL INTERRUPT VECTOR.
                                        ; Set to 0 for no interrupt

INSTAT:         PUSH    DPL             ; INPUT STATUS OF SERIAL INTERFACE
                PUSH    DPH
                PUSH    ACC
                MOV     DPTR,#EX_UART_ADR+5 ; LSR
                MOVX    A,@DPTR         ; Check if Ready
                MOV     C,ACC.0
                POP     ACC        
                POP     DPH        
                POP     DPL        
                RET

OUTSTAT:        PUSH    DPL             ; OUTPUT STATUS OF SERIAL INTERFACE
                PUSH    DPH
                PUSH    ACC
                MOV     DPTR,#EX_UART_ADR+5 ; LSR
                MOVX    A,@DPTR         ; Check if Ready
                MOV     C,ACC.5
                POP     ACC
                POP     DPH
                POP     DPL
                RET

INCHAR:         PUSH    DPL             ; CHARACTER INPUT-ROUTINE
                PUSH    DPH
                MOV     DPTR,#EX_UART_ADR
                MOVX    A,@DPTR
                ORL     P1,#02H
                POP     DPH        
                POP     DPL        
                RET

OUTCHAR:        PUSH    DPL             ; CHARACTER OUTPUT-ROUTINE
                PUSH    DPH
                MOV     DPTR,#EX_UART_ADR
                MOVX    @DPTR,A
                ORL     P1,#04H
                POP     DPH
                POP     DPL
                RET

CLR_TI:                                 ; CLEAR SERIAL TRANSMIT INTERRUPT FLAG
                RET

SET_TI:                                 ; SET SERIAL TRANSMIT INTERRUPT FLAG
                RET

CLR_RI:                                 ; CLEAR SERIAL RECEIVE INTERRUPT FLAG
                RET

CLR_SER_IE:                             ; CLEAR SERIAL INTERRUPT ENABLE FLAG
                RET

SET_SER_IE:                             ; SET SERIAL INTERRUPT ENABLE FLAG
                RET

ELSE 

;********************************************************************
;*  Interface via standard 8051 UART                                *
;********************************************************************
SER_INT_ADR     EQU     23H             ; ADDRESS OF SERIAL INTERRUPT VECTOR

INSTAT:         MOV     C,RI            ; INPUT STATUS OF SERIAL INTERFACE
                RET

OUTSTAT:        MOV     C,TI            ; OUTPUT STATUS OF SERIAL INTERFACE
                RET

INCHAR:         MOV     A,SBUF          ; CHARACTER INPUT-ROUTINE
                RET

OUTCHAR:        MOV     SBUF,A          ; CHARACTER OUTPUT-ROUTINE
                RET

CLR_TI:         CLR     TI              ; CLEAR SERIAL TRANSMIT INTERRUPT FLAG
                RET

SET_TI:         SETB    TI              ; SET SERIAL TRANSMIT INTERRUPT FLAG
                RET

CLR_RI:         CLR     RI              ; CLEAR SERIAL RECEIVE INTERRUPT FLAG
                RET

CLR_SER_IE:     CLR     ES              ; CLEAR SERIAL INTERRUPT ENABLE FLAG
                RET

SET_SER_IE:     SETB    ES              ; SET SERIAL INTERRUPT ENABLE FLAG
                RET
ENDIF



BEFORE_GO:                              ; this code is executed before a
                RET                     ; a go or proc step is executed

AFTER_GO:                               ; this code is executed after a go
                RET                     ; command (when a breakpoint was set)


IF (FLASH_PAGESIZE <> 0)
;*********************************************************************
;*  Flash programming functions for ATMEL T89C51RB2/RC2/CC01 devices *
;*********************************************************************
FBUSY_MSK       EQU 001h
FMOD_MSK        EQU 006h
FPS_MSK         EQU 008h
FPL_MSK         EQU 0F0h
FMOD_USER_MSK   EQU 000h
FMOD_XROW_MSK   EQU 002h
FMOD_FUSE_MSK   EQU 004h
SEL_USER_CL     EQU 008h
FPL_S0          EQU 050h
FPL_S1          EQU 0A0h


DATA_AREA       SEGMENT DATA
                RSEG    DATA_AREA
BLOCK_LEN:      DS      1
S_ADR_L:        DS      1
S_ADR_H:        DS      1
B_ADR_L:        DS      1
B_ADR_H:        DS      1


XDATA_AREA      SEGMENT  XDATA
                RSEG    XDATA_AREA
F_BUFFER:       DS      128

                RSEG INSTALLCODE

PRE_PROG:       MOV     BLOCK_LEN,A       ; Prepare for Flash programming
                MOV     S_ADR_L,DPL       ; A=block length DPTR=first address
                MOV     S_ADR_H,DPH       ; This function must not take much time! (no flash erase!) 
                MOV     B_ADR_L,#LOW(F_BUFFER)
                MOV     B_ADR_H,#HIGH(F_BUFFER)
                RET

LD_FPAGE:       PUSH    DPL               ; load data into flash page or ram for programming
                PUSH    DPH
                MOV     DPL,B_ADR_L
                MOV     DPH,B_ADR_H
                MOVX    @DPTR,A
                INC     DPTR
                MOV     B_ADR_L,DPL
                MOV     B_ADR_H,DPH
                POP     DPH
                POP     DPL
                SETB    C                 ; set C flag to suppresses immediate code verify
                RET                       ; C flag set suppresses code verify

POST_PROG:                                ; Finish Flash programming
                ORL     AUXR1,#20h        ; MAP boot memory
                MOV     R1,#09h
                MOV     A,BLOCK_LEN       ; number of bytes to flash
                MOV     DPL,S_ADR_L
                MOV     DPH,S_ADR_H
                INC     AUXR1
                MOV     DPTR,#F_BUFFER
                INC     AUXR1
                LCALL   0FFF0H            ; Common API entry point in the bootloader
                ANL     AUXR1,  #0DFh     ; UNMAP BOOT MEMORY
                RET


; write one byte into flash
WR_CODE:        PUSH    AR1               ; Save regiters R1 R2 R4 R6
                MOV     R1, #02h          ; Prepare for API write byte
                PUSH    AR2
                PUSH    AR4
                PUSH    AR6
                PUSH    ACC
                ORL     AUXR1,#20h        ; MAP boot memory
                LCALL   0FFF0h            ; Common API entry point in the bootloader
                ANL     AUXR1,  #0DFh     ; UNMAP BOOT MEMORY
                POP     ACC
                POP     AR6
                POP     AR4
                POP     AR2
                POP     AR1
                RET                     

ELSE

; Dummy flash functions when application is loaded into v.Neumann RAM
PRE_PROG:       RET                       ; prepare flash for programming

LD_FPAGE:       MOVX    @DPTR,A           ; write one byte into v.Neumann wired RAM
                CLR     C                 ; clear C flag to force immediate code verification
                RET

POST_PROG:      RET                       ; Finish Flash programming


WR_CODE:        MOVX    @DPTR,A           ; write one byte into v.Neumann wired RAM
                RET                     
ENDIF



SER_INT_ADR_OFF EQU (INT_ADR_OFF + SER_INT_ADR)

XDATA_BEGIN     SEGMENT XDATA AT XDATA_START
                RSEG    XDATA_BEGIN
XDATA_START_ADR:DS     1 ; define one dummy byte

IF (FLASH_PAGESIZE <> 0)
CODE_AREA       SEGMENT CODE
                RSEG    CODE_AREA
ELSE
XDATA_AREA      SEGMENT XDATA
                RSEG    XDATA_AREA
ENDIF
EXECBUFF:       DS      9

                END

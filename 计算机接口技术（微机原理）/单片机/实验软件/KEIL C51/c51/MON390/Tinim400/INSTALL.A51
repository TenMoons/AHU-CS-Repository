$TITLE ('Configuration for MON400 (C) 2003 KEIL')

;------------------------------------------------------------------------------
;
;  MON390 CONFIGURATION FOR DALLAS CONTIGIOUS MODE on DS80C400
;  COPYRIGHT KEIL ELEKTRONIK GmbH 2001 - 2003
;
;------------------------------------------------------------------------------
;
; Chip Specific Options (MCON needs to be set before ACON)
; ========================================================
;
; IDM1, IDM0:  Internal Data Memory Configuration Bits (MCON.7, MCON.6)
IDM  EQU 0  ; 0 = 8KB on-chip SRAM location X:0x00E000 - X:0x00FFFF
;           ; 1 = 8KB on-chip SRAM location X:0x000000 - X:0x001FFF
;           ; 2 = 8KB on-chip SRAM location X:0xFFE000 - X:0xFFFFFF
;           ; 3 = invalid
;
;
; CMA: CAN Data Memory Assignment (MCON.5)
CMA  EQU 0  ; 0 = CAN0 X:0x00DB00 - X:0x00DBFF
            ; 1 = CAN0 X:0xFFDB00 - X:0xFFDBFF
;
;
; SA: Extend Stack Address Mode Enable (ACON.2)
SA   EQU 1  ; 0 = 8051 compatible stack in IDATA memory
;           ; 1 = Use 1KB stack in on-chip XDATA space
;
;
; Port 4 Function Control (P4CNT)
; ===============================
; Port 4 Pin Function (P4CNT.2-0)
P4PF EQU 7  ; 0 : all pin used as I/O pin (P4.0 - P4.3)
;           ; 4 : P4.0 is CE0
;           ; 5 : P4.0 is CE0, P4.1 is CE1
;           ; 6 : P4.0 is CE0, P4.1 is CE1, P4.2 is CE2
;           ; 7 : P4.0 is CE0, P4.1 is CE1, P4.2 is CE2, P4.3 is CE3
;
; Program Memory Chip Enable Window Size (P4CNT.5-3)
PCES EQU 6  ; 0 = 32KB  address window (0 - 0x7FFF)
;           ; 4 = 128KB address window (0 - 0x1FFFF)
;           ; 5 = 256KB address window (0 - 0x3FFFF)
;           ; 6 = 512KB address window (0 - 0x7FFFF)
;           ; 7 = 1MB   address window (0 - 0xFFFFF)
;
; PDCE3 .. PDCE0: Program/Data Chip Enable (MCON.3, MCON.2, MCON.1, MCON.0)
; refer to the Dallas Data Sheet for more information
PDCE3 EQU 0
PDCE2 EQU 0
PDCE1 EQU 0
PDCE0 EQU 1
;
;
;------------------------------------------------------------------------------
;  Serial interface settings
;
$SET (SERIAL = 2)       ; 0 = use SERIAL PORT0 for Monitor Communication
                        ; 1 = use SERIAL PORT1 for Monitor Communication
                        ; 2 = use SERIAL PORT2 for Monitor Communication
;
;------------------------------------------------------------------------------
;  Memory Mapping
;
; Monitor Code and Data Memory
MON_CODE_START  EQU     0470000H  ; start address of Monitor code area in CODE memory
MON_RAM_START   EQU     027FF00H  ; start address of Monitor data area in XDATA memory

; User Code Memory (von-Neumann mapped)
CODE_RAM_START  EQU     0200000H  ; start address of user CODE space in XDATA memory
                                  ; (von Neumann mapping)
INT_ADR_OFF     EQU     0000000H  ; Interrupt Vector Offset if MON400 is installed at 
                                  ; address 0000H
CODE_RAM_END    EQU     027FF00H  ; end address of user CODE space in XDATA memory

;------------------------------------------------------------------------------
;
; Extended Stack Mapping
STK_BASE0       EQU     000DC00H  ; Stack Start for: IDM1=0, IDM0=0 
STK_BASE1       EQU     0002000H  ; Stack Start for: IDM1=0, IDM0=1
STK_BASE2       EQU     0FFDC00H  ; Stack Start for: IDM1=1, IDM0=0 
STK_BASE3       EQU     0FFDC00H  ; Stack Start for: IDM1=1, IDM0=1 (invalid) 
;
;------------------------------------------------------------------------------

$include(xseg_ext.inc)

NAME   CONFIG

PUBLIC RECEIVEBYTE         ; CHARACTER INPUT-ROUTINE 
PUBLIC SENDBYTE            ; CHARACTER OUTPUT-ROUTINE 
PUBLIC SENDCHECK           ; CHECK OUTPUT STATUS OF SERIAL INTERFACE
PUBLIC  SERINT_ENABLE       ; ENABLE SERIAL INTERRUPT
PUBLIC  SERINT_DISABLE      ; DISABLE SERIAL INTERRUPT
PUBLIC  IDENT_STRING        ; IDENTIFIER STRING
PUBLIC  INT_ADR_OFF         ; OFFSET FOR INTERRUPT VECTORS
PUBLIC  SER_INT_OFF         ; ADDRESS OFFSET OF SERIAL INTERRUPT VECTOR
PUBLIC  CODE_RAM_START      ; USER CODE START
PUBLIC  CODE_RAM_END        ; USER CODE END
PUBLIC  MON_CODE_START      ; MON400 CODE START
PUBLIC  BEFORE_GO           ; DO SOME THINGS BEFORE STARTING USER PROGRAM
PUBLIC  AFTER_GO            ; DO SOME THINGS AFTER TERMINATION OF USER PROGRAM
PUBLIC  WR_CODE             ; WRITE CODE BYTE
PUBLIC  WR_XDATA            ; WRITE XDATA BYTE
PUBLIC  STK_BASE            ; RETURN EXTENDED STACK BASE (DEVICE DEPENDANT)

EXTRN ECODE:FAR (MONSTART)    ; START OF MONITOR-51
EXTRN ECODE:FAR (MONBREAK)    ; BREAK RESTART OF MONITOR-251  
EXTRN ECODE:FAR (SERBREAK)    ; SERIAL INTERRUPT ENTRY OF MONITOR-251

SINTENABLE    LIT    '(MONDATA+ 30)'

; SFR SYMBOLS
P3      DATA    0B0h
DPL     DATA    82h
DPH     DATA    83h
DPX     DATA    93h
TMOD    DATA    89H
TH1     DATA    8DH
SCON0   DATA    98H
CKCON   DATA    8EH
TCON    DATA    88H
TR1     BIT     8EH
SBUF    DATA    99H
TI      BIT     99H
RI      BIT     98H
ACC     DATA    0E0H
P5CNT   DATA    0A2h
ES      BIT     0ACH
EX0     BIT     0A8H
PSW1    DATA    0D1H
PCON    DATA    087H
EA      BIT     0AFH
IPH0    DATA    0B7H
IPL0    DATA    0B8H
P1      DATA    090H
PSW     DATA    0D0h
EIE     DATA    0E8h
ES2     BIT     EIE.2
TL3     DATA    0FBh
TH3     DATA    0FCh
T3CM    DATA    0FDh
SCON2   DATA    0FEh
SBUF2   DATA    0FFh

R0_B0   equ     0
R2_B0   equ     2

INFOTX_PIN_ONEWIRE      EQU     P3.5

DPX1    DATA    095h
DPH1    DATA    085h
DPL1    DATA    084h
DPS     DATA    086h

sfr     ACON  = 0x9D
sfr     TA    = 0xC7
sfr     MCON  = 0xC6
sfr     P4CNT = 0x92 

FILLGAP       MACRO
              NOP
              NOP
              NOP
              NOP
              ENDM


TIMEDACCESS     MACRO
                MOV     TA,#0xAA        
                MOV     TA,#0x55
                ENDM

?PR?INITSEG   SEGMENT ECODE AT MON_CODE_START
              RSEG   ?PR?INITSEG

                sjmp startup1

                ;
                ; TINIm400 Boot-Tag
                ;
                db 'T', 'I', 'N', 'I'
                db 47h

$if (SERIAL = 0)
  SER_INT_OFF     EQU     23H                     ; OFFSET OF SERIAL0 INTERRUPT VECTOR
$endif
$if (SERIAL = 1)
  SER_INT_OFF     EQU     3BH                     ; OFFSET OF SERIAL1 INTERRUPT VECTOR
$endif
$if (SERIAL = 2)
  SER_INT_OFF     EQU     53H                     ; OFFSET OF SERIAL2 INTERRUPT VECTOR
$endif


SER_INT_CODE:
   ljmp SERBREAK

HACK_INIT_CODE:
   ;ljmp 200000h
   ljmp 0200000h


STARTUP1:     mov     dptr, #SER_INT_CODE
                mov     dpx1, #0h
                mov     dph1, #0
                mov     dpl1, #23h
                ;
                ; Copy interrupt rountines. Copy to XSEG first and then back trough a library call.
                ;
              acall   Init_Copy4
                ;
                
                ;
              mov     dptr, #SER_INT_CODE
              inc     dps
              mov     dptr, #MONITOR_INTERRUPT
              mov     a, #SER_INT_OFF               ; first write serial interrupt offset
              movx    @dptr, a
              inc     dptr
              inc     dps
              acall   Init_Copy4

              mov     dptr, #HACK_INIT_CODE
              inc     dps
              mov     dptr, #MONITOR_HACK_LJMP
              inc     dps
              acall   Init_Copy4

                ; put 'reti's everywhere in the interrupt table
                acall   install_default_interrupts

                
MonitorStart: MOV     R0,#0        
              MOV     R1,#0
              MOV    A,#01H
Flashloop:    MOV    P1,A
              RL     A
FWait_State:  NOP
              NOP
              NOP
              DJNZ    R0,FWait_State
              DJNZ    R1,FWait_State
              RL     A
              ADD    A,ACC
              JNZ     Flashloop
              MOV     P1,#0FFH

/*
 *     Work-Around for SerInit on int. S0 19200@40Mhz
 */

              LJMP   InitSerial

;---- Setup for Serial Interfaces.

$IF (SERIAL = 0)
;********************************************************************
;*  Using TIMER 1 to Generate Baud Rates                            *
;*  Oscillator frequency = 40.000 MHz                               *
;*  Set Baudrate to 38400 Baud                                       *
;********************************************************************

InitSerial:   ORL    PCON, #080H
              MOV     SCON0,#050H                  
              ORL     TMOD, #021H           
              ;MOV     TH1,  #0F8H   
              mov     th1, #0FAh          ; 36.864 MHz, 38400 baud, divisor=4
              ORL     CKCON,#010H
              MOV    TCON, #050H              
              ORL     SCON0,#002H   

              JMP    MONSTART
IDENT_STRING: DB      'MONITOR-400 USING TIMER 1 FOR BAUDRATES',0

$ENDIF

$IF (SERIAL = 1)
;********************************************************************
;*  Using TIMER 2 to Generate Baud Rates                            *
;********************************************************************
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
T2CON   DATA    0C8H

RCAPVAL EQU  (65536 - ((XTAL / BAUDRATE)/16))

InitSerial:   LABEL   FAR
              LJMP   Next
Next:         MOV    T2CON,#30H
              MOV    RCAP2H,#HIGH (RCAPVAL)
              MOV    RCAP2L,#LOW (RCAPVAL)
               SETB  T2CON.2         ; start timer
              MOV    SCON,#01011010B ; Init Serial Interface
              LJMP   MONSTART

IDENT_STRING: DB     'MONITOR-400 USING TIMER 2 FOR BAUDRATES',0
$ENDIF

$IF (SERIAL = 2)
;********************************************************************
;*  Using TIMER 3 to Generate Baud Rates                            *
;*  Oscillator frequency = 14.7456 MHz                              *
;*  Set Baudrate to 38400 Baud                                      *
;********************************************************************

InitSerial:     mov     T3CM, #010h         ; turn on baud doubler
                mov     SCON2,#050h         ; serport 2 mode 1, enable receive
                orl     T3CM, #002H         ; timer 3, 8-bit auto-reload
;                mov     th3,  #0FAh         ; 36.864 MHz, 38400 baud, divisor=4
                mov     th3, #0FEh          ; 115200 baud

                orl     T3CM, #020H         ; Timer 3 = Oscillator / 4
                orl     T3CM, #040H         ; Enable timer 3 to run
                orl     SCON2,#002H         ; Serial 2 transmit indicator set

              JMP    MONSTART
IDENT_STRING: DB     'MONITOR-400 USING TIMER 3 FOR BAUDRATES',0

$ENDIF



$IF (SERIAL = 0 OR SERIAL = 1)
;********************************************************************
;*  Interface via standard on-chip UART                             *
;********************************************************************

SENDBYTE      PROC   NEAR
              ;ORL   P1,#1
              CLR    TI            ; Only A & PSW can be destroyed!
              MOV    SBUF,A
              ;ORL   P1,#1
              RET
              ENDP

SENDCHECK     PROC   NEAR
              JNB    TI,$          ; Only A & PSW can be destroyed!
              RET
              ENDP

RECEIVEBYTE   PROC   NEAR
              ;ORL   P1,#2  
              JNB    RI,$          ; Only A & PSW can be destroyed!
              MOV    A,SBUF
              CLR    RI
              ;ORL   P1,#2
              RET
              ENDP

SERINT_ENABLE PROC   NEAR
              CLR    TI            ; No Transmitter Interrupt yet
              SETB   ES              ; Enable Serial Interrupt
              RET
              ENDP

SERINT_DISABLE  PROC    NEAR
              CLR    ES            ; Disable Serial Interrupt
              SETB   TI            ; Set Transmitter Interrupt Flag
              RET
              ENDP


$ENDIF

$IF (SERIAL = 2)
;********************************************************************
;*  Interface via super-duper standard on-chip UART                 *
;********************************************************************

SENDBYTE      PROC   NEAR
                anl     scon2, #0FDh      ; Clear the transmit indicator flag
                mov     sbuf2,A
                ret
              ENDP

SENDCHECK     PROC   NEAR
                push    acc
sc_top:         mov     a, scon2
                jnb     acc.1, sc_top 
                pop     acc
                ret
              ENDP

RECEIVEBYTE   PROC   NEAR
rb_top:         mov     a, scon2
                jnb     acc.0, rb_top   ; Only A & PSW can be destroyed!
                mov     a, sbuf2
                anl     scon2, #0FEh    ; clear the lowest (RI) bit
                ret
              ENDP

SERINT_ENABLE PROC   NEAR
                anl     scon2, #0FDh    ; No Transmitter Interrupt yet
                setb    es2             ; Enable Serial Interrupt
                ret
              ENDP

SERINT_DISABLE  PROC    NEAR
                clr     es2             ; Disable Serial Interrupt
                orl     scon2, #02h     ; Set Transmitter Interrupt Flag
                ret
              ENDP


$ENDIF

;-----------------------------------------------------------------------------

BEFORE_GO:                               ; this code is executed before a
                RET                      ; a go or proc step is executed

AFTER_GO:                                ; this code is executed after a go
                RET                      ; command (when a breakpoint was set)

WR_CODE:        MOVX    @DPTR,A          ; insert different code here, but
                RET                      ; do not change any other register
                                         ; without saving it

WR_XDATA:       MOVX    @DPTR,A          ; insert different code here, but
                RET                      ; do not change any other register
                                         ; without saving it

STK_BASE:                                ; RETURN STACK BASE (DEVICE DEPENDANT)
                MOV    A,MCON
                ANL    A,#0C0H
                CJNE   A,#000H,N_STK_BASE0
                MOV    R1,#BYTE0 STK_BASE0   ; IDM1=0, IDM0=0 
                MOV    R2,#BYTE1 STK_BASE0
                MOV    R3,#BYTE2 STK_BASE0
                RET
N_STK_BASE0:    CJNE   A,#040H,N_STK_BASE1
                MOV    R1,#BYTE0 STK_BASE1   ; IDM1=0, IDM0=1
                MOV    R2,#BYTE1 STK_BASE1
                MOV    R3,#BYTE2 STK_BASE1
                RET
N_STK_BASE1:    CJNE   A,#040H,N_STK_BASE2
                MOV    R1,#BYTE0 STK_BASE2   ; IDM1=1, IDM0=0
                MOV    R2,#BYTE1 STK_BASE2
                MOV    R3,#BYTE2 STK_BASE2
                RET
N_STK_BASE2:    MOV    R1,#BYTE0 STK_BASE3   ; IDM1=1, IDM0=1
                MOV    R2,#BYTE1 STK_BASE3
                MOV    R3,#BYTE2 STK_BASE3
                RET

;-----------------------------------------------------------------------------
;
; Copy four bytes from dptr0 to dptr1.  Meant to be used to copy code snippets around.
;
; Destroys: A, dptr0, dptr1, dps
;
Init_Copy4:
                movx    a, @dptr                  ; get byte of interrupt vector
                inc     dptr 
                inc     dps
                movx    @dptr, a                  ; put byte of interrupt vector
                inc     dptr 
                inc     dps
                ;  do it 3 more times
                movx    a, @dptr                  ; get byte of interrupt vector
                inc     dptr 
                inc     dps
                movx    @dptr, a                  ; put byte of interrupt vector
                inc     dptr 
                inc     dps
                ;  do it 2 more times
                movx    a, @dptr                  ; get byte of interrupt vector
                inc     dptr 
                inc     dps
                movx    @dptr, a                  ; put byte of interrupt vector
                inc     dptr 
                inc     dps
                ;  do it 1 more time
                movx    a, @dptr                  ; get byte of interrupt vector
                inc     dptr 
                inc     dps
                movx    @dptr, a                  ; put byte of interrupt vector
                inc     dptr 
                mov     dps, #0
                ret

install_default_interrupts:
                mov     dptr, #int_adr_off
                mov     a, #01h
              movx    @dptr, a
              inc     dptr

              mov     a, #HIGH(MONITOR_HACK_LJMP)
              movx    @dptr, a
              inc     dptr
              mov     a, #LOW(MONITOR_HACK_LJMP)
              movx    @dptr, a

                mov     a, #032h                          ; code for 'reti'
                mov     dpl, #03h
                movx    @dptr, a
                mov     dpl, #0Bh
                movx    @dptr, a
                mov     dpl, #13h
                movx    @dptr, a
                mov     dpl, #1Bh
                movx    @dptr, a
                mov     dpl, #2Bh
                movx    @dptr, a
                mov     dpl, #33h
                movx    @dptr, a
                mov     dpl, #3Bh
                movx    @dptr, a
                mov     dpl, #43h
                movx    @dptr, a
                mov     dpl, #4Bh
                movx    @dptr, a
                mov     dpl, #53h
                movx    @dptr, a
                mov     dpl, #5Bh
                movx    @dptr, a
                mov     dpl, #63h
                movx    @dptr, a
                mov     dpl, #6Bh
                movx    @dptr, a
                mov     dpl, #73h
                movx    @dptr, a
                mov     dpl, #7Bh
                movx    @dptr, a
                mov     dpl, #83h
                movx    @dptr, a
                mov     dpl, #8Bh
                movx    @dptr, a
                mov     dpl, #93h
                movx    @dptr, a
                mov     dpl, #9Bh
                movx    @dptr, a
                mov     dpl, #0A3h
                movx    @dptr, a
                mov     dpl, #0ABh
                movx    @dptr, a
                mov     dpl, #0B3h
                movx    @dptr, a
                mov     dpl, #0BBh
                movx    @dptr, a
                mov     dpl, #0C3h
                movx    @dptr, a
                mov     dpl, #0CBh
                movx    @dptr, a
                mov     dpl, #0D3h
                movx    @dptr, a
                mov     dpl, #0DBh
                movx    @dptr, a
                mov     dpl, #0E3h
                movx    @dptr, a
                mov     dpl, #0F3h
                movx    @dptr, a
                mov     dpl, #0FBh
                movx    @dptr, a
                ret               

;
; input: A - byte to output to debug port
;
output_ASCII:
        push    psw
       push    acc
       push    r0_b0
       push    r2_b0

        mov R2,#9               ; Loop for 9 bits
        clr C

        ;WOS_DISABLE_INTERRUPTS
       clr   ea

SendLoop0:
        mov INFOTX_PIN_ONEWIRE,C ; 2       0.000/8.68          Begin a data bit
        rrc A                    ; 1       0.217
        mov R0,#24               ; 2       0.325
        djnz R0,$                ; 3*24    0.543
        djnz R2,SendLoop0        ; 3       8.35
    
        setb INFOTX_PIN_ONEWIRE  ; 2       8.68/0.000           Begin stop bit

        ;WOS_ENABLE_INTERRUPTS
       setb    ea

        mov R0,#30               ; 2       0.217                Make long inter-byte time.....
        djnz R0,$                ; 3*30      10.20

       pop   r2_b0
       pop   r0_b0
       pop   acc
       pop   psw
       ret



PUBLIC MONDATA
?FD?MON_DATA  SEGMENT       HDATA  AT MON_RAM_START
              RSEG   ?FD?MON_DATA
MONDATA:      DS     32            ; Monitor data area; DO NOT CHANGE SIZE
MONDATA_CODE    EQU MON_RAM_START
PUBLIC  MONDATA_CODE


              END


$TITLE ('Configuration for MONITOR-51   (C) 1987-1995 KEIL')
;***********************************************************************
;*                                                                     *
;* MONITOR 8051  Configuration                                         *
;* COPYRIGHT KEIL ELEKTRONIK GmbH 1987 - 1995                          *
;*                                                                     *
;* written by:     RK  11.06.87                                        *
;* updated by:     RK  23.10.89                                        *
;* updated by:     HS  02.09.91                                        *
;* updated by:     HS  11.04.95                                        *
;* updated by:     HS  07.09.97                                        *
;*                                                                     *
;***********************************************************************

                NAME    CONFIG

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
PUBLIC	DEF_PC_VAL	    ; DEFAULT PC VALUE AFTER START UP
PUBLIC  WR_CODE         ; WRITE CODE BYTE

EXTRN   CODE (MON51)    ; START OF MONITOR-51
EXTRN   CODE (SER_ISR)  ; SERIAL INTERRUPT SERVICE ROUTINE

INT_ADR_OFF EQU 8000H   ; INTERRUPT VECTOR OFFSET IF MONITOR
                        ; IS INSTALLED AT ADDRESS 0000H
DEF_PC_VAL	EQU	8000H	; DEFAULT PC VALUE AFTER START UP

INITSEG SEGMENT CODE
                RSEG    INITSEG

                LJMP    InitSerial
                LJMP    INT_ADR_OFF + 03H
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
$IF ((SERIAL = 3) OR (SERIAL = 5) OR (SERIAL = 10) OR (SERIAL = 12))
                LJMP    INT_ADR_OFF + 23H
$ELSE
                LJMP    SER_ISR
$ENDIF
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
$IF ((SERIAL = 5) OR (SERIAL = 12))
                LJMP    SER_ISR
$ELSE
                LJMP    INT_ADR_OFF + 3BH
$ENDIF
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
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 53H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 5BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 63H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 6BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 73H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 7BH
                NOP
                NOP
                NOP
                NOP
                NOP
$IF ((SERIAL = 3) OR (SERIAL = 10))
                LJMP    SER_ISR
$ELSE
                LJMP    INT_ADR_OFF + 83H
$ENDIF
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 8BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 93H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 9BH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0A3H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0ABH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0B3H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0BBH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0C3H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0CBH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0D3H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0DBH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0E3H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0EBH
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0F3H
                NOP
                NOP
                NOP
                NOP
                NOP
                LJMP    INT_ADR_OFF + 0FBH


;********************************************************************
;* This Macro checks whether a PROM or a RAM is at Address 0.       *
;* If a PROM is detected -> Jump to Program in PROM (Address 0)     *
;* If a RAM  is detected -> Jump to Monitor                         *
;********************************************************************
PROMCHECK       MACRO
$IF (PROMCHECK)
                USING   0

                MOV     DPTR,#0         ; IF EPROM THEN JMP 0
                CLR     A
                MOVC    A,@A+DPTR
                MOV     R1,A
                CPL     A
                MOVX    @DPTR,A
                CLR     A
                MOVC    A,@A+DPTR
                CPL     A
                CJNE    A,AR1,JMP0
                MOVX    @DPTR,A
$ENDIF
                ENDM

INSTALLCODE     SEGMENT CODE
                RSEG INSTALLCODE

$IF (PROMCHECK)
JMP0:           LJMP    0
$ENDIF


$IF (SERIAL = 0)
;********************************************************************
;*  Using TIMER 1 to Generate Baud Rates                            *
;*  Oscillator frequency = 11.059 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************

InitSerial:     PROMCHECK               ; Check if PROM in System
                MOV     TMOD,#00100000B ;C/T = 0, Mode = 2
                MOV     TH1,#0FDH
                SETB    TR1
                MOV     SCON,#01011010B ; Init Serial Interface
                JMP     Mon51

$ENDIF

$IF (SERIAL = 1)
;********************************************************************
;*  Using internal Baud Rate Generator (only for 80515 and 80C517)  *
;*  Oscillator frequency = 12.000 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************
BD      BIT     0DFH

InitSerial:     PROMCHECK               ; Check if PROM in System
                SETB    BD
                ORL     PCON,#10000000B
                MOV     SCON,#01011010B ; Init Serial Interface
                JMP     Mon51
$ENDIF

$IF (SERIAL = 2)
;********************************************************************
;*  Using TIMER 2 to Generate Baud Rates (only for 8052)            *
;*  Oscillator frequency = 12.000 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
T2CON   DATA    0C8H

InitSerial:     PROMCHECK               ; Check if PROM in System
                MOV     T2CON,#34H
                MOV     RCAP2H,#0FFH
                MOV     RCAP2L,#0D9H
                MOV     SCON,#01011010B ; Init Serial Interface
                JMP     Mon51
$ENDIF


$IF (SERIAL = 3)
;********************************************************************
;*  Using Serial Interface 1 Baudrate Generator (only for 80C517)   *
;*  Oscillator frequency = 12.000 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************
S1REL   DATA    09DH
S1CON   DATA    09BH
S1BUF   DATA    09CH
IEN2    DATA    09AH

InitSerial:     PROMCHECK                ; Check if PROM in System
                MOV     S1REL,#0D9H      ; Reload Value
                MOV     S1CON,#10111010B ; Init Serial Interface
                JMP     Mon51
$ENDIF

$IF (SERIAL = 4)
;********************************************************************
;*  Using TIMER 2 to Generate Baud Rates (only for 80C320/520/530)  *
;*  with dual data pointer support                                  *
;*  Oscillator frequency = 12.000 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
T2CON   DATA    0C8H
DPS     DATA    086H

InitSerial:     PROMCHECK               ; Check if PROM in System
                MOV     DPS,#00H
                MOV     T2CON,#34H
                MOV     RCAP2H,#0FFH
                MOV     RCAP2L,#0D9H    ; 9600 baud @ 12 MHz
;                MOV     RCAP2L,#0BFH    ; 9600 baud @ 20 MHz
;                MOV     RCAP2L,#095H    ; 9600 baud @ 33 MHz
;                MOV     RCAP2L,#0DCH    ; 9600 baud @ 11.0592 MHz
;                MOV     RCAP2L,#0EEH    ; 19200 baud @ 11.0592 MHz
;                MOV     RCAP2L,#0F7H    ; 38400 baud @ 11.0592 MHz
;                MOV     RCAP2L,#0FAH    ; 57600 baud @ 11.0592 MHz
                MOV     SCON,#01011010B ; Init Serial Interface
                JMP     Mon51
$ENDIF

$IF (SERIAL = 5)
;********************************************************************
;*  Using second serial interface of 80C320/520/530 with TIMER 1    *
;*  and dual data pointer support                                   *
;*  Oscillator frequency = 12.000 MHz                               *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************
DPS     DATA    086H
CKCON   DATA    08EH
SCON1   DATA    0C0H
SBUF1   DATA    0C1H
WDCON   DATA    0D8H
RI1     BIT     0C0H.0

InitSerial:     PROMCHECK               ; Check if PROM in System
                MOV     DPS,#00H
                MOV     TMOD,#00100000B ;C/T = 0, Mode = 2

                MOV     TH1,#0F6H       ; 9600 baud @ 12 MHz
                ORL     CKCON,#010H     ; Timer 1 uses a divide by 4 clock
;                ORL     WDCON,#10000000B; 19200 baud @ 12 MHz

;                MOV     TH1,#0FDH       ; 9600 baud @ 11.0592 MHz

;                MOV     TH1,#0FFH       ; 57600 baud @ 11.0592 MHz
;                ORL     WDCON,#10000000B

;                MOV     TH1,#0E5H       ; 9600 baud @ 33 MHz
;                ORL     CKCON,#010H     ; Timer 1 uses a divide by 4 clock
;                ORL     WDCON,#10000000B; 19200 baud @ 33 MHz

                SETB    TR1
                MOV     SCON1,#01011010B ; Init Serial Interface
                JMP     Mon51
$ENDIF

$IF (SERIAL = 6)
;********************************************************************
;*  Using external UART 16450/16550                                 *
;*  UART Oscillator frequency = 12.000 MHz                          *
;*  Set Baudrate to 9600 Baud                                       *
;********************************************************************
SIOCLK    EQU   3686400                 ; EXTERNAL SIO XTAL FREQUENZY
BAUDRATE  EQU   9600                    ;9600 bps
BAUDDIV   EQU   (SIOCLK / 16) / BAUDRATE
SIOADDR   EQU   0FC00H                  ; SIO Address

InitSerial:     PROMCHECK               ; Check if PROM in System
                MOV     DPTR,#SIOADDR+3
                MOV     A,#83H          ; Select Baudrate Registers
                MOVX    @DPTR,A
                MOV     DPTR,#SIOADDR
                MOV     A,#LOW (BAUDDIV)
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,#HIGH (BAUDDIV)
                MOVX    @DPTR,A
                MOV     DPTR,#SIOADDR+3
                MOV     A,#03H          ; Mode: 8-bit, 1 stop, no parity
                MOVX    @DPTR,A
                MOV     DPTR,#SIOADDR+1
                CLR     A
                MOVX    @DPTR,A         ; disable all interrupts
                MOV     DPTR,#SIOADDR+4
                MOVX    @DPTR,A
                JMP     Mon51


$ELSEIF (SERIAL = 7)
;********************************************************************
;*  Using Timer 1 to generate Baud Rates                            *
;*  for 8052 and compatibles except Dallas 80C320/520/530           *
;*  Oscillator frequency = don't care                               *
;*  Automatic Baudrate Adjustment                                   *
;********************************************************************

InitSerial:     PROMCHECK               ; Check if PROM in System
                CLR     TR1
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,#010H
L4:             JB      RXD,L4
L6:             JNB     RXD,L6
L7:             SETB    TR1
L8:             JNB     RXD,L10
                JNB     TF1,L8
L10:            JNB     RXD,L10
L12:            JNB     RXD,L14
                JNB     TF1,L12
L14:            JNB     RXD,L14
L15:            CLR     TR1
                JB      TF1,InitSerial
                MOV     R7,TL1
                MOV     R6,TH1

                MOV     A,R7
                ADD     A,#040H
                MOV     R7,A
                CLR     A
                ADDC    A,R6
                MOV     R6,A

                MOV     A,R7
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
                MOV     TMOD,#00100000B ;C/T = 0, Mode = 2
                SETB    TR1
                ORL     PCON,#080H
                MOV     SCON,#05AH

L16:            CLR     RI
                JNB     RI,$
                MOV     A,SBUF
                CJNE    A,#011H,L16
                JMP     Mon51


$ELSEIF (SERIAL = 8)
;********************************************************************
;*  Using Timer 2 to generate Baud Rates (8052 and compatibles)     *
;*  Oscillator frequency = don't care                               *
;*  Automatic Baudrate Adjustment                                   *
;********************************************************************
T2CON   DATA    0C8H
T2MOD   DATA    0C9H
RC2L    DATA    0CAH
RC2H    DATA    0CBH
TL2     DATA    0CCH
TH2     DATA    0CDH
TR2     BIT     0C8H.2
TF2     BIT     0C8H.7
  
InitSerial:     PROMCHECK               ; Check if PROM in System
                CLR     A
                MOV     RC2H,A
                MOV     RC2L,A
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
                MOV     RC2L,A
                MOV     TL2,A
                CLR     A
                SUBB    A,R6
                MOV     RC2H,A
                MOV     TH2,A

                MOV     T2CON,#034H
                MOV     SCON,#05AH
L16:            CLR     RI
                JNB     RI,$
                MOV     A,SBUF
                CJNE    A,#011H,L16
                JMP     Mon51

  
$ELSEIF (SERIAL = 9)
;********************************************************************
;*  Using internal Baudrate Generator to generate Baud Rates        *
;*  Oscillator frequency = don't care                               *
;*  Automatic Baudrate Adjustment                                   *
;********************************************************************
SRELL   DATA    0AAH
SRELH   DATA    0BAH
ADCON   DATA    0D8H

BD      BIT     0D8H.7

InitSerial:     PROMCHECK               ; Check if PROM in System
                CLR     TR1
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,#010H
L4:             JB      RXD,L4
L6:             JNB     RXD,L6
L7:             SETB    TR1
L8:             JNB     RXD,L10
                JNB     TF1,L8
L10:            JNB     RXD,L10
L12:            JNB     RXD,L14
                JNB     TF1,L12
L14:            JNB     RXD,L14
L15:            CLR     TR1
                JB      TF1,InitSerial
                MOV     R7,TL1
                MOV     R6,TH1

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
                MOV     SRELL,A
                MOV     A,#04H
                SUBB    A,R6
                MOV     SRELH,A

                SETB    BD
                ORL     PCON,#080H
                MOV     SCON,#05AH
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,A
L16:            CLR     RI
                JNB     RI,$
                MOV     A,SBUF
                CJNE    A,#011H,L16
                JMP     Mon51

$ELSEIF (SERIAL = 10)
;********************************************************************
;*  Using internal Baudrate Generator with serial interface 1       *
;*  Only for 80C517 and 80C517A                                     *
;*  Oscillator frequency = don't care                               *
;*  Automatic Baudrate Adjustment                                   *
;********************************************************************
S1REL   DATA    09DH
S1RELH  DATA    0BBH
S1CON   DATA    09BH
S1BUF   DATA    09CH
P6      DATA    0FAH
IEN2    DATA    09AH

InitSerial:     PROMCHECK               ; Check if PROM in System
                CLR     TR1
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,#010H
L4:             MOV     A,P6
                JB      ACC.1,L4
L6:             MOV     A,P6
                JNB     ACC.1,L6
L7:             SETB    TR1
L8:             MOV     A,P6
                JNB     ACC.1,L10
                JNB     TF1,L8
L10:            MOV     A,P6
                JNB     ACC.1,L10
L12:            MOV     A,P6
                JNB     ACC.1,L14
                JNB     TF1,L12
L14:            MOV     A,P6
                JNB     ACC.1,L14
L15:            CLR     TR1
                JB      TF1,InitSerial
                MOV     R7,TL1
                MOV     R6,TH1

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
                MOV     S1REL,A
                MOV     A,#04H
                SUBB    A,R6
                MOV     S1RELH,A

                MOV     S1CON,#10111010B ; Init Serial Interface
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,A
L16:            ANL     S1CON,#0FEH
L17:            MOV     A,S1CON
                JNB     ACC.0,L17
                MOV     A,S1BUF
                CJNE    A,#011H,L16
                JMP     Mon51


$ELSEIF (SERIAL = 11)
;********************************************************************
;*  Using Timer 2 to generate Baud Rates                            *
;*  for Dallas 80C320/520/530 with multiple data pointer support    *
;*  Oscillator frequency = don't care                               *
;*  Automatic Baudrate Adjustment                                   *
;********************************************************************
T2CON   DATA    0C8H
T2MOD   DATA    0C9H
RC2L    DATA    0CAH
RC2H    DATA    0CBH
TL2     DATA    0CCH
TH2     DATA    0CDH
TR2     BIT     0C8H.2
TF2     BIT     0C8H.7
  
InitSerial:     PROMCHECK               ; Check if PROM in System
                CLR     A
                MOV     RC2H,A
                MOV     RC2L,A
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
                MOV     RC2L,A
                MOV     TL2,A
                CLR     A
                SUBB    A,R6
                MOV     RC2H,A
                MOV     TH2,A

                MOV     T2CON,#034H
                MOV     SCON,#05AH
L16:            CLR     RI
                JNB     RI,$
                MOV     A,SBUF
                CJNE    A,#011H,L16
                JMP     Mon51


$ELSEIF (SERIAL = 12)
;********************************************************************
;*  Using second serial interface of Dallas 80C320/520/530 with     *
;*  Timer 1 and multiple data pointer support                       *
;*  Oscillator frequency = don't care                               *
;*  Automatic Baudrate Adjustment                                   *
;********************************************************************
DPS     DATA    086H
CKCON   DATA    08EH
SCON1   DATA    0C0H
SBUF1   DATA    0C1H
WDCON   DATA    0D8H
RI1     BIT     0C0H.0
RXD1    BIT     P1.2

InitSerial:     PROMCHECK               ; Check if PROM in System
                MOV     DPS,#00H
                ORL     CKCON,#010H     ; Timer 1 uses a divide by 4 clock
                CLR     TR1
                CLR     TF1
                CLR     A
                MOV     TL1,A
                MOV     TH1,A
                MOV     TMOD,#010H
L4:             JB      RXD1,L4
L6:             JNB     RXD1,L6
L7:             SETB    TR1
L8:             JNB     RXD1,L10
                JNB     TF1,L8
L10:            JNB     RXD1,L10
L12:            JNB     RXD1,L14
                JNB     TF1,L12
L14:            JNB     RXD1,L14
L15:            CLR     TR1
                JB      TF1,InitSerial
                MOV     R7,TL1
                MOV     R6,TH1

                MOV     A,R7
                ADD     A,#040H
                MOV     R7,A
                CLR     A
                ADDC    A,R6
                MOV     R6,A

                MOV     A,R7
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
                MOV     TMOD,#00100000B ;C/T = 0, Mode = 2
                SETB    TR1
                ORL     WDCON,#080H
                MOV     SCON1,#05AH

L16:            CLR     RI1
                JNB     RI1,$
                MOV     A,SBUF1
                CJNE    A,#011H,L16
                JMP     Mon51

$ENDIF


$IF ((SERIAL = 3) OR (SERIAL = 10))
;********************************************************************
;*  Interface via additional 80517 UART                             *
;********************************************************************
SER_INT_ADR     EQU     83H             ; ADDRESS OF SERIAL INTERRUPT VECTOR
SER_INT_ADR_OFF EQU (INT_ADR_OFF + SER_INT_ADR)

INSTAT:         PUSH    B               ; INPUT STATUS OF SERIAL INTERFACE
                MOV     B,S1CON
                MOV     C,B.0
                POP     B
                RET

OUTSTAT:        PUSH    B               ; OUTPUT STATUS OF SERIAL INTERFACE
                MOV     B,S1CON
                MOV     C,B.1
                POP     B
                RET

INCHAR:         MOV     A,S1BUF         ; CHARACTER INPUT-ROUTINE 
                RET

OUTCHAR:        MOV     S1BUF,A         ; CHARACTER OUTPUT-ROUTINE 
                RET

CLR_TI:         ANL     S1CON,#11111101B ; CLEAR SERIAL TRANSMIT INTERRUPT FLAG
                RET

SET_TI:         ORL     S1CON,#00000010B ; SET SERIAL TRANSMIT INTERRUPT FLAG
                RET

CLR_RI:         ANL     S1CON,#11111110B ; CLEAR SERIAL RECEIVE INTERRUPT FLAG
                RET

CLR_SER_IE:     ANL     IEN2,#11111110B  ; CLEAR SERIAL INTERRUPT ENABLE FLAG
                RET

SET_SER_IE:     ORL     IEN2,#00000001B  ; SET SERIAL INTERRUPT ENABLE FLAG
                RET

BEFORE_GO:                               ; this code is executed before a
                RET                      ; a go or proc step is executed

AFTER_GO:                                ; this code is executed after a go
                RET                      ; command (when a breakpoint was set)

WR_CODE:        MOVX    @DPTR,A          ; insert different code here, but
                RET                      ; do not change any other register
                                         ; without saving it


$ELSEIF ((SERIAL = 5) OR (SERIAL = 12))
;********************************************************************
;*  Interface via additional 80C320 UART                            *
;********************************************************************
SER_INT_ADR     EQU     03BH            ; ADDRESS OF SERIAL INTERRUPT VECTOR
SER_INT_ADR_OFF EQU (INT_ADR_OFF + SER_INT_ADR)
TI1     BIT     0C1H
ES1     BIT     0AEH

INSTAT:         MOV     C,RI1           ; INPUT STATUS OF SERIAL INTERFACE
                RET

OUTSTAT:        MOV     C,TI1           ; OUTPUT STATUS OF SERIAL INTERFACE
                RET

INCHAR:         MOV     A,SBUF1         ; CHARACTER INPUT-ROUTINE
                RET

OUTCHAR:        MOV     SBUF1,A         ; CHARACTER OUTPUT-ROUTINE
                RET

CLR_TI:         CLR     TI1             ; CLEAR SERIAL TRANSMIT INTERRUPT FLAG
                RET

SET_TI:         SETB    TI1             ; SET SERIAL TRANSMIT INTERRUPT FLAG
                RET

CLR_RI:         CLR     RI1             ; CLEAR SERIAL RECEIVE INTERRUPT FLAG
                RET

CLR_SER_IE:     CLR     ES1             ; CLEAR SERIAL INTERRUPT ENABLE FLAG
                RET

SET_SER_IE:     SETB    ES1             ; SET SERIAL INTERRUPT ENABLE FLAG
                RET

BEFORE_GO:                              ; this code is executed before a
                RET                     ; a go or proc step is executed

AFTER_GO:                               ; this code is executed after a go
                RET                     ; command (when a breakpoint was set)

WR_CODE:        MOVX    @DPTR,A         ; insert different code here, but
                RET                     ; do not change any other register
                                        ; without saving it


$ELSEIF (SERIAL = 6)
;********************************************************************
;*  Interface via external UART 16450/16550                         *
;********************************************************************
SER_INT_ADR     EQU     023H            ; ADDRESS OF SERIAL INTERRUPT VECTOR
SER_INT_ADR_OFF EQU (INT_ADR_OFF + SER_INT_ADR)

INSTAT:         PUSH    DPL             ; INPUT STATUS OF SERIAL INTERFACE
                PUSH    DPH
                PUSH    ACC
                MOV     DPTR,#SIOADDR+5 ; LSR
                MOVX    A,@DPTR         ; Check if Ready
                MOV     C,ACC.0
                POP     ACC        
                POP     DPH        
                POP     DPL        
                RET

OUTSTAT:        PUSH    DPL             ; OUTPUT STATUS OF SERIAL INTERFACE
                PUSH    DPH
                PUSH    ACC
                MOV     DPTR,#SIOADDR+5 ; LSR
                MOVX    A,@DPTR         ; Check if Ready
                MOV     C,ACC.5
                POP     ACC
                POP     DPH
                POP     DPL
                RET

INCHAR:         PUSH    DPL             ; CHARACTER INPUT-ROUTINE
                PUSH    DPH
                MOV     DPTR,#SIOADDR
                MOVX    A,@DPTR
                POP     DPH        
                POP     DPL        
                RET

OUTCHAR:        PUSH    DPL             ; CHARACTER OUTPUT-ROUTINE
                PUSH    DPH
                MOV     DPTR,#SIOADDR
                MOVX    @DPTR,A
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

BEFORE_GO:                              ; this code is executed before a
                RET                     ; a go or proc step is executed

AFTER_GO:                               ; this code is executed after a go
                RET                     ; command (when a breakpoint was set)

WR_CODE:        MOVX    @DPTR,A         ; insert different code here, but
                RET                     ; do not change any other register
                                        ; without saving it


$ELSE 

;********************************************************************
;*  Interface via standard 8051 UART                                *
;********************************************************************
SER_INT_ADR     EQU     23H             ; ADDRESS OF SERIAL INTERRUPT VECTOR
SER_INT_ADR_OFF EQU (INT_ADR_OFF + SER_INT_ADR)

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

BEFORE_GO:                              ; this code is executed before a
                RET                     ; a go or proc step is executed

AFTER_GO:                               ; this code is executed after a go
                RET                     ; command (when a breakpoint was set)

WR_CODE:        MOVX    @DPTR,A         ; insert different code here, but
                RET                     ; do not change any other register
                                        ; without saving it


$ENDIF


                END

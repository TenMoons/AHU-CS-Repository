$TITLE ('Configuration for MON390   (C) 2002 KEIL')
;------------------------------------------------------------------------------
;
;  MON390 CONFIGURATION FOR DALLAS CONTIGIOUS MODE
;  COPYRIGHT KEIL ELEKTRONIK GmbH 2001 - 2002                          *
;
;------------------------------------------------------------------------------
;
; Chip Specific Options (MCON needs to be set before ACON)
; ========================================================
;
; IDM1, IDM0:  Internal Data Memory Configuration Bits (MCON.7, MCON.6)
IDM  EQU 0  ; 0 = 4KB on-chip SRAM location X:0x00F000 - X:0x00FFFF
;           ; 1 = 4KB on-chip SRAM location X:0x000000 - X:0x000FFF
;           ; 2 = 4KB on-chip SRAM location X:0x400000 - X:0x400FFF
;           ; 3 = 4KB on-chip SRAM location X:0x400000 - X:0x400FFF
;                 and code memory C:0x400000 - C:0x400FFF
;
; CMA: CAN Data Memory Assignment (MCON.5)
CMA  EQU 0  ; 0 = CAN0 X:0x00EE00 - X:0x00EEFF, CAN1 X:0x00EF00 - X:0x00EFFF
            ; 1 = CAN0 X:0x401000 - X:0x4010FF, CAN1 X:0x401100 - X:0x4011FF
;
;
; SA: Extend Stack Address Mode Enable (ACON.2)
SA   EQU 0  ; 0 = 8051 compatible stack in IDATA memory
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
$SET (SERIAL = 0)       ; 0 = use SERIAL PORT0 for Monitor Communcation
                        ; 1 = use SERIAL PORT1 for Monitor Communcation
;
;------------------------------------------------------------------------------
;  Memory Mapping
;
; Monitor Code and Data Memory
MON_CODE_START  EQU     0000000H  ; start address of Monitor code area in CODE memory
MON_RAM_START   EQU     001FFE0H  ; start address of Monitor data area in XDATA memory

; User Code Memory (von-Neumann mapped)
CODE_RAM_START  EQU     0001000H  ; start address of user CODE space in XDATA memory
                                  ; (von Neumann mapping)
INT_ADR_OFF     EQU     0001000H  ; Interrupt Vector Offset if MON390 is installed at 
                                  ; address 0000H
CODE_RAM_END    EQU     001EFFFH  ; end address of user CODE space in XDATA memory

;------------------------------------------------------------------------------
;
; Extended Stack Mapping
STK_BASE0       EQU     000DC00H  ; Stack Start for: IDM1=0, IDM0=0 
STK_BASE1       EQU     0002000H  ; Stack Start for: IDM1=0, IDM0=1
STK_BASE2       EQU     0FFDC00H  ; Stack Start for: IDM1=1, IDM0=0 
STK_BASE3       EQU     0FFDC00H  ; Stack Start for: IDM1=1, IDM0=1 (invalid) 
;
;------------------------------------------------------------------------------

NAME	CONFIG

PUBLIC	RECEIVEBYTE         ; CHARACTER INPUT-ROUTINE 
PUBLIC	SENDBYTE            ; CHARACTER OUTPUT-ROUTINE 
PUBLIC	SENDCHECK           ; CHECK OUTPUT STATUS OF SERIAL INTERFACE
PUBLIC  SERINT_ENABLE       ; ENABLE SERIAL INTERRUPT
PUBLIC  SERINT_DISABLE      ; DISABLE SERIAL INTERRUPT
PUBLIC  IDENT_STRING        ; IDENTIFIER STRING
PUBLIC  INT_ADR_OFF         ; OFFSET FOR INTERRUPT VECTORS
PUBLIC  SER_INT_OFF         ; ADDRESS OFFSET OF SERIAL INTERRUPT VECTOR
PUBLIC  CODE_RAM_START      ; USER CODE START
PUBLIC  CODE_RAM_END        ; USER CODE END
PUBLIC  MON_CODE_START      ; MON390 CODE START
PUBLIC  BEFORE_GO           ; DO SOME THINGS BEFORE STARTING USER PROGRAM
PUBLIC  AFTER_GO            ; DO SOME THINGS AFTER TERMINATION OF USER PROGRAM
PUBLIC  WR_CODE             ; WRITE CODE BYTE
PUBLIC  WR_XDATA            ; WRITE XDATA BYTE
PUBLIC  STK_BASE            ; RETURN EXTENDED STACK BASE (DEVICE DEPENDANT)

EXTRN ECODE:FAR (MONSTART)    ; START OF MONITOR-51
EXTRN ECODE:FAR (MONBREAK)    ; BREAK RESTART OF MONITOR-251  
EXTRN ECODE:FAR (SERBREAK)    ; SERIAL INTERRUPT ENTRY OF MONITOR-251

SINTENABLE	LIT	'(MONDATA+ 30)'

; SFR SYMBOLS
TMOD    DATA    89H
TH1     DATA    8DH
SCON0   DATA    98H
CKCON	DATA	8EH
TCON	DATA	88H
TR1     BIT     8EH
SBUF    DATA    99H
TI      BIT     99H
RI      BIT     98H
ACC     DATA    0E0H
ES	BIT	0ACH
EX0     BIT     0A8H
PSW1	DATA	0D1H
PCON	DATA	087H
EA	BIT	0AFH
IPH0	DATA	0B7H
IPL0	DATA	0B8H
P1	DATA	090H
sfr     ACON  = 0x9D
sfr     TA    = 0xC7
sfr	MCON  = 0xC6
sfr	P4CNT = 0x92	

FILLGAP         MACRO
		NOP
		NOP
		NOP
		NOP
		ENDM


?PR?INITSEG	SEGMENT ECODE AT MON_CODE_START
		RSEG	?PR?INITSEG

		DB	02H		      ; LJMP in Classic 8051 Mode
		DW	WORD0 STARTUP1
		LJMP	INT_ADR_OFF + 03H
		FILLGAP
		LJMP	INT_ADR_OFF + 0BH
		FILLGAP
		LJMP	INT_ADR_OFF + 13H
		FILLGAP
		LJMP	INT_ADR_OFF + 1BH
		FILLGAP
$IF (SERIAL = 0 OR SERIAL = 1 OR SERIAL = 2)
SER_INT_OFF     EQU     23H                     ; OFFSET OF SERIAL INTERRUPT VECTOR
		LJMP	SERBREAK		; On-chip UART Device Interrupt
$ELSE
		LJMP	INT_ADR_OFF + 23H
$ENDIF
		FILLGAP
		LJMP	INT_ADR_OFF + 2BH
		FILLGAP
		LJMP	INT_ADR_OFF + 33H
		FILLGAP
		LJMP	INT_ADR_OFF + 3BH
		FILLGAP
		LJMP	INT_ADR_OFF + 43H
		FILLGAP
		LJMP	INT_ADR_OFF + 4BH
		FILLGAP
		LJMP	INT_ADR_OFF + 53H
		FILLGAP
		LJMP	INT_ADR_OFF + 5BH
		FILLGAP
		LJMP	INT_ADR_OFF + 63H
		FILLGAP
		LJMP	INT_ADR_OFF + 6BH
		FILLGAP
		LJMP	INT_ADR_OFF + 73H
		FILLGAP
		LJMP	INT_ADR_OFF + 7BH
		FILLGAP
		LJMP	INT_ADR_OFF + 83H
		FILLGAP
		LJMP	INT_ADR_OFF + 8BH
		FILLGAP
		LJMP	INT_ADR_OFF + 93H
		FILLGAP
		LJMP	INT_ADR_OFF + 9BH
		FILLGAP
		LJMP	INT_ADR_OFF + 0A3H
		FILLGAP
		LJMP	INT_ADR_OFF + 0ABH
		FILLGAP
		LJMP	INT_ADR_OFF + 0B3H
		FILLGAP
		LJMP	INT_ADR_OFF + 0BBH
		FILLGAP
		LJMP	INT_ADR_OFF + 0C3H
		FILLGAP
		LJMP	INT_ADR_OFF + 0CBH
		FILLGAP
		LJMP	INT_ADR_OFF + 0D3H
		FILLGAP
		LJMP	INT_ADR_OFF + 0DBH
		FILLGAP
		LJMP	INT_ADR_OFF + 0E3H
		FILLGAP
		LJMP 	INT_ADR_OFF + 0F3H
		FILLGAP
		LJMP	INT_ADR_OFF + 0FBH

		
STARTUP1:   	MOV     TA,#0xAA        ; Enable access to MCON
                MOV     TA,#0x55
MCON_VAL SET (IDM SHL 6) OR (CMA SHL 5) OR (PDCE3 SHL 3) OR (PDCE2 SHL 2)
MCON_VAL SET MCON_VAL OR (PDCE1 SHL 1) OR (PDCE0)
                MOV     MCON,#MCON_VAL

		MOV     TA,#0xAA        ; Enable access to ACON
                MOV     TA,#0x55
ACON_VAL EQU (2 OR (SA SHL 2)) ; 22-bit contigious mode, SA bit
                MOV     ACON,#ACON_VAL

; Set Port 4 Function Control (P4CNT)
P4_VAL   EQU P4PF OR (PCES SHL 3)
		MOV     P4CNT,#P4_VAL
 
MonitorStart:	MOV     R0,#0		
		MOV     R1,#0
		MOV	A,#01H
Flashloop:      MOV	P1,A
		RL	A
FWait_State:    NOP
		NOP
		NOP
		DJNZ    R0,FWait_State
                DJNZ    R1,FWait_State
		RL	A
	      	ADD	A,ACC
		JNZ     Flashloop
                MOV     P1,#0FFH

/*
 *	Work-Around for SerInit on int. S0 19200@40Mhz
 */

		LJMP	InitSerial

;---- Setup for Serial Interfaces.

$IF (SERIAL = 0)
;********************************************************************
;*  Using TIMER 1 to Generate Baud Rates                            *
;*  Oscillator frequency = 40.000 MHz                               *
;*  Set Baudrate to 38400 Baud                                       *
;********************************************************************

InitSerial:	ORL	PCON, #080H
	        MOV     SCON0,#050H		         
    		ORL     TMOD, #021H           
    		MOV     TH1,  #0F8H   
                ORL     CKCON,#010H
   		MOV	TCON, #050H              
    		ORL     SCON0,#002H   

		JMP	MONSTART
IDENT_STRING:	DB    	 'MONITOR-390 USING TIMER 1 FOR BAUDRATES',0

$ENDIF

$IF (SERIAL = 1)
;********************************************************************
;*  Using TIMER 2 to Generate Baud Rates                            *
;********************************************************************
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
T2CON   DATA    0C8H

RCAPVAL EQU  (65536 - ((XTAL / BAUDRATE)/16))

InitSerial:	LABEL   FAR
		LJMP	Next
Next:		MOV	T2CON,#30H
		MOV	RCAP2H,#HIGH (RCAPVAL)
		MOV	RCAP2L,#LOW (RCAPVAL)
	        SETB	T2CON.2         ; start timer
		MOV	SCON,#01011010B ; Init Serial Interface
		LJMP	MONSTART

IDENT_STRING:	DB	'MONITOR-390 USING TIMER 2 FOR BAUDRATES',0
$ENDIF

$IF (SERIAL = 0 OR SERIAL = 1)
;********************************************************************
;*  Interface via standard on-chip UART                             *
;********************************************************************

SENDBYTE	PROC	NEAR
		ORL  	P1,#1
		CLR	TI		; Only A & PSW can be destroyed!
		MOV	SBUF,A
		ORL  	P1,#1
		RET
        	ENDP

SENDCHECK	PROC	NEAR
		JNB	TI,$		; Only A & PSW can be destroyed!
		RET
         	ENDP

RECEIVEBYTE	PROC	NEAR
		ORL  	P1,#2	
		JNB	RI,$		; Only A & PSW can be destroyed!
		MOV	A,SBUF
		CLR	RI
		ORL  	P1,#2
		RET
           	ENDP

SERINT_ENABLE	PROC	NEAR
		CLR	TI		; No Transmitter Interrupt yet
		SETB	ES              ; Enable Serial Interrupt
		RET
		ENDP

SERINT_DISABLE  PROC    NEAR
		CLR	ES		; Disable Serial Interrupt
		SETB	TI		; Set Transmitter Interrupt Flag
		RET
		ENDP


$ENDIF

;-----------------------------------------------------------------------------

BEFORE_GO:                               ; this code is executed before a
                RET                      ; a go or proc step is executed

AFTER_GO:                                ; this code is executed after a go
                RET                      ; command (when a breakpoint was set)
                
WR_XDATA:	  MOVX    @DPTR,A          ; insert different code here, but
                RET                      ; do not change any other register
                                         ; without saving it                

WR_CODE:        MOVX    @DPTR,A          ; insert different code here, but
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



PUBLIC	MONDATA
?FD?MON_DATA	SEGMENT	HDATA  AT MON_RAM_START
          	RSEG	?FD?MON_DATA
MONDATA:	DS	32		; Monitor data area; DO NOT CHANGE SIZE
MONDATA_CODE    EQU MON_RAM_START
PUBLIC  MONDATA_CODE
		END


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
$SET (DS80C390=0)
$SET (DS80C400=0)
$SET (DS5240=1)
$SET (DS5250=0)


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
MON_CODE_START  EQU     0001400H  ; start address of Monitor code area in CODE memory
MON_RAM_START   EQU     0000400H  ; start address of Monitor data area in XDATA memory

; User Code Memory (von-Neumann mapped)
CODE_RAM_START  EQU     0002000H  ; start address of user CODE space in XDATA memory
                                  ; (von Neumann mapping)
INT_ADR_OFF     EQU     0002000H  ; Interrupt Vector Offset if MON390 is installed at 
                                  ; address 0000H
CODE_RAM_END    EQU     001EFFFH  ; end address of user CODE space in XDATA memory

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
PUBLIC  RD_XDATA            ; READ XDATA BYTE


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
P0	DATA	080H
SP	DATA	081H
sfr     ACON  = 0x9D
sfr     TA    = 0xC7
sfr	MCON  = 0xC6
sfr	P4CNT = 0x92
sfr	b     = 0x90
sfr     IE    = 0xA8
sfr     DPL   = 0x82
sfr     DPH   = 0x83


$IF (DS5240 = 1 OR DS5250 = 1)
;
; 5240 Regs
;
PBCD	DATA	0DEh
PBCC	DATA	0DFh
RAMST	DATA	0D1h
R0_B0	DATA	0h
R0_B3	DATA	011h
R1_B3	DATA	012h
R2_B3	DATA	013h
R3_B3	DATA	014h
R4_B3	DATA	015h
R5_B3	DATA	016h
R6_B3	DATA	017h
R7_B3	DATA	018h
dps	DATA	086h
dpx	DATA	093h
ROMST	DATA	0D9h	
$ENDIF

$IF (DS5250 = 1)
;
;5250 REGS
;
PKA     DATA    0DDh
$ENDIF

FILLGAP         MACRO
		NOP
		NOP
		NOP
		NOP
		ENDM


$IF (DS5240 = 1 OR DS5250 = 1) 
;
; Locate in 5240 VECTOR RAM
;
?PR?INITSEG	SEGMENT ECODE AT 0
$ELSE
?PR?INITSEG	SEGMENT ECODE AT MON_CODE_START
$ENDIF
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

$IF (DS5240 = 1 OR DS5250 = 1) 

WR_CODE:
 
		push	R0_B0
		push	R0_B3
		push	R1_B3
		push	R2_B3
		push	R3_B3
		push	R4_B3
		push	R5_B3
		push	R6_B3
		push	R7_B3
		push	IE
		push	b
		push	acc
		push	dpl
		push	dph
		push	dpx
		push	dps


		;
		; Clear interrupts
		;
		clr	EA
		mov	dps,#0
		;
		; Enter User Loader Mode, Mr. Sulu
		; Aye, Sir
		;
		
		mov	TA,#0AAh
		mov	TA,#055h
		orl	ACON,#040h
		
		;
		; Program memory is ours now for the taking! OURS!
		; GUAH HAH HAH HAH HA!!!!
		; Save DPTR for now.
		; 
		;push	PBCC
		push	dpl
		push	dph
		push	acc


		;
		; We need to read a bank (8 bytes) of memory.
		; Mask off dpl, read 8 bytes, and move it into
		; the progran block decryptor
		;
		anl	PBCC,#0FDh
		anl	dpl,#0F8h
		mov	b,#8

$if (DS5250 = 1)
		mov	PKA,dpx
		mov	PKA,dph
		mov	PKA,dpl
$endif	

writeuserbyte_loop1:
		movx	a,@dptr
		mov	PBCD,a
		inc	dptr
		djnz	b,writeuserbyte_loop1

		nop
		nop
		nop
		nop
		nop
		

		;
		; Pull the data out of the decrypter
		;
		mov	R0_B3,PBCD
		mov	R1_B3,PBCD
		mov	R2_B3,PBCD
		mov	R3_B3,PBCD
		mov	R4_B3,PBCD
		mov	R5_B3,PBCD
		mov	R6_B3,PBCD
		mov	R7_B3,PBCD

		
		
		;
		; Hackity hack hack!
		; Indirectly change the data
		; to the new byte
		;

		; Point to first register
		mov	R0,#R0_B3


		
		; Restore the pointers and data
		pop	acc
		pop	dph
		pop	dpl

		; Sneak our new byte into the data
		mov	b,a
		mov	a,dpl
		anl	a,#07h
		add	a,R0
		mov	R0,a
		mov	a,b
		mov	@R0,a
  		
		
		; Re-encrypt the data
		orl	PBCC,#02h

$if (DS5250 = 1)
		mov	PKA,dpx
		mov	PKA,dph
		mov	PKA,dpl
$endif
		
		mov	PBCD,R0_B3
		mov	PBCD,R1_B3
		mov	PBCD,R2_B3
		mov	PBCD,R3_B3
		mov	PBCD,R4_B3
		mov	PBCD,R5_B3
		mov	PBCD,R6_B3
		mov	PBCD,R7_B3


		nop
		nop
		nop
		nop
		nop



		anl	dpl,#0F8h
		mov	b,#8
writeuserbyte_loop2:
		mov	a,PBCD
		movx	@dptr,a
		inc	dptr
		djnz	b,writeuserbyte_loop2

		anl	PBCC,#0FDh

		mov	TA,#0AAh
		mov	TA,#055h
		anl	ACON,#NOT(040h)

	
		
		pop	dps
		pop	dpx
		pop	dph
		pop	dpl
		pop	acc
		pop	b
		pop	IE
		pop	R7_B3
		pop	R6_B3
		pop	R5_B3
		pop	R4_B3
		pop	R3_B3
		pop	R2_B3
		pop	R1_B3
		pop	R0_B3

		pop	R0_B0
		ret

;
; Work around for errata condition 8
;
WR_XDATA:
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		movx @dptr,a
		ret
RD_XDATA:
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		nop
		movx a,@dptr
		ret


DALLASSEG	SEGMENT ECODE AT MON_CODE_START
		RSEG	DALLASSEG

$ENDIF
		
STARTUP1:
$IF ((DS80C390 = 1) or (DS80C400 = 1))
                MOV     TA,#0xAA        ; Enable access to MCON
                MOV     TA,#0x55
MCON_VAL SET (IDM SHL 6) OR (CMA SHL 5) OR (PDCE3 SHL 3) OR (PDCE2 SHL 2)
MCON_VAL SET MCON_VAL OR (PDCE1 SHL 1) OR (PDCE0)
                MOV     MCON,#MCON_VAL

$endif
		MOV     TA,#0xAA        ; Enable access to ACON
                MOV     TA,#0x55
ACON_VAL EQU (2 OR (SA SHL 2)) ; 22-bit contigious mode, SA bit
                MOV     ACON,#ACON_VAL

$IF (DS5240 = 1 OR DS5250 = 1)
      		;
		; Turn off extended stack
		;


		;push	IE
		clr	EA
 
		mov	a,ACON
		anl	a,#0FBh
		mov	TA,#0AAh
		mov	TA,#055h
		mov	ACON,a

		mov	SP,#07Fh
		
		;
		; Set RAM1 to Program/Data Memory
		;		
		mov	a,RAMST
		orl	a,#030h
		mov	TA,#0AAh
		mov	TA,#055h
		mov	RAMST,a

		setb	EA
		
		;pop	IE
$ENDIF

$IF ((DS80C390 = 1) OR (DS80C400 = 1))
; Set Port 4 Function Control (P4CNT)
P4_VAL   EQU P4PF OR (PCES SHL 3)
		MOV     P4CNT,#P4_VAL
$ENDIF
 
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
    		MOV     TH1,  #0E8H  ;#0F8h    
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
$IF (DS5240 = 0 AND DS5250 = 0)

WR_XDATA:	MOVX    @DPTR,A          ; insert different code here, but
                RET                      ; do not change any other register
                                         ; without saving it                

WR_CODE:        MOVX    @DPTR,A          ; insert different code here, but
                RET                      ; do not change any other register
                                         ; without saving it

$ENDIF

;-----------------------------------------------------------------------------



PUBLIC	MONDATA
?FD?MON_DATA	SEGMENT	HDATA  AT MON_RAM_START
          	RSEG	?FD?MON_DATA
MONDATA:	DS	32		; Monitor data area; DO NOT CHANGE SIZE
MONDATA_CODE    EQU MON_RAM_START
PUBLIC  MONDATA_CODE
		END


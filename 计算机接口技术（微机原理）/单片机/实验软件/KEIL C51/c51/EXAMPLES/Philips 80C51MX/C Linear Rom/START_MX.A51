$MOD_MX51
;------------------------------------------------------------------------------
;  This file is part of the PK51 Professional Developers Kit
;  Startup Code for the Philips 80C51MX architecture
;  Copyright (c) 2000-2002 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 1.02
;------------------------------------------------------------------------------
;  START_MX.A51:  This code is executed after processor reset.
;  You may add this file to a uVision2 project.
;
;  To translate this file manually use AX51 with the following invocation:
;
;     AX51 START_MX.A51  
;
;  To link the modified START_MX.OBJ file to your application use the
;  following LX51 invocation:
;
;     LX51 START_MX.OBJ, <your object file list> <controls>
;
;------------------------------------------------------------------------------
;
;  Setup 80C51MX Configuration Register (MXCON)
;
; Extended Addressing Mode (enable upper address multiplex on Port 2)
; EAM        Val  Description
; ---        ---  -----------
EAM EQU  1  ; 0 = do not change configuration state of the CPU
;           ; 1 = enable extended addressing mode (multiplex A16..A22 on Port 2)
;
; Extended Stack Memory Mode (16-bit Stack Pointer)
; ESMM       Val  Description
; ----       ---  -----------
ESMM EQU 0  ; 0 = classic 8051 stack pointer (8-bit) addressing IDATA space
;           ; 1 = extended 16-bit stack pointer addressing EDATA space
;
; Extended Interrupt Frame
; EIFM       Val  Description
; --         ---  -----------
EIFM EQU 1  ; 0 = classic 8051 interrupt frame (16-bit address pushed)
;           ; 1 = extended 24-bit interrupt frame (3 bytes pushed on interrupt)
;
;
;
;  Setup Additional Features (AUXR, AUXR1)
;
; XDATA access (External XDATA space)
; EXTRAM     Val  Description
; ---        ---  -----------
EXTRAM EQU 0; 0 = access on-chip XDATA RAM 
;           ; 1 = disable on-chip XDATA and access off-chip XDATA space
;
; ALE (Address Latch Enable) Output Signal 
; AO         Val  Description
; --         ---  -----------
AO   EQU 0  ; 0 = ALE signal is generate at a constant rate 
;           ; 1 = ALE signal is active only during a MOVX or MOVC instruction
;
; Low Volatage (Vcc) configuration
; LPEP       Val  Description
; ----       ---  -----------
LPEP EQU 0  ; 0 = chip supply volatage (Vcc) is above 4V
;           ; 1 = chip supply volatage (Vcc) is below 4V
;------------------------------------------------------------------------------
;
;  CPU Stack Size Definition 
;
;  The following EQU statement defines the stack space available in extended
;  stack mode (ESMM set to 1) for the application program.  It should be noted
;  that the stack space must be adjusted according the actual requirements of 
;  the application.
;
STACKSIZE	EQU	100H	; set to 100H Bytes.
;
;------------------------------------------------------------------------------
;
;  User-defined Power-On Initialization of Memory
;
;  With the following EQU statements the initialization of memory
;  at processor reset can be defined:
;
;		; the absolute start-address of IDATA memory is always 0
IDATALEN	EQU	0FFH	; the length of IDATA memory in bytes.
;
XDATASTART	EQU	0H	; the absolute start-address of XDATA memory
XDATALEN	EQU	0H	; the length of XDATA memory in bytes.
;
PDATASTART	EQU	0H	; the absolute start-address of PDATA memory
PDATALEN	EQU	0H	; the length of PDATA memory in bytes.
;
;  Notes:  The IDATA space overlaps physically the DATA and BIT areas of the
;          80C51MX CPU.
;------------------------------------------------------------------------------
;
;  Reentrant Stack Initilization
;
;  The following EQU statements define the stack pointer for reentrant
;  functions and initialized it:
;
;  Stack Space for reentrant functions in the SMALL model.
IBPSTACK	EQU	0	; set to 1 if small reentrant is used.
IBPSTACKTOP	EQU	0FFH+1	; set top of stack to highest location+1.
;
;  Stack Space for reentrant functions in the LARGE model.	
XBPSTACK	EQU	0	; set to 1 if large reentrant is used.
XBPSTACKTOP	EQU	0FFFFH+1; set top of stack to highest location+1.
;
;  Stack Space for reentrant functions in the COMPACT model.	
PBPSTACK	EQU	0	; set to 1 if compact reentrant is used.
PBPSTACKTOP	EQU	0FFFFH+1; set top of stack to highest location+1.
;
;------------------------------------------------------------------------------
;
;  Page Definition for Using the Compact Model with 64 KByte xdata RAM
;
;  The following EQU statements define the xdata page used for pdata
;  variables. The EQU PPAGE must conform with the PPAGE control used
;  in the linker invocation.
;
PPAGEENABLE	EQU	0	; set to 1 if pdata object are used.
PPAGE		EQU	0	; define PPAGE number.
;
;------------------------------------------------------------------------------

; Define CPU Symbols
sfr SP     = 0x81;
sfr SPE    = 0x1FB;
sfr AUXR   = 0x8E;
sfr AUXR1  = 0xA2;
sfr MXCON  = 0x1FF;

		NAME	?C_STARTUP

?C_C51STARTUP	SEGMENT   CODE

IF ESMM == 1

?STACK		SEGMENT   EDATA
		RSEG	?STACK
		DS	STACKSIZE	; Stack Space 100H Bytes

ELSE

?STACK		SEGMENT   IDATA
		RSEG	?STACK
		DS	1

ENDIF


		EXTRN CODE (?C_START)
		PUBLIC	?C_STARTUP

		CSEG	AT	0
?C_STARTUP:	LJMP	STARTUP1

		
                CSEG    AT      7BH
STARTUP1:
; Init MXCON
_VMXCON EQU (EAM SHL 2) OR (ESMM SHL 1) OR (EIFM)
IF _VMXCON
                MOV     MXCON,#_VMXCON
ENDIF
		LJMP	STARTUP2


		RSEG	?C_C51STARTUP

STARTUP2:
; Init AUXR
_VAUXR  EQU (EXTRAM SHL 1) OR (AO)
IF _VAUXR
                MOV     AUXR,#_VAUXR
ENDIF

; Init AUXR1
_VAUXR1 EQU (LPEP SHL 4)
IF _VAUXR1
                MOV     AUXR1,#_VAUXR1
ENDIF

IF IDATALEN <> 0
		MOV	R0,#IDATALEN - 1
		CLR	A
IDATALOOP:	MOV	@R0,A
		DJNZ	R0,IDATALOOP
ENDIF

IF XDATALEN <> 0
		MOV	R1,#BYTE0 XDATASTART
		MOV	R2,#BYTE1 XDATASTART
		MOV	R3,#BYTE2 XDATASTART
		MOV	R7,#BYTE0 (XDATALEN)
  IF (BYTE0 (XDATALEN)) <> 0
		MOV	R6,#(BYTE1 (XDATALEN)) +1
  ELSE
		MOV	R6,#BYTE1 (XDATALEN)
  ENDIF
  IF (WORD0 (XDATALEN)) <> 0
                MOV     R5,#(BYTE2 (XDATALEN)) + 1
  ELSE
                MOV     R5,#BYTE2 (XDATALEN)
  ENDIF
		CLR	A
XDATALOOP:	EMOV	@PR0,A
		ADD	PR0,#1
		DJNZ	R7,XDATALOOP
		DJNZ	R6,XDATALOOP
		DJNZ	R5,XDATALOOP
ENDIF

IF PPAGEENABLE <> 0
		MOV	P2,#PPAGE
ENDIF

IF PDATALEN <> 0
		MOV	R0,#PDATASTART
		MOV	R7,#LOW (PDATALEN)
		CLR	A
PDATALOOP:	MOVX	@R0,A
		INC	R0
		DJNZ	R7,PDATALOOP
ENDIF

IF IBPSTACK <> 0
EXTRN DATA (?C_IBP)

		MOV	?C_IBP,#LOW IBPSTACKTOP
ENDIF

IF XBPSTACK <> 0
EXTRN DATA (?C_XBP)

		MOV	?C_XBP,#HIGH XBPSTACKTOP
		MOV	?C_XBP+1,#LOW XBPSTACKTOP
ENDIF

IF PBPSTACK <> 0
EXTRN DATA (?C_PBP)
		MOV	?C_PBP,#LOW PBPSTACKTOP
ENDIF

IF (ESMM)
		MOV	SP,#BYTE0 (?STACK-1)    ; Initilize Extended Stack Pointer
		MOV     SPE,#BYTE1 (?STACK-1)
ELSE
		MOV	SP,#?STACK-1            ; Initilize Classic 8051 Stack
ENDIF
		LJMP	?C_START


		END

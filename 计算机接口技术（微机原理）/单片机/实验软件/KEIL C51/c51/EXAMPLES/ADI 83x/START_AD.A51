$NOMOD51
;------------------------------------------------------------------------------
;  This file is part of the C51 Compiler package
;  Startup Code for the Analog Devices ADuC83x and ADuC84x series
;  Copyright (c) 2001-2003 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 1.02
;------------------------------------------------------------------------------
;  START_AD.A51:  This code is executed after processor reset.
;
;  To translate this file use Ax51 with the following invocation:
;
;     Ax51 STARTUP.A51
;
;  To link the modified STARTUP.OBJ file to your application use the following
;  Lx51 invocation:
;
;     Lx51 <your object file list>, STARTUP.OBJ <controls>
;
;------------------------------------------------------------------------------
;
;  Setup Extended Data RAM
;
; On-chip XDATA RAM
; XRAMEN     Val  Description
; ------     ---  -----------
XRAMEN EQU 0; 0 = disable on-chip XDATA RAM and access off-chip XDATA space
;           ; 1 = enable on-chip XDATA RAM
;
; Extended Stack Mode (16-bit Stack Pointer)
; EXSP       Val  Description
; ----       ---  -----------
EXSP EQU 0  ; 0 = classic 8051 stack pointer (8-bit) addressing IDATA space
;           ; 1 = extended 16-bit stack pointer addressing XDATA space
; NOTE: The Extended Stack Mode works only with enabled on-chip XDATA RAM!
;
; CPU Stack Size Definition in Extended Stack Mode:
; The following EQU statements defines the stack space available in extended
; stack mode (EXSP set to 1) for the application program.  It should be noted
; that the stack space must be adjusted according the actual requirements of 
; the application.  This STARTUP file allocates the stack in extended stack
; mode in XDATA memory beginning at XSTACKSTART.  The extended stack must
; be within the on-chip XDATA memory and XSTACKSTART must be not less than
; 100H. 
;
STACKSIZE   EQU 200H             ; set to 200H Bytes.
XSTACKSTART EQU 800H - STACKSIZE ; 800H is top of on-chip XRAM.
;
;------------------------------------------------------------------------------
;
;  User-defined Power-On Initialization of Memory
;
;  With the following EQU statements the initialization of memory
;  at processor reset can be defined:
;
;		; the absolute start-address of IDATA memory is always 0
IDATALEN	EQU	80H	; the length of IDATA memory in bytes.
;
XDATASTART	EQU	0H	; the absolute start-address of XDATA memory
XDATALEN	EQU	0H	; the length of XDATA memory in bytes.
;
PDATASTART	EQU	0H	; the absolute start-address of PDATA memory
PDATALEN	EQU	0H	; the length of PDATA memory in bytes.
;
;  Notes:  The IDATA space overlaps physically the DATA and BIT areas of the
;          8051 CPU. At minimum the memory space occupied from the C51 
;          run-time routines must be set to zero.
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
PPAGEENABLE	EQU	1	; set to 1 if pdata object are used.
PPAGE		EQU	0	; define PPAGE number.
;
;------------------------------------------------------------------------------

; Define CPU Symbols
sfr SP     = 0x81;
sfr SPH    = 0xB7;
sfr CFG8xx = 0xAF;    ; Chip Configuration SFR
sfr P2     = 0xA0;

IF (EXSP = 1) AND (XRAMEN = 0)
  __error__ "Extended Stack Mode requires enabled on-chip XDATA RAM"
ENDIF

IF (EXSP = 1) AND (XSTACKSTART < 100H)
  __error__ "Extended Stack must start in XRAM above address 100H"
ENDIF

		NAME	?C_STARTUP


?C_C51STARTUP	SEGMENT   CODE

IF (EXSP = 1)
		XSEG	AT XSTACKSTART
		DS	STACKSIZE	; Stack Space 200H Bytes
ELSE
?STACK		SEGMENT   IDATA
		RSEG	?STACK
		DS	1
ENDIF

		EXTRN CODE (?C_START)
		PUBLIC	?C_STARTUP

		CSEG	AT	0
?C_STARTUP:	LJMP	STARTUP1

		RSEG	?C_C51STARTUP

STARTUP1:

_CFG8xx EQU (EXSP SHL 7) OR (XRAMEN)

IF _CFG8xx
		ORL     CFG8xx,#_CFG8xx    ; set extended memory modes
ENDIF

IF IDATALEN <> 0
		MOV	R0,#IDATALEN - 1
		CLR	A
IDATALOOP:	MOV	@R0,A
		DJNZ	R0,IDATALOOP
ENDIF

IF XDATALEN <> 0
		MOV	DPTR,#XDATASTART
		MOV	R7,#LOW (XDATALEN)
  IF (LOW (XDATALEN)) <> 0
		MOV	R6,#(HIGH (XDATALEN)) +1
  ELSE
		MOV	R6,#HIGH (XDATALEN)
  ENDIF
		CLR	A
XDATALOOP:	MOVX	@DPTR,A
		INC	DPTR
		DJNZ	R7,XDATALOOP
		DJNZ	R6,XDATALOOP
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

IF EXSP = 1
                MOV     SP,#LOW (XSTACKSTART-1)
                MOV     SPH,#HIGH (XSTACKSTART-1)
ELSE
		MOV	SP,#?STACK-1
ENDIF

;EXTRN CODE (?B_SWITCH0)
;               CALL    ?B_SWITCH0      ; init bank mechanism to code bank 0
                LJMP	?C_START

		END

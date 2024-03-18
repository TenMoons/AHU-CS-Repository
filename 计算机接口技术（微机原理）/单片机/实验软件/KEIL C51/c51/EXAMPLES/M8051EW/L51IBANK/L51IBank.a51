$NOMOD51 NOLINES
$NOCOND
;------------------------------------------------------------------------------
;  This file is part of the LX51 Banked Linker/Locater package
;  Copyright (c) 1988 - 2002 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 0.02 (Code and Variable Banking for Mentor M8051EW based devices)
;------------------------------------------------------------------------------
;
;  This file implements code and variable banking for Mentor M8051EW based
;  devices, which offer three memory extension registers MEX1, MEX2 and MEX3.
;  *** Important Notes ***  
;
;  1.  Full support for Mentor M8051EW based devices requires the LX51 linker/
;      locater.  This file does not work with the BL51 linker/locater.
;
;  2.  The C51 Compiler must be invoked with the directive VARBANKING(1)
;      in order to use this file.   It is unimportant if you are using 
;      variable banking (far memory type) in your application.
;
;  3.  This file contains also the CPU startup code
;  
;  4.  You need to use the C51 run-time library files C51M*.LIB.
;
;************************ Configuration Section *******************************
?B_NBANKS       EQU  4    ; Define maximum Number of Banks                    *
;                         ; following values are allowed: 2 .. 16             *
;                                                                             *
?B_CB           EQU  3    ; Define Memory Bank used for constants             *
;                         ; following values are allowed: 0 .. 7              *
;                         ; The value 0xFF uses the current program code bank *
;                         ; as constant bank                                  *
;                                                                             *
?B_VAR_BANKING  EQU  0    ; XDATA Variable Banking (far memory type support)  *
;                         ; 0 XDATA Variable Banking no required              *
;                         ; 1 XDATA Variable Banking uses this L51IBANK.A51   *
;                         ;   module                                          *
; Notes: ?B_VAR_BANKING uses the C51 'far' memory type to extent the space    *
;        for variables in RAM space of the M8051EW device.                    *
;                                                                             *
;******************************************************************************
;------------------------- CPU STARTUP CONFIGURATION --------------------------
;
;  User-defined Power-On Initialization of Memory
;
;  With the following EQU statements the initialization of memory
;  at processor reset can be defined:
;
;               ; the absolute start-address of IDATA memory is always 0
IDATALEN        EQU     80H     ; the length of IDATA memory in bytes.
;
XDATASTART      EQU     0H      ; the absolute start-address of XDATA memory
XDATALEN        EQU     0H      ; the length of XDATA memory in bytes.
;
PDATASTART      EQU     0H      ; the absolute start-address of PDATA memory
PDATALEN        EQU     0H      ; the length of PDATA memory in bytes.
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
IBPSTACK        EQU     0       ; set to 1 if small reentrant is used.
IBPSTACKTOP     EQU     0FFH+1  ; set top of stack to highest location+1.
;
;  Stack Space for reentrant functions in the LARGE model.      
XBPSTACK        EQU     0       ; set to 1 if large reentrant is used.
XBPSTACKTOP     EQU     0FFFFH+1; set top of stack to highest location+1.
;
;  Stack Space for reentrant functions in the COMPACT model.    
PBPSTACK        EQU     0       ; set to 1 if compact reentrant is used.
PBPSTACKTOP     EQU     0FFFFH+1; set top of stack to highest location+1.
;
;------------------------------------------------------------------------------
;
;  Page Definition for Using the Compact Model with 64 KByte xdata RAM
;
;  The following EQU statements define the xdata page used for pdata
;  variables. The EQU PPAGE must conform with the PPAGE control used
;  in the linker invocation.
;
PPAGEENABLE     EQU     0       ; set to 1 if pdata object are used.
;
PPAGE           EQU     0       ; define PPAGE number.
;
PPAGE_SFR       DATA    0A0H    ; SFR that supplies uppermost address byte
;               (most 8051 variants use P2 as uppermost address byte)
;
;------------------------------------------------------------------------------

                NAME    ?BANK?SWITCHING


;******************************************************************************
;                                                                             *
; THEORY OF OPERATION                                                         *
; -------------------                                                         *
; The section below describes the code generated by LX51.  LX51 generates for *
; each function that is located in a code memory bank and called from the     *
; common area or a different code bank and entry into the INTRABANK CALL      *
; TABLE.  The INTRABANK CALL TABLE is located in the SEGMENT ?BANK?SELECT and *
; listed in the Linker MAP file. The entries in that TABLE have the following *
; format:                                                                     *
;                                                                             *
;   ?FCT?1:  MOV  MEX1,#n          ; Load bank number of target FCT           *
;            LJMP FCT              ; Jump to Target Code                      *
;                                                                             *
; Instead of directly calling the function FCT, the Linker changes the entry  *
; to ?FCT?1.  This entry selects the bank where the function FCT is located   *
; and jumps to that function.                                                 *
;******************************************************************************

; Standard SFR Symbols 
ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    81H
DPL     DATA    82H
DPH     DATA    83H


; Definitions for Mentor Memory Extension Hardware
MEX1    DATA    94H
MEX2    DATA    95H
MEX3    DATA    96H
MEXSP   DATA    97H

?B_MODE         EQU     8        ; 8 for Mentor EW8051 integrated MEX Banking
?B_RST_BANK     EQU     0        ; active code bank after CPU reset
?B_IB           EQU     0        ; use Bank 0 for Interrupt Functions
?B_CURRENTBANK  EQU     MEX1     ; MEX1.4 .. 7 hold current code bank
?B_FACTOR       EQU     4        ; ?B_CURRENTBANK shift factor
?B_MASK         EQU     0F0H     ; valid bits in ?B_CURRENTBANK
?B_MEX1         EQU     MEX1     ; address of next bank register

                PUBLIC  ?B_NBANKS, ?B_MODE
                PUBLIC  ?B_CURRENTBANK
                PUBLIC  ?B_FACTOR, ?B_RST_BANK
                PUBLIC  ?B_IB, ?B_CB, ?B_MEX1


?C_C51STARTUP   SEGMENT   CODE
?STACK          SEGMENT   IDATA

                RSEG    ?STACK
                DS      1

                EXTRN CODE (?C_START)
                PUBLIC  ?C_STARTUP

                CSEG    AT      0
?C_STARTUP:     LJMP    STARTUP1

                RSEG    ?C_C51STARTUP

STARTUP1:

IF IDATALEN <> 0
                MOV     R0,#IDATALEN - 1
                CLR     A
IDATALOOP:      MOV     @R0,A
                DJNZ    R0,IDATALOOP
ENDIF

IF XDATALEN <> 0
                MOV     DPTR,#XDATASTART
                MOV     R7,#LOW (XDATALEN)
  IF (LOW (XDATALEN)) <> 0
                MOV     R6,#(HIGH (XDATALEN)) +1
  ELSE
                MOV     R6,#HIGH (XDATALEN)
  ENDIF
                CLR     A
XDATALOOP:      MOVX    @DPTR,A
                INC     DPTR
                DJNZ    R7,XDATALOOP
                DJNZ    R6,XDATALOOP
ENDIF

IF PPAGEENABLE <> 0
                MOV     PPAGE_SFR,#PPAGE
ENDIF

IF PDATALEN <> 0
                MOV     R0,#LOW (PDATASTART)
                MOV     R7,#LOW (PDATALEN)
                CLR     A
PDATALOOP:      MOVX    @R0,A
                INC     R0
                DJNZ    R7,PDATALOOP
ENDIF

IF IBPSTACK <> 0
EXTRN DATA (?C_IBP)

                MOV     ?C_IBP,#LOW IBPSTACKTOP
ENDIF

IF XBPSTACK <> 0
EXTRN DATA (?C_XBP)

                MOV     ?C_XBP,#HIGH XBPSTACKTOP
                MOV     ?C_XBP+1,#LOW XBPSTACKTOP
ENDIF

IF PBPSTACK <> 0
EXTRN DATA (?C_PBP)
                MOV     ?C_PBP,#LOW PBPSTACKTOP
ENDIF

                MOV     SP,#?STACK-1

; Configure Memory Extension Registers
MEX2VAL         SET     0

IF ?B_CB <> 0xFF
MEX2VAL         SET     ((?B_CB AND 7) SHL 4) OR 80H
ENDIF

MEX2VAL         SET     MEX2VAL OR ?B_IB

                MOV     MEX2,#MEX2VAL
                MOV     MEXSP,#7FH      ; set to bottom of stack

                LJMP    ?C_START


IF ?B_VAR_BANKING <> 0 ;----- XDATA Variable Banking

;******************************************************************************
;                                                                             *
; THEORY OF OPERATION                                                         *
; -------------------                                                         *
; This section describes how the extended LX51 linker/locater manages the     *
; extended address spaces that are addressed with the new C51 memory types    *
; 'far' and 'far const'.  The C51 Compiler uses 3 byte pointer generic        *
; pointer to access these memory areas.  'far' variables are placed in the    *
; memory class HDATA and 'far const' variables get the memory class 'HCONST'. *
; The LX51 linker/locater allows you to locate these memory classes in the    *
; logical 16 MBYTE CODE or 16 MBYTE XDATA spaces.                             *
;                                                                             *
; The memory access itself is performed via eight different subroutines that  *
; can be configured in this assembler module.  These routines are:            *
;    ?C?CLDXPTR, ?C?CSTXPTR  ; load/store BYTE (char)  in extended memory     *
;    ?C?ILDXPTR, ?C?ISTXPTR  ; load/store WORD (int)   in extended memory     *
;    ?C?PLDXPTR, ?C?PSTXPTR  ; load/store 3-BYTE PTR   in extended memory     *
;    ?C?LLDXPTR, ?C?LSTXPTR  ; load/store DWORD (long) in extended memory     *
;                                                                             *
; Each function gets as a parameter the memory address with 3 BYTE POINTER    *
; representation in the CPU registers R1/R2/R3.  The register R3 holds the    *
; memory type.  The C51 compiler uses the following memory types:             *
;                                                                             *
; R3 Value | Memory Type | Memory Class | Address Range                       *
; -----------------------+--------------+--------------------------           *
;    00    | data/idata  | DATA/IDATA   | I:0x00     .. I:0xFF                *
;    01    | xdata       | XDATA        | X:0x0000   .. X:0xFFFF              *
;  02..7F  | far         | HDATA        | X:0x010000 .. X:0x7E0000            *
;  80..FD  | far const   | HCONST       | C:0x800000 .. C:0xFD0000 (see note) *
;    FE    | pdata       | XDATA        | one 256-byte page in XDATA memory   *
;    FF    | code        | CODE         | C:0x0000   .. C:0xFFFF              *
;                                                                             *
; Note: the far const memory area is mapped into the banked memory areas.     *
;                                                                             *
; The R3 values 00, 01, FE and FF are already handled within the C51 run-time *
; library.  Only the values 02..FE are passed to the XPTR access functions    *
; described below.  The AX51 macro assembler provides the MBYTE operator      *
; that calculates the R3 value that needs to be passed to the XPTR access     *
; function.   AX51 Assembler example for using XPTR access functions:         *
;     MOV  R1,#LOW   (variable)   ; gives LSB address byte of variable        *
;     MOV  R1,#HIGH  (variable)   ; gives MSB address byte of variable        *
;     MOV  R1,#MBYTE (variable)   ; gives memory type byte of variable        *
;     CALL ?C?CLDXPTR             ; load BYTE variable into A                 *
;******************************************************************************


?C?XPAGE1SFR	EQU	MEX3
?C?XPAGE1RST	EQU	0

PUBLIC ?C?XPAGE1SFR, ?C?XPAGE1RST
PUBLIC ?C?CLDXPTR, ?C?CSTXPTR, ?C?ILDXPTR, ?C?ISTXPTR
PUBLIC ?C?PLDXPTR, ?C?PSTXPTR, ?C?LLDXPTR, ?C?LSTXPTR

?C?LIB_CODE	SEGMENT	CODE
		RSEG	?C?LIB_CODE

LOAD_BANK	MACRO
LOCAL lab
		MOV	DPL,R1
		MOV	DPH,R2
		MOV	?C?XPAGE1SFR,R3	
		ANL	?C?XPAGE1SFR,#07FH
		CJNE	R3,#80H,lab
lab:
		ENDM


B	DATA 0F0H	; SFR Address
DPL	DATA 082H
DPH	DATA 083H
ACC	DATA 0E0H

; CLDXPTR: Load   BYTE in A             via Address given in R1/R2/R3


?C?CLDXPTR:	LOAD_BANK
                JNC	CLDCODE
		DEC	?C?XPAGE1SFR
		MOVX	A,@DPTR
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET
CLDCODE:	CLR	A
		MOVC	A,@A+DPTR
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

; CSTXPTR: Store  BYTE in A             via Address given in R1/R2/R3


?C?CSTXPTR:	LOAD_BANK
                JNC	CSTCODE
		DEC	?C?XPAGE1SFR
		MOVX	@DPTR,A
CSTCODE:	MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

; ILDXPTR: Load   WORD in A(LSB)/B(HSB) via Address given in R1/R2/R3 

?C?ILDXPTR:	LOAD_BANK
                JNC	ILDCODE
		DEC	?C?XPAGE1SFR
		MOVX	A,@DPTR
		MOV	B,A
		INC	DPTR
		MOVX	A,@DPTR
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET
ILDCODE:	CLR	A
		MOVC	A,@A+DPTR
		MOV	B,A
		MOV	A,#1
		MOVC	A,@A+DPTR
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

; ISTXPTR: Store  WORD in A(HSB)/B(LSB) via Address given in R1/R2/R3 
?C?ISTXPTR:	LOAD_BANK
                JNC	ISTCODE
		DEC	?C?XPAGE1SFR
		MOVX	@DPTR,A
		INC	DPTR
		MOV	A,B
		MOVX	@DPTR,A
ISTCODE:	MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET


; PLDXPTR: Load    PTR in R1/R2/R3      via Address given in R1/R2/R3 
?C?PLDXPTR:	LOAD_BANK
                JNC	PLDCODE
		DEC	?C?XPAGE1SFR
		MOVX	A,@DPTR
		MOV	R3,A
		INC	DPTR
		MOVX	A,@DPTR
		MOV	R2,A
		INC	DPTR
		MOVX	A,@DPTR
		MOV	R1,A
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET
PLDCODE:	CLR	A
		MOVC	A,@A+DPTR
		MOV	R3,A
		MOV	A,#1
		MOVC	A,@A+DPTR
		MOV	R2,A
		MOV	A,#2
		MOVC	A,@A+DPTR
		MOV	R1,A
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

; PSTXPTR: Store   PTR in R0/A/B        via Address given in R1/R2/R3 
?C?PSTXPTR:	LOAD_BANK
                JNC	PSTCODE
		DEC	?C?XPAGE1SFR
		XCH	A,B
		MOVX	@DPTR,A
		INC	DPTR
		XCH	A,B
		MOVX	@DPTR,A
		INC	DPTR
		MOV	A,R0
		MOVX	@DPTR,A
PSTCODE:	MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

; LLDXPTR: Load  DWORD in R4/R5/R6/R7   via Address given in R1/R2/R3 
?C?LLDXPTR:	LOAD_BANK
                JNC	LLDCODE
		DEC	?C?XPAGE1SFR
		MOVX	A,@DPTR
		MOV	R4,A
		INC	DPTR
		MOVX	A,@DPTR
		MOV	R5,A
		INC	DPTR
		MOVX	A,@DPTR
		MOV	R6,A
		INC	DPTR
		MOVX	A,@DPTR
		MOV	R7,A
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET
LLDCODE:	CLR	A
		MOVC	A,@A+DPTR
		MOV	R4,A
		MOV	A,#1
		MOVC	A,@A+DPTR
		MOV	R5,A
		MOV	A,#2
		MOVC	A,@A+DPTR
		MOV	R6,A
		MOV	A,#3
		MOVC	A,@A+DPTR
		MOV	R7,A
		MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

; LSTXPTR: Store DWORD in R4/R5/R6/R7   via Address given in R1/R2/R3 
?C?LSTXPTR:	LOAD_BANK
                JNC	LSTCODE
		DEC	?C?XPAGE1SFR
		MOV	A,R4
		MOVX	@DPTR,A
		INC	DPTR
		MOV	A,R5
		MOVX	@DPTR,A
		INC	DPTR
		MOV	A,R6
		MOVX	@DPTR,A
		INC	DPTR
		MOV	A,R7
		MOVX	@DPTR,A
LSTCODE:	MOV	?C?XPAGE1SFR,#?C?XPAGE1RST ; Reset Page Register 
		RET

ENDIF ; IF ?B_VAR_BANKING <> 0 ----- XDATA Variable Banking


                END

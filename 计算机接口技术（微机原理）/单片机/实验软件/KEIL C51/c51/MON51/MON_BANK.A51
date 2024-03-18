$NOCOND DEBUGPUBLICS
;------------------------------------------------------------------------------
;  This file is part of the Monitor-51 Version 3 package
;  Copyright KEIL ELEKTRONIK GmbH 1998
;  Version 3.0
;
;  Most of the settings in this file must conform with the settings
;  in the file L51_BANK.A51 which is used for code banking with the
;  BL51 Linker/Locater
;
;------------------------------------------------------------------------------
;************************ Configuration Section *******************************
?B_NBANKS       EQU     8        ; Define max. Number of Code Banks (not      *
;                                ; including XDATA or COMMON bank).           *
;                                ; The max. value for ?B_BANKS is 32          *
;                                ; possible values are: 1,2,3,...32           *
;                                                                             *
?B_MODE         EQU     0        ; 0 for Bank-Switching via 8051 Port         *
;                                ; 1 for Bank-Switching via XDATA Port        *
;                                                                             *
?B_BANKSTART    EQU     08000H   ; defines the start address of the code      *
;                                ; banking area                               *
;                                                                             *
?B_BANKEND      EQU     0FFFFH   ; defines the end address of the code        *
;                                ; banking area                               *
;                                                                             *
?B_COMMON       EQU     0FFH     ; 0FFH if the COMMON area is not mapped into *
;                                ; a code bank.                               *
;                                ; otherwise ?B_COMMON must be set to the     *
;                                ; bank number which contains the COMMON area *
;                                                                             *
?B_XRAM         EQU     0FFH     ; 0FFH if the XDATA RAM area is not mapped   *
;                                ; into a code bank.                          *
;                                ; otherwise ?B_XRAM must be set to the bank  *
;                                ; number which contains the XDATA RAM area   *
;                                                                             *
?B_MON_DATA_BANK EQU    007H     ; Bank number where monitor data is stored   *
;                                                                             *
IF  ?B_MODE = 0;                                                              *
;-----------------------------------------------------------------------------*
; if ?BANK?MODE is 0 define the following values                              *
; For Bank-Switching via 8051 Port define Port Address / Bits                 *
?B_PORT         EQU     P1       ; default is P1                              *
?B_FIRSTBIT     EQU     3        ; default is Bit 3                           *
;-----------------------------------------------------------------------------*
ENDIF;                                                                        *
;
IF  ?B_MODE = 1;                                                              *
;-----------------------------------------------------------------------------*
; if ?BANK?MODE is 1 define the following values                              *
; For Bank-Switching via XDATA Port define XDATA Port Address / Bits          *
?B_XDATAPORT    EQU     0FFFFH   ; default is XDATA Port Address 0FFFFH       *
?B_FIRSTBIT     EQU     0        ; default is Bit 0                           *
;-----------------------------------------------------------------------------*
ENDIF;                                                                        *
;                                                                             *
;                                                                             *
;******************************************************************************

                NAME    ?BANK?SWITCHING

                PUBLIC  ?B_NBANKS	; Number of Banks
		PUBLIC	?B_MODE		; Banking Mode (currently 0)
		PUBLIC	?B_COMMON	; Bank Number of the COMMON area
		PUBLIC	?B_XRAM  	; Bank Number of the XDATA RAM area
		PUBLIC  ?B_SWITCHBANK	; Change to the Bank specified in ACC
		PUBLIC	?B_GETCURRBANK	; Returns in ACC the current Code Bank
		PUBLIC	?B_BANKSTART	; Banking Area Start Address
		PUBLIC	?B_BANKEND	; Banking Area End Address
		PUBLIC	?B_INITBANKING	; e.g. Initialize the Bank Ident Number
                PUBLIC  ?B_MON_DATA_BANK; Bank number where monitor data is stored

; generate Mask and Bank Number Information
IF      ?B_NBANKS <= 2
  MASK          EQU     00000001B
ELSEIF  ?B_NBANKS <= 4
  MASK          EQU     00000011B
ELSEIF  ?B_NBANKS <= 8
  MASK          EQU     00000111B
ELSEIF  ?B_NBANKS <= 16
  MASK          EQU     00001111B
ELSE
  MASK          EQU     00011111B
ENDIF     

?B_MASK         EQU     MASK SHL ?B_FIRSTBIT


CODE_AREA	SEGMENT	CODE
		RSEG	CODE_AREA

  IF  ?B_FIRSTBIT = 0
  CONVTOPIN     MACRO
                ENDM
  ENDIF
  IF  ?B_FIRSTBIT = 1
  CONVTOPIN     MACRO
                RL      A
                ENDM
  ENDIF
  IF  ?B_FIRSTBIT = 2
  CONVTOPIN     MACRO
                RL      A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONVTOPIN     MACRO
                SWAP    A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONVTOPIN     MACRO
                SWAP    A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONVTOPIN     MACRO
                SWAP    A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONVTOPIN     MACRO
                RR      A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONVTOPIN     MACRO
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 0
  CONVTOBANK    MACRO
                ENDM
  ENDIF
  IF  ?B_FIRSTBIT = 1
  CONVTOBANK    MACRO
                RR      A
                ENDM
  ENDIF
  IF  ?B_FIRSTBIT = 2
  CONVTOBANK    MACRO
                RR      A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONVTOBANK    MACRO
                SWAP    A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONVTOBANK    MACRO
                SWAP    A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONVTOBANK    MACRO
                SWAP    A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONVTOBANK    MACRO
                RL      A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONVTOBANK    MACRO
                RL      A
                ENDM
  ENDIF

;------------------------
;  Switchbank function
;------------------------
 
IF  ?B_MODE = 0;
?B_SWITCHBANK:
IF  ?B_COMMON <> 0FFH
		CJNE	A,#0FFH,SWB1
		MOV	A,#?B_COMMON
ENDIF
SWB1:		ANL	A,#MASK
                CONVTOPIN
                ANL     ?B_PORT,#LOW (NOT ?B_MASK)
		ORL	?B_PORT,A
		NOP
		RET
ENDIF

IF  ?B_MODE = 1;
?B_SWITCHBANK:	PUSH	DPL
		PUSH	DPH
IF  ?B_COMMON <> 0FFH
		CJNE	A,#0FFH,SWB1
		MOV	A,#?B_COMMON
ENDIF
SWB1:		ANL	A,#MASK
                CONVTOPIN
                MOV     DPTR,#?B_XDATAPORT
                MOVX    @DPTR,A
		POP	DPH
		POP	DPL
		RET
ENDIF

;------------------------
; Getbank function
;------------------------

IF  ?B_MODE = 0;
?B_GETCURRBANK:	MOV	A,?B_PORT
                CONVTOBANK
		ANL	A,#MASK
		RET
ENDIF

IF  ?B_MODE = 1;
?B_GETCURRBANK:	PUSH	DPL
		PUSH	DPH
		MOV	DPTR,#?B_BANKEND
		CLR	A
		MOVC	A,@A+DPTR
		ANL	A,#MASK
		POP	DPH
		POP	DPL
		RET
ENDIF

;------------------------
; Init banking system
;------------------------

?B_INITBANKING:	
; -----
; Add here code for user hardware initilization

; -----

IF  ?B_MODE = 1;  Write bank number into the last byte of each bank
		MOV	A,#?B_NBANKS
INIT_LOOP:	DEC	A
INIT1:		CJNE	A,#?B_XRAM,INIT2
		SJMP	INIT_LOOP
INIT2:		CJNE	A,#?B_COMMON,INIT3
		SJMP	INIT_LOOP
INIT3:		PUSH	ACC
		CALL	?B_SWITCHBANK
		POP	ACC
		MOV	DPTR,#?B_BANKEND		
		MOVX	@DPTR,A
		JNZ	INIT_LOOP
ENDIF
		RET

                END

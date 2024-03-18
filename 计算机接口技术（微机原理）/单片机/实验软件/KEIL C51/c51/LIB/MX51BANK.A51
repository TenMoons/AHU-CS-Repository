$NOCOND MOD_MX51 NOLINES
;------------------------------------------------------------------------------
;  This file is part of the PK51 Professional Developers Kit
;  Support for large programs on Philips 80C51MX architecture
;  Copyright (c) 2000-2002 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 1.02
;------------------------------------------------------------------------------
;************************ Configuration Section *******************************
;  Program Code in expanded memory is supported via the code banking machnism
;  known from the classic 8051 architecture.  You need to specify the number
;  of code banks that are required for your application.
;
?B_NBANKS       EQU     2        ; Define max. Number of Banks
;                                ; the max. value for ?B_BANKS is 16
;******************************************************************************
;                                                                             *
?B_MODE         EQU     2        ; 2 for using Philips 80C51MX address lines

; Define SFR Registers
ACC     DATA    0E0H
PSW     DATA    0D0H
DPL     DATA    82H
DPH     DATA    83H

PUBLIC  ?B_BANKSTARTSEG
?B_BANKSTARTSEG EQU     080H
?B_FIRSTBIT     EQU     0        ; set to  0


                NAME    ?BANK?SWITCHING

                PUBLIC  ?B_NBANKS, ?B_MODE, ?B_CURRENTBANK, ?B_MASK
                PUBLIC  ?B_FACTOR
                PUBLIC  SWITCHBANK

?B_FACTOR       EQU     1 SHL ?B_FIRSTBIT

?C_INITSEG      SEGMENT   CODE          ; Segment zur Initialisierung
                RSEG    ?C_INITSEG
                DB      01H             ; IData
                DB      ?B_CURRENTBANK  ; Init Current Bank
                DB      0               ; Set to Zero

?BANK?DATA      SEGMENT DATA
                RSEG    ?BANK?DATA
?B_CURRENTBANK: DS      1

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

BANKN           MACRO   N
BANK&N           EQU     N SHL ?B_FIRSTBIT
                ENDM

CNT             SET     0

                REPT    ?B_NBANKS
                BANKN   %CNT
CNT             SET     CNT+1
                ENDM

  ; Convert Bank No in Accu to Address * 16
  IF  ?B_FIRSTBIT = 0
  CONVBANKNO    MACRO
                SWAP    A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 1
  CONVBANKNO    MACRO
                SWAP    A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 2
  CONVBANKNO    MACRO
                RL      A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONVBANKNO    MACRO
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONVBANKNO    MACRO
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONVBANKNO    MACRO
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONVBANKNO    MACRO
                RR      A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONVBANKNO    MACRO
                SWAP    A
                RL      A
                ENDM
  ENDIF


SELECT          MACRO   N
LOCAL           XLABEL, YLABEL

                PUBLIC  ?B_BANK&N
?B_BANK&N:      
                MOV     A,?B_CURRENTBANK
                ANL     A,#?B_MASK
                CJNE    A,#BANK&N,XLABEL
                SJMP    YLABEL

XLABEL:         CONVBANKNO         ; Convert Bank Number to Address
                PUSH    ACC
                MOV     A,#HIGH ?BANK?SWITCH
                PUSH    ACC
YLABEL:         PUSH    DPL
                PUSH    DPH
                LJMP    ?B_SWITCH&N

                ENDM


?BANK?SELECT    SEGMENT  CODE

                RSEG    ?BANK?SELECT
CNT             SET     0

                REPT    ?B_NBANKS
                SELECT  %CNT
CNT             SET     CNT+1

                ENDM


SWITCH          MACRO   N
                ORG     N * 16
                PUBLIC  ?B_SWITCH&N
    ?B_SWITCH&N:
                ORL     ?B_CURRENTBANK,#?B_MASK
    IF  N <> (?B_NBANKS-1)
                ANL     ?B_CURRENTBANK,#(BANK&N OR NOT ?B_MASK) 
    ENDIF
                
                DB      0A5H            ; ESC
                DB      002H            ; EJMP Instruction
                DB      LOW (N+?B_BANKSTARTSEG)
                DW      SWITCHDONE
                ENDM


?BANK?SWITCH    SEGMENT  CODE  PAGE

                RSEG    ?BANK?SWITCH
CNT             SET     0

                REPT    ?B_NBANKS
                SWITCH  %CNT

CNT             SET     CNT+1
                ENDM

RSEG            ?BANK?SELECT

;************************  SWITCHBANK FUNCTION  *******************************
;                                                                             *
; SWITCHBANK allows use of bank-switching for C programs                      *
;                                                                             *
; prototype:   extern switchbank (unsigned char bank_number);                 *
;                                                                             *
;******************************************************************************

SWITCHBANK:     MOV     A,R7
                SWAP    A
                MOV     DPTR,#?BANK?SWITCH
                JMP     @A+DPTR
SWITCHDONE:     RET

                END

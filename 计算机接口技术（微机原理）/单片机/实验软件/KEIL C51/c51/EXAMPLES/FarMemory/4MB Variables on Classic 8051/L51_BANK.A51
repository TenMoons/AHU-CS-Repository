$NOMOD51 NOLINES
$NOCOND
;------------------------------------------------------------------------------
;  This file is part of the BL51 / LX51 Banked Linker/Locater package
;  Copyright (c) 1988 - 2001 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 2.21 (Code and Variable Banking for Classic 8051 Derivatives)
;------------------------------------------------------------------------------
;************************ Configuration Section *******************************
?B_NBANKS       EQU  4    ; Define maximum Number of Banks                    *
;                         ; following values are allowed: 2, 4, 8, 16, 32, 64 *
;                         ; for BL51 the maximum value for ?B_BANKS is 32     *
;                         ; for LX51 the maximum value for ?B_BANKS is 64     *
;                                                                             *
?B_MODE         EQU  0    ; 0 for Bank-Switching via 8051 Port                *
;                         ; 1 for Bank-Switching via XDATA Port               *
;                         ; 4 for user-provided bank switch code              *
;                                                                             *
?B_RTX          EQU  0    ; 0 for applications without real-time OS           *
;                         ; 1 for applications using the RTX-51 real-time OS  *
;                                                                             *
?B_VAR_BANKING  EQU  1    ; Variable Banking via L51_BANK (far memory support)*
;                         ; 0 Variable Banking does not use L51_BANK.A51      *
;                         ; 1 Variable Banking uses this L51_BANK.A51 module  *
; Notes: ?B_VAR_BANKING uses the 'far' and 'far const' C51 memory types to    *
;        extent the space for variables in RAM and/or ROM of classic 8051     *
;        device.  The same hardware as for code banking is used.  Program     *
;        code banking and variable banking share the same hardware I/O pins.  *
;        The C51 Compiler must be used with the VARBANKING directive.         *
;        Variable Banking is only supported with the LX51 linker/locater.     *
;                                                                             *
?B_RST_BANK     EQU  0xFF ; specifies the active code bank number after CPU   *
;                         ; Reset.  Used to reduce the entries in the         *
;                         ; INTERBANK CALL TABLE.  The value 0xFF disables    *
;                         ; this LX51 linker/locater optimization.            *
; Note:  Interbank Call Table optimization is only possible with LX51.        *
;                                                                             *
;-----------------------------------------------------------------------------*
;                                                                             *
IF  ?B_MODE = 0;                                                              *
;-----------------------------------------------------------------------------*
; if ?BANK?MODE is 0 define the following values                              *
; For Bank-Switching via 8051 Port define Port Address / Bits                 *
;                                                                             *
P1              DATA    90H      ; I/O Port Address                           *
;                                                                             *
?B_PORT         EQU     P1       ; default is P1                              *
?B_FIRSTBIT     EQU     2        ; default is Bit 2                           *
;-----------------------------------------------------------------------------*
ENDIF;                                                                        *
;                                                                             *
IF  ?B_MODE = 1;                                                              *
;-----------------------------------------------------------------------------*
; if ?BANK?MODE is 1 define the following values                              *
; For Bank-Switching via XDATA Port define XDATA Port Address / Bits          *
?B_XDATAPORT    EQU     0FFFFH   ; default is XDATA Port Address 0FFFFH       *
?B_FIRSTBIT     EQU     0        ; default is Bit 0                           *
;-----------------------------------------------------------------------------*
ENDIF;                                                                        *
;                                                                             *
IF  ?B_MODE = 4;                                                              *
;-----------------------------------------------------------------------------*
; if ?BANK?MODE is 4 define the following switch macros                       *
; For bank switching via user-provided bank switch code you must define for   *
; each memory bank a own macro which contains the bank switch code.  The      *
; following example shows how to use the I/O lines P1.4 and P1.7 for bank     *
; switching.  Since you can select just 4 banks with two address lines, just  *
; four macros are defined.  The number of macros must conform with the number *
; ?B_NBANKS number, i.e. for an application with 16 memory banks you must     *
; define 16 macros.                                                           *
;                                                                             *
; IMPORTANT NOTES:                                                            *
; 1. The bank switch logic must be initialized before using it.  Therefore    *
;    add the following lines of code at the end of the STARTUP.A51 file:      *
;                :                                                            *
;      EXTRN CODE (?B_SWITCH0)                                                *
;               CALL    ?B_SWITCH0    ; init bank mechanism to code bank 0    *
;               LJMP    ?C_START      ; line already exits at the end of file *
;                :                                                            *
;                                                                             *
; 2. If the bank switch macros and the additional control code generate more  *
;    than 256 bytes, you need to set the LONG_MACRO flag below.  The error    *
;    message "BANK SWITCH CODE BIGGER THAN 256 BYTES, SET LONG_MACRO TO 1"    *
;    is generated in case that this is required.                              *
;                                                                             *
; 3. The only registers that can be modified in this routines without prior   *
;    saving are:  DPTR and ACC.                                               *
;                                                                             *
;                                                                             *
LONG_MACRO      EQU  0    ; 0 default, for normal macros and up to 8 banks    *
;                         ; 1 big macro code or many banks                    *
;                                                                             *
;                                                                             *
P1              DATA    90H      ; I/O Port Addresses                         *
P3              DATA    0B0H     ;                                            *
;                                                                             *
SWITCH0         MACRO            ; Switch to Memory Bank #0                   *
                CLR     P1.5     ; Clear Port 1 Bit 5                         *
                CLR     P3.3     ; Clear Port 3 Bit 3                         *
                ENDM             ;                                            *
;                                                                             *
SWITCH1         MACRO            ; Switch to Memory Bank #1                   *
                SETB    P1.5     ; Set   Port 1 Bit 5                         *
                CLR     P3.3     ; Clear Port 3 Bit 3                         *
                ENDM             ;                                            *
;                                                                             *
SWITCH2         MACRO            ; Switch to Memory Bank #2                   *
                CLR     P1.5     ; Clear Port 1 Bit 5                         *
                SETB    P3.3     ; Set   Port 3 Bit 3                         *
                ENDM             ;                                            *
;                                                                             *
SWITCH3         MACRO            ; Switch to Memory Bank #3                   *
                SETB    P1.5     ; Set   Port 1 Bit 5                         *
                SETB    P3.3     ; Set   Port 3 Bit 3                         *
                ENDM             ;                                            *
;                                                                             *
;-----------------------------------------------------------------------------*
ENDIF;                                                                        *
;									      *
IF ?B_VAR_BANKING = 1;                                                        *							        
;									      * 
XMEM EQU 0x02000000       ; LX51 xdata symbol offset: do not change!	      *
;									      *
;******* Configuration Section for uVision2 Memory Simulation Support *********
;                                                                             *
; The following settings allow you to map the physical xdata and code memory  *
; banks into simulation memory of the uVision2 Simulator.                     *
;                                                                             *
?B?XSTART EQU 0x8000      ; Start of xdata bank area                          *
?B?XEND   EQU 0xFFFF      ; Stop of xdata bank area                           *
?B?XMEM   EQU XMEM+0x010000  ; First HDATA memory bank in xdata space         *
;                                                                             *
; The above setting redirects the symbols in the area X:0x20000 .. X:0x2FFFF  *
; into the uVision2 simulation memory area for the EEPROM  V:0 .. V:0xFFFF    *
;                                                                             *
;-----------------------------------------------------------------------------*
;                                                                             *
                PUBLIC ?B?XSTART, ?B?XEND, ?B?XMEM;                           *
ENDIF;                                                                        *
;                                                                             *
;******************************************************************************
;                                                                             *
; THEORY OF OPERATION                                                         *
; -------------------                                                         *
; The section below describes the code generated by BL51 or LX51 and the      *
; operation of the L51_BANK.A51 module.  BL51/LX51 generates for each         *
; function that is located in a code memory bank and called from the common   *
; area or a different code bank and entry into the INTRABANK CALL TABLE.  The *
; INTRABANK CALL TABLE is located in the SEGMENT ?BANK?SELECT and listed in   *
; the Linker MAP file. The entries in that TABLE have the following format:   *
;                                                                             *
;   ?FCT?1:  MOV  DPTR,#FCT     ; Load Address of target FCT                  *
;            JMP  ?B_BANKn      ; Switch to Bank and Jump to Target Code      *
;                                                                             *
; Instead of directly calling the function FCT, the Linker changes the entry  *
; to ?FCT?1.  This entry selects the bank where the function FCT is located   *
; and calls that function via the routines defined in this L51_BANK.A51 file. *
; The L51_BANK.A51 file contains two sets of functions for each bank:         *
;                                                                             *
; ?B_BANKn    is a routine which saves the entry of the ?B_SWITCHn function   *
;             for the current active bank on the STACK and switches to the    *
;             bank 'n'.  Then it jumps to the address specified by the DPTR   *
;             register.  It is allowed to modify the following registers in   *
;             the ?B_BANKn routine:  A, B, R0, DPTR, PSW                      *
;                                                                             *
; ?B_SWITCHn  is a function which selects the bank 'n'.  This function is     *
;             used at the end of a user function to return to the calling     *
;             code bank.  Only the following registers may be altered in the  *
;             ?B_SWITCHn function:  R0, DPTR                                  *
;                                                                             *
; The current active bank is stored in ?B_CURRENTBANK.  RTX-51 uses this      *
; variable to restore the code bank after a task switch.  To get correct      *
; results, ?B_CURRENTBANK must be set to the code bank before the hardware    *
; switch is done, or the code banking sequences must be interrupt protected.  *
;******************************************************************************

                NAME    ?BANK?SWITCHING

                PUBLIC  ?B_NBANKS, ?B_MODE, ?B_CURRENTBANK, ?B_MASK
                PUBLIC  ?B_FACTOR, ?B_RST_BANK
IF (?B_RTX = 1)
                PUBLIC  ?B_RESTORE_BANK
ENDIF

; Standard SFR Symbols required in L51_BANK.A51
ACC     DATA    0E0H
B       DATA    0F0H
DPL     DATA    82H
DPH     DATA    83H
IE      DATA    0A8H
EA      BIT     IE.7


; generate Mask and Bank Number Information
IF      ?B_NBANKS <= 2
  MASK          EQU     00000001B
ELSEIF  ?B_NBANKS <= 4
  MASK          EQU     00000011B
ELSEIF  ?B_NBANKS <= 8
  MASK          EQU     00000111B
ELSEIF  ?B_NBANKS <= 16
  MASK          EQU     00001111B
ELSEIF  ?B_NBANKS <= 32
  MASK          EQU     00011111B
ELSE
  MASK          EQU     00111111B
ENDIF     

IF  ?B_MODE = 0 ;**************************************************************

?B_FACTOR       EQU     1 SHL ?B_FIRSTBIT

?B_MASK         EQU     MASK SHL ?B_FIRSTBIT

BANKN           MACRO   N
BANK&N           EQU     N SHL ?B_FIRSTBIT
                ENDM

CNT             SET     0

                REPT    ?B_NBANKS
                BANKN   %CNT
CNT             SET     CNT+1
                ENDM


?B_CURRENTBANK  EQU     ?B_PORT

  IF ?B_RTX = 1 OR ?B_NBANKS > 32
  ; Convert Bank No in Accu to Address * 4

  IF  ?B_FIRSTBIT = 0
  CONVBANKNO    MACRO
                RL      A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 1
  CONVBANKNO    MACRO
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 2
  CONVBANKNO    MACRO
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONVBANKNO    MACRO
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONVBANKNO    MACRO
                RR      A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONVBANKNO    MACRO
                SWAP    A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONVBANKNO    MACRO
                SWAP    A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONVBANKNO    MACRO
                SWAP    A
                RR      A
                ENDM
  ENDIF

  ; Macro code to select the 'N'
  SWITCH        MACRO   N
                ORG     N * 4
                PUBLIC  ?B_SWITCH&N
  ?B_SWITCH&N:
                MOV     R0,#(BANK&N OR NOT ?B_MASK) 
  IF ?B_NBANKS > 32
    IF (N < 32) 
                SJMP    SWITCHBNK_H
    ELSEIF (N = 32)
      SWITCHBNK_H:
                SJMP    SWITCHBNK
    ELSEIF (N <> ?B_NBANKS-1)
                SJMP    SWITCHBNK
    ENDIF
  ELSE
    IF N <> (?B_NBANKS-1)
                SJMP    SWITCHBNK
    ENDIF
  ENDIF

                ENDM

ENDIF


IF ?B_RTX = 0 AND ?B_NBANKS <= 32
  ; Convert Bank No in Accu to Address * 8

  IF  ?B_FIRSTBIT = 0
  CONVBANKNO    MACRO
                SWAP    A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 1
  CONVBANKNO    MACRO
                RL      A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 2
  CONVBANKNO    MACRO
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONVBANKNO    MACRO
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONVBANKNO    MACRO
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONVBANKNO    MACRO
                RR      A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONVBANKNO    MACRO
                SWAP    A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONVBANKNO    MACRO
                SWAP    A
                ENDM
  ENDIF


  ; Macro code to select the 'N'
  SWITCH        MACRO   N
                ORG     N * 8
                PUBLIC  ?B_SWITCH&N
  ?B_SWITCH&N:
    IF  N <> 0
                ORL     ?B_CURRENTBANK,#?B_MASK
    ENDIF
    IF  N <> (?B_NBANKS-1)
                ANL     ?B_CURRENTBANK,#(BANK&N OR NOT ?B_MASK) 
    ENDIF
                RET
                ENDM

ENDIF


SELECT          MACRO   N
LOCAL           XLABEL, YLABEL

                PUBLIC  ?B_BANK&N
?B_BANK&N:      
                MOV     A,?B_CURRENTBANK
                ANL     A,#?B_MASK
                CONVBANKNO         ; Convert Bank Number to Address
                PUSH    ACC
                MOV     A,#HIGH ?BANK?SWITCH
                PUSH    ACC
                PUSH    DPL
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




?BANK?SWITCH    SEGMENT  CODE  PAGE

                RSEG    ?BANK?SWITCH
CNT             SET     0

                REPT    ?B_NBANKS
                SWITCH  %CNT

CNT             SET     CNT+1
                ENDM


  IF ?B_RTX = 0 AND ?B_NBANKS > 32

    SWITCHBNK:  XCH     A,R0
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
                MOV     A,R0
                RET

  ELSEIF ?B_RTX = 1

    SWITCHBNK:  XCH     A,R0
    SWITCHBNK2: JBC     EA,SWITCHBNK_EA1
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
                MOV     A,R0
                RET

    SWITCHBNK_EA1:                     ; interrupts where enabled
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
                MOV     A,R0
                SETB    EA             ; enable interrupts again
                RET

    ?B_RESTORE_BANK:                   ; entry for RTX-51 bank restore
                ANL     A,#?B_MASK
                SJMP    SWITCHBNK2

  ENDIF


ENDIF  ; close block IF ?B_MODE = 0 *******************************************


IF ?B_MODE = 1 ;***************************************************************

?B_FACTOR       EQU     1 SHL ?B_FIRSTBIT

?B_MASK         EQU     MASK SHL ?B_FIRSTBIT

BANKN           MACRO   N
BANK&N           EQU     N SHL ?B_FIRSTBIT
                ENDM

CNT             SET     0

                REPT    ?B_NBANKS
                BANKN   %CNT
CNT             SET     CNT+1
                ENDM


?C_INITSEG      SEGMENT   CODE          ; Segment for Variable Initialization
                RSEG    ?C_INITSEG
                DB      01H             ; IData
                DB      ?B_CURRENTBANK  ; Init Current Bank
                DB      0               ; Set to Zero
                DB      41H             ; XData
                DW      ?B_XDATAPORT    ; Init XDATA Port
                DB      0               ; Set to Zero

                PUBLIC  ?B_XDATAPORT

?BANK?DATA      SEGMENT DATA
                RSEG    ?BANK?DATA
?B_CURRENTBANK: DS      1


IF ?B_NBANKS > 16
  ; Convert Bank No in Accu to Address * 4

  IF  ?B_FIRSTBIT = 0
  CONVBANKNO    MACRO
                RL      A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 1
  CONVBANKNO    MACRO
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 2
  CONVBANKNO    MACRO
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONVBANKNO    MACRO
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONVBANKNO    MACRO
                RR      A
                RR      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONVBANKNO    MACRO
                SWAP    A
                RL      A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONVBANKNO    MACRO
                SWAP    A
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONVBANKNO    MACRO
                SWAP    A
                RR      A
                ENDM
  ENDIF

  ; Macro code to select the 'N'
  SWITCH        MACRO   N
                ORG     N * 4
                PUBLIC  ?B_SWITCH&N
  ?B_SWITCH&N:
                MOV     R0,#BANK&N 
  IF ?B_NBANKS > 32
    IF (N < 32) 
                SJMP    SWITCHBNK_H
    ELSEIF (N = 32)
      SWITCHBNK_H:
                SJMP    SWITCHBNK
    ELSEIF (N <> ?B_NBANKS-1)
                SJMP    SWITCHBNK
    ENDIF
  ELSE
    IF N <> (?B_NBANKS-1)
                SJMP    SWITCHBNK
    ENDIF
  ENDIF
                ENDM
ENDIF


IF ?B_NBANKS <= 16
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

  SWITCH        MACRO   N
                ORG     N * 16
                PUBLIC  ?B_SWITCH&N
  ?B_SWITCH&N:
                MOV     R0,A
                MOV     A,#BANK&N
                MOV     DPTR,#?B_XDATAPORT
                MOV     ?B_CURRENTBANK,A
                MOVX    @DPTR,A
                MOV     A,R0
                RET
                ENDM
  
ENDIF


SELECT          MACRO   N
LOCAL           XLABEL, YLABEL

                PUBLIC  ?B_BANK&N
?B_BANK&N:      
                MOV     A,?B_CURRENTBANK
                ANL     A,#?B_MASK
                CONVBANKNO         ; Convert Bank Number to Address
                PUSH    ACC
                MOV     A,#HIGH ?BANK?SWITCH
                PUSH    ACC
                PUSH    DPL
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



?BANK?SWITCH    SEGMENT  CODE  PAGE

                RSEG    ?BANK?SWITCH
CNT             SET     0

                REPT    ?B_NBANKS
                SWITCH  %CNT

CNT             SET     CNT+1
                ENDM

  IF ?B_NBANKS > 16
    SWITCHBNK:  XCH     A,R0
                MOV     DPTR,#?B_XDATAPORT
                MOV     ?B_CURRENTBANK,A
                MOVX    @DPTR,A
                MOV     A,R0
                RET
  ENDIF

  IF (?B_RTX = 1 OR ?B_VAR_BANKING = 1)
    ?B_RESTORE_BANK:                   ; entry for RTX-51/XBANKING bank restore
                MOV     DPTR,#?B_XDATAPORT
                MOV     ?B_CURRENTBANK,A
                MOVX    @DPTR,A
                RET
  ENDIF

ENDIF  ; close block IF ?B_MODE = 1 *******************************************


IF  ?B_MODE = 4 ;**************************************************************

?B_FACTOR       EQU     0               ; Dummy Declarations
?B_FIRSTBIT     EQU     0
?B_MASK         EQU     MASK

?BANK?SELECT    SEGMENT CODE
?BANK?DATA      SEGMENT DATA
                RSEG    ?BANK?DATA
?B_CURRENTBANK: DS      1

BANK            MACRO   N
                PUBLIC  ?B_BANK&N
?B_BANK&N:
                PUSH    ?B_CURRENTBANK
                MOV     A,#HIGH ?BANK?SWITCH
                PUSH    ACC
                PUSH    DPL
                PUSH    DPH
                ENDM

SWITCH          MACRO   N
                PUBLIC  ?B_SWITCH&N
  IF (LONG_MACRO = 1)
    ?B_SWITCHJ&N:
  ELSE
    ?B_SWITCH&N:
  ENDIF
                MOV     ?B_CURRENTBANK,#LOW ?B_SWITCH&N
                SWITCH&N
                RET
                ENDM

  IF (LONG_MACRO = 1)
    SWITCHJ     MACRO   N
    ?B_SWITCH&N:
                JMP     ?B_SWITCHJ&N
                ENDM
  ENDIF

?BANK?SWITCH    SEGMENT CODE PAGE

                RSEG    ?BANK?SWITCH
B_SWITCH_START  EQU     $

  IF (LONG_MACRO = 1)
    ; Generate ?B_SWITCHn jmp table entries
    CNT         SET     0

                REPT    ?B_NBANKS
                SWITCHJ %CNT
    CNT         SET     CNT+1
                ENDM
  ENDIF


; Generate ?B_SWITCHn functions
CNT             SET     0

                REPT    ?B_NBANKS
                BANK    %CNT
                SWITCH  %CNT
CNT             SET     CNT+1
                ENDM

B_SWITCH_SIZE   EQU     $-B_SWITCH_START

  IF (LONG_MACRO = 0) AND (B_SWITCH_SIZE > 256)
    __ERROR__ "BANK SWITCH CODE BIGGER THAN 256 BYTES, SET LONG_MACRO TO 1"
  ENDIF

ENDIF  ; close block IF ?B_MODE = 4 *******************************************

                RSEG    ?BANK?SELECT

;************************  SWITCHBANK FUNCTION  *******************************
;                                                                             *
; SWITCHBANK allows use of bank-switching for C programs                      *
;                                                                             *
; prototype:   extern switchbank (unsigned char bank_number);                 *
;                                                                             *
;******************************************************************************
                PUBLIC  _SWITCHBANK, ?B_SWITCHBANK_A

_SWITCHBANK:    MOV     A,R7

IF  ?B_MODE = 0 ;**************************************************************

?B_SWITCHBANK_A:
IF ?B_NBANKS > 32 OR ?B_RTX = 1
                RL      A
                RL      A
ENDIF

IF ?B_NBANKS <= 16 AND ?B_RTX = 0
                SWAP    A
                RR      A
ENDIF
                MOV     DPTR,#?BANK?SWITCH
                JMP     @A+DPTR

ENDIF  ; close block IF ?B_MODE = 0 *******************************************

IF ?B_MODE = 1 ;***************************************************************

?B_SWITCHBANK_A:
IF ?B_NBANKS > 16
                RL      A
                RL      A
ENDIF

IF ?B_NBANKS <= 16
                SWAP    A
ENDIF
                MOV     DPTR,#?BANK?SWITCH
                JMP     @A+DPTR

ENDIF  ; close block IF ?B_MODE = 1 *******************************************

IF  ?B_MODE = 4 ;**************************************************************

IF (?B_VAR_BANKING = 1)
                SJMP    ?B_SWITCHBANK_A
SELECT_BANK_R3:
                MOV     A,R3
                DEC     A
                ANL     A,#3FH
ENDIF

?B_SWITCHBANK_A:
                MOV	DPTR,#switch_tab
                MOVC    A,@A+DPTR
?B_RESTORE_BANK:                       ; entry for RTX-51/XBANKING bank restore
                MOV     DPTR,#?BANK?SWITCH
                JMP     @A+DPTR

S_ENTRY         MACRO   N
                DB      LOW ?B_SWITCH&N
                ENDM

switch_tab:     
CNT             SET     0

                REPT    ?B_NBANKS
                S_ENTRY %CNT
CNT             SET     CNT+1
                ENDM
ENDIF  ; close block IF ?B_MODE = 4 *******************************************


IF ?B_VAR_BANKING  ;***********************************************************

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

PUBLIC ?C?CLDXPTR, ?C?CSTXPTR, ?C?ILDXPTR, ?C?ISTXPTR
PUBLIC ?C?PLDXPTR, ?C?PSTXPTR, ?C?LLDXPTR, ?C?LSTXPTR

?C?LIB_CODE     SEGMENT CODE
                RSEG    ?C?LIB_CODE


IF  ?B_MODE = 0 OR ?B_MODE = 1   ;*********************************************

; Define Helper Macros

  ; Shift Bank No in Accu to correct bit position

  IF  ?B_FIRSTBIT = 0
  CONV_MSPC     MACRO
                ANL	A,#LOW (MASK)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 1
  CONV_MSPC     MACRO
                RL      A
                ANL	A,#LOW (MASK SHL 1)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 2
  CONV_MSPC     MACRO
                RL      A
                RL      A
                ANL	A,#LOW (MASK SHL 2)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 3
  CONV_MSPC     MACRO
                SWAP    A
                RR      A
                ANL	A,#LOW (MASK SHL 3)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 4
  CONV_MSPC     MACRO
                SWAP    A
                ANL	A,#LOW (MASK SHL 4)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 5
  CONV_MSPC     MACRO
                SWAP    A
                RL      A
                ANL	A,#LOW (MASK SHL 5)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 6
  CONV_MSPC     MACRO
                RR      A
                RR      A
                ANL	A,#LOW (MASK SHL 6)
                ENDM
  ENDIF

  IF  ?B_FIRSTBIT = 7
  CONV_MSPC     MACRO
                RR      A
                ANL	A,#LOW (MASK SHL 7)
                ENDM
  ENDIF


ENDIF  ; close block IF  ?B_MODE = 0 OR ?B_MODE = 1   *************************


IF  ?B_MODE = 0 ;**************************************************************

; Select Bank depending on value in R3
SEL_BNK         MACRO   SaveA
IF NOT NUL SaveA
                PUSH    ACC
ENDIF
                CALL    SELECT_BANK_R3
IF NOT NUL SaveA
                POP     ACC 
ENDIF
                ENDM

; Pop previous Bank and select it again
POP_BNK         MACRO   SaveA
LOCAL BNK_EA1
IF NOT NUL SaveA
		MOV	DPL,A
ENDIF
                POP     ACC            ; bank information
                ANL     A,#?B_MASK
IF ?B_RTX = 1
                JBC     EA,BNK_EA1
ENDIF
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
IF NOT NUL SaveA
		MOV	A,DPL
ENDIF
                RET

    BNK_EA1:                           ; interrupts where enabled
IF ?B_RTX = 1
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
                SETB    EA             ; enable interrupts again
IF NOT NUL SaveA
		MOV	A,DPL
ENDIF
                RET
ENDIF
                ENDM


SELECT_BANK_R3:
		MOV	A,R3
		DEC     A
		CONV_MSPC               
                MOV     DPL,R1
                MOV     DPH,R2
                CJNE    R3,#80H,SEL_BANK_LAB  ; set CY
SEL_BANK_lab:            
IF ?B_RTX = 1
                JBC     EA,SEL_BANK_EA1
ENDIF
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
                RET

    SEL_BANK_EA1:                      ; interrupts where enabled
IF ?B_RTX = 1
                ORL     ?B_CURRENTBANK, #?B_MASK
                ANL     ?B_CURRENTBANK, A
                SETB    EA             ; enable interrupts again
                RET
ENDIF

ENDIF  ; close block IF ?B_MODE = 0 *******************************************

IF ?B_MODE = 1 ;***************************************************************

; Select Bank depending on value in R3
SEL_BNK         MACRO   SaveA
LOCAL lab
IF NOT NUL SaveA
                PUSH    ACC
ENDIF
                CALL    SELECT_BANK_R3
IF NOT NUL SaveA
                POP	ACC
ENDIF
                ENDM

; Pop previous Bank and select it again
POP_BNK         MACRO   SaveA
IF NOT NUL SaveA
                POP     DPL
		XCH	A,DPL
		PUSH	DPL
ELSE
                POP     ACC
ENDIF
                MOV     DPTR,#?B_XDATAPORT
                MOV     ?B_CURRENTBANK,A
                MOVX    @DPTR,A
IF NOT NUL SaveA
                POP     ACC
ENDIF
                RET
                ENDM


SELECT_BANK_R3:
		MOV	A,R3
		DEC     A
		CONV_MSPC               
                MOV     DPTR,#?B_XDATAPORT
                MOV     ?B_CURRENTBANK,A
                MOVX    @DPTR,A
                MOV     DPL,R1
                MOV     DPH,R2
                CJNE    R3,#80H,SEL_BANK_LAB  ; set CY
SEL_BANK_LAB:
                RET

ENDIF  ; close block IF ?B_MODE = 1 *******************************************

IF  ?B_MODE = 4 ;**************************************************************

; Select Bank depending on value in R3
SEL_BNK         MACRO   SaveA
LOCAL lab
IF NOT NUL SaveA
                PUSH	ACC
ENDIF
                CALL    SELECT_BANK_R3
IF NOT NUL SaveA
                POP	ACC
ENDIF
                MOV     DPL,R1
                MOV     DPH,R2
                CJNE    R3,#80H,lab
lab:            
                ENDM

; Pop previous Bank and select it again
POP_BNK         MACRO   SaveA
IF NOT NUL SaveA
                POP     DPL
		XCH	A,DPL
		PUSH	DPL
                CALL    ?B_RESTORE_BANK
                POP     ACC
                RET
ELSE
                POP     ACC
                MOV     DPTR,#?BANK?SWITCH
                JMP     @A+DPTR
ENDIF
                ENDM

ENDIF  ; close block IF ?B_MODE = 4 *******************************************



; CLDXPTR: Load   BYTE in A             via Address given in R1/R2/R3
?C?CLDXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK
                JNC     CLDCODE
                MOVX    A,@DPTR
                SJMP    RETURN_A
CLDCODE:        CLR     A
                MOVC    A,@A+DPTR
RETURN_A:       POP_BNK 1


; CSTXPTR: Store  BYTE in A             via Address given in R1/R2/R3
?C?CSTXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK 1          
                JNC     CSTCODE
                MOVX    @DPTR,A
CSTCODE:        SJMP	RETURN_A       ; correct 10.5.2002


; ILDXPTR: Load   WORD in A(LSB)/B(HSB) via Address given in R1/R2/R3 
?C?ILDXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK
                JNC     ILDCODE
                MOVX    A,@DPTR
                MOV     B,A
                INC     DPTR
                MOVX    A,@DPTR
                SJMP    RETURN_A
ILDCODE:        CLR     A
                MOVC    A,@A+DPTR
                MOV     B,A
                MOV     A,#1
                MOVC    A,@A+DPTR
                SJMP    RETURN_A


; ISTXPTR: Store  WORD in A(HSB)/B(LSB) via Address given in R1/R2/R3 
?C?ISTXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK 1
                JNC     ISTCODE
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,B
                MOVX    @DPTR,A
ISTCODE:        SJMP    RETURN_NO_A


; PLDXPTR: Load    PTR in R1/R2/R3      via Address given in R1/R2/R3 
?C?PLDXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK
                JNC     PLDCODE
                MOVX    A,@DPTR
                MOV     R3,A
                INC     DPTR
                MOVX    A,@DPTR
                MOV     R2,A
                INC     DPTR
                MOVX    A,@DPTR
                MOV     R1,A
                SJMP    RETURN_NO_A
PLDCODE:        CLR     A
                MOVC    A,@A+DPTR
                MOV     R3,A
                MOV     A,#1
                MOVC    A,@A+DPTR
                MOV     R2,A
                MOV     A,#2
                MOVC    A,@A+DPTR
                MOV     R1,A
RETURN_NO_A:    POP_BNK

; PSTXPTR: Store   PTR in R0/A/B        via Address given in R1/R2/R3 
?C?PSTXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK 1
                JNC     PSTCODE
                XCH     A,B
                MOVX    @DPTR,A
                INC     DPTR
                XCH     A,B
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,R0
                MOVX    @DPTR,A
PSTCODE:        SJMP    RETURN_NO_A 

; LLDXPTR: Load  DWORD in R4/R5/R6/R7   via Address given in R1/R2/R3 
?C?LLDXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK
                JNC     LLDCODE
                MOVX    A,@DPTR
                MOV     R4,A
                INC     DPTR
                MOVX    A,@DPTR
                MOV     R5,A
                INC     DPTR
                MOVX    A,@DPTR
                MOV     R6,A
                INC     DPTR
                MOVX    A,@DPTR
                MOV     R7,A
                SJMP    RETURN_NO_A
LLDCODE:        CLR     A
                MOVC    A,@A+DPTR
                MOV     R4,A
                MOV     A,#1
                MOVC    A,@A+DPTR
                MOV     R5,A
                MOV     A,#2
                MOVC    A,@A+DPTR
                MOV     R6,A
                MOV     A,#3
                MOVC    A,@A+DPTR
                MOV     R7,A
                SJMP    RETURN_NO_A

; LSTXPTR: Store DWORD in R4/R5/R6/R7   via Address given in R1/R2/R3 
?C?LSTXPTR:     PUSH    ?B_CURRENTBANK
                SEL_BNK
                JNC     LSTCODE
                MOV     A,R4
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,R5
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,R6
                MOVX    @DPTR,A
                INC     DPTR
                MOV     A,R7
                MOVX    @DPTR,A
LSTCODE:        SJMP    RETURN_NO_A

 
ENDIF  ; close block IF ?B_VAR_BANKING ****************************************

                END

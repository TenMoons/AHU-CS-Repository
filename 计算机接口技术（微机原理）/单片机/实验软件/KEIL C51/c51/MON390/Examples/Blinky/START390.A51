$NOMOD51
;------------------------------------------------------------------------------
;  This file is part of the C51 Compiler package
;  Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
;  Startup code for Dallas 390/400/5240 CPU, Contigious Mode
;
;  Version 1.01:  order of MCON/ACON setup changed
;
;------------------------------------------------------------------------------
;  START390.A51:  This code is executed after processor reset.
;  You may add this file to a uVision2 project.
;
;  To translate this file use A51 with the following invocation:
;
;     AX51 START390.A51 MOD_CONT
;
;  To link the modified STARTUP.OBJ file to your application use the following
;  LX51 invocation:
;
;     LX51 <your object file list>, START390.OBJ <controls>
;
;------------------------------------------------------------------------------
;
; Chip Specific Options (MCON needs to be set before ACON)
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
; PDCE3 .. PDCE0: Program/Data Chip Enable (MCON.3, MCON.2, MCON.1, MCON.0)
; refer to the Dallas Data Sheet for more information
PDCE3 EQU 0
PDCE2 EQU 0
PDCE1 EQU 0
PDCE0 EQU 1
;
; SA: Extend Stack Address Mode Enable (ACON.2)
SA   EQU 0  ; 0 = 8051 compatible stack in IDATA memory
;           ; 1 = Use 1KB stack in on-chip XDATA space
;
;------------------------------------------------------------------------------
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
PPAGE           EQU     0       ; define PPAGE number.
;
;------------------------------------------------------------------------------

#include <REG390.H>

                NAME    ?C_STARTUP


?C_C51STARTUP   SEGMENT   CODE

IF SA = 1
  IF IDM = 0
    
    ?STACK SEGMENT XDATA AT 0F000H
  ENDIF

  IF IDM = 1
    ?STACK SEGMENT XDATA AT 00000H
  ENDIF

  IF IDM = 2
    ?STACK SEGMENT HDATA AT 0400000H
  ENDIF

  IF IDM = 3
    __ERROR__ "Extended Stack not possible when on-chip XRAM is mapped as code & xdata"
  ENDIF

                RSEG    ?STACK
                DS      1024
ELSE

?STACK          SEGMENT   IDATA

                RSEG    ?STACK
                DS      1
ENDIF

                EXTRN CODE (?C_START)
                PUBLIC  ?C_STARTUP

?C_CPURESET?0   SEGMENT CODE OFFS 0
                RSEG    ?C_CPURESET?0   

?C_STARTUP      LABEL   NEAR
$IF MONITOR
		AJMP	STARTUP1
$ELSE
                DB      02H     ; LJMP in Classic 8051 Mode
                DW      WORD0 STARTUP1
$ENDIF
                RSEG    ?C_C51STARTUP

STARTUP1:       MOV     TA,#0xAA        ; Enable access to MCON
                MOV     TA,#0x55
MCON_VAL SET (IDM SHL 6) OR (CMA SHL 5) OR (PDCE3 SHL 3) OR (PDCE2 SHL 2)
MCON_VAL SET MCON_VAL OR (PDCE1 SHL 1) OR (PDCE0)
                MOV     MCON,#MCON_VAL

                MOV     TA,#0xAA        ; Enable access to ACON
                MOV     TA,#0x55
ACON_VAL EQU (2 OR (SA SHL 2)) ; 22-bit contigious mode, SA bit
                MOV     ACON,#ACON_VAL

IF IDATALEN <> 0
                MOV     R0,#IDATALEN - 1
                CLR     A
IDATALOOP:      MOV     @R0,A
                DJNZ    R0,IDATALOOP
ENDIF

IF XDATALEN <> 0
                MOV     DPTR,#XDATASTART
                MOV     R7,#BYTE0 (XDATALEN)
  IF (BYTE0 (XDATALEN)) <> 0
                MOV     R6,#(BYTE1 XDATALEN) +1
  ELSE
                MOV     R6,#BYTE1 (XDATALEN)
  ENDIF
  IF (BYTE1 (XDATALEN)) <> 0
                MOV     R5,#(BYTE2 XDATALEN) +1
  ELSE
                MOV     R5,#BYTE2 (XDATALEN)
  ENDIF
                CLR     A
XDATALOOP:      MOVX    @DPTR,A
                INC     DPTR
                DJNZ    R7,XDATALOOP
                DJNZ    R6,XDATALOOP
                DJNZ    R5,XDATALOOP
ENDIF

IF PPAGEENABLE <> 0
                MOV     P2,#PPAGE
                MOV     MXAX,#0
ENDIF

IF PDATALEN <> 0
                MOV     R0,#PDATASTART
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

IF SA = 1
                MOV     SP,#BYTE0 (?STACK-1)
                MOV     ESP,#BYTE1 (?STACK-1)
ELSE
                MOV     SP,#?STACK-1
ENDIF
                LJMP    ?C_START

                END

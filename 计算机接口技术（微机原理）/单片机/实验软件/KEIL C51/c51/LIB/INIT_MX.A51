;------------------------------------------------------------------------------
;  This file is part of the CX51 Compiler package
;  Copyright (c) 1988-2003 Keil Elektronik GmbH and Keil Software, Inc.
;------------------------------------------------------------------------------
;  INIT_MX.A51:  This code is executed, if the application program contains
;                initialized variables at file level.
;
;  If you are using uVision2, just add the file as last file to your project.
;  *** IMPORTANT NOTE ***:  this file needs to be the last file of the linker 
;  input list.  If you are using uVision2 this file should be therefore the 
;  last file in your project tree.
;
;
;  To translate this file use Ax51 with the following invocation:
;
;     AX51 INIT_MX.A51
;
;  To link the modified INIT_MX.OBJ file to your application use the following
;  linker invocation:
;
;     LX51 <your object file list>, INIT.OBJ <controls>
;
;------------------------------------------------------------------------------
;
;  User-defined Watch-Dog Refresh.
;
;  If the C application contains many initialized variables uses a watchdog
;  it might be possible that the user has to include a watchdog refresh into
;  the initialization process. The watchdog refresh routine can be included
;  in the following MACRO and can alter all CPU registers except
;  DPTR.
;
WATCHDOG        MACRO
                                ; Include any Watchdog refresh code here
                ENDM
;
;------------------------------------------------------------------------------
;
;  Far Memory Support
;
;  If the C application contains variables in the far memory space that are
;  initialized, you need to set the following define to 1.
;
; --- Set XBANK = 1 when far variables should be initialized
$SET (XBANK = 1)
;
;------------------------------------------------------------------------------

; Standard SFR Symbols
ACC     DATA    0E0H
DPL     DATA    82H
DPH     DATA    83H

		NAME	?C_INIT


?C_C51STARTUP	SEGMENT   CODE
?C_INITSEG	SEGMENT   CODE		; Segment zur Initialisierung


INIT_IorP       MACRO
IorPData:                               ; If CY=1 PData Values
                CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                MOV     R0,A            ; Start Address
IorPLoop:       CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                JC      PData
                MOV     @R0,A
                SJMP    Common
PData:          MOVX    @R0,A
Common:         INC     R0
                DJNZ    R7,IorPLoop
                JMP    Loop
                ENDM


                EXTRN CODE (MAIN)
                PUBLIC  ?C_START

                RSEG    ?C_C51STARTUP
INITEND:        EJMP    MAIN

$IF (XBANK = 0)
                INIT_IorP
$ENDIF

Bits:           CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                MOV     R0,A
                ANL     A,#007H
                ADD     A,#Table-LoadTab
                XCH     A,R0
                CLR     C       
                RLC     A               ; Bit Condition to Carry
                SWAP    A
                ANL     A,#00FH
                ORL     A,#20H          ; Bit Address
                XCH     A,R0            ; convert to Byte Addressen
                MOVC    A,@A+PC
LoadTab:        JC      Setzen
                CPL     A
                ANL     A,@R0
                SJMP    BitReady
Setzen:         ORL     A,@R0
BitReady:       MOV     @R0,A
                DJNZ    R7,Bits
                SJMP    Loop

Table:          DB      00000001B
                DB      00000010B
                DB      00000100B
                DB      00001000B
                DB      00010000B
                DB      00100000B
                DB      01000000B
                DB      10000000B
                

?C_START:       
                MOV     DPTR,#?C_INITSEG
Loop:
                WATCHDOG
                CLR     A
                MOV     R6,#1
                MOVC    A,@A+DPTR
                JZ      INITEND
                INC     DPTR
                MOV     R7,A
                ANL     A,#3FH
                JNB     ACC.5,NOBIG
                ANL     A,#01FH
                MOV     R6,A
                CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                JZ      NOBIG
                INC     R6
NOBIG:          XCH     A,R7

; ---- Init for far Variables
$IF (XBANK = 1)
                ANL     A,#0E0H
                CJNE    A,#0E0H,NOHDATA
;
HPTRINIT:       CLR     A
                MOVC    A,@A+DPTR
                MOV     R3,A
                INC     DPTR
                CLR     A
                MOVC    A,@A+DPTR
                MOV     R2,A
                INC     DPTR
                CLR     A
                MOVC    A,@A+DPTR
                MOV     R1,A
                INC     DPTR
HLOOP:          CLR     A
                MOVC    A,@A+DPTR
                EMOV	@PR0,A
                INC     DPTR
                INC     R1
                MOV     A,R1
                JNZ     HINC
                INC     R2
HINC:           DJNZ    R7,HLOOP
                DJNZ    R6,HLOOP
                SJMP    Loop
NOHDATA:
$ENDIF
                ANL     A,#0C0H         ; Typ is in Bit 6 and Bit 7
                ADD     A,ACC
                JZ      IorPData
                JC      Bits

XdataMem:       CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                MOV     R2,A            ; High
                CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                MOV     R0,A            ; LOW
XLoop:          CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                XCH     A,R0
                XCH     A,DPL
                XCH     A,R0
                XCH     A,R2
                XCH     A,DPH
                XCH     A,R2
                MOVX    @DPTR,A
                INC     DPTR
                XCH     A,R0
                XCH     A,DPL
                XCH     A,R0
                XCH     A,R2
                XCH     A,DPH
                XCH     A,R2
                DJNZ    R7,XLoop
                DJNZ    R6,XLoop
                SJMP    Loop

$IF (XBANK = 1)
                INIT_IorP
$ENDIF

                RSEG    ?C_INITSEG
                DB      0

;-------------------------------------------------------------------------
; STRUCTURE OF THE INITIALIZATION INFORMATION
; -------------------------------------------
; This section describes the initialization data generated by C51 for
; explicit variable initializations (in segment ?C_INITSEC).
;
; Explicit variable initilizations at C source level are stored by C51 in
; the segment ?C_INITSEC.  All partial segments are combined at linker level
; to one segment.  The segment end value DB 0 is taken from this library module
; INIT.A51.
;
; Structure of the ?C_INITSEC information:
;     <Info> (see below) [BYTE]                      ----+  repeated
;     <additional info>  [BYTES depend on Info]      ----+  repeated
;     0x00               [BYTE]   <end of list mark>
;
;  <Info> has the following format:
;
;  Bit      7  6  5  4  3  2  1  0
;  <Info>   T  T  B  L  L  L  L  L    T=Type  B=BIGBIT  L=LENGTH
;
;  If BIGBIT is set, another LENGTH BYTE FOLLOWS.  The LENGHT
;  info of the first byte is then the HIGH part.
;
;  Typ is one of the following:
;  0  := IDATA init values;  the following bytes follow:
;        -  1 byte address
;        -  init data bytes according LENGTH specification
;
;  1  := XDATA init values;  the following bytes follow:
;        -  2 byte address (high byte first)
;        -  init data bytes according LENGTH specification
;
;  2  := PDATA init values;  the following bytes follow:
;        -  1 byte address
;        -  init data bytes according LENGTH specification
;
;  3, BIGBIT=0  := BIT init values; the followign bytes follow:
;        -  1 byte for each bit according LENGTH specification
;           this byte has the following format:
;
;           Bit    7  6  5  4  3  2  1  0
;                  I  B  B  B  B  B  B  B   I := state of the bit
;                                           B := bit address
;
;  3, BIGBIT=1  := HDATA init values;   the following bytes follow:
;        -  another LENGTH byte (since BIGBIT is always 1)
;        -  3 byte address  (MSB first)
;        -  data bytes according LENGTH specification
;
;----------------------------------------------------------------------

		END


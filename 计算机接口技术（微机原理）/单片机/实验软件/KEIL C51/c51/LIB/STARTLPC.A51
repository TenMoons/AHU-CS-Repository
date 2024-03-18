;------------------------------------------------------------------------------
;  This file is part of the C51 Compiler package
;  Startup Code for the Philips LPC series
;  Copyright (c) 1988-2001 Keil Elektronik GmbH and Keil Software, Inc.
;------------------------------------------------------------------------------
;  STARTLPC.A51:  This code is executed after processor reset.
;  You may add this file to a uVision2 project.
;
;  To translate this file use Ax51 with the following invocation:
;
;     Ax51 STARTLPC.A51
;
;  To link the modified STARTLPC.OBJ file to your application use the following
;  Lx51 invocation:
;
;     Lx51 <your object file list>, STARTLPC.OBJ <controls>
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
IBPSTACKTOP     EQU     07FH+1  ; set top of stack to highest location+1.
;
;------------------------------------------------------------------------------
;
;  Setup LPC Configuration Register (UCFG1, UCFG2)
;
; Oscillator Configuration (UCFG1.0 .. UCFG1.2)
; FOSC       Val  Description
; ----       ---  -----------
FOSC EQU 7  ; 0 = high frequency crystal or resonator (4MHz .. 20MHz)
;           ; 1 = medium frequency crystal or resonator (100kHz .. 4MHz)
;           ; 2 = low frequency crystal (20kHz .. 100kHz)
;           ; 3 = internal RC oscillator (6MHz +/- 25%)
;           ; 7 = (default on unprogrammed part) external clock input on X1
;
; Clock Rate Select (UCFG1.3)
; CLKR       Val  Description
; ----       ---  -----------
CLKR EQU 1  ; 0 = CPU clock devided by 2 (results in 12 CPU clocks like on 8051)
;           ; 1 = (default on unprogrammed part) fast CPU clock (6 CPU clocks)
;
; Brownout Voltage Select (UCFG1.4)
; BOV        Val  Description
; ----       ---  -----------
BOV  EQU 1  ; 0 = Brownout detect voltage = 3.8V 
;           ; 1 = Brownout detect voltage = 2.5V 
;
; Port reset state (UCFG1.5)
; PRHI       Val  Description
; ----       ---  -----------
PRHI EQU 1  ; 0 = Ports reset to a low state
;           ; 1 = (default on unprogrammed part) Ports reset to a high state
;
; Reset PIN disable (UCFG1.6)
; RPD        Val  Description
; ---        ---  -----------
RPD  EQU 1  ; 0 = P1.5 will act as reset pin (low active)
;           ; 1 = (default on unprogrammed part) P1.5 can be used as input PIN
;           
; Watchdog timer enable (UCFG1.7)
; WDTE       Val  Description
; ----       ---  -----------
WDTE EQU 1  ; 0 = watchdog disabled (watch can still be a timer to generate interrupts)
;           ; 1 = (default on unprogrammed part) watchdog enabled
;
;
; EPROM Security (UCFG2.6 .. UCFG2.7)
; SB         Val  Description
; --         ---  -----------
SB   EQU 3  ; 0 = EPROM verification and programming disabled
;           ; 2 = further EPROM programming is disabled
;           ; 3 = no security features enabled; EPROM is programmable and verifiable.
;
;------------------------------------------------------------------------------

                NAME    ?C_STARTUP

_UCFG1 EQU FOSC OR (CLKR SHL 3) OR (BOV SHL 4) OR (PRHI SHL 5) OR (RPD SHL 6) OR (WDTE SHL 7)
_UCFG2 EQU (SB SHL 6) OR 0x3F

                CSEG    AT      0FD00H
                DB      _UCFG1          ; place UCFG Bytes in ROM
                DB      _UCFG2


?C_C51STARTUP   SEGMENT   CODE
?STACK          SEGMENT   IDATA

                RSEG    ?STACK
                DS      1

                EXTRN CODE (?C_START)
                PUBLIC  ?C_STARTUP

                CSEG    AT      0
?C_STARTUP:     JMP     STARTUP1

                RSEG    ?C_C51STARTUP

STARTUP1:

IF IDATALEN <> 0
                MOV     R0,#IDATALEN - 1
                CLR     A
IDATALOOP:      MOV     @R0,A
                DJNZ    R0,IDATALOOP
ENDIF


IF IBPSTACK <> 0
EXTRN DATA (?C_IBP)

                MOV     ?C_IBP,#LOW IBPSTACKTOP
ENDIF

                MOV     SP,#?STACK-1
                JMP     ?C_START

                END

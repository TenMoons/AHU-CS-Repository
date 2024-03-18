;------------------------------------------------------------------------------
;  This file is part of the C51 Compiler package
;  Startup Code for the Philips LPC9xx devices 
;  Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
;  Version 2.0
;------------------------------------------------------------------------------
;  START900.A51:  This code is executed after processor reset.
;  You may add this file to a uVision2 project.
;
;  To translate this file use Ax51 with the following invocation:
;
;     Ax51 START900.A51
;
;  To link the modified START900.OBJ file to your application use the following
;  Lx51 invocation:
;
;     Lx51 <your object file list>, START900.OBJ <controls>
;
;------------------------------------------------------------------------------
;
;  User-defined Power-On Initialization of Memory
;
;  With the following EQU statements the initialization of memory
;  at processor reset can be defined:
;
;               ; the absolute start-address of IDATA memory is always 0
IDATALEN        EQU     100H    ; the length of IDATA memory in bytes.
;
XDATASTART      EQU     0H      ; the absolute start-address of XDATA memory
XDATALEN        EQU     0H      ; the length of XDATA memory in bytes.
;
;  Note:  The IDATA space overlaps physically the DATA and BIT areas of the
;         LPC9xx device.
;
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
XBPSTACKTOP     EQU     01FFH+1 ; set top of stack to highest location+1.
;
;  Stack Space for reentrant functions in the COMPACT model.    
PBPSTACK        EQU     0       ; set to 1 if compact reentrant is used.
PBPSTACKTOP     EQU     0FFH+1  ; set top of stack to highest location+1.
;
;------------------------------------------------------------------------------
;
;  Setup LPC9xx Configuration Register (UCFG1, BOOTVEC, BOOTSTAT, SEC0..SEC7)
;
; Oscillator Configuration (UCFG1.0 .. UCFG1.2)
; FOSC       Val  Description
; ----       ---  -----------
FOSC EQU 3  ; 0 = high frequency crystal or resonator (4MHz .. 20MHz)
;           ; 1 = medium frequency crystal or resonator (100kHz .. 4MHz)
;           ; 2 = low frequency crystal (20kHz .. 100kHz)
;           ; 3 = internal RC oscillator (7.373MHz +/- 2.5%) (default on unprogrammed part)
;           ; 4 = internal Watchdog oscillator (400kHz +20/-30%)
;           ; 7 = external clock input on X1
;
; Watchdog Saftey Enable (UCFG1.4)
; WDSE       Val  Description
; ----       ---  -----------
WDSE EQU 0  ; 0 = user can set WDCLK to select clock source(default on unprogrammed part) 
;           ; 1 = Always use WDCLK, WDCON and WDL can be written once, WDT is always running 
;
; Brownout Detect Enable (UCFG1.5)
; BOE       Val  Description
; ----       ---  -----------
BOE EQU 1   ; 0 = 
;           ; 1 = (default on unprogrammed part) 
;
; Reset PIN enable (UCFG1.6)
; RPE        Val  Description
; ---        ---  -----------
RPE  EQU 1  ; 0 = P1.5 can be used as input PIN (default on unprogrammed part)
;           ; 1 = P1.5 will act as low active reset pin (low active)
;           
; Watchdog timer enable (UCFG1.7)
; WDTE       Val  Description
; ----       ---  -----------
WDTE EQU 0  ; 0 = watchdog disabled WDSE has no effect (default on unprogrammed part)
;           ; 1 = watchdog enabled
;
; BOOTVECTOR (BOOTVEC)
; BOOTVEC    Val  Description
; ----       ---  -----------
BOOTVEC EQU 0x1E  ; points to ISP entry point (default on unprogrammed part)
;
; BOOTSTATUS (BOOTSTAT)
; BOOTSTAT   Val  Description
; ----       ---  -----------
BOOTSTAT EQU 0x01 ; enables ISP entry on power-up (default on unprogrammed part)
;
; Flash Security Configuration (SEC0.0 .. SEC0.2)
; SEC0       Val  Description
; ----       ---  -----------
SEC0 EQU 0  ; 0 = no security on sector 0 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 0
;           ; 2 = program/erase disabled on sector 0
;           ; 3 = MOVC disabled, program/erase disabled on sector 0 
;           ; 4 = IAP/ISP global erase disabled on sector 0
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 0
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 0
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 0
;
; Flash Security Configuration (SEC1.0 .. SEC1.2)
; SEC1       Val  Description
; ----       ---  -----------
SEC1 EQU 0  ; 0 = no security on sector 1 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 1
;           ; 2 = program/erase disabled on sector 1
;           ; 3 = MOVC disabled, program/erase disabled on sector 1 
;           ; 4 = IAP/ISP global erase disabled on sector 1
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 1
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 1
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 1
;
; Flash Security Configuration (SEC2.0 .. SEC2.2)
; SEC2       Val  Description
; ----       ---  -----------
SEC2 EQU 0  ; 0 = no security on sector 2 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 2
;           ; 2 = program/erase disabled on sector 2
;           ; 3 = MOVC disabled, program/erase disabled on sector 2 
;           ; 4 = IAP/ISP global erase disabled on sector 2
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 2
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 2
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 2
;
; Flash Security Configuration (SEC3.0 .. SEC3.2)
; SEC3       Val  Description
; ----       ---  -----------
SEC3 EQU 0  ; 0 = no security on sector 3 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 3
;           ; 2 = program/erase disabled on sector 3
;           ; 3 = MOVC disabled, program/erase disabled on sector 3 
;           ; 4 = IAP/ISP global erase disabled on sector 3
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 3
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 3
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 3
;
; Flash Security Configuration (SEC4.0 .. SEC4.2)
; SEC4       Val  Description
; ----       ---  -----------
SEC4 EQU 0  ; 0 = no security on sector 4 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 4
;           ; 2 = program/erase disabled on sector 4
;           ; 3 = MOVC disabled, program/erase disabled on sector 4 
;           ; 4 = IAP/ISP global erase disabled on sector 4
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 4
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 4
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 4
;
; Flash Security Configuration (SEC5.0 .. SEC5.2)
; SEC5       Val  Description
; ----       ---  -----------
SEC5 EQU 0  ; 0 = no security on sector 5 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 5
;           ; 2 = program/erase disabled on sector 5
;           ; 3 = MOVC disabled, program/erase disabled on sector 5 
;           ; 4 = IAP/ISP global erase disabled on sector 5
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 5
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 5
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 5
;
; Flash Security Configuration (SEC6.0 .. SEC6.2)
; SEC6       Val  Description
; ----       ---  -----------
SEC6 EQU 0  ; 0 = no security on sector 6 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 6
;           ; 2 = program/erase disabled on sector 6
;           ; 3 = MOVC disabled, program/erase disabled on sector 6 
;           ; 4 = IAP/ISP global erase disabled on sector 6
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 6
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 6
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 6
;
; Flash Security Configuration (SEC7.0 .. SEC7.2)
; SEC7       Val  Description
; ----       ---  -----------
SEC7 EQU 0  ; 0 = no security on sector 7 (default on unprogrammed part)
;           ; 1 = MOVC disabled on sector 7
;           ; 2 = program/erase disabled on sector 7
;           ; 3 = MOVC disabled, program/erase disabled on sector 7 
;           ; 4 = IAP/ISP global erase disabled on sector 7
;           ; 5 = MOVC disabled, IAP/ISP global erase disabled on sector 7
;           ; 6 = program/erase disabled, IAP/ISP global erase disabled on sector 7
;           ; 7 = MOVC disabled, program/erase disabled, IAP/ISP global erase disabled on sector 7
;
;------------------------------------------------------------------------------


                NAME    ?C_STARTUP

_UCFG1 EQU FOSC OR (WDSE SHL 4) OR (BOE SHL 5) OR (RPE SHL 6) OR (WDTE SHL 7)
_UCFG2 EQU 0

                CSEG    AT      0FFF0H
                DB      _UCFG1          ; place UCFG Bytes in hex file
                DB      _UCFG2          ; reserved for future use
                DB      BOOTVEC
                DB      BOOTSTAT
                DB      SEC0
                DB      SEC1
                DB      SEC2
                DB      SEC3
                DB      SEC4
                DB      SEC5
                DB      SEC6
                DB      SEC7

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
                JMP     ?C_START

                END

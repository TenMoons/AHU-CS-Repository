;------------------------------------------------------------------------------
;  This file defines the Monitor Configuration Parameters
;  Copyright KEIL ELEKTRONIK GmbH 1993 - 2003
;  Flash Monitor-51 Version 4.00
;------------------------------------------------------------------------------
;
; Definitions of Monitor Parameters
; ---------------------------------
;
; XDATA_START: Defines the start address for the Monitor XDATA area
;              Monitor-51 uses 256 Bytes RAM starting at this location.
XDATA_START   EQU  00280H    ; default Monitor data area 0x0300 .. 0x03FF

; CODE_START: Defines the Start Address for the Monitor Code Area
;             Monitor requires 4KB for program code starting at this location.
CODE_START    EQU  0E000H    ; default Monitor code area 0x7000 .. 0x7FFF

; INT_ADR_OFF: Defines the Interrupt Vector Address relocation 
; Notes: This setting is ONLY relevant, if CODE_START is 0.  You must locate the 
;        interrupts of your target application to the same address with uVision2
;        'Options for Target'->'C51'->'Interrupt vectors at address'.
;        (generates the L166 VECTAB directive).
INT_ADR_OFF   EQU  00000H    ; default interrupt vector relocation is 0x0000

; DEF_PC_VAL: Program counter value after start
; Notes: When CODE_START is set to 0 you should set DEF_PC_VAL to the beginning
;        of the application code area.  This is typically the start of the v.Neumann
;        wired RAM area.
DEF_PC_VAL    EQU  00000H    ; reset value of program counter after monitor start

; SERIAL: Defines the UART and the baudrategenerator
SERIAL        EQU  1         ; 0 = on-chip UART with timer1 as baudrate generator
                             ; 1 = on-chip UART with timer2 as baudrate generator
                             ; 2 = use external 16550/16450 UART (see EX_UART_CLK and EX_UART_ADR)

; BAUDRATE: Defines the communication baudrate.
; Note: You may set BAUDRATE to 0 to enable automatic baudrate detection.
;       Automatic baudrate detection does not work for an external UART (SERIAL=2).
BAUDRATE      EQU  0         ; default Baudrate is 9600 bps.

; EX_UART_CLK: Oscillator/crystal frequency of external UART
; Note: This setting is only relevant when an external UART is selected (SERIAL=2)
EX_UART_CLK   EQU  1843200   ; clock for external UART

; EX_UART_ADR: XDATA memory address of external UART
; Note: This setting is only relevant when an external UART is selected (SERIAL=2)
EX_UART_ADR   EQU  0E700H    ; XDATA address of external UART

; CPU_CLOCK: Defines the CPU Clock frequency (external oscillator/crystal)
CPU_CLOCK     EQU  24000000  ; default clock for most chips is 24MHz

; CPU_X2:  Specifies if CPU runs in X2 mode.
; Note: This does not set the CPU into X2 mode. CPU_X2 must be set according to the 
;       X2 bit of the hardware security byte (HSB).
CPU_X2        EQU  0         ; 0 = 12 cycle CPU
                             ; 1 =  6 cycle CPU


; Definitions for AUXR Register:
; ------------------------------

; AO: ALE Output Bit (AUXR.0):
_AO           EQU  1         ; 0 = ALE is emitted at a constant rate of 1/6 of the 
                             ;     oscillator frequency (or 1/3 if X2 mode is used)
                             ; 1 = ALE is active only during a MOVX or MOVC instruction

; EXTRAM: EXTRAM Bit (AUXR.1):
; Note: The on-chip XDATA RAM must be enabled in the hardware security byte (HSB).
_EXTRAM       EQU  0         ; 0 = access internal XRAM using movx @Ri / @DPTR 
                             ; 1 = access external memory

; XRS: on-chip XRAM size (AUXR.2 .. AUXR.3):
_XRS          EQU  3         ; 0 =  256 bytes
                             ; 1 =  512 bytes
                             ; 2 =  768 bytes
                             ; 3 = 1024 bytes

; M0: Pulse Length (AUXR.5):
_M0           EQU  0         ; 0 = RD and the WR pulse length is 6 clock periods (default).
                             ; 1 = RD and the WR pulse length is 30 clock periods
;------------------------------------------------------------------------------
_AUXR   EQU (_AO) OR (_EXTRAM SHL 1) OR (_XRS SHL 2) OR (_M0 SHL 5)


; Definitions for FLASH programming:
; ----------------------------------

; FLASH_PAGESIZE: Defines the flash page size. uVision does not send data blocks that 
;                 cross this boundary. Must be set to 0 if flash programming is not used
FLASH_PAGESIZE EQU 128       ; flash page size

; FLASH_MAXBYTES: Defines the max. number of bytes which can be loaded into one 
;                 flash page before the page is programmed.  This is a workaround for
;                 a chip problem in some Atmel devices. 
FLASH_MAXBYTES EQU 16        ; max number of bytes to load in one flash page








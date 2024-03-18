;
; Copyright 2002 Texas Instruments
;
; Define HCR0 and HCR1 while download Flash Programming
; -----------------------------------------------------
;
; EPMA: Enable Programming Memory Access (Security Bit) (HCR0.7):
_EPMA    EQU    1       ; 0 = After reset in programming modes, Flash Memory can not be read or written
;                       ; 1 = Fully Accessible (default)
;
; PML:  Program Memory Lock. (PML has Priority Over RSL)(HCR0.6):
_PML     EQU    0       ; 0 = Enable all Flash Programming Modes in program mode, can be written in UAM
;                       ; 1 = Enable read only for program mode, can’t be written in UAM (default)
;
; RSL:  Reset Sector Lock. (HCR0.5):
_RSL     EQU    0       ; 0 = Enable Reset Sector Writing
;                       ; 1 = Enable Read Only Mode for Reset Sector (4kB) (default)
;
; EBR:  Enable Boot Rom. (HCR0.4):
; Note: Boot Rom is 2kB of code located in ROM, not to be confused with the 4kB Boot Sector located in Flash Memory.
_EBR     EQU    1       ; 0 = Disable Internal Boot Rom
;                       ; 1 = Enable Internal Boot Rom (default)
;
; EWDR: Enable Watchdog Reset. (HCR0.3):
_EWDR    EQU    0       ; 0 = Disable Watchdog Reset
;                       ; 1 = Enable Watchdog Reset (default)
;
; DFSEL: Data Flash Memory Size. (HCR0.0 .. HCR0.2):
_DFSEL   EQU    7       ; 0 = Reserved
;                       ; 1 = 32kB, 16kB, 8kB, or 4kB Data Flash Memory
;                       ; 2 = 16kB, 8kB, or 4kB Data Flash Memory
;                       ; 3 = 8kB, or 4kB Data Flash Memory
;                       ; 4 = 4kB Data Flash Memory
;                       ; 5 = 2kB Data Flash Memory
;                       ; 6 = 1kB Data Flash Memory
;                       ; 7 = No Data Flash Memory (default)
;
; DBLSEL: Digital Brownout Level Select. (HCR1.6 .. HCR1.7):
_DBLSEL  EQU    3       ; 0 = 4.5V
;                       ; 1 = 4.2V
;                       ; 2 = 2.7V
;                       ; 3 = 2.5V (default)
;
; ABLSEL: Analog Brownout Level Select. (HCR1.4 .. HCR1.5):
_ABLSEL  EQU    3       ; 0 = 4.5V
;                       ; 1 = 4.2V
;                       ; 2 = 2.7V
;                       ; 3 = 2.5V (default)
;
; DAB: Disable Analog Power-Supply Brownout Detection. (HCR1.3):
_DAB     EQU    1       ; 0 = Enable Analog Brownout Detection
;                       ; 1 = Disable Analog Brownout Detection (default)
;
; DDB: Disable Digital Power-Supply Brownout Detection. (HCR1.2):
_DDB     EQU    1       ; 0 = Enable Digital Brownout Detection
;                       ; 1 = Disable Digital Brownout Detection (default)
;
; EGP0: Enable General-Purpose I/O for Port 0. (HCR1.1):
_EGP0    EQU    0       ; 0 = Port 0 is Used for External Memory
;                       ; 1 = Port 0 is Used as General-Purpose I/O (default)
;
; EGP23: Enable General-Purpose I/O for Ports 2 and 3. (HCR1.0):
_EGP23   EQU    0       ; 0 = Port 2 is Used for External Memory, P3.6 and P3.7 Used for WR and RD
;                       ; 1 = Port 2 and Port3 are Used as General-Purpose I/O (default)
;

HCR1     EQU     (_EPMA SHL 7) OR (_PML SHL 6) OR (_RSL SHL 5) OR (_EBR SHL 4) OR (_EWDR SHL 3) OR _DFSEL

HCR0     EQU     (_DBLSEL SHL 6) OR (_ABLSEL SHL 4) OR (_DAB SHL 3) OR (_DDB SHL 2) OR (_EGP0 SHL 1) OR _EGP23

         CSEG AT 0807EH
         DB      HCR0
         DB      HCR1
         END


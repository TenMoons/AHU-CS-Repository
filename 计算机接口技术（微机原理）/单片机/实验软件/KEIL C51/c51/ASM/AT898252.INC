;-------------------------------------------------------------------
; AT898252.INC
;
; Copyright 1997 KEIL ELEKTRONIK GmbH.  1997, All rights reserved.
; Atmel AT89S8252 Processor Declarations
;-------------------------------------------------------------------
$SAVE
$NOLIST
;
; Byte Registers
;
P0      DATA 80H
SP      DATA 81H
DPL     DATA 82H
DPH     DATA 83H
DP1L    DATA 84H
DP1H    DATA 85H 
SPDR    DATA 86H 
PCON    DATA 87H
TCON    DATA 88H
TMOD    DATA 89H
TL0     DATA 8AH
TL1     DATA 8BH
TH0     DATA 8CH
TH1     DATA 8DH
P1      DATA 90H
WMCON   DATA 96H
SCON    DATA 98H
SBUF    DATA 99H
;
P2      DATA 0A0H
IE      DATA 0A8H
SPSR    DATA 0AAH 
P3      DATA 0B0H
IP      DATA 0B8H
;
T2CON   DATA 0C8H
T2MOD   DATA 0C9H
RCAP2L  DATA 0CAH
RCAP2H  DATA 0CBH
TL2     DATA 0CCH
TH2     DATA 0CDH
;
PSW     DATA 0D0H
SPCR    DATA 0D5H
ACC     DATA 0E0H
B       DATA 0F0H
;
;
; Bit registers
;
; P0 Registers
P0_0 BIT 80H
P0_1 BIT 81H
P0_2 BIT 82H
P0_3 BIT 83H
P0_4 BIT 84H
P0_5 BIT 85H
P0_6 BIT 86H
P0_7 BIT 87H
;
; TCON Registers
IT0  BIT 88H
IE0  BIT 89H
IT1  BIT 8AH
IE1  BIT 8BH
TR0  BIT 8CH
TF0  BIT 8DH
TR1  BIT 8EH
TF1  BIT 8FH
;
; P1 Registers
P1_0 BIT 90H
P1_1 BIT 91H
P1_2 BIT 92H
P1_3 BIT 93H
P1_4 BIT 94H
P1_5 BIT 95H
P1_6 BIT 96H
P1_7 BIT 97H
;
T2   BIT 90H
T2EX BIT 91H
;
; SCON Registers
RI   BIT 98H
TI   BIT 99H
RB8  BIT 9AH
TB8  BIT 9BH
REN  BIT 9CH
SM2  BIT 9DH
SM1  BIT 9EH
SM0  BIT 9FH
;
; P2 Registers
P2_0 BIT 0A0H
P2_1 BIT 0A1H
P2_2 BIT 0A2H
P2_3 BIT 0A3H
P2_4 BIT 0A4H
P2_5 BIT 0A5H
P2_6 BIT 0A6H
P2_7 BIT 0A7H
;
; IE Registers
EX0  BIT 0A8H       ; 1=Enable External interrupt 0 
ET0  BIT 0A9H       ; 1=Enable Timer 0 interrupt 
EX1  BIT 0AAH       ; 1=Enable External interrupt 1 
ET1  BIT 0ABH       ; 1=Enable Timer 1 interrupt 
ES   BIT 0ACH       ; 1=Enable Serial port interrupt 
ET2  BIT 0ADH       ; 1=Enable Timer 2 interrupt 
EA   BIT 0AFH       ; 0=Disable all interrupts 
;
; P3 Registers (Mnemonics & Ports)
P3_0 BIT 0B0H
P3_1 BIT 0B1H
P3_2 BIT 0B2H
P3_3 BIT 0B3H
P3_4 BIT 0B4H
P3_5 BIT 0B5H
P3_6 BIT 0B6H
P3_7 BIT 0B7H
;
RXD  BIT 0B0H       ; Serial input 
TXD  BIT 0B1H       ; Serial output 
INT0 BIT 0B2H       ; External interrupt 0 
INT1 BIT 0B3H       ; External interrupt 1 
T0   BIT 0B4H       ; Timer 0 external input 
T1   BIT 0B5H       ; Timer 1 external input 
WR   BIT 0B6H       ; External memory write strobe 
RD   BIT 0B7H       ; External memory read strobe 
;
; IP Registers
PX0  BIT 0B8H
PT0  BIT 0B9H
PX1  BIT 0BAH
PT1  BIT 0BBH
PS   BIT 0BCH
PT2  BIT 0BDH
;
; T2CON Registers
CP_RL2 BIT 0C8H      ; 0=Reload, 1=Capture select 
C_T2   BIT 0C9H      ; 0=Timer, 1=Counter 
TR2    BIT 0CAH      ; 0=Stop timer, 1=Start timer 
EXEN2  BIT 0CBH      ; Timer 2 external enable 
TCLK   BIT 0CCH      ; 0=Serial clock uses Timer 1 overflow, 1=Timer 2 
RCLK   BIT 0CDH      ; 0=Serial clock uses Timer 1 overflow, 1=Timer 2 
EXF2   BIT 0CEH      ; Timer 2 external flag 
TF2    BIT 0CFH      ; Timer 2 overflow flag 
;
; PSW Registers
P    BIT 0D0H
FL   BIT 0D1H
OV   BIT 0D2H
RS0  BIT 0D3H
RS1  BIT 0D4H
F0   BIT 0D5H
AC   BIT 0D6H
CY   BIT 0D7H
;
$RESTORE
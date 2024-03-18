$SAVE
$NOLIST
;/* (c) Copyright KEIL ELEKTRONIK GmbH.  1997, All rights reserved. */
;/* 80524/528 Processor Declarations */
;
; BYTE Registers
P0      DATA    80H
P1      DATA    90H
P2      DATA    0A0H
P3      DATA    0B0H
PSW     DATA    0D0H
ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    81H
DPL     DATA    82H
DPH     DATA    83H
PCON    DATA    87H
TCON    DATA    88H
TMOD    DATA    89H
TL0     DATA    8AH
TL1     DATA    8BH
TH0     DATA    8CH
TH1     DATA    8DH
IE      DATA    0A8H
IP      DATA    0B8H
SCON    DATA    98H
SBUF    DATA    99H
T2CON   DATA    0C8H
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
TL2     DATA    0CCH
TH2     DATA    0CDH

S1BIT   DATA    0D9H
S1INT   DATA    0DAH
S1SCS   DATA    0D8H

T3      DATA    0FFH

; BIT Registers
; PSW
CY      BIT     0D7H
AC      BIT     0D6H
F0      BIT     0D5H
RS1     BIT     0D4H
RS0     BIT     0D3H
OV      BIT     0D2H
F1      BIT     0D1H
P       BIT     0D0H
; TCON
TF1     BIT     8FH
TR1     BIT     8EH
TF0     BIT     8DH
TR0     BIT     8CH
IE1     BIT     8BH
IT1     BIT     8AH
IE0     BIT     89H
IT0     BIT     88H
; IE 
EA      BIT     0AFH
ES1     BIT     0AEH
ET2     BIT     0ADH
ES0     BIT     0ACH
ET1     BIT     0ABH
EX1     BIT     0AAH
ET0     BIT     0A9H
EX0     BIT     0A8H
; IP 
PS1     BIT     0BEH
PT2     BIT     0BDH
PS0     BIT     0BCH
PT1     BIT     0BBH
PX1     BIT     0BAH
PT0     BIT     0B9H
PX0     BIT     0B8H
; P1
SDA     BIT     97H
SEL     BIT     96H
T2EX    BIT     91H
T2      BIT     90H
; P3
RD      BIT     0B7H
WR      BIT     0B6H
T1      BIT     0B5H
T0      BIT     0B4H
INT1    BIT     0B3H
INT0    BIT     0B2H
TXD     BIT     0B1H
RXD     BIT     0B0H
; SCON
SM0     BIT     9FH
SM1     BIT     9EH
SM2     BIT     9DH
REN     BIT     9CH
TB8     BIT     9BH
RB8     BIT     9AH
TI      BIT     99H
RI      BIT     98H
; T2CON
TF2     BIT     0CFH
EXF2    BIT     0CEH
RCLK    BIT     0CDH
TCLK    BIT     0CCH
EXEN2   BIT     0CBH
TR2     BIT     0CAH
C_T2    BIT     0C9H
CP_RL2  BIT     0C8H
; S1SCS 
SD0     BIT     0DFH  ; write
SDI     BIT     0DFH  ; read
SC0     BIT     0DEH  ; write
SCI     BIT     0DEH  ; read
CLH     BIT     0DDH  ; read/writE
BB      BIT     0DCH  ; read only
RBF     BIT     0DBH  ; read only
WBF     BIT     0DAH  ; read only
STR     BIT     0D9H  ; read/write
ENS     BIT     0D8H  ; read/write
$RESTORE

;-------------------------------------------------------------------------------
; Copyright 1995-1996 KEIL Software, Inc.
; 80C51GA Processor Declarations
;-------------------------------------------------------------------------------
$SAVE
$NOLIST
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

; 80C51GA Extensions
ADRES   DATA    84H
WDTLB   DATA    86H
WDTDIS  DATA    95H
WDTUB   DATA    96H
ADCON   DATA    97H
OFDCON  DATA    0A5H
WDTCON  DATA    0A6H
SEPCON  DATA    0D7H
SEPDAT  DATA    0E7H
SEPSTA  DATA    0F7H

; BIT Registers
; PSW
CY      BIT     0D7H
AC      BIT     0D6H
F0      BIT     0D5H
RS1     BIT     0D4H
RS0     BIT     0D3H
OV      BIT     0D2H
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
ES      BIT     0ACH
ET1     BIT     0ABH
EX1     BIT     0AAH
ET0     BIT     0A9H
EX0     BIT     0A8H
; IP
PS      BIT     0BCH
PT1     BIT     0BBH
PX1     BIT     0BAH
PT0     BIT     0B9H
PX0     BIT     0B8H
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

; 80C51GA Extensions
; IE
EAI     BIT     0AEH
; IP
PAI     BIT     0BEH
; P1
ACH3    BIT     93H
ACH2    BIT     92H
ACH1    BIT     91H
ACH0    BIT     90H
$RESTORE


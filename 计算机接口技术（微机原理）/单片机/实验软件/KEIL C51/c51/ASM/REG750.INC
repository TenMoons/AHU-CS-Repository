$SAVE
$NOLIST
;/* (c) Copyright KEIL ELEKTRONIK GmbH.  1997, All rights reserved. */
;  Register Declarations for the Philips 83/87C750 Processor
;
; BYTE Register
P0      DATA    80H
P1      DATA    90H
P3      DATA    0B0H
PSW     DATA    0D0H
ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    81H
DPL     DATA    82H
DPH     DATA    83H
PCON    DATA    87H
TCON    DATA    88H
TL0     DATA    8AH
RTL     DATA    8BH
TH0     DATA    8CH
IE      DATA    0A8H
SCON    DATA    98H
SBUF    DATA    99H


; BIT Register
; PSW
CY      BIT     0D7H
AC      BIT     0D6H
F0      BIT     0D5H
RS1     BIT     0D4H
RS0     BIT     0D3H
OV      BIT     0D2H
P       BIT     0D0H
; TCON
GATE    BIT     8FH
CT      BIT     8EH
TF      BIT     8DH
TR      BIT     8CH
IE0     BIT     8BH
IT0     BIT     8AH
IE1     BIT     89H
IT1     BIT     88H
; IE 
EA      BIT     0AFH
EX1     BIT     0AAH
ET0     BIT     0A9H
EX0     BIT     0A8H
; IP 
PS      BIT     0BCH
PT1     BIT     0BBH
PX1     BIT     0BAH
PT0     BIT     0B9H
PX0     BIT     0B8H
; P1
T0      BIT     97H
INT1    BIT     96H
INT0    BIT     95H
; SCON
SM0     BIT     9FH
SM1     BIT     9EH
SM2     BIT     9DH
REN     BIT     9CH
TB8     BIT     9BH
RB8     BIT     9AH
TI      BIT     99H
RI      BIT     98H
$RESTORE

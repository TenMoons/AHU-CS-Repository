;-------------------------------------------------------------------------------
; Copyright 1995-1996 KEIL Software, Inc.
; 80C452 Processor Declarations
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

; 80C452 Extensions
P4      DATA    0C0H
SLCON   DATA    0E8H
IEP     DATA    0F8H
DCON0   DATA    92H
DCON1   DATA    93H
SARL0   DATA    0A2H
SARH0   DATA    0A3H
SARL1   DATA    0B2H
SARH1   DATA    0B3H
DARL0   DATA    0C2H
DARH0   DATA    0C3H
DARL1   DATA    0D2H
DARH1   DATA    0D3H
BCRL0   DATA    0E2H
BCRH0   DATA    0E3H
HSTAT   DATA    0E6H
HCON    DATA    0E7H
SSTAT   DATA    0E9H
IWPR    DATA    0EAH
IRPR    DATA    0EBH
CBP     DATA    0ECH
FIN     DATA    0EEH
CIN     DATA    0EFH
BCRL1   DATA    0F2H
BCRH1   DATA    0F3H
ITHR    DATA    0F6H
OTHR    DATA    0F7H
MODE    DATA    0F9H
ORPR    DATA    0FAH
OWPR    DATA    0FBH
IMIN    DATA    0FCH
IMOUT   DATA    0FDH
FOUT    DATA    0FEH
COUT    DATA    0FFH


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

; 80C452 Extensions
; P1
HLDA    BIT     96H
HLD     BIT     95H
; SLCON
IFI     BIT     0EFH
OFI     BIT     0EEH
ICII    BIT     0EDH
ICOI    BIT     0ECH
FRZ     BIT     0EBH
IFRS    BIT     0E9H
OFRS    BIT     0E8H
; IEP
PFIFO   BIT     0FDH
EDMA0   BIT     0FCH
EDMA1   BIT     0FBH
PDMA0   BIT     0FAH
PDMA1   BIT     0F9H
EFIFO   BIT     0F8H
$RESTORE


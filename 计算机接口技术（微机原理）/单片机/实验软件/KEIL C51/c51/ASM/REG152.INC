;-------------------------------------------------------------------------------
; Copyright 1995-1996 KEIL Software, Inc.
; 80C152 Processor Declarations
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

; 80C152 Extensions
P4      DATA    0C0H
P5      DATA    91H
P6      DATA    0A1H
IEN1    DATA    0C8H
TSTAT   DATA    0D8H
RSTAT   DATA    0E8H
IPN1    DATA    0F8H
GMOD    DATA    84H
TFIFO   DATA    85H
DCON0   DATA    92H
DCON1   DATA    93H
BAUD    DATA    94H
ADR0    DATA    95H
SARL0   DATA    0A2H
SARH0   DATA    0A3H
IFS     DATA    0A4H
ADR1    DATA    0A5H
SARL1   DATA    0B2H
SARH1   DATA    0B3H
SLOTTM  DATA    0B4H
ADR2    DATA    0B5H
DARL0   DATA    0C2H
DARH0   DATA    0C3H
BKOFF   DATA    0C4H
ADR3    DATA    0C5H
DARL1   DATA    0D2H
DARH1   DATA    0D3H
TCDCNT  DATA    0D4H
AMSK0   DATA    0D5H
BCRL0   DATA    0E2H
BCRH0   DATA    0E3H
PRBS    DATA    0E4H
AMSK1   DATA    0E5H
BCRL1   DATA    0F2H
BCRH1   DATA    0F3H
RFIFO   DATA    0F4H
MYSLOT  DATA    0F5H


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

; 80C152 Extensions
; P1
HLDA    BIT     96H
HLD     BIT     95H
RXC     BIT     94H
TXC     BIT     93H
DEN     BIT     92H
GTXD    BIT     91H
GRXD    BIT     90H
; IEN1
EGSTE   BIT     0CDH
EDMA1   BIT     0CCH
EGSTV   BIT     0CBH
EDMA0   BIT     0CAH
EGSRE   BIT     0C9H
EGSRV   BIT     0C8H
; TSTAT
LNI     BIT     0DFH
NOACK   BIT     0DEH
UR      BIT     0DDH
TCDT    BIT     0DCH
TDN     BIT     0DBH
TFNF    BIT     0DAH
TEN     BIT     0D9H
DMA     BIT     0D8H
; RSTAT
OVR     BIT     0EFH
RCABT   BIT     0EEH
AE      BIT     0EDH
CRCE    BIT     0ECH
RDN     BIT     0EBH
RFNE    BIT     0EAH
GREN    BIT     0E9H
HABEN   BIT     0E8H
; IPN1
PGSTE   BIT     0FDH
PDMA1   BIT     0FCH
PGSTV   BIT     0FBH
PDMA0   BIT     0FAH
PGSRE   BIT     0F9H
PGSRV   BIT     0F8H
$RESTORE


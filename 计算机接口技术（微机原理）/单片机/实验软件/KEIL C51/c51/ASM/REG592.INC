;-------------------------------------------------------------------------------
; Copyright 1995-1996 KEIL Software, Inc.
; 80592 Processor Declarations
;-------------------------------------------------------------------------------
$SAVE
$NOLIST
;
;/*  BYTE Registers  */
P0        DATA     080H
P1        DATA     090H
P2        DATA     0A0H
P3        DATA     0B0H
P4        DATA     0C0H
P5        DATA     0C4H

PSW       DATA     0D0H
ACC       DATA     0E0H
B         DATA     0F0H
SP        DATA     081H
DPL       DATA     082H
DPH       DATA     083H
PCON      DATA     087H
TCON      DATA     088H
TMOD      DATA     089H
TL0       DATA     08AH
TL1       DATA     08BH
TH0       DATA     08CH
TH1       DATA     08DH
IEN0      DATA     0A8H
IEN1      DATA     0E8H
IP0       DATA     0B8H
IP1       DATA     0F8H
S0CON     DATA     098H
S0BUF     DATA     099H
CML0      DATA     0A9H
CML1      DATA     0AAH
CML2      DATA     0ABH
CTL0      DATA     0ACH
CTL1      DATA     0ADH
CTL2      DATA     0AEH
CTL3      DATA     0AFH
ADCON     DATA     0C5H
ADCH      DATA     0C6H
TM2IR     DATA     0C8H
CMH0      DATA     0C9H
CMH1      DATA     0CAH
CMH2      DATA     0CBH
CTH0      DATA     0CCH
CTH1      DATA     0CDH
CTH2      DATA     0CEH
CTH3      DATA     0CFH

CANSTA    DATA     0D8H
CANCON    DATA     0D9H
CANDAT    DATA     0DAH
CANADR    DATA     0DBH

TM2CON    DATA     0EAH
CTCON     DATA     0EBH
TML2      DATA     0ECH
TMH2      DATA     0EDH
STE       DATA     0EEH
RTE       DATA     0EFH
PWM0      DATA     0FCH
PWM1      DATA     0FDH
PWMP      DATA     0FEH
T3        DATA     0FFH

;/*  BIT Registers  */
;/*  PSW  */
CY        BIT     0D7H
AC        BIT     0D6H
F0        BIT     0D5H
RS1       BIT     0D4H
RS0       BIT     0D3H
OV        BIT     0D2H
P         BIT     0D0H

;/*  TCON  */
TF1       BIT     08FH
TR1       BIT     08EH
TF0       BIT     08DH
TR0       BIT     08CH
IE1       BIT     08BH
IT1       BIT     08AH
IE0       BIT     089H
IT0       BIT     088H

;/*  IEN0  */
EA        BIT     0AFH
EAD       BIT     0AEH
ES1       BIT     0ADH
ES0       BIT     0ACH
ET1       BIT     0ABH
EX1       BIT     0AAH
ET0       BIT     0A9H
EX0       BIT     0A8H

;/*  IEN1  */
ET2       BIT     0EFH
ECM2      BIT     0EEH
ECM1      BIT     0EDH
ECM0      BIT     0ECH
ECT3      BIT     0EBH
ECT2      BIT     0EAH
ECT1      BIT     0E9H
ECT0      BIT     0E8H

;/*  IP0  */
PAD       BIT     0BEH
PS1       BIT     0BDH
PS0       BIT     0BCH
PT1       BIT     0BBH
PX1       BIT     0BAH
PT0       BIT     0B9H
PX0       BIT     0B8H

;/*  IP1  */
PT2       BIT     0FFH
PCM2      BIT     0FEH
PCM1      BIT     0FDH
PCM0      BIT     0FCH
PCT3      BIT     0FBH
PCT2      BIT     0FAH
PCT1      BIT     0F9H
PCT0      BIT     0F8H

;/*  P1  */
CTX1      BIT     097H
CTX0      BIT     096H
RT2       BIT     095H
T2        BIT     094H
INT5      BIT     093H
INT4      BIT     092H
INT3      BIT     091H
INT2      BIT     090H
CT3I      BIT     093H
CT2I      BIT     092H
CT1I      BIT     091H
CT0I      BIT     090H
             
;/*  P3  */
RD        BIT     0B7H
WR        BIT     0B6H
T1        BIT     0B5H
T0        BIT     0B4H
INT1      BIT     0B3H
INT0      BIT     0B2H
TXD       BIT     0B1H
RXD       BIT     0B0H

;/*  P4  */
CMT1      BIT     0C7H
CMT0      BIT     0C6H
CMSR5     BIT     0C5H
CMSR4     BIT     0C4H
CMSR3     BIT     0C3H
CMSR2     BIT     0C2H
CMSR1     BIT     0C1H
CMSR0     BIT     0C0H

;/*  S0CON  */
SM0       BIT     09FH
SM1       BIT     09EH
SM2       BIT     09DH
REN       BIT     09CH
TB8       BIT     09BH
RB8       BIT     09AH
TI        BIT     099H
RI        BIT     098H

;/*  TM2IR  */
T20V      BIT     0CFH
CMI2      BIT     0CEH
CMI1      BIT     0CDH
CMI0      BIT     0CCH
CTI3      BIT     0CBH
CTI2      BIT     0CAH
CTI1      BIT     0C9H
CTI0      BIT     0C8H

;/*  CANSTA  */
RAMA7     BIT     0DFH
RAMA6     BIT     0DEH
RAMA5     BIT     0DDH
RAMA4     BIT     0DCH
RAMA3     BIT     0DBH
RAMA2     BIT     0DAH
RAMA1     BIT     0D9H
RAMA0     BIT     0D8H
$RESTORE


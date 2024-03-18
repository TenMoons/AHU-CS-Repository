;-------------------------------------------------------------------------------
; Copyright 1995-1996 KEIL Software, Inc.
; 8xCL781 Processor Declarations
;-------------------------------------------------------------------------------
$SAVE
$NOLIST
;
;  BYTE Registers
P0      DATA    080H
P1      DATA    090H
P2      DATA    0A0H
P3      DATA    0B0H
PSW     DATA    0D0H
ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    081H
DPL     DATA    082H
DPH     DATA    083H
PCON    DATA    087H
TCON    DATA    088H
TMOD    DATA    089H
TL0     DATA    08AH
TL1     DATA    08BH
TH0     DATA    08CH
TH1     DATA    08DH

IEN0    DATA    0A8H
IEN1    DATA    0E8H
IP0     DATA    0B8H
IP1     DATA    0F8H
IRQ1    DATA    0C0H
IX1     DATA    0E9H

S0CON   DATA    098H
S0BUF   DATA    099H
S1ADR   DATA    0DBH
S1CON   DATA    0D8H
S1DAT   DATA    0DAH
S1STA   DATA    0D9H

T2CON   DATA    0C8H
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
TL2     DATA    0CCH
TH2     DATA    0CDH


;  BIT Registers
;  PSW
CY      BIT     0D7H
AC      BIT     0D6H
F0      BIT     0D5H
RS1     BIT     0D4H
RS0     BIT     0D3H
OV      BIT     0D2H
P       BIT     0D0H

;  TCON
TF1     BIT     08FH
TR1     BIT     08EH
TF0     BIT     08DH
TR0     BIT     08CH
IE1     BIT     08BH
IT1     BIT     08AH
IE0     BIT     089H
IT0     BIT     088H

;  IEN0
EA      BIT     0AFH
ET2     BIT     0AEH
ES1     BIT     0ADH
ES0     BIT     0ACH
ET1     BIT     0ABH
EX1     BIT     0AAH
ET0     BIT     0A9H
EX0     BIT     0A8H

;  IEN1
EX9     BIT     0EFH
EX8     BIT     0EEH
EX7     BIT     0EDH
EX6     BIT     0ECH
EX5     BIT     0EBH
EX4     BIT     0EAH
EX3     BIT     0E9H
EX2     BIT     0E8H

;  IRQ1
IQ9     BIT     0C7H
IQ8     BIT     0C6H
IQ7     BIT     0C5H
IQ6     BIT     0C4H
IQ5     BIT     0C3H
IQ4     BIT     0C2H
IQ3     BIT     0C1H
IQ2     BIT     0C0H

;  IP0
PT2     BIT     0BEH
PS1     BIT     0BDH
PS0     BIT     0BCH
PT1     BIT     0BBH
PX1     BIT     0BAH
PT0     BIT     0B9H
PX0     BIT     0B8H

;  IP1
PX9     BIT     0FFH
PX8     BIT     0FEH
PX7     BIT     0FDH
PX6     BIT     0FCH
PX5     BIT     0FBH
PX4     BIT     0FAH
PX3     BIT     0F9H
PX2     BIT     0F8H

;  P1
INT9    BIT     097H
SDA     BIT     097H
INT8    BIT     096H
SCL     BIT     096H
INT7    BIT     095H
INT6    BIT     094H
INT5    BIT     093H
INT4    BIT     092H
INT3    BIT     091H
T2EX    BIT     091H
INT2    BIT     090H
T2      BIT     090H

;  P3
RD      BIT     0B7H
WR      BIT     0B6H
T1      BIT     0B5H
T0      BIT     0B4H
INT1    BIT     0B3H
INT0    BIT     0B2H
TXD     BIT     0B1H
RXD     BIT     0B0H

;  SCON0
SM0     BIT     09FH
SM1     BIT     09EH
SM2     BIT     09DH
REN     BIT     09CH
TB8     BIT     09BH
RB8     BIT     09AH
TI      BIT     099H
RI      BIT     098H

;  S1CON
ENS1    BIT     0DEH
STA     BIT     0DDH
STO     BIT     0DCH
SI      BIT     0DBH
AA      BIT     0DAH
CR1     BIT     0D9H
CR0     BIT     0D8H

;  T2CON
TF2     BIT     0CFH
EXF2    BIT     0CEH
GF2     BIT     0CDH
RTCLK   BIT     0CCH
EXEN2   BIT     0CBH
TR2     BIT     0CAH
C_T2    BIT     0C9H
CP_RL2  BIT     0C8H
$RESTORE


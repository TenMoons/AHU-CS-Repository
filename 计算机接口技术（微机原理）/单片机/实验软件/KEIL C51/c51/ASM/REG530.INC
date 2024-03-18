$SAVE
$NOLIST
; (c) Copyright KEIL ELEKTRONIK GmbH. 1997 - 2000, All rights reserved. */
; DALLAS DS87C520 Processor Declarations */

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
IE      DATA    0A8H
IP      DATA    0B8H
SCON0   DATA    098H
SBUF0   DATA    099H

;  DS8xC520/530 Extensions
DPL1    DATA    084H
DPH1    DATA    085H
DPS     DATA    086H
CKCON   DATA    08EH
EXIF    DATA    091H
TRIM    DATA    096H ;8xC530 only!
SADDR0  DATA    0A9H
SADDR1  DATA    0AAH
SADEN0  DATA    0B9H
SADEN1  DATA    0BAH
SCON1   DATA    0C0H
SBUF1   DATA    0C1H
ROMSIZE DATA    0C2H
PMR     DATA    0C4H
STATUS  DATA    0C5H
TA      DATA    0C7H
T2CON   DATA    0C8H
T2MOD   DATA    0C9H
RCAP2L  DATA    0CAH
RCAP2H  DATA    0CBH
TL2     DATA    0CCH
TH2     DATA    0CDH
WDCON   DATA    0D8H
EIE     DATA    0E8H
RTASS   DATA    0F2H ;8xC530 only!
RTAS    DATA    0F3H ;8xC530 only!
RTAM    DATA    0F4H ;8xC530 only!
RTAH    DATA    0F5H ;8xC530 only!
EIP     DATA    0F8H
RTCC    DATA    0F9H ;8xC530 only!
RTCSS   DATA    0FAH ;8xC530 only!
RTCS    DATA    0FBH ;8xC530 only!
RTCM    DATA    0FCH ;8xC530 only!
RTCH    DATA    0FDH ;8xC530 only!
RTCD0   DATA    0FEH ;8xC530 only!
RTCD1   DATA    0FFH ;8xC530 only!

;  BIT Registers
; *** PSW ***
CY      BIT     0D7H
AC      BIT     0D6H
F0      BIT     0D5H
RS1     BIT     0D4H
RS0     BIT     0D3H
OV      BIT     0D2H
FL      BIT     0D1H
P       BIT     0D0H

; *** TCON ***
TF1     BIT     08FH
TR1     BIT     08EH
TF0     BIT     08DH
TR0     BIT     08CH
IE1     BIT     08BH
IT1     BIT     08AH
IE0     BIT     089H
IT0     BIT     088H

; *** IE ***
EA      BIT     0AFH
ES1     BIT     0AEH
ET2     BIT     0ADH
ES0     BIT     0ACH
ET1     BIT     0ABH
EX1     BIT     0AAH
ET0     BIT     0A9H
EX0     BIT     0A8H

; *** IP ***
PS1     BIT     0BEH
PT2     BIT     0BDH
PS0     BIT     0BCH
PT1     BIT     0BBH
PX1     BIT     0BAH
PT0     BIT     0B9H
PX0     BIT     0B8H

; *** P1 ***
INT5    BIT     097H
INT4    BIT     096H
INT3    BIT     095H
INT2    BIT     094H
TXD1    BIT     093H
RXD1    BIT     092H
T2EX    BIT     091H
T2      BIT     090H

; *** P3 ***
RD      BIT     0B7H
WR      BIT     0B6H
T1      BIT     0B5H
T0      BIT     0B4H
INT1    BIT     0B3H
INT0    BIT     0B2H
TXD0    BIT     0B1H
RXD0    BIT     0B0H

; *** SCON0 ***
SM0     BIT     09FH ;Alternate SM0_FE0
SM1     BIT     09EH ;Alternate SM10
SM2     BIT     09DH ;Alternate SM20
REN     BIT     09CH ;Alternate REN0
TB8     BIT     09BH ;Alternate TB80
RB8     BIT     09AH ;Alternate RB80
TI      BIT     099H ;Alternate TI0
RI      BIT     098H ;Alternate RI0

; *** SCON1 ***
SM01    BIT     0C7H
SM11    BIT     0C6H
SM21    BIT     0C5H
REN1    BIT     0C4H
TB81    BIT     0C3H
RB81    BIT     0C2H
TI1     BIT     0C1H
RI1     BIT     0C0H

; *** T2CON ***
TF2     BIT     0CFH
EXF2    BIT     0CEH
RCLK    BIT     0CDH
TCLK    BIT     0CCH
EXEN2   BIT     0CBH
TR2     BIT     0CAH
C_T2    BIT     0C9H
CP_RL2  BIT     0C8H

; *** WDCON ***
SMOD    BIT     0DFH
POR     BIT     0DEH
EPFI    BIT     0DDH
PFI     BIT     0DCH
WDIF    BIT     0DBH
WDRF    BIT     0DAH
EWT     BIT     0D9H
RWT     BIT     0D8H

; *** EIE ***
ERTCI   BIT     0EDH ;8xC530 only!
EWDI    BIT     0ECH
EX5     BIT     0EBH
EX4     BIT     0EAH
EX3     BIT     0E9H
EX2     BIT     0E8H

; *** EIP ***
PRTCI   BIT     0FDH ;8xC530 only!
PWDI    BIT     0FCH
PX5     BIT     0FBH
PX4     BIT     0FAH
PX3     BIT     0F9H
PX2     BIT     0F8H
$RESTORE

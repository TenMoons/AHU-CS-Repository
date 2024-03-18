;*INC*************************************************************************
; NAME: 89C5115.inc           
;----------------------------------------------------------------------------
; PURPOSE: for Keil
;*****************************************************************************

;----------------------------------------
; Include file for 8051 SFR Definitions  
;----------------------------------------

;  BYTE Register 
P1      DATA    90H
P2      DATA    0A0H

P3      DATA    0B0H
RD      BIT     0B7H
WR      BIT     0B6H
T1      BIT     0B5H
T0      BIT     0B4H
INT1    BIT     0B3H
INT0    BIT     0B2H
TXD     BIT     0B1H
RXD     BIT     0B0H

P4      DATA    0C0H

PSW     DATA    0D0H
CY      BIT     0D7H
AC      BIT     0D6H
F0      BIT     0D5H
RS1     BIT     0D4H
RS0     BIT     0D3H
OV      BIT     0D2H
P       BIT     0D0H

ACC     DATA    0E0H
B       DATA    0F0H
SP      DATA    81H
DPL     DATA    82H
DPH     DATA    83H
PCON    DATA    87H
CKCON   DATA    8FH

;------------------ TIMERS registers ---------------------
TCON    DATA    88H
TF1     BIT     8FH
TR1     BIT     8EH
TF0     BIT     8DH
TR0     BIT     8CH
IE1     BIT     8BH
IT1     BIT     8AH
IE0     BIT     89H
IT0     BIT     88H
	
TMOD    DATA    89H

T2CON   DATA    0C8H
TF2     BIT 	0CFH
EXF2    BIT 	0CEH
RCLK    BIT 	0CDH
TCLK    BIT 	0CCH
EXEN2   BIT 	0CBH
TR2     BIT 	0CAH
C_T2    BIT 	0C9H
CP_RL2  BIT 	0C8H
	
T2MOD 	DATA	0C9H	
TL0     DATA    8AH
TL1     DATA    8BH
TL2 	DATA	0CCH
TH0     DATA    8CH
TH1     DATA    8DH
TH2 	DATA	0CDH	
RCAP2L 	DATA	0CAH	
RCAP2H 	DATA	0CBH	
WDTRST  DATA	0A6H	
WDTPRG  DATA	0A7H	


;------------------- UART registers ------------------------
SCON    DATA    98H
SM0  	BIT 	9FH
FE   	BIT	9FH
SM1  	BIT	9EH
SM2  	BIT	9DH
REN  	BIT	9CH
TB8  	BIT	9BH
RB8  	BIT	9AH
TI   	BIT	99H
RI   	BIT	98H

SBUF    DATA    99H
SADEN 	DATA	0B9H
SADDR 	DATA	0A9H	

;-------------------- ADC registers ----------------------
ADCLK 	DATA	0F2H	
ADCON 	DATA	0F3H	
ADDL 	DATA	0F4H	
ADDH 	DATA	0F5H	
ADCF 	DATA	0F6H	

;-------------------- FLASH EEPROM registers ------------

FCON  	DATA	0D1H	
EECON  	DATA	0D2H	
AUXR  	DATA	8EH
AUXR1  	DATA	0A2H

;-------------------- IT registers -----------------------
IPL1 	DATA	0F8H	
IPH1 	DATA	0F7H	
IEN0  	DATA	0A8H	
IPL0 	DATA	0B8H	
IPH0 	DATA	0B7H	
IEN1  	DATA	0E8H	

;  IEN0  
EA   	BIT 	0AFH
EC   	BIT 	0AEH
ET2  	BIT 	0ADH
ES   	BIT 	0ACH
ET1  	BIT 	0ABH
EX1  	BIT 	0AAH
ET0  	BIT 	0A9H
EX0  	BIT 	0A8H

;  IEN1 

EADC 	BIT  	0E9H


;--------------------- PCA registers --------------------
CCON 	DATA	0D8H	
CF		BIT		0DFH
CR		BIT		0DEH

CCF1	BIT		0D1H
CCF0	BIT		0D0H

CMOD 	DATA	0D9H	
CH 	DATA	0F9H	
CL 	DATA	0E9H	
CCAP0H  DATA	0FAH	
CCAP0L  DATA	0EAH	
CCAPM0  DATA	0DAH	
CCAP1H  DATA	0FBH	
CCAP1L  DATA	0EBH	
CCAPM1  DATA	0DBH	



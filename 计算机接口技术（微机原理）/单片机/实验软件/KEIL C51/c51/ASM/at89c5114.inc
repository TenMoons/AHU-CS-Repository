;*INC***********************************************************************
; NAME: at89c5114.inc         
; PURPOSE: for KEIL 
;***************************************************************************


;----------------------------------------
; Include file for 8051 SFR Definitions  
;----------------------------------------

;  BYTE Register  
P0     DATA 80h        
P0_7   BIT  87h
P0_6   BIT  86h
P0_5   BIT  85h
P0_4   BIT  84h
P0_3   BIT  83h
P0_2   BIT  82h
P0_1   BIT  81h
P0_0   BIT  80h

P2     DATA 0A0h
P2_3   BIT  0A3h
P2_2   BIT  0A2h
P2_1   BIT  0A1h
P2_0   BIT  0A0h
       
P3     DATA 0B0h        
P3_7   BIT  0B7h
P3_6   BIT  0B6h
P3_5   BIT  0B5h
P3_4   BIT  0B4h
P3_3   BIT  0B3h
P3_2   BIT  0B2h
P3_1   BIT  0B1h
P3_0   BIT  0B0h

P3M1   DATA 0D5h
P3M2   DATA 0E4h

P4     DATA 0C0h        
P4_3   BIT  0C3h
P4_2   BIT  0C2h
P4_1   BIT  0C1h
P4_0   BIT  0C0h

P4M1   DATA 0D6h

; P2 
RD     BIT  0B7h
WR     BIT  0B6h
T0     BIT  0B4h
INT0   BIT  0B2h

; P4 
INT1   BIT  0C3h
T1     BIT  0C1h 

PSW    DATA 0D0h
CY     BIT  0D7h
AC     BIT  0D6h
F0     BIT  0D5h
RS1    BIT  0D4h
RS0    BIT  0D3h
OV     BIT  0D2h
UD     BIT  0D1h
P      BIT  0D0h

ACC    DATA 0E0h       
B      DATA 0F0h 
SP     DATA  81h        
DPL    DATA  82h       
DPH    DATA  83h       

PCON   DATA  87h      

;------------------ TIMERS registers ---------------------
TCON   DATA  88h
TF1    BIT   8Fh
TR1    BIT   8Eh
TF0    BIT   8Dh
TR0    BIT   8Ch
IE1    BIT   8Bh
IT1    BIT   8Ah
IE0    BIT   89h
IT0    BIT   88h
        
TMOD   DATA  89h      
TL0    DATA  8Ah       
TL1    DATA  8Bh       
TL2    DATA 0CCh       
TH0    DATA  8Ch       
TH1    DATA  8Dh       
TH2    DATA 0CDh       
WDTRST DATA 0A6h    
WDTPRG DATA 0A7h    

;------------------- ADC registers -------------------------
ADCA   DATA 0F7h
ADCF   DATA 0F6h
ADCLK  DATA 0F2h
ADCON  DATA 0F3h
ADDH   DATA 0F5h
ADDL   DATA 0F4h

;------------------- FLASH EEPROM registers ----------------
FCON   DATA 0D1h
AUXR   DATA  8Eh
AUXR1  DATA 0A2h

;------------------- IT registers --------------------------
IEN0   DATA  0A8h      
IPH0   DATA  0B7h      
IPL0   DATA  0B8h      
IOR    DATA  0A5h

;  IE0  
EA     BIT  0AFh
EADC   BIT  0AEh
EW1    BIT  0ADh
EW0    BIT  0ACh
ET1    BIT  0ABh
EX1    BIT  0AAh
ET0    BIT  0A9h
EX0    BIT  0A8h

; IPL0 
PADC   BIT  0BEh
PW1    BIT  0BDh
PW0    BIT  0BCh
PT1    BIT  0BBh
PX1    BIT  0BAh
PT0    BIT  0B9h
PX0    BIT  0B8h

;--------------------- PCA registers -----------------------------

;--------------------- PWM registers -----------------------------

W0CH   DATA 0ECh
W0CL   DATA 0EDh
W0CON  DATA 0E8h
W0FH   DATA 0EAh
W0FL   DATA 0EBh
W0IC   DATA 0EEh
W0MOD  DATA 0E9h
W0R0H  DATA 0D9h
W0R0L  DATA 0DAh
W0R1H  DATA 0DBh
W0R1L  DATA 0DCh
W0R2H  DATA 0DDh
W0R2L  DATA 0DEh

W1CH   DATA 0FCh
W1CL   DATA 0FDh
W1CON  DATA 0F8h
W1FH   DATA 0FAh
W1FL   DATA 0FBh
W1IC   DATA 0FEh
W1R0H  DATA 0C9h
W1R0L  DATA 0CAh

; W0CON 
W0UP   BIT  0EFh
W0R    BIT  0EEh
W0OS   BIT  0EBh
W0EN2  BIT  0EAh
W0EN1  BIT  0E9h
W0EN0  BIT  0E8h

; W1CON 
W1UP   BIT  0FFh
W1R    BIT  0FEh
W1ECLK BIT  0FCh
W1CPS1 BIT  0FBh
W1CPS0 BIT  0FAh
W1INV0 BIT  0F9h
W1EN0  BIT  0F8h


;-------------------- OSC control registers ----------------------

CKCON  DATA  8Fh
CKRL   DATA  97h
CKSEL  DATA  85h
OSCBFA DATA  9Fh
OSCCON DATA  86h











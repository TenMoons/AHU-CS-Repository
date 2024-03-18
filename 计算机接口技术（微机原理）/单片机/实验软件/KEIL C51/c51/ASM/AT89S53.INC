;-------------------------------------------------------------------
; AT89S53.INC
;
; Copyright 1997 KEIL ELEKTRONIK GmbH.  1997, All rights reserved.
; Atmel AT89S53 Processor Declarations
;-------------------------------------------------------------------
$SAVE
$NOLIST
;
; Byte Registers
;
P0      DATA 80H     ; Port 0 
SP      DATA 81H     ; Stack Pointer 
DPL     DATA 82H     ; Data Pointer Low Byte 
DP0L    DATA 82H     ; Alternate Definition 
DPH     DATA 83H     ; Data Pointer High Byte 
DP0H    DATA 83H     ; Alternate Definition 
DP1L    DATA 84H     ; Data Pointer 1 Low Byte 
DP1H    DATA 85H     ; Data Pointer 1 High Byte 
SPDR    DATA 86H     ; SPI Data Register 
PCON    DATA 87H     ; Power Control Register 
;
TCON    DATA 88H     ; Timer Control Register 
TMOD    DATA 89H     ; Timer Mode Control Register 
TL0     DATA 8AH     ; Timer 0 Low Byte 
TL1     DATA 8BH     ; Timer 1 Low Byte 
TH0     DATA 8CH     ; Timer 0 High Byte 
TH1     DATA 8DH     ; Timer 1 High Byte 
;
P1      DATA 90H     ; Port 1 
WMCON   DATA 96H     ; Watchdog and Memory Control Register 
SCON    DATA 98H     ; Serial Port Control 
SBUF    DATA 99H     ; Serial Port Buffer 
;
P2      DATA 0A0H     ; Port 2 
IE      DATA 0A8H     ; Interrupt Enable Register 0 
SPSR    DATA 0AAH     ; SPI Status Register 
;
P3      DATA 0B0H     ; Port 3 
IP      DATA 0B8H     ; Interrupt Priority Register 
;
T2CON   DATA 0C8H     ; Timer 2 Control 
T2MOD	  DATA 0C9H     ; Timer 2 Mode 
RCAP2L  DATA 0CAH     ; Timer 2 Capture Low Byte 
RCAP2H  DATA 0CBH     ; Timer 2 Capture High Byte 
TL2     DATA 0CCH     ; Timer 2 Low Byte 
TH2     DATA 0CDH     ; Timer 2 High Byte 
;
PSW     DATA 0D0H     ; Program Status Word 
SPCR    DATA 0D5H     ; SPI Control Register 
ACC     DATA 0E0H     ; Accumulator 
B       DATA 0F0H     ; B Register 
;
;
; Bit Registers
;
P0_0 BIT 80H
P0_1 BIT 81H
P0_2 BIT 82H
P0_3 BIT 83H
P0_4 BIT 84H
P0_5 BIT 85H
P0_6 BIT 86H
P0_7 BIT 87H
;
;TCON (88H) Bit Registers
IT0  BIT 88H       ; Interrupt 0 Type Control Bit 
IE0  BIT 89H       ; Interrupt 0 Edge Flag 
IT1  BIT 8AH       ; Interrupt 1 Type Control Bit 
IE1  BIT 8BH       ; Interrupt 1 Edge Flag 
TR0  BIT 8CH       ; Timer 0 Run Control Bit 
TF0  BIT 8DH       ; Timer 0 Overflow Flag 
TR1  BIT 8EH       ; Timer 1 Run Control Bit 
TF1  BIT 8FH       ; Timer 1 Overflow Flag 
;
;P1 (90H) Bit Registers
P1_0 BIT 90H
P1_1 BIT 91H
P1_2 BIT 92H
P1_3 BIT 93H
P1_4 BIT 94H
P1_5 BIT 95H
P1_6 BIT 96H
P1_7 BIT 97H
;
T2   BIT 90H       ; External input to Timer/Counter 2, clock out 
T2EX BIT 91H       ; Timer/Counter 2 capture/reload trigger & dir ctl 
SS   BIT 94H       ; SPI: SS - Slave port select input 
MOSI BIT 95H       ; SPI: MOSI - Master data output, slave data input 
MISO BIT 96H       ; SPI: MISO - Master data input, slave data output 
SCK  BIT 97H       ; SPI: SCK - Master clock output, slave clock input 
;
; SCON (98H) Bit Registers
RI   BIT 98H       ; Receive Interrupt Flag 
TI   BIT 99H       ; Transmit Interrupt Flag 
RB8  BIT 9AH       ; 9th data bit received 
TB8  BIT 9BH       ; 9th data bit to be transmitted in modes 2 & 3 
REN  BIT 9CH       ; Receive Enable 
SM2  BIT 9DH       ; Serial Port Mode Bit 2 
SM1  BIT 9EH       ; Serial Port Mode Bit 1 
SM0  BIT 9FH       ; Serial Port Mode Bit 0 
;
; P2 (A0H) Bit Registers
P2_0 BIT 0A0H
P2_1 BIT 0A1H
P2_2 BIT 0A2H
P2_3 BIT 0A3H
P2_4 BIT 0A4H
P2_5 BIT 0A5H
P2_6 BIT 0A6H
P2_7 BIT 0A7H
;
; IE (A8H) Bit Registers
EX0  BIT 0A8H       ; External Interrupt 0 Enable: 1=Enabled 
ET0  BIT 0A9H       ; Timer 0 Interrupt Enable: 1=Enabled 
EX1  BIT 0AAH       ; External Interrupt 1 Enable: 1=Enabled 
ET1  BIT 0ABH       ; Timer 1 Interrupt Enable: 1=Enabled 
ES   BIT 0ACH       ; SPI and UART Interrupt Enable: 1=Enabled 
ET2  BIT 0ADH       ; Timer 2 Interrupt Enable: 1=Enabled 
EA   BIT 0AFH       ; Global Interrupt Enable: 0=Disable all interrupts 
;
; P3 (B0H) Bit Registers (Mnemonics & Ports)
P3_0  BIT  0B0H
P3_1  BIT  0B1H
P3_2  BIT  0B2H
P3_3  BIT  0B3H
P3_4  BIT  0B4H
P3_5  BIT  0B5H
P3_6  BIT  0B6H
P3_7  BIT  0B7H
;
RXD  BIT 0B0H       ; Serial data input 
TXD  BIT 0B1H       ; Serial data output 
INT0 BIT 0B2H       ; External interrupt 0 
INT1 BIT 0B3H       ; External interrupt 1 
T0   BIT 0B4H       ; Timer 0 external input 
T1   BIT 0B5H       ; Timer 1 external input 
WR   BIT 0B6H       ; External data memory write strobe 
RD   BIT 0B7H       ; External data memory read strobe 
;
; IP (B8H) Bit Registers
PX0  BIT 0B8H       ; External Interrupt 0 Priority Bit 
PT0  BIT 0B9H       ; Timer 0 Interrupt Priority Bit 
PX1  BIT 0BAH       ; External Interrupt 1 Priority Bit 
PT1  BIT 0BBH       ; Timer 1 Interrupt Priority Bit 
PS   BIT 0BCH       ; Serial Port Interrupt Priority Bit    
PT2  BIT 0BDH       ; Timer 2 Interrupt Priority Bit 
;
;T2CON (C8H) Bit Registers
CP_RL2 BIT 0C8H       ; 0=Reload, 1=Capture select 
C_T2   BIT 0C9H       ; 0=Timer, 1=Counter 
TR2    BIT 0CAH       ; 0=Stop timer, 1=Start timer 
EXEN2  BIT 0CBH       ; Timer 2 external enable 
TCLK   BIT 0CCH       ; 0=Serial clock uses Timer 1 overflow, 1=Timer 2 
RCLK   BIT 0CDH       ; 0=Serial clock uses Timer 1 overflow, 1=Timer 2 
EXF2   BIT 0CEH       ; Timer 2 external flag 
TF2    BIT 0CFH       ; Timer 2 overflow flag 
;
;PSW (D0H) Bit Registers
P    BIT 0D0H       ; Parity Flag 
FL   BIT 0D1H       ; User Flag 
OV   BIT 0D2H       ; Overflow Flag 
RS0  BIT 0D3H       ; Register Bank Select Bit 0 
RS1  BIT 0D4H       ; Register Bank Select Bit 1 
F0   BIT 0D5H       ; User Flag 0 
AC   BIT 0D6H       ; Auxiliary Carry Flag 
CY   BIT 0D7H       ; Carry Flag 
;
$RESTORE
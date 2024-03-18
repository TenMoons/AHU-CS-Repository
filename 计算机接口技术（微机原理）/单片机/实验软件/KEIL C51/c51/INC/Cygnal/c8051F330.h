/*---------------------------------------------------------------------------
; Copyright (C) 2002 CYGNAL INTEGRATED PRODUCTS, INC.
; All rights reserved.
;
;
; FILE NAME: C8051F330.H
; TARGET MCUs: C8051F330, F331
; DESCRIPTION: Register/bit definitions for the C8051F330 product family.
;
; REVISION 1.0
;
;---------------------------------------------------------------------------*/

/*  BYTE Registers  */

sfr P0            = 0x80; /* PORT 0 LATCH */
sfr SP            = 0x81; /* STACK POINTER */
sfr DPL           = 0x82; /* DATA POINTER LOW */
sfr DPH           = 0x83; /* DATA POINTER HIGH */
sfr PCON          = 0x87; /* POWER CONTROL */
sfr TCON          = 0x88; /* TIMER/COUNTER CONTROL */
sfr TMOD          = 0x89; /* TIMER/COUNTER MODE */
sfr TL0           = 0x8A; /* TIMER/COUNTER 0 LOW */
sfr TL1           = 0x8B; /* TIMER/COUNTER 1 LOW */
sfr TH0           = 0x8C; /* TIMER/COUNTER 0 HIGH */
sfr TH1           = 0x8D; /* TIMER/COUNTER 1 HIGH */
sfr CKCON         = 0x8E; /* CLOCK CONTROL */
sfr PSCTL         = 0x8F; /* PROGRAM STORE R/W CONTROL */
sfr P1            = 0x90; /* PORT 1 LATCH */
sfr TMR3CN        = 0x91; /* TIMER/COUNTER 3 CONTROL */
sfr TMR3RLL       = 0x92; /* TIMER/COUNTER 3 RELOAD LOW */
sfr TMR3RLH       = 0x93; /* TIMER/COUNTER 3 RELOAD HIGH */
sfr TMR3L         = 0x94; /* TIMER/COUNTER 3 LOW */
sfr TMR3H         = 0x95; /* TIMER/COUNTER 3 HIGH */
sfr IDA0L         = 0x96; /* CURRENT MODE DAC0 LOW */
sfr IDA0H         = 0x97; /* CURRENT MODE DAC0 HIGH */
sfr SCON0         = 0x98; /* UART0 CONTROL */
sfr SBUF0         = 0x99; /* UART0 DATA BUFFER */
sfr CPT0CN        = 0x9B; /* COMPARATOR0 CONTROL */
sfr CPT0MD        = 0x9D; /* COMPARATOR0 MODE SELECTION */
sfr CPT0MX        = 0x9F; /* COMPARATOR0 MUX SELECTION */
sfr P2            = 0xA0; /* PORT 2 LATCH */
sfr SPI0CFG       = 0xA1; /* SPI CONFIGURATION */
sfr SPI0CKR       = 0xA2; /* SPI CLOCK RATE CONTROL */
sfr SPI0DAT       = 0xA3; /* SPI DATA */
sfr P0MDOUT       = 0xA4; /* PORT 0 OUTPUT MODE CONFIGURATION */
sfr P1MDOUT       = 0xA5; /* PORT 1 OUTPUT MODE CONFIGURATION */
sfr P2MDOUT       = 0xA6; /* PORT 2 OUTPUT MODE CONFIGURATION */
sfr IE            = 0xA8; /* INTERRUPT ENABLE */
sfr CLKSEL        = 0xA9; /* CLOCK SELECT */
sfr EMI0CN        = 0xAA; /* EXTERNAL MEMORY INTERFACE CONTROL */
sfr OSCXCN        = 0xB1; /* EXTERNAL OSCILLATOR CONTROL */
sfr OSCICN        = 0xB2; /* INTERNAL OSCILLATOR CONTROL */
sfr OSCICL        = 0xB3; /* INTERNAL OSCILLATOR CALIBRATION */
sfr FLSCL         = 0xB6; /* FLASH SCALE */
sfr FLKEY         = 0xB7; /* FLASH LOCK AND KEY  */
sfr IP            = 0xB8; /* INTERRUPT PRIORITY */
sfr IDA0CN        = 0xB9; /* CURRENT MODE DAC0 CONTROL */
sfr AMX0N         = 0xBA; /* AMUX0 NEGATIVE CHANNEL SELECT */
sfr AMX0P         = 0xBB; /* AMUX0 POSITIVE CHANNEL SELECT */
sfr ADC0CF        = 0xBC; /* ADC0 CONFIGURATION */
sfr ADC0L         = 0xBD; /* ADC0 LOW */
sfr ADC0H         = 0xBE; /* ADC0 HIGH */
sfr SMB0CN        = 0xC0; /* SMBUS CONTROL */
sfr SMB0CF        = 0xC1; /* SMBUS CONFIGURATION */
sfr SMB0DAT       = 0xC2; /* SMBUS DATA */
sfr ADC0GTL       = 0xC3; /* ADC0 GREATER-THAN COMPARE LOW */
sfr ADC0GTH       = 0xC4; /* ADC0 GREATER-THAN COMPARE HIGH */
sfr ADC0LTL       = 0xC5; /* ADC0 LESS-THAN COMPARE WORD LOW */
sfr ADC0LTH       = 0xC6; /* ADC0 LESS-THAN COMPARE WORD HIGH */
sfr TMR2CN        = 0xC8; /* TIMER/COUNTER 2 CONTROL */
sfr TMR2RLL       = 0xCA; /* TIMER/COUNTER 2 RELOAD LOW */
sfr TMR2RLH       = 0xCB; /* TIMER/COUNTER 2 RELOAD HIGH */
sfr TMR2L         = 0xCC; /* TIMER/COUNTER 2 LOW */
sfr TMR2H         = 0xCD; /* TIMER/COUNTER 2 HIGH */
sfr PSW           = 0xD0; /* PROGRAM STATUS WORD */
sfr REF0CN        = 0xD1; /* VOLTAGE REFERENCE CONTROL */
sfr P0SKIP        = 0xD4; /* PORT 0 SKIP */
sfr P1SKIP        = 0xD5; /* PORT 1 SKIP */
sfr PCA0CN        = 0xD8; /* PCA CONTROL */
sfr PCA0MD        = 0xD9; /* PCA MODE  */
sfr PCA0CPM0      = 0xDA; /* PCA MODULE 0 MODE REGISTER */
sfr PCA0CPM1      = 0xDB; /* PCA MODULE 1 MODE REGISTER */
sfr PCA0CPM2      = 0xDC; /* PCA MODULE 2 MODE REGISTER */
sfr ACC           = 0xE0; /* ACCUMULATOR */
sfr XBR0          = 0xE1; /* PORT I/O CROSSBAR CONTROL 0 */
sfr XBR1          = 0xE2; /* PORT I/O CROSSBAR CONTROL 1 */
sfr OSCLCN        = 0xE3; /* LOW-FREQUENCY OSCILLATOR CONTROL */
sfr IT01CF        = 0xE4; /* INT0/INT1 CONFIGURATION */
sfr EIE1          = 0xE6; /* EXTENDED INTERRUPT ENABLE 1 */
sfr ADC0CN        = 0xE8; /* ADC0 CONTROL */
sfr PCA0CPL1      = 0xE9; /* PCA CAPTURE 1 LOW */
sfr PCA0CPH1      = 0xEA; /* PCA CAPTURE 1 HIGH */
sfr PCA0CPL2      = 0xEB; /* PCA CAPTURE 2 LOW */
sfr PCA0CPH2      = 0xEC; /* PCA CAPTURE 2 HIGH */
sfr RSTSRC        = 0xEF; /* RESET SOURCE CONFIGURATION/STATUS */
sfr B             = 0xF0; /* B REGISTER */
sfr P0MDIN        = 0xF1; /* PORT 0 INPUT MODE CONFIGURATION */
sfr P1MDIN        = 0xF2; /* PORT 1 INPUT MODE CONFIGURATION */
sfr EIP1          = 0xF6; /* EXTENDED INTERRUPT PRIORITY 1 */
sfr SPI0CN        = 0xF8; /* SPI CONTROL */
sfr PCA0L         = 0xF9; /* PCA COUNTER LOW */
sfr PCA0H         = 0xFA; /* PCA COUNTER HIGH */
sfr PCA0CPL0      = 0xFB; /* PCA CAPTURE 0 LOW */
sfr PCA0CPH0      = 0xFC; /* PCA CAPTURE 0 HIGH */
sfr VDM0CN        = 0xFF; /* VDD MONITOR CONTROL */



/* Bit Definitions */

/* TCON 0x88 */
sbit TF1 =        0x8F ;  /* TIMER 1 OVERFLOW FLAG */
sbit TR1 =        0x8E ;  /* TIMER 1 ON/OFF CONTROL */
sbit TF0 =        0x8D ;  /* TIMER 0 OVERFLOW FLAG */
sbit TR0 =        0x8C ;  /* TIMER 0 ON/OFF CONTROL */
sbit IE1 =        0x8B ;  /* EXT. INTERRUPT 1 EDGE FLAG */
sbit IT1 =        0x8A ;  /* EXT. INTERRUPT 1 TYPE */
sbit IE0 =        0x89 ;  /* EXT. INTERRUPT 0 EDGE FLAG */
sbit IT0 =        0x88 ;  /* EXT. INTERRUPT 0 TYPE */

/* SCON0 0x98 */
sbit S0MODE =     0x9F ;  /* UART 0 MODE */
sbit MCE0 =       0x9D ;  /* UART 0 MCE */
sbit REN0 =       0x9C ;  /* UART 0 RX ENABLE */
sbit TB80 =       0x9B ;  /* UART 0 TX BIT 8 */
sbit RB80 =       0x9A ;  /* UART 0 RX BIT 8 */
sbit TI0 =        0x99 ;  /* UART 0 TX INTERRUPT FLAG */
sbit RI0 =        0x98 ;  /* UART 0 RX INTERRUPT FLAG */

/* IE 0xA8 */
sbit EA =         0xAF ;  /* GLOBAL INTERRUPT ENABLE */
sbit ESPI0 =      0xAE ;  /* SPI0 INTERRUPT ENABLE */
sbit ET2  =       0xAD ;  /* TIMER 2 INTERRUPT ENABLE */
sbit ES0  =       0xAC ;  /* UART0 INTERRUPT ENABLE */
sbit ET1 =        0xAB ;  /* TIMER 1 INTERRUPT ENABLE */
sbit EX1 =        0xAA ;  /* EXTERNAL INTERRUPT 1 ENABLE */
sbit ET0 =        0xA9 ;  /* TIMER 0 INTERRUPT ENABLE */
sbit EX0 =        0xA8 ;  /* EXTERNAL INTERRUPT 0 ENABLE */

/* IP 0xB8 */
sbit PSPI0 =      0xBE ;  /* SPI0 PRIORITY */
sbit PT2 =        0xBD ;  /* TIMER 2 PRIORITY */
sbit PS0 =        0xBC ;  /* UART0 PRIORITY */
sbit PT1 =        0xBB ;  /* TIMER 1 PRIORITY */
sbit PX1 =        0xBA ;  /* EXTERNAL INTERRUPT 1 PRIORITY */
sbit PT0 =        0xB9 ;  /* TIMER 0 PRIORITY */
sbit PX0 =        0xB8 ;  /* EXTERNAL INTERRUPT 0 PRIORITY */

/* SMB0CN 0xC0 */
sbit MASTER =     0xC7 ;  /* SMBUS 0 MASTER/SLAVE */
sbit TXMODE =     0xC6 ;  /* SMBUS 0 TRANSMIT MODE */
sbit STA  =       0xC5 ;  /* SMBUS 0 START FLAG */
sbit STO =        0xC4 ;  /* SMBUS 0 STOP FLAG */
sbit ACKRQ =      0xC3 ;  /* SMBUS 0 ACKNOWLEDGE REQUEST */
sbit ARBLOST =    0xC2 ;  /* SMBUS 0 ARBITRATION LOST */
sbit ACK =        0xC1 ;  /* SMBUS 0 ACKNOWLEDGE FLAG */
sbit SI =         0xC0 ;  /* SMBUS 0 INTERRUPT PENDING FLAG */

/* TMR2CN 0xC8 */
sbit TF2H =       0xCF ;  /* TIMER 2 HIGH BYTE OVERFLOW FLAG */
sbit TF2L =       0xCE ;  /* TIMER 2 LOW BYTE OVERFLOW FLAG */
sbit TF2LEN =     0xCD ;  /* TIMER 2 LOW BYTE INTERRUPT ENABLE */
sbit TF2CEN =     0xCC ;  /* TIMER 2 LFO CAPTURE ENABLE */
sbit T2SPLIT =    0xCB ;  /* TIMER 2 SPLIT MODE ENABLE */
sbit TR2 =        0xCA ;  /* TIMER 2 ON/OFF CONTROL */
sbit T2XCLK =     0xC8 ;  /* TIMER 2 EXTERNAL CLOCK SELECT */

/* PSW 0xD0 */
sbit CY =         0xD7 ;  /* CARRY FLAG */
sbit AC =         0xD6 ;  /* AUXILIARY CARRY FLAG */
sbit F0 =         0xD5 ;  /* USER FLAG 0 */
sbit RS1 =        0xD4 ;  /* REGISTER BANK SELECT 1 */
sbit RS0 =        0xD3 ;  /* REGISTER BANK SELECT 0 */
sbit OV =         0xD2 ;  /* OVERFLOW FLAG */
sbit F1 =         0xD1 ;  /* USER FLAG 1 */
sbit P =          0xD0 ;  /* ACCUMULATOR PARITY FLAG */

/* PCA0CN 0xD8 */
sbit CF =         0xDF ;  /* PCA 0 COUNTER OVERFLOW FLAG */
sbit CR =         0xDE ;  /* PCA 0 COUNTER RUN CONTROL BIT */
sbit CCF2 =       0xDA ;  /* PCA 0 MODULE 2 INTERRUPT FLAG */
sbit CCF1 =       0xD9 ;  /* PCA 0 MODULE 1 INTERRUPT FLAG */
sbit CCF0 =       0xD8 ;  /* PCA 0 MODULE 0 INTERRUPT FLAG */
                          /* ADC 0 WINDOW INTERRUPT FLAG */
/* ADC0CN 0xE8 */
sbit AD0EN  =     0xEF ;  /* ADC 0 ENABLE */
sbit AD0TM =      0xEE ;  /* ADC 0 TRACK MODE */
sbit AD0INT =     0xED ;  /* ADC 0 EOC INTERRUPT FLAG */
sbit AD0BUSY =    0xEC ;  /* ADC 0 BUSY FLAG */
sbit AD0WINT =    0xEB ;  /* ADC 0 WINDOW INTERRUPT FLAG */
sbit AD0CM2 =     0xEA ;  /* ADC 0 CONVERT START MODE BIT 2 */
sbit AD0CM1   =   0xE9 ;  /* ADC 0 CONVERT START MODE BIT 1 */
sbit AD0CM0 =     0xE8 ;  /* ADC 0 CONVERT START MODE BIT 0 */

/* SPI0CN 0xF8 */
sbit SPIF =       0xFF ;  /* SPI 0 INTERRUPT FLAG */
sbit WCOL =       0xFE ;  /* SPI 0 WRITE COLLISION FLAG */
sbit MODF =       0xFD ;  /* SPI 0 MODE FAULT FLAG */
sbit RXOVRN =     0xFC ;  /* SPI 0 RX OVERRUN FLAG */
sbit NSSMD1 =     0xFB ;  /* SPI 0 SLAVE SELECT MODE 1 */
sbit NSSMD0 =     0xFA ;  /* SPI 0 SLAVE SELECT MODE 0 */
sbit TXBMT =      0xF9 ;  /* SPI 0 TX BUFFER EMPTY FLAG */
sbit SPIEN =      0xF8 ;  /* SPI 0 SPI ENABLE */


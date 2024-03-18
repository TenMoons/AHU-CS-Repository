/*--------------------------------------------------------------------------
VERSAMIX.H

Header file for GOAL Semiconductor Versa MIX
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __VERSAMIX_H__
#define __VERSAMIX_H__

/*  BYTE Registers  */
sfr P0               = 0x80;
sfr SP               = 0x81;
sfr DPL0             = 0x82;
sfr DPH0             = 0x83;
sfr DPL1             = 0x84;
sfr DPH1             = 0x85;
sfr DPS              = 0x86;
sfr PCON             = 0x87;
sfr TCON             = 0x88;
sfr TMOD             = 0x89;
sfr TL0              = 0x8A;
sfr TL1              = 0x8B;
sfr TH0              = 0x8C;
sfr TH1              = 0x8D;
sfr CKCON            = 0x8E;
sfr P1               = 0x90;
sfr IRCON            = 0x91;
sfr ANALOGPWREN      = 0x92;
sfr DIGPWREN         = 0x93;
sfr CLKDIVCTRL       = 0x94;
sfr ADCCLKDIV        = 0x95;
sfr S0RELL           = 0x96;
sfr S0RELH           = 0x97;
sfr S0CON            = 0x98;
sfr S0BUF            = 0x99;
sfr IEN2             = 0x9A;
sfr P0PINCFG         = 0x9B;
sfr P2PINCFG         = 0x9D;
sfr P3PINCFG         = 0x9E;
sfr PORTIRQEN        = 0x9F;
sfr P2               = 0xA0;
sfr PORTIRQSTAT      = 0xA1;
sfr ADCCTRL          = 0xA2;
sfr ADCCONVRLOW      = 0xA3;
sfr ADCCONVRMED      = 0xA4;
sfr ADCCONVRHIGH     = 0xA5;
sfr ADCD0LO          = 0xA6;
sfr ADCD0HI          = 0xA7;
sfr IEN0             = 0xA8;
sfr ADCD1LO          = 0xA9;
sfr ADCD1HI          = 0xAA;
sfr ADCD2LO          = 0xAB;
sfr ADCD2HI          = 0xAC;
sfr ADCD3LO          = 0xAD;
sfr ADCD3HI          = 0xAE;
sfr P3               = 0xB0;
sfr ADCFORCE         = 0xB1;
sfr ADCALTBL         = 0xB2;
sfr BGAPCAL          = 0xB3;
sfr PGACAL           = 0xB4;
sfr INMUXCTRL        = 0xB5;
sfr OUTMUXCTRL       = 0xB6;
sfr SWITCHCTRL       = 0xB7;
sfr IP0              = 0xB8;
sfr IP1              = 0xB9;
sfr DIGPOT1          = 0xBA;
sfr DIGPOT2          = 0xBB;
sfr ISRCCAL1         = 0xBC;
sfr ISRCCAL2         = 0xBD;
sfr S1RELL           = 0xBE;
sfr S1RELH           = 0xBF;
sfr S1CON            = 0xC0;
sfr S1BUF            = 0xC1;
sfr CCL1             = 0xC2;
sfr CCH1             = 0xC3;
sfr CCL2             = 0xC4;
sfr CCH2             = 0xC5;
sfr CCL3             = 0xC6;
sfr CCH3             = 0xC7;
sfr T2CON            = 0xC8;
sfr CCEN             = 0xC9;
sfr CRCL             = 0xCA;
sfr CRCH             = 0xCB;
sfr TL2              = 0xCC;
sfr TH2              = 0xCD;
sfr MPAGE            = 0xCF;
sfr PSW              = 0xD0;
sfr BREAKP0L         = 0xD1;
sfr BREAKP0H         = 0xD2;
sfr BREAKP1L         = 0xD3;
sfr BREAKP1H         = 0xD4;
sfr BREAKPCTRL       = 0xD5;
sfr DEBUGCTRL        = 0xD6;
sfr DEBUGSTATUS      = 0xD7;
sfr WDCON            = 0xD8;
sfr WDTREL           = 0xD9;
sfr I2CCONFIG        = 0xDA;
sfr I2CCLKCTRL       = 0xDB;
sfr I2CCHIPID        = 0xDC;
sfr I2CIRQSTAT       = 0xDD;
sfr I2CRXTX          = 0xDE;
sfr ACC              = 0xE0;
sfr SPIRXTX0         = 0xE1;
sfr SPIRXTX1         = 0xE2;
sfr SPIRXTX2         = 0xE3;
sfr SPIRXTX3         = 0xE4;
sfr SPICTRL1         = 0xE5;
sfr SPICTRL2         = 0xE6;
sfr SPISIZECTRL      = 0xE7;
sfr IEN1             = 0xE8;
sfr SPIIRQSTAT       = 0xE9;
sfr MACCTRL          = 0xEB;
sfr MACC0            = 0xEC;
sfr MACC1            = 0xED;
sfr MACC2            = 0xEE;
sfr MACC3            = 0xEF;
sfr B                = 0xF0;
sfr MACCTRL2         = 0xF1;
sfr MACA0            = 0xF2;
sfr MACA1            = 0xF3;
sfr MACRES0          = 0xF4;
sfr MACRES1          = 0xF5;
sfr MACRES2          = 0xF6;
sfr MACRES3          = 0xF7;
sfr USERFLAGS        = 0xF8;
sfr MACB0            = 0xF9;
sfr MACB1            = 0xFA;
sfr MACSHIFTCTRL     = 0xFB;
sfr MACPREV0         = 0xFC;
sfr MACPREV1         = 0xFD;
sfr MACPREV2         = 0xFE;
sfr MACPREV3         = 0xFF;

/*  BIT Registers  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit P     = PSW^0; 

/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  IE  */
sbit EA    = IEN1^7;
sbit ET2   = IEN1^5; 
sbit ES    = IEN1^4;
sbit ET1   = IEN1^3;
sbit EX1   = IEN1^2;
sbit ET0   = IEN1^1;
sbit EX0   = IEN1^0;

/*  IP  */
sbit PT2   = IP0^5;
sbit PS    = IP0^4;
sbit PT1   = IP0^3;
sbit PX1   = IP0^2;
sbit PT0   = IP0^1;
sbit PX0   = IP0^0;

/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;
#endif

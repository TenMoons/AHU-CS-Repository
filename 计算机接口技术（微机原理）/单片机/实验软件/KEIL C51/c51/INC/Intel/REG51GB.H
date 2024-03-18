/*--------------------------------------------------------------------------
REG51GB.H

Header file for 80C51GB.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG51GB_H__
#define __REG51GB_H__

/*  BYTE Registers  */
sfr P0    = 0x80;
sfr P1    = 0x90;
sfr P2    = 0xA0;
sfr P3    = 0xB0;
sfr PSW   = 0xD0;
sfr ACC   = 0xE0;
sfr B     = 0xF0;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr PCON  = 0x87;
sfr TCON  = 0x88;
sfr TMOD  = 0x89;
sfr TL0   = 0x8A;
sfr TL1   = 0x8B;
sfr TH0   = 0x8C;
sfr TH1   = 0x8D;
sfr IE    = 0xA8;
sfr IP    = 0xB8;
sfr SCON  = 0x98;
sfr SBUF  = 0x99;

/*  80C51GB Specific Extensions  */
sfr SADDR  = 0xA9;
sfr SADEN  = 0xB9;
sfr T2CON  = 0xC8;
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;
sfr P4     = 0xC0;
sfr ADRES0 = 0x84;
sfr ADRES1 = 0x94;
sfr ADRES2 = 0xA4;
sfr ADRES3 = 0xB4;
sfr ADRES4 = 0xC4;
sfr ADRES5 = 0xD4;
sfr ADRES6 = 0xE4;
sfr ADRES7 = 0xF4;
sfr AUXR   = 0x8E;
sfr OFDCON = 0xA5;
sfr IPA1   = 0xB5;
sfr WDTCON = 0xA6;
sfr IPA    = 0xB6;
sfr EXICON = 0xC6;
sfr ADCON  = 0x97;
sfr IEA    = 0xA7;
sfr IP1    = 0xB7;
sfr ACMP   = 0xC7;
sfr SEPCON = 0xD7;
sfr SEPDAT = 0xE7;
sfr SEPSTA = 0xF7;
sfr P5     = 0xF8;

/******** PCA0 SFRS *******/
sfr CCON   = 0xD8;
sfr CMOD   = 0xD9;
sfr CCAPM0 = 0xDA;
sfr CCAPM1 = 0xDB;
sfr CCAPM2 = 0xDC;
sfr CCAPM3 = 0xDD;
sfr CCAPM4 = 0xDE;
sfr CL     = 0xE9;
sfr CCAP0L = 0xEA;
sfr CCAP1L = 0xEB;
sfr CCAP2L = 0xEC;
sfr CCAP3L = 0xED;
sfr CCAP4L = 0xEE;
sfr CH     = 0xF9;
sfr CCAP0H = 0xFA;
sfr CCAP1H = 0xFB;
sfr CCAP2H = 0xFC;
sfr CCAP3H = 0xFD;
sfr CCAP4H = 0xFE;

/******** PCA1 SFRS *******/
sfr C1CON   = 0xE8;
sfr C1MOD   = 0x9F;
sfr C1CAPM0 = 0x9A;
sfr C1CAPM1 = 0x9B;
sfr C1CAPM2 = 0x9C;
sfr C1CAPM3 = 0x9D;
sfr C1CAPM4 = 0x9E;
sfr CL1     = 0xAF;
sfr C1CAP0L = 0xAA;
sfr C1CAP1L = 0xAB;
sfr C1CAP2L = 0xAC;
sfr C1CAP3L = 0xAD;
sfr C1CAP4L = 0xAE;
sfr CH1     = 0xBF;
sfr C1CAP0H = 0xBA;
sfr C1CAP1H = 0xBB;
sfr C1CAP2H = 0xBC;
sfr C1CAP3H = 0xBD;
sfr C1CAP4H = 0xBE;

/*  SFR BIT Registers  */
/*  PSW  */
sbit CY    = 0xD7;
sbit AC    = 0xD6;
sbit F0    = 0xD5;
sbit RS1   = 0xD4;
sbit RS0   = 0xD3;
sbit OV    = 0xD2;
sbit P     = 0xD0;

/*  TCON  */
sbit TF1   = 0x8F;
sbit TR1   = 0x8E;
sbit TF0   = 0x8D;
sbit TR0   = 0x8C;
sbit IE1   = 0x8B;
sbit IT1   = 0x8A;
sbit IE0   = 0x89;
sbit IT0   = 0x88;

/*  IE  */
sbit EA    = 0xAF;
sbit EC    = 0xAE;
sbit ET2   = 0xAD;
sbit ES    = 0xAC;
sbit ET1   = 0xAB;
sbit EX1   = 0xAA;
sbit ET0   = 0xA9;
sbit EX0   = 0xA8;

/*  IP  */
sbit PPC   = 0xBE;
sbit PT2   = 0xBD;
sbit PS    = 0xBC;
sbit PT1   = 0xBB;
sbit PX1   = 0xBA;
sbit PT0   = 0xB9;
sbit PX0   = 0xB8;

/********  P1  Bits *******/
sbit CEX4 = 0x97;
sbit CEX3 = 0x96;
sbit CEX2 = 0x95;
sbit CEX1 = 0x94;
sbit CEX0 = 0x93;
sbit ECI  = 0x92;
sbit T2EX = 0x91;
sbit T2   = 0x90;

/********  P3  Bits ********/
sbit RD   = 0xB7;
sbit WR   = 0xB6;
sbit T1   = 0xB5;
sbit T0   = 0xB4;
sbit INT1 = 0xB3;
sbit INT0 = 0xB2;
sbit TXD  = 0xB1;
sbit RXD  = 0xB0;

/********  P4  BITS *******/
sbit C1EX4  = 0xC7;
sbit C1EX3  = 0xC6;
sbit C1EX2  = 0xC5;
sbit C1EX1  = 0xC4;
sbit C1EX0  = 0xC3;
sbit C1     = 0xC2;
sbit SEPIO  = 0xC1;
sbit SEPCLK = 0xC0;

/********  P5  BITS *******/
sbit INT6   = 0xFE;
sbit INT5   = 0xFD;
sbit INT4   = 0xFC;
sbit INT3   = 0xFB;
sbit INT2   = 0xFA;

/********  SCON  Bits  ********/
sbit SM0   = 0x9F;
sbit SM1   = 0x9E;
sbit SM2   = 0x9D;
sbit REN   = 0x9C;
sbit TB8   = 0x9B;
sbit RB8   = 0x9A;
sbit TI    = 0x99;
sbit RI    = 0x98;

/******** T2CON BITS *******/
sbit TF2   = 0xCF; 
sbit EXF2  = 0xCE;
sbit RCLK  = 0xCD;
sbit TCLK  = 0xCC;
sbit EXEN2 = 0xCB;
sbit TR2   = 0xCA;
sbit CT2   = 0xC9;
sbit CPRL2 = 0xC8;

/******** CCON BITS *******/
sbit CF    = 0xDF;
sbit CR    = 0xDE;
sbit CCF4  = 0xDC;
sbit CCF3  = 0xDB;
sbit CCF2  = 0xDA;
sbit CCF1  = 0xD9;
sbit CCF0  = 0xD8;

/******** CCON1 BITS *******/
sbit CF1    = 0xEF;
sbit CR1    = 0xEE;
sbit CRE    = 0xED;
sbit C1CF4  = 0xEC;
sbit C1CF3  = 0xEB;
sbit C1CF2  = 0xEA;
sbit C1CF1  = 0xE9;
sbit C1CF0  = 0xE8;

#endif

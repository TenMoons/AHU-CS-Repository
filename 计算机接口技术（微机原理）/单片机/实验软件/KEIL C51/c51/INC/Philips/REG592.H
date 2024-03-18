/*--------------------------------------------------------------------------
REG592.H

Header file for 80592.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG592_H__
#define __REG592_H__

/*  BYTE Registers  */
sfr P0    = 0x80;
sfr P1    = 0x90;
sfr P2    = 0xA0;
sfr P3    = 0xB0;
sfr P4    = 0xC0;
sfr P5    = 0xC4;

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
sfr IEN0  = 0xA8;
sfr IEN1  = 0xE8;
sfr IP0   = 0xB8;
sfr IP1   = 0xF8;
sfr S0CON = 0x98;
sfr S0BUF = 0x99;
sfr CML0  = 0xA9;
sfr CML1  = 0xAA;
sfr CML2  = 0xAB;
sfr CTL0  = 0xAC;
sfr CTL1  = 0xAD;
sfr CTL2  = 0xAE;
sfr CTL3  = 0xAF;
sfr ADCON = 0xC5;
sfr ADCH  = 0xC6;
sfr TM2IR = 0xC8;
sfr CMH0  = 0xC9;
sfr CMH1  = 0xCA;
sfr CMH2  = 0xCB;
sfr CTH0  = 0xCC;
sfr CTH1  = 0xCD;
sfr CTH2  = 0xCE;
sfr CTH3  = 0xCF;

sfr CANSTA= 0xD8;
sfr CANCON= 0xD9;
sfr CANDAT= 0xDA;
sfr CANADR= 0xDB;

sfr TM2CON= 0xEA;
sfr CTCON = 0xEB;
sfr TML2  = 0xEC;
sfr TMH2  = 0xED;
sfr STE   = 0xEE;
sfr RTE   = 0xEF;
sfr PWM0  = 0xFC;
sfr PWM1  = 0xFD;
sfr PWMP  = 0xFE;
sfr T3    = 0xFF;

/*  BIT Registers  */
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

/*  IEN0  */
sbit EA    = 0xAF;
sbit EAD   = 0xAE;
sbit ES1   = 0xAD;
sbit ES0   = 0xAC;
sbit ET1   = 0xAB;
sbit EX1   = 0xAA;
sbit ET0   = 0xA9;
sbit EX0   = 0xA8;

/*  IEN1  */
sbit ET2   = 0xEF;
sbit ECM2  = 0xEE;
sbit ECM1  = 0xED;
sbit ECM0  = 0xEC;
sbit ECT3  = 0xEB;
sbit ECT2  = 0xEA;
sbit ECT1  = 0xE9;
sbit ECT0  = 0xE8;

/*  IP0  */
sbit PAD   = 0xBE;
sbit PS1   = 0xBD;
sbit PS0   = 0xBC;
sbit PT1   = 0xBB;
sbit PX1   = 0xBA;
sbit PT0   = 0xB9;
sbit PX0   = 0xB8;

/*  IP1  */
sbit PT2   = 0xFF;
sbit PCM2  = 0xFE;
sbit PCM1  = 0xFD;
sbit PCM0  = 0xFC;
sbit PCT3  = 0xFB;
sbit PCT2  = 0xFA;
sbit PCT1  = 0xF9;
sbit PCT0  = 0xF8;

/*  P1  */
sbit CTX1  = 0x97;
sbit CTX0  = 0x96;
sbit RT2   = 0x95;
sbit T2    = 0x94;
sbit INT5  = 0x93;
sbit INT4  = 0x92;
sbit INT3  = 0x91;
sbit INT2  = 0x90;
sbit CT3I  = 0x93;
sbit CT2I  = 0x92;
sbit CT1I  = 0x91;
sbit CT0I  = 0x90;
             
/*  P3  */
sbit RD    = 0xB7;
sbit WR    = 0xB6;
sbit T1    = 0xB5;
sbit T0    = 0xB4;
sbit INT1  = 0xB3;
sbit INT0  = 0xB2;
sbit TXD   = 0xB1;
sbit RXD   = 0xB0;

/*  P4  */
sbit CMT1  = 0xC7;
sbit CMT0  = 0xC6;
sbit CMSR5 = 0xC5;
sbit CMSR4 = 0xC4;
sbit CMSR3 = 0xC3;
sbit CMSR2 = 0xC2;
sbit CMSR1 = 0xC1;
sbit CMSR0 = 0xC0;

/*  S0CON  */
sbit SM0   = 0x9F;
sbit SM1   = 0x9E;
sbit SM2   = 0x9D;
sbit REN   = 0x9C;
sbit TB8   = 0x9B;
sbit RB8   = 0x9A;
sbit TI    = 0x99;
sbit RI    = 0x98;

/*  TM2IR  */
sbit T20V  = 0xCF;
sbit CMI2  = 0xCE;
sbit CMI1  = 0xCD;
sbit CMI0  = 0xCC;
sbit CTI3  = 0xCB;
sbit CTI2  = 0xCA;
sbit CTI1  = 0xC9;
sbit CTI0  = 0xC8;

/*  CANSTA  */
sbit RAMA7 = 0xDF;
sbit RAMA6 = 0xDE;
sbit RAMA5 = 0xDD;
sbit RAMA4 = 0xDC;
sbit RAMA3 = 0xDB;
sbit RAMA2 = 0xDA;
sbit RAMA1 = 0xD9;
sbit RAMA0 = 0xD8;

#endif

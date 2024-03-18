/*--------------------------------------------------------------------------
REG504.H

Header file for the C504 Processor.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG504_H__
#define __REG504_H__


/*  BYTE Register  */
sfr   P0     = 0x80; /* Bit-addressable SFR */
sfr   SP     = 0x81;
sfr   DPL    = 0x82;
sfr   DPH    = 0x83;
sfr   WDTREL = 0x86;
sfr   PCON   = 0x87;
sfr   TCON   = 0x88; /* Bit-addressable SFR */
sfr   PCON1  = 0x88; /* Bit-addressable SFR, in mapped SFR area */
sfr   TMOD   = 0x89;
sfr   TL0    = 0x8A;
sfr   TL1    = 0x8B;
sfr   TH0    = 0x8C;
sfr   TH1    = 0x8D;

sfr   P1     = 0x90; /* Bit-addressable SFR */
sfr   P1ANA  = 0x90; /* Bit-addressable SFR, in mapped SFR area */
sfr   SCON   = 0x98; /* Bit-addressable SFR */
sfr   SBUF   = 0x99;
sfr   ITCON  = 0x9A;

sfr   P2     = 0xA0; /* Bit-addressable SFR */
sfr   IEN0   = 0xA8; /* Bit-addressable SFR */
sfr   IEN1   = 0xA9;
sfr   SRELL  = 0xAA;

sfr   P3     = 0xB0; /* Bit-addressable SFR */
sfr   P3ANA  = 0xB0; /* Bit-addressable SFR, in mapped SFR area */
sfr   SYSCON = 0xB1;
sfr   IP0    = 0xB8; /* Bit-addressable SFR */
sfr   IP1    = 0xB9;

sfr   WDCON  = 0xC0; /* Bit-addressable SFR */
sfr   CT2CON = 0xC1;
sfr   CCL0   = 0xC2;
sfr   CCH0   = 0xC3;
sfr   CCL1   = 0xC4;
sfr   CCH1   = 0xC5;
sfr   CCL2   = 0xC6;
sfr   CCH2   = 0xC7;
sfr   T2CON  = 0xC8; /* Bit-addressable SFR */
sfr   T2MOD  = 0xC9;
sfr   RC2L   = 0xCA;
sfr   RC2H   = 0xCB;
sfr   TL2    = 0xCC;
sfr   TH2    = 0xCD;
sfr   TRCON  = 0xCF;

sfr   PSW    = 0xD0; /* Bit-addressable SFR */
sfr   CP2L   = 0xD2;
sfr   CP2H   = 0xD3;
sfr   CMP2l  = 0xD4;
sfr   CMP2H  = 0xD5;
sfr   CCIE   = 0xD6;
sfr   BCON   = 0xD7;
sfr   ADCON0 = 0xD8; /* Bit-addressable SFR */
sfr   ADDATH = 0xD9;
sfr   ADDATL = 0xDA;
sfr   ADCON1 = 0xDC;
sfr   CCPL   = 0xDE;
sfr   CCPH   = 0xDF;

sfr   ACC    = 0xE0; /* Bit-addressable SFR */
sfr   CT1CON = 0xE1;
sfr   COINI  = 0xE2;
sfr   CMSEL0 = 0xE3;
sfr   CMSEL1 = 0xE4;
sfr   CCIR   = 0xE5;
sfr   CT1OFL = 0xE6;
sfr   CT1OFH = 0xE7;
sfr   B      = 0xF0; /* Bit-addressable SFR */

/* 16-Bit SFR's for CC?? registers */

sfr16 CC0    = 0xC2;
sfr16 CC1    = 0xC4;
sfr16 CC2    = 0xC6;
sfr16 RC2    = 0xCA;
sfr16 T2     = 0xCC;

/*******************************************/

/* BIT-addressable registers */
/* TCON */
sbit  TF1   = 0x8F;
sbit  TR1   = 0x8E;
sbit  TF0   = 0x8D;
sbit  TR0   = 0x8C;
sbit  IE1   = 0x8B;
sbit  IT1   = 0x8A;
sbit  IE0   = 0x89;
sbit  IT0   = 0x88;
sbit  EWPD  = 0x88; /* in mapped SFR area */
/* SCON */
sbit  SM0   = 0x9F;
sbit  SM1   = 0x9E;
sbit  SM2   = 0x9D;
sbit  REN   = 0x9C;
sbit  TB8   = 0x9B;
sbit  RB8   = 0x9A;
sbit  TI    = 0x99;
sbit  RI    = 0x98;
/* P1, P1ANA */
sbit  EAN3  = 0x93; /* in mapped SFR area */
sbit  EAN2  = 0x92; /* in mapped SFR area */
sbit  EAN1  = 0x91; /* in mapped SFR area */
sbit  T2EX  = 0x91;
sbit  EAN0  = 0x90; /* in mapped SFR area */
sbit  _T2   = 0x90; /* T2 (Timer#2)defined as 16 Bit SFR */
/* IEN0 */
sbit  EA    = 0xAF;
sbit  ET2   = 0xAD;
sbit  ES    = 0xAC;
sbit  ET1   = 0xAB;
sbit  EX1   = 0xAA;
sbit  ET0   = 0xA9;
sbit  EX0   = 0xA8;
/* IP0 */
sbit  PT2   = 0xBD;
sbit  PS    = 0xBC;
sbit  PT1   = 0xBB;
sbit  PX1   = 0xBA;
sbit  PT0   = 0xB9;
sbit  PX0   = 0xB8;
/* P3, P3ANA */
sbit  RD    = 0xB7;
sbit  WR    = 0xB6;
sbit  T1    = 0xB5;
sbit  EAN7  = 0xB5; /* in mapped SFR area */
sbit  T0    = 0xB4;
sbit  EAN6  = 0xB4; /* in mapped SFR area */
sbit  INT1  = 0xB3;
sbit  EAN5  = 0xB3; /* in mapped SFR area */
sbit  INT0  = 0xB2;
sbit  EAN4  = 0xB2; /* in mapped SFR area */
sbit  TXD   = 0xB1;
sbit  RXD   = 0xB0;
/* T2CON */
sbit  TF2   = 0xCF;
sbit  EXF2  = 0xCE;
sbit  RCLK  = 0xCD;
sbit  TCLK  = 0xCC;
sbit  EXEN2 = 0xCB;
sbit  TR2   = 0xCA;
sbit  C     = 0xC9; /* also /T2 */
sbit  CP    = 0xC8; /* also /RL2 */
/* WDCON */
sbit  OWDS  = 0xC3;
sbit  WDTS  = 0xC2;
sbit  WDT   = 0xC1;
sbit  SWDT  = 0xC0;
/* ADCON0 */
sbit  IADC  = 0xDD;
sbit  BSY   = 0xDC;
sbit  ADM   = 0xDB;
sbit  MX2   = 0xDA;
sbit  MX1   = 0xD9;
sbit  MX0   = 0xD8;
/* PSW */
sbit  CY    = 0xD7;
sbit  AC    = 0xD6;
sbit  F0    = 0xD5;
sbit  RS1   = 0xD4;
sbit  RS0   = 0xD3;
sbit  OV    = 0xD2;
sbit  F1    = 0xD1;
sbit  P     = 0xD0;

#endif


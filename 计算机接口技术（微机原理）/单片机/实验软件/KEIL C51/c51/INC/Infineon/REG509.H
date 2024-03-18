/*--------------------------------------------------------------------------
REG509.H

Header file for C509.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG509_H__
#define __REG509_H__

/*  BYTE Register  */
sfr   P0     = 0x80;
sfr   DIR0   = 0x80;
sfr   SP     = 0x81;
sfr   DPL    = 0x82;
sfr   DPH    = 0x83;
sfr   WDTREL = 0x86;
sfr   PCON   = 0x87;
sfr   TCON   = 0x88;
sfr   TMOD   = 0x89;
sfr   TL0    = 0x8A;
sfr   TL1    = 0x8B;
sfr   TH0    = 0x8C;
sfr   TH1    = 0x8D;

sfr   P1     = 0x90;
sfr   DIR1   = 0x90;
sfr   XPAGE  = 0x91;
sfr   DPSEL  = 0x92;
sfr   S0CON  = 0x98;
sfr   S0BUF  = 0x99;
sfr   IEN2   = 0x9A;
sfr   S1CON  = 0x9B;
sfr   S1BUF  = 0x9C;
sfr   S1RELL = 0x9D;

sfr   P2     = 0xA0;
sfr   DIR2   = 0xA0;
sfr   COMSETL= 0xA1;
sfr   COMSETH= 0xA2;
sfr   COMCLRL= 0xA3;
sfr   COMCLRH= 0xA4;
sfr   SETMSK = 0xA5;
sfr   CLRMSK = 0xA6;

sfr   IEN0   = 0xA8;
sfr   IP0    = 0xA9;
sfr   S0RELL = 0xAA;

sfr   P3     = 0xB0;
sfr   DIR3   = 0xB0;
sfr   SYSCON = 0xB1;
sfr   SYSCON1= 0xB2;
sfr   FMODE  = 0xB3;
sfr   PRSC   = 0xB4;

sfr   IEN1   = 0xB8;
sfr   IP1    = 0xB9;
sfr   S0RELH = 0xBA;
sfr   S1RELH = 0xBB;
sfr   CT1CON = 0xBC;
sfr   IEN3   = 0xBE;
sfr   IRCON2 = 0xBF;
sfr   EICC1  = 0xBF;

sfr   IRCON  = 0xC0;
sfr   CCEN   = 0xC1;
sfr   CCL1   = 0xC2;
sfr   CCH1   = 0xC3;
sfr   CCL2   = 0xC4;
sfr   CCH2   = 0xC5;
sfr   CCL3   = 0xC6;
sfr   CCH3   = 0xC7;
sfr   T2CON  = 0xC8;
sfr   CC4EN  = 0xC9;
sfr   CRCL   = 0xCA;
sfr   CRCH   = 0xCB;
sfr   TL2    = 0xCC;
sfr   TH2    = 0xCD;
sfr   CCL4   = 0xCE;
sfr   CCH4   = 0xCF;

/* 16-Bit SFR's for CC?? registers */

sfr16 CC1    = 0xC2;
sfr16 CC2    = 0xC4;
sfr16 CC3    = 0xC6;
sfr16 CRC    = 0xCA;
sfr16 T2     = 0xCC;
sfr16 CC4    = 0xCE;

sfr   PSW    = 0xD0;
sfr   IRCON1 = 0xD1;
sfr   CML0   = 0xD2;
sfr   CC1L0  = 0xD2;
sfr   CMH0   = 0xD3;
sfr   CC1H0  = 0xD3;
sfr16 CM0    = 0xD2;
sfr   CML1   = 0xD4;
sfr   CC1L1  = 0xD4;
sfr   CMH1   = 0xD5;
sfr   CC1H1  = 0xD5;
sfr16 CM1    = 0xD4;
sfr   CML2   = 0xD6;
sfr   CC1L2  = 0xD6;
sfr   CMH2   = 0xD7;
sfr   CC1H2  = 0xD7;
sfr16 CM2    = 0xD6;

sfr   ADCON0 = 0xD8;
sfr   ADDATH = 0xD9;
sfr   ADDATL = 0xDA;
sfr   P7     = 0xDB;
sfr   ADCON1 = 0xDC;
sfr   P8     = 0xDD;
sfr   CTRELL = 0xDE;
sfr   CT1RELL= 0xDE;
sfr   CTRELH = 0xDF;
sfr   CT1RELH= 0xDF;
sfr16 CTREL  = 0xDE;

sfr   ACC    = 0xE0;
sfr   CTCON  = 0xE1;
sfr   CML3   = 0xE2;
sfr   CC1L3  = 0xE2;
sfr   CMH3   = 0xE3;
sfr   CC1H3  = 0xE3;
sfr16 CM3    = 0xE2;
sfr   CML4   = 0xE4;
sfr   CC1L4  = 0xE4;
sfr   CMH4   = 0xE5;
sfr   CC1H4  = 0xE5;
sfr16 CM4    = 0xE4;
sfr   CML5   = 0xE6;
sfr   CC1L5  = 0xE6;
sfr   CMH5   = 0xE7;
sfr   CC1H5  = 0xE7;
sfr16 CM5    = 0xE6;

sfr   P4     = 0xE8;
sfr   DIR4   = 0xE8;
sfr   MD0    = 0xE9;
sfr   MD1    = 0xEA;
sfr   MD2    = 0xEB;
sfr   MD3    = 0xEC;
sfr   MD4    = 0xED;
sfr   MD5    = 0xEE;
sfr   ARCON  = 0xEF;

sfr   B      = 0xF0;
sfr   CML6   = 0xF2;
sfr   CC1L6  = 0xF2;
sfr   CMH6   = 0xF3;
sfr   CC1H6  = 0xF3;
sfr16 CM6    = 0xF2;
sfr   CML7   = 0xF4;
sfr   CC1L7  = 0xF4;
sfr   CMH7   = 0xF5;
sfr   CC1H7  = 0xF5;
sfr16 CM7    = 0xF4;
sfr   CMEN   = 0xF6;
sfr   CC1EN  = 0xF6;
sfr   CMSEL  = 0xF7;
sfr   CAFR   = 0xF7;

sfr   P5     = 0xF8;
sfr   DIR5   = 0xF8;
sfr   P9     = 0xF9;
sfr   DIR9   = 0xF9;
sfr   P6     = 0xFA;
sfr   DIR6   = 0xFA;


/* BIT Register */

/* PSW */
sbit  CY     = 0xD7;
sbit  AC     = 0xD6;
sbit  F0     = 0xD5;
sbit  RS1    = 0xD4;
sbit  RS0    = 0xD3;
sbit  OV     = 0xD2;
sbit  F1     = 0xD1;
sbit  P      = 0xD0;
/* TCON */
sbit  TF1    = 0x8F;
sbit  TR1    = 0x8E;
sbit  TF0    = 0x8D;
sbit  TR0    = 0x8C;
sbit  IE1    = 0x8B;
sbit  IT1    = 0x8A;
sbit  IE0    = 0x89;
sbit  IT0    = 0x88;
/* IEN0 */
sbit  EAL    = 0xAF;
sbit  WDT    = 0xAE;
sbit  ET2    = 0xAD;
sbit  ES0    = 0xAC;
sbit  ET1    = 0xAB;
sbit  EX1    = 0xAA;
sbit  ET0    = 0xA9;
sbit  EX0    = 0xA8;
/* IEN1 */
sbit  EXEN2  = 0xBF;
sbit  SWDT   = 0xBE;
sbit  EX6    = 0xBD;
sbit  EX5    = 0xBC;
sbit  EX4    = 0xBB;
sbit  EX3    = 0xBA;
sbit  EX2    = 0xB9;
sbit  EADC   = 0xB8;
/* P3 */
sbit  RD     = 0xB7;
sbit  WR     = 0xB6;
sbit  T1     = 0xB5;
sbit  T0     = 0xB4;
sbit  INT1   = 0xB3;
sbit  INT0   = 0xB2;
sbit  TXD    = 0xB1;
sbit  RXD    = 0xB0;
/* S0CON */
sbit  SM0    = 0x9F;
sbit  SM1    = 0x9E;
sbit  SM20   = 0x9D;
sbit  REN0   = 0x9C;
sbit  TB80   = 0x9B;
sbit  RB80   = 0x9A;
sbit  TI0    = 0x99;
sbit  RI0    = 0x98;
/* T2CON */
sbit  T2PS   = 0xCF;
sbit  I3FR   = 0xCE;
sbit  I2FR   = 0xCD;
sbit  T2R1   = 0xCC;
sbit  T2R0   = 0xCB;
sbit  T2CM   = 0xCA;
sbit  T2I1   = 0xC9;
sbit  T2I0   = 0xC8;
/* ADCON */
sbit  BD     = 0xDF;
sbit  CLK    = 0xDE;
sbit  ADEX   = 0xDD;
sbit  BSY    = 0xDC;
sbit  ADM    = 0xDB;
sbit  MX2    = 0xDA;
sbit  MX1    = 0xD9;
sbit  MX0    = 0xD8;
/* IRCON */
sbit  EXF2   = 0xC7;
sbit  TF2    = 0xC6;
sbit  IEX6   = 0xC5;
sbit  IEX5   = 0xC4;
sbit  IEX4   = 0xC3;
sbit  IEX3   = 0xC2;
sbit  IEX2   = 0xC1;
sbit  IADC   = 0xC0;

#endif

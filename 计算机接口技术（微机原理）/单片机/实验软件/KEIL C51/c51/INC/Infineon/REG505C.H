/*--------------------------------------------------------------------------
REG505C.H

Header file for the C505C Processor.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG505C_H__
#define __REG505C_H__

/*  BYTE Register  */
sfr   P0     = 0x80;
sfr   SP     = 0x81;
sfr   DPL    = 0x82;
sfr   DPH    = 0x83;
sfr   WDTREL = 0x86;
sfr   PCON   = 0x87;
sfr   TCON   = 0x88;
sfr   PCON1  = 0x88; /* in mapped SFR area */
sfr   TMOD   = 0x89;
sfr   TL0    = 0x8A;
sfr   TL1    = 0x8B;
sfr   TH0    = 0x8C;
sfr   TH1    = 0x8D;

sfr   P1     = 0x90;
sfr   P1ANA  = 0x90;
sfr   XPAGE  = 0x91;
sfr   DPSEL  = 0x92;
sfr   SCON   = 0x98;
sfr   SBUF   = 0x99;

sfr   P2     = 0xA0;
sfr   IEN0   = 0xA8;
sfr   IP0    = 0xA9;
sfr   SRELL  = 0xAA;

sfr   P3     = 0xB0;
sfr   SYSCON = 0xB1;

sfr   IEN1   = 0xB8;
sfr   IP1    = 0xB9;
sfr   SRELH  = 0xBA;

sfr   IRCON  = 0xC0;
sfr   CCEN   = 0xC1;
sfr   CCL1   = 0xC2;
sfr   CCH1   = 0xC3;
sfr   CCL2   = 0xC4;
sfr   CCH2   = 0xC5;
sfr   CCL3   = 0xC6; /* in C505CA */
sfr   CCH3   = 0xC7; /* in C505CA */

sfr   T2CON  = 0xC8;
sfr   CRCL   = 0xCA;
sfr   CRCH   = 0xCB;
sfr   TL2    = 0xCC;
sfr   TH2    = 0xCD;

sfr   PSW    = 0xD0;
sfr   ADCON0 = 0xD8;
sfr   ADDAT  = 0xD9;
sfr   ADDATH = 0xD9; /* C505CA */
sfr   ADST   = 0xDA;
sfr   ADDATL = 0xDA; /* C505CA */
sfr   ADCON1 = 0xDC;

sfr   ACC    = 0xE0;
sfr   P4     = 0xE8;

sfr   B      = 0xF0;
sfr   VR0    = 0xFC; /* in mapped SFR area */
sfr   VR1    = 0xFD; /* in mapped SFR area */
sfr   VR2    = 0xFE; /* in mapped SFR area */

/* 16-Bit SFR's for CC?? registers */

sfr16 CC1    = 0xC2;
sfr16 CC2    = 0xC4;
sfr16 CC3    = 0xC6; /* in C505CA */
sfr16 CRC    = 0xCA;
/* sfr16 T2     = 0xCC; */

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
/* PCON1 in mapped SFR area*/
sbit  EWPD   = 0x8F;
sbit  WS     = 0x8C;

/* IEN0 */
sbit  EA     = 0xAF;
sbit  WDT    = 0xAE;
sbit  ET2    = 0xAD;
sbit  ES     = 0xAC;
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
sbit  ECAN   = 0xB9;
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

/* SCON */
sbit  SM0    = 0x9F;
sbit  SM1    = 0x9E;
sbit  SM2    = 0x9D;
sbit  REN    = 0x9C;
sbit  TB8    = 0x9B;
sbit  RB8    = 0x9A;
sbit  TI     = 0x99;
sbit  RI     = 0x98;
/* T2CON */
sbit  T2PS   = 0xCF;
sbit  I3FR   = 0xCE;
sbit  T2R1   = 0xCC;
sbit  T2R0   = 0xCB;
sbit  T2CM   = 0xCA;
sbit  T2I1   = 0xC9;
sbit  T2I0   = 0xC8;
/* ADCON0 */
sbit  BD     = 0xDF;
sbit  CLK    = 0xDE;
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
sbit  IADC   = 0xC0;
/* P1 */
sbit  T2     = 0x97; /* use _T2 if "T2" defined as 16 Bit SFR */
sbit  CLKOUT = 0x96;
sbit  T2EX   = 0x95;
sbit  INT5   = 0x92;
sbit  INT4   = 0x91;
/* P1ANA in mapped SFR area */
sbit  EAN7   = 0x97;
sbit  EAN6   = 0x96;
sbit  EAN5   = 0x95;
sbit  EAN4   = 0x94;
sbit  EAN3   = 0x93;
sbit  EAN2   = 0x92;
sbit  EAN1   = 0x91;
sbit  EAN0   = 0x90;

#endif

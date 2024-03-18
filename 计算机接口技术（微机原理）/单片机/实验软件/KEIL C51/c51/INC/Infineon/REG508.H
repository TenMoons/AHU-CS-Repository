/*----------------------------------------------------------------------
REG508.H

Header file for Infineon C508
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG508_H__
#define __REG508_H__

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
sfr   XPAGE  = 0x91;
sfr   DPSEL  = 0x92;
sfr   SCON   = 0x98;
sfr   SBUF   = 0x99;
sfr   IEN2   = 0x9A;

sfr   P2     = 0xA0;
sfr   IEN0   = 0xA8;
sfr   IP0    = 0xA9;
sfr   SRELL  = 0xAA;

sfr   P3     = 0xB0;
sfr   SYSCON = 0xB1;

sfr   IEN1   = 0xB8;
sfr   IP1    = 0xB9;
sfr   SRELH  = 0xBA;
sfr   IEN3   = 0xBE;

sfr   IRCON  = 0xC0;
sfr   CCEN   = 0xC1;
sfr   CCL1   = 0xC2;
sfr   CCH1   = 0xC3;
sfr   CCL2   = 0xC4;
sfr   CCH2   = 0xC5;
sfr   CCL3   = 0xC6;
sfr   CCH3   = 0xC7;
sfr   T2CON  = 0xC8;
sfr   CRCL   = 0xCA;
sfr   CRCH   = 0xCB;
sfr   TL2    = 0xCC;
sfr   TH2    = 0xCD;

/* 16-Bit SFR's for CC?? registers */

sfr16 CC1    = 0xC2;
sfr16 CC2    = 0xC4;
sfr16 CC3    = 0xC6;
sfr16 CRC    = 0xCA;
sfr16 T2     = 0xCC;

sfr   PSW    = 0xD0;
sfr   CP2L   = 0xD2;
sfr   CP2H   = 0xD3;
sfr16 CP2    = 0xD2;
sfr   CMP2L  = 0xD4;
sfr   CMP2H  = 0xD5;
sfr16 CMP2   = 0xD4;
sfr   CCIE   = 0xD6;
sfr   CC1L2  = 0xD6;
sfr   BCON   = 0xD7;

sfr   ADCON0 = 0xD8;
sfr   ADDATH = 0xD9;
sfr   ADDATL = 0xDA;
sfr   P4     = 0xDB;
sfr   ADCON1 = 0xDC;
sfr   CCPL   = 0xDE;
sfr   CCPH   = 0xDF;
sfr16 CCP    = 0xDE;

sfr   ACC    = 0xE0;
sfr   CT1CON = 0xE1;
sfr   COINI  = 0xE2;
sfr   CMSEL0 = 0xE3;
sfr   CMSEL1 = 0xE4;
sfr   CCIR   = 0xE5;
sfr   CT1OFL = 0xE6;
sfr   CT1OFH = 0xE7;

sfr   B      = 0xF0;
sfr   CT2CON = 0xF1;
sfr   CCL0   = 0xF2;
sfr   CCH0   = 0xF3;
//sfr   CCL1   = 0xF4;
//sfr   CCH1   = 0xF5;
//sfr   CCL2   = 0xF6;
//sfr   CCH2   = 0xF7;
sfr   P5     = 0xF8;
sfr   COTRAP = 0xF9;
sfr   EINT   = 0xFB;
sfr   VR0    = 0xFC; /* in mapped SFR area */
sfr   VR1    = 0xFD; /* in mapped SFR area */
sfr   VR2    = 0xFE; /* in mapped SFR area */
sfr   TRCON  = 0xFF;


/* BIT Register */

/* P0 */
sbit  P0_7   = P0^7;
sbit  P0_6   = P0^6;
sbit  P0_5   = P0^5;
sbit  P0_4   = P0^4;
sbit  P0_3   = P0^3;
sbit  P0_2   = P0^2;
sbit  P0_1   = P0^1;
sbit  P0_0   = P0^0;
/* TCON */
sbit  TF1    = TCON^7;
sbit  TR1    = TCON^6;
sbit  TF0    = TCON^5;
sbit  TR0    = TCON^4;
sbit  IE1    = TCON^3;
sbit  IT1    = TCON^2;
sbit  IE0    = TCON^1;
sbit  IT0    = TCON^0;
/* PCON1 */
sbit  EWPD   = PCON1^7;
sbit  WS     = PCON1^4;
/* P1 */
sbit  _T2     = P1^7;  // symbol "T2" used for sfr16 Timer2
sbit  CLKOUT = P1^6;
sbit  T2EX   = P1^5;
sbit  P1_4   = P1^4;
sbit  P1_3   = P1^3;
sbit  INT5   = P1^2;
sbit  INT4   = P1^1;
sbit  P1_0   = P1^0;
/* SCON */
sbit  SM0   = SCON^7;
sbit  SM1   = SCON^6;
sbit  SM2   = SCON^5;
sbit  REN   = SCON^4;
sbit  TB8   = SCON^3;
sbit  RB8   = SCON^2;
sbit  TI    = SCON^1;
sbit  RI    = SCON^0;
/* P2 */
sbit  P2_7   = P2^7;
sbit  P2_6   = P2^6;
sbit  P2_5   = P2^5;
sbit  P2_4   = P2^4;
sbit  P2_3   = P2^3;
sbit  P2_2   = P2^2;
sbit  P2_1   = P2^1;
sbit  P2_0   = P2^0;
/* IEN0 */
sbit  EA     = IEN0^7;
sbit  WDT    = IEN0^6;
sbit  ET2    = IEN0^5;
sbit  ES     = IEN0^4;
sbit  ET1    = IEN0^3;
sbit  EX1    = IEN0^2;
sbit  ET0    = IEN0^1;
sbit  EX0    = IEN0^0;
/* P3 */
sbit  RD     = P3^7;
sbit  WR     = P3^6;
sbit  T1     = P3^5;
sbit  T0     = P3^4;
sbit  INT1   = P3^3;
sbit  INT0   = P3^2;
sbit  TXD    = P3^1;
sbit  RXD    = P3^0;
/* IEN1 */
sbit  SWDT   = IEN1^6;
sbit  EX6    = IEN1^5;
sbit  EX5    = IEN1^4;
sbit  EX4    = IEN1^3;
sbit  EX3    = IEN1^2;
sbit  EX2    = IEN1^1;
sbit  EADC   = IEN1^0;
/* IRCON */
sbit  TF2    = IRCON^6;
sbit  IEX6   = IRCON^5;
sbit  IEX5   = IRCON^4;
sbit  IEX4   = IRCON^3;
sbit  IEX3   = IRCON^2;
sbit  IEX2   = IRCON^1;
sbit  IADC   = IRCON^0;
/* T2CON */
sbit  T2PS   = T2CON^7;
sbit  I3FR   = T2CON^6;
sbit  I2FR   = T2CON^5;
sbit  T2R    = T2CON^4;
sbit  T2CM   = T2CON^2;
sbit  T2I    = T2CON^0;
/* PSW */
sbit  CY     = PSW^7;
sbit  AC     = PSW^6;
sbit  F0     = PSW^5;
sbit  RS1    = PSW^4;
sbit  RS0    = PSW^3;
sbit  OV     = PSW^2;
sbit  F1     = PSW^1;
sbit  P      = PSW^0;
/* ADCON0 */
sbit  BD     = ADCON0^7;
sbit  CLK    = ADCON0^6;
sbit  BSY    = ADCON0^4;
sbit  ADM    = ADCON0^3;
sbit  MX2    = ADCON0^2;
sbit  MX1    = ADCON0^1;
sbit  MX0    = ADCON0^0;
/* P5 */
sbit  P5_7     = P5^7;
sbit  P5_6     = P5^6;
sbit  P5_5     = P5^5;
sbit  P5_4     = P5^4;
sbit  P5_3     = P5^3;
sbit  P5_2     = P5^2;
sbit  P5_1     = P5^1;
sbit  P5_0     = P5^0;

#endif

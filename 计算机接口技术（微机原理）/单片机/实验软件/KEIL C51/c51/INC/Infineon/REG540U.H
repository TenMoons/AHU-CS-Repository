/*------------------------------------------------------------------
REG540U.H 

Header file for Infineon C540U USB controller 
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG540U_H__
#define __REG540U_H__

/*  BYTE Register  */
sfr   P0     = 0x80; 
sfr   SP     = 0x81;
sfr   DPL    = 0x82;
sfr   DPH    = 0x83;
sfr   PCON   = 0x87;
sfr   TCON   = 0x88; 
sfr   PCON1  = 0x88; /* in mapped SFR area */
sfr   TMOD   = 0x89;
sfr   TL0    = 0x8A;
sfr   TL1    = 0x8B;
sfr   TH0    = 0x8C;
sfr   TH1    = 0x8D;
sfr   P1     = 0x90; 
sfr   ITCON  = 0x9A;
sfr   P2     = 0xA0; 
sfr   IEN0   = 0xA8; 
sfr   IEN1   = 0xA9;
sfr   P3     = 0xB0; 
sfr   SYSCON = 0xB1;
sfr   IP0    = 0xB8; 
sfr   IP1    = 0xB9;
sfr   WDCON  = 0xC0; 

/* USB Device and Endpoint Register definitons */
/* EPSEL = 1xxx.xxxxb */
sfr   DCR     = 0xC1;
sfr   DPWDR   = 0xC2;
sfr   DIER    = 0xC3;
sfr   DIRR    = 0xC4;
sfr16 FNR     = 0xC6;
sfr   FNRL    = 0xC6;
sfr   FNRH    = 0xC7; 
/* EPSEL = 0xxx.x000b */
sfr   EPBC0   = 0xC1;
sfr   EPBS0   = 0xC2;
sfr   EPIE0   = 0xC3;
sfr   EPIR0   = 0xC4;
sfr   EPBA0   = 0xC5;
sfr   EPLEN0  = 0xC6;
/* EPSEL = 0xxx.x001b */
sfr   EPBC1   = 0xC1;
sfr   EPBS1   = 0xC2;
sfr   EPIE1   = 0xC3;
sfr   EPIR1   = 0xC4;
sfr   EPBA1   = 0xC5;
sfr   EPLEN1  = 0xC6;
/* EPSEL = 0xxx.x010b */
sfr   EPBC2   = 0xC1;
sfr   EPBS2   = 0xC2;
sfr   EPIE2   = 0xC3;
sfr   EPIR2   = 0xC4;
sfr   EPBA2   = 0xC5;
sfr   EPLEN2  = 0xC6;
/* EPSEL = 0xxx.x011b */
sfr   EPBC3   = 0xC1;
sfr   EPBS3   = 0xC2;
sfr   EPIE3   = 0xC3;
sfr   EPIR3   = 0xC4;
sfr   EPBA3   = 0xC5;
sfr   EPLEN3  = 0xC6;
/* EPSEL = 0xxx.x100b */
sfr   EPBC4   = 0xC1;
sfr   EPBS4   = 0xC2;
sfr   EPIE4   = 0xC3;
sfr   EPIR4   = 0xC4;
sfr   EPBA4   = 0xC5;
sfr   EPLEN4  = 0xC6;

sfr   PSW    = 0xD0; 
sfr   EPSEL  = 0xD2;
sfr   USBVAL = 0xD3;
sfr   ADROFF = 0xD4;
sfr   GEPIR  = 0xD6;

sfr   ACC    = 0xE0; 

sfr   B      = 0xF0;

sfr   VR0    = 0xFC; /* in mapped SFR area  */
sfr   VR1    = 0xFD; /* in mapped SFR area  */
sfr   VR2    = 0xFE; /* in mapped SFR area  */

/*******************************************/

/* BIT-addressable registers */
/* TCON, PCON1 */
sbit  TF1   = 0x8F;
sbit  EWPD  = 0x8F; /* in mapped SFR area */
sbit  TR1   = 0x8E;
sbit  TF0   = 0x8D;
sbit  TR0   = 0x8C;
sbit  WS    = 0x8C; /* in mapped SFR area */
sbit  IE1   = 0x8B;
sbit  IT1   = 0x8A;
sbit  IE0   = 0x89;
sbit  IT0   = 0x88;
/* P1 */
sbit  SLS   = 0x95;
sbit  STO   = 0x94;
sbit  SRI   = 0x93;
sbit  SCLK  = 0x92; 
sbit  LED1  = 0x91;
sbit  LED0  = 0x90;
/* IEN0 */
sbit  EA    = 0xAF;
sbit  EX1   = 0xAA;
sbit  ET0   = 0xA9;
sbit  EX0   = 0xA8;
/* IP0 */
sbit  PT1   = 0xBC;
sbit  PX1   = 0xBB;
sbit  PT0   = 0xBA;
sbit  PX0   = 0xB8;
/* P3 */
sbit  RD    = 0xB7;
sbit  WR    = 0xB6;
sbit  T1    = 0xB5;
sbit  T0    = 0xB4;
sbit  INT1  = 0xB3;
sbit  INT0  = 0xB2;
sbit  DADD  = 0xB1;
sbit  LED2  = 0xB0;
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

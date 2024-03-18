/*------------------------------------------------------------------
REG515C.H

Header file for the Infineon C515C 
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG515C_H__
#define __REG515C_H__

/*  BYTE Registers    */
/*  CPU    */
sfr   ACC    = 0xE0;
sfr   B      = 0xF0;
sfr   DPL    = 0x82;
sfr   DPH    = 0x83;
sfr   DPSEL  = 0x92;
sfr   PSW    = 0xD0;
sfr   SP     = 0x81;
sfr   SYSCON = 0xB1;

/*  A/D Converter     */
sfr   ADCON0 = 0xD8;
sfr   ADDATH = 0xD9;
sfr   ADDATL = 0xDA;  /* in mapped SFR area */
sfr   ADCON1 = 0xDC;

/*  Interrupt System  */
sfr   IEN0   = 0xA8;
sfr   IEN1   = 0xB8;
sfr   IEN2   = 0x9A;
sfr   IP0    = 0xA9;
sfr   IP1    = 0xB9;
sfr   IRCON  = 0xC0;

/*  XRAM   */
sfr   XPAGE  = 0x91;

/*  Ports  */
sfr   P0     = 0x80;
sfr   P1     = 0x90;
sfr   P2     = 0xA0;
sfr   P3     = 0xB0;
sfr   P4     = 0xE8;
sfr   P5     = 0xF8;
sfr   DIR5   = 0xF8;  /* in mapped SFR area */
sfr   P6     = 0xDB;
sfr   P7     = 0xFA;

/*  Serial Channel    */
sfr   SCON   = 0x98;
sfr   SBUF   = 0x99;
sfr   SRELL  = 0xAA;
sfr   SRELH  = 0xBA;

/*  SSC Interface     */
sfr   SSCCON = 0x93;
sfr   STB    = 0x94;
sfr   SRB    = 0x95;
sfr   SCF    = 0xAB;
sfr   SCIEN  = 0xAC;
sfr   SSCMOD = 0x96;

/*  Timer0 / Timer1   */
sfr   TCON   = 0x88;
sfr   TMOD   = 0x89;
sfr   TL0    = 0x8A;
sfr   TL1    = 0x8B;
sfr   TH0    = 0x8C;
sfr   TH1    = 0x8D;

/*  CAP/COM Unit / Timer2 */
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

/*  Watchdog */
sfr   WDTREL = 0x86;

/*  Power Save Moders */
sfr   PCON   = 0x87;
sfr   PCON1  = 0x88;  /* in mapped SFR area */


/*  BIT Register  */
/*  PSW  */
sbit  CY     = PSW^7;
sbit  AC     = PSW^6;
sbit  F0     = PSW^5;
sbit  RS1    = PSW^4;
sbit  RS0    = PSW^3;
sbit  OV     = PSW^2;
sbit  F1     = PSW^1;
sbit  P      = PSW^0;

/*  TCON  */
sbit  TF1    = TCON^7;
sbit  TR1    = TCON^6;
sbit  TF0    = TCON^5;
sbit  TR0    = TCON^4;
sbit  IE1    = TCON^3;
sbit  IT1    = TCON^2;
sbit  IE0    = TCON^1;
sbit  IT0    = TCON^0;

/*  IEN0  */
sbit  EAL    = IEN0^7;
sbit  WDT    = IEN0^6;
sbit  ET2    = IEN0^5;
sbit  ES     = IEN0^4;
sbit  ET1    = IEN0^3;
sbit  EX1    = IEN0^2;
sbit  ET0    = IEN0^1;
sbit  EX0    = IEN0^0;

/*  IEN1  */
sbit  EXEN2  = IEN1^7;
sbit  SWDT   = IEN1^6;
sbit  EX6    = IEN1^5;
sbit  EX5    = IEN1^4;
sbit  EX4    = IEN1^3;
sbit  EX3    = IEN1^2;
sbit  EX2    = IEN1^1;
sbit  EADC   = IEN1^0;

/*  P3  */
sbit  RD     = P3^7;
sbit  WR     = P3^6;
sbit  T1     = P3^5;
sbit  T0     = P3^4;
sbit  INT1   = P3^3;
sbit  INT0   = P3^2;
sbit  TXD    = P3^1;
sbit  RXD    = P3^0;

/*  SCON  */
sbit  SM0    = SCON^7;
sbit  SM1    = SCON^6;
sbit  SM2    = SCON^5;
sbit  REN    = SCON^4;
sbit  TB8    = SCON^3;
sbit  RB8    = SCON^2;
sbit  TI     = SCON^1;
sbit  RI     = SCON^0;

/*  T2CON  */
sbit  T2PS   = T2CON^7;
sbit  I3FR   = T2CON^6;
sbit  I2FR   = T2CON^5;
sbit  T2R1   = T2CON^4;
sbit  T2R0   = T2CON^3;
sbit  T2CM   = T2CON^2;
sbit  T2I1   = T2CON^1;
sbit  T2I0   = T2CON^0;

/*  ADCON0  */
sbit  BD     = ADCON0^7;
sbit  CLK    = ADCON0^6;
sbit  ADEX   = ADCON0^5;
sbit  BSY    = ADCON0^4;
sbit  ADM    = ADCON0^3;
sbit  MX2    = ADCON0^2;
sbit  MX1    = ADCON0^1;
sbit  MX0    = ADCON0^0;

/*  IRCON  */
sbit  EXF2   = IRCON^7;
sbit  TF2    = IRCON^6;
sbit  IEX6   = IRCON^5;
sbit  IEX5   = IRCON^4;
sbit  IEX4   = IRCON^3;
sbit  IEX3   = IRCON^2;
sbit  IEX2   = IRCON^1;
sbit  IADC   = IRCON^0;

/*  P1    */
sbit  T2     = P1^7;
sbit  CLKOUT = P1^6;
sbit  T2EX   = P1^5;
sbit  INT2   = P1^4;
sbit  INT6   = P1^3;
sbit  INT5   = P1^2;
sbit  INT4   = P1^1;
sbit  INT3   = P1^0;

/*  P4    */
sbit  RXDC   = P4^7;
sbit  TXDC   = P4^6;
sbit  INT8   = P4^5;
sbit  SLS    = P4^4;
sbit  STO    = P4^3;
sbit  SRI    = P4^2;
sbit  SCLK   = P4^1;
sbit  ADST   = P4^0;

#endif

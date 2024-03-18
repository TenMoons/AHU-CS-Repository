/*----------------------------------------------------------------------
REG513A.H

Header file for Infineon C513A
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG513A_H__
#define __REG513A_H__

/* BYTE Registers */
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
sfr   SCON   = 0x98;
sfr   SBUF   = 0x99;
sfr   P2     = 0xA0;
sfr   IE     = 0xA8;
sfr   P3     = 0xB0;
sfr   SYSCON = 0xB1;
sfr   IP     = 0xB8;
sfr   WDCON  = 0xC0;
sfr   T2CON  = 0xC8;
sfr   T2MOD  = 0xC9;
sfr   RC2L   = 0xCA;
sfr   RC2H   = 0xCB;
sfr   TL2    = 0xCC;
sfr   TH2    = 0xCD;
sfr   PSW    = 0xD0;
sfr   ACC    = 0xE0;
sfr   SSCCON = 0xE8;
sfr   STB    = 0xE9;
sfr   SRB    = 0xEA;
sfr   SSCMOD = 0xEB;
sfr   B      = 0xF0;
sfr   SCF    = 0xF8;
sfr   SCIEN  = 0xF9;
sfr   VR0    = 0xFC;
sfr   VR1    = 0xFD;
sfr   VR2    = 0xFE;

/* BIT Registers */
/* P0     */
sbit  P0_7   = P0^7;
sbit  P0_6   = P0^6;
sbit  P0_5   = P0^5;
sbit  P0_4   = P0^4;
sbit  P0_3   = P0^3;
sbit  P0_2   = P0^2;
sbit  P0_1   = P0^1;
sbit  P0_0   = P0^0;
/* TCON   */
sbit   TF1  = TCON^7;
sbit   TR1  = TCON^6;
sbit   TF0  = TCON^5;
sbit   TR0  = TCON^4;
sbit   IE1  = TCON^3;
sbit   IT1  = TCON^2;
sbit   IE0  = TCON^1;
sbit   IT0  = TCON^0;
/* PCON1  */
sbit  EWPD  = PCON1^7;
/* P1     */ 
sbit  SLS   = P1^5;
sbit  STO   = P1^4;
sbit  SRI   = P1^3;
sbit  SLCK  = P1^2;
sbit  T2EX  = P1^1;
sbit  T2    = P1^0;
/* SCON   */
sbit  SM0   = SCON^7;
sbit  SM1   = SCON^6;
sbit  SM2   = SCON^5;
sbit  REN   = SCON^4;
sbit  TB8   = SCON^3;
sbit  RB8   = SCON^2;
sbit  TI    = SCON^1;
sbit  RI    = SCON^0;
/* P2    */
sbit  P2_7  = P2^7;
sbit  P2_6  = P2^6;
sbit  P2_5  = P2^5;
sbit  P2_4  = P2^4;
sbit  P2_3  = P2^3;
sbit  P2_2  = P2^2;
sbit  P2_1  = P2^1;
sbit  P2_0  = P2^0;
/* IE    */
sbit  EAL   = IE^7;
sbit  ESSC  = IE^6;
sbit  ET2   = IE^5;
sbit  ES    = IE^4;
sbit  ET1   = IE^3;
sbit  EX1   = IE^2;
sbit  ET0   = IE^1;
sbit  EX0   = IE^0;
/* P3    */
sbit  RD    = P3^7;
sbit  WR    = P3^6;
sbit  T1    = P3^5;
sbit  T0    = P3^4;
sbit  INT1  = P3^3;
sbit  INT0  = P3^2;
sbit  TXD   = P3^1;
sbit  RXD   = P3^0;
/* IP    */
sbit  PSSC  = IP^6;
sbit  PT2   = IP^5;
sbit  PS    = IP^4;
sbit  PT1   = IP^3;
sbit  PX1   = IP^2;
sbit  PT0   = IP^1;
sbit  PX0   = IP^0;
/* WDCON */
sbit  OWDS  = WDCON^3;
sbit  WDTS  = WDCON^2;
sbit  WDT   = WDCON^1;
sbit  SWDT  = WDCON^0;
/* T2CON */
sbit   TF2    = T2CON^7;
sbit   IEXF2  = T2CON^6;
sbit   EXF2   = T2CON^6;
sbit   RCLK   = T2CON^5;
sbit   TCLK   = T2CON^4;
sbit   EXEN2  = T2CON^3;
sbit   TR2    = T2CON^2;
sbit   C_T2   = T2CON^1;
sbit   CP_RL2 = T2CON^0;
/* PSW   */
sbit  CY    = PSW^7;
sbit  AC    = PSW^6;
sbit  F0    = PSW^5;
sbit  RS1   = PSW^4;
sbit  RS0   = PSW^3;
sbit  OV    = PSW^2;
sbit  F1    = PSW^1;
sbit  P     = PSW^0;
/* SSCON */ 
sbit   SCEN  = SSCCON^7;
sbit   TEN   = SSCCON^6;
sbit   MSTR  = SSCCON^5;
sbit   CPOL  = SSCCON^4;
sbit   CPHA  = SSCCON^3;
sbit   BRS2  = SSCCON^2;
sbit   BRS1  = SSCCON^1;
sbit   BRS0  = SSCCON^0;
/* SCF   */
sbit   WCOL  = SCF^1;
sbit   TC    = SCF^0;

#endif



/*-------------------------------------------------------------------------
REG668.H

Header file for Philips 8xC668
  
Copyright (c)2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
-------------------------------------------------------------------------*/

#ifndef __REG668_H__
#define __REG668_H__

/*  BYTE Registers  */
sfr ACC  	= 0xE0;
sfr AUXR  	= 0x8E;
sfr AUXR1  	= 0xA2;
sfr B  	= 0xF0;
sfr CCAP0H  	= 0xFA;
sfr CCAP1H  	= 0xFB;
sfr CCAP2H  	= 0xFC;
sfr CCAP3H  	= 0xFD;
sfr CCAP4H  	= 0xFE;
sfr CCAP0L  	= 0xEA;
sfr CCAP1L  	= 0xEB;
sfr CCAP2L  	= 0xEC;
sfr CCAP3L  	= 0xED;
sfr CCAP4L  	= 0xEE;
sfr CCAPM0  	= 0xC2;
sfr CCAPM1  	= 0xC3;
sfr CCAPM2  	= 0xC4;
sfr CCAPM3  	= 0xC5;
sfr CCAPM4  	= 0xC6;
sfr CCON  	= 0xC0;
sfr CH  	= 0xF9;
sfr CL  	= 0xE9;
sfr CMOD  	= 0xC1;
sfr DPH  	= 0x83;
sfr DPL  	= 0x82;
sfr IEN0  	= 0xA8;
sfr IEN1 	= 0xE8;
sfr IP  	= 0xB8;
sfr IPH 	= 0xB7;
sfr P0  	= 0x80;
sfr P1  	= 0x90;
sfr P2  	= 0xA0;
sfr P3  	= 0xB0;
sfr PCON  	= 0x87;
sfr PSW  	= 0xD0;
sfr RCAP2H  	= 0xCB;
sfr RCAP2L 	= 0xCA;
sfr SADDR	= 0xA9;
sfr SADEN 	= 0xB9;
sfr S0BUF	= 0x99;
sfr S0CON 	= 0x98;
sfr SP 	= 0x81;
sfr S1DAT 	= 0xDA;
sfr S1IST 	= 0xDC;
sfr S1ADR 	= 0xDB;
sfr S1STA 	= 0xD9;
sfr S1CON 	= 0xD8;
sfr TCON 	= 0x88;
sfr T2CON 	= 0xC8;
sfr T2MOD 	= 0xC9;
sfr TH0 	= 0x8C;
sfr TH1 	= 0x8D;
sfr TH2 	= 0xCD;
sfr TL0 	= 0x8A;
sfr TL1 	= 0x8B;
sfr TL2 	= 0xCC;
sfr TMOD 	= 0x89;
sfr WDTRST 	= 0xA6;

/*  BIT Registers  */

sbit  CY     =   PSW^7;
sbit  AC     =   PSW^6;
sbit  F0     =   PSW^5;
sbit  RS1    =   PSW^4;
sbit  RS0    =   PSW^3;
sbit  OV     =   PSW^2;
sbit  UD     =   PSW^1;
sbit  P      =   PSW^0;

sbit  AD7    =   P0^7;
sbit  AD6    =   P0^6;
sbit  AD5    =   P0^5;
sbit  AD4    =   P0^4;
sbit  AD3    =   P0^3;
sbit  AD2    =   P0^2;
sbit  AD1    =   P0^1;
sbit  AD0    =   P0^0;

sbit  TF1    =   TCON^7;
sbit  TR1    =   TCON^6;
sbit  TF0    =   TCON^5;
sbit  TR0    =   TCON^4;
sbit  IE1    =   TCON^3;
sbit  IT1    =   TCON^2;
sbit  IE0    =   TCON^1;
sbit  IT0    =   TCON^0;

sbit  SDA     =   P1^7;
sbit  SCL     =   P1^6;
sbit  CEX2    =   P1^5;
sbit  CEX1    =   P1^4;
sbit  CEX0    =   P1^3;
sbit  ECI     =   P1^2;
sbit  T2EX    =   P1^1;
sbit  T2      =   P1^0;

sbit  SM0    =   S0CON^7;
sbit  FE     =   S0CON^7;
sbit  SM1    =   S0CON^6;
sbit  SM2    =   S0CON^5;
sbit  REN    =   S0CON^4;
sbit  TB8    =   S0CON^3;
sbit  RB8    =   S0CON^2;
sbit  TI     =   S0CON^1;
sbit  RI     =   S0CON^0;

sbit  CR2    =   S1CON^7;
sbit  ENS1   =   S1CON^6;
sbit  STA    =   S1CON^5;
sbit  STO    =   S1CON^4;
sbit  SI     =   S1CON^3;
sbit  AA     =   S1CON^2;
sbit  CR1    =   S1CON^1;
sbit  CR0    =   S1CON^0;

sbit  AD15    =   P2^7;
sbit  AD14    =   P2^6;
sbit  AD13    =   P2^5;
sbit  AD12    =   P2^4;
sbit  AD11    =   P2^3;
sbit  AD10    =   P2^2;
sbit  AD9     =   P2^1;
sbit  AD8     =   P2^0;

sbit  EA     =   IEN0^7;
sbit  EC     =   IEN0^6;
sbit  ES1    =   IEN0^5;
sbit  ES0    =   IEN0^4;
sbit  ET1    =   IEN0^3;
sbit  EX1    =   IEN0^2;
sbit  ET0    =   IEN0^1;
sbit  EX0    =   IEN0^0;

sbit  ET2    =   IEN1^0;

sbit  RD      =   P3^7;
sbit  WR      =   P3^6;
sbit  T1      =   P3^5;
sbit  T0      =   P3^4;
sbit  INT1    =   P3^3;
sbit  INT0    =   P3^2;
sbit  TXD     =   P3^1;
sbit  RXD     =   P3^0;

sbit  TF2    =   T2CON^7;
sbit  EXF2   =   T2CON^6;
sbit  RCLK   =   T2CON^5;
sbit  TCLK   =   T2CON^4;
sbit  EXEN2  =   T2CON^3;
sbit  TR2    =   T2CON^2;
sbit  CT2    =   T2CON^1;
sbit  CP     =   T2CON^0;

#endif
/*-------------------------------------------------------------------------
REG575.H

Header file for Philips 8xC575
  
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG575_H__
#define __REG575_H__

sfr  P0      =   0x80;			 

sbit  P0_7    =   P0^7;
sbit  P0_6    =   P0^6;
sbit  P0_5    =   P0^5;
sbit  P0_4    =   P0^4;
sbit  P0_3    =   P0^3;
sbit  P0_2    =   P0^2;
sbit  P0_1    =   P0^1;
sbit  P0_0    =   P0^0;

sfr  SP      =   0x81;
sfr  DPL     =   0x82;
sfr  DPH     =   0x83;

sfr  PCON    =   0x87;			 

sfr  TCON    =   0x88;             

sbit  TF1    =   TCON^7;
sbit  TR1    =   TCON^6;
sbit  TF0    =   TCON^5;
sbit  TR0    =   TCON^4;
sbit  IE1_   =   TCON^3;
sbit  IT1    =   TCON^2;
sbit  IE0_   =   TCON^1;
sbit  IT0    =   TCON^0;

sfr  TMOD    =   0x89;			 

sfr  TL0     =   0x8A;			 

sfr  TL1     =   0x8B;			 

sfr  TH0     =   0x8C;			 

sfr  TH1     =   0x8D;			 

sfr  P1      =   0x90;			 

sbit  P1_7    =   P1^7;
sbit  P1_6    =   P1^6;
sbit  P1_5    =   P1^5;
sbit  P1_4    =   P1^4;
sbit  P1_3    =   P1^3;
sbit  P1_2    =   P1^2;
sbit  P1_1    =   P1^1;
sbit  P1_0    =   P1^0;

sbit  T2EX    =   P1^1;
sbit  T2      =   P1^0;

sfr  S0CON    =   0x98;			 
sfr  S1CON	  =	  0xD8;

sfr  SCON	 =	  0x98;

sbit  SM0    =   S0CON^7;
sbit  FE     =   S0CON^7;
sbit  SM1    =   S0CON^6;
sbit  SM2    =   S0CON^5;
sbit  REN    =   S0CON^4;
sbit  TB8    =   S0CON^3;
sbit  RB8    =   S0CON^2;
sbit  TI     =   S0CON^1;
sbit  RI     =   S0CON^0;

sfr  S0BUF    =   0x99;			 

sfr  P2      =   0xA0;			 

sbit  P2_7    =   P2^7;
sbit  P2_6    =   P2^6;
sbit  P2_5    =   P2^5;
sbit  P2_4    =   P2^4;
sbit  P2_3    =   P2^3;
sbit  P2_2    =   P2^2;
sbit  P2_1    =   P2^1;
sbit  P2_0    =   P2^0;

sfr  IE     =   0xA8;			     
sfr  IE0    =   0xA8;

sbit  EA     =   IE^7;
sbit  ET2    =   IE^5;
sbit  ES     =   IE^4;
sbit  ET1    =   IE^3;
sbit  EX1    =   IE^2;
sbit  ET0    =   IE^1;
sbit  EX0    =   IE^0;

sfr  SADDR   =   0xA9;			 

sfr  P3      =   0xB0;			 

sbit  P3_7    =   P3^7;
sbit  P3_6    =   P3^6;
sbit  P3_5    =   P3^5;
sbit  P3_4    =   P3^4;
sbit  P3_3    =   P3^3;
sbit  P3_2    =   P3^2;
sbit  P3_1    =   P3^1;
sbit  P3_0    =   P3^0;

sbit  RD      =   P3^7;
sbit  WR      =   P3^6;
sbit  T1      =   P3^5;
sbit  T0      =   P3^4;
sbit  INT1    =   P3^3;
sbit  INT0    =   P3^2;
sbit  TXD     =   P3^1;
sbit  RXD     =   P3^0;

sfr  IPH    =   0xB7;			     
sfr  IP     =   0xB8;


sfr  SADEN   =   0xB9;			 
	

sbit  IPLT2    =   IP^5;
sbit  IPLS     =   IP^4;
sbit  IPLT1    =   IP^3;
sbit  IPLX1    =   IP^2;
sbit  IPLT0    =   IP^1;
sbit  IPLX0    =   IP^0;

sfr  T2CON   =   0xC8;             

sbit  TF2    =   T2CON^7;
sbit  EXF2   =   T2CON^6;
sbit  RCLK   =   T2CON^5;
sbit  TCLK   =   T2CON^4;
sbit  EXEN2  =   T2CON^3;
sbit  TR2    =   T2CON^2;
sbit  CT2    =   T2CON^1;
sbit  CPRL2  =   T2CON^0;

sfr  T2MOD   =   0xC9;			 

sfr  RCAP2L  =   0xCA;			 
sfr  RCAP2H  =   0xCB;			 
sfr  TL2     =   0xCC;			 
sfr  TH2     =   0xCD;			 

sfr  PSW     =   0xD0;			 
sbit  CY     =   PSW^7;
sbit  AC     =   PSW^6;
sbit  F0     =   PSW^5;
sbit  RS1    =   PSW^4;
sbit  RS0    =   PSW^3;
sbit  OV     =   PSW^2;
sbit  UD     =   PSW^1;
sbit  P      =   PSW^0;

			 
sfr  ACC     =   0xE0;			 
sfr  B       =   0xF0;			 

sfr  CCON    =   0xC0;			 

sfr  CMOD    =   0xC1;			 
sfr  CCAPM0  =   0xC2;			 
sfr  CCAPM1  =   0xC3;			 
sfr  CCAPM2  =   0xC4;			 
sfr  CCAPM3  =   0xC5;			 
sfr  CCAPM4  =   0xC6;	

sfr  CL      =   0xE9;			 
sfr  CCAP0L  =   0xEA;			 
sfr  CCAP1L  =   0xEB;			 
sfr  CCAP2L  =   0xEC;			 
sfr  CCAP3L  =   0xED;			 
sfr  CCAP4L  =   0xEE;			 

sfr  CH      =   0xF9;			 
sfr  CCAP0H  =   0xFA;			 
sfr  CCAP1H  =   0xFB;			  
sfr  CCAP2H  =   0xFC;			 
sfr  CCAP3H  =   0xFD;			 
sfr  CCAP4H  =   0xFE;	
sfr IEN0  	= 0xA8;
sfr IEN1	= 0xE8;

sfr AUXR	= 0x8E;
sfr AUXR1	= 0xA2;

sfr S1DAT	= 0xDA;
sfr	S1IST	=	0xDC;
sfr	S1ADR	=	0xDB;
sfr	S1STA	=	0xD9;

#endif

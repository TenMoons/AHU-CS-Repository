/*-------------------------------------------------------------------------
REG51CC01.H

Header file for Atmel Wireless & uC 89C51CC01
  
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG51CC01_H__
#define __REG51CC01_H__

sfr  ACC     =   0xE0;			 
sfr  B       =   0xF0;			 
sfr  PSW     =   0xD0;	
sfr  SP      =   0x81;
sfr  DPL     =   0x82;
sfr  DPH     =   0x83;


sfr  P0      =   0x80;			 
sbit  P0_7    =   P0^7;
sbit  P0_6    =   P0^6;
sbit  P0_5    =   P0^5;
sbit  P0_4    =   P0^4;
sbit  P0_3    =   P0^3;
sbit  P0_2    =   P0^2;
sbit  P0_1    =   P0^1;
sbit  P0_0    =   P0^0;

sfr  P1      =   0x90;			 
sbit  P1_7    =   P1^7;
sbit  P1_6    =   P1^6;
sbit  P1_5    =   P1^5;
sbit  P1_4    =   P1^4;
sbit  P1_3    =   P1^3;
sbit  P1_2    =   P1^2;
sbit  P1_1    =   P1^1;
sbit  P1_0    =   P1^0;

sfr  P2      =   0xA0;	
sbit  P2_7    =   P2^7;
sbit  P2_6    =   P2^6;
sbit  P2_5    =   P2^5;
sbit  P2_4    =   P2^4;
sbit  P2_3    =   P2^3;
sbit  P2_2    =   P2^2;
sbit  P2_1    =   P2^1;
sbit  P2_0    =   P2^0;

sfr  P3      =   0xB0;			 
sbit  P3_7    =   P3^7;
sbit  P3_6    =   P3^6;
sbit  P3_5    =   P3^5;
sbit  P3_4    =   P3^4;
sbit  P3_3    =   P3^3;
sbit  P3_2    =   P3^2;
sbit  P3_1    =   P3^1;
sbit  P3_0    =   P3^0;

sfr  P4      =   0xC0;
sbit  P4_1    =   P4^1;
sbit  P4_0    =   P4^0;

sfr  TH0     =   0x8C;			 
sfr  TL0     =   0x8A;			 
sfr  TH1     =   0x8D;			 
sfr  TL1     =   0x8B;
sfr  TH2     =   0xCD;			 
sfr  TL2     =   0xCC;

sfr  TCON    =   0x88;   
 sbit  TF1    =   TCON^7;
 sbit  TR1    =   TCON^6;
 sbit  TF0    =   TCON^5;
 sbit  TR0    =   TCON^4;
 sbit  IE1   =   TCON^3;
 sbit  IT1    =   TCON^2;
 sbit  IE0   =   TCON^1;
 sbit  IT0    =   TCON^0;

sfr  TMOD    =   0x89;

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
sfr  RCAP2H  =   0xCB;
sfr  RCAP2L  =   0xCA;			 
sfr  WDTRST  =   0xA6;			 
sfr  WDTPRG  =   0xA7;			 

sfr  SCON    =   0x98;	
 sbit SM0   = SCON^7;
 sbit SM1   = SCON^6;
 sbit SM2   = SCON^5;
 sbit REN   = SCON^4;
 sbit TB8   = SCON^3;
 sbit RB8   = SCON^2;
 sbit TI    = SCON^1;
 sbit RI    = SCON^0;

		 
sfr  SBUF    =   0x99;			 
sfr  SADEN   =   0xB9;	
sfr  SADDR   =   0xA9;

sfr  CCON    =   0xD8;			 
 sbit  CF      =   CCON^7;
 sbit  CR      =   CCON^6;
 sbit  CCF4    =   CCON^4;
 sbit  CCF3    =   CCON^3;
 sbit  CCF2    =   CCON^2;
 sbit  CCF1    =   CCON^1;
 sbit  CCF0    =   CCON^0;
sfr  CMOD    =   0xD9;
sfr  CL      =   0xE9;
sfr  CH      =   0xF9;
sfr  CCAPM0  =   0xDA;			 
sfr  CCAPM1  =   0xDB;			 
sfr  CCAPM2  =   0xDC;			 
sfr  CCAPM3  =   0xDD;			 
sfr  CCAPM4  =   0xDE;	
sfr  CCAP0H  =   0xFA;			 
sfr  CCAP1H  =   0xFB;			  
sfr  CCAP2H  =   0xFC;			 
sfr  CCAP3H  =   0xFD;			 
sfr  CCAP4H  =   0xFE;			 
sfr  CCAP0L  =   0xEA;			 
sfr  CCAP1L  =   0xEB;			 
sfr  CCAP2L  =   0xEC;			 
sfr  CCAP3L  =   0xED;			 
sfr  CCAP4L  =   0xEE;			 

sfr  IEN0    =   0xA8;
 sbit  EA     =   IE0^7;
 sbit  EC     =   IE0^6;
 sbit  ET2    =   IE0^5;
 sbit  ES     =   IE0^4;
 sbit  ET1    =   IE0^3;
 sbit  EX1    =   IE0^2;
 sbit  ET0    =   IE0^1;
 sbit  EX0    =   IE0^0;

sfr  IEN1    =   0xE8;
 sbit   ETIM   =   IE1^2;
 sbit   EADC   =   IE1^1;
 sbit   ECAN   =   IE1^0;

sfr  IPL0    =   0xB8;	
 sbit  PPC      =   IPL0^6;
 sbit  PT2      =   IPL0^5;
 sbit  PS       =   IPL0^4;
 sbit  PT1      =   IPL0^3;
 sbit  PX1      =   IPL0^2;
 sbit  PT0      =   IPL0^1;
 sbit  PX0      =   IPL0^0; 
sfr  IPH0    =   0xB7; 
sfr  IPL1    =   0xF8;
 sbit  POVRL   =   IPL1^2;
 sbit  PADCL   =   IPL1^1;
 sbit  PCANL   =   IPL1^0;
sfr  IPH1    =   0xF7;

sfr  ADCON   =   0xF3;

sfr  ADCF    =   0xF6;
sfr  ADCLK   =   0xF2;
sfr  ADDH    =   0xF5;
sfr  ADDL    =   0xF4;

sfr CANGCON   = 0xAB;
sfr CANGSTA   = 0xAA;
sfr CANGIT    = 0x9B;
sfr CANBT1    = 0xB4;
sfr CANBT2    = 0xB5;
sfr CANBT3    = 0xB6;
sfr CANEN1    = 0xCE;
sfr CANEN2    = 0xCF;
sfr CANGIE    = 0xC1;
sfr CANIE1    = 0xC2;
sfr CANIE2    = 0xC3;
sfr CANSIT1   = 0xBA;
sfr CANSIT2   = 0xBB;
sfr CANTCON   = 0xA1;
sfr CANTIMH   = 0xAD;
sfr CANTIML   = 0xAC;
sfr CANSTMH   = 0xAF;
sfr CANSTML   = 0xAE;
sfr CANTTCH   = 0xA5;
sfr CANTTCL   = 0xA4;
sfr CANTEC    = 0x9C;
sfr CANREC    = 0x9D;
sfr CANPAGE   = 0xB1;
sfr CANSTCH   = 0xB2;
sfr CANCONCH  = 0xB3;
sfr CANMSG    = 0xA3;
sfr CANIDT1   = 0xBC;
sfr CANIDT2   = 0xBD;
sfr CANIDT3   = 0xBE;
sfr CANIDT4   = 0xBF;
sfr CANIDM1   = 0xC4;
sfr CANIDM2   = 0xC5;
sfr CANIDM3   = 0xC6;
sfr CANIDM4   = 0xC7;

sfr  PCON     = 0x87;	
sfr  AUXR     = 0x8E; 
sfr  AUXR1    = 0xA2; 
sfr  CKCON    = 0x8F;	
sfr  FCON     = 0xD1;
sfr  EECON    = 0xD2;

#endif




/*-------------------------------------------------------------------------
R80C5111.H    

Header file for AtmelWM T80C5111 REV A  PER T80C5111 DS REV A1 13 OCT 2000
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __R80C5111_H__
#define __R80C5111_H__

sfr  SP      =   0x81;
sfr  DPL     =   0x82;
sfr  DPH     =   0x83;

sfr  CKSEL   =   0x85;
sfr  OSCCON  =   0x86;

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

/*  sfr  AUXR    =   0x8E;  */   /* AUXR NOT AVAILABLE ON T80C5111 REV A  */
	 

sfr  CKCON   =   0x8F;			 
sfr  CKCON0  =   0x8F;			 


sfr  P1      =   0x90;			 

sbit  P1_7    =   P1^7;
sbit  P1_6    =   P1^6;
sbit  P1_5    =   P1^5;
sbit  P1_4    =   P1^4;
sbit  P1_3    =   P1^3;
sbit  P1_2    =   P1^2;
sbit  P1_1    =   P1^1;
sbit  P1_0    =   P1^0;

sbit  CEX4    =   P1^7;
sbit  CEX3    =   P1^6;
sbit  CEX2    =   P1^5;
sbit  CEX1    =   P1^4;
sbit  CEX0    =   P1^3;
sbit  ECI     =   P1^2;


sfr  CKRL    =   0x97;			 

sfr  SCON    =   0x98;			 

sbit  SM0    =   SCON^7;
sbit  FE     =   SCON^7;
sbit  SM1    =   SCON^6;
sbit  SM2    =   SCON^5;
sbit  REN    =   SCON^4;
sbit  TB8    =   SCON^3;
sbit  RB8    =   SCON^2;
sbit  TI     =   SCON^1;
sbit  RI     =   SCON^0;

sfr  SBUF    =   0x99;			 


sfr  BRL     =   0x9A;			 

sfr  BDRCON  =   0x9B;                

sfr  AUXR1   =   0xA2;              

sfr  WDRST   =   0xA6;   
sfr  WDTPRG  =   0xA7;   



sfr  IE     =   0xA8;			     
sfr  IE0    =   0xA8;

sbit  EA     =   IE^7;
sbit  EC     =   IE^6;
/*  IE^5  RESERVED  DO NOT SET */
sbit  ES     =   IE^4;
sbit  ET1    =   IE^3;
sbit  EX1    =   IE^2;
sbit  ET0    =   IE^1;
sbit  EX0    =   IE^0;

sfr  SADDR   =   0xA9;			 

sfr  CKCON1  =   0xAF;              

sfr  P3      =   0xB0;			 

sbit  P3_7    =   P3^7;
sbit  P3_6    =   P3^6;
sbit  P3_5    =   P3^5;
sbit  P3_4    =   P3^4;
sbit  P3_3    =   P3^3;
sbit  P3_2    =   P3^2;
sbit  P3_1    =   P3^1;
sbit  P3_0    =   P3^0;


sbit  T0      =   P3^3;
sbit  INT0    =   P3^2;
sbit  TXD     =   P3^1;
sbit  RXD     =   P3^0;

sfr  IE1     =   0xB1;
			     
sfr  IPL1    =   0xB2;
sfr  IPH1    =   0xB3;


sfr  IPH     =   0xB7;			     
sfr  IPH0    =   0xB7;

sfr  IPL     =   0xB8;			     
sfr  IPL0    =   0xB8;

/*  IPL^7 RESERVED DO NOT SET   */
sbit  PPC      =   IPL^6;       /* DOC CONFLICT USE PPCL */
sbit  PPCL     =   IPL^6;  
/*  IPL^5 RESERVED DO NOT SET   */
sbit  PSL      =   IPL^4; 
sbit  PT1L     =   IPL^3;
sbit  PX1L     =   IPL^2;
sbit  PT0L     =   IPL^1; 
sbit  PX0L     =   IPL^0;


sfr  SADEN   =   0xB9;			 

sfr  P4      =   0xC0;			 

sbit  P4_7    =   P4^7;
sbit  P4_6    =   P4^6;
sbit  P4_5    =   P4^5;
sbit  P4_4    =   P4^4;
sbit  P4_3    =   P4^3;
sbit  P4_2    =   P4^2;
sbit  P4_1    =   P4^1;
sbit  P4_0    =   P4^0;

sbit  SPSCK   =   P4^6;
sbit  MOSI    =   P4^5;
sbit  MISO    =   P4^4;
sbit  INT1    =   P4^3;
sbit  SS      =   P4^2;
sbit  T1      =   P4^1;

sbit  AIN7    =   P4^7;
sbit  AIN6    =   P4^6;
sbit  AIN5    =   P4^5;
sbit  AIN4    =   P4^4;
sbit  AIN3    =   P4^3;
sbit  AIN2    =   P4^2;
sbit  AIN1    =   P4^1;
sbit  AIN0    =   P4^0;

sfr  SPCON    =   0xC3;		

sfr  SPSTA    =   0xC4;		

sfr  SPDAT    =   0xC5;		

sfr  PSW     =   0xD0;			 
sbit  CY     =   PSW^7;
sbit  AC     =   PSW^6;
sbit  F0     =   PSW^5;
sbit  RS1    =   PSW^4;
sbit  RS0    =   PSW^3;
sbit  OV     =   PSW^2;
sbit  UD     =   PSW^1;
sbit  P      =   PSW^0;

sfr  P1M1    =   0xD4;	
		 
sfr  P3M1    =   0xD5;			 

sfr  P4M1    =   0xD6;			 

sfr  CCON    =   0xD8;			 

sbit  CF      =   CCON^7;
sbit  CR      =   CCON^6;
sbit  CCF4    =   CCON^4;
sbit  CCF3    =   CCON^3;
sbit  CCF2    =   CCON^2;
sbit  CCF1    =   CCON^1;
sbit  CCF0    =   CCON^0;

sfr  CMOD    =   0xD9;			 

sfr  CCAPM0  =   0xDA;			 
sfr  CCAPM1  =   0xDB;			 
sfr  CCAPM2  =   0xDC;			 
sfr  CCAPM3  =   0xDD;			 
sfr  CCAPM4  =   0xDE;			 

sfr  ACC     =   0xE0;	

sfr  P1M2    =   0xE2;	
		 
sfr  P3M2    =   0xE4;			 

sfr  P4M2    =   0xE5;			 

		 

sfr  CL      =   0xE9;			 

sfr  CCAP0L  =   0xEA;			 

sfr  CCAP1L  =   0xEB;			 

sfr  CCAP2L  =   0xEC;			 

sfr  CCAP3L  =   0xED;			 

sfr  CCAP4L  =   0xEE;			 

sfr  CONF    =   0xEF;   

sfr  B       =   0xF0;

sfr  ADCLK   =   0xF2;	
		 
sfr  ADCON   =   0xF3;			 

sfr  ADDL    =   0xF4;			 

sfr  ADDH    =   0xF5;			 

sfr  ADCF    =   0xF6;

			 

sfr  CH      =   0xF9;			 

sfr  CCAP0H  =   0xFA;			 

sfr  CCAP1H  =   0xFB;			  

sfr  CCAP2H  =   0xFC;			 

sfr  CCAP3H  =   0xFD;			 

sfr  CCAP4H  =   0xFE;			 

#endif    
        

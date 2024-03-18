/*--------------------------------------------------------------------------
REG51EX.H

Header file for generic 80C51 and 80C31 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG51EX_H__
#define __REG51EX_H__

sfr	P0	=	0x80;
sfr	SP	=	0x81;
sfr	DPL0	=	0x82;
sfr	DPH0	=	0x83;
sfr	DPL1	=	0x84;
sfr	DPH1	=	0x85;
sfr	DPS	=	0x86;
sfr	PCON	=	0x87;

sfr	TCON	=	0x88;
sfr	TMOD	=	0x89;
sfr	TL0	=	0x8A;
sfr	TL1	=	0x8B;
sfr	TH0	=	0x8C;
sfr	TH1	=	0x8D;
sfr	CKCON	=	0x8E;
sfr	SPC_FNC	=	0x8F;

sfr	P1	=	0x90;
sfr	EXIF	=	0x91;

sfr	SCON0	=	0x98;
sfr	SBUF9	=	0x99;

sfr	P2	=	0xA0;
sfr	IE	=	0xA8;

sfr	P3	=	0xB0;
sfr	VERSION	=	0xBA;

sfr	IP	=	0xB8;
sfr	ADCALADR=	0xBA;
sfr	ADCALD	=	0xBB;

sfr	SCON1	=	0xC0;
sfr	SBUF1	=	0xC1;
sfr	ADDAT0	=	0xC2;
sfr	ADDAT1	=	0xC3;
sfr	ADDAT2	=	0xC4;
sfr	ADCON	=	0xC5;

sfr	T2CON	=	0xC8;
sfr	RCAP2L	=	0xCA;
sfr	RCAP2H	=	0xCB;
sfr	TL2	=	0xCC;
sfr	TH2	=	0xCD;

sfr	PSW	=	0xD0;

sfr	EICON	=	0xD8;
sfr	PWPS	=	0xDA;
sfr	PWDTA	=	0xDB;
sfr	PWDTB	=	0xDC;
sfr	WDT	=	0xDD;

sfr	ACC	=	0xE0;

sfr	EIE	=	0xE8;
sfr	EEAL	=	0xEA;
sfr	EEAH	=	0xEB;
sfr	EEDAT	=	0xEC;
sfr	EESTCMD	=	0xED;

sfr	B	=	0xF0;

sfr	EIP	=	0xF8;
sfr	PWMC	=	0xFE;

#endif	

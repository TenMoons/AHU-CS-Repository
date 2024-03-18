/*--------------------------------------------------------------------------
VERSA1.H

Header file for GOAL Semiconductor Versa 1
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __VERSA1_H__
#define __VERSA1_H__

/*  BYTE Registers  */
sfr SP 	= 0x81;
sfr DPL0 	= 0x82;
sfr DPH0 	= 0x83;
sfr DPL1 	= 0x84;
sfr DPH1 	= 0x85;
sfr DPS 	= 0x86;
sfr PCON 	= 0x87;
sfr TCON 	= 0x88;
sfr TMOD 	= 0x89;
sfr TL0 	= 0x8A;
sfr TL1 	= 0x8B;
sfr TH0 	= 0x8C;
sfr TH1 	= 0x8D;
sfr CKCON 	= 0x8E;
sfr SPC_FNC 	= 0x8F;
sfr EXIF 	= 0x91;
sfr MPAGE 	= 0x92;
sfr ADCCTRL 	= 0x94;
sfr BGAPCAL 	= 0x95;
sfr ADCALADR 	= 0x96;
sfr ADCALDAT 	= 0x97;
sfr SCON0 	= 0x98;
sfr SBUF0 	= 0x99;
sfr ADCSTAT 	= 0x9C;
sfr ADCD0LO 	= 0xA4;
sfr ADCD0HI 	= 0xA5;
sfr ADCD1LO 	= 0xA6;
sfr ADCD1HI 	= 0xA7;
sfr IE 	= 0xA8;
sfr ADCD2LO 	= 0xAC;
sfr ADCD2HI 	= 0xAD;
sfr ADCD3LO 	= 0xAE;
sfr ADCD3HI 	= 0xAF;
sfr SPICTRL 	= 0xB4;
sfr SPIRX 	= 0xB5;
sfr SPITX 	= 0xB6;
sfr SPIIE 	= 0xB7;
sfr IP 	= 0xB8;
sfr IOCTRL 	= 0xBA;
sfr IOREAD 	= 0xBB;
sfr SPIINTSTAT = 0xBC;
sfr SPIRXOVC 	= 0xBD;
sfr SCON1 	= 0xC0;
sfr SBUF1 	= 0xC1;
sfr MACACC0 	= 0xC4;
sfr MACACC1 	= 0xC5;
sfr MACACC2 	= 0xC6;
sfr MACACC3 	= 0xC7;
sfr T2CON 	= 0xC8;
sfr RCAP2L 	= 0xCA;
sfr RCAP2H 	= 0xCB;
sfr TL2 	= 0xCC;
sfr TH2 	= 0xCD;
sfr PSW 	= 0xD0;
sfr J17CTRL 	= 0xD7;
sfr EICON 	= 0xD8;
sfr J17PRIREG = 0xD9;
sfr J17IDLE 	= 0xDA;
sfr J17BDLO 	= 0xDB;
sfr J17BDHI 	= 0xDC;
sfr J17DATA 	= 0xDD;
sfr J17IE 	= 0xDE;
sfr J17INTSTAT = 0xDF;
sfr ACC 	= 0xE0;
sfr INTSRC 	= 0xE4;
sfr CLKDIV 	= 0xE5;
sfr MACA0 	= 0xE6;
sfr MACA1 	= 0xE7;
sfr EIE 	= 0xE8;
sfr MACRES0  = 0xEa;
sfr MACRES1  = 0xEb;
sfr MACRES2 	= 0xEC;
sfr MACRES3 	= 0xED;
sfr MACB0 	= 0xEe;
sfr MACB1 	= 0xEf;
sfr B 		= 0xF0;
sfr CONVRLO 	= 0xF5;
sfr CONVRMED 	= 0xF6;
sfr CONVRHI 	= 0xF7;
sfr EIP 	= 0xF8;
sfr PGACTRL 	= 0xF9;
sfr ISRC1 	= 0xFa;
sfr ISRC2 	= 0xFB;
sfr INMUX 	= 0xFC;
sfr OUTMUX 	= 0xFD;
sfr ADCCkDIV 	= 0xFE;


/*  BIT Registers  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit P     = PSW^0; 

/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  IE  */
sbit EA    = IE^7;
sbit ET2   = IE^5; 
sbit ES    = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;

/*  IP  */
sbit PT2   = IP^5;
sbit PS    = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;

/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;
#endif

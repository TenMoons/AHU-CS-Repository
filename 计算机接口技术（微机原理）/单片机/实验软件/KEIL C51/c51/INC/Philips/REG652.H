/*------------------------------------------------------------------
REG652.H
Header file for the Philips 80/83/87C652 & 80/83/87C654 
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG652_H__
#define __REG652_H__

/*  BYTE Registers  */
sfr P0     = 0x80;
sfr P1     = 0x90;
sfr P2     = 0xA0;
sfr P3     = 0xB0;
sfr PSW    = 0xD0;
sfr ACC    = 0xE0;
sfr B      = 0xF0;
sfr SP     = 0x81;
sfr DPL    = 0x82;
sfr DPH    = 0x83;
sfr PCON   = 0x87;
sfr TCON   = 0x88;
sfr TMOD   = 0x89;
sfr TL0    = 0x8A;
sfr TL1    = 0x8B;
sfr TH0    = 0x8C;
sfr TH1    = 0x8D;
sfr IE     = 0xA8;
sfr IP     = 0xB8;
sfr S0CON  = 0x98;
sfr S0BUF  = 0x99;
sfr S1CON  = 0xD8;
sfr S1STA  = 0xD9;
sfr S1DAT  = 0xDA;
sfr S1ADR  = 0xDB;

/*  BIT Registers  */
/*  PSW  */
sbit CY    = 0xD7;
sbit AC    = 0xD6;
sbit F0    = 0xD5;
sbit RS1   = 0xD4;
sbit RS0   = 0xD3;
sbit OV    = 0xD2;
sbit F1    = 0xD1;
sbit P     = 0xD0;

/*  TCON  */
sbit TF1   = 0x8F;
sbit TR1   = 0x8E;
sbit TF0   = 0x8D;
sbit TR0   = 0x8C;
sbit IE1   = 0x8B;
sbit IT1   = 0x8A;
sbit IE0   = 0x89;
sbit IT0   = 0x88;

/*  IE  */
sbit EA    = 0xAF;
sbit ES1   = 0xAD;
sbit ES0   = 0xAC;
sbit ET1   = 0xAB;
sbit EX1   = 0xAA;
sbit ET0   = 0xA9;
sbit EX0   = 0xA8;

/*  IP  */
sbit PS1   = 0xBD;
sbit PS0   = 0xBC;
sbit PT1   = 0xBB;
sbit PX1   = 0xBA;
sbit PT0   = 0xB9;
sbit PX0   = 0xB8;

/*  P0  */
sbit AD7   = 0x87;
sbit AD6   = 0x86;
sbit AD5   = 0x85;
sbit AD4   = 0x84;
sbit AD3   = 0x83;
sbit AD2   = 0x82;
sbit AD1   = 0x81;
sbit AD0   = 0x80;

/*  P1  */
sbit SDA   = 0x97;
sbit SCL   = 0x96;
             
/*  P3  */
sbit RD    = 0xB7;
sbit WR    = 0xB6;
sbit T1    = 0xB5;
sbit T0    = 0xB4;
sbit INT1  = 0xB3;
sbit INT0  = 0xB2;
sbit TXD   = 0xB1;
sbit RXD   = 0xB0;

/*  S0CON  */
sbit SM0   = 0x9F;
sbit SM1   = 0x9E;
sbit SM2   = 0x9D;
sbit REN   = 0x9C;
sbit TB8   = 0x9B;
sbit RB8   = 0x9A;
sbit TI    = 0x99;
sbit RI    = 0x98;

/* S1CON */
sbit CR2   = 0xDF;
sbit ENS1  = 0xDE;
sbit STA   = 0xDD;
sbit STO   = 0xDC;
sbit SI    = 0xDB;
sbit AA    = 0xDA;
sbit CR1   = 0xD9;
sbit CR0   = 0xD8;

#endif

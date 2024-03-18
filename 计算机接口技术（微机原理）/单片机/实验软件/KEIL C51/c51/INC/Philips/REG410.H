/*--------------------------------------------------------------------------
REG410.H

Header file for 8XCL410.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG410_H__
#define __REG410_H__

/*  BYTE Register  */
sfr P0   = 0x80;
sfr P1   = 0x90;
sfr P2   = 0xA0;
sfr P3   = 0xB0;
sfr PSW  = 0xD0;
sfr ACC  = 0xE0;
sfr B    = 0xF0;
sfr SP   = 0x81;
sfr DPL  = 0x82;
sfr DPH  = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TMOD = 0x89;
sfr TL0  = 0x8A;
sfr TL1  = 0x8B;
sfr TH0  = 0x8C;
sfr TH1  = 0x8D;
sfr IEN0 = 0xA8;
sfr IEN1 = 0xE8;
sfr IP0  = 0xB8;
sfr IP1  = 0xF8;
sfr IRQ1 = 0xC0;
sfr IX1  = 0xE9;
sfr S1ADR= 0xDB;
sfr S1CON= 0xD8;
sfr S1DAT= 0xDA;
sfr S1STA= 0xD9;


/*  BIT Register  */
/*  PSW   */
sbit CY   = 0xD7;
sbit AC   = 0xD6;
sbit F0   = 0xD5;
sbit RS1  = 0xD4;
sbit RS0  = 0xD3;
sbit OV   = 0xD2;
sbit P    = 0xD0;

/*  TCON  */
sbit TF1  = 0x8F;
sbit TR1  = 0x8E;
sbit TF0  = 0x8D;
sbit TR0  = 0x8C;
sbit IE1  = 0x8B;
sbit IT1  = 0x8A;
sbit IE0  = 0x89;
sbit IT0  = 0x88;

/*  IEN0   */
sbit EA   = 0xAF;
sbit ES1  = 0xAD;
sbit ET1  = 0xAB;
sbit EX1  = 0xAA;
sbit ET0  = 0xA9;
sbit EX0  = 0xA8;

/*  IEN1   */
sbit EX9  = 0xEF;
sbit EX8  = 0xEE;
sbit EX7  = 0xED;
sbit EX6  = 0xEC;
sbit EX5  = 0xEB;
sbit EX4  = 0xEA;
sbit EX3  = 0xE9;
sbit EX2  = 0xE8;

/*  IRQ1   */
sbit IQ9  = 0xC7;
sbit IQ8  = 0xC6;
sbit IQ7  = 0xC5;
sbit IQ6  = 0xC4;
sbit IQ5  = 0xC3;
sbit IQ4  = 0xC2;
sbit IQ3  = 0xC1;
sbit IQ2  = 0xC0;

/*  IP0   */ 
sbit PS1  = 0xBD;
sbit PT1  = 0xBB;
sbit PX1  = 0xBA;
sbit PT0  = 0xB9;
sbit PX0  = 0xB8;

/*  IP1   */ 
sbit PX9  = 0xFF;
sbit PX8  = 0xFE;
sbit PX7  = 0xFD;
sbit PX6  = 0xFC;
sbit PX5  = 0xFB;
sbit PX4  = 0xFA;
sbit PX3  = 0xF9;
sbit PX2  = 0xF8;

/*  P1  */
sbit INT9 = 0x97;
sbit SDA  = 0x97;
sbit INT8 = 0x96;
sbit SCL  = 0x96;
sbit INT7 = 0x95;
sbit INT6 = 0x94;
sbit INT5 = 0x93;
sbit INT4 = 0x92;
sbit INT3 = 0x91;
sbit INT2 = 0x90;

/*  P3  */
sbit RD   = 0xB7;
sbit WR   = 0xB6;
sbit T1   = 0xB5;
sbit T0   = 0xB4;
sbit INT1 = 0xB3;
sbit INT0 = 0xB2;

/*  S1CON  */
sbit ENS1 = 0xDE;
sbit STA  = 0xDD;
sbit STO  = 0xDC;
sbit SI   = 0xDB;
sbit AA   = 0xDA;
sbit CR1  = 0xD9;
sbit CR0  = 0xD8;

#endif

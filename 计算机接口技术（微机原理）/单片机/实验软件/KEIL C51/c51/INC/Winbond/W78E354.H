/*--------------------------------------------------------------------------
W78E354.H

Header file for Winbond W78E354/374 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __W78E354_H__
#define __W78E354_H__

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
sfr IE   = 0xA8;
sfr IP   = 0xB8;
sfr SCON = 0x98;
sfr SBUF = 0x99;

/* W78E354/374 */

sfr CONTREG1 = 0x80;
sfr CONTREG2 = 0x85;
sfr CONTREG3 = 0x86;
sfr CONTREG4 = 0xC8;
sfr CONTREG5 = 0x84;

sfr SDAC0    = 0xA1;
sfr SDAC1    = 0xA2;
sfr SDAC2    = 0xA3;
sfr SDAC3    = 0xA4;
sfr SDAC4    = 0xA5;
sfr SDAC5    = 0xA6;
sfr SDAC6    = 0xA7;
sfr SDAC7    = 0xA9;
sfr SDAC8    = 0xAA;
sfr SDAC9    = 0xAB;
sfr SDAC10   = 0xAC;
sfr SDAC11   = 0xAD;
sfr SDAC12   = 0xAE;
sfr SDAC13   = 0xAF;

sfr BSDAC0   = 0x9A;
sfr SBRM0    = 0xB9;
sfr BSDAC1   = 0x9B;
sfr SBRM1    = 0xBA;
sfr DDAC0    = 0x9D;
sfr DDAC1    = 0x9E;
sfr DDAC2    = 0x9F;
sfr BDDAC    = 0x96;
sfr DBRM     = 0x97;

sfr HFCOUNTL = 0xB4;
sfr HFCOUNTH = 0xB5;
sfr VFCOUNTL = 0xB6;
sfr VFCOUNTH = 0xB7;

sfr DHREG    = 0x92;
sfr DVREG    = 0x93;
sfr PARAL    = 0x8E;
sfr PARAH    = 0x8F;

sfr AUTOLOAD = 0x91;
sfr WDTCLR   = 0x9C;
sfr SOAREG   = 0xBC;
sfr SOACLR   = 0xBD;
sfr INTMSK   = 0x95;
sfr INTVECT  = 0xB2;
sfr STATUS   = 0xB3;
sfr ADC      = 0xB1;
sfr PORT4    = 0xBB;
sfr DDC1     = 0x94;
sfr S1CON    = 0xD8;
sfr S1STA    = 0xD9;
sfr S1DAT    = 0xDA;
sfr S1ADR    = 0xDB;


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

/*  IE   */
sbit EA   = 0xAF;
sbit ES   = 0xAC;
sbit ET1  = 0xAB;
sbit EX1  = 0xAA;
sbit ET0  = 0xA9;
sbit EX0  = 0xA8;

/*  IP   */ 
sbit PS   = 0xBC;
sbit PT1  = 0xBB;
sbit PX1  = 0xBA;
sbit PT0  = 0xB9;
sbit PX0  = 0xB8;

/*  P3  */
sbit RD   = 0xB7;
sbit WR   = 0xB6;
sbit T1   = 0xB5;
sbit T0   = 0xB4;
sbit INT1 = 0xB3;
sbit INT0 = 0xB2;
sbit TXD  = 0xB1;
sbit RXD  = 0xB0;

/*  SCON  */
sbit SM0  = 0x9F;
sbit SM1  = 0x9E;
sbit SM2  = 0x9D;
sbit REN  = 0x9C;
sbit TB8  = 0x9B;
sbit RB8  = 0x9A;
sbit TI   = 0x99;
sbit RI   = 0x98;

#endif

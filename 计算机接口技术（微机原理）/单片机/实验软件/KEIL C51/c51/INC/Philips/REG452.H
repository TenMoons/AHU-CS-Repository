/*--------------------------------------------------------------------------
REG452.H

Header file for 80C452.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG452_H__
#define __REG452_H__

/*  BYTE Registers  */
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

/*  80C452 Extensions  */
sfr P4    = 0xC0;
sfr SLCON = 0xE8;
sfr IEP   = 0xF8;
sfr DCON0 = 0x92;
sfr DCON1 = 0x93;
sfr SARL0 = 0xA2;
sfr SARH0 = 0xA3;
sfr SARL1 = 0xB2;
sfr SARH1 = 0xB3;
sfr DARL0 = 0xC2;
sfr DARH0 = 0xC3;
sfr DARL1 = 0xD2;
sfr DARH1 = 0xD3;
sfr BCRL0 = 0xE2;
sfr BCRH0 = 0xE3;
sfr HSTAT = 0xE6;
sfr HCON  = 0xE7;
sfr SSTAT = 0xE9;
sfr IWPR  = 0xEA;
sfr IRPR  = 0xEB;
sfr CBP   = 0xEC;
sfr FIN   = 0xEE;
sfr CIN   = 0xEF;
sfr BCRL1 = 0xF2;
sfr BCRH1 = 0xF3;
sfr ITHR  = 0xF6;
sfr OTHR  = 0xF7;
sfr MODE  = 0xF9;
sfr ORPR  = 0xFA;
sfr OWPR  = 0xFB;
sfr IMIN  = 0xFC;
sfr IMOUT = 0xFD;
sfr FOUT  = 0xFE;
sfr COUT  = 0xFF;


/*  BIT Registers  */
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

/*  80C452 Extensions  */
/*  P1  */
sbit HLDA = 0x96;
sbit HLD  = 0x95;

/*  SLCON  */
sbit IFI  = 0xEF;
sbit OFI  = 0xEE;
sbit ICII = 0xED;
sbit ICOI = 0xEC;
sbit FRZ  = 0xEB;
sbit IFRS = 0xE9;
sbit OFRS = 0xE8;

/*  IEP  */
sbit PFIFO = 0xFD;
sbit EDMA0 = 0xFC;
sbit EDMA1 = 0xFB;
sbit PDMA0 = 0xFA;
sbit PDMA1 = 0xF9;
sbit EFIFO = 0xF8;

#endif

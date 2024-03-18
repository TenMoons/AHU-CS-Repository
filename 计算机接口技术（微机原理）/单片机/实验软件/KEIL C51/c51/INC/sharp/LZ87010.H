/*--------------------------------------------------------------------------
LZ87010.H

Header file for sharp LZ87010 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __LZ87010_H__
#define __LZ87010_H__

/*  BYTE Registers  */
sfr PORT0    = 0x80;
sfr PORT1    = 0x90;
sfr PORT5    = 0x91;
sfr PORT8    = 0x93;
sfr CLKCFG   = 0x94;
sfr ALTFEN1  = 0x94;
sfr FLASHCFG = 0x96;
sfr FLASHTB  = 0x97;
sfr PORT2    = 0xA0;
sfr T5CON    = 0xA1;
sfr T5STA    = 0xA2;
sfr T5CMP    = 0xA3;
sfr T5CMP0L  = 0xA4;
sfr T5CMP0H  = 0xA5;
sfr T5CMP1L  = 0xA6;
sfr T5CMP1H  = 0xA7;
sfr PORT9    = 0xA9;
sfr WDTCTL   = 0xAC;
sfr WDTCNT   = 0xAD;
sfr T5CNTL   = 0xAE;
sfr T5CNTH   = 0xAF;
sfr PORT3    = 0xB0;
sfr TCMPOE   = 0xB3;
sfr ICCON    = 0xB4;
sfr ICSAR    = 0xB5;
sfr ICUSAR   = 0xB6;
sfr ICDATA   = 0xB7;
sfr ICHCNT   = 0xBC;
sfr ICFCNT   = 0xBD;
sfr ICDBUG   = 0xBE;
sfr ICSTAT   = 0xBF;
sfr PORT6    = 0xC0;
sfr ADCDL    = 0xC1;
sfr ADCDH    = 0xC2;
sfr ADCC     = 0xC3;
sfr DACC     = 0xC4;
sfr XMCFG    = 0xC5;
sfr BRGCNTL  = 0xC6;
sfr BRGCNTH  = 0xC7;
sfr SCON1    = 0xC8;
sfr SBUF1    = 0xC9;
sfr WGCTL0   = 0xCA;
sfr WGCTL1   = 0xCB;
sfr WGCFG0   = 0xCC;
sfr WGCFG1   = 0xCD;
sfr WGINX0   = 0xCE;
sfr WGINX1   = 0xCF;
sfr T2CON    = 0xD1;
sfr T2STA    = 0xD2;
sfr T2CMP    = 0xD3;
sfr T2CMP0L  = 0xD4;
sfr T2CMP0H  = 0xD5;
sfr T2CMP1L  = 0xD6;
sfr T2CMP1H  = 0xD7;
sfr PORT7    = 0xD8;
sfr T2CAP    = 0xD9;
sfr T2CAP0L  = 0xDA;
sfr T2CAP0H  = 0xDB;
sfr T2CAP1L  = 0xDC;
sfr T2CAP1H  = 0xDD;
sfr T2CNTL   = 0xDE;
sfr T2CNTH   = 0xDF;
sfr T3CON    = 0xE1;
sfr T3STA    = 0xE2;
sfr T3CMP    = 0xE3;
sfr T3CMP0L  = 0xE4;
sfr T3CMP0H  = 0xE5;
sfr T3CMP1L  = 0xE6;
sfr T3CMP1H  = 0xE7;
sfr T3CAP    = 0xE9;
sfr T3CAP0L  = 0xEA;
sfr T3CAP0H  = 0xEB;
sfr T3CAP1L  = 0xEC;
sfr T3CAP1H  = 0xED;
sfr T3CNTL   = 0xEE;
sfr T3CNTH   = 0xEF;
sfr T4CON    = 0xF1;
sfr T4STA    = 0xF2;
sfr T4CMP    = 0xF3;
sfr T4CMP0L  = 0xF4;
sfr T4CMP0H  = 0xF5;
sfr T4CMP1L  = 0xF6;
sfr T4CMP1H  = 0xF7;
sfr WGMA0    = 0xFA;
sfr WGMD0    = 0xFB;
sfr WGMA1    = 0xFC;
sfr WGMD1    = 0xFD;
sfr T4CNTL   = 0xFE;
sfr T4CNTH   = 0xFF;

sfr PSW   = 0xD0;
sfr ACC   = 0xE0;
sfr B     = 0xF0;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr PCON  = 0x87;
sfr TCON  = 0x88;
sfr TMOD  = 0x89;
sfr TL0   = 0x8A;
sfr TL1   = 0x8B;
sfr TH0   = 0x8C;
sfr TH1   = 0x8D;
sfr IE    = 0xA8;
sfr IP    = 0xB8;
sfr SCON  = 0x98;
sfr SBUF  = 0x99;

/*  BIT Registers  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit P     = PSW^0; //8052 only

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
sbit ET2   = IE^5; //8052 only
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

/*  PORT3  */
sbit RD    = PORT3^7;
sbit WR    = PORT3^6;
sbit T1    = PORT3^5;
sbit T0    = PORT3^4;
sbit INT1  = PORT3^3;
sbit INT0  = PORT3^2;
sbit TXD   = PORT3^1;
sbit RXD   = PORT3^0;

/*  SCON  */
sbit SM0   = SCON^7;
sbit SM1   = SCON^6;
sbit SM2   = SCON^5;
sbit REN   = SCON^4;
sbit TB8   = SCON^3;
sbit RB8   = SCON^2;
sbit TI    = SCON^1;
sbit RI    = SCON^0;

/*  P1  */
sbit T2EX  = PORT1^1;
sbit T2    = PORT1^0; 

#endif
            

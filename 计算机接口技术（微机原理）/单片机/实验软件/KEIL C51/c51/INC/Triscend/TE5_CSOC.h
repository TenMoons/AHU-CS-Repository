/*--------------------------------------------------------------------------
TE5_CSOC.H

Header file for Triscend E5 CSoC Device Common.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __TE5_CSOC_H__
#define __TE5_CSOC_H__


/***************************************************************************
 * BYTE Registers
 ***************************************************************************
 */
/* Unused SFR locations [0x80,0xff] are available for use by a soft module. */
//sfr P0    =   0x80;   /* to be exported and implemented in CSL */
sfr SP      =   0x81;
sfr DPL     =   0x82;
sfr DPH     =   0x83;
sfr DPL1    =   0x84;
sfr DPH1    =   0x85;
sfr DPS     =   0x86;
sfr PCON    =   0x87;
sfr TCON    =   0x88;
sfr TMOD    =   0x89;
sfr TL0     =   0x8a;
sfr TL1     =   0x8b;
sfr TH0     =   0x8c;
sfr TH1     =   0x8d;
sfr CKCON   =   0x8e;
/* unused: 0x8f */
//sfr P1    =   0x90;   /* to be exported and implemented in CSL */
/* unused: [0x91,0x97] */
sfr SCON    =   0x98;
sfr SBUF    =   0x99;
/* unused: [0x9a,0x9f] */
//sfr P2    =   0xa0;   /* to be exported and implemented in CSL */
/* unused: [0xa1,0xa7] */
sfr IE      =   0xa8;
sfr SADDR   =   0xa9;
/* unused: [0xaa,0xaf] */
//sfr P3    =   0xb0;   /* to be exported and implemented in CSL */
/* unused: [0xb1,0xb7] */
sfr IP      =   0xb8;
sfr SADEN   =   0xb9;
/* unused: [0xba,0xbf] */
/* unused: [0xc0,0xc6] */
sfr TA      =   0xc7;
sfr T2CON   =   0xc8;
sfr T2MOD   =   0xc9;
sfr RCAP2L  =   0xca;
sfr RCAP2H  =   0xcb;
sfr TL2     =   0xcc;
sfr TH2     =   0xcd;
/* unused: [0xce,0xcf] */
sfr PSW     =   0xd0;
/* unused: [0xd1,0xd7] */
sfr WDCON   =   0xd8;
/* unused: [0xd9,0xdf] */
sfr ACC     =   0xe0;
/* unused: [0xe1,0xe7] */
sfr EIE     =   0xe8;
/* unused: [0xe9,0xef] */
sfr B       =   0xf0;
/* unused: [0xf1,0xf7] */
sfr EIP     =   0xf8;
/* unused: [0xf9,0xff] */

/***************************************************************************
 * BIT Registers
 ***************************************************************************
 */
/* Unused bits of the following SFR locations are reserved. */
/* P0:     [0x80,0x87] */
/* TCON:   [0x88,0x8f] */
sbit IT0     =   0x88;
sbit IE0     =   0x89;
sbit IT1     =   0x8a;
sbit IE1     =   0x8b;
sbit TR0     =   0x8c;
sbit TF0     =   0x8d;
sbit TR1     =   0x8e;
sbit TF1     =   0x8f;
/* P1:     [0x90,0x97] */
/* SCON:   [0x98,0x9f] */
sbit RI      =   0x98;
sbit TI      =   0x99;
sbit RB8     =   0x9a;
sbit TB8     =   0x9b;
sbit REN     =   0x9c;
sbit SM2     =   0x9d;
sbit SM1     =   0x9e;
sbit SM0_FE  =   0x9f;
/* P2:     [0xa0,0xa7] */
/* IE:     [0xa8,0xaf] */
sbit EX0     =   0xa8;
sbit ET0     =   0xa9;
sbit EX1     =   0xaa;
sbit ET1     =   0xab;
sbit ES      =   0xac;
sbit ET2     =   0xad;
/* unused:       0xae; */
sbit EA      =   0xaf;
/* P3:     [0xb0,0xb7] */
/* IP:     [0xb8,0xbf] */
sbit PX0     =   0xb8;
sbit PT0     =   0xb9;
sbit PX1     =   0xba;
sbit PT1     =   0xbb;
sbit PS      =   0xbc;
sbit PT2     =   0xbd;
/*               0xbe; */
/*               0xbf; */
/* unused: [0xc0,0xc7] */
/* T2CON:  [0xc8,0xcf] */
sbit CP_RL2  =   0xc8;
sbit C_T2    =   0xc9;
sbit TR2     =   0xca;
sbit EXEN2   =   0xcb;
sbit TCLK    =   0xcc;
sbit RCLK    =   0xcd;
sbit EXF2    =   0xce;
sbit TF2     =   0xcf;
/* PSW:    [0xd0,0xd7] */
sbit P       =   0xd0;
sbit F1      =   0xd1;
sbit OV      =   0xd2;
sbit RS0     =   0xd3;
sbit RS1     =   0xd4;
sbit F0      =   0xd5;
sbit AC      =   0xd6;
sbit CY      =   0xd7;
/* WDCON:  [0xd8,0xdf] */
sbit RWT     =   0xd8;
sbit EWT     =   0xd9;
sbit WTRF    =   0xda;
sbit WDIF    =   0xdb;
sbit HPI     =   0xdc;
sbit EHPI    =   0xdd;
sbit POR     =   0xde;
/*               0xdf; */
/* ACC:    [0xe0,0xe7] */
/* EIE:    [0xe8,0xef] */
sbit EWDI    =   0xec;
/* B:      [0xf0,0xf7] */
/* EIP     [0xf8,0xff] */
sbit PWDI    =   0xfc;


/***************************************************************************
 * E5 Configuration Register Unit (CRU) defintions
 ***************************************************************************
 */

/* All addresses in the range [0xff00,0xffff] are reserved */
#define CMAP0_TAR	(*((unsigned char volatile xdata*) 0xff00))
#define CMAP0_ALT	(*((unsigned char volatile xdata*) 0xff01))
#define CMAP1_TAR_0	(*((unsigned char volatile xdata*) 0xff02))
#define CMAP1_TAR_1	(*((unsigned char volatile xdata*) 0xff03))
#define CMAP1_TAR_2	(*((unsigned char volatile xdata*) 0xff04))
#define CMAP1_SRC	(*((unsigned char volatile xdata*) 0xff05))
#define CMAP1_CTL	(*((unsigned char volatile xdata*) 0xff06))
#define CMAP1_ALT	(*((unsigned char volatile xdata*) 0xff07))
#define CMAP2_TAR_0	(*((unsigned char volatile xdata*) 0xff08))
#define CMAP2_TAR_1	(*((unsigned char volatile xdata*) 0xff09))
#define CMAP2_TAR_2	(*((unsigned char volatile xdata*) 0xff0a))
#define CMAP2_SRC	(*((unsigned char volatile xdata*) 0xff0b))
#define CMAP2_CTL	(*((unsigned char volatile xdata*) 0xff0c))
#define CMAP2_ALT	(*((unsigned char volatile xdata*) 0xff0d))
#define DMAP0_TAR	(*((unsigned char volatile xdata*) 0xff0e))
#define DMAP1_TAR_0	(*((unsigned char volatile xdata*) 0xff0f))
#define DMAP1_TAR_1	(*((unsigned char volatile xdata*) 0xff10))
#define DMAP1_TAR_2	(*((unsigned char volatile xdata*) 0xff11))
#define DMAP1_SRC	(*((unsigned char volatile xdata*) 0xff12))
#define DMAP1_CTL	(*((unsigned char volatile xdata*) 0xff13))
#define DMAP2_TAR_0	(*((unsigned char volatile xdata*) 0xff14))
#define DMAP2_TAR_1	(*((unsigned char volatile xdata*) 0xff15))
#define DMAP2_TAR_2	(*((unsigned char volatile xdata*) 0xff16))
#define DMAP2_SRC	(*((unsigned char volatile xdata*) 0xff17))
#define DMAP2_CTL	(*((unsigned char volatile xdata*) 0xff18))
#define DMAP3_TAR	(*((unsigned char volatile xdata*) 0xff19))
#define DMAP3_SRC	(*((unsigned char volatile xdata*) 0xff1a))
#define DMAP3_CTL	(*((unsigned char volatile xdata*) 0xff1b))
/* reserved: [0xff1c,0xff1f] */
#define DMASADR0_0	(*((unsigned char volatile xdata*) 0xff20))
#define DMASADR0_1	(*((unsigned char volatile xdata*) 0xff21))
#define DMASADR0_2	(*((unsigned char volatile xdata*) 0xff22))
#define DMASADR0_3	(*((unsigned char volatile xdata*) 0xff23))
#define DMASCNT0_0	(*((unsigned char volatile xdata*) 0xff24))
#define DMASCNT0_1	(*((unsigned char volatile xdata*) 0xff25))
#define DMASCNT0_2	(*((unsigned char volatile xdata*) 0xff26))
#define DMACTRL0_0	(*((unsigned char volatile xdata*) 0xff27))
#define DMACTRL0_1	(*((unsigned char volatile xdata*) 0xff28))
#define DMAEINT0	(*((unsigned char volatile xdata*) 0xff29))
#define DMAINT0     (*((unsigned char volatile xdata*) 0xff2a))
#define DMACADR0_0	(*((unsigned char volatile xdata*) 0xff2b))
#define DMACADR0_1	(*((unsigned char volatile xdata*) 0xff2c))
#define DMACADR0_2	(*((unsigned char volatile xdata*) 0xff2d))
#define DMACADR0_3	(*((unsigned char volatile xdata*) 0xff2e))
#define DMACCNT0_0	(*((unsigned char volatile xdata*) 0xff2f))
#define DMACCNT0_1	(*((unsigned char volatile xdata*) 0xff30))
#define DMACCNT0_2	(*((unsigned char volatile xdata*) 0xff31))
#define DMAPREQ0_0	(*((unsigned char volatile xdata*) 0xff32))
#define DMAPREQ0_1	(*((unsigned char volatile xdata*) 0xff33))
#define DMASADR1_0	(*((unsigned char volatile xdata*) 0xff34))
#define DMASADR1_1	(*((unsigned char volatile xdata*) 0xff35))
#define DMASADR1_2	(*((unsigned char volatile xdata*) 0xff36))
#define DMASADR1_3	(*((unsigned char volatile xdata*) 0xff37))
#define DMASCNT1_0	(*((unsigned char volatile xdata*) 0xff38))
#define DMASCNT1_1	(*((unsigned char volatile xdata*) 0xff39))
#define DMASCNT1_2	(*((unsigned char volatile xdata*) 0xff3a))
#define DMACTRL1_0	(*((unsigned char volatile xdata*) 0xff3b))
#define DMACTRL1_1	(*((unsigned char volatile xdata*) 0xff3c))
#define DMAEINT1	(*((unsigned char volatile xdata*) 0xff3d))
#define DMAINT1  	(*((unsigned char volatile xdata*) 0xff3e))
#define DMACADR1_0	(*((unsigned char volatile xdata*) 0xff3f))
#define DMACADR1_1	(*((unsigned char volatile xdata*) 0xff40))
#define DMACADR1_2	(*((unsigned char volatile xdata*) 0xff41))
#define DMACADR1_3	(*((unsigned char volatile xdata*) 0xff42))
#define DMACCNT1_0	(*((unsigned char volatile xdata*) 0xff43))
#define DMACCNT1_1	(*((unsigned char volatile xdata*) 0xff44))
#define DMACCNT1_2	(*((unsigned char volatile xdata*) 0xff45))
#define DMAPREQ1_0	(*((unsigned char volatile xdata*) 0xff46))
#define DMAPREQ1_1	(*((unsigned char volatile xdata*) 0xff47))
#define DMACRC_0	(*((unsigned char volatile xdata*) 0xff48))
#define DMACRC_1	(*((unsigned char volatile xdata*) 0xff49))
/* reserved: [0xff4a,0xff5f] */
#define PROTECT  	(*((unsigned char volatile xdata*) 0xff60))
#define SECURITY	(*((unsigned char volatile xdata*) 0xff61))
#define PWDSEL  	(*((unsigned char volatile xdata*) 0xff62))
#define PORCTRL 	(*((unsigned char volatile xdata*) 0xff63))
/* reserved: [0xff64,0xff7f] */
#define DMAP4_TAR_0	(*((unsigned char volatile xdata*) 0xff80))
#define DMAP4_TAR_1	(*((unsigned char volatile xdata*) 0xff81))
#define DMAP4_TAR_2	(*((unsigned char volatile xdata*) 0xff82))
#define DMAP4_SRC	(*((unsigned char volatile xdata*) 0xff83))
#define DMAP4_CTL	(*((unsigned char volatile xdata*) 0xff84))
#define DMAP5_TAR_0	(*((unsigned char volatile xdata*) 0xff85))
#define DMAP5_TAR_1	(*((unsigned char volatile xdata*) 0xff86))
#define DMAP5_TAR_2	(*((unsigned char volatile xdata*) 0xff87))
#define DMAP5_SRC	(*((unsigned char volatile xdata*) 0xff88))
#define DMAP5_CTL	(*((unsigned char volatile xdata*) 0xff89))
/* reserved: [0xff8a,0xffff] */

#endif 

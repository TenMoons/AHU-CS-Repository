/*--------------------------------------------------------------------------
REG530.H

Header file for DS87C520/DS83C520 and DS87C530/DS83C530.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG530_H__
#define __REG530_H__

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
sfr SCON0  = 0x98;
sfr SBUF0  = 0x99;

/*  DS8xC520/530 Extensions  */
sfr DPL1   = 0x84;
sfr DPH1   = 0x85;
sfr DPS    = 0x86;
sfr CKCON  = 0x8E;
sfr EXIF   = 0x91;
sfr TRIM   = 0x96;   /* 8xC530 only! */
sfr SADDR0 = 0xA9;
sfr SADDR1 = 0xAA;
sfr SADEN0 = 0xB9;
sfr SADEN1 = 0xBA;
sfr SCON1  = 0xC0;
sfr SBUF1  = 0xC1;
sfr ROMSIZE = 0xC2;
sfr PMR    = 0xC4;
sfr STATUS = 0xC5;
sfr TA     = 0xC7;
sfr T2CON  = 0xC8;
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;
sfr WDCON  = 0xD8;
sfr EIE    = 0xE8;
sfr RTASS  = 0xF2;  /* 8xC530 only! */
sfr RTAS   = 0xF3;  /* 8xC530 only! */
sfr RTAM   = 0xF4;  /* 8xC530 only! */
sfr RTAH   = 0xF5;  /* 8xC530 only! */
sfr EIP    = 0xF8;
sfr RTCC   = 0xF9;  /* 8xC530 only! */
sfr RTCSS  = 0xFA;  /* 8xC530 only! */
sfr RTCS   = 0xFB;  /* 8xC530 only! */
sfr RTCM   = 0xFC;  /* 8xC530 only! */
sfr RTCH   = 0xFD;  /* 8xC530 only! */
sfr RTCD0  = 0xFE;  /* 8xC530 only! */
sfr RTCD1  = 0xFF;  /* 8xC530 only! */


/*  BIT Registers  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit FL    = PSW^1;
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
sbit ES1   = IE^6;
sbit ET2   = IE^5;
sbit ES0   = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;

/*  IP  */
sbit PS1   = IP^6;
sbit PT2   = IP^5;
sbit PS0   = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;

/*  P1  */
sbit INT5  = P1^7;
sbit INT4  = P1^6;
sbit INT3  = P1^5;
sbit INT2  = P1^4;
sbit TXD1  = P1^3;
sbit RXD1  = P1^2;
sbit T2EX  = P1^1;
sbit T2    = P1^0;

/*  P3  */
sbit RD    = P3^7;
sbit WR    = P3^6;
sbit T1    = P3^5;
sbit T0    = P3^4;
sbit INT1  = P3^3;
sbit INT0  = P3^2;
sbit TXD0  = P3^1;
sbit RXD0  = P3^0;

/*  SCON0  */
sbit SM0   = SCON0^7; /* Alternate SM0_FE0 */
sbit SM1   = SCON0^6; /* Alternate SM10 */
sbit SM2   = SCON0^5; /* Alternate SM20 */
sbit REN   = SCON0^4; /* Alternate REN0 */
sbit TB8   = SCON0^3; /* Alternate TB80 */
sbit RB8   = SCON0^2; /* Alternate RB80 */
sbit TI    = SCON0^1; /* Alternate TI0  */
sbit RI    = SCON0^0; /* Alternate RI0  */

/*  SCON1  */
sbit SM01  = SCON1^7;
sbit SM11  = SCON1^6;
sbit SM21  = SCON1^5;
sbit REN1  = SCON1^4;
sbit TB81  = SCON1^3;
sbit RB81  = SCON1^2;
sbit TI1   = SCON1^1;
sbit RI1   = SCON1^0;

/*  T2CON  */
sbit TF2   = T2CON^7;
sbit EXF2  = T2CON^6;
sbit RCLK  = T2CON^5;
sbit TCLK  = T2CON^4;
sbit EXEN2 = T2CON^3;
sbit TR2   = T2CON^2;
sbit C_T2  = T2CON^1;
sbit CP_RL2= T2CON^0;

/*  WDCON  */
sbit SMOD  = WDCON^7;
sbit POR   = WDCON^6;
sbit EPFI  = WDCON^5;
sbit PFI   = WDCON^4;
sbit WDIF  = WDCON^3;
sbit WTRF  = WDCON^2;
sbit EWT   = WDCON^1;
sbit RWT   = WDCON^0;

/*  EIE  */
sbit ERTCI = EIE^5;  /* 8xC530 only! */
sbit EWDI  = EIE^4;
sbit EX5   = EIE^3;
sbit EX4   = EIE^2;
sbit EX3   = EIE^1;
sbit EX2   = EIE^0;

/*  EIP  */
sbit PRTCI = EIP^5;  /* 8xC530 only! */
sbit PWDI  = EIP^4;
sbit PX5   = EIP^3;
sbit PX4   = EIP^2;
sbit PX3   = EIP^1;
sbit PX2   = EIP^0;

#endif

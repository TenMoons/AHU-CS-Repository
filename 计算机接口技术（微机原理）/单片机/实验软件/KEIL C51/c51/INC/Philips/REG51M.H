/*--------------------------------------------------------------------------
REG51M.H

Header file for Philips 8xC51MA2 & 8xC51MB2 devices
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG51M_H__
#define __REG51M_H__


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
sfr IEN0   = 0xA8;
sfr IEN1   = 0xE8;
sfr IP     = 0xB8;
sfr SCON   = 0x98;
sfr S0CON  = 0x98;
sfr SBUF   = 0x99;
sfr S0BUF  = 0x99;

/*  80C51Fx/Rx Extensions  */
sfr AUXR   = 0x8E;
sfr AUXR1  = 0xA2;
sfr S0ADDR = 0xA9;
sfr IPH    = 0xB7;
sfr S0ADEN = 0xB9;
sfr T2CON  = 0xC8;
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;
sfr CCON   = 0xD8;
sfr CMOD   = 0xD9;
sfr CCAPM0 = 0xDA;
sfr CCAPM1 = 0xDB;
sfr CCAPM2 = 0xDC;
sfr CCAPM3 = 0xDD;
sfr CCAPM4 = 0xDE;
sfr CL     = 0xE9;
sfr CCAP0L = 0xEA;
sfr CCAP1L = 0xEB;
sfr CCAP2L = 0xEC;
sfr CCAP3L = 0xED;
sfr CCAP4L = 0xEE;
sfr CH     = 0xF9;
sfr CCAP0H = 0xFA;
sfr CCAP1H = 0xFB;
sfr CCAP2H = 0xFC;
sfr CCAP3H = 0xFD;
sfr CCAP4H = 0xFE;

/* 80C51MA/MB Extensions */
sfr BRGR0  = 0x186;
sfr BRGR1  = 0x187;
sfr BRGCON = 0x185;
sfr EPL    = 0x1FC;
sfr EPM    = 0x1FD;
sfr EPH    = 0x1FE;
sfr MXCON  = 0x1FF;
sfr S0STAT = 0x18C;
sfr S1CON  = 0x180;
sfr S1BUF  = 0x181;
sfr S1ADDR = 0x182;
sfr S1STAT = 0x184;
sfr SPE    = 0x1FB;
sfr WDCON  = 0x18F;
sfr WDTRST = 0xA6;
sfr IP0    = 0xB8;
sfr IP1	   = 0xF8;
sfr IP0H   = 0xB7;
sfr IP1H   = 0xF7;
sfr P4     = 0x1C0;

/*  BIT Registers  */

/*  PSW   */
sbit CY   = PSW^7;
sbit AC   = PSW^6;
sbit F0   = PSW^5;
sbit RS1  = PSW^4;
sbit RS0  = PSW^3;
sbit OV   = PSW^2;
sbit P    = PSW^0;

/*  TCON  */
sbit TF1  = TCON^7;
sbit TR1  = TCON^6;
sbit TF0  = TCON^5;
sbit TR0  = TCON^4;
sbit IE1  = TCON^3;
sbit IT1  = TCON^2;
sbit IE0  = TCON^1;
sbit IT0  = TCON^0;

/*  IEN0   */
sbit EA   = IEN0^7;
sbit EC   = IEN0^6;
sbit ET2  = IEN0^5;
sbit ES   = IEN0^4;
sbit ET1  = IEN0^3;
sbit EX1  = IEN0^2;
sbit ET0  = IEN0^1;
sbit EX0  = IEN0^0;

/*  IEN1   */
sbit ESPI = IEN1^3;
sbit ES1T = IEN1^2;
sbit ES0T = IEN1^1;
sbit ES1  = IEN1^0;
sbit ES1R = IEN1^0;

/*  IP   */ 
sbit PPC  = IP^6;
sbit PT2  = IP^5;
sbit PS   = IP^4;
sbit PT1  = IP^3;
sbit PX1  = IP^2;
sbit PT0  = IP^1;
sbit PX0  = IP^0;

/*  IP1   */ 
sbit PSPI  = IP1^3;
sbit PS1T  = IP1^2;
sbit PS0T  = IP1^1;
sbit PS1   = IP1^0;

/*  P3  */
sbit RD   = P3^7;
sbit WR   = P3^6;
sbit T1   = P3^5;
sbit T0   = P3^4;
sbit INT1 = P3^3;
sbit INT0 = P3^2;
sbit TXD  = P3^1;
sbit RXD  = P3^0;

/*  P4  */
sbit TXD1 = P4^1;
sbit RXD1 = P4^0;

/*  SCON  */
sbit SM0  = SCON^7; // alternatively "FE"
sbit FE   = SCON^7;
sbit SM1  = SCON^6;
sbit SM2  = SCON^5;
sbit REN  = SCON^4;
sbit TB8  = SCON^3;
sbit RB8  = SCON^2;
sbit TI   = SCON^1;
sbit RI   = SCON^0;
             
/*  P1  */
sbit CEX4 = P1^7;
sbit CEX3 = P1^6;
sbit CEX2 = P1^5;
sbit CEX1 = P1^4;
sbit CEX0 = P1^3;
sbit ECI  = P1^2;
sbit T2EX = P1^1;
sbit T2   = P1^0;

/*  T2CON  */
sbit TF2   = T2CON^7;
sbit EXF2  = T2CON^6;
sbit RCLK  = T2CON^5;
sbit TCLK  = T2CON^4;
sbit EXEN2 = T2CON^3;
sbit TR2   = T2CON^2;
sbit C_T2  = T2CON^1;
sbit CP_RL2= T2CON^0;

/*  CCON  */
sbit CF    = CCON^7;
sbit CR    = CCON^6;
sbit CCF4  = CCON^4;
sbit CCF3  = CCON^3;
sbit CCF2  = CCON^2;
sbit CCF1  = CCON^1;
sbit CCF0  = CCON^0;

#endif

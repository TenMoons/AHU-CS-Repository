/*--------------------------------------------------------------------------
RegCE560.H

Header file for Philips P8xCE560 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __RegCE560_H__
#define __RegCE560_H__

/*  BYTE Registers ordered by Address */
sfr P0    = 0x80;
sfr SP    = 0x81;
sfr DPL   = 0x82;
sfr DPH   = 0x83;
sfr ADRSL0= 0x86;
sfr PCON  = 0x87;
sfr TCON  = 0x88;
sfr TMOD  = 0x89;
sfr TL0   = 0x8A;
sfr TL1   = 0x8B;
sfr TH0   = 0x8C;
sfr TH1   = 0x8D;
sfr P0    = 0x90;
sfr ADRSL1= 0x96;
sfr S0CON = 0x98;
sfr S0BUF = 0x99;
sfr P2    = 0xA0;
sfr ADRSL2= 0xA6;
sfr IEN0  = 0xA8;
sfr CML0  = 0xA9;
sfr CML1  = 0xAA;
sfr CML2  = 0xAB;
sfr CTL0  = 0xAC;
sfr CTL1  = 0xAD;
sfr CTL2  = 0xAE;
sfr CTL3  = 0xAF;
sfr P3    = 0xB0;
sfr ADRSL3= 0xB6;
sfr IP0   = 0xB8;
sfr P4    = 0xC0;
sfr ADRSL4= 0xC6;
sfr P5    = 0xC7;
sfr TM2IR = 0xC8;
sfr CMH0  = 0xC9;
sfr CMH1  = 0xCA;
sfr CMH2  = 0xCB;
sfr CTH0  = 0xCC;
sfr CTH1  = 0xCD;
sfr CTH2  = 0xCE;
sfr CTH3  = 0xCF;
sfr PSW   = 0xD0;
sfr ADRSL5= 0xD6;
sfr ADCON = 0xD7;
sfr S1CON = 0xD8;
sfr S1STA = 0xD9;
sfr S1DAT = 0xDA;
sfr S1ADR = 0xDB;
sfr ACC   = 0xE0;
sfr ADRSL6= 0xE6;
sfr ADPSS = 0xE7;
sfr IEN1  = 0xE8;
sfr TM2CON= 0xEA;
sfr CTCON = 0xEB;
sfr TML2  = 0xEC;
sfr TMH2  = 0xED;
sfr STE   = 0xEE;
sfr RTE   = 0xEF;
sfr B     = 0xF0;
sfr ADRSL7= 0xF6;
sfr ADRSH = 0xF7;
sfr IP1   = 0xF8;
sfr PLLCON= 0xF9;
sfr XRAMP = 0xFA;
sfr PWM0  = 0xFC;
sfr PWM1  = 0xFD;
sfr PWMP  = 0xFE;
sfr T3    = 0xFF;

//**************************************************

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

/*  P3  */
sbit RD    = P3^7;
sbit WR    = P3^6;
sbit T1    = P3^5;
sbit T0    = P3^4;
sbit INT1  = P3^3;
sbit INT0  = P3^2;
sbit TXD   = P3^1;
sbit RXD   = P3^0;

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
sbit T2EX  = P1^1;
sbit T2    = P1^0;
             
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

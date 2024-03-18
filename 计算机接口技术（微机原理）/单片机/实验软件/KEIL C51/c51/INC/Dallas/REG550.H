/*--------------------------------------------------------------------------
REG550.H

Header file for Dallas DS87C550.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG550_H__
#define __REG550_H__

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

/*  DS87C550 Extensions  */
sfr P4     = 0xC0;
sfr P5     = 0xC4;
sfr P6     = 0xF1;
sfr DPL1   = 0x84;
sfr DPH1   = 0x85;
sfr DPS    = 0x86;
sfr CKCON  = 0x8E;
sfr RCON   = 0x91;
sfr PMR    = 0x9F;
sfr SADDR0 = 0xA1;
sfr SADDR1 = 0xA2;
sfr CMPL0  = 0xA9;
sfr CMPL1  = 0xAA;
sfr CMPL2  = 0xAB;
sfr CMTL0  = 0xAC;
sfr CMTL1  = 0xAD;
sfr CMTL2  = 0xAE;
sfr CMTL3  = 0xAF;
sfr ADCON1 = 0xB2;
sfr ADCON2 = 0xB3;
sfr ADMSB  = 0xB4;
sfr ADLSB  = 0xB5;
sfr WINHI  = 0xB6;
sfr WINLO  = 0xB7;
sfr SADEN0 = 0xB9;
sfr SADEN1 = 0xBA;
sfr T2CON  = 0xBE;
sfr T2MOD  = 0xBF;
sfr ROMSIZE = 0xC2;
sfr STATUS = 0xC5;
sfr TA     = 0xC7;
sfr T2IR   = 0xC8;
sfr CMPH0  = 0xC9;
sfr CMPH1  = 0xCA;
sfr CMPH2  = 0xCB;
sfr CPTH0  = 0xCC;
sfr CPTH1  = 0xCD;
sfr CPTH2  = 0xCE;
sfr CPTH3  = 0xCF;
sfr PW0FG  = 0xD2;
sfr PW1FG  = 0xD3;
sfr PW2FG  = 0xD4;
sfr PW3FG  = 0xD5;
sfr PWMADR = 0xD6;
sfr SCON1  = 0xD8;
sfr SBUF1  = 0xD9;
sfr PWM0   = 0xDC;
sfr PWM1   = 0xDD;
sfr PWM2   = 0xDE;
sfr PWM3   = 0xDF;
sfr PW01CS = 0xE1;
sfr PW23CS = 0xE2;
sfr PW01CON = 0xE3;
sfr PW23CON = 0xE4;
sfr RLOADL = 0xE6;
sfr RLOADH = 0xE7;
sfr EIE    = 0xE8;
sfr T2SEL  = 0xEA;
sfr CTCON  = 0xEB;
sfr TL2    = 0xEC;
sfr TH2    = 0xED;
sfr SETR   = 0xEE;
sfr RSTR   = 0xEF;
sfr EIP    = 0xF8;
sfr WDCON  = 0xFF;

/*  BIT Registers  */
/*  P0  */
sbit P0_7  = P0^7;
sbit P0_6  = P0^6;
sbit P0_5  = P0^5;
sbit P0_4  = P0^4;
sbit P0_3  = P0^3;
sbit P0_2  = P0^2;
sbit P0_1  = P0^1;
sbit P0_0  = P0^0;
/*  P1  */
sbit P1_7  = P1^7;
sbit P1_6  = P1^6;
sbit P1_5  = P1^5;
sbit P1_4  = P1^4;
sbit P1_3  = P1^3;
sbit P1_2  = P1^2;
sbit P1_1  = P1^1;
sbit P1_0  = P1^0;
/*  P2  */
sbit P2_7  = P2^7;
sbit P2_6  = P2^6;
sbit P2_5  = P2^5;
sbit P2_4  = P2^4;
sbit P2_3  = P2^3;
sbit P2_2  = P2^2;
sbit P2_1  = P2^1;
sbit P2_0  = P2^0;
/*  P3  */
sbit P3_7  = P3^7;
sbit P3_6  = P3^6;
sbit P3_5  = P3^5;
sbit P3_4  = P3^4;
sbit P3_3  = P3^3;
sbit P3_2  = P3^2;
sbit P3_1  = P3^1;
sbit P3_0  = P3^0;
/*  P4  */
sbit CMT1  = P4^7;
sbit CMT0  = P4^6;
sbit CMSR5 = P4^5;
sbit CMSR4 = P4^4;
sbit CMSR3 = P4^3;
sbit CMSR2 = P4^2;
sbit CMSR1 = P4^1;
sbit CMSR0 = P4^0;
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit F1    = PSW^1;
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
sbit EAD   = IE^6;
sbit ES1   = IE^5;
sbit ES0   = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;
/*  IP  */
sbit PAD   = IP^6;
sbit PS1   = IP^5;
sbit PS0   = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;
/*  SCON0  */
sbit SM0   = SCON0^7; /* Alternate SM0_FE_0 */
sbit SM1   = SCON0^6; /* Alternate SM1_0 */
sbit SM2   = SCON0^5; /* Alternate SM2_0 */
sbit REN   = SCON0^4; /* Alternate REN_0 */
sbit TB8   = SCON0^3; /* Alternate TB8_0 */
sbit RB8   = SCON0^2; /* Alternate RB8_0 */
sbit TI    = SCON0^1; /* Alternate TI_0  */
sbit RI    = SCON0^0; /* Alternate RI_0  */
/*  SCON1  */
sbit SM01  = SCON1^7; /* Alternate SM0_FE_1 */
sbit SM11  = SCON1^6; /* Alternate SM1_1 */
sbit SM21  = SCON1^5; /* Alternate SM2_1 */
sbit REN1  = SCON1^4; /* Alternate REN_1 */
sbit TB81  = SCON1^3; /* Alternate TB8_1 */
sbit RB81  = SCON1^2; /* Alternate RB8_1 */
sbit TI1   = SCON1^1; /* Alternate TI_1  */
sbit RI1   = SCON1^0; /* Alternate RI_1  */
/*  T2IR  */
sbit CM2F    = T2IR^6;
sbit CM1F    = T2IR^5;
sbit CM0F    = T2IR^4;
sbit IE5_CF3 = T2IR^3;
sbit IE4_CF2 = T2IR^2;
sbit IE3_CF1 = T2IR^1;
sbit IE2_CF0 = T2IR^0;
/*  EIE  */
sbit ET2   = EIE^7;
sbit ECM2  = EIE^6;
sbit ECM1  = EIE^5;
sbit ECM0  = EIE^4;
sbit EX5   = EIE^3; /* Alternate EC3 */
sbit EX4   = EIE^2; /* Alternate EC2 */
sbit EX3   = EIE^1; /* Alternate EC1 */
sbit EX2   = EIE^0; /* Alternate EC0 */
/*  EIP  */
sbit PT2   = EIP^7;
sbit PCM2  = EIP^6;
sbit PCM1  = EIP^5;
sbit PCM0  = EIP^4;
sbit PX5   = EIP^3; /* Alternate PC3 */
sbit PX4   = EIP^2; /* Alternate PC2 */
sbit PX3   = EIP^1; /* Alternate PC1 */
sbit PX2   = EIP^0; /* Alternate PC0 */

#endif

/*--------------------------------------------------------------------------
REG420.H

Header file for Dallas 80C420.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG420_H__
#define __REG420_H__

/*  BYTE Registers  */
sfr P0      = 0x80;
sfr SP      = 0x81;
sfr DPL     = 0x82;
sfr DPH     = 0x83;
sfr DPL1    = 0x84;
sfr DPH1    = 0x85;
sfr DPS     = 0x86;
sfr PCON    = 0x87;
sfr TCON    = 0x88;
sfr TMOD    = 0x89;
sfr TL0     = 0x8A;
sfr TL1     = 0x8B;
sfr TH0     = 0x8C;
sfr TH1     = 0x8D;
sfr CKCON   = 0x8E;
sfr P1      = 0x90;
sfr EXIF    = 0X91;
sfr CKMOD   = 0x96;
sfr SCON0   = 0x98;
sfr SBUF0   = 0x99;
sfr ACON    = 0x9D;
sfr P2      = 0xA0;
sfr IE      = 0xA8;
sfr SADDR0  = 0xA9;
sfr SADDR1  = 0xAA;
sfr P3      = 0xB0;
sfr IP1     = 0xB1;
sfr IP0     = 0xB8;
sfr SADEN0  = 0xB9;
sfr SADEN1  = 0xBA;
sfr SCON1   = 0xC0;
sfr SBUF1   = 0xC1;
sfr ROMSIZ  = 0xC2;
sfr PMR     = 0xC4;
sfr STATUS  = 0xC5;
sfr TA      = 0xC7;
sfr T2CON   = 0xC8;
sfr T2MOD   = 0xC9;
sfr RCAP2L  = 0xCA;
sfr RCAP2H  = 0xCB;
sfr TL2     = 0xCC;
sfr TH2     = 0xCD;
sfr PSW     = 0xD0;
sfr FCNTL   = 0xD5;
sfr FDATA   = 0xD6;
sfr WDCON   = 0xD8;
sfr ACC     = 0xE0;
sfr EIE     = 0xE8;
sfr B       = 0xF0;
sfr EIP1    = 0xF1;
sfr EIP0    = 0xF8;
/*                 */
/*  BIT Registers  */
/*  TCON */
sbit IT0    = 0x88;
sbit IE0    = 0x89;
sbit IT1    = 0x8A;
sbit IE1    = 0x8B;
sbit TR0    = 0x8C;
sbit TF0    = 0x8D;
sbit TR1    = 0x8E;
sbit TF1    = 0x8F;

/* SCON0 */ 
sbit RI     = 0x98;
sbit TI     = 0x99;
sbit RB8    = 0x9A;
sbit TB8    = 0x9B;
sbit REN    = 0x9C;
sbit SM2    = 0x9D;
sbit SM1    = 0x9E;
sbit SM0    = 0x9F;

sbit RI_0    = 0x98; /* alternative definitions */
sbit TI_0    = 0x99;
sbit RB8_0   = 0x9A;
sbit TB8_0   = 0x9B;
sbit REN_0   = 0x9C;
sbit SM2_0   = 0x9D;
sbit SM1_0   = 0x9E;
sbit SM0FE_0 = 0x9F;

/* IE	 */
sbit EX0    = 0xA8;
sbit ET0    = 0xA9;
sbit EX1    = 0xAA;
sbit ET1    = 0xAB;
sbit ES0    = 0xAC;
sbit ET2    = 0xAD;
sbit ES1    = 0xAE;
sbit EA     = 0xAF;

/*  IP0	*/
sbit LPX0   = 0xB8;
sbit LPT0   = 0xB9;
sbit LPX1   = 0xBA;
sbit LPT1   = 0xBB;
sbit LPS0   = 0xBC;
sbit LPT2   = 0xBD;
sbit LPS1   = 0xBE;

/*  SCON1  */
sbit RI1    = 0xC0;
sbit TI1    = 0xC1;
sbit RB81   = 0xC2;
sbit TB81   = 0xC3;
sbit REN1   = 0xC4;
sbit SM21   = 0xC5;
sbit SM11   = 0xC6;
sbit SM01   = 0xC7;

sbit RI_1    = 0xC0;   /* alternative definition */
sbit TI_1    = 0xC1;
sbit RB8_1   = 0xC2;
sbit TB8_1   = 0xC3;
sbit REN_1   = 0xC4;
sbit SM2_1   = 0xC5;
sbit SM1_1   = 0xC6;
sbit SM0FE_1 = 0xC7;

/* T2CON */
sbit CP_RL2 = 0xC8;
sbit C_T2   = 0xC9;
sbit TR2    = 0xCA;
sbit EXEN2  = 0xCB;
sbit TCLK   = 0xCC;
sbit RCLK   = 0xCD;
sbit EXF2   = 0xCE;
sbit TF2    = 0xCF;

/* PSW	*/
sbit P	    = 0xD0;
sbit F1     = 0xD1;
sbit OV     = 0xD2;
sbit RS0    = 0xD3;
sbit RS1    = 0xD4;
sbit F0     = 0xD5;
sbit AC     = 0xD6;
sbit CY     = 0xD7;

/*  WDCON   */
sbit RWT    = 0xD8;
sbit EWT    = 0xD9;
sbit WTRF   = 0xDA;
sbit WDIF   = 0xDB;
sbit PFI    = 0xDC;
sbit EPFI   = 0xDD;
sbit POR    = 0xDE;
sbit SMOD_1 = 0xDF;

/*  EIE   */
sbit EX2    = 0xE8;
sbit EX3    = 0xE9;
sbit EX4    = 0xEA;
sbit EX5    = 0xEB;
sbit EWDI   = 0xEC;

/*  EIP0   */
sbit LPX2   = 0xF8;
sbit LPX3   = 0xF9;
sbit LPX4   = 0xFA;
sbit LPPX5  = 0xFB;
sbit LPWDI  = 0xFC;

/* end */

#endif

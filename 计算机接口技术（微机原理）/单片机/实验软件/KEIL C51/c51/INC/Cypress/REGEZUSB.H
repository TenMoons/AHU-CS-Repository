/*--------------------------------------------------------------------------
REGEZUSB.H

Header file for the Cypress AN21XX microcontroller family.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REGEZUSB_H__
#define __REGEZUSB_H__

sfr SP      = 0x81;
sfr DPL     = 0x82;
sfr DPH     = 0x83;
sfr DPL1    = 0x84;
sfr DPH1    = 0x85;
sfr DPS     = 0x86;
			/*  DPS  */
			sbit SEL   = 0x86+0;
sfr PCON    = 0x87;	/*  PCON  */
			//sbit IDLE   = 0x87+0;
			//sbit STOP   = 0x87+1;
			//sbit GF0    = 0x87+2;
			//sbit GF1    = 0x87+3;
			//sbit SMOD0  = 0x87+7;
sfr TCON    = 0x88;
			/*  TCON  */
			sbit IT0    = 0x88+0;
			sbit IE0    = 0x88+1;
			sbit IT1    = 0x88+2;
			sbit IE1    = 0x88+3;
			sbit TR0    = 0x88+4;
			sbit TF0    = 0x88+5;
			sbit TR1    = 0x88+6;
			sbit TF1    = 0x88+7;
sfr TMOD    = 0x89;
			/*  TMOD  */
			//sbit M00    = 0x89+0;
			//sbit M10    = 0x89+1;
			//sbit CT0    = 0x89+2;
			//sbit GATE0  = 0x89+3;
			//sbit M01    = 0x89+4;
			//sbit M11    = 0x89+5;
			//sbit CT1    = 0x89+6;
			//sbit GATE1  = 0x89+7;
sfr TL0     = 0x8A;
sfr TL1     = 0x8B;
sfr TH0     = 0x8C;
sfr TH1     = 0x8D;
sfr CKCON   = 0x8E;
			/*  CKCON  */
			//sbit MD0    = 0x89+0;
			//sbit MD1    = 0x89+1;
			//sbit MD2    = 0x89+2;
			//sbit T0M    = 0x89+3;
			//sbit T1M    = 0x89+4;
			//sbit T2M    = 0x89+5;
sfr SPC_FNC = 0x8F; // Was WRS in Reg320
			/*  CKCON  */
			//sbit WRS    = 0x8F+0;
sfr EXIF    = 0x91; // EXIF Bit Values differ from Reg320
			/*  EXIF  */
			//sbit USBINT = 0x91+4;
			//sbit I2CINT = 0x91+5;
			//sbit IE4    = 0x91+6;
			//sbit IE5    = 0x91+7;
sfr MPAGE  = 0x92;
sfr SCON0  = 0x98;
			/*  SCON0  */
			sbit RI    = 0x98+0;
			sbit TI    = 0x98+1;
			sbit RB8   = 0x98+2;
			sbit TB8   = 0x98+3;
			sbit REN   = 0x98+4;
			sbit SM2   = 0x98+5;
			sbit SM1   = 0x98+6;
			sbit SM0   = 0x98+7;
sfr SBUF0  = 0x99;
sfr IE     = 0xA8;
			/*  IE  */
			sbit EX0   = 0xA8+0;
			sbit ET0   = 0xA8+1;
			sbit EX1   = 0xA8+2;
			sbit ET1   = 0xA8+3;
			sbit ES0   = 0xA8+4;
			sbit ET2   = 0xA8+5;
			sbit ES1   = 0xA8+6;
			sbit EA    = 0xA8+7;
sfr IP     = 0xB8;
			/*  IP  */
			sbit PX0   = 0xB8+0;
			sbit PT0   = 0xB8+1;
			sbit PX1   = 0xB8+2;
			sbit PT1   = 0xB8+3;
			sbit PS0   = 0xB8+4;
			sbit PT2   = 0xB8+5;
			sbit PS1   = 0xB8+6;
sfr SCON1  = 0xC0;
			/*  SCON1  */
			sbit RI1   = 0xC0+0;
			sbit TI1   = 0xC0+1;
			sbit RB81  = 0xC0+2;
			sbit TB81  = 0xC0+3;
			sbit REN1  = 0xC0+4;
			sbit SM21  = 0xC0+5;
			sbit SM11  = 0xC0+6;
			sbit SM01  = 0xC0+7;
sfr SBUF1  = 0xC1;
sfr T2CON  = 0xC8;
			/*  T2CON  */
			sbit CP_RL2 = 0xC8+0;
			sbit C_T2  = 0xC8+1;
			sbit TR2   = 0xC8+2;
			sbit EXEN2 = 0xC8+3;
			sbit TCLK  = 0xC8+4;
			sbit RCLK  = 0xC8+5;
			sbit EXF2  = 0xC8+6;
			sbit TF2   = 0xC8+7;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;
sfr PSW    = 0xD0;
			/*  PSW  */
			sbit P     = 0xD0+0;
			sbit FL    = 0xD0+1;
			sbit OV    = 0xD0+2;
			sbit RS0   = 0xD0+3;
			sbit RS1   = 0xD0+4;
			sbit F0    = 0xD0+5;
			sbit AC    = 0xD0+6;
			sbit CY    = 0xD0+7;
sfr EICON  = 0xD8; // Was WDCON in DS80C320; Bit Values differ from Reg320
			/*  EICON  */
			sbit INT6  = 0xD8+3;
			sbit RESI  = 0xD8+4;
			sbit ERESI = 0xD8+5;
			sbit SMOD1 = 0xD8+7;
sfr ACC    = 0xE0;
sfr EIE    = 0xE8; // EIE Bit Values differ from Reg320
                        /*  EIE  */
			sbit EUSB    = 0xE8+0;
			sbit EI2C    = 0xE8+1;
			sbit EIEX4   = 0xE8+2;
			sbit EIEX5   = 0xE8+3;
			sbit EIEX6   = 0xE8+4;
sfr B      = 0xF0;
sfr EIP    = 0xF8; // EIP Bit Values differ from Reg320
                        /*  EIP  */
			sbit PUSB    = 0xF8+0;
			sbit PI2C    = 0xF8+1;
			sbit EIPX4   = 0xF8+2;
			sbit EIPX5   = 0xF8+3;
			sbit EIPX6   = 0xF8+4;
#endif

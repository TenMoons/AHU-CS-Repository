/*--------------------------------------------------------------------------
REG390.H

Header file for Dallas DS80C390.
Copyright (c) 1988-2000 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

/*  BYTE Registers  */
sfr P4     = 0x80;
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

/*  DS87C390 Extensions  */
sfr DPL1   = 0x84;
sfr DPH1   = 0x85;
sfr DPS    = 0x86;
sfr CKCON  = 0x8E;
sfr EXIF   = 0x91;
sfr P4CNT  = 0x92;
sfr DPX    = 0x93;
sfr DPX1   = 0x95;
sfr C0RMS0 = 0x96;
sfr C0RMS1 = 0x97;
sfr ESP    = 0x9B;
sfr AP     = 0x9C;
sfr ACON   = 0x9D;
sfr C0TMA0 = 0x9E;
sfr C0TMA1 = 0x9F;
sfr P5     = 0xA1;
sfr P5CNT  = 0xA2;
sfr C0C    = 0xA3;
sfr C0S    = 0xA4;
sfr C0IR   = 0xA5;
sfr C0TE   = 0xA5;
sfr C0RE   = 0xA7;
sfr SADDR0 = 0xA9;
sfr SADDR1 = 0xAA;
sfr C0M1C  = 0xAB;
sfr C0M2C  = 0xAC;
sfr C0M3C  = 0xAD;
sfr C0M4C  = 0xAE;
sfr C0M5C  = 0xAF;
sfr C0M6C  = 0xB3;
sfr C0M7C  = 0xB4;
sfr C0M8C  = 0xB5;
sfr C0M9C  = 0xB6;
sfr C0M10C = 0xB7;
sfr SADEN0 = 0xB9;
sfr SADEN1 = 0xBA;
sfr C0M11C = 0xBB;
sfr C0M12C = 0xBC;
sfr C0M13C = 0xBD;
sfr C0M14C = 0xBE;
sfr C0M15C = 0xBF;
sfr SCON1  = 0xC0;
sfr SBUF1  = 0xC1;
sfr PMR    = 0xC4;
sfr STATUS = 0xC5;
sfr MCON   = 0xC6;
sfr TA     = 0xC7;
sfr T2CON  = 0xC8;
sfr T2MOD  = 0xC9;
sfr RCAP2L = 0xCA;
sfr RCAP2H = 0xCB;
sfr TL2    = 0xCC;
sfr TH2    = 0xCD;
sfr COR    = 0xCE;
sfr MCNT0  = 0xD1;
sfr MCNT1  = 0xD2;
sfr MA     = 0xD3;
sfr MB     = 0xD4;
sfr MC     = 0xD5;
sfr CIRMS0 = 0xD6;
sfr CIRMS1 = 0xD7;
sfr WDCON  = 0xD8;
sfr CITMA0 = 0xDE;
sfr CITMA1 = 0xDF;
sfr C1C    = 0xE3;
sfr C1S    = 0xE4;
sfr C1IR   = 0xE5;
sfr C1TE   = 0xE6;
sfr C1RE   = 0xE7;
sfr EIE    = 0xE8;
sfr MXAX   = 0xEA;
sfr C1M1C  = 0xEB;
sfr C1M2C  = 0xEC;
sfr C1M3C  = 0xED;
sfr C1M4C  = 0xEE;
sfr C1M5C  = 0xEF;
sfr C1M6C  = 0xF3;
sfr C1M7C  = 0xF4;
sfr C1M8C  = 0xF5;
sfr C1M9C  = 0xF6;
sfr C1M10C = 0xF7;
sfr EIP    = 0xF8;
sfr C1M11C = 0xFB;
sfr C1M12C = 0xFC;
sfr C1M13C = 0xFD;
sfr C1M14C = 0xFE;
sfr C1M15C = 0xFF;

/*  BIT Registers  */
/*  P4  */
sbit P4_7  = P4^7;
sbit P4_6  = P4^6;
sbit P4_5  = P4^5;
sbit P4_4  = P4^4;
sbit P4_3  = P4^3;
sbit P4_2  = P4^2;
sbit P4_1  = P4^1;
sbit P4_0  = P4^0;
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
sbit SMOD_1= WDCON^7;
sbit POR   = WDCON^6;
sbit EPF1  = WDCON^5;
sbit PF1   = WDCON^4;
sbit WDIF  = WDCON^3;
sbit WTRF  = WDCON^2;
sbit EWT   = WDCON^1;
sbit RWT   = WDCON^0;
/*  EIE  */
sbit CANBIE= EIE^7;
sbit C0IE  = EIE^6;
sbit C1IE  = EIE^5;
sbit EWDI  = EIE^4;
sbit EX5   = EIE^3; /* Alternate EC3 */
sbit EX4   = EIE^2; /* Alternate EC2 */
sbit EX3   = EIE^1; /* Alternate EC1 */
sbit EX2   = EIE^0; /* Alternate EC0 */
/*  EIP  */
sbit CANBIP= EIP^7;
sbit C0IP  = EIP^6;
sbit C1IP  = EIP^5;
sbit PWD1  = EIP^4;
sbit PX5   = EIP^3; /* Alternate PC3 */
sbit PX4   = EIP^2; /* Alternate PC2 */
sbit PX3   = EIP^1; /* Alternate PC1 */
sbit PX2   = EIP^0; /* Alternate PC0 */


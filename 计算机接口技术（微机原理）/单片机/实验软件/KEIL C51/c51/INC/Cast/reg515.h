/*--------------------------------------------------------------------------
REG515.H

Header file for generic R80515 microcontroller.
--------------------------------------------------------------------------*/

#ifndef __REG515_H__
#define __REG515_H__

/*  BYTE Register  */
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
sfr DPL1   = 0x84; 
sfr DPH1   = 0x85; 
sfr WDTREL = 0x86; 
sfr PCON   = 0x87; 
sfr TCON   = 0x88; 
sfr TMOD   = 0x89; 
sfr TL0    = 0x8A; 
sfr TL1    = 0x8B; 
sfr TH0    = 0x8C; 
sfr TH1    = 0x8D; 
sfr CKCON  = 0x8E; 
sfr DPS    = 0x92; 
sfr S0CON  = 0x98; 
sfr S0BUF  = 0x99; 
sfr IEN2   = 0x9A; 
sfr S1CON  = 0x9B; 
sfr S1BUF  = 0x9C; 
sfr S1RELL = 0x9D; 
sfr IEN0   = 0xA8; 
sfr IP0    = 0xA9; 
sfr S0RELL = 0xAA; 
sfr IEN1   = 0xB8; 
sfr IP1    = 0xB9; 
sfr S0RELH = 0xBA; 
sfr S1RELH = 0xBB; 
sfr IRCON  = 0xC0; 
sfr CCEN   = 0xC1; 
sfr CCL1   = 0xC2; 
sfr CCH1   = 0xC3; 
sfr CCL2   = 0xC4; 
sfr CCH2   = 0xC5;  
sfr CCL3   = 0xC6; 
sfr CCH3   = 0xC7; 
sfr T2CON  = 0xC8; 
sfr CRCL   = 0xCA; 
sfr CRCH   = 0xCB; 
sfr TL2    = 0xCC; 
sfr TH2    = 0xCD; 
sfr WDCON  = 0xD8; 
sfr MD0    = 0xE9; 
sfr MD1    = 0xEA; 
sfr MD2    = 0xEB; 
sfr MD3    = 0xEC; 
sfr MD4    = 0xED; 
sfr MD5    = 0xEE; 
sfr ARCON  = 0xEF; 


/*  BIT Register  */
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

/* T2CON */
sbit T2PS = 0xCF; 
sbit I3FR = 0xCE;
sbit I2FR = 0xCD;
sbit T2R1 = 0xCC;
sbit T2R0 = 0xCB;
sbit T2CM = 0xCA;
sbit T2I1 = 0xC9;
sbit T2I0 = 0xC8;

/*  S0CON  */
sbit SM0  = 0x9F; 
sbit SM1  = 0x9E;
sbit SM20 = 0x9D;
sbit REN0 = 0x9C;
sbit TB80 = 0x9B;
sbit RB80 = 0x9A;
sbit TI0  = 0x99;
sbit RI0  = 0x98;

/*  IEN0  */
sbit EAL  = 0xAF; 
sbit WDT  = 0xAE;
sbit ET2  = 0xAD;
sbit ES0  = 0xAC;
sbit ET1  = 0xAB;
sbit EX1  = 0xAA;
sbit ET0  = 0xA9;
sbit EX0  = 0xA8;

/* IEN1  */
sbit EXEN2 = 0xBF; 
sbit SWDT  = 0xBE;
sbit EX6   = 0xBD;
sbit EX5   = 0xBC;
sbit EX4   = 0xBB;
sbit EX3   = 0xBA;
sbit EX2   = 0xB9;
sbit EADC  = 0xB8;

/* IRCON */
sbit EXF2 = 0xC7;
sbit TF2  = 0xC6;
sbit IEX6 = 0xC5;
sbit IEX5 = 0xC4;
sbit IEX4 = 0xC3;
sbit IEX3 = 0xC2;
sbit IEX2 = 0xC1;
sbit IADC = 0xC0;

#endif

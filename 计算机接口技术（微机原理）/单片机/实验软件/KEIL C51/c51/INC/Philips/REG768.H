/*--------------------------------------------------------------------------
REG768.H

Header file for Philips 87LPC768
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG768_H__
#define __REG768_H__

/* standard 8051 BYTE Registers  */
sfr P0    = 0x80;
sfr P1    = 0x90;
sfr P2    = 0xA0;
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
sfr IEN0  = 0xA8;
sfr IEN1  = 0xE8;
sfr IP0   = 0xB8;
sfr IP1   = 0XF8;
sfr SCON  = 0x98;
sfr SBUF  = 0x99;

/* Extensions for 87LPC768  */
sfr AUXR1   = 0xA2;
sfr ADCON   = 0xC0;
sfr DAC0    = 0xC5;
sfr CMP1    = 0xAC;
sfr CMP2    = 0xAD;
sfr CNSW0   = 0xD1;
sfr CNSW1   = 0xD2;
sfr CPSW0   = 0xD3;
sfr CPSW1   = 0xD4;
sfr CPSW2   = 0xD5;
sfr CPSW3   = 0xD6;
sfr CPSW4   = 0xD7;
sfr PWMCON0 = 0xDA;
sfr PWMCON1 = 0xDB;
sfr DIVM    = 0x95;
sfr I2CFG   = 0xC8;
sfr I2CON   = 0xD8;
sfr I2DAT   = 0xD9;
sfr IP0H    = 0xB7;
sfr IP1H    = 0xF7;
sfr KBI     = 0x86;
sfr P0M1    = 0x84;
sfr P0M2    = 0x85;
sfr P1M1    = 0x91;
sfr P1M2    = 0x92;
sfr P2M1    = 0xA4;
sfr P2M2    = 0xA5;
sfr PT0AD   = 0xF6;
sfr SADDR   = 0xA9;
sfr SADEN   = 0xB9;
sfr WDCON   = 0xA7;
sfr WDRST   = 0xA6;


/*  BIT Registers  */
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

/*  IEN0  */
sbit EA    = IEN0^7;
sbit EWD   = IEN0^6;
sbit EB0   = IEN0^5;
sbit ES    = IEN0^4;
sbit ET1   = IEN0^3;
sbit EX1   = IEN0^2;
sbit ET0   = IEN0^1;
sbit EX0   = IEN0^0;

/*  IEN1  */
sbit ETI   = IEN1^7;
sbit EC1   = IEN1^5;
sbit EAD   = IEN1^4;
sbit EC2   = IEN1^2;
sbit EKB   = IEN1^1;
sbit EI2   = IEN1^0;

/*  P0  */
sbit T1      = P0^7;
sbit _CMP1   = P0^6; // renamed since sfr CMP1 already exists
sbit _CMPREF = P0^5; // renamed since VTREG CMPREF already exists
sbit _CIN1A  = P0^4; // renamed since VTREG CIN1A already exists
sbit _CIN1B  = P0^3; // renamed since VTREG CIN1B already exists
sbit _CIN2A  = P0^2; // renamed since VTREG CIN2A already exists
sbit _CIN2B  = P0^1; // renamed since VTREG CIN2B already exists
sbit _CMP2   = P0^0; // renamed since sfr CMP2 already exists
 
/*  P1  */
sbit P1_7  = P1^7;
sbit P1_6  = P1^6;
sbit RST   = P1^5;
sbit INT1  = P1^4;
sbit INT0  = P1^3;
sbit T0    = P1^2;
sbit RXD   = P1^1;
sbit TXD   = P1^0;

/*  P2  */
sbit X1    = P2^1;
sbit X2    = P2^0;

/*  SCON  */
sbit SM0   = SCON^7;
sbit SM1   = SCON^6;
sbit SM2   = SCON^5;
sbit REN   = SCON^4;
sbit TB8   = SCON^3;
sbit RB8   = SCON^2;
sbit TI    = SCON^1;
sbit RI    = SCON^0;

/*  I2CFG  */
sbit SLAVEN = I2CFG^7; 
sbit MASTRQ = I2CFG^6;
sbit CLRTI  = I2CFG^5;
sbit TIRUN  = I2CFG^4;
sbit CT1    = I2CFG^1;
sbit CT0    = I2CFG^0;

/*  I2CON - read  */
sbit RDAT   = I2CON^7;
sbit ATN    = I2CON^6;
sbit DRDY   = I2CON^5;
sbit ARL    = I2CON^4;
sbit STR    = I2CON^3;
sbit STP    = I2CON^2;
sbit MASTER = I2CON^1;

/*  I2CON - write  */
sbit CXA    = I2CON^7;
sbit IDLE   = I2CON^6;
sbit CDR    = I2CON^5;
sbit CARL   = I2CON^4;
sbit CSTR   = I2CON^3;
sbit CSTP   = I2CON^2;
sbit XSTR   = I2CON^1;
sbit XSTP   = I2CON^0;

/*  IP0  */
sbit PWD    = IP0^6;
sbit PBO    = IP0^5;
sbit PS     = IP0^4;
sbit PT1    = IP0^3;
sbit PX1    = IP0^2;
sbit PT0    = IP0^1;
sbit PX0    = IP0^0;

/*  IP1  */
sbit PTI    = IP1^7;
sbit PC1    = IP1^5;
sbit PAD    = IP1^4;
sbit PC2    = IP1^2;
sbit PKB    = IP1^1;
sbit PI2    = IP1^0;

/*  ADCON */
sbit ENADC  = ADCON^7;
sbit ADCI   = ADCON^4;
sbit ADCS   = ADCON^3;
sbit RCCLK  = ADCON^2;
sbit AADR1  = ADCON^1;
sbit AADR0  = ADCON^0;

#endif

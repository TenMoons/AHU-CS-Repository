/*--------------------------------------------------------------------------
PCD6001.H

Header file for Philips PCD 6001
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __PCD6001_H__
#define __PCD6001_H__

/*  BYTE Registers  */
sfr ACC	= 0xE0;		/* accumulator */
sfr ALTP	= 0xAB;		/* LE and GPC control */
sfr A		= 0x80;		/*accumulator */
sfr B		= 0xF0;		/* B register for multiply, divide or scratch */
sfr CKCON	= 0x9A;		/* Clock Control Register */
sfr CDVC1	= 0xBB;		/* CODEC digital volume control for CODEC1 */
sfr CDVC2	= 0xBC;		/* CODEC digital volume control for CODEC2 */
sfr CDTR1	= 0xBD;		/* CODEC Test Register 1; see note 1 */
sfr CDTR2	= 0xB7;		/* CODEC Test Register 2; see note 2 */
sfr DTCON	= 0xC7;		/* line selection and alternative gain control register */
sfr DPL	= 0x82;		/* data pointer low */
sfr DPH	= 0x83;		/* data pointer high */
sfr DTM0	= 0xA2;		/* DSP to Microcontroller Communication Register 0 (read only) */
sfr DTM1	= 0xA3;		/* DSP to Microcontroller Communication Register 1 (read only) */
sfr DTM2	= 0xA4;		/* DSP to Microcontroller Communication Register 2 (read only) */
sfr GPADC	= 0xC3;		/* automatic analog-to-digital conversion, channel select*/
sfr GPADR	= 0xC2;		/* digital value of analog input (read only) */
sfr GPDAR	= 0xC4;		/* digital value of analog output */
sfr IEN0	= 0xA8;		/* Interrupt Enable Register 0 */
sfr IEN1	= 0xE8;		/* Interrupt Enable Register 1 */
sfr INTC	= 0xC1;		/* Interrupt Control Register */
sfr IP0	= 0xB8;		/* Interrupt Priority Register 0 */
sfr IP1	= 0xF8;		/* Interrupt Priority Register 1 */
sfr IRQ1	= 0xC0;		/* Interrupt Request Flag Register */
sfr IX1	= 0xE9;		/* Interrupt Polarity Register */
sfr MCSD	= 0xAA;		/* Memory Control Serial Data Register */
sfr MCSC	= 0xA9;		/* Memory Control Serial Command Register */
sfr MTD0	= 0xA5;		/* microcontroller to DSP communication register 0 */
sfr MTD1	= 0xA6;		/* microcontroller to DSP communication register 1 */
sfr MTD2	= 0xA7;		/* microcontroller to DSP communication register 2 */
sfr MCON	= 0xC8;		/* MSK Control Register */
sfr MBUF	= 0xC9;		/* MSK Data Buffer Register */
sfr MSTAT	= 0xCA;		/* MSK Status Register */
sfr P1		= 0x90;		/* general purpose digital I/O */
sfr P3		= 0xB0;		/* general purpose digital I/O */
sfr P4		= 0x98;		/* P4 can be used to control flash memory */
sfr P4CFG	= 0x9F;		/* P4 configuration and addressing mode register */
sfr PCON	= 0x87;		/* Power and Interrupt Control Register */
sfr PMTR1	= 0xB5;		/* Power Management Test Register 1; see note 2 */
sfr PMTR2	= 0xB6;		/* Power Management Test Register 2; see note 2 */
sfr PSW	= 0xD0;		/* Program Status Word */
sfr RTCON	= 0x9B;		/* Real-Time Clock control */
sfr S1CON	= 0xD8;		/* I 2 C-bus Serial Control Register */
sfr S1ADR	= 0xDB;		/* I 2 C-bus own slave address register */
sfr S1DAT	= 0xDA;		/* I 2 C-bus Data Shift Register */
sfr S1STA	= 0xD9;		/* I 2 C-bus Status Register (read only) */
sfr SYMOD	= 0xC5;		/* analog system mode control */
sfr SPCON	= 0x99;		/* system power and clock configuration */
sfr SP		= 0x81;		/* Stack Pointer */
sfr TCON	= 0x88;		/* Timer/counter Control Register */
sfr TMOD	= 0x89;		/* Timer/counter Mode Control Register */
sfr TL0	= 0x90;		/* Timer Low Register 0 */
sfr TL1	= 0x91;		/* Timer Low Register 1 */
sfr TH0	= 0x92;		/* Timer High Register 0 */
sfr TH1	= 0x93;		/* Timer High Register 1 */
sfr VREFR	= 0xBA;		/* Voltage Reference Register */
sfr WDT	= 0xFF;		/* Watchdog Timer */
sfr WDTKEY	= 0xF7;		/* Watchdog Key Register */
sfr XWUD	= 0xB9;		/* external wake-up disable */


/*  BIT Registers  */
/*  PSW  */
sbit CY    = 0xD7;
sbit AC    = 0xD6;
sbit F0    = 0xD5;
sbit RS1   = 0xD4;
sbit RS0   = 0xD3;
sbit OV    = 0xD2;
sbit F1    = 0xD1;
sbit P     = 0xD0;

/*  TCON  */
sbit TF1   = 0x8F;
sbit TR1   = 0x8E;
sbit TF0   = 0x8D;
sbit TR0   = 0x8C;
sbit IE1   = 0x8B;
sbit IT1   = 0x8A;
sbit IE0   = 0x89;
sbit IT0   = 0x88;

/*  IE  */
sbit EA    = 0xAF;
sbit ES1   = 0xAD;
sbit ES0   = 0xAC;
sbit ET1   = 0xAB;
sbit EX1   = 0xAA;
sbit ET0   = 0xA9;
sbit EX0   = 0xA8;

/*  IP  */
sbit PS1   = 0xBD;
sbit PS0   = 0xBC;
sbit PT1   = 0xBB;
sbit PX1   = 0xBA;
sbit PT0   = 0xB9;
sbit PX0   = 0xB8;

/*  P0  */
sbit AD7   = 0x87;
sbit AD6   = 0x86;
sbit AD5   = 0x85;
sbit AD4   = 0x84;
sbit AD3   = 0x83;
sbit AD2   = 0x82;
sbit AD1   = 0x81;
sbit AD0   = 0x80;

/*  P1  */
sbit SDA   = 0x97;
sbit SCL   = 0x96;
             
/*  P3  */
sbit RD    = 0xB7;
sbit WR    = 0xB6;
sbit T1    = 0xB5;
sbit T0    = 0xB4;
sbit INT1  = 0xB3;
sbit INT0  = 0xB2;
sbit TXD   = 0xB1;
sbit RXD   = 0xB0;

/*  S0CON  */
sbit SM0   = 0x9F;
sbit SM1   = 0x9E;
sbit SM2   = 0x9D;
sbit REN   = 0x9C;
sbit TB8   = 0x9B;
sbit RB8   = 0x9A;
sbit TI    = 0x99;
sbit RI    = 0x98;

/* S1CON */
sbit CR2   = 0xDF;
sbit ENS1  = 0xDE;
sbit STA   = 0xDD;
sbit STO   = 0xDC;
sbit SI    = 0xDB;
sbit AA    = 0xDA;
sbit CR1   = 0xD9;
sbit CR0   = 0xD8;

#endif

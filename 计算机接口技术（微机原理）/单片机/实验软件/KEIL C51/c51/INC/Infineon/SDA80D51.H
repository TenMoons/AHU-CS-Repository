/*--------------------------------------------------------------------------
SDA80D51.H

Header file for SDA80D51 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __SDA80D51_H__
#define __SDA80D51_H__

/* -------------------- SFR ---------------------------------------- */
sfr P0              = 0x80;
sfr SP              = 0x81;
sfr DPL             = 0x82;
sfr DPH             = 0x83;
sfr PCON            = 0x87;
sfr TCON            = 0x88;
sfr TMOD            = 0x89;
sfr TL0             = 0x8A;
sfr TL1             = 0x8B;
sfr TH0             = 0x8C;
sfr TH1             = 0x8D;
sfr P1              = 0x90;
sfr SCON            = 0x98;
sfr SBUF            = 0x99;
sfr P2              = 0xA0;
sfr EO              = 0xA2;
sfr IE              = 0xA8;
sfr P3              = 0xB0;
sfr IP              = 0xB8;
sfr IPH             = 0xB9;
sfr PSW             = 0xD0;
sfr ACC             = 0xE0;
sfr IEN1            = 0xE8;
sfr B               = 0xF0;
sfr IP1             = 0xF8;/* interrupt Priority 1 */

sfr IFO8B1          = 0xF1;/* Interface OAK to 8051 Byte 1 (MSByte of Oak-to-8051 fifo) */
sfr IFO8B0          = 0xF2;/* Interface OAK to 8051 Byte 0     */
sfr IFO8CR          = 0xF3;/* Interface OAK to 8051 Control    */
sfr IFO8SR1         = 0xF4;/* Interface OAK to 8051 Status 1   */
sfr IFO8SR0         = 0xF5;/* Interface OAK to 8051 Status 0   */
sfr IF8OB1          = 0xF6;/* Interface 8051 to OAK Byte 1     */
sfr IF8OB0          = 0xF7;/* Interface 8051 to OAK Byte 0     */
sfr IF8OCR          = 0xFA;/* Interface 8051 to OAK Control    */
sfr IF8OSR1         = 0xFB;/* Interface 8051 to OAK Status 1   */
sfr IF8OSR0         = 0xFC;/* Interface 8051 to OAK Status 0   */
sfr MMUBLK          = 0x91; 
sfr MMUMAP1         = 0x92; 
sfr MMUMAP2         = 0x93; 
sfr MMU8051PPG      = 0x94; 
sfr MMU8051DPG      = 0x95; 
sfr MMUEXTCONF      = 0x96; 
sfr MMUEXTDAT       = 0x97; 
sfr I2SCR           = 0x86;/* I2S Interface */
sfr I2CCSRB3        = 0xE1; 
sfr I2CCSRB2        = 0xE2; 
sfr I2CCSRB1        = 0xE3; 
sfr I2CCSRB0        = 0xE4; 
sfr I2CRTB3         = 0xE5; 
sfr I2CRTB2         = 0xE6; 
sfr I2CRTB1         = 0xE7; 
sfr I2CRTB0         = 0xE9; 

sfr I2CBUCB3        = 0xEA; 
sfr I2CBUCB2        = 0xEB; 
sfr I2CBUCB1        = 0xEC; 
sfr PWMADD          = 0xEE;/* shadow register for PWM adress   */
sfr PWMREG          = 0xEF;/* shadow register for PWM register */
sfr SSCCONB1        = 0xD8; 
sfr SSCCONB0        = 0xD9; 
sfr SSCBRB1         = 0xDA; 
sfr SSCBRB0         = 0xDB; 
sfr SSCTBB1         = 0xDC; 
sfr SSCTBB0         = 0xDD; 
sfr SSCRBB1         = 0xDE; 
sfr SSCRBB0         = 0xDF; 
sfr ASIADD          = 0xD1;/* ASI address registers */
sfr ASIREG          = 0xD2;/* ASI registers */
sfr FLAG            = 0xFD; 
sfr FLAG1           = 0xFE; 
sfr FLAGOAK         = 0x85;
sfr INTCLR          = 0x84;/* clear interrupt */
sfr INTEN0          = 0xBA;/* Interrupt Mask (bits 0 to 7)	 */
sfr INTEN1          = 0xBB;/* Interrupt Mask (bits 8 to 15)	 */
sfr INTEN2          = 0xBC;/* Interrupt Mask (bits 16 to 23) */
sfr INTEN3          = 0xBD;/* Interrupt Mask (bits 24 to 31) */
sfr INTEN4          = 0xBE;/* Interrupt Mask (bits 32 to 39) */
sfr INTEN5          = 0xBF;/* Interrupt Mask (bits 40 to 47) */
sfr ADCCNT0         = 0xD3; 

sfr DACCNT0         = 0xD5; 
sfr ADCCNT1         = 0xD4; 
sfr DACCNT1         = 0xD6; 
sfr ALOOP           = 0xD7; 
sfr TXDIVB0         = 0xAA; 
sfr TXRXDIVB1       = 0xAB; 
sfr RXDIVB0         = 0xAC;
sfr ADCDIV          = 0xAD; 
sfr PLLCR0          = 0xAE; 
sfr PLLCR1          = 0xAF; 
sfr PLLCR2          = 0xB1; 
sfr OSCCR		    = 0xA9;
sfr CKCNTR0         = 0xB2; 
sfr CKCNTR1         = 0xB3; 
sfr CKCSR           = 0xB4; 
sfr WDTTIM          = 0xB5; 
sfr WDTCSR          = 0xB6; 
sfr WDTCNT          = 0xB7; 
sfr RTCADD          = 0xA1; 
sfr RTCREG          = 0xA3; 
sfr PREG            = 0xFF; 

sfr GPIOMUX1        = 0xA4; 
sfr GPIOMUX0        = 0xA5;
sfr GPIOSEL         = 0xA6;
sfr GPIOSET         = 0xA7;
sfr EXTESFR0        = 0xC0;/*\                */
sfr EXTESFR1        = 0xC1;/* |               */
sfr EXTESFR2        = 0xC2;/* |               */
sfr EXTESFR3        = 0xC3;/* |               */
sfr EXTESFR4        = 0xC4;/* |               */
sfr EXTESFR5        = 0xC5;/* |               */
sfr EXTESFR6        = 0xC6;/* |               */
sfr EXTESFR7        = 0xC7;/* |               */
sfr EXTESFR8        = 0xC8;/* External ESFRs  */
sfr EXTESFR9        = 0xC9;/* |               */
sfr EXTESFR10       = 0xCA;/* |               */
sfr EXTESFR11       = 0xCB;/* |               */
sfr EXTESFR12       = 0xCC;/* |               */
sfr EXTESFR13       = 0xCD;/* |               */
sfr EXTESFR14       = 0xCE;/* |               */
sfr EXTESFR15       = 0xCF;/*                 */
				   	 
/* --------------------BITS---------------------------------------- */
/* Bits P0 */
sbit P0_0           = 0x80;
sbit P0_1           = 0x81;
sbit P0_2           = 0x82;
sbit P0_3           = 0x83;
sbit P0_4           = 0x84;
sbit P0_5           = 0x85;
sbit P0_6           = 0x86;
sbit P0_7           = 0x87;

/* Bits TCON */
sbit IT0            = 0x88;
sbit IE0            = 0x89;
sbit IT1            = 0x8A;
sbit IE1            = 0x8B;
sbit TR0            = 0x8C;
sbit TF0            = 0x8D;
sbit TR1            = 0x8E;
sbit TF1            = 0x8F;

/* Bits P1 */
sbit P1_0           = 0x90;
sbit P1_1           = 0x91;
sbit P1_2           = 0x92;
sbit P1_3           = 0x93;
sbit P1_4           = 0x94;
sbit P1_5           = 0x95;
sbit P1_6           = 0x96;
sbit P1_7           = 0x97;

/* bits SCON */
sbit RI             = 0x98;
sbit TI             = 0x99;
sbit RB8            = 0x9A;
sbit TB8            = 0x9B;
sbit REN            = 0x9C;
sbit SM2            = 0x9D;
sbit SM1            = 0x9E;
sbit SM0            = 0x9F;

/* Bits P2 */
sbit P2_0           = 0xA0;
sbit P2_1           = 0xA1;
sbit P2_2           = 0xA2;
sbit P2_3           = 0xA3;
sbit P2_4           = 0xA4;
sbit P2_5           = 0xA5;
sbit P2_6           = 0xA6;
sbit P2_7           = 0xA7;

/* Bits IEN0 */
sbit EX0            = 0xA8;
sbit ET0            = 0xA9;
sbit EX1            = 0xAA;
sbit ET1            = 0xAB;
sbit ES             = 0xAC;
sbit EI5            = 0xAD;
sbit EA             = 0xAF;

/* Bits P3 */
sbit P3_0           = 0xB0;
sbit P3_1           = 0xB1;
sbit P3_2           = 0xB2;
sbit P3_3           = 0xB3;
sbit P3_4           = 0xB4;
sbit P3_5           = 0xB5;
sbit P3_6           = 0xB6;
sbit P3_7           = 0xB7;

/* Bits IP */
sbit PX0            = 0xB8;
sbit PT0            = 0xB9;
sbit PX1            = 0xBA;
sbit PT1            = 0xBB;
sbit PS             = 0xBC;
sbit PI5            = 0xBD;

/* Bits PSW */
sbit P              = 0xD0;
sbit F1             = 0xD1;
sbit OV             = 0xD2;
sbit RS0            = 0xD3;
sbit RS1            = 0xD4;
sbit F0             = 0xD5;
sbit AC             = 0xD6;
sbit CY             = 0xD7;

/* Bits ACC */
sbit ACC_0          = 0xE0;
sbit ACC_1          = 0xE1;
sbit ACC_2          = 0xE2;
sbit ACC_3          = 0xE3;
sbit ACC_4          = 0xE4;
sbit ACC_5          = 0xE5;
sbit ACC_6          = 0xE6;
sbit ACC_7          = 0xE7;

/* Bits IEN1 */
sbit IE1_0          = 0xE8;
sbit IE1_1          = 0xE9;
sbit IE1_2          = 0xEA;
sbit IE1_3          = 0xEB;
sbit IE1_4          = 0xEC;
sbit IE1_5          = 0xED;
sbit IE1_6          = 0xEE;
sbit IE1_7          = 0xEF;

/* Bits B */
sbit B_0            = 0xF0;
sbit B_1            = 0xF1;
sbit B_2            = 0xF2;
sbit B_3            = 0xF3;
sbit B_4            = 0xF4;
sbit B_5            = 0xF5;
sbit B_6            = 0xF6;
sbit B_7            = 0xF7;

/* Bits IP1 */
sbit IP1_0          = 0xF8;
sbit IP1_1          = 0xF9;
sbit IP1_2          = 0xFA;
sbit IP1_3          = 0xFB;
sbit IP1_4          = 0xFC;
sbit IP1_5          = 0xFD;
sbit IP1_6          = 0xFE;
sbit IP1_7          = 0xFF;

#endif











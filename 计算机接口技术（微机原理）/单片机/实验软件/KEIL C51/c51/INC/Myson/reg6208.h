/*--------------------------------------------------------------------------
REG6208.H

Header file for Myson-Century CS6208  Enhanced 8051 Processor
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG6208_H__
#define __REG6208_H__
  
sfr TA=0xc7;
sfr SP  = 0x81 ; // stack pointer
sfr DPL  = 0x82 ; // data pointer 0 lsb
sfr DPH  = 0x83 ; // data pointer 0 msb
sfr DPL1  = 0x84 ; // data pointer 1 lsb
sfr DPH1  = 0x85 ; // data pointer 1 msb
sfr DPS  = 0x86 ; // data pointer select
sfr PCON  = 0x87 ; // power control
sfr TCON = 0x88 ; // timer/counter control
  sbit IT0 = 0x88 ;
  sbit IE0 = 0x89 ;
  sbit IT1 = 0x8a ;
  sbit IE1 = 0x8b ;
  sbit TR0 = 0x8c ;
  sbit TF0 = 0x8d ;
  sbit TR1 = 0x8e ;
  sbit TF1 = 0x8f ;
sfr TMOD = 0x89 ; // timer mode control
sfr TL0 = 0x8a ; // timer 0 lsb
sfr TL1 = 0x8b ; // timer 1 msb
sfr TH0 = 0x8c ; // timer 0 msb
sfr TH1 = 0x8d ; // timer 1 msb
sfr CKCON = 0x8e ; // clock control
sfr P1 = 0x90 ;
  sbit T2 = 0x90 ;
  sbit T2EX = 0x91 ;
  sbit RXD1 = 0x92 ;
  sbit TXD1 = 0x93 ;
  sbit INT2 = 0x94 ;
  sbit INT3 = 0x95 ;
  sbit INT4 = 0x96 ;
  sbit INT5 = 0x97 ;

sfr SCON0 = 0x98 ; // serial 0 control
sfr SCON = 0x98 ;
  sbit RI_0 = 0x98 ;
  sbit RI = 0x98 ;
  sbit TI_0  =0x99 ;
  sbit TI  = 0x99 ;
  sbit RB8_0 = 0x9a ;
  sbit TB8_0 = 0x9b ;
  sbit REN_0 = 0x9c ;
  sbit SM2_0 = 0x9d ;
  sbit SM1_0 = 0x9e ;
  sbit SM0_0 = 0x9f ;
  sbit FE_0 = 0x9f ; // depending on SMOD0
sfr SBUF0 = 0x99 ; // serial 0 data buffer
sfr SBUF = 0x99 ;

sfr P2 = 0xa0 ;// never mind the sbits


//sfr at 0xa2 P5CNT;
sfr IE = 0xa8 ; // interrupt enable
  sbit EX0 = 0xa8 ;
  sbit ET0 = 0xa9 ;
  sbit EX1 = 0xaa ;
  sbit ET1 = 0xab ;
  sbit ES0 = 0xac ;
  sbit ET2 = 0xad ;
  sbit ES1 = 0xae ;
  sbit EA = 0xaf ;
sfr SADDR = 0xa8 ;

sfr P3 = 0xb0 ;
  sbit RXD0 = 0xb0 ;
  sbit TXD0 = 0xb1 ;
  sbit INT0 = 0xb2 ;
  sbit INT1 = 0xb3 ;
  sbit T0 = 0xb4 ;
  sbit T1 = 0xb5 ;
  sbit WR = 0xb6 ;
  sbit RD = 0xb7 ;
sfr IP = 0xb8 ; // interupt priority 
  sbit PX0 = 0xb8 ; // external 0
  sbit PT0 = 0xb9 ; // timer 0
  sbit PX1 = 0xba ; // external 1
  sbit PT1 = 0xbb ; // timer 1
  sbit PS0 = 0xbc ; // serial port 0
  sbit PT2 = 0xbd ; // timer 2
  sbit PS1 = 0xbe ; // serial port 1
sfr SADEN = 0xb9 ; 
  

sfr T2CON = 0xc8 ; // timer 2 control
  sbit CP_RL = 0xc8 ; // capture/reload
  sbit C_T = 0xc9 ; // count/timer
  sbit TR2 = 0xca ; // stop/run
  sbit EXEN2 = 0xcb ;
  sbit TCLK = 0xcc ;
  sbit RCLK = 0xcd ;
  sbit EXF2 = 0xce ;
  sbit TF2 = 0xcf ; // overflow flag
sfr T2MOD = 0xc9 ; // timer 2 mode
sfr RCAP2L = 0xca ; // timer 2 capture/reload
//sfr at 0xca RTL2; // depends on CP_RL
sfr RCAP2H = 0xcb ;
//sfr at 0xcb RTH2;
sfr TL2 = 0xcc ; // timer 2 lsb
sfr TH2 = 0xcd ; // timer 2 msb
sfr PSW = 0xd0 ; // program status word (byte actually)
  sbit P = 0xd0 ; // parity
  sbit F1 = 0xd1 ; // user flag 1
  sbit OV = 0xd2 ; // overflow flag
  sbit RS0 = 0xd3 ; // register select l
  sbit RS1 = 0xd4 ; // register select h
  sbit F0 = 0xd5 ; // user flag 0
  sbit AC = 0xd6 ; // auxiliary carry flag
  sbit CY = 0xd7 ; // carry flag

sfr WDCON = 0xd8 ; // watch dog
  sbit RWT = 0xd8 ;
  sbit EWT = 0xd9 ;
  sbit WTRF = 0xda ;
  sbit PF1 = 0xdb ;
  sbit EPF1 = 0xdc ;
  sbit POR = 0xde ;
  sbit SMOD_1 = 0xdf ;
sfr ACC = 0xe0 ; // accumulator
sfr EIE = 0xe8 ; // extended interrupt enable
  sbit EX2 = 0xe8 ;
  sbit EX3 = 0xe9 ;
  sbit EX4 = 0xea ;
  sbit EX5 = 0xeb ;
  sbit EWDI = 0xec ;
  sbit C1IE = 0xed ;
  sbit C0IE = 0xee ;
  sbit CANBIE = 0xef ;

sfr B = 0xf0 ; // aux accumulator
sfr EIP = 0xf8 ; // extended interrupt priority
  sbit PX2 = 0xf8 ;
  sbit PX3 = 0xf9 ;
  sbit PX4 = 0xfa ;
  sbit PX5 = 0xfb ;
  sbit PWDI = 0xfc ;
  sbit C1IP = 0xfd ;
  sbit C0IP = 0xfe ;
  sbit CANBIP = 0xff ;

#ifdef SDCC
sfr at 0x81 SP; // stack pointer
sfr at 0x82 DPL; // data pointer 0 lsb
sfr at 0x83 DPH; // data pointer 0 msb
sfr at 0x84 DPL1; // data pointer 1 lsb
sfr at 0x85 DPH1; // data pointer 1 msb
sfr at 0x86 DPS; // data pointer select
sfr at 0x87 PCON; // power control
sfr at 0x88 TCON; // timer/counter control
  sbit at 0x88 IT0;
  sbit at 0x89 IE0;
  sbit at 0x8a IT1;
  sbit at 0x8b IE1;
  sbit at 0x8c TR0;
  sbit at 0x8d TF0;
  sbit at 0x8e TR1;
  sbit at 0x8f TF1;
sfr at 0x89 TMOD; // timer mode control
sfr at 0x8a TL0; // timer 0 lsb
sfr at 0x8b TL1; // timer 1 msb
sfr at 0x8c TH0; // timer 0 msb
sfr at 0x8d TH1; // timer 1 msb
sfr at 0x8e CKCON; // clock control
sfr at 0x90 P1;
  sbit at 0x90 T2;
  sbit at 0x91 T2EX;
  sbit at 0x92 RXD1;
  sbit at 0x93 TXD1;
  sbit at 0x94 INT2;
  sbit at 0x95 INT3;
  sbit at 0x96 INT4;
  sbit at 0x97 INT5;

sfr at 0x98 SCON0; // serial 0 control
sfr at 0x98 SCON;
  sbit at 0x98 RI_0;
  sbit at 0x98 RI;
  sbit at 0x99 TI_0;
  sbit at 0x99 TI;
  sbit at 0x9a RB8_0;
  sbit at 0x9b TB8_0;
  sbit at 0x9c REN_0;
  sbit at 0x9d SM2_0;
  sbit at 0x9e SM1_0;
  sbit at 0x9f SM0_0;
  sbit at 0x9f FE_0; // depending on SMOD0
sfr at 0x99 SBUF0; // serial 0 data buffer
sfr at 0x99 SBUF;

sfr at 0xa0 P2 ;// never mind the sbits


//sfr at 0xa2 P5CNT;
sfr at 0xa8 IE; // interrupt enable
  sbit at 0xa8 EX0;
  sbit at 0xa9 ET0;
  sbit at 0xaa EX1;
  sbit at 0xab ET1;
  sbit at 0xac ES0;
  sbit at 0xad ET2;
  sbit at 0xae ES1;
  sbit at 0xaf EA;
sfr at 0xa8 SADDR;

sfr at 0xb0 P3;
  sbit at 0xb0 RXD0;
  sbit at 0xb1 TXD0;
  sbit at 0xb2 INT0;
  sbit at 0xb3 INT1;
  sbit at 0xb4 T0;
  sbit at 0xb5 T1;
  sbit at 0xb6 WR;
  sbit at 0xb7 RD;
sfr at 0xb8 IP; // interupt priority 
  sbit at 0xb8 PX0; // external 0
  sbit at 0xb9 PT0; // timer 0
  sbit at 0xba PX1; // external 1
  sbit at 0xbb PT1; // timer 1
  sbit at 0xbc PS0; // serial port 0
  sbit at 0xbd PT2; // timer 2
  sbit at 0xbe PS1; // serial port 1
sfr at 0xb9 SADEN; 
  

sfr at 0xc8 T2CON; // timer 2 control
  sbit at 0xc8 CP_RL; // capture/reload
  sbit at 0xc9 C_T; // count/timer
  sbit at 0xca TR2; // stop/run
  sbit at 0xcb EXEN2;
  sbit at 0xcc TCLK;
  sbit at 0xcd RCLK;
  sbit at 0xce EXF2;
  sbit at 0xcf TF2; // overflow flag
sfr at 0xc9 T2MOD; // timer 2 mode
sfr at 0xca RCAP2L; // timer 2 capture/reload
//sfr at 0xca RTL2; // depends on CP_RL
sfr at 0xcb RCAP2H;
//sfr at 0xcb RTH2;
sfr at 0xcc TL2; // timer 2 lsb
sfr at 0xcd TH2; // timer 2 msb
sfr at 0xd0 PSW; // program status word (byte actually)
  sbit at 0xd0 P; // parity
  sbit at 0xd1 F1; // user flag 1
  sbit at 0xd2 OV; // overflow flag
  sbit at 0xd3 RS0; // register select l
  sbit at 0xd4 RS1; // register select h
  sbit at 0xd5 F0; // user flag 0
  sbit at 0xd6 AC; // auxiliary carry flag
  sbit at 0xd7 CY; // carry flag

sfr at 0xd8 WDCON; // watch dog
  sbit at 0xd8 RWT;
  sbit at 0xd9 EWT;
  sbit at 0xda WTRF;
  sbit at 0xdb PF1;
  sbit at 0xdc EPF1;
  sbit at 0xde POR;
  sbit at 0xdf SMOD_1;
sfr at 0xe0 ACC; // accumulator
sfr at 0xe8 EIE; // extended interrupt enable
  sbit at 0xe8 EX2;
  sbit at 0xe9 EX3;
  sbit at 0xea EX4;
  sbit at 0xeb EX5;
  sbit at 0xec EWDI;
  sbit at 0xed C1IE;
  sbit at 0xee C0IE;
  sbit at 0xef CANBIE;

sfr at 0xf0 B; // aux accumulator
sfr at 0xf8 EIP; // extended interrupt priority
  sbit at 0xf8 PX2;
  sbit at 0xf9 PX3;
  sbit at 0xfa PX4;
  sbit at 0xfb PX5;
  sbit at 0xfc PWDI;
  sbit at 0xfd C1IP;
  sbit at 0xfe C0IP;
  sbit at 0xff CANBIP;
#endif 


/* defining EXT_SFR*/

#define	I2C2_SAR	0x0FFD8
#define	I2C2_SCON	0x0FFD9
#define	I2C2_TX		0x0FFDA
#define	I2C2_CON	0x0FFDB
#define	I2C1_SAR	0x0FFDC
#define	I2C1_SCON	0x0FFDD
#define	I2C1_TX		0x0FFDE
#define	I2C1_CON	0x0FFDF

#define	I2C2_RX		0x0FFE0
#define	I2C2_STA	0x0FFE1
#define	I2C1_RX		0x0FFE2
#define	I2C1_STA	0x0FFE3

#define	PAOE		0x0FFE7
#define	AREG		0x0FFE8
#define	B10CTRL 	0x0FFE9
#define	PHYCTRL		0x0FFEA

//xdata at 0x0FFEA unsigned char PHYCTRL;

#define	INTSTA		0x0FFEB
#define	RAMCKC		0x0FFEC
#define	RCKSDL		0x0FFED
#define	RCKSDH		0x0FFEE
#define	RCKBCL		0x0FFEF

#define	RCKBCH		0x0FFF0
#define	RCKSL		0x0FFF1
#define	RCKSH		0x0FFF2
#define	MBSEL		0x0FFF3
#define	PCOE		0x0FFF4
//xdata at 0x0FFF4 unsigned char PCOE;

#define	CREG		0x0FFF5
#define	PBOE		0x0FFF6
//xdata at 0x0FFF6 unsigned char PBOE;

#define	BREG		0x0FFF7
#define	ADC_DIV		0x0FFF8
#define	XX_DATA		0x0FFF9
#define	XX_ADDR		0x0FFFA
#define	ADC_SW		0x0FFFB
#define	ADC_COR		0x0FFFC
#define	ADC_CR		0x0FFFD
//#define	PLLFC		0x0FFFE
#define	CCR		0x0FFFF

#define TRUE  1
#define FALSE 0
#define true  1
#define false 0

#define SBUF     SBUF0
#define SCON     SCON0
#define RI       RI_0
#define TI       TI_0

#define BANK_REG 0x0e  // bank switch reg(all 4 banks)
// bank 0
#define TCR_REG  0x00  // transmit control reg
#define RCR_REG  0x04  // receive control reg
// bank 1
#define MAC0_REG     0x04
#define CONTROL_REG  0x0c  // misc control bits
// bank 2
#define CMD_REG 0  // high level commands and packet sizing, allocation
#define AUTO_TX_START_REG 1  // num of 16 bytes when trasmit starts transmit
#define PNR_REG 2  //  packet number reg(packet alloc).
#define ARR_REG 3  //  alloc. result reg(packet alloc).
#define TX_FIFO_REG 4  // 
#define RX_FIFO_REG 5  // 
#define POINTER_REG 6  // 6,7(7=high addr, bit ctrl flags, 6=addr)
#define DATA_REG    8  // 4 bytes long(extra for efficient dword read/write)
#define ISR_REG     0x0c // interrupt status reg,
#define ISR_RCV_INT 0x01 // bit flag in ISR_REG indicating packet rx

#endif

/*-------------------------------------------------------------------------
T8XC5121.h    

Header file for Atmel T8XC5121
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __T8XC5121_H__
#define __T8XC5121_H__

/*_____IT  D E F I N I T I O N _____________________________________________*/
#define IRQ_INT0     0
#define IRQ_TIMER0   1
#define IRQ_INT1     2
#define IRQ_TIMER1   3
#define IRQ_UART     4

#define IRQ_SCI     10 

/*_____ SFR D E F I N I T I O N _____________________________________________*/

#define Sfr(x, y)       sfr x = y
#define Sbit(x, y, z)   sbit x = y^z
#define Sfr16(x,y)      sfr16 x = y

/*----------------------------------------*/
/* Include file for 8051 SFR Definitions  */
/*----------------------------------------*/

/*  BYTE Register  */
Sfr (P0, 0x80);

Sbit (P0_7, 0x80, 7);
Sbit (P0_6, 0x80, 6);
Sbit (P0_5, 0x80, 5);
Sbit (P0_4, 0x80, 4);
Sbit (P0_3, 0x80, 3);
Sbit (P0_2, 0x80, 2);
Sbit (P0_1, 0x80, 1);
Sbit (P0_0, 0x80, 0);


Sfr (P1, 0x90);

Sbit (P1_7, 0x90, 7);
Sbit (P1_6, 0x90, 6);
Sbit (P1_5, 0x90, 5);
Sbit (P1_4, 0x90, 4);
Sbit (P1_3, 0x90, 3);
Sbit (P1_2, 0x90, 2);
Sbit (P1_1, 0x90, 1);
Sbit (P1_0, 0x90, 0);

Sfr (P2, 0xA0);

Sbit (P2_7, 0xA0, 7);
Sbit (P2_6, 0xA0, 6);
Sbit (P2_5, 0xA0, 5);
Sbit (P2_4, 0xA0, 4);
Sbit (P2_3, 0xA0, 3);
Sbit (P2_2, 0xA0, 2);
Sbit (P2_1, 0xA0, 1);
Sbit (P2_0, 0xA0, 0);

Sfr (P3, 0xB0);

Sbit (P3_7, 0xB0, 7);
Sbit (P3_6, 0xB0, 6);
Sbit (P3_5, 0xB0, 5);
Sbit (P3_4, 0xB0, 4);
Sbit (P3_3, 0xB0, 3);
Sbit (P3_2, 0xB0, 2);
Sbit (P3_1, 0xB0, 1);
Sbit (P3_0, 0xB0, 0);

Sbit (RD ,  0xB0, 7);
Sbit (WR ,  0xB0, 6);
Sbit (T1 ,  0xB0, 5);
Sbit (T0 ,  0xB0, 4);
Sbit (INT1, 0xB0, 3);
Sbit (INT0, 0xB0, 2);
Sbit (TXD , 0xB0, 1);
Sbit (RXD , 0xB0, 0);

Sfr (PSW, 0xD0);

Sbit (CY  , 0xD0, 7);
Sbit (AC  , 0xD0, 6);
Sbit (F0  , 0xD0, 5);
Sbit (RS1 , 0xD0, 4);
Sbit (RS0 , 0xD0, 3);
Sbit (OV  , 0xD0, 2);
Sbit (UD  , 0xD0, 1);
Sbit (P   , 0xD0, 0);

Sfr (SP  , 0x81);
Sfr (DPL , 0x82);
Sfr (DPH , 0x83);
Sfr (PCON, 0x87);
Sfr (ACC , 0xE0);
Sfr (B ,   0xF0);


/*------------------ CLOCK registers ---------------------*/
Sfr (CKCON , 0x8F);
Sfr (CKCON0, 0x8F);
#define B_CKCONX2 1            /* For SFR at address != X0/X8 */

Sfr (CKRL,   0x97);
Sfr (CKCON1, 0xAF);
#define MSK_CKCON1_SCX2    0x08

Sfr (DCCKPS, 0xBF);

/*------------------ TIMERS registers ---------------------*/
Sfr  (TCON, 0x88);
Sbit (TF1 , 0x88, 7);
Sbit (TR1 , 0x88, 6);
Sbit (TF0 , 0x88, 5);
Sbit (TR0 , 0x88, 4);
Sbit (IE1 , 0x88, 3);
Sbit (IT1 , 0x88, 2);
Sbit (IE0 , 0x88, 1);
Sbit (IT0 , 0x88, 0);

Sfr (TMOD , 0x89);
Sfr (TL0  , 0x8A);
Sfr (TL1  , 0x8B);
Sfr (TH0  , 0x8C);
Sfr (TH1  , 0x8D);
Sfr (WDTRST, 0xA6);
Sfr (WDTPRG, 0xA7);

/*------------------- UART registers ------------------------*/
Sfr (SIOCON, 0x91);

Sfr  (SCON , 0x98);
Sbit (SM0  , 0x98, 7);
Sbit (FE   , 0x98, 7);
Sbit (SM1  , 0x98, 6);
Sbit (SM2  , 0x98, 5);
Sbit (REN  , 0x98, 4);
Sbit (TB8  , 0x98, 3);
Sbit (RB8  , 0x98, 2);
Sbit (TI   , 0x98, 1);
Sbit (RI   , 0x98, 0);

Sfr (SBUF  , 0x99);
Sfr (BRL   , 0x9A);
Sfr (BDRCON, 0x9B);
Sfr (SADEN , 0xB9);
Sfr (SADDR , 0xA9);

/*-------------------- RAM ROM registers ------------*/
Sfr (RCON  , 0xD1);
Sfr (AUXR  , 0x8E);
Sfr (AUXR1 , 0xA2);

/*-------------------- IT registers -----------------------*/

Sfr (IEN0   , 0xA8);
Sfr (IEN1   , 0xB1);
#define MSK_IEN1_ESCI   0x08

Sfr (IPL1  , 0xB2);
Sfr (IPH1  , 0xB3);
Sfr (IPH0  , 0xB7);
#define B_IPHS  4    /* For SFR adresses 0-4 */ 
#define B_IPHT1 3
#define B_IPHX1 2
#define B_IPHT0 1
#define B_IPHX0 0

Sfr (IPL  , 0xB8);   /* IP */
Sfr (IPL0 , 0xB8);

Sbit (IPLS   , IPL, 4);
Sbit (IPLT1  , IPL, 3);
Sbit (IPLX1  , IPL, 2);
Sbit (IPLT0  , IPL, 1);
Sbit (IPLX0  , IPL, 0);

Sfr (ISEL  , 0xBA);
#define MSK_ISEL_CPLEV    0x80
#define MSK_ISEL_PRESIT   0x20
#define MSK_ISEL_RXIT     0x10
#define MSK_ISEL_OELEV    0x08
#define MSK_ISEL_OEEN     0x04
#define MSK_ISEL_PRESEN   0x02
#define MSK_ISEL_RXEN     0x01

/*  IEN0  */
Sbit (EA   , 0xA8, 7);
Sbit (ES   , 0xA8, 4);
Sbit (ET1  , 0xA8, 3);
Sbit (EX1  , 0xA8, 2);
Sbit (ET0  , 0xA8, 1);
Sbit (EX0  , 0xA8, 0);

/*  IPL0  */
Sbit (PS   , 0xB8, 4);
Sbit (PT1  , 0xB8, 3);
Sbit (PX1  , 0xB8, 2);
Sbit (PT0  , 0xB8, 1);
Sbit (PX0  , 0xB8, 0);

/*-------------------- SCI registers -----------------------*/

Sfr (SCTBUF, 0xAA);
Sfr (SCRBUF, 0xAA);
Sfr (SCSR  , 0xAB);
#define MSK_SCSR_REPSEL    0x10
#define MSK_SCSR_ALTKPS1   0x08
#define MSK_SCSR_ALTKPS0   0x04
#define MSK_SCSR_SCCLK1    0x02
#define MSK_SCSR_SCRS      0x01

Sfr (SCCON, 0xAC);
#define MSK_SCCON_CLK      0x80
#define MSK_SCCON_CARDC8   0x20
#define MSK_SCCON_CARDC4   0x10
#define MSK_SCCON_CARDIO   0x08
#define MSK_SCCON_CARDCLK  0x04
#define MSK_SCCON_CARDRST  0x02
#define MSK_SCCON_CARDVCC  0x01

Sfr (SCETU0, 0xAC);
#define MSK_SCETU0_ETU7    0x80
#define MSK_SCETU0_ETU6    0x40
#define MSK_SCETU0_ETU5    0x20
#define MSK_SCETU0_ETU4    0x10
#define MSK_SCETU0_ETU3    0x08
#define MSK_SCETU0_ETU2    0x04
#define MSK_SCETU0_ETU1    0x02
#define MSK_SCETU0_ETU0    0x01

Sfr (SCISR, 0xAD);
#define MSK_SCISR_SCTBE    0x80
#define MSK_SCISR_CARDIN   0x40
#define MSK_SCISR_ICARDOVF 0x20
#define MSK_SCISR_VCARDOK  0x10
#define MSK_SCISR_SCWTO    0x08
#define MSK_SCISR_SCTC     0x04
#define MSK_SCISR_SCRC     0x02
#define MSK_SCISR_SCPE     0x01

Sfr (SCETU1, 0xAD);
#define MSK_SCETU1_COMP    0x80
#define MSK_SCETU1_ETU10   0x40
#define MSK_SCETU1_ETU9    0x20
#define MSK_SCETU1_ETU8    0x10

Sfr (SCIIR, 0xAE);
#define MSK_SCIIR_SCTBI    0x80
#define MSK_SCIIR_ICARDERR 0x20
#define MSK_SCIIR_VCARDERR 0x10
#define MSK_SCIIR_SCWTI    0x08
#define MSK_SCIIR_SCTI     0x04
#define MSK_SCIIR_SCRI     0x02
#define MSK_SCIIR_SCPI     0x01

Sfr (SCIER, 0xAE);
#define MSK_SCIER_ESCTBI   0x80
#define MSK_SCIER_ICARDER  0x20
#define MSK_SCIER_EVCARDER 0x10
#define MSK_SCIER_ESCWT    0x08
#define MSK_SCIER_ESCTI    0x04
#define MSK_SCIER_ESCRI    0x02
#define MSK_SCIER_ESCPI    0x01

Sfr (SCWT0, 0xB4);
Sfr (SCGT0, 0xB4);
Sfr (SCWT1, 0xB5);
Sfr (SCGT1, 0xB5);
Sfr (SCWT2, 0xB6);
Sfr (SCICR, 0xB6);
#define MSK_SCICR_RESET    0x80
#define MSK_SCICR_CARDDET  0x40 
#define MSK_SCICR_VCARD1   0x20 
#define MSK_SCICR_VCARD0   0x10 
#define MSK_SCICR_UART     0x08 
#define MSK_SCICR_WTEN     0x04 
#define MSK_SCICR_CREP     0x02 
#define MSK_SCICR_CONV     0x01 

/*-------------------- LED registers -----------------------*/
Sfr (LEDCON, 0xF1);


#endif


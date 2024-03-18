/*H***************************************************************************
* NAME:             at8xc51snd1.h
*-----------------------------------------------------------------------------
* COMPANY:          ATMEL
* $REVISION:        1.6 $
* $DATE:            30/10/2002$
*-----------------------------------------------------------------------------
* PURPOSE:
* This file defines the AT8xC51SND1 component:
*   - Register SFRs
*   - Bit SFRs
******************************************************************************/

#ifndef _REGSND1_H_
#define _REGSND1_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/

/* RAISONANCE compiler */

#define Sfr(x, y)       sfr x = y
#define Sbit(x, y, z)   sbit x = y^z


/* C51 CORE */

Sfr (A       , 0xE0);
Sfr (ACC     , 0xE0);
Sfr (B       , 0xF0);
Sfr (PSW     , 0xD0);
Sfr (SP      , 0x81);
Sfr (DPL     , 0x82);
Sfr (DPH     , 0x83);

Sbit (CY     , 0xD0, 7);    /* PSW */
Sbit (AC     , 0xD0, 6);
Sbit (F0     , 0xD0, 5);
Sbit (RS1    , 0xD0, 4);
Sbit (RS0    , 0xD0, 3);
Sbit (OV     , 0xD0, 2);
Sbit (F1     , 0xD0, 1);
Sbit (P      , 0xD0, 0);


/* SYSTEM MANAGEMENT */

Sfr (PCON    , 0x87);
Sfr (AUXR    , 0x8E);
Sfr (AUXR1   , 0xA2);
Sfr (NVERS   , 0xFB);


/* PLL & CLOCK */

Sfr (CKCON   , 0x8F);
Sfr (PLLCON  , 0xE9);
Sfr (PLLDIV0 , 0xEE);
Sfr (PLLNDIV , 0xEE);
Sfr (PLLDIV1 , 0xEF);
Sfr (PLLRDIV , 0xEF);


/* INTERRUPT */

Sfr (IEN0    , 0xA8);
Sfr (IPL0    , 0xB8);
Sfr (IPH0    , 0xB7);
Sfr (IEN1    , 0xB1);
Sfr (IPL1    , 0xB2);
Sfr (IPH1    , 0xB3);

Sbit (EA     , 0xA8, 7);    /* IEN0 */
Sbit (EAUD   , 0xA8, 6);
Sbit (ES     , 0xA8, 4);
Sbit (ET1    , 0xA8, 3);
Sbit (EX1    , 0xA8, 2);
Sbit (ET0    , 0xA8, 1);
Sbit (EX0    , 0xA8, 0);

Sbit (IPLAUD , 0xB8, 6);    /* IPL0 */
Sbit (IPLS   , 0xB8, 4);
Sbit (IPLT1  , 0xB8, 3);
Sbit (IPLX1  , 0xB8, 2);
Sbit (IPLT0  , 0xB8, 1);
Sbit (IPLX0  , 0xB8, 0);


/* PORTS */

Sfr (P0      , 0x80);
Sfr (P1      , 0x90);
Sfr (P2      , 0xA0);
Sfr (P3      , 0xB0);
Sfr (P4      , 0xC0);
Sfr (P5      , 0xD8);

Sbit (P0_7   , 0x80, 7);    /* P0 */
Sbit (P0_6   , 0x80, 6);
Sbit (P0_5   , 0x80, 5);
Sbit (P0_4   , 0x80, 4);
Sbit (P0_3   , 0x80, 3);
Sbit (P0_2   , 0x80, 2);
Sbit (P0_1   , 0x80, 1);
Sbit (P0_0   , 0x80, 0);

Sbit (P1_7   , 0x90, 7);    /* P1 */
Sbit (P1_6   , 0x90, 6);
Sbit (P1_5   , 0x90, 5);
Sbit (P1_4   , 0x90, 4);
Sbit (P1_3   , 0x90, 3);
Sbit (P1_2   , 0x90, 2);
Sbit (P1_1   , 0x90, 1);
Sbit (P1_0   , 0x90, 0);

Sbit (SDA    , 0x90, 7);    /* P1 */
Sbit (SCL    , 0x90, 6);
Sbit (KIN3   , 0x90, 3);
Sbit (KIN2   , 0x90, 2);
Sbit (KIN1   , 0x90, 1);
Sbit (KIN0   , 0x90, 0);

Sbit (P2_7   , 0xA0, 7);    /* P2 */
Sbit (P2_6   , 0xA0, 6);
Sbit (P2_5   , 0xA0, 5);
Sbit (P2_4   , 0xA0, 4);
Sbit (P2_3   , 0xA0, 3);
Sbit (P2_2   , 0xA0, 2);
Sbit (P2_1   , 0xA0, 1);
Sbit (P2_0   , 0xA0, 0);

Sbit (P3_7   , 0xB0, 7);    /* P3 */
Sbit (P3_6   , 0xB0, 6);
Sbit (P3_5   , 0xB0, 5);
Sbit (P3_4   , 0xB0, 4);
Sbit (P3_3   , 0xB0, 3);
Sbit (P3_2   , 0xB0, 2);
Sbit (P3_1   , 0xB0, 1);
Sbit (P3_0   , 0xB0, 0);

Sbit (RD     , 0xB0, 7);    /* P3 */
Sbit (WR     , 0xB0, 6);
Sbit (T1     , 0xB0, 5);
Sbit (T0     , 0xB0, 4);
Sbit (INT1   , 0xB0, 3);
Sbit (INT0   , 0xB0, 2);
Sbit (TXD    , 0xB0, 1);
Sbit (RXD    , 0xB0, 0);

Sbit (P4_7   , 0xC0, 7);    /* P4 */
Sbit (P4_6   , 0xC0, 6);
Sbit (P4_5   , 0xC0, 5);
Sbit (P4_4   , 0xC0, 4);
Sbit (P4_3   , 0xC0, 3);
Sbit (P4_2   , 0xC0, 2);
Sbit (P4_1   , 0xC0, 1);
Sbit (P4_0   , 0xC0, 0);

Sbit (SS_    , 0xC0, 3);    /* P4 */
Sbit (SCK    , 0xC0, 2);
Sbit (MOSI   , 0xC0, 1);
Sbit (MISO   , 0xC0, 0);

Sbit (P5_3   , 0xD8, 3);    /* P5 */
Sbit (P5_2   , 0xD8, 2);
Sbit (P5_1   , 0xD8, 1);
Sbit (P5_0   , 0xD8, 0);


/* FLASH MEMORY */

Sfr (FCON    , 0xD1);


/* TIMERS */

Sfr (TCON    , 0x88);
Sfr (TMOD    , 0x89);
Sfr (TL0     , 0x8A);
Sfr (TL1     , 0x8B);
Sfr (TH0     , 0x8C);
Sfr (TH1     , 0x8D);

Sbit (TF1    , 0x88, 7);    /* TCON */
Sbit (TR1    , 0x88, 6);
Sbit (TF0    , 0x88, 5);
Sbit (TR0    , 0x88, 4);
Sbit (IE1    , 0x88, 3);
Sbit (IT1    , 0x88, 2);
Sbit (IE0    , 0x88, 1);
Sbit (IT0    , 0x88, 0);


/* WATCHDOG */

Sfr (WDTRST  , 0xA6);
Sfr (WDTPRG  , 0xA7);


/* AUDIO INTERFACE */

Sfr (AUDCON0 , 0x9A);
Sfr (AUDCON1 , 0x9B);
Sfr (AUDSTA  , 0x9C);
Sfr (AUDDAT  , 0x9D);
Sfr (AUDCLK  , 0xEC);


/* USB CONTROLLER */

Sfr (USBCON  , 0xBC);
Sfr (USBADDR , 0xC6);
Sfr (USBINT  , 0xBD);
Sfr (USBIEN  , 0xBE);
Sfr (UEPNUM  , 0xC7);
Sfr (UEPCONX , 0xD4);
Sfr (UEPSTAX , 0xCE);
Sfr (UEPRST  , 0xD5);
Sfr (UEPINT  , 0xF8);
Sfr (UEPIEN  , 0xC2);
Sfr (UEPDATX , 0xCF);
Sfr (UBYCTX  , 0xE2);
Sfr (UFNUML  , 0xBA);
Sfr (UFNUMH  , 0xBB);
Sfr (USBCLK  , 0xEA);

Sbit (EP3INT , 0xF8, 3);    /* UEPINT */
Sbit (EP2INT , 0xF8, 2);
Sbit (EP1INT , 0xF8, 1);
Sbit (EP0INT , 0xF8, 0);


/* MMC CONTROLLER */

Sfr (MMDAT   , 0xDC);
Sfr (MMCMD   , 0xDD);
Sfr (MMSTA   , 0xDE);
Sfr (MMMSK   , 0xDF);
Sfr (MMCON0  , 0xE4);
Sfr (MMCON1  , 0xE5);
Sfr (MMCON2  , 0xE6);
Sfr (MMINT   , 0xE7);
Sfr (MMCLK   , 0xED);


/* IDE CONTROLLER */

Sfr (DAT16H  , 0xF9);


/* UART */

Sfr (SCON    , 0x98);
Sfr (SBUF    , 0x99);
Sfr (SADDR   , 0xA9);
Sfr (SADEN   , 0xB9);
Sfr (BDRCON  , 0x92);
Sfr (BRL     , 0x91);

Sbit (SM0    , 0x98, 7);    /* SCON */
Sbit (FE     , 0x98, 7);
Sbit (SM1    , 0x98, 6);
Sbit (SM2    , 0x98, 5);
Sbit (REN    , 0x98, 4);
Sbit (TB8    , 0x98, 3);
Sbit (RB8    , 0x98, 2);
Sbit (TI     , 0x98, 1);
Sbit (RI     , 0x98, 0);


/* SPI CONTROLLER */

Sfr (SPCON   , 0xC3);
Sfr (SPSTA   , 0xC4);
Sfr (SPDAT   , 0xC5);


/* I2C CONTROLLER */

Sfr (SSCON   , 0x93);
Sfr (SSSTA   , 0x94);
Sfr (SSDAT   , 0x95);
Sfr (SSADR   , 0x96);


/* KEYBOARD */

Sfr (KBCON   , 0xA3);
Sfr (KBSTA   , 0xA4);


/* ADC CONVERTER */

Sfr (ADCON   , 0xF3);
Sfr (ADDL    , 0xF4);
Sfr (ADDH    , 0xF5);
Sfr (ADCLK   , 0xF2);


#endif        /* _REGSND1_H_ */

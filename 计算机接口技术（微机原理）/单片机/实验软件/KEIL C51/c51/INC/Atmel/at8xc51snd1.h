/*H***************************************************************************
* NAME:             at8xc51snd1.h
*-----------------------------------------------------------------------------
* COMPANY:          ATMEL
* $REVISION:        1.6 $
* $DATE:            30/10/2002$
*-----------------------------------------------------------------------------
* PURPOSE:
* This file defines the AT8xC51SND1 component:
*   - Register sfrs
*   - Bit sfrs
******************************************************************************/

#ifndef _REGSND1_H_
#define _REGSND1_H_

/* C51 CORE */

sfr ACC     = 0xE0;
sfr B       = 0xF0;
sfr PSW     = 0xD0;
sfr SP      = 0x81;
sfr DPL     = 0x82;
sfr DPH     = 0x83;

sbit CY     = 0xD0^7;    /* PSW */
sbit AC     = 0xD0^6;
sbit F0     = 0xD0^5;
sbit RS1    = 0xD0^4;
sbit RS0    = 0xD0^3;
sbit OV     = 0xD0^2;
sbit F1     = 0xD0^1;
sbit P      = 0xD0^0;


/* SYSTEM MANAGEMENT */

sfr PCON    = 0x87;
sfr AUXR    = 0x8E;
sfr AUXR1   = 0xA2;
sfr NVERS   = 0xFB;


/* PLL & CLOCK */

sfr CKCON   = 0x8F;
sfr PLLCON  = 0xE9;
sfr PLLDIV0 = 0xEE;
sfr PLLNDIV = 0xEE;
sfr PLLDIV1 = 0xEF;
sfr PLLRDIV = 0xEF;


/* INTERRUPT */

sfr IEN0    = 0xA8;
sfr IPL0    = 0xB8;
sfr IPH0    = 0xB7;
sfr IEN1    = 0xB1;
sfr IPL1    = 0xB2;
sfr IPH1    = 0xB3;

sbit EA     = 0xA8^7;    /* IEN0 */
sbit EAUD   = 0xA8^6;
sbit EMP3   = 0xA8^5;
sbit ES     = 0xA8^4;
sbit ET1    = 0xA8^3;
sbit EX1    = 0xA8^2;
sbit ET0    = 0xA8^1;
sbit EX0    = 0xA8^0;

sbit IPLAUD = 0xB8^6;    /* IPL0 */
sbit IPLMP3 = 0xB8^5;
sbit IPLS   = 0xB8^4;
sbit IPLT1  = 0xB8^3;
sbit IPLX1  = 0xB8^2;
sbit IPLT0  = 0xB8^1;
sbit IPLX0  = 0xB8^0;


/* PORTS */

sfr P0      = 0x80;
sfr P1      = 0x90;
sfr P2      = 0xA0;
sfr P3      = 0xB0;
sfr P4      = 0xC0;
sfr P5      = 0xD8;

sbit P0_7   = 0x80^7;    /* P0 */
sbit P0_6   = 0x80^6;
sbit P0_5   = 0x80^5;
sbit P0_4   = 0x80^4;
sbit P0_3   = 0x80^3;
sbit P0_2   = 0x80^2;
sbit P0_1   = 0x80^1;
sbit P0_0   = 0x80^0;

sbit P1_7   = 0x90^7;    /* P1 */
sbit P1_6   = 0x90^6;
sbit P1_5   = 0x90^5;
sbit P1_4   = 0x90^4;
sbit P1_3   = 0x90^3;
sbit P1_2   = 0x90^2;
sbit P1_1   = 0x90^1;
sbit P1_0   = 0x90^0;

sbit SDA    = 0x90^7;    /* P1 */
sbit SCL    = 0x90^6;
sbit KIN3   = 0x90^3;
sbit KIN2   = 0x90^2;
sbit KIN1   = 0x90^1;
sbit KIN0   = 0x90^0;

sbit P2_7   = 0xA0^7;    /* P2 */
sbit P2_6   = 0xA0^6;
sbit P2_5   = 0xA0^5;
sbit P2_4   = 0xA0^4;
sbit P2_3   = 0xA0^3;
sbit P2_2   = 0xA0^2;
sbit P2_1   = 0xA0^1;
sbit P2_0   = 0xA0^0;

sbit P3_7   = 0xB0^7;    /* P3 */
sbit P3_6   = 0xB0^6;
sbit P3_5   = 0xB0^5;
sbit P3_4   = 0xB0^4;
sbit P3_3   = 0xB0^3;
sbit P3_2   = 0xB0^2;
sbit P3_1   = 0xB0^1;
sbit P3_0   = 0xB0^0;

sbit RD     = 0xB0^7;    /* P3 */
sbit WR     = 0xB0^6;
sbit T1     = 0xB0^5;
sbit T0     = 0xB0^4;
sbit INT1   = 0xB0^3;
sbit INT0   = 0xB0^2;
sbit TXD    = 0xB0^1;
sbit RXD    = 0xB0^0;

sbit P4_7   = 0xC0^7;    /* P4 */
sbit P4_6   = 0xC0^6;
sbit P4_5   = 0xC0^5;
sbit P4_4   = 0xC0^4;
sbit P4_3   = 0xC0^3;
sbit P4_2   = 0xC0^2;
sbit P4_1   = 0xC0^1;
sbit P4_0   = 0xC0^0;

sbit SS_    = 0xC0^3;    /* P4 */
sbit SCK    = 0xC0^2;
sbit MOSI   = 0xC0^1;
sbit MISO   = 0xC0^0;

sbit P5_3   = 0xD8^3;    /* P5 */
sbit P5_2   = 0xD8^2;
sbit P5_1   = 0xD8^1;
sbit P5_0   = 0xD8^0;


/* FLASH MEMORY */

sfr FCON    = 0xD1;


/* TIMERS */

sfr TCON    = 0x88;
sfr TMOD    = 0x89;
sfr TL0     = 0x8A;
sfr TL1     = 0x8B;
sfr TH0     = 0x8C;
sfr TH1     = 0x8D;

sbit TF1    = 0x88^7;    /* TCON */
sbit TR1    = 0x88^6;
sbit TF0    = 0x88^5;
sbit TR0    = 0x88^4;
sbit IE1    = 0x88^3;
sbit IT1    = 0x88^2;
sbit IE0    = 0x88^1;
sbit IT0    = 0x88^0;


/* WATCHDOG */

sfr WDTRST  = 0xA6;
sfr WDTPRG  = 0xA7;


/* MP3 DECODER */

sfr MP3CON  = 0xAA;
sfr MP3STA  = 0xC8;
sfr MP3STA1 = 0xAF;
sfr MP3DAT  = 0xAC;
sfr MP3ANC  = 0xAD;
sfr MP3VOL  = 0x9E;
sfr MP3VOR  = 0x9F;
sfr MP3BAS  = 0xB4;
sfr MP3MED  = 0xB5;
sfr MP3TRE  = 0xB6;
sfr MP3CLK  = 0xEB;
sfr MP3DBG  = 0xAE; /* hidden register */

sbit MPANC  = 0xC8^7;    /* MP3STA */
sbit MPREQ  = 0xC8^6;
sbit ERRLAY = 0xC8^5;
sbit ERRSYN = 0xC8^4;
sbit ERRCRC = 0xC8^3;
sbit MPFS1  = 0xC8^2;
sbit MPFS0  = 0xC8^1;
sbit MPVER  = 0xC8^0;


/* AUDIO INTERFACE */

sfr AUDCON0 = 0x9A;
sfr AUDCON1 = 0x9B;
sfr AUDSTA  = 0x9C;
sfr AUDDAT  = 0x9D;
sfr AUDCLK  = 0xEC;


/* USB CONTROLLER */

sfr USBCON  = 0xBC;
sfr USBADDR = 0xC6;
sfr USBINT  = 0xBD;
sfr USBIEN  = 0xBE;
sfr UEPNUM  = 0xC7;
sfr UEPCONX = 0xD4;
sfr UEPSTAX = 0xCE;
sfr UEPRST  = 0xD5;
sfr UEPINT  = 0xF8;
sfr UEPIEN  = 0xC2;
sfr UEPDATX = 0xCF;
sfr UBYCTX  = 0xE2;
sfr UFNUML  = 0xBA;
sfr UFNUMH  = 0xBB;
sfr USBCLK  = 0xEA;

sbit EP3INT = 0xF8^3;    /* UEPINT */
sbit EP2INT = 0xF8^2;
sbit EP1INT = 0xF8^1;
sbit EP0INT = 0xF8^0;


/* MMC CONTROLLER */

sfr MMDAT   = 0xDC;
sfr MMCMD   = 0xDD;
sfr MMSTA   = 0xDE;
sfr MMMSK   = 0xDF;
sfr MMCON0  = 0xE4;
sfr MMCON1  = 0xE5;
sfr MMCON2  = 0xE6;
sfr MMINT   = 0xE7;
sfr MMCLK   = 0xED;


/* IDE CONTROLLER */

sfr DAT16H  = 0xF9;


/* UART */

sfr SCON    = 0x98;
sfr SBUF    = 0x99;
sfr SADDR   = 0xA9;
sfr SADEN   = 0xB9;
sfr BDRCON  = 0x92;
sfr BRL     = 0x91;

sbit SM0    = 0x98^7;    /* SCON */
sbit FE     = 0x98^7;
sbit SM1    = 0x98^6;
sbit SM2    = 0x98^5;
sbit REN    = 0x98^4;
sbit TB8    = 0x98^3;
sbit RB8    = 0x98^2;
sbit TI     = 0x98^1;
sbit RI     = 0x98^0;


/* SPI CONTROLLER */

sfr SPCON   = 0xC3;
sfr SPSTA   = 0xC4;
sfr SPDAT   = 0xC5;


/* I2C CONTROLLER */

sfr SSCON   = 0x93;
sfr SSSTA   = 0x94;
sfr SSDAT   = 0x95;
sfr SSADR   = 0x96;


/* KEYBOARD */

sfr KBCON   = 0xA3;
sfr KBSTA   = 0xA4;


/* ADC CONVERTER */

sfr ADCON   = 0xF3;
sfr ADDL    = 0xF4;
sfr ADDH    = 0xF5;
sfr ADCLK   = 0xF2;


#endif        /* _REGSND1_H_ */

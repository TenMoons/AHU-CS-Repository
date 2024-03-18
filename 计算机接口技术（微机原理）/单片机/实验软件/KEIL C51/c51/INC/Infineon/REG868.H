/*--------------------------------------------------------------------------
REG868.H

Header file for for SAB C868 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __REG868_H__
#define __REG868_H__

/*  BYTE Register  */
sfr       SP        =         0x81;
sfr       DPL       =         0x82;
sfr       DPH       =         0x83;
sfr       DPSEL     =         0x84;
sfr       PCON      =         0x87;
sfr       TCON      =         0x88;
sfr       TMOD      =         0x89;
sfr       TL0       =         0x8A;
sfr       TL1       =         0x8B;
sfr       TH0       =         0x8C;
sfr       TH1       =         0x8D;
sfr       PMCON0    =         0x8E;
sfr       CMCON     =         0x8F;
sfr       P1        =         0x90;
sfr       P1DIR     =         0x90;     // rmap=1
sfr       EXICON    =         0x91;
sfr       IRCON0    =         0x92;
sfr       IRCON1    =         0x93;
sfr       SCON      =         0x98;
sfr       SBUF      =         0x99;

sfr       WDTCON    =         0xA2;
sfr       WDTREL    =         0xA3;
sfr       TMODE     =         0xA4;
sfr       PSLRL     =         0xA6;
sfr       IEN0      =         0xA8;
sfr       IEN1      =         0xA9;
sfr       IEN2      =         0xAA;
sfr       IP1       =         0xAC;
sfr       SYSCON0   =         0xAD;

sfr       SYSCON1   =         0xAF;
sfr       P3        =         0xB0;
sfr       P3DIR     =         0xB0;    // rmap=1
sfr       P3ALT     =         0xB1;
sfr       WDTL      =         0xB2;
sfr       WDTH      =         0xB3;
sfr       P1ALT     =         0xB4;
sfr       CC63SRL   =         0xB6;
sfr       CC63SRH   =         0xB7;
sfr       IP0       =         0xB8;
sfr       ISSL      =         0xBC;
sfr       ISRL      =         0xBC;     // rmap=1
sfr       ISSH      =         0xBD;
sfr       ISRH      =         0xBD;     // rmap=1
sfr       IENL      =         0xBE;
sfr       INPL      =         0xBE;     // rmap=1
sfr       IENH      =         0xBF;
sfr       INPH      =         0xBF;     // rmap=1
sfr       SCUWDT    =         0xC0;
sfr       CC60RL    =         0xC2;
sfr       CC60RH    =         0xC3;
sfr       CC61RL    =         0xC4;
sfr       CC61RH    =         0xC5;
sfr       CC62RL    =         0xC6;
sfr       CC62RH    =         0xC7;
sfr       T2CON     =         0xC8;
sfr       T2MOD     =         0xC9;
sfr       RC2L      =         0xCA;
sfr       RC2H      =         0xCB;
sfr       TL2       =         0xCC;
sfr       TH2       =         0xCD;
sfr       TRPCTRL   =         0xCE;
sfr       TRPCTRH   =         0xCF;
sfr       PSW       =         0xD0;
sfr       T13PL     =         0xD2;
sfr       T13PH     =         0xD3;
sfr       CC63RL    =         0xD4;
sfr       CC63RH    =         0xD5;
sfr       MODCTRL   =         0xD6;     // rmap=1
sfr       MCMCTRL   =         0xD6;
sfr       MODCTRH   =         0xD7;     // rmap=1
sfr       MCMCTRH   =         0xD7;
sfr       ADCON0    =         0xD8;
sfr       ADCON1    =         0xD9;

sfr       ADDATH    =         0xDB;
sfr       MCMOUTL   =         0xDC;
sfr       MCMOUTSL  =         0xDC;     // rmap=1
sfr       MCMOUTH   =         0xDD;
sfr       MCMOUTSH  =         0xDD;     // rmap=1
sfr       T12PL     =         0xDE;
sfr       T12PH     =         0xDF;
sfr       ACC       =         0xE0;
sfr       TCTR0L    =         0xE2;
sfr       TCTR0H    =         0xE3;
sfr       ISL       =         0xE4;
sfr       ISH       =         0xE5;
sfr       T12DTCL   =         0xE6;
sfr       T12DTCH   =         0xE7;
sfr       PMCON1    =         0xE8;
sfr       CMPMODIFL =         0xEA;
sfr       CMPMODIFH =         0xEB;
sfr       T12L      =         0xEC;
sfr       T12H      =         0xED;
sfr       T13L      =         0xEE;
sfr       T13H      =         0xEF;
sfr       B         =         0xF0;
sfr       TCTR2L    =         0xF2;     // rmap=1
sfr       TCTR4L    =         0xF2;
sfr       TCTR4H    =         0xF3;
sfr       TCTR2H    =         0xF3;     // rmap=1
sfr       CMPSTATL  =         0xF4;
sfr       CMPSTATH  =         0xF5;
sfr       T12MSELL  =         0xF6;
sfr       T12MSELH  =         0xF7;
sfr       PMCON2    =         0xF8;
sfr       CCU_CC60RL=         0xFA;
sfr       CCU_CC60RH=         0xFB;
sfr       CCU_CC61RL=         0xFC;
sfr       CCU_CC61RH=         0xFD;
sfr       CCU_CC62RL=         0xFE;
sfr       CCU_CC62RH=         0xFF;

/* BIT Register */

/* PSW */
sbit  CY     = PSW^7;
sbit  AC     = PSW^6;
sbit  F0     = PSW^5;
sbit  RS1    = PSW^4;
sbit  RS0    = PSW^3;
sbit  OV     = PSW^2;
sbit  F1     = PSW^1;
sbit  P      = PSW^0;

/* SCUWDT */
sbit  PLLR   = SCUWDT^6;
sbit  WDTR   = SCUWDT^4;
sbit  WDTEOI = SCUWDT^3;
sbit  WDTDIS = SCUWDT^2;
sbit  WDTRS  = SCUWDT^1;
sbit  WDTRE  = SCUWDT^0;

/* PMCON1 */
sbit  CCUDIS = PMCON1^2;
sbit  T2DIS  = PMCON1^1;
sbit  ADCDIS = PMCON1^0;

/* PMCON2 */
sbit  CCUST = PMCON2^2;
sbit  T2ST  = PMCON2^1;
sbit  ADCST = PMCON2^0;

/* IEN0 */
sbit  EA     = IEN0^7;
sbit  ET2    = IEN0^5;
sbit  ES     = IEN0^4;
sbit  ET1    = IEN0^3;
sbit  EX1    = IEN0^2;
sbit  ET0    = IEN0^1;
sbit  EX0    = IEN0^0;


/* TCON */
sbit  TF1    = TCON^7;
sbit  TR1    = TCON^6;
sbit  TF0    = TCON^5;
sbit  TR0    = TCON^4;
sbit  IE1    = TCON^3;
sbit  IT1    = TCON^2;
sbit  IE0    = TCON^1;
sbit  IT0    = TCON^0;

/* SCON */
sbit  SM0   = SCON^7;
sbit  SM1   = SCON^6;
sbit  SM2   = SCON^5;
sbit  REN   = SCON^4;
sbit  TB8   = SCON^3;
sbit  RB8   = SCON^2;
sbit  TI    = SCON^1;
sbit  RI    = SCON^0;

/* P1 */
sbit  RXD    = P1^4;
sbit  INT3   = P1^3;
sbit  P12    = P1^2;
sbit  P11    = P1^1;
sbit  TXD    = P1^0;

/* P3 */
sbit  CC0      = P3^7;
sbit  COUT0    = P3^6;
sbit  CC1      = P3^5;
sbit  COUT1    = P3^4;
sbit  CC2      = P3^3;
sbit  COUT2    = P3^2;
sbit  CTRAP    = P3^1;
sbit  COUT3    = P3^0;

/* T2CON */
sbit  TF2    = T2CON^7;
sbit  EXF2   = T2CON^6;
sbit  RCLK   = T2CON^5;
sbit  TCLK   = T2CON^4;
sbit  EXEN2  = T2CON^3;
sbit  TR2    = T2CON^2;
sbit  CT2    = T2CON^1;
sbit  CP     = T2CON^0;

/* ADCON0 */
sbit  ADST   = ADCON0^7;
sbit  ADBSY  = ADCON0^6;
sbit  ADM1   = ADCON0^5;
sbit  ADM0   = ADCON0^4;
sbit  ADCH2  = ADCON0^2;
sbit  ADCH1  = ADCON0^1;
sbit  ADCH0  = ADCON0^0;

#endif





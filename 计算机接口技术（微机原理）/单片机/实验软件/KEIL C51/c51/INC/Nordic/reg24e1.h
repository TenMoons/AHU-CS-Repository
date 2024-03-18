/*--------------------------------------------------------------------------
 * reg24e1.h
 *
 * Header file for the Nordic VLSI nRF24E1 2.4Ghz RF transceiver with
 * embedded 8051 compatible microcontroller.
 *
 * $Revision: 1 $
 *
 *------------------------------------------------------------------------*/
#ifndef __REG24E1_H__
#define __REG24E1_H__

/*  BYTE Registers  */

sfr P0        = 0x80;
sfr SP        = 0x81;
sfr DPL       = 0x82;
sfr DPH       = 0x83;
sfr DPL1      = 0x84;
sfr DPH1      = 0x85;
sfr DPS       = 0x86;
sfr PCON      = 0x87;
sfr TCON      = 0x88;
sfr TMOD      = 0x89;
sfr TL0       = 0x8A;
sfr TL1       = 0x8B;
sfr TH0       = 0x8C;
sfr TH1       = 0x8D;
sfr CKCON     = 0x8E;
sfr P1        = 0x90;
sfr EXIF      = 0x91;
sfr MPAGE     = 0x92;
sfr SCON      = 0x98;
sfr SBUF      = 0x99;
sfr IE        = 0xA8;
sfr IP        = 0xB8;
sfr T2CON     = 0xC8;
sfr RCAP2L    = 0xCA;
sfr RCAP2H    = 0xCB;
sfr TL2       = 0xCC;
sfr TH2       = 0xCD;
sfr PSW       = 0xD0;
sfr EICON     = 0xD8;
sfr ACC       = 0xE0;
sfr B         = 0xF0;                
sfr EIE       = 0xE8;
sfr EIP       = 0xF8;

sfr P0_DIR    = 0x94;
sfr P0_ALT    = 0x95;
sfr P1_DIR    = 0x96;
sfr P1_ALT    = 0x97;
sfr RADIO     = 0xA0;
sfr ADCCON    = 0xA1;
sfr ADCDATAH  = 0xA2;
sfr ADCDATAL  = 0xA3;
sfr ADCSTATIC = 0xA4;
sfr PWMCON    = 0xA9;
sfr PWMDUTY   = 0xAA;
sfr REGX_MSB  = 0xAB;
sfr REGX_LSB  = 0xAC;
sfr REGX_CTRL = 0xAD;
sfr RSTREAS   = 0xB1;
sfr SPI_DATA  = 0xB2;
sfr SPI_CTRL  = 0xB3;
sfr SPICLK    = 0xB4;
sfr TICK_DV   = 0xB5;
sfr CK_CTRL   = 0xB6;

/*  BIT Registers  */

/*  PSW */
sbit CY       = PSW^7;
sbit AC       = PSW^6;
sbit F0       = PSW^5;
sbit RS1      = PSW^4;
sbit RS0      = PSW^3;
sbit OV       = PSW^2;
sbit F1       = PSW^1;
sbit P        = PSW^0;

/*  TCON  */
sbit TF1      = TCON^7;
sbit TR1      = TCON^6;
sbit TF0      = TCON^5;
sbit TR0      = TCON^4;
sbit IE1      = TCON^3;
sbit IT1      = TCON^2;
sbit IE0      = TCON^1;
sbit IT0      = TCON^0;

/*  IE  */
sbit EA       = IE^7;
sbit ET2      = IE^5;
sbit ES       = IE^4;
sbit ET1      = IE^3;
sbit EX1      = IE^2;
sbit ET0      = IE^1;
sbit EX0      = IE^0;

/*  IP  */
sbit PT2      = IP^5;
sbit PS       = IP^4;
sbit PT1      = IP^3;
sbit PX1      = IP^2;
sbit PT0      = IP^1;
sbit PX0      = IP^0;


/*  P0  */
sbit T1       = P0^6;
sbit T0       = P0^5;
sbit INT1     = P0^4;
sbit INT0     = P0^3;

/*  P1  */
sbit T2       = P1^0;

/*  SCON  */
sbit SM0      = SCON^7;
sbit SM1      = SCON^6;
sbit SM2      = SCON^5;
sbit REN      = SCON^4;
sbit TB8      = SCON^3;
sbit RB8      = SCON^2;
sbit TI       = SCON^1;
sbit RI       = SCON^0;

/*  T2CON  */
sbit TF2      = T2CON^7;
sbit EXF2     = T2CON^6;
sbit RCLK     = T2CON^5;
sbit TCLK     = T2CON^4;
sbit EXEN2    = T2CON^3;
sbit TR2      = T2CON^2;
sbit C_T2     = T2CON^1;
sbit CP_RL2   = T2CON^0;

/*  EICON  */
sbit SMOD1    = EICON^7;
sbit WDTI     = EICON^3;

/*  EIE  */
sbit EWDI     = EIE^4;
sbit EX5      = EIE^3;
sbit EX4      = EIE^2;
sbit EX3      = EIE^1;
sbit EX2      = EIE^0;

/*  EIP  */
sbit PWDI     = EIP^4;
sbit PX5      = EIP^3;
sbit PX4      = EIP^2;
sbit PX3      = EIP^1;
sbit PX2      = EIP^0;

/* RADIO */
sbit PWR_UP   = RADIO^7;
sbit DR2      = RADIO^6;
sbit CE       = RADIO^6;
sbit CLK2     = RADIO^5;
sbit DOUT2    = RADIO^4;
sbit CS       = RADIO^3;
sbit DR1      = RADIO^2;
sbit CLK1     = RADIO^1;
sbit DATA     = RADIO^0;

#endif

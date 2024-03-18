/*------------------------------------------------------------------
REG750.H

Header file for the Philips 83C750/87C750 
Copyright (c) 1995-1997 Keil Elektronik GmbH  All rights reserved.
------------------------------------------------------------------*/

/*  BYTE Register  */
sfr P0   = 0x80;
sfr SP   = 0x81;
sfr DPL  = 0x82;
sfr DPH  = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TL   = 0x8A;
sfr RTL  = 0x8B;
sfr TH   = 0x8C;
sfr RTH  = 0x8D;

sfr P1   = 0x90;
sfr IE   = 0xA8;
sfr P3   = 0xB0;
sfr PSW  = 0xD0;
sfr ACC  = 0xE0;
sfr B    = 0xF0;

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
sbit GATE = 0x8F;
sbit CT   = 0x8E;
sbit TF   = 0x8D;
sbit TR   = 0x8C;
sbit IE0  = 0x8B;
sbit IT0  = 0x8A;
sbit IE1  = 0x89;
sbit IT1  = 0x88;

/*  IE   */
sbit EX1  = 0xAA;
sbit ET0  = 0xA9;
sbit EX0  = 0xA8;


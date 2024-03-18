/*--------------------------------------------------------------------------
AT89S4D12.H

Header file for Atmel AT89S4D12 microcontroller.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __AT89S4D12_H__
#define __AT89S4D12_H__

/*  BYTE Register  */
sfr P1   = 0x90;
sfr PSW  = 0xD0;
sfr ACC  = 0xE0;
sfr B    = 0xF0;
sfr DP0L = 0x82;
sfr DP0H = 0x83;
sfr DP1L = 0x84;
sfr DP1H = 0x85;
sfr PCON = 0x87;
sfr SPSR = 0xAA;
sfr SPCR = 0xD5;
sfr MCON = 0x96;
sfr SPDR = 0x86;

/*  BIT Register  */
/*  PSW   */
sbit CY   = 0xD7;
sbit AC   = 0xD6;
sbit F0   = 0xD5;
sbit RS1  = 0xD4;
sbit RS0  = 0xD3;
sbit OV   = 0xD2;
sbit P    = 0xD0;

#endif

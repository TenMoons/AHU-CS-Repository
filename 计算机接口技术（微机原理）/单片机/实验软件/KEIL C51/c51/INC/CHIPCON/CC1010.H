/*--------------------------------------------------------------------------
CC1010.H

Header file for ChipCon CC1010 microcontroller.
Copyright (c) 2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __CC1010_H__
#define __CC1010_H__

/*  BYTE Registers  */
sfr ACC 	= 0xE0; // - Accumulator Register 
sfr ADCON 	= 0x93; // - ADC Control Register
sfr ADCON2	= 0x96; // - ADC Control Register 2
sfr ADDATH 	= 0x95; // - ADC Data Register, High Bits
sfr ADDATL 	= 0x94; // - ADC Data Register, Low Byte
sfr ADTRH 	= 0x97; // - ADC Threshold Register 
sfr B 		= 0xF0; // - B Register 
sfr BSYNC 	= 0xD4; // - Byte Synchronisation Register 
sfr CAL 	= 0xE5; // - PLL Calibration Control Register 
sfr CHVER 	= 0x9F; // - Chip Version / Revision Register
sfr CKCON 	= 0x8E; // - Timer Clock rate Control Register
sfr CRPCNT 	= 0xC6; // - Encryption / Decryption Counter 
sfr CRPCON 	= 0xC3; // - Encryption / Decryption Control Register
sfr CRPDAT 	= 0xC5; // - Encryption / Decryption Data Location Register 
sfr CRPINI0	= 0xB4; // - DES Initialisation Vector 
sfr CRPINI1	= 0xB5; // - DES Initialisation Vector 
sfr CRPINI2	= 0xB6; // - DES Initialisation Vector 
sfr CRPINI3	= 0xB7; // - DES Initialisation Vector 
sfr CRPINI4	= 0xBC; // - DES Initialisation Vector 
sfr CRPINI5	= 0xBD; // - DES Initialisation Vector 
sfr CRPINI6	= 0xBE; // - DES Initialisation Vector 
sfr CRPINI7	= 0xBF; // - DES Initialisation Vector 
sfr CRPKEY 	= 0xC4; // - Encryption / Decryption Key Location Register 
sfr CURRENT 	= 0xE1; // - RF Current Control Register
sfr DPH0 	= 0x83; // - Data Pointer 0, high byte 
sfr DPH1 	= 0x85; // - Data Pointer 1, high byte 
sfr DPL0 	= 0x82; // - Data Pointer 0, low byte 
sfr DPL1 	= 0x84; // - Data Pointer 1, low byte 
sfr DPS 	= 0x86; // - Data Pointer Select 
sfr EICON 	= 0xD8; // - Extended Interrupt Control 
sfr EIE 	= 0xE8; // - Extended Interrupt Enable Register 
sfr EIP 	= 0xF8; // - Extended Interrupt Priority Register 
sfr EXIF 	= 0x91; // - Extended Interrupt Flag
sfr FLADR 	= 0xAE; // - Flash Write Address Register 
sfr FLCON 	= 0xAF; // - Flash Write Control Register 
sfr FLTIM 	= 0xDD; // - Flash Write Timing Register 
sfr FREND 	= 0xEE; // - Front End Control Register 
sfr FREQ_0A 	= 0xCA; // - Frequency A, Control Register 0
sfr FREQ_0B 	= 0xCD; // - Frequency B, Control Register 0 
sfr FREQ_1A 	= 0xCB; // - Frequency A, Control Register 1
sfr FREQ_1B 	= 0xCE; // - Frequency B, Control Register 1
sfr FREQ_2A 	= 0xCC; // ¨C Frequency A, Control Register 2 
sfr FREQ_2B 	= 0xCF; // - Frequency B, Control Register 2
sfr FSCTRL 	= 0xEC; // - Frequency Synthesiser Control Register 
sfr FSDELAY 	= 0xE9; // - Frequency Shaping Delay Control Register 
sfr FSEP0 	= 0xEA; // - Frequency Separation Control Register 0
sfr FSEP1 	= 0xEB; // - Frequency Separation Control Register 1
sfr FSHAPE0 	= 0xF1; // - Frequency Shaping Register
sfr FSHAPE1 	= 0xF2; // - Frequency Shaping Register
sfr FSHAPE2 	= 0xF3; // - Frequency Shaping Register
sfr FSHAPE3 	= 0xF4; // - Frequency Shaping Register
sfr FSHAPE4 	= 0xF5; // - Frequency Shaping Register
sfr FSHAPE5 	= 0xF6; // - Frequency Shaping Register
sfr FSHAPE6 	= 0xF7; // - Frequency Shaping Register
sfr IE 	= 0xA8; // - Interrupt Enable Register
sfr IP 	= 0xB8; // - Interrupt Priority Register
sfr LOCK 	= 0xE4; // - PLL Lock Register 
sfr MATCH 	= 0xDC; // - Match Capacitor Array Control Register 
sfr MODEM0 	= 0xDB; // - Modem Control Register 0
sfr MODEM1 	= 0xDA; // - Modem Control Register 1
sfr MODEM2 	= 0xD9; // - Modem Control Register 2
sfr MPAGE 	= 0x92; // - Memory Page Select Register
sfr P0 	= 0x80; // - Port 0 Data Register 
sfr P0DIR 	= 0xA4; // - Port 0 Direction Register 
sfr P1 	= 0x90; // - Port 1 Data Register 
sfr P1DIR 	= 0xA5; // - Port 1 Direction Register 
sfr P2 	= 0xA0; // - Port 2 Data Register 
sfr P2DIR 	= 0xA6; // - Port 2 Direction Register 
sfr P3 	= 0xB0; // - Port 3 Data Register 
sfr P3DIR 	= 0xA7; // - Port 3 Direction Register 
sfr PA_POW 	= 0xE2; // - PA Output Power Control Register
sfr PCON 	= 0x87; // - Power Control Register
sfr PDET 	= 0xD3; // - Preamble Detection Control Register 
sfr PLL 	= 0xE3; // - PLL Control Register 
sfr PRESCALER	= 0xE6; // - Prescaler Control Register 
sfr PSW 	= 0xD0; // - Program Status Word 
sfr RADRH 	= 0xBB; // - Replacement address, high byte 
sfr RADRL 	= 0xBA; // - Replacement address, low byte 
sfr RANCON 	= 0xC7; // - Random Bit Generator Control Register 
sfr RDATA 	= 0xB9; // - Replacement Data 
sfr RESERVED 	= 0xE7; // - Reserved register, used by Chipcon debugger software
sfr RFBUF 	= 0xC9; // - RF Data Buffer
sfr RFCON 	= 0xC2; // - RF Control Register 
sfr RFMAIN 	= 0xC8; // - RF Main Control Register 
sfr RTCON 	= 0xED; // - Realtime Clock Control Register 
sfr SBUF0 	= 0x99; // - Serial Port 0, data buffer
sfr SBUF1 	= 0xC1; // – Serial Port 1, data buffer 
sfr SCON0 	= 0x98; // - Serial Port 0 Control Register 
sfr SCON1 	= 0xC0; // - Serial Port 1 Control Register
sfr SP 	= 0x81; // - Stack Pointer 
sfr SPCR 	= 0xA1; // - SPI Control Register 
sfr SPDR 	= 0xA2; // - SPI Data Register 
sfr SPSR 	= 0xA3; // - SPI Status Register
sfr T2 	= 0xAC; // - Timer 2 Low byte counter value 
sfr T2PRE 	= 0xAA; // - Timer 2 Prescaler Control 
sfr T3 	= 0xAD; // - Timer 3 Low byte counter value 
sfr T3PRE 	= 0xAB; // - Timer 3 Prescaler Control 
sfr TCON 	= 0x88; // - Timer / Counter 0 and 1 control register 
sfr TCON2 	= 0xA9; // - Timer Control register 2 
sfr TEST0 	= 0xF9; // – PLL Test Register 0 
sfr TEST1 	= 0xFA; // – PLL Test Register 1 
sfr TEST2 	= 0xFB; // – PLL Test Register 2 
sfr TEST3 	= 0xFC; // – PLL Test Register 3
sfr TEST4 	= 0xFD; // – PLL Test Register 4
sfr TEST5 	= 0xFE; // – PLL Test Register 5 
sfr TEST6 	= 0xFF; // – PLL Test Register 6 
sfr TESTMUX 	= 0xEF; // - Test Multiplexer Control Register (for prototype testing)
sfr TH0 	= 0x8C; // - Timer / Counter 0 High byte counter value 
sfr TH1 	= 0x8D; // - Timer / Counter 1 High byte counter value 
sfr TL0 	= 0x8A; // - Timer / Counter 0 Low byte counter value
sfr TL1 	= 0x8B; // - Timer / Counter 1 Low byte counter value
sfr TMOD 	= 0x89; // - Timer / Counter 0 and 1 Mode register
sfr WDT 	= 0xD2; // - Watchdog Timer Control Register 
sfr X32CON 	= 0xD1; // - 32.768 kHz Crystal Oscillator Control Register

/*  BIT Registers  */
/*  PSW  */
sbit CY    = PSW^7;
sbit AC    = PSW^6;
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;
sbit P     = PSW^0; //8052 only

/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  IE  */
sbit EA    = IE^7;
sbit ET2   = IE^5; //8052 only
sbit ES    = IE^4;
sbit ET1   = IE^3;
sbit EX1   = IE^2;
sbit ET0   = IE^1;
sbit EX0   = IE^0;

/*  IP  */
sbit PT2   = IP^5;
sbit PS    = IP^4;
sbit PT1   = IP^3;
sbit PX1   = IP^2;
sbit PT0   = IP^1;
sbit PX0   = IP^0;

/*  P3  */
sbit RD    = P3^7;
sbit WR    = P3^6;
sbit T1    = P3^5;
sbit T0    = P3^4;
sbit INT1  = P3^3;
sbit INT0  = P3^2;
sbit TXD   = P3^1;
sbit RXD   = P3^0;

/*  SCON0  */
sbit SM0   = SCON0^7;
sbit SM1   = SCON0^6;
sbit SM2   = SCON0^5;
sbit REN   = SCON0^4;
sbit TB8   = SCON0^3;
sbit RB8   = SCON0^2;
sbit TI    = SCON0^1;
sbit RI    = SCON0^0;

/*  P1  */
sbit T2EX  = P1^1; // 8052 only
sbit T2_   = P1^0; // 8052 only
             

#endif

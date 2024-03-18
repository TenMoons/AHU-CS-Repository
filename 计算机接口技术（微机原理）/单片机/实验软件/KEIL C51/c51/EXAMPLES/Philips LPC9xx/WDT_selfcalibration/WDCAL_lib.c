// wdcal_lib.c
// Library with functions for the self-calibration

// This file contains asm directives:
// Set the Compiler options (Keil uVision2) for this file to:
// - Generate Assembler SRC File
// - Assemble SRC File

#include <REG932.H>
#include "WDCAL_lib.h"
#include "CSTM_lib.h"

unsigned char WDTcnt=0;

void WDcal()
{
	// state machine
	unsigned char calStat=0;		
	calStat=EEPROMread(ADRSTAT);		// get current state 
	switch(calStat)
	{
		case MESWD:	// this is the very first powerup:
					EEPROMwrite(ADRSTAT, calStat+1);	

					// Set timer0 16bit Mode 1
					TAMOD=0x00;			// set mode 1, 16bit timer
					TMOD=0x01;
					TH0=0x3E;			// setup 13.44ms until overflow @ fosc=7.374MHz (RCosc)
					TL0=0x74;				
					IP0H|=0x02;			// interrupt priority level 2
					IP0&=0xFD;

					// Set watchdog
					WDL=0x00;			// WDT reloadvalue=0 -> OverFlowPeriod=80us@400kHz
					WDCON=0x05;			// Start WDT, use WDTosc
					IP0H&=0xBF;			// interrupt priority level 1
					IP0|=0x40;		

					// Enable both timers
					msec(11);			// wait for WDT update (wait for next underflow)
					ET0=1;				// enable timer0 interrupt
					EC=1;				// enable WDT interrupt
					EA=1;
					TR0=1;				// start TR0
					WDTcnt=0;			// reset overflow counter
					while(EC);			// wait until measurement is done
					setUCFG(WDTOSC);	// select WDTosc and reset
					break;
		case USERC:	break;				// this is a 'following' powerup:
										//  now execute user code
	}
}

void EEPROMwrite(unsigned int adr, unsigned char dat)
{
	EA=0;									// disable interrupts during write
	DEECON=(unsigned char)((adr>>8)&0x01);	// set byte write mode
	DEEDAT=dat;								// write data to buffer
	DEEADR=(unsigned char) adr;				// start write
	EA=1;
	while((DEECON&0x80)==0);				// wait until write complete
}

unsigned char EEPROMread(unsigned int adr)
{
	DEECON=(unsigned char)((adr>>8)&0x01);	 
	DEEADR=(unsigned char) adr;				// start byte read
	while((DEECON&0x80)==0);				// wait until read complete
	return DEEDAT;							// copy data from buffer
}

void WDT_ISR() interrupt 10
{
	WDTcnt++;				// count WDT overflows
	WDCON&=0x0FD;			// reset WDT interrupt flag
}

void T0_ISR() interrupt 1
{
	EC=0;							// Deactivate all timers,
	ET0=0;							
	EEPROMwrite(ADRWDFQ, WDTcnt);	// Save WDTcnt to EEPROM	
}

void setUCFG(unsigned char ucfg)
{
	EA=0;				// disable interrupt during IAP
	ACC=ucfg;			// 0x43: RCosc, 0x44: WDTosc, 0x40: Crystal
	#pragma asm
	MOV R5,A			;IAP parameter
	MOV A,#02h
	MOV R7,#00h
	CALL 0FF00h			;call IAP
	MOV AUXR1, #08h		;software reset
	#pragma endasm
	EA=1;
}

void msec(int x)	 // delays x msec (at fosc=11.0592MHz)
{
	int j=0;
	while(x>=0)
	{
		for (j=0; j<1350; j++);
		x--;
	}
}


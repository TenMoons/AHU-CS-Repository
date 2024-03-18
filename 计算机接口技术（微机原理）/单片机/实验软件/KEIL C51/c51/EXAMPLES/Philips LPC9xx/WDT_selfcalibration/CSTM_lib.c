// cstm_lib.c
// Library with functions related to the application

#include <REG932.H>
#include "CSTM_lib.h"
#include "WDCAL_lib.h"

unsigned char sendRQ=0;				// flag for polling

void UART_ISR(void) interrupt 4
{
	RI = 0;
	if (SBUF=='S')	sendRQ=1;		// set send request flag
}

void sendtoPC(char* dat)
{
	int j=0;
	while(dat[j])					// send data string to UART
	{
		TI=0;				// clear transmit flag
		SBUF=dat[j];		// write byte to UART buffer
		while (!TI);		// wait for transmit flag
		j++;
	}
}

void init(void)
{
	P1M1 = 0x00;     	// initialize ports
	P1M2 = 0xFD;		// all push pull except RX (Input)
	P2M1 = 0x00;
	P2M2 = 0xFF;
	ES = 1;				// enable UART interrupt
	EA = 1; 
}   
 
void UART_init()
{	
	unsigned char presc=0;
	SCON=0x50;						// select BRG as UART Baud Rate Gen
	SSTAT=0x60;						// separate Rx / Tx interrupts
	// Calculate BRGR prescaler
	presc=(EEPROMread(ADRWDFQ)>>2)-16; 	// Read calibration value from EEPROM
	BRGR0=(unsigned char)presc;			// write to both BRGR registers
	BRGR1=(unsigned char)(presc>>8);
	BRGCON = 0x03;     					// enable BRG
}

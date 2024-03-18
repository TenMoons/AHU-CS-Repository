// eeprom.c
// Christian Kulig, 10/29/02

// This sample demonstrates the usage of the data EEPROM.
// It counts the number of powerups of the device and
// saves this value in the EEPROM. From there it is read
// again, incremented and written back on every power up.

#include <Reg932.h> 				//Keil header file name
#include <stdio.h>

#define ADDR 5
 
void msec(int x);
void init(void);
void brkrst_init(void);
void EEPROMwrite(unsigned int adr, unsigned char dat);
unsigned char EEPROMread(unsigned int adr);

unsigned char pus=0;

void main(void)
{
	init();						// configure ports
	brkrst_init();				// enable break-detect 
	pus=EEPROMread(ADDR);		// read last powerup counter value
	pus++;						// increase it
	EEPROMwrite(ADDR, pus);		// write new value back to EEPROM
 
	while(1)
	{	
		P2=pus;					// blink current powerup counter
		msec(200);
		P2=0x00;
		msec(200);
	}		
}

void init(void)
{
	P1M1 = 0x00;				// push pull except RX
	P1M2 = 0x00;
	P2M1 = 0x00;
	P2M2 = 0xFF;

	P0M1 = 0xFF;
	P0M1 = 0x00;

	ES = 1;
	EA = 1;
} 		
 
void brkrst_init(void)			// This function allows ISP entry 
								// through the UART break detect
{
	AUXR1 |= 0x40;				// enable reset on break detect
	SCON = 0x50;				// select the BRG as UART baud rate source
	SSTAT = 0x00;
	BRGR0 = 0x70;				// 9600 BAUD at 11.0592 MHz
	BRGR1 = 0x04;
	BRGCON = 0x03;				// enable BRG
}

void UART(void) interrupt 4
{
	RI = 0;						// clear receive interrupt flag
}

void msec(int x)	//LPC932  11.0592 MHz
{
	int j=0;
	while(x>=0)
	{
		for (j=0; j<1350; j++);
		x--;
	}	
}

void EEPROMwrite(unsigned int adr, unsigned char dat)
{
	EA=0;										// disable Interrupts during write
	DEECON=(unsigned char)((adr>>8)&0x01);		// mode: write byte, set address
	DEEDAT=dat;									// set write data
	DEEADR=(unsigned char) adr;					// start write
	EA=1;					
	while((DEECON&0x80)==0);					// wait until write is complete
}

unsigned char EEPROMread(unsigned int adr)
{
	DEECON=(unsigned char)((adr>>8)&0x01);		// mode: read byte, set adress
	DEEADR=(unsigned char) adr;					// start read
	while((DEECON&0x80)==0);					// wait until read is complete
	return DEEDAT;								// return data
}




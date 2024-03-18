// uart_internal_brg.c
// Christian Kulig, 10/29/02
//
// This sample uses the UART to communicate with a PC. Therefore it sets up the internal
// Baud Rate Generator (BRG). The LPC900 receives a command ('S'), sent by the PC and
// sends out a response, which can be displayed with the program 'Hyperterminal'.
// The parameter settings for Hyperterminal are:
// 9600 baud, 8 data bits, 1 stop bit and no flow control.
// To begin the communication click on 'wait for call'.

#include <REG932.H>

void UART_ISR(void);
void sendtoPC(char* dat);
void UART_init();
void init(void);

unsigned char sendRQ=0;
unsigned char ch=0;
char text[]="response at 9600 baud ";

void main ()
{
	init();
	UART_init();
	P2=0;
	while(1)
	{
		P2=ch;						// display ASCII of received character on P2
		if (sendRQ)					// wait for command 'S'
		{
			sendtoPC(text);		// send data to PC
			sendRQ=0;			// reset send request flag
		}
	}
}

void UART_ISR(void) interrupt 4
{
	RI = 0;							// clear receive interrupt flag
	ch=SBUF;						// copy input bufffer to ch
	if (ch=='S')	sendRQ=1;		// set flag for polling in main loop
}

void sendtoPC(char* dat)
{
	int j=0;
	while(dat[j])					// send string
	{
		TI=0;						// clear transmit interrupt flag
		SBUF=dat[j];				// start sending one byte
		while (!TI);				// wait until sent
		j++;
	}
}

void init(void)
{
	P1M1 = 0x00;     //push pull except RX
	P1M2 = 0xFD;
	P2M1 = 0x00;	// push pull
	P2M2 = 0xFF;
	ES = 1;			// enable UART interrupt
	EA = 1;
}   
 
void UART_init()
{	
	SCON=0x50;				// select BRG as UART Baud Rate Gen
	SSTAT=0x60;				// separate Rx / Tx interrupts
//	BRGR0=0xF0;				// setup BRG for 9600 baud @ 7.373MHz internal RC oscillator
//	BRGR1=0x02;
	BRGR0=0x70;				// setup BRG for 9600 baud @ 12MHz external Crystal
	BRGR1=0x04;
	BRGCON = 0x03;     		// enable BRG
}



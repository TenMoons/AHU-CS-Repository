// wdt_selfcalibration.c
// Software sample: Watchdog Timer Self-Calibration
// Christian Kulig, 10/28/02

// This sample shows how to take advantage of the sophisticated clock tree of the LPC900.
// In order to reduce power consumption and to save the external crystal, it clocks
// the microcontroller with the internal watchdog timer oscillator (WDT).
// The actual application is to communicate with the PC using the serial interface (UART).
// It waits for a command from the PC and sends some data back.
// Since the UART needs a clock with an accuracy better than 2.5% and the watchdog timers
// frequency is stable but unknown in absolute value, it has to be calibrated in advance.
// The very first time the device is powered up, it calibrates the watchdog timer
// and saves the result to EEPROM. After that it selects the WDT as the clock source
// and executes a software reset.
// From then on, on every powerup this calibration is skipped and the actual application 
// is executed. It reads the result of the calibration from the EEPROM and sets up the
// UART according to this value.

// To test this sample, connect the evaluation board to a com port of the PC.
// Start the program 'Hyperterminal', and set it up as follows:
// 9600 baud, 8 data bits, 1 stop bit and no flow control.
// Click on 'Waiting for Call' and power up the LPC900.
// It should start blinking and wait for a command entered.
// After pressing 'S' the LPC900 sends out data, which are displayed in Hyperterminal.

// This sample demonstrates the setup and usage of the following functionalities:
// -Watchdog Timer Oscillator
// -Interrupt system
// -Standard Timer 
// -UART and internal baud rate generator (BRG)
// -In-application programming (IAP)
// -Data EEPROM
// -I/O ports

#include <Reg932.h>
#include "wdt_selfcalibration.h"
 
unsigned char dat[]="ABCDEFGHIJ";	// Data to send
unsigned char calStat=0;			// state of calibration

void main(void)
{
	init();							// initialize the I/O ports
	UART_init();					// read the EEPROM and set up the UART
	WDcal();						// call calibration state machine
	EA=1;
	while(1)				
	{ 
		P2=0x00;					// blink the value of BRGR0 on port P2
		msec(5);
		P2=BRGR0;					
		msec(5);					
		if (sendRQ)					// if 'S' was pressed
		{
			sendtoPC(dat);			// send out data to PC
			sendRQ=0;				// clear send request flag
		}
	}
}



// CAPCOM_PWM.c
// Christian Kulig, 10/29/02
//
// This sample uses the Capture Compare Unit (CCU) to create Pulse Width 
// Modulated (PWM) signals to drive and dimm two LEDs on port P2.1 and P2.6.
// It sets up the compare function of the CCU for asymmetrical (edge aligned) PWM,
// and varies the duty cycle.
//

#include <Reg932.h> 				//Keil header file name
#include <stdio.h>
 
void msec(int x);
void init(void);
void brkrst_init(void);
void CCU_init(void);

void main(void)
{
	unsigned char n=5;
	init();				// sets up the UART
	brkrst_init();		// for break-detect
	CCU_init();			// sets up CCU 
 	while(1)		
	{	
		for (n=5; n <= 250; n+=5)
			{
				OCRAL=n;		// vary both duty cycles	
				OCRDL=n;			
				TCR21|=0x80;	// update duty cycles
				msec(10);
			}
		for (n=250; n >= 5; n-=5)
			{
				OCRAL=n;		// vary both duty cycles
				OCRDL=n;			
				TCR21|=0x80;	// update duty cycles
				msec(10);
			}
	}		
}

void CCU_init(void)
{
	OCA=1;			// enable ports P2.1 and P2.6 as PWM outputs
	OCD=1;
	TPCR2H=0x00;	// set CCU Prescaler:
	TPCR2L=0x63;	// divide by 100 (99+1)
					
	TCR21=0x06;		// Prescaler for Phase Locked Loop:
					// Input frequency must be in range of 0.5-1Mhz
					// InpFrq=PCLK/(PLLDIV+1)=(CCLK/2)/(PLLDIV+1)
					// using the internal RC oscillator: CCLK=7.373MHz 
					// 		PLLDiv=6, 6+1=7      => 0.526 MHz
					// using Crystal 11.0592 MHz => 0.789 MHz

	CCCRA=0x01;		// non-inverted PWM output on channel A
	CCCRD=0x02;		// inverted PWM output on channel D
	
	TCR20=0x80;		// Start PLL, OutputMode: stop
	OCA=1;			// wait a machine cycle
	while(PLEEN==0);// wait until PLL locked

	TOR2H=0x00;		// Reload Value 0x00FF=255
	TOR2L=0xFF;		// -> PWM period
	TCR21|=0x80;	// update reload value

	OCRAH=0x00;		// initialize Duty-Cycle channel A 0x0100 => 25%
	OCRAL=0x0F;			
	TCR21|=0x80;	// update duty cycle

	OCRDH=0x00;		// initialize Duty-Cycle channel D 0x0100 => 25%
	OCRDL=0x0F;			
	TCR21|=0x80;	// update duty cycle

	TCR20=0x82;		// Set output mode: asymmetrical PWM
}

void init(void)
{
	P2M1 = 0x00;				// Push Pull output
	P2M2 = 0xFF;
	P2=0;

	ES = 1;						// Enable UART interrupt
	EA = 1;
} 		
 
void brkrst_init(void)			// This function allows ISP entry through 
								//	the UART break detect
{
	AUXR1 |= 0x40;				// enable reset on break detect
	SCON = 0x50;				// select the BRG as UART baud rate source
	SSTAT = 0x00;
	BRGR0 = 0x70;				// 9600 BAUD at 11.0592 MHz
	BRGR1 = 0x04;				// 11.0592 MHz / (470h+10h) = 9600 baud
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


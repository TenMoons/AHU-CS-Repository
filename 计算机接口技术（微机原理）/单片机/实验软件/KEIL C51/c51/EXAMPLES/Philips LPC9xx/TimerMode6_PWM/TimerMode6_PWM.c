// timermode6_pwm.c
// Christian Kulig, 10/29/02
//
// This sample creates a PWM signal on port P0.7 using a standard timer. 
// It sets up the mode 6 (PWM mode) and varies the duty cycle.
 
#include <Reg932.h> 				//Keil header file name
#include <stdio.h>
 
void msec(int x);
void init(void);
void brkrst_init(void);
void Timer1_init(void);

unsigned char n=0;
 	
void main(void)
{
	init();				// configure ports
	brkrst_init();		// enable UART break-detect 
	Timer1_init();		// set up timer1 mode6 (PWM)

 	while(1)
	{	
		for(n=0; n<255; n++) 	// vary duty cycle
		{
			TH1=n;	
			msec(15);
		}
		msec(100);
	
		for(n=255; n>0; n--) 
		{
			TH1=n;
			msec(15);
		}
		msec(100);
	}		
}

void init(void)
{
	P0M1 = 0x00;				// push pull output
	P0M2 = 0xFF;

	ES = 1;						// enable UART interrupt
	EA = 1;
} 		
 
void brkrst_init(void)			// This function allows ISP entry through the UART break detect
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
	
void msec(int x)				// @ 11.0592 MHz
{
	int j=0;
	while(x>=0)
	{
		for (j=0; j<1350; j++);
		x--;
	}	
}

void Timer1_init(void)
{
	TMOD|=0x20;					// timer1 mode 6, PWM
	TAMOD|=0x10;
	TH1=200;					// duty cycle = 256-TH1
	AUXR1|=0x20;				// enable toggling pin P0.7
	TR1=1;						// start timer 1
}


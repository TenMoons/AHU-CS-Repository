/*
 * MAIN APPLICATION SECTION
 */
#pragma USERCLASS (ECODE=APPL)  // application code will be in ECODE_APPL

#include <reg51m.h>

extern unsigned char stsys;		//system status: 0-boot, 1-application
extern unsigned char t2_ind;	//t2 interrupt ISR indication: 0-none, 1-happened

extern void int_on(void);
extern void int_off(void);

void t2_ini_app(void);

void main_app(void)
{
	int_off();
	t2_ini_app();
	int_on();
	while(1)
		{
		if (t2_ind == 1)
			{
			t2_ind = 0;
			P3 = 0x00;
			P3 = 0xFF;
			P3 = 0x00;
			P3 = 0xFF;
			P3 = 0x00;
			P3 = 0xFF;
			P3 = 0x00;
			P3 = 0xFF;
			P3 = 0x00;
			P3 = 0xFF;
			}
		}
}


void t2_ini_app(void)
{
	ET2 = 0;
	T2MOD = 0x00;			//T2 is in 16 bit autoreload mode
	T2CON = 0x00;
	RCAP2L = 0x98;			//genereating interrupts on 16 ms|22.1184 MHz clock
	RCAP2H = 0x19;
	TL2 = RCAP2L;
	TH2 = RCAP2H;
	ET2 = 1;
	TR2 = 1;				//T2 is on
}

void t2_isr_app(void)
{
	P1 = 0x00;				//signal t2 ISR activity (bootloader)
	P1 = 0xFF;
	t2_ind = 1;
}



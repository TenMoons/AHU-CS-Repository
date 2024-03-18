/*
 * MAIN BOOT SECTION
 */

#include <reg51m.h>

unsigned char stsys  = 0;   // system status: 0-boot, 1-application
unsigned char t2_ind = 0;   // t2 interrupt ISR indication: 0-none, 1-happened

extern void main_app(void);

void int_off(void);
void t2_ini_load(void);
void int_on(void);

main()
{
	int_off();
	t2_ini_load();
	t2_ind = 0;
	int_on();
	P2 = 0xFF;
	while(1)
		{
		if (P2 != 0xFF)
			{
			stsys = 1;
			main_app();
			}
		if (t2_ind == 1)
			{
			t2_ind = 0;
			P3 = 0x00;
			P3 = 0xFF;
			P3 = 0x00;
			P3 = 0xFF;
			P3 = 0x00;
			P3 = 0xFF;
			}
		}
}


void t2_ini_load(void)
{
	ET2 = 0;
	T2MOD = 0x00;			//T2 is in 16 bit autoreload mode
	T2CON = 0x00;
	RCAP2L = 0xFF;			//genereating interrupts on 10 ms|22.1184 MHz clock
	RCAP2H = 0x6f;
	TL2 = RCAP2L;
	TH2 = RCAP2H;
	ET2 = 1;
	TR2 = 1;				//T2 is on
}

void t2_isr_load(void)  {
	P1 = 0x00;				//signal t2 ISR activity (bootloader)
	P1 = 0xFF;
	t2_ind = 1;
}

void int_on(void)  {
	EA = 1;
}

void int_off(void)  {
	EA = 0;
}



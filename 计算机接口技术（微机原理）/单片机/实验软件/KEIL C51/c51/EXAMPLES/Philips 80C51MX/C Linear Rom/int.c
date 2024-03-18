#include <reg51m.h>

extern unsigned char stsys;		//system status: 0-boot, 1-application

extern void t2_isr_load(void);
extern void t2_isr_app(void);

void timer2(void) interrupt 5 using 1 
{
	TF2 = 0;
	if (stsys == 0)
		t2_isr_load();
	else
		t2_isr_app();
}

#include <Reg932.h> 

void keypad_init(void)  {
  // P0.5 must be pulled high
  KBPATN = 0x20;
  // Port 0 must match KBPATN to generate interrupt
  KBCON = 0x02;
  // mask out all pins except P0.5
  KBMASK = 0x20;

  // enable keypad interrupt
  EKBI = 1;
  // enable interrupts
  EA = 1;
}

void keypad_isr(void) interrupt 7 using 1  {
  // turn on peripherals
  PCONA = 0x00;
  // turn on P2 LEDs
  P2 = 0xFF;
  // clear KBIF interrupt flag by writing 0 to it
  KBCON &= 0xFE;
}
 
void main(void)  {
  // set P2 to push-pull outputs
  P2M1 = 0x00;
  P2M2 = 0xFF;

  keypad_init();

  // turn off LEDs
  P2 = 0x00;

  // turn off all peripherals that can be turned off 
  PCONA = 0xEF;

  // switch to idle mode
  PCON |= 0x01;

  while(1);
}

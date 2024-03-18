/* FLASH.C - LED Flasher for the Atmel SND1 Reference Board*/
                  
#include <AT8xC51SND1.H>

sbit LED1 = P1^2;
sbit LED2 = P1^5;
sbit LED3 = P1^7;
sbit LED4 = P1^6;

code char reserve_serint[3] _at_ 0x23;

#define CLR_PATTERN 0xE4;

void set_led(char ledno) {

  switch (ledno) {
    case 1:
      LED1 = 0;
      break;
    case 2:
      LED2 = 0;
      break;
    case 3:
      LED3 = 0;
      break;
    case 4:
      LED4 = 0;
      break;
  }
}

void clr_leds(void) {

  P1 |= CLR_PATTERN;  

}

void wait (void)  {                   /* wait function */
  ;                                   /* only to delay for LED flashes */
}

void main (void)  {
  unsigned int i;                     /* Delay var */
  unsigned char j;                    /* LED var */

  while (1) {                         /* Loop forever */
    for (j = 1; j <= 3; j++)  {         /* Blink LED 1, 2, 3, 4 */
      clr_leds ();                         /* Output to LED Port */
      set_led (j);
      for (i = 0; i < 10000; i++)  {  /* Delay for 10000 Counts */
       wait ();                       /* call wait function */
      }
    }

    for (j = 4; j >= 2; j--)  {         /* Blink LED 4, 3, 2, 1 */
      clr_leds ();                         /* Output to LED Port */
      set_led (j);
      for (i = 0; i < 10000; i++)  {  /* Delay for 10000 Counts */
       wait ();                       /* call wait function */
      }
    }
  }
}

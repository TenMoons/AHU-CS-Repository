/* BLINKY.C - LED Flasher for the Dallas 390 part */
                  

#include <REG390.H>
#include <stdio.h> 

int far init_var = 0x1234;
 
void wait (void)  {                   /* wait function */
  ;                                   /* only to delay for LED flashes */
}

void main (void)  {
  unsigned int i;                     /* Delay var */
  unsigned char j;                    /* LED var */

//  init serial interface 19200 baud @ 40MHz
  PCON  |= 0x80;
  SCON0  = 0x50;		         
  TMOD  |= 0x21;           
  TH1    = 0xF8;   
  CKCON |= 0x10;
  TCON   = 0x50;              
  TI     = 1;   

  while (1) {                         /* Loop forever */
    printf ("Hello World\n");         /* Print "Hello World" */

	for (j=0x01; j< 0x80; j<<=1)  {   /* Blink LED 0, 1, 2, 3, 4, 5, 6 */
      P1 = j;                         /* Output to LED Port */
      for (i = 0; i < 10000; i++)  {  /* Delay for 10000 Counts */
       wait ();                       /* call wait function */
      }
    }

    for (j=0xFF; j> 0x01; j>>=1)  {   /* Blink LED 6, 5, 4, 3, 2, 1 */
      P1 = j;                         /* Output to LED Port */
      for (i = 0; i < 10000; i++)  {  /* Delay for 10000 Counts */
       wait ();                       /* call wait function */
      }
    }
  }
}

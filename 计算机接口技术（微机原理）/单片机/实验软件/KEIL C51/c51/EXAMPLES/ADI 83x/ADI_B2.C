/* ADI_B2.C - Module that shows new features in the ADuC B2 device*/
#include <ADUC834.H>
#include <string.h>
#include <absacc.h>
#include <stdio.h>


#ifdef MONITOR51                         // Debugging with Monitor-51 needs
char code reserve [3] _at_ 0x23;         // space for serial interrupt if
#endif                                   // Stop Exection with Serial Intr.

char code  mytext[] = "This is a text string";
char xdata array[0x100];
int errcnt;

unsigned char far large_array[0xC000];


/* 
 * the following timer interrupt routine uses a variable in xdata space
 */
#define PERIOD     -250                   // 250 usec interrupt period
unsigned char xdata timer_tick;           // xdata variable

void timer0 (void) interrupt 1 using 1 {  // Int Vector at 000BH, Reg Bank 1
  timer_tick++;                           // increment xdata variable
}

/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/

void main (void) {
  unsigned int i;
/*------------------------------------------------
Setup the serial port for 1200 baud at 16MHz.
------------------------------------------------*/
#ifndef MONITOR51
  SCON  = 0x50;               // SCON: mode 1, 8-bit UART, enable rcvr
  TMOD |= 0x20;               // TMOD: timer 1, mode 2, 8-bit reload
  TH1   = 221;                // TH1:  reload value for 1200 baud @ 16MHz
  TR1   = 1;                  // TR1:  timer 1 run
  TI    = 1;                  // TI:   set TI to send first char of UART
#endif

/* setup the timer 0 interrupt */
  TH0 = (unsigned char) PERIOD;          // set timer period
  TL0 = (unsigned char) PERIOD;
  TMOD = TMOD | 0x02;                    // select mode 2
  TR0 = 1;                               // start timer 0
  ET0 = 1;                               // enable timer 0 interrupt
  EA  = 1;                               // global interrupt enable

                                         // fast Dual DPTR routines
  strcpy (array, mytext);             
  memmove (&array[10], &array[0], 90);
  if (memcmp (&array[10], mytext, sizeof (mytext)) != 0)  {
    errcnt++;
  }
  memmove (&array[0], &array[10], 90);
  memcpy (&array[20], mytext, sizeof (mytext));
  if (strcmp (&array[20], mytext) != 0)  {
    errcnt++;
  }
  memset (large_array, 0x55, sizeof (large_array));

  FVAR (char, 0x015678) = 0x5A;          // absolute memory access
  i = FVAR (char, 0x015678);

  for (i = 0; i < sizeof (large_array); i++)  {
    large_array[i] = (unsigned char) i;  // just an example
  }
  for (i = 0; i < sizeof (large_array); i++)  {
    printf ("\nRead large_array[0x%X]=%bX", i, large_array[i]);
  }
  while (1);
}

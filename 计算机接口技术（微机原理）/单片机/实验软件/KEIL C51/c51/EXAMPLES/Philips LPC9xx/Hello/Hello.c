/*------------------------------------------------------------------------------
HELLO.C - adapted for the P89LPC932 and the Keil MCB900 Microcontroller Board

Copyright 1995-2003 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <REG932.H>               /* special function register declarations   */
                                  /* for the Philips P89C932 device           */

#include <stdio.h>                /* prototype declarations for I/O functions */

/* The delay C function is a for loop that
needs about 0.2 seconds execution time */
static void delay (void)  {
  unsigned long i;

  for (i = 0; i < 25000; i++)  {  /* waste timea and */
    ;                             /* do notthing */
  }
}

/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/
void main() {
  P2M1 = 0;
  P1M1 = 0;

  SCON   = 0x52;                 /* initialize UART */
  BRGR0  = 0xF0;                 /* 9600 baud, 8 bit, no parity, 1 stop bit */
  BRGR1  = 0x02;
  BRGCON = 0x03;
  
  P2 = 0x55;

/*------------------------------------------------
Note that an embedded program never exits (because
there is no operating system to return to).  It
must loop and execute forever.
------------------------------------------------*/
  while (1) {
    P2 ^= 0xFF;     		     /* Toggle port 2 pins each time we print */
    printf ("Hello World\n");    /* Print "Hello World"                   */
    delay ();                    /* Delay about 0.2 seconds               */
  }
}

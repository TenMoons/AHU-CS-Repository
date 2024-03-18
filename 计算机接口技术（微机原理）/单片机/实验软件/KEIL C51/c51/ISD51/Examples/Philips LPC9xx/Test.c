/*------------------------------------------------------------------------------
TEST.C:  ISD51 Demo for Philips P89LPC932

Copyright 2002 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <REG932.H>
#include <intrins.h>
#include <stdio.h>
#include "ISD51.h"

unsigned char j;

unsigned char code testarray[] = "Some Text";


#if 0   // uncomment this function to verify serial communication

/*
 * Test Function: verify serial communication with HyperTerminal
 */
void TestSerial (void)  {
  char c = 'A';

  TI = 1;
  while (1)  {
    if (RI)  {
      c = SBUF;
      RI = 0;
    }
    while (!TI);
    TI = 0;
    SBUF = c;
  }
}

#endif

void delay(void) {
  long i;
  
  i = 0x800;
  while(i--);
}



void main (void)  {
  unsigned int i;
  char ch;

  P2M1 = 0;
  P1M1 = 0;

  BRGR0   = 0xF0;      /* 9600 baud, 8 bit, no parity, 1 stop bit */
  BRGR1   = 0x02;
  BRGCON  = 0x03;
  SCON    = 0x52;      /* enable serial uart & receiver      */
  EA = 1;              /* Enable global interrupt flag       */

//TestSerial ();      // uncomment this function to verify serial communication
 
#if 0   // init ISD51 and start user program until the uVision2 Debugger connects
  ISDinit ();        // initialize uVision2 Debugger and continue program run
#endif

#if 0   // init ISD51 and wait until the uVision2 Debugger connects
  ISDwait ();        // wait for connection to uVision2 Debugger
#endif

  for (i = 0; i < sizeof (testarray); i++)  {
   j = testarray[i];
  }

  while (1)  {
#if 1   // init ISD51 only when the uVision2 Debugger tries to connect
    ISDcheck();      // initialize uVision2 Debugger and continue program run
#endif
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    P2 ^= 0x10;
    if (_iskey ()) {   // check if a charcter has been received
      ch = _getkey (); // get the received character
      putchar (ch);    // echo the received character
    }
    _nop_();
    _nop_();
    _nop_();
#if 0   // you may use ISDbreak when ISD51 is started with ISDcheck or ISDwait
    ISDbreak ();  // hard coded stop (breakpoint)
#endif
    delay();
    _nop_();
    _nop_();
    _nop_();
  }
}



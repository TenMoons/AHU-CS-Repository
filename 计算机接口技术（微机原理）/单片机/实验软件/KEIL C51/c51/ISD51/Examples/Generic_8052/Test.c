/*------------------------------------------------------------------------------
TEST.C:  ISD51 Demo for classic 8051 devices like Philips 89C51RD2/89C66x

Copyright 2002 - 2003 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <REG51F.H>
#include <intrins.h>
#include <absacc.h>
#include "ISD51.h"

unsigned char j;

#define Port_D    XBYTE [0xFFA0]   // bit 0:  switch S1
                                   // bit 1:  switch S2
                                   // bit 4:  LED    D1
                                   // bit 5:  LED    D2

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


  T2CON   = 0x34;      /* Use Timer 2 as baudrate generator  */

#if 0
  RCAP2H  = 0xFF;      /*  9615 baud @ 20MHz with X2 Mode off */
  RCAP2L  = 0xBF;      /* 19230 baud @ 20MHz with X2 Mode on  */
#endif

  RCAP2H  = 0xFF;
  RCAP2L  = 0xD9;      /* 19230 baud @ 12MHz                  */
                       /* 38460 baud @ 24MHz                  */

  SCON    = 0x50;      /* enable serial uart & receiver      */
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
    Port_D = (Port_D) ^ 0x30;
    P1 ^= 0x10;
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



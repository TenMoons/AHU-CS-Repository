/*------------------------------------------------------------------------------
TIME.C:  Time Function for DHRYSTONE and WHEATSTONE Benchmarks

Copyright 1995-1996 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <reg51.h>


long timeval;

timerint () interrupt 1 {
  TH0 = -250;             /* 125 Hz at 12 MHz 8051 */
  timeval++;
}

long time (long *t)  {
  long tval;

  t = (long *) 0;
  EA   = 0;
  tval = timeval;
  IE   = 0x82;
  TR0  = 1;
  return (tval);
}


initserial ()  {
  SCON = 0x52;    /* SCON */
  TMOD = 0x20;    /* TMOD */
  TCON = 0x69;    /* TCON */
  TH1 =  0xf3;    /* TH1 */
}


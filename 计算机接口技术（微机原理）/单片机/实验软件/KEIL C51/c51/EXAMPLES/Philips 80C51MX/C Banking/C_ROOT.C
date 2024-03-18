/*------------------------------------------------------------------------------
C_ROOT.C

Copyright 2000 KEIL Software, Inc.
------------------------------------------------------------------------------*/

#include <stdio.h>
#include <reg51m.h>

extern void func0(void);
extern void func1(void);

const char far text[] = "This is a text in the HCONST memory class";
unsigned int far iarray[0x100];  // This array is in HDATA 

void main(void) {
/* INITIALIZE SERIAL INTERFACE TO 2400 BAUD @12MHz */
  SCON = 0x52;    /* SCON */
  TMOD = 0x20;    /* TMOD */
  TCON = 0x69;    /* TCON */
  TH1 =  0xf3;    /* TH1 */

  printf("\n*** %s ***\n", text);  // Print Text
  iarray[0] = 0x1234;
  printf("MAIN PROGRAM CALLS A FUNCTION IN BANK 0 \n");
  func0();
  printf("MAIN PROGRAM CALLS A FUNCTION IN BANK 1 \n");
  func1();

  while(1);
}

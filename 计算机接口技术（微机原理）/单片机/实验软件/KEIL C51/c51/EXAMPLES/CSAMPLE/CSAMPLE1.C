/*------------------------------------------------------------------------------
CSAMPLE1.C

Copyright 1995-1999 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <reg51.h>                             /* define 8051 registers */
#include <stdio.h>                             /* define I/O functions */

extern unsigned int getnumber (void);
extern void output (unsigned int);

void main (void)  {                            /* main program */
  unsigned int number1, number2;               /* define operation registers */
  bit operation;                               /* define operation */

  SCON = 0x52;    /* SCON */                   /* setup serial port control */
  TMOD = 0x20;    /* TMOD */                   /* hardware (2400 BAUD @12MHZ) */
  TCON = 0x69;    /* TCON */
  TH1 =  0xf3;    /* TH1 */

  printf ("\n\nC compiler demonstration program\n\n");

  while (1)  {                                 /* repeat forever */
    number1 = getnumber ();                    /* read number1 */
    number2 = getnumber ();                    /* read number2 */
    printf ("Input operation: '+' (ADD) or '-' (SUB) ? ");
    operation = (getchar () == '+');           /* get operation */
    output (operation ? (number1 + number2)    /* perform operation */
                      : (number1 - number2) );
  }
}

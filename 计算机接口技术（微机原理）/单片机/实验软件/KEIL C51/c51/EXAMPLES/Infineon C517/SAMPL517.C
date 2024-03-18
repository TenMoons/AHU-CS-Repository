/********************************************************************/
/*                                                                  */
/*    SAMPL517.C:  C-COMPILER-51 80C517 Demo                        */
/*                                                                  */
/*    Copyright KEIL ELEKTRONIK GmbH, 1989-2000                     */
/*                                                                  */
/********************************************************************/
	
/* The following program is a simple UPN calculator.                */

#include <80C517.h>
#include <stdio.h>
#include <stdlib.h>
#include <reg517.h>
#include <ctype.h>
#include <string.h>

#ifdef MONITOR51                         /* Debugging with Monitor-51 needs   */
char code reserve1 [3] _at_ 0x23;        /* space for serial 0 interrupt      */
char code reserve2 [3] _at_ 0x83;        /* and for serial 1 interrupt if     */
#endif                                   /* Stop Exection with Serial Intr.   */

union {
  unsigned char c [4];
  unsigned long l;
} time = {0, 0, 0, 0};

code char menu[] =
"\n"
"+***************** C-51 COMPILER UPN DEMO *********************+\n"
"! usage (is like any HP calculator): a number goes to TOS      !\n"
"! a operation or function forces the calculation               !\n"
"+- operations --------------+- functions ----------------------+\n"
"! add:      +   subtract: - ! SIN   COS    TAN    SQRT   LOG   !\n"
"! multiply: *   divide:   / ! ASIN  ACOS   ATAN   EXP    LOG10 !\n"
"+---------------------------+----------------------------------+\n";

/**************************************/
/* Timer 0 interrupt service function */
/**************************************/

/* executes once timer 0 overflow */
/* maintains high part of usec counter */

#pragma NOMOD517                /* Interrupt Routine without 80C517 support */
void timer0(void) interrupt 1 { /* no Register Bank using on simple routines */

  time.c[1]++;                  /* increment on timer overflow */
}

#pragma MOD517            /* All 80C517 instructions */

float val [4] = {0.0, 0.0, 0.0, 0.0};
code char fchar [] = {'X', 'Y', 'Z', 'T'};
code char error [] = "\nERROR *** Illegal Command";


dispvals ()  {
  unsigned char i;

  printf517 ("Stack:\n");
  for (i = 0; i != 4; i++)  {
    printf517 ("%c: %G\n", fchar[i], val[i]);
  }
}

pushval (float f)  {
  unsigned char i;

  for (i = 3; i > 0; i--) val [i] = val [i-1];
  val[0] = f;
}

float popval ()  {
  unsigned char i;
  float f;

  f = val[0];
  for (i = 0; i < 3; i++) val [i] = val [i+1];
  return(f);
}

code struct  { 
  unsigned char len;
  char         *cmd;
}  fcttab []  =  {
  { 1, "+" },
  { 1, "-" },
  { 1, "*" },
  { 1, "/" },
  { 3, "SIN" },
  { 3, "COS" },
  { 3, "TAN" },
  { 4, "ASIN" },
  { 4, "ACOS" },
  { 4, "ATAN" },
  { 3, "EXP" },
  { 5, "LOG10" },
  { 3, "LOG" },
  { 4, "SQRT" },
  { 0, "" } };

#define ADD   0
#define SUB   1
#define MUL   2
#define DIV   3
#define SIN   4
#define COS   5
#define TAN   6
#define ASIN  7
#define ACOS  8
#define ATAN  9
#define EXP   10
#define LOG10 11
#define LOG   12
#define SQRT  13


unsigned char findfct (char *p)  {
  unsigned char i = 0;

  while (fcttab[i].len != 0)  {
    if (memcmp (fcttab[i].cmd, p, fcttab[i].len) == 0) return (i);
    i++;
  }
  return (0xFF);
}


/****************/
/* main program */
/****************/

void main (void)  {
  char cmdbuf [15];
  unsigned char i;

  /* initialize serial interface */
#if 0
// Initialization of serial interface 0
  BD = 1;         /* internal Baudrate Generator */
  PCON |= 0x80;   /* 9600 Baud @ 12 MHz */
  S0CON = 0x5A;   /* S0CON */
#endif
#ifndef MONITOR51
// Serial interface should not be initialized when it is used for debugging.
// Initialization of serial interface 1
  S1REL = 0xD9;	  /* Reload Value for 9600 Baud @ 12 MHz */
  S1CON = 0xB2;   /* Init Serial Interface */
#endif

  /* setup timer 0 interrupt */
  TMOD = TMOD | 0x01;      /* select mode 1 */
  TR0 = 1;                 /* start timer 0 */
  ET0 = 1;                 /* enable timer 0 interrupt */

  EAL = 1;                 /* global interrupt enable */

  printf517 (menu);
  while (1)  {
    dispvals ();
    printf517 ("\nCommand: ");
    gets (cmdbuf, sizeof (cmdbuf));

    for (i = 0; i < sizeof (cmdbuf); i++)  {   /* Upper Chars */
      cmdbuf[i] = toupper(cmdbuf[i]);
    }

    for (i = 0; cmdbuf[i] == ' '; i++);        /* Skip Blanks */

    if (isdigit (cmdbuf[i]) ||
       (cmdbuf[i] == '-' && isdigit (cmdbuf[i+1])) )  {
      pushval (atof517 (&cmdbuf[i]));
    }

    else  {
      i = findfct (&cmdbuf[i]);                /* Find Command */
 
      EAL = 0;                                 /* Disable Int and timer */
      TR0 = 0;                                 /* to avoid error        */
      time.c[1] = 0;                           /* Set Time to Zero      */
      TH0 = 0;
      TL0 = 0;
      EAL = 1;
      TR0 = 1;

      switch (i)  {
        case ADD:
          pushval (popval () + popval ());
          break;

        case SUB:
          pushval (popval () - popval ());
          break;

        case MUL:
          pushval (popval () * popval ());
          break;

        case DIV:
          pushval (popval () / popval ());
          break;

        case SIN:
          pushval (sin517 (popval ()));
          break;

        case COS:
          pushval (cos517 (popval ()));
          break;

        case TAN:
          pushval (tan517 (popval ()));
          break;

        case ASIN:
          pushval (asin517 (popval ()));
          break;

        case ACOS:
          pushval (acos517 (popval ()));
          break;

        case ATAN:
          pushval (atan517 (popval ()));
          break;
            
        case EXP:
          pushval (exp517 (popval ()));
          break;

        case LOG:
          pushval (log517 (popval ()));
          break;

        case LOG10:
          pushval (log10517 (popval ()));
          break;

        case SQRT:
          pushval (sqrt517 (popval ()));
          break;

        default:
          printf517 (error);
          printf517 (menu);
          break;
 
      }

                                               /* Display execution time */
      EAL = 0;                                 /* Disable Int and timer  */
      TR0 = 0;                                 /* to avoid error         */
      time.c[2] = TH0;                         /* Set Time to Zero       */
      time.c[3] = TL0;

      printf517 ("Execution Time: %lu usec.\n", time.l);  

      EAL = 1;
      TR0 = 1;
    }
  }
}


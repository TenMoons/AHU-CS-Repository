/******************************************************************************/
/*                                                                            */
/*     BLINKY.C:  Test Program for Dallas 390 in Contiguous Mode              */
/*                                                                            */
/******************************************************************************/

#include <REG390.H>                      /* special function register         */

char code reserve [5] _at_ 0x23;

struct time  {                           /* structure for time record         */
  unsigned char    hour;                 /* hour                              */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned int     msec;                 /* milli second                      */
} time;

                                            /* external functions: input line */
unsigned char intcycle = 0;                 /* Interrupt cycle counter        */

#define PERIOD     -250                     /* 250 usec interrupt period      */
#define WRONGINDEX 0xffff                   /* error signal for wrong index   */


/* 
 * The following function is called from the interrupt service routine.  This
 * means that the code must be generated in the same Register Bank as the
 * interrupt service function.
 */
#pragma REGISTERBANK (1)                    /* use Register Bank 1 for coding */

/******************************************************************************/
/*                Timer 0 interrupt service function                          */
/*                executes each 250us @ 12 MHz Crystal Clock                  */
/******************************************************************************/
void timer0(void) interrupt 1 using 1 {        /* Int Vector at 000BH, Reg Bank 1  */
  if (++intcycle == 4)  {                      /* 1 msec = 4 * 250 usec cycle */
    intcycle = 0;
                                               /* check if interval is over   */
    if (++time.msec == 1000)  {                /* update millisecond cnt      */
      time.msec = 0;

      if (++time.sec == 60)  {                 /* update second counter       */
        time.sec = 0;

        if (++time.min == 60)  {               /* update minute counter       */
          time.min = 0;

          if (++time.hour == 24)  {            /* update hour counter         */
            time.hour = 0;
          }
        }
      }
    }	/* end of if( ++time.msec... */
  }
}


/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
long long_cnt = 0;

void main ( void )  {                          /* main entry for program      */
  /* setup the timer 0 interrupt */
  TH0 = PERIOD;                                /* set timer period            */
  TL0 = PERIOD;
  TMOD = TMOD | 0x02;                          /* select mode 2               */
  TR0 = 1;                                     /* start timer 0               */
  ET0 = 1;                                     /* enable timer 0 interrupt    */
  EA  = 1;                                     /* global interrupt enable     */

  while (1)  {                                 /* loop forever                */
    P1 &= 0x80;
    P1 |= (time.sec * 10) + (time.msec / 100); /* toggle LED's                */
    long_cnt++;
  }
}

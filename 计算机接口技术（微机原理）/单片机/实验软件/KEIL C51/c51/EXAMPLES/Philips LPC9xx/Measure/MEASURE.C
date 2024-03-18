/*------------------------------------------------------------------------------
MEASURE.C:  Remote Measurement Recorder using the C51 COMPILER

Copyright 1990-2003 Keil Software, Inc.
------------------------------------------------------------------------------*/

static char code menu[] = 
   "\n"
   "+**************** REMOTE MEASUREMENT RECORDER *****************+\n"
   "| This program is a simple Measurement Recorder. It is based   |\n"
   "| on the LPC CPU and records the state of Port 1 and Port 2    |\n"
   "+ command -+ syntax -----+ function ---------------------------+\n"
   "| Read     | R [n]       | read <n> recorded measurements      |\n"
   "| Display  | D           | display current measurement values  |\n"
   "| Time     | T hh:mm:ss  | set time                            |\n"
   "| Interval | I mm:ss.ttt | set interval time                   |\n"
   "| Clear    | C           | clear measurement records           |\n"
   "| Quit     | Q           | quit measurement recording          |\n"
   "| Start    | S           | start measurement recording         |\n"
   "+----------+-------------+-------------------------------------+\n";

#include <REG932.H>               /* special function register declarations   */
                                  /* for the Philips P89C932 device           */
#include <stdio.h>                       /* standard I/O .h-file              */
#include <stdlib.h>                      /* standard library .h-file          */
#include <ctype.h>                       /* character functions               */

#include "measure.h"                     /* global project definition file    */

struct interval setinterval;                /* interval setting values        */
struct interval interval;                   /* interval counter               */

static unsigned char intcycle = 0;          /* Interrupt cycle counter        */

static bit measurement_interval = 0;        /* measurement interval over      */
static bit mdisplay = 0;                    /* measurement display requested  */
static bit startflag = 0;                   /* start measurement recording    */

struct mrec current;                        /* current measurements           */

#define XRAM    512                         /* size of XDATA RAM is 512 Bytes */
#define SCNT  (XRAM / sizeof (current))     /* number of records in XDATA RAM */

struct mrec xdata save_record[SCNT];        /* buffer for measurements        */
unsigned int sindex;                        /* save index                     */
unsigned int savefirst;                     /* save first index               */

char code ERROR [] = "\n*** ERROR: %s\n";   /* ERROR message string in code   */

#define PERIOD     -250                     /* 250 usec interrupt period      */
#define WRONGINDEX 0xffff                   /* error signal for wrong index   */


/* 
 * The following function is called from the interrupt service routine.  This
 * means that the code must be generated in the same Register Bank as the
 * interrupt service function.
 */
#pragma REGISTERBANK (1)                    /* use Register Bank 1 for coding */

/******************************************************************************/
/*               Save current measurements in save_record                     */
/******************************************************************************/
static void save_current_measurements (void) {
  save_record[sindex++] = current;             /* copy current measurements   */
  if (sindex == SCNT) sindex = 0;              /* check bounds of sindex      */
  if (sindex == savefirst)  {                  /* check circular buffer limits*/
    if (++savefirst == SCNT)  savefirst = 0;   /* check bounds of savefirst   */
  }
}


/******************************************************************************/
/*                Timer 0 interrupt service function                          */
/*                executes each 250us @ 12 MHz Crystal Clock                  */
/******************************************************************************/
void timer0 (void) interrupt 1 using 1 {   /* Int Vector at 000BH, Reg Bank 1 */

  if (measurement_interval)  {                 /* measurement done ?          */
    save_current_measurements ();              /* yes -> save measurements    */
    measurement_interval = 0;                  /* Save measurements done      */
  }

  if (++intcycle == 4)  {                      /* 1 msec = 4 * 250 usec cycle */
    intcycle = 0;
                                               /* check if interval is over   */
    if (interval.min  == 0 && 
        interval.sec  == 0 && 
        interval.msec == 0     )  {
      interval = setinterval;                  /* set interval time again     */
      measurement_interval = startflag;        /* determine measurement flag  */
    }
    else  {                                    /* update interval time        */
      if (interval.msec-- == 0)  {             /* calculate millisecond       */
        interval.msec = 999;
        if (interval.sec-- == 0)  {            /* calculate second            */
          interval.sec = 59;
          interval.min--;                      /* calculate minute            */
        }
      }
    }
                                               /* update current time         */
    if (++current.time.msec == 1000)  {        /* update millisecond cnt      */
      current.time.msec = 0;

      if (++current.time.sec == 60)  {         /* update second counter       */
        current.time.sec = 0;

        if (++current.time.min == 60)  {       /* update minute counter       */
          current.time.min = 0;

          if (++current.time.hour == 24)  {    /* update hour counter         */
            current.time.hour = 0;
          }
        }
      }
    }	/* end of if( ++current.time.msec... */

    if (measurement_interval || mdisplay)  {   /* process measurement         */
      current.port1 = P1;                      /* read port 4                 */
      current.port2 = P2;                      /* read port 5                 */
      mdisplay = 0;                            /* mdisplay = 0 for ready sig. */
    }
  }
}


/* 
 * The following functions are called from the main routine.  Therefore
 * Register Bank 0 must be used when coding these functions.
 */

#pragma REGISTERBANK (0)                    /* use Register Bank 0 for coding */
/******************************************************************************/
/*                       Calculate first Read Index                           */
/******************************************************************************/
static unsigned int read_index (unsigned char *buffer) {
  int index = 0;
  unsigned char args;

  if (setinterval.min == 0     &&              /* check if setinterval is     */
      setinterval.sec == 0     &&              /* below 1 second and          */
      setinterval.msec < 999   &&              /* measurements are collected  */
      startflag                   )  {         
    printf (ERROR, "QUIT MEASUREMENTS BEFORE READ");
    return (WRONGINDEX);                       /* no display on the fly if    */
  }                                            /* interval time < 1 second    */
  args = sscanf (buffer, "%d", &index);        /* scan input for read count   */
  if (args == 0  ||  index == 0  || args == EOF)  index = SCNT-1;
  index = ((int) sindex) - index;              /* calculate first read index  */
  if (index < 0) index += ((int) SCNT);        /* from read count             */
  return ((unsigned int) index);
}
  

/******************************************************************************/
/*                         Clear Measurement Records                          */
/******************************************************************************/
static void clear_records (void) {
  unsigned int idx;                            /* index for loop              */

  startflag = 0;                               /* stop measurement collecting */
  sindex = savefirst = 0;                      /* reset circular buffer index */
  for (idx = 0; idx != SCNT; idx++)  {         /* mark all records unused     */
    save_record[idx].time.hour = 0xff;         /* unused flag: hour = 0xff    */
  }     
}


/******************************************************************************/
/***************************      MAIN PROGRAM      ***************************/
/******************************************************************************/
void main ( void )  {                          /* main entry for program      */
  unsigned char idata cmdbuf [15];             /* command input buffer        */
  unsigned char i;                             /* index for command buffer    */
  unsigned int idx;                            /* index for circular buffer   */

  P1M1 = 0xFE;                   // Configure P1.0 (TxD) as Output

  SCON   = 0x52;                               /* initialize UART */
  BRGR0  = 0xF0;                               /* 9600 baud, 8 bit, no parity, 1 stop bit */
  BRGR1  = 0x02;
  BRGCON = 0x03;

  /* setup the timer 0 interrupt */
  TH0 = (unsigned char) PERIOD;                /* set timer period            */
  TL0 = (unsigned char) PERIOD;
  TMOD = TMOD | 0x02;                          /* select mode 2               */
  TR0 = 1;                                     /* start timer 0               */
  ET0 = 1;                                     /* enable timer 0 interrupt    */
  EA = 1;                                      /* global interrupt enable     */

  clear_records ();                            /* initialize circular buffer  */
  printf ( menu );                             /* display command menu        */
  while (1)  {                                 /* loop forever                */
    printf ("\nCommand: ");                    
    getline (&cmdbuf[0], sizeof (cmdbuf));     /* input command line          */

    for (i = 0; cmdbuf[i] != 0; i++)  {        /* convert to upper characters */
      cmdbuf[i] = toupper(cmdbuf[i]);
    }

    for (i = 0; cmdbuf[i] == ' '; i++);        /* skip blanks                 */

    switch (cmdbuf[i])  {                      /* proceed to command function */

      case 'R':                                /* Read circular Buffer        */
        if ((idx = read_index (&cmdbuf[i+1])) == WRONGINDEX)  break;
        while (idx != sindex)  {               /* check end of table          */
          if (RI)  {                           /* check serial interface      */
            if (_getkey() == 0x1B) break;      /* for escape character        */
          }
          if (save_record[idx].time.hour != 0xff)  {
            measure_display (save_record[idx]);      /* display record        */
            printf ("\n");
          }
          if (++idx == SCNT) idx = 0;          /* next circular buffer entry  */
        }
        break;

      case 'T':                                /* Enter Current Time          */
        set_time (&cmdbuf[i+1]);
        break;

      case 'I':                                /* Enter Interval Time         */
        set_interval (&cmdbuf[i+1]);
        break;

      case 'D':                                /* Display Command             */
        printf ("\nDisplay current Measurements: (ESC to abort)\n");
        do  {                                  
          while (! RI)  {                      /* check serial interface      */
            mdisplay = 1;                      /* request measurement         */
            while (mdisplay);                  /* wait for measurement        */
            measure_display (current);         /* display values              */
          }
        } while (_getkey () != 0x1b);          /* escape terminates command   */
        printf ("\n\n");
        break;

      case 'S':                                /* Start Command               */
        printf ("\nStart Measurement Recording\n");
        startflag = 1;
        break;

      case 'Q':                                /* Quit Command                */
        printf ("\nQuit Measurement Recording\n");
        startflag = 0;
        break;

      case 'C':                                /* Clear Command               */
        printf ("\nClear Measurement Records\n");
        clear_records ();
        break;

      default:                                 /* Error Handling              */
        printf (ERROR, "UNKNOWN COMMAND");
        printf (menu);                         /* display command menu        */
        break;
    }
  }
}


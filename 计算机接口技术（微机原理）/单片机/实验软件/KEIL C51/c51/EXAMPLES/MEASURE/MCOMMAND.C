/*------------------------------------------------------------------------------
MCOMMAND.C:  Time Set Commands for the Remote Measurement Recorder

Copyright 1995-1996 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <stdio.h>                       /* standard ANSI I/O .h-file         */
#include <reg515.h>                      /* special function register 80515   */
#include "measure.h"                     /* global project definition file    */


/******************************************************************************/
/*                           Display measurements                             */
/******************************************************************************/
void measure_display (struct mrec display)  {    
  unsigned char i;                       /* index count for AN0 - AN3         */

  printf ("\rTime: %2bd:%02bd:%02bd.%03d  P4:%b02X P5:%b02X ",
           display.time.hour,            /* display hour                      */
           display.time.min,             /* display minute                    */
           display.time.sec,             /* display second                    */
           display.time.msec,            /* display millisecond               */
           display.port4,                /* display port 4 value              */
           display.port5);               /* display port 5 value              */

  for (i = 0; i != 4; i++)  {            /* display AN0 through AN3           */
    printf (" AN%bd:%4.2fV", i, (float) display.analog[i] * 5.0 / 256);
  }
}


/******************************************************************************/
/*                           Set Current Time                                 */
/******************************************************************************/
void set_time (unsigned char * buffer)  {
  struct clock time;                     /* temporary time values             */
  unsigned char args;                    /* number of arguments               */

  time.sec = 0;                          /* preset seconds...                 */
  time.msec = 0;                         /* ...and milliseconds               */
  args = sscanf (buffer, "%bd:%bd:%bd",  /* scan input line for               */
                 &time.hour,             /* hour, minute and second           */
                 &time.min,
                 &time.sec);
  if (time.hour > 23  ||  time.min > 59  ||    /* check for valid inputs      */
      time.sec > 59   ||  args < 2       ||  args == EOF)  {
    printf (ERROR, "INVALID TIME FORMAT");
  } 
  else  {                                /* if inputs valid then              */
    EAL = 0;                             /* disable interrupts while          */
    current.time = time;                 /* setting the new time              */
    interval.min = 0;                    /* force new interval                */
    interval.sec = 0;
    interval.msec = 0;
    EAL = 1;                             /* enable interrupts again           */
  }
}
  

/******************************************************************************/
/*                            Set Interval Time                               */
/******************************************************************************/
void set_interval (unsigned char * buffer) {
  struct interval itime;                 /* temporary interval record         */
  unsigned char args;                    /* number of arguments               */
  float second;                          /* float sec for ss.mmm format       */

  args = sscanf (buffer, "%bd:%f",       /* scan input line for               */
                 &itime.min,             /* minute, second and                */
                 &second);               /* milliseconds                      */
                                         /* check valid inputs                */
  if (second >= 60.0  ||  args < 2  || args == EOF)  {
    printf (ERROR, "INVALID INTERVAL FORMAT");
  }
  else  {                                /* if inputs are valid then          */
    itime.sec = (unsigned char) second;  /* calculate second and millisecond..*/
    itime.msec = (second - itime.sec) * 1000;  /* ..from float values         */
    if (itime.min != 0 || itime.sec != 0 || itime.msec != 0)  {
      if (itime.msec-- == 0)  {          /* correct interval time for         */
        itime.msec = 999;                /* interrupt routine                 */
        if (itime.sec-- == 0)  {
          itime.sec = 59;
          itime.min--;
        }
      }
    }
    EAL = 0;                             /* disable interrupts for copy       */
    setinterval = itime;                 /* of the new setinterval time       */
    interval.min = 0;                    /* force new interval                */
    interval.sec = 0;
    interval.msec = 0;
    EAL = 1;                             /* enable interrupts again           */
  }
}

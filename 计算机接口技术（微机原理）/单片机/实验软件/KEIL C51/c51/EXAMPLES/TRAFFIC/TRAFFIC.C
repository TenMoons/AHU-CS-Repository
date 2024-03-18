/******************************************************************************/
/*                                                                            */
/*   TRAFFIC.C:  Traffic Light Controller using the C-51 COMPILER             */
/*                                                                            */
/******************************************************************************/

char code menu[] = 
   "\n"
   "+***** TRAFFIC LIGHT CONTROLLER using C51 and RTX-51 tiny *****+\n"
   "| This program is a simple Traffic Light Controller.  Between  |\n"
   "| start time and end time the system controls a traffic light  |\n"
   "| with pedestrian self-service.  Outside of this time range    |\n"
   "| the yellow caution lamp is blinking.                         |\n"
   "+ command -+ syntax -----+ function ---------------------------+\n"
   "| Display  | D           | display times                       |\n"
   "| Time     | T hh:mm:ss  | set clock time                      |\n"
   "| Start    | S hh:mm:ss  | set start time                      |\n"
   "| End      | E hh:mm:ss  | set end time                        |\n"
   "+----------+-------------+-------------------------------------+\n";


#include <reg52.h>                    /* special function registers 8052      */
#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */
#include <stdio.h>                    /* standard I/O .h-file                 */
#include <ctype.h>                    /* character functions                  */
#include <string.h>                   /* string and memory functions          */


extern void getline (char idata *, unsigned char);  /* ext. func: input line  */
extern void serial_init (void);       /* external function:  init serial UART */

#define INIT      0                   /* task number of task:  init           */
#define COMMAND   1                   /* task number of task:  command        */
#define CLOCK     2                   /* task number of task:  clock          */
#define BLINKING  3                   /* task number of task:  blinking       */
#define LIGHTS    4                   /* task number of task:  signal         */
#define KEYREAD   5                   /* task number of task:  keyread        */
#define GET_ESC   6                   /* task number of task:  get_escape     */

struct time  {                        /* structure of the time record         */
  unsigned char hour;                 /* hour                                 */
  unsigned char min;                  /* minute                               */
  unsigned char sec;                  /* second                               */
};

struct time ctime = { 12,  0,  0 };   /* storage for clock time values        */
struct time start = {  7, 30,  0 };   /* storage for start time values        */
struct time end   = { 18, 30,  0 };   /* storage for end   time values        */

sbit  red    = P1^2;                  /* I/O Pin:  red    lamp output         */
sbit  yellow = P1^1;                  /* I/O Pin:  yellow lamp output         */
sbit  green  = P1^0;                  /* I/O Pin:  green  lamp output         */
sbit  stop   = P1^3;                  /* I/O Pin:  stop   lamp output         */
sbit  walk   = P1^4;                  /* I/O Pin:  walk   lamp output         */
sbit  key    = P1^5;                  /* I/O Pin:  self-service key input     */

char idata inline[16];                /* storage for command input line       */


/******************************************************************************/
/*        Task 0 'init': Initialize                                           */
/******************************************************************************/
void init (void) _task_ INIT  {       /* program execution starts here        */
  serial_init ();                     /* initialize the serial interface      */
  os_create_task (CLOCK);             /* start clock task                     */
  os_create_task (COMMAND);           /* start command task                   */
  os_create_task (LIGHTS);            /* start lights task                    */
  os_create_task (KEYREAD);           /* start keyread task                   */
  os_delete_task (INIT);              /* stop init task (no longer needed)    */
}


bit display_time = 0;                 /* flag:  signal cmd state display_time */

/******************************************************************************/
/*        Task 2 'clock'                                                      */
/******************************************************************************/
void clock (void)  _task_ CLOCK  {
  while (1)  {                        /* clock is an endless loop             */
    if (++ctime.sec == 60)  {         /* calculate the second                 */
      ctime.sec = 0;
      if (++ctime.min == 60)  {       /* calculate the minute                 */
        ctime.min = 0;
        if (++ctime.hour == 24)  {    /* calculate the hour                   */
          ctime.hour = 0;
        }
      }
    }
    if (display_time)  {              /* if command_status == display_time    */
      os_send_signal (COMMAND);       /* signal to task command: time changed */
    }
    os_wait (K_IVL, 100, 0);          /* wait interval:  1 second             */
  }
}


struct time rtime;                    /* temporary storage for entry time     */

/******************************************************************************/
/*        readtime: convert line input to time values & store in rtime        */
/******************************************************************************/
bit readtime (char idata *buffer)  {
  unsigned char args;                          /* number of arguments         */

  rtime.sec = 0;                               /* preset second               */
  args = sscanf (buffer, "%bd:%bd:%bd",        /* scan input line for         */
                 &rtime.hour,                  /* hour, minute and second     */
                 &rtime.min,
                 &rtime.sec);
  
  if (rtime.hour > 23  ||  rtime.min > 59  ||  /* check for valid inputs      */
      rtime.sec > 59   ||  args < 2        ||  args == EOF)  {
    printf ("\n*** ERROR: INVALID TIME FORMAT\n");
    return (0);
  }
  return (1);
}



#define ESC  0x1B                     /* ESCAPE character code                */

bit   escape;                         /* flag: mark ESCAPE character entered  */

/******************************************************************************/
/*        Task 6 'get_escape': check if ESC (escape character) was entered    */
/******************************************************************************/
void get_escape (void) _task_ GET_ESC  {
  while (1)  {                                 /* endless loop                */
    if (_getkey () == ESC)  escape = 1;        /* set flag if ESC entered     */
    if (escape)  {                             /* if escape flag send signal  */
      os_send_signal (COMMAND);                /* to task 'command'           */
    }
  }
}


/******************************************************************************/
/*        Task 1 'command': command processor */
/******************************************************************************/
void command (void) _task_ COMMAND  {
  unsigned char i;

  printf (menu);                               /* display command menu        */
  while (1)  {                                 /* endless loop                */
    printf ("\nCommand: ");                    /* display prompt              */
    getline (&inline, sizeof (inline));        /* get command line input      */

    for (i = 0; inline[i] != 0; i++)  {        /* convert to uppercase        */
      inline[i] = toupper(inline[i]);
    }

    for (i = 0; inline[i] == ' '; i++);        /* skip blanks                 */

    switch (inline[i])  {                      /* proceed to command function */
      case 'D':                                /* Display Time Command        */
        printf ("Start Time: %02bd:%02bd:%02bd    "
                "End Time: %02bd:%02bd:%02bd\n",
                 start.hour, start.min, start.sec,
                 end.hour,   end.min,   end.sec);
        printf ("                        type ESC to abort\r");

        os_create_task (GET_ESC);              /* ESC check in display loop   */
        escape = 0;                            /* clear escape flag           */
        display_time = 1;                      /* set display time flag       */
        os_clear_signal (COMMAND);             /* clear pending signals       */

        while (!escape)  {                     /* while no ESC entered        */
          printf ("Clock Time: %02bd:%02bd:%02bd\r",      /* display time     */
                   ctime.hour, ctime.min, ctime.sec);
          os_wait (K_SIG, 0, 0);               /* wait for time change or ESC */
        }

        os_delete_task (GET_ESC);              /* ESC check not longer needed */
        display_time = 0;                      /* clear display time flag     */
        printf ("\n\n");
        break;

      case 'T':                                /* Set Time Command            */
        if (readtime (&inline[i+1]))  {        /* read time input and         */
          ctime.hour = rtime.hour;             /* store in 'ctime'            */
          ctime.min  = rtime.min;
          ctime.sec  = rtime.sec;
        }
        break;

      case 'E':                                /* Set End Time Command        */
        if (readtime (&inline[i+1]))  {        /* read time input and         */
          end.hour = rtime.hour;               /* store in 'end'              */
          end.min  = rtime.min;
          end.sec  = rtime.sec;
        }
        break;

      case 'S':                                /* Set Start Time Command */
        if (readtime (&inline[i+1]))  {        /* read time input and         */
          start.hour = rtime.hour;             /* store in 'start'            */
          start.min  = rtime.min;
          start.sec  = rtime.sec;
        }
        break;

      default:                                 /* Error Handling              */
        printf (menu);                         /* display command menu        */
        break;
    }   
  }
}


/******************************************************************************/
/*        signalon: check if clock time is between start and end              */
/******************************************************************************/
bit signalon (void)   {
  if (memcmp (&start, &end, sizeof (struct time)) < 0)  {
    if (memcmp (&start, &ctime, sizeof (struct time)) < 0  &&
        memcmp (&ctime, &end,   sizeof (struct time)) < 0)  return (1);
  }
                                                
  else  { 
    if (memcmp (&end,   &ctime, sizeof (start)) > 0  &&
        memcmp (&ctime, &start, sizeof (start)) > 0)  return (1);
  }
  return (0);                                  /* signal off, blinking on     */
}


/******************************************************************************/
/*        Task 3 'blinking': runs if current time is outside start & end time */
/******************************************************************************/
void blinking (void) _task_ BLINKING  {        /* blink yellow light          */
  red    = 0;                                  /* all lights off              */
  yellow = 0;
  green  = 0;
  stop   = 0;
  walk   = 0;

  while (1)  {                                 /* endless loop                */
    yellow = 1;                                /* yellow light on             */
    os_wait (K_TMO, 80, 0);                    /* wait for timeout: 80 ticks  */
    yellow = 0;                                /* yellow light off            */
    os_wait (K_TMO, 80, 0);                    /* wait for timeout: 80 ticks  */
    if (signalon ())  {                        /* if blinking time over       */
      os_create_task (LIGHTS);                 /* start lights                */
      os_delete_task (BLINKING);               /* and stop blinking           */
    }
  }
}


/******************************************************************************/
/*      Task 4 'lights': executes if current time is between start & end time */
/******************************************************************************/
void lights (void) _task_ LIGHTS  {            /* traffic light operation     */
  red    = 1;                                  /* red & stop lights on        */
  yellow = 0;
  green  = 0;
  stop   = 1;
  walk   = 0;
  while (1)  {                                 /* endless loop                */
    os_wait (K_TMO, 80, 0);                    /* wait for timeout: 80 ticks  */
    if (!signalon ())  {                       /* if traffic signal time over */
      os_create_task (BLINKING);               /* start blinking              */
      os_delete_task (LIGHTS);                 /* stop lights                 */
    }
    yellow = 1;
    os_wait (K_TMO, 80, 0);                    /* wait for timeout: 80 ticks  */
    red    = 0;                                /* green light for cars        */
    yellow = 0; 
    green  = 1;
    os_clear_signal (LIGHTS);
    os_wait (K_TMO, 100, 0);                   /* wait for timeout: 100 ticks */
    os_wait (K_TMO + K_SIG, 250, 0);           /* wait for timeout & signal   */
    yellow = 1;
    green  = 0;
    os_wait (K_TMO, 80, 0);                    /* wait for timeout: 80 ticks  */
    red    = 1;                                /* red light for cars          */
    yellow = 0;
    os_wait (K_TMO, 80, 0);                    /* wait for timeout: 80 ticks  */
    stop   = 0;                                /* green light for walkers     */    
    walk   = 1;
    os_wait (K_TMO, 250, 0);                   /* wait for timeout: 250 ticks */
    stop   = 1;                                /* red light for walkers       */        
    walk   = 0;
  }
}


/******************************************************************************/
/*        Task 5 'keyread': process key stroke from pedestrian push button    */
/******************************************************************************/
void keyread (void) _task_ KEYREAD  {
  while (1)  {                                 /* endless loop                */
    if (key)  {                                /* if key pressed              */
      os_send_signal (LIGHTS);                 /* send signal to task lights  */
    }
    os_wait (K_TMO, 2, 0);                     /* wait for timeout: 2 ticks   */
  }
}

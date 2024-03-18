/******************************************************************************/
/*                                                                            */
/*     MEASURE.H:  struct type and extern definitions for MEASURE project     */
/*                                                                            */
/******************************************************************************/

struct clock {                           /* structure of the clock record     */
  unsigned char    hour;                 /* hour                              */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned int     msec;                 /* milliseconds                      */
};

struct mrec  {                           /* structure for measurement records */
  struct   clock   time;                 /* time of measurement               */
  unsigned char   port1;                 /* state of port 1                   */
  unsigned char   port2;                 /* state of port 2                   */
};

struct interval  {                       /* structure for interval record     */
  unsigned char     min;                 /* minute                            */
  unsigned char     sec;                 /* second                            */
  unsigned int     msec;                 /* milli second                      */
};

                                                 /* external functions:       */
extern void getline (unsigned char idata *line, unsigned char n); /*input line*/
extern void measure_display (struct mrec disp);          /* display mrec      */
extern void set_time (unsigned char *buffer);            /* set current time  */
extern void set_interval (unsigned char *buffer);        /* set interval time */

extern char code ERROR [];               /* ERROR message string              */
extern struct mrec current;              /* current measurements              */
extern struct interval setinterval;      /* interval setting values           */
extern struct interval interval;         /* interval counter                  */



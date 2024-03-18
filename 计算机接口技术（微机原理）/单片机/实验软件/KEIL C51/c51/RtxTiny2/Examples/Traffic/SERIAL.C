/******************************************************************************/
/*                                                                            */
/*       SERIAL.C:  Interrupt Controlled Serial Interface for RTX-51 tiny     */
/*                                                                            */
/******************************************************************************/


#include <reg52.h>                    /* special function register 8052       */
#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

#define  OLEN  8                      /* size of serial transmission buffer   */
unsigned char  ostart;                /* transmission buffer start index      */
unsigned char  oend;                  /* transmission buffer end index        */
idata    char  outbuf[OLEN];          /* storage for transmission buffer      */
unsigned char  otask = 0xff;          /* task number of output task           */

#define  ILEN  8                      /* size of serial receiving buffer      */
unsigned char  istart;                /* receiving buffer start index         */
unsigned char  iend;                  /* receiving buffer end index           */
idata    char  inbuf[ILEN];           /* storage for receiving buffer         */
unsigned char  itask = 0xff;          /* task number of output task           */

#define   CTRL_Q  0x11                /* Control+Q character code             */
#define   CTRL_S  0x13                /* Control+S character code             */

bit   sendfull;                       /* flag: marks transmit buffer full     */
bit   sendactive;                     /* flag: marks transmitter active       */
bit   sendstop;                       /* flag: marks XOFF character           */

/******************************************************************************/
/*       putbuf:  write a character to SBUF or transmission buffer            */
/******************************************************************************/
void putbuf (char c)  {
  if (!sendfull)  {                   /* transmit only if buffer not full     */
    if (!sendactive && !sendstop)  {  /* if transmitter not active:           */
      sendactive = 1;                 /* transfer the first character direct  */
      SBUF = c;                       /* to SBUF to start transmission        */
    }
    else  {                           /* otherwize:                           */
      outbuf[oend++ & (OLEN-1)] = c;  /* transfer char to transmission buffer */
      if (((oend ^ ostart) & (OLEN-1)) == 0)  sendfull = 1;
    }                                 /* set flag if buffer is full           */
  }
}


/******************************************************************************/
/*       putchar:  interrupt controlled putchar function                      */
/******************************************************************************/
char putchar (char c)  {
  if (c == '\n')  {                   /* expand new line character:           */
    while (sendfull)  {               /* wait for transmission buffer empty   */
      otask = os_running_task_id ();  /* set output task number               */
      os_wait (K_SIG, 0, 0);          /* RTX-51 call: wait for signal         */
      otask = 0xff;                   /* clear output task number             */
    }
    putbuf (0x0D);                    /* send CR before LF for <new line>     */
  }
  while (sendfull)  {                 /* wait for transmission buffer empty   */
    otask = os_running_task_id ();    /* set output task number               */
    os_wait (K_SIG, 0, 0);            /* RTX-51 call: wait for signal         */
    otask = 0xff;                     /* clear output task number             */
  }
  putbuf (c);                         /* send character                       */
  return (c);                         /* return character: ANSI requirement   */
}


/******************************************************************************/
/*       _getkey:  interrupt controlled _getkey                               */
/******************************************************************************/
char _getkey (void)  {
  while  (iend == istart)  {
    itask = os_running_task_id ();    /* set input task number                */
    os_wait (K_SIG, 0, 0);            /* RTX-51 call: wait for signal         */
    itask = 0xff;                     /* clear input task number              */
  }
  return (inbuf[istart++ & (ILEN-1)]);
}


/******************************************************************************/
/*       serial:  serial receiver / transmitter interrupt                     */
/******************************************************************************/
serial () interrupt 4 using 2  {     /* use registerbank 2 for interrupt      */
  unsigned char c;
  bit   start_trans = 0;

  if (RI)  {                         /* if receiver interrupt                 */
    c = SBUF;                        /* read character                        */
    RI = 0;                          /* clear interrupt request flag          */
    switch (c)  {                    /* process character                     */
      case CTRL_S:
        sendstop = 1;                /* if Control+S stop transmission        */
        break;

      case CTRL_Q:
        start_trans = sendstop;      /* if Control+Q start transmission       */
        sendstop = 0;
        break;

      default:                       /* read all other characters into inbuf  */
        if (istart + ILEN != iend)  {
          inbuf[iend++ & (ILEN-1)] = c;
        }
                                     /* if task waiting: signal ready         */
        if (itask != 0xFF) isr_send_signal (itask);
        break;
    }
  }

  if (TI || start_trans)  {          /* if transmitter interrupt              */
    TI = 0;                          /* clear interrupt request flag          */
    if (ostart != oend)  {           /* if characters in buffer and           */
      if (!sendstop)  {              /* if not Control+S received             */
        SBUF = outbuf[ostart++ & (OLEN-1)];      /* transmit character        */
        sendfull = 0;                /* clear 'sendfull' flag                 */
                                     /* if task waiting: signal ready         */
        if (otask != 0xFF)  isr_send_signal (otask);
      }
    }
    else sendactive = 0;             /* if all transmitted clear 'sendactive' */
  }

}


/******************************************************************************/
/*       serial_init: initialize serial interface                             */
/******************************************************************************/
void serial_init (void)  {
  SCON  = 0x50;                      /* mode 1: 8-bit UART, enable receiver   */
  TMOD |= 0x20;                      /* timer 1 mode 2: 8-Bit reload          */
  TH1   = 0xf3;                      /* reload value 2400 baud                */
  TR1   = 1;                         /* timer 1 run                           */
  ES    = 1;                         /* enable serial port interrupt          */
}

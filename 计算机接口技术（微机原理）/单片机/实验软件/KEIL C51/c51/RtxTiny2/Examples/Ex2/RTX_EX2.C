/******************************************************************************/
/*                                                                            */
/*                     RTX_EX2.C:  A RTX-51 Application                       */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

long counter0;                        /* counter for task 0                   */
long counter1;                        /* counter for task 1                   */
long counter2;                        /* counter for task 2                   */
long counter3;                        /* counter for task 2                   */

/******************************************************************************/
/*       Task 0 'job0':  RTX-51 tiny starts execution with task 0             */
/******************************************************************************/
job0 () _task_ 0  {                  
  os_create_task (1);                 /* start task 1                         */
  os_create_task (2);                 /* start task 2                         */
  os_create_task (3);                 /* start task 3                         */

  while (1)  {                        /* endless loop                         */
    counter0++;                       /* increment counter 0                  */
    os_wait (K_TMO, 5, 0);            /* wait for timeout: 5 ticks            */
  }
}

/******************************************************************************/
/*   Task 1 'job1':  RTX-51 tiny starts this task with os_create_task (1)     */
/******************************************************************************/
job1 () _task_ 1  {
  while (1)  {                        /* endless loop                         */
    counter1++;                       /* increment counter 1                  */
    os_wait (K_TMO, 10, 0);           /* wait for timeout: 10 ticks           */
  }
}

/******************************************************************************/
/*    Task 2 'job2':  RTX-51 tiny starts this task with os_create_task (2)    */
/******************************************************************************/
job2 () _task_ 2  {
  while (1)  {                        /* endless loop                         */
    counter2++;                       /* increment counter 2                  */
    if ((counter2 & 0xFFFF) == 0)  {  /* signal overrun of counter 2          */
      os_send_signal (3);             /* to task 3                            */
    }
  }
}

/******************************************************************************/
/*    Task 3 'job3':  RTX-51 tiny starts this task with os_create_task (3)    */
/******************************************************************************/
job3 () _task_ 3  {
  while (1)  {                        /* endless loop                         */
    os_wait (K_SIG, 0, 0);            /* wait for signal                      */
    counter3++;                       /* process overflow from counter 2      */
  }
}

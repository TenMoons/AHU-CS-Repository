/******************************************************************************/
/*                                                                            */
/*   Task 0:  Create other Tasks and Count up Every 5 ticks                   */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

unsigned long counter0;               /* counter for task 0                   */

/******************************************************************************/
/*       Task 0 'job0':  RTX-51 tiny starts execution with task 0            */
/******************************************************************************/
void job0 (void) _task_ 0  {                  
  os_create_task (1);                 /* start task 1                         */
  os_create_task (2);                 /* start task 2                         */
  os_create_task (3);                 /* start task 3                         */

  while (1)  {                        /* endless loop                         */
    counter0++;                       /* increment counter 0                  */
    os_wait (K_TMO, 5, 0);            /* wait for timeout: 5 ticks            */
  }
}


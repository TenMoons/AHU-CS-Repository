/******************************************************************************/
/*                                                                            */
/*   Task 1:  Count up Every 2 ticks                                          */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

unsigned long counter1;               /* counter for task 1                   */

/******************************************************************************/
/*   Task 1 'job1':  RTX-51 tiny starts this task with os_create_task (1)     */
/******************************************************************************/
void job1 (void) _task_ 1  {
  while (1)  {                        /* endless loop                         */
    counter1++;                       /* increment counter 1                  */
    os_wait (K_TMO, 2, 0);            /* wait for timeout: 2 ticks            */
  }
}


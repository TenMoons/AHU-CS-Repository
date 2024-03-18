/******************************************************************************/
/*                                                                            */
/*   Task 2:  Count as fast as possible and Signal Overflow to Task 3         */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

unsigned long counter2;               /* counter for task 2                   */


/******************************************************************************/
/*    Task 2 'job2':  RTX-51 tiny starts this task with os_create_task (2)    */
/******************************************************************************/
void job2 (void) _task_ 2  {
  while (1)  {                        /* endless loop                         */
    counter2++;                       /* increment counter 1                  */
    if ((counter2 & 0x0F) == 0)  {    /* every 16 counts:                    */ 
      os_switch_task ();              /* give other tasks CPU time            */
    }
    if ((counter2 & 0xFFFF) == 0)  {  /* if counter overflows,                */
      os_set_ready (3);               /* set run flag of task 3               */
    }
  }
}


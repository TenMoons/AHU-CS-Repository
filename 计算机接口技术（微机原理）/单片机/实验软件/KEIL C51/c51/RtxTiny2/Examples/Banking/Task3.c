/******************************************************************************/
/*                                                                            */
/*   Task 3:  Process Overflow from Task 2                                    */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

unsigned long counter3;               /* counter for task 3                   */


/******************************************************************************/
/*    Task 3 'job3':  RTX-51 tiny starts this task with os_create_task (3)    */
/******************************************************************************/
void job3 (void) _task_ 3  {
  while (1)  {                        /* endless loop                         */
    os_wait0 ();                      /* wait for RDY                         */
    counter3++;                       /* process overflow from counter 2      */
  }
}

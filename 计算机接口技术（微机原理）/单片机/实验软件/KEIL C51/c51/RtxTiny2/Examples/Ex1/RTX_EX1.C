/******************************************************************************/
/*                                                                            */
/*                   RTX_EX1.C:  The first RTX-51 Program                     */
/*                                                                            */
/******************************************************************************/

#include <rtx51tny.h>                 /* RTX-51 tiny functions & defines      */

long counter0;                        /* counter for task 0                   */
long counter1;                        /* counter for task 1                   */
long counter2;                        /* counter for task 2                   */

/******************************************************************************/
/*       Task 0 'job0':  RTX-51 tiny starts execution with task 0             */
/******************************************************************************/
job0 () _task_ 0  {                  
  os_create_task (1);                 /* start task 1                         */
  os_create_task (2);                 /* start task 2                         */

  while (1)  {                        /* endless loop                         */
    counter0++;                       /* increment counter 0                  */
  }
}

/******************************************************************************/
/*    Task 1 'job1':  RTX-51 tiny starts this task with os_create_task (1)    */
/******************************************************************************/
job1 () _task_ 1  {
  while (1)  {                        /* endless loop                         */
    counter1++;                       /* increment counter 1                  */
  }
}

/******************************************************************************/
/*    Task 2 'job2':  RTX-51 tiny starts this task with os_create_task (2)    */
/******************************************************************************/
job2 () _task_ 2  {
  while (1)  {                        /* endless loop                         */
    counter2++;                       /* increment counter 2                  */
  }
}

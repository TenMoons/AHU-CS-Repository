/*--------------------------------------------------------------------------
RTX51TNY.H

Prototypes for RTX51 Tiny Real-Time Operating System Version 2.02
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __RTX51TNY_H__
#define __RTX51TNY_H__


/* constants for os_wait function */
#define K_SIG      0x01              /* Wait for Signal   */
#define K_TMO      0x02              /* Wait for Timeout  */
#define K_IVL      0x80              /* Wait for Interval */

/* function return values */
#define NOT_OK     0xFF              /* Parameter Error */
#define TMO_EVENT  0x08              /* Timeout Event   */
#define SIG_EVENT  0x04              /* Signal  Event   */
#define RDY_EVENT  0x80              /* Ready   Event   */

extern unsigned char os_create_task     (unsigned char task_id);
extern unsigned char os_delete_task     (unsigned char task_id);

extern unsigned char os_wait            (unsigned char typ, 
                                         unsigned char ticks,
                                         unsigned int dummy);
extern unsigned char os_wait1           (unsigned char typ);
extern unsigned char os_wait2           (unsigned char typ,
                                         unsigned char ticks);

extern unsigned char os_send_signal     (unsigned char task_id);
extern unsigned char os_clear_signal    (unsigned char task_id);
extern unsigned char isr_send_signal    (unsigned char task_id);

extern void          os_set_ready       (unsigned char task_id);
extern void          isr_set_ready      (unsigned char task_id);

extern unsigned char os_running_task_id (void);
extern unsigned char os_switch_task     (void); 

extern void          os_reset_interval  (unsigned char ticks);

#endif

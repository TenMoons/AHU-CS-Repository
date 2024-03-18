/*--------------------------------------------------------------------------
SETJMP.H

Prototypes for longjmp facility.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

/* define the buffer type for holding the state information */
#ifndef __SETJMP_H__
#define __SETJMP_H__

 #ifdef __CX51__
  #define _JBLEN	9  /* SP, SPE, ?C_XBP, ?C_IBP, ?C_PBP, RET-ADDR */
 #else
  #define _JBLEN	7  /* RET-ADDR, ?C_XBP, ?C_IBP, ?C_PBP, SP */
 #endif

typedef  char jmp_buf[_JBLEN];

/* function prototypes */
extern int  setjmp  (jmp_buf);
extern void longjmp (jmp_buf, int);
#endif


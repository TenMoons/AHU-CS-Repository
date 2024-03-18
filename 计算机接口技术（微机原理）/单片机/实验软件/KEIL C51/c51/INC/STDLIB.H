/*--------------------------------------------------------------------------
STDLIB.H

Standard functions.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STDLIB_H__
#define __STDLIB_H__

#ifndef _SIZE_T
 #define _SIZE_T
 typedef unsigned int size_t;
#endif

#ifndef NULL
 #define NULL ((void *) 0L)
#endif

#ifndef _WCHAR_T_DEFINED_
#define _WCHAR_T_DEFINED_
typedef char wchar_t;
#endif


#pragma SAVE
#pragma REGPARMS

extern int    abs  (int   val);
extern long  labs  (long  val);

extern float atof (char *s1);
extern long  atol (char *s1);
extern int   atoi (char *s1);
extern int   rand ();
extern void  srand (int);

extern float         strtod  (char *, char **);
extern long          strtol  (char *, char **, unsigned char);
extern unsigned long strtoul (char *, char **, unsigned char);

#define _MALLOC_MEM_	xdata

extern int  init_mempool          (void _MALLOC_MEM_ *p, unsigned int size);
extern void _MALLOC_MEM_ *malloc  (unsigned int size);
extern void free                  (void _MALLOC_MEM_ *p);
extern void _MALLOC_MEM_ *realloc (void _MALLOC_MEM_ *p, unsigned int size);
extern void _MALLOC_MEM_ *calloc  (unsigned int size, unsigned int len);

#pragma RESTORE

#endif

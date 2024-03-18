/*--------------------------------------------------------------------------
STDDEF.H

Standard definitions.
Copyright (c) 1988-2003 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __STDDEF_H__
#define __STDDEF_H__

#ifndef NULL
 #define NULL ((void *) 0)
#endif

#ifndef _SIZE_T
 #define _SIZE_T
 typedef unsigned int size_t;
#endif

typedef int          ptrdiff_t;
#define offsetof(s,m)	(size_t)&(((s code *)0)->m)

#endif


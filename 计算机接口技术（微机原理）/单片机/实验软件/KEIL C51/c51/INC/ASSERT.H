/*--------------------------------------------------------------------------
ASSERT.H

Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __ASSERT_H__
#define __ASSERT_H__

#undef assert

#ifndef	__ASSERT_INC
#include <stdio.h>	/* prototype for 'printf' */
#define	__ASSERT_INC
#endif

#ifndef NDEBUG

#define assert(expr) \
  if (expr) { ; } \
  else  {\
    printf("Assert failed: " #expr " (file %s line %d)\n", __FILE__, (int) __LINE__ );\
    while (1);\
  }
#else
#define	assert(expr)
#endif

#endif

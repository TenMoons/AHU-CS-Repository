/*-----------------------------------------------------------------------------
CALLOC.C is part of the C51 Compiler package from Keil Software.
Copyright (c) 1995-2002 Keil Software.  All rights reserved.
-----------------------------------------------------------------------------*/
#include "stdlib.h"
#include <string.h>

/*-----------------------------------------------------------------------------
-----------------------------------------------------------------------------*/
void _MALLOC_MEM_ *calloc (
  unsigned int size,
  unsigned int len)
{
void _MALLOC_MEM_ *p;

size *= len;

if ((p = malloc (size)) == NULL)
  return (NULL);

memset (p, 0, size);
return (p);
}


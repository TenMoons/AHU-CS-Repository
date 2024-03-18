/*-----------------------------------------------------------------------------
REALLOC.C is part of the C51 Compiler package from Keil Software.
Copyright (c) 1995-2002 Keil Software.  All rights reserved.
-----------------------------------------------------------------------------*/
#include <string.h>
#include "stdlib.h"

/*-----------------------------------------------
Memory pool block structure and typedefs.
Memory is laid out as follows:

{[NXT|LEN][BLK (LEN bytes)]}{[NXT|LEN][BLK]}...

Note that the size of a node is:
          __mem__.len + sizeof (__mem__)
-----------------------------------------------*/
struct __mem__
  {
  struct __mem__ _MALLOC_MEM_ *next;	/* single-linked list */
  unsigned int                 len;	/* length of following block */
  };

typedef struct __mem__         __memt__;
typedef __memt__ _MALLOC_MEM_ *__memp__;

#define	HLEN	(sizeof(__memt__))

/*-----------------------------------------------
Memory pool headers.  AVAIL points to the first
available block or is NULL if there are no free
blocks.  ROVER is a roving header that points to
a block somewhere in the list.

Note that the list is maintained in address
order.  AVAIL points to the block with the
lowest address.  That block points to the block
with the next higher address and so on.
-----------------------------------------------*/
extern __memt__ _MALLOC_MEM_ __mem_avail__ [];

#define AVAIL	(__mem_avail__[0])


/*-----------------------------------------------------------------------------
-----------------------------------------------------------------------------*/
void _MALLOC_MEM_ *realloc (
  void _MALLOC_MEM_ *oldp,
  unsigned int size)
{
__memp__ p0;
void _MALLOC_MEM_ *newp;

/*-----------------------------------------------
-----------------------------------------------*/
if ((oldp == NULL) || (AVAIL.len == 0))
  return (NULL);

p0 = oldp;
p0 = &p0 [-1];		/* get address of header */

/*-----------------------------------------------
-----------------------------------------------*/
if ((newp = malloc (size)) == NULL)
  {
  return (NULL);
  }

if (size > p0->len)
  size = p0->len;

memcpy (newp, oldp, size);
free (oldp);

return (newp);
}



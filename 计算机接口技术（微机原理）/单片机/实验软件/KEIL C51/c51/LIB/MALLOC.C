/*-----------------------------------------------------------------------------
MALLOC.C is part of the C51 Compiler package from Keil Software.
Copyright (c) 1995-2002 Keil Software.  All rights reserved.
-----------------------------------------------------------------------------*/
#include <stdlib.h>

/*-----------------------------------------------
Memory pool block structure and typedefs.
Memory is laid out as follows:

{[NXT|LEN][BLK (LEN bytes)]}{[NXT|LEN][BLK]}...

Note that the size of a node is:
          __mem__.len + sizeof (__mem__)
-----------------------------------------------*/
struct __mem__
  {
  struct __mem__ _MALLOC_MEM_ *next;    /* single-linked list */
  unsigned int                len;      /* length of following block */
  };

typedef struct __mem__         __memt__;
typedef __memt__ _MALLOC_MEM_ *__memp__;

#define	HLEN	(sizeof(__memt__))

/*-----------------------------------------------
Memory pool headers.  AVAIL points to the first
available block or is NULL if there are no free
blocks.

Note that the list is maintained in address
order.  AVAIL points to the block with the
lowest address.  That block points to the block
with the next higher address and so on.
-----------------------------------------------*/
extern __memt__ _MALLOC_MEM_ __mem_avail__ [];

#define AVAIL	(__mem_avail__[0])

#define MIN_BLOCK	(HLEN * 4)

/*-----------------------------------------------------------------------------
void _MALLOC_MEM_ *malloc (
  unsigned int size);			number of bytes to allocate

Return Value
------------
    NULL	FAILURE:  No free blocks of size are available
  NON-NULL	SUCCESS:  Address of block returned
-----------------------------------------------------------------------------*/
void _MALLOC_MEM_ *malloc (
  unsigned int size)
{
__memp__ q;			/* ptr to free block */
__memp__ p;			/* q->next */
unsigned int k;			/* space remaining in the allocated block */

/*-----------------------------------------------
Initialization:  Q is the pointer to the next
available block.
-----------------------------------------------*/
q = &AVAIL;

/*-----------------------------------------------
End-Of-List:  P points to the next block.  If
that block DNE (P==NULL), we are at the end of
the list.
-----------------------------------------------*/
while (1)
  {
  if ((p = q->next) == NULL)
    {
    return (NULL);				/* FAILURE */
    }

/*-----------------------------------------------
Found Space:  If block is large enough, reserve
if.  Otherwise, copy P to Q and try the next
free block.
-----------------------------------------------*/
  if (p->len >= size)
    break;

  q = p;
  }

/*-----------------------------------------------
Reserve P:  Use at least part of the P block to
satisfy the allocation request.  At this time,
the following pointers are setup:

P points to the block from which we allocate
Q->next points to P
-----------------------------------------------*/
k = p->len - size;		/* calc. remaining bytes in block */

if (k < MIN_BLOCK)		/* rem. bytes too small for new block */
  {
  q->next = p->next;
  return (&p[1]);				/* SUCCESS */
  }

/*-----------------------------------------------
Split P Block:  If P is larger than we need, we
split P into two blocks:  the leftover space and
the allocated space.  That means, we need to
create a header in the allocated space.
-----------------------------------------------*/
k -= HLEN;
p->len = k;

q = (__memp__ ) (((char _MALLOC_MEM_ *) (&p [1])) + k);
q->len = size;

return (&q[1]);					/* SUCCESS */
}




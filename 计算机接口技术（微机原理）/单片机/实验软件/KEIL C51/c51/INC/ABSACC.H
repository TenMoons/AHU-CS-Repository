/*--------------------------------------------------------------------------
ABSACC.H

Direct access to 8051, extended 8051 and Philips 80C51MX memory areas.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __ABSACC_H__
#define __ABSACC_H__

#define CBYTE ((unsigned char volatile code  *) 0)
#define DBYTE ((unsigned char volatile data  *) 0)
#define PBYTE ((unsigned char volatile pdata *) 0)
#define XBYTE ((unsigned char volatile xdata *) 0)

#define CWORD ((unsigned int volatile code  *) 0)
#define DWORD ((unsigned int volatile data  *) 0)
#define PWORD ((unsigned int volatile pdata *) 0)
#define XWORD ((unsigned int volatile xdata *) 0)


#ifdef __CX51__
#define FVAR(object, addr)   (*((object volatile far *) (addr)))
#define FARRAY(object, base) ((object volatile far *) (base))
#define FCVAR(object, addr)   (*((object const far *) (addr)))
#define FCARRAY(object, base) ((object const far *) (base))
#else
#define FVAR(object, addr)    (*((object volatile far *) ((addr)+0x10000L)))
#define FCVAR(object, addr)   (*((object const far *) ((addr)+0x810000L)))
#define FARRAY(object, base)  ((object volatile far *) ((base)+0x10000L))
#define FCARRAY(object, base) ((object const far *) ((base)+0x810000L))
#endif

#endif

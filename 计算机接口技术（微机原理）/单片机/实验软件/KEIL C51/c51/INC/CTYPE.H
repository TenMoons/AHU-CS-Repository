/*--------------------------------------------------------------------------
CTYPE.H

Prototypes for character functions.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __CTYPE_H__
#define __CTYPE_H__

#pragma SAVE
#pragma REGPARMS
extern bit isalpha (unsigned char);
extern bit isalnum (unsigned char);
extern bit iscntrl (unsigned char);
extern bit isdigit (unsigned char);
extern bit isgraph (unsigned char);
extern bit isprint (unsigned char);
extern bit ispunct (unsigned char);
extern bit islower (unsigned char);
extern bit isupper (unsigned char);
extern bit isspace (unsigned char);
extern bit isxdigit (unsigned char);
extern unsigned char tolower (unsigned char);
extern unsigned char toupper (unsigned char);
extern unsigned char toint (unsigned char);

#define _tolower(c) ( (c)-'A'+'a' )
#define _toupper(c) ( (c)-'a'+'A' )
#define toascii(c)  ( (c) & 0x7F )
#pragma RESTORE

#endif

/*--------------------------------------------------------------------------
LIMITS.H

ANSI standard include file.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __LIMITS_H__
#define __LIMITS_H__

#define CHAR_BIT         8              /* Number of bits in any "char" */
#define CHAR_MAX         127            /* Max             "char" value */
#define CHAR_MIN       (-128)           /* Min             "char" value */
#define SCHAR_MAX        127            /* Max "signed"    "char" value */
#define SCHAR_MIN      (-128)           /* Min "signed"    "char" value */
#define UCHAR_MAX        255            /* Max "unsigned"  "char" value */
#define SHRT_MAX         32767          /* Max ("signed") "short" value */
#define SHRT_MIN       (-32768)         /* Min ("signed") "short" value */
#define USHRT_MAX        0xFFFF         /* Max "unsigned" "short" value */
#define INT_MAX          32767          /* Max ("signed")   "int" value */
#define INT_MIN        (-32768)         /* Min ("signed")   "int" value */
#define UINT_MAX         0xFFFF         /* Max "unsigned"   "int" value */
#define LONG_MAX         2147483647     /* Max ("signed")  "long" value */
#define LONG_MIN        -2147483648     /* Min ("signed")  "long" value */
#define ULONG_MAX        0xFFFFFFFF     /* Max "unsigned"  "long" value */

#endif

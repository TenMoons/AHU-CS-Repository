/*--------------------------------------------------------------------------
C505LEXT.H

Header file for extended LCD and RTC Register Definitions for the C505L Processor
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __C505LEXT_H__
#define __C505LEXT_H__

/* LCD Controller */
#define LCON (*((unsigned char volatile xdata*)0xF3DD))
#define LCRL (*((unsigned char volatile xdata*)0xF3DE))
#define LCRH (*((unsigned char volatile xdata*)0xF3DE))
#define DIG0 (*((unsigned char volatile xdata*)0xF3E0))
#define DIG1 (*((unsigned char volatile xdata*)0xF3E1))
#define DIG2 (*((unsigned char volatile xdata*)0xF3E2))
#define DIG3 (*((unsigned char volatile xdata*)0xF3E3))
#define DIG4 (*((unsigned char volatile xdata*)0xF3E4))
#define DIG5 (*((unsigned char volatile xdata*)0xF3E5))
#define DIG6 (*((unsigned char volatile xdata*)0xF3E6))
#define DIG7 (*((unsigned char volatile xdata*)0xF3E7))
#define DIG8 (*((unsigned char volatile xdata*)0xF3E8))
#define DIG9 (*((unsigned char volatile xdata*)0xF3E9))
#define DIGA (*((unsigned char volatile xdata*)0xF3EA))
#define DIGB (*((unsigned char volatile xdata*)0xF3EB))
#define DIGC (*((unsigned char volatile xdata*)0xF3EC))
#define DIGD (*((unsigned char volatile xdata*)0xF3ED))
#define DIGE (*((unsigned char volatile xdata*)0xF3EE))
#define DIGF (*((unsigned char volatile xdata*)0xF3EF))

/* RTC Real Time Clock */
#define RTCCON (*((unsigned char volatile xdata*)0xF3F0))
#define RTCR0  (*((unsigned char volatile xdata*)0xF3F1))
#define RTCR1  (*((unsigned char volatile xdata*)0xF3F2))
#define RTCR2  (*((unsigned char volatile xdata*)0xF3F3))
#define RTCR3  (*((unsigned char volatile xdata*)0xF3F4))
#define RTCR4  (*((unsigned char volatile xdata*)0xF3F5))
#define CLREG0 (*((unsigned char volatile xdata*)0xF3F6))
#define CLREG1 (*((unsigned char volatile xdata*)0xF3F7))
#define CLREG2 (*((unsigned char volatile xdata*)0xF3F8))
#define CLREG3 (*((unsigned char volatile xdata*)0xF3F9))
#define CLREG4 (*((unsigned char volatile xdata*)0xF3FA))
#define RTINT0 (*((unsigned char volatile xdata*)0xF3FB))
#define RTINT1 (*((unsigned char volatile xdata*)0xF3FC))
#define RTINT2 (*((unsigned char volatile xdata*)0xF3FD))
#define RTINT3 (*((unsigned char volatile xdata*)0xF3FE))
#define RTINT4 (*((unsigned char volatile xdata*)0xF3FF))

#endif


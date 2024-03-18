/*--------------------------------------------------------------------------
C5X5CEXT.H

Header file for Extended CAN Register Definitions for the C505C and C515C CAN Processors.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __C5X5CEXT_H__
#define __C5X5CEXT_H__

#define CR (*((unsigned char volatile xdata*)0xF700))
#define SR (*((unsigned char volatile xdata*)0xF701))
#define IR (*((unsigned char volatile xdata*)0xF702))
#define BTR0 (*((unsigned char volatile xdata*)0xF704))
#define BTR1 (*((unsigned char volatile xdata*)0xF705))
#define GMS0 (*((unsigned char volatile xdata*)0xF706))
#define GMS1 (*((unsigned char volatile xdata*)0xF707))
#define UGML0 (*((unsigned char volatile xdata*)0xF708))
#define UGML1 (*((unsigned char volatile xdata*)0xF709))
#define LGML0 (*((unsigned char volatile xdata*)0xF70A))
#define LGML1 (*((unsigned char volatile xdata*)0xF70B))
#define UMLM0 (*((unsigned char volatile xdata*)0xF70C))
#define UMLM1 (*((unsigned char volatile xdata*)0xF70D))
#define LMLM0 (*((unsigned char volatile xdata*)0xF70E))
#define LMLM1 (*((unsigned char volatile xdata*)0xF70F))

#if 0
/* Message Object Registers */
#define MCR0 (*((unsigned char volatile xdata*)0xF7n0))
#define MCR1 (*((unsigned char volatile xdata*)0xF7n1))
#define UART0 (*((unsigned char volatile xdata*)0xF7n2))
#define UART1 (*((unsigned char volatile xdata*)0xF7n3))
#define LAR0 (*((unsigned char volatile xdata*)0xF7n4))
#define LAR1 (*((unsigned char volatile xdata*)0xF7n5))
#define MCFG (*((unsigned char volatile xdata*)0xF7n6))
#define DB0 (*((unsigned char volatile xdata*)0xF7n7))
#define DB1 (*((unsigned char volatile xdata*)0xF7n8))
#define DB2 (*((unsigned char volatile xdata*)0xF7n9))
#define DB3 (*((unsigned char volatile xdata*)0xF7nA))
#define DB4 (*((unsigned char volatile xdata*)0xF7nB))
#define DB5 (*((unsigned char volatile xdata*)0xF7nC))
#define DB6 (*((unsigned char volatile xdata*)0xF7nD))
#define DB7 (*((unsigned char volatile xdata*)0xF7n0))
/* The notation "n" (n = 1 to F) in the message object address 
   definition defines the number of the related message object. */
#endif

#endif

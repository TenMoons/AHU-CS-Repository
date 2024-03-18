/*------------------------------------------------------------------------
SROM.H

Handling for SROM MEMORY SECTIONS for C51 Version 7.
Copyright (c) 1998-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
-------------------------------------------------------------------------*/

#ifndef __SROM_H__
#define __SROM_H__

/*
 * Macros that create external definitions for start, length, target
 * address, length and bank number.  The external symbol references 
 * are resolved by the LX51 linker/Locater.
 */
#define SROM_PS(n)                                                  \
extern unsigned char  _PR_##n##_S_;  /* segment start */            \
extern unsigned char  _PR_##n##_E_;  /* segment end */              \
extern unsigned char  _PR_##n##_L_;  /* segment len */              \
extern unsigned char  _PR_##n##_T_;  /* segment target address */   \
extern unsigned char  _PR_##n##_B_;  /* segment bank address */

#define SROM_MC(n)                                                  \
extern unsigned char  _##n##_S_;     /* class start */              \
extern unsigned char  _##n##_E_;     /* class end */                \
extern unsigned char  _##n##_L_;     /* class len */                \
extern unsigned char  _##n##_T_;     /* class target address */     \
extern unsigned char  _##n##_B_;     /* class bank address */

/*
 * The following MACROS create references for the target address, 
 * source address, end address, length and bank number of segments 
 * and classes.
 */
#define SROM_PS_TRG(n) ((void *)       &_PR_##n##_T_)
#define SROM_PS_SRC(n) ((void *)       &_PR_##n##_S_)
#define SROM_PS_END(n) ((void *)       &_PR_##n##_E_)
#define SROM_PS_LEN(n) ((unsigned int) &_PR_##n##_L_)
#define SROM_PS_BNK(n) ((unsigned int) &_PR_##n##_B_)

#define SROM_MC_TRG(n) ((void *)       &_##n##_T_)
#define SROM_MC_SRC(n) ((void *)       &_##n##_S_)
#define SROM_MC_END(n) ((void *)       &_##n##_E_)
#define SROM_MC_LEN(n) ((unsigned int) &_##n##_L_)
#define SROM_MC_BNK(n) ((unsigned int) &_##n##_B_)

#endif


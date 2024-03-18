/*--------------------------------------------------------------------------
MATH.H

Prototypes for mathematic functions.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __MATH_H__
#define __MATH_H__

#pragma SAVE
#pragma REGPARMS
extern char  cabs  (char  val);
extern int    abs  (int   val);
extern long  labs  (long  val);
extern float fabs  (float val);
extern float sqrt  (float val);
extern float exp   (float val);
extern float log   (float val);
extern float log10 (float val);
extern float sin   (float val);
extern float cos   (float val);
extern float tan   (float val);
extern float asin  (float val);
extern float acos  (float val);
extern float atan  (float val);
extern float sinh  (float val);
extern float cosh  (float val);
extern float tanh  (float val);
extern float atan2 (float y, float x);

extern float ceil  (float val);
extern float floor (float val);
extern float modf  (float val, float *n);
extern float fmod  (float x, float y);
extern float pow   (float x, float y);

#pragma RESTORE

#endif

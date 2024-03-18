/*--------------------------------------------------------------------------
80C517.H

Prototypes for 80C517 specific functions.
Copyright (c) 1988-1997 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#pragma SAVE
#pragma REGPARMS
extern float sqrt517  (float val);
extern float exp517   (float val);
extern float log517   (float val);
extern float log10517 (float val);
extern float sin517   (float val);
extern float cos517   (float val);
extern float tan517   (float val);
extern float asin517  (float val);
extern float acos517  (float val);
extern float atan517  (float val);

extern int printf517  (const char *, ...);
extern int sprintf517 (char *, const char *, ...);
extern int scanf517   (const char *, ...);
extern int sscanf517  (char *, const char *, ...);

extern float atof517   (void *s1);
extern float strtod517 (char *, char **);
#pragma RESTORE

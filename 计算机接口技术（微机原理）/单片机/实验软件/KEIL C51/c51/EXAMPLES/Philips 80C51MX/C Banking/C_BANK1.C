/*------------------------------------------------------------------------------
C_BANK1.C

Copyright 2000 KEIL Software, Inc.
------------------------------------------------------------------------------*/

#include <stdio.h>

extern void func0(void);

void func1(void) {
  printf("FUNCTION IN BANK 1 CALLS A FUNCTION IN BANK 0 \n");
  func0();
}

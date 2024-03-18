/*
 *  This file contains the data defintions that are stored in EEPROM
 */

#ifndef DECLARE                    // if DECLARE is not defined
  #define DECLARE  extern          // variables are extern
#endif

struct sample  {
  char carray[20];
  int  iarray[20];
  long larray[20];
};

DECLARE struct sample far esample1;  // reserve space for esample1 struct
DECLARE struct sample far esample2;  // reserve space for esample2 struct
DECLARE char *        far etxt_ptr;  // pointer in EEPROM space



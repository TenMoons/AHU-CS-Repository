#include "record.h"
#include <REG51M.H>

float f;

void main (void)  {
  RECORD far *p1;
  RECORD far *p2;

  p1       = pRecord(14000);      // Address Record #14000
  p1->c0   = 5;
  p1->f    = 14000.0;
  p1->i[0] = 0;
  p1->i[1] = 1;
  p1->i[2] = 2;
  p1->i[3] = 3;
  p1->i[4] = 4;

  p2       = pRecord(13000);      // Address Record #13000
  *p2      = *p1;                 // copy records
  p2->f    = 13000.0;
  p2->next = p1;

  f = p2->next->f;
  while (1);
}






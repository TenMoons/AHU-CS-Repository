/*------------------------------------------------------------------------------
CSAMPLE2.C

Copyright 1995-1999 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <stdio.h>                             /* define I/O functions */

void getline (char *line)  {
  while ((*line++ = getchar()) != '\n');
}

int atoi (char *line)  {
  bit sign;
  int number;

  /* skip white space */
  for ( ; *line == ' ' || *line == '\n' || *line == '\t'; line++);

  /* establish sign */
  sign = 1;
  if (*line == '+' || *line == '-')  sign = (*line++ == '+');

  /* compute decimal value */
  for (number=0; *line >= '0' && *line <= '9'; line++)
    number = (number * 10) + (*line - '0');

  return (sign ? number : -number);
}

unsigned int getnumber (void)  {
  char line [40];
  
  printf ("Input Number ? ");
  getline (line);
  return (atoi (line));
}


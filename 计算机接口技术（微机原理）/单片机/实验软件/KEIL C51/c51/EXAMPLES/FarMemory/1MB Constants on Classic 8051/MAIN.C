#include <REG320.H>                      // SFR definition header file
#include <stdio.h>                       // prototype declarations for I/O functions

#include "text.h"                        // definitions for the text strings

#ifdef MONITOR51                         // Debugging with Monitor-51 needs
char code reserve [3] _at_ 0x23;         // space for serial interrupt if
#endif                                   // Stop Exection with Serial Intr.


unsigned char language;                  // this variable selects the language

void PrintText (char **text)  {
  printf ("Language %bd: Text String \"%s\"\n", language, text[language]);
}

  

void main (void) {
/*------------------------------------------------
Setup the serial port for 1200 baud at 16MHz.
------------------------------------------------*/
#ifndef MONITOR51
  SCON0 = 0x50;               // SCON: mode 1, 8-bit UART, enable rcvr
  TMOD |= 0x20;               // TMOD: timer 1, mode 2, 8-bit reload
  TH1   = 221;                // TH1:  reload value for 1200 baud @ 16MHz
  TR1   = 1;                  // TR1:  timer 1 run
  TI    = 1;                  // TI:   set TI to send first char of UART
#endif

  for (language = 0; language < NO_LANG; language++)  {
    PrintText (&text0);
    PrintText (&text1);
    PrintText (&text2);
    PrintText (&text3);
  }
  while (1);
}



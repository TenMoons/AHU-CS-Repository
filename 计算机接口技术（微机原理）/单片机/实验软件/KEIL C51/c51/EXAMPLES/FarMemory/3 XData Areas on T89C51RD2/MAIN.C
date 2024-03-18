#include <89c51rd2.H>              // SFR definition header file
#include <stdio.h>                 // prototype declarations for I/O functions
#include <eeprom.h>                // include EEPROM variables

// on-chip xdata RAM (XRAM) variables are defined with memory type 'far'
struct xsample  {
  char carray[20];
  int  iarray[20];
  long larray[20];
};

struct xsample far xsample1;  // reserve space for xsample1 struct
struct xsample far xsample2;  // reserve space for xsample2 struct
char * far         xtxt_ptr;  // pointer in XRAM space


// off-chip xdata RAM variables are defined with memory type 'xdata'
char xdata array[0x1000];     // 0x1000 bytes in xdata space

#ifdef MONITOR51                         /* Debugging with Monitor-51 needs   */
char code reserve [3] _at_ 0x23;         /* space for serial interrupt if     */
#endif                                   /* Stop Exection with Serial Intr.   */


/*
 *  This routine stores some values into the EEPROM for testing
 */
void store_eeprom (void)  {
  unsigned char i;

  for (i = 0; i < 20; i++)  {
    esample1.carray[i] = i;               // Store some values to show how it works
    esample2.carray[i] = i + 10;
    esample1.iarray[i] = 0xFF00+i;
    esample2.iarray[i] = 0xFE00+i;
    esample1.larray[i] = 0xABCDEF00+i;
    esample2.larray[i] = 0x12345600+i;
  }
  etxt_ptr = "Store External EEPROM Done";      // Pointer to Text in ROM
}


/*
 *  This routine stores some values into on-chip XRAM for testing
 */
void store_xram (void)  {
  unsigned char i;

  for (i = 0; i < 20; i++)  {
    xsample1.carray[i] = i + 40;                // Store some values to show how it works
    xsample2.carray[i] = i + 80;
    xsample1.iarray[i] = 0x0F00+i;
    xsample2.iarray[i] = 0x0E00+i;
    xsample1.larray[i] = 0x45678900+i;
    xsample2.larray[i] = 0xFEDCBA00+i;
  }
  xtxt_ptr = "Store External XRAM Done";         // Pointer to Text in ROM
}
 

/*------------------------------------------------
The main C function.  Program execution starts
here after stack initialization.
------------------------------------------------*/

void main (void) {
  unsigned char i;
/*------------------------------------------------
Setup the serial port for 1200 baud at 16MHz.
------------------------------------------------*/
  EETIM = 5 * 40;             // EETIM: 5 * 40 MHz in normal mode

#ifndef MONITOR51
  SCON  = 0x50;               // SCON: mode 1, 8-bit UART, enable rcvr
  TMOD |= 0x20;               // TMOD: timer 1, mode 2, 8-bit reload
  TH1   = 221;                // TH1:  reload value for 1200 baud @ 16MHz
  TR1   = 1;                  // TR1:  timer 1 run
  TI    = 1;                  // TI:   set TI to send first char of UART
#endif

  esample1.carray[0] = 4;
  xsample1.carray[0] = 8;
  array[0] = 12;

  
  store_eeprom ();            // store some values in EEPROM
  store_xram ();              // store some values in on-chip XRAM

                              // Read Back Values from EEPROM
  for (i = 0; i < 20; i++)  {
    printf ("\n%bd %bd %bd %x %x", i, esample1.carray[i],
                                      esample2.carray[i],
                                      esample1.iarray[i],
                                      esample2.iarray[i]);
  }
  printf ("\n%s", etxt_ptr);

                              // Read Back Values from on-chip XRAM
  for (i = 0; i < 20; i++)  {
    printf ("\n%bd %bd %bd %x %x", i, xsample1.carray[i],
                                      xsample2.carray[i],
                                      xsample1.iarray[i],
                                      xsample2.iarray[i]);
  }
  printf ("\n%s", xtxt_ptr);

  while (1);
}


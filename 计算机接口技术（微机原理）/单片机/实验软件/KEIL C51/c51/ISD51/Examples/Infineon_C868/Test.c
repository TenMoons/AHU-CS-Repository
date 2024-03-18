/*------------------------------------------------------------------------------
TEST.C:  ISD51 Demo for Infineon C868

Copyright 2003 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <REG868.H>
#include <intrins.h>
#include <stdio.h>
#include "ISD51.h"

unsigned char j;
unsigned char code testarray[] = "Some Text";

//#define ADC        // uncomment to use the A/D converter interrupt
#ifdef ADC
unsigned char data ADresult;

void ADC_Init(void) {

  ADCON1 = 0x43;     // set conversion timings
  ADCON0 = 0x00;     // channel 0
  IEN1 |= 0x01;      // set EADC
}

void ADC_viIsr(void) interrupt 6 { //ADCINT

  P3 ^= 0x80;
  ADresult = ADDATH; // read ADvalue
  IRCON1  &= ~0x01;  // clear IADC 
}
#endif

void Project_Init(void)  {
  SCUWDT   = 0x04;   // disable WDT
  CMCON    = 0x40;
  P1ALT    = 0x11;   // P1ALT.4 and P1ALT.0=1, Alternate functions
  SYSCON0 |= 0x10;   
  P1 = 0x10;         // P1DIR.4=1, P1.4/RxD is an input   
  P3 = 0x00;         // P3                  is    output
  SYSCON0 &= 0xef;
  T2CON = 0;         // reset timer 2 (used in bootstrap mode)
  PCON |= 0x80;      // SMOD = 1; 
  SCON  = 0x50;      // enable serial uart & receiver
  TMOD |= 0x20;      // TMOD: timer 1, mode 2, 8-bit reload
#ifdef SK868
  TH1   = 0xEA;      // TH1:  reload value for 9600 baud @ 10.6MHz (SK-C868)
#endif
#ifdef MINIC868
  TH1   = 0xEC;      // TH1:  reload value for 9600 baud @ 10MHz (MiniC868)
#endif
  TR1   = 1;         // TR1:  timer 1 run

  IP0 |= 0x11;       // IP0.4 = UART  to Level 3
  IP1 |= 0x10;       // IP0.0 = ADC   to Level 1
                     //         other to Level 0  
  EA = 1;            // enable globally all interrupts
}


#if 0   // uncomment this function to verify serial communication

/*
 * Test Function: verify serial communication with HyperTerminal
 */
void TestSerial (void)  {
  char c = 'A';

  TI = 1;
  while (1)  {
    if (RI)  {
      c = SBUF;
      RI = 0;
    }
    while (!TI);
    TI = 0;
    SBUF = c;
  }
}

#endif



void delay(void) {
  long i;

  i = 0x800;
  while(i--);
}

void main (void)  {
  unsigned int i;

  ES = 0;             // fix C868 bootstrap loader problem because of ES = 1
  Project_Init();     // Initialize Chip and Serial Interface

#ifdef ADC
  ADC_Init();         // initalize ADC	
#endif

//TestSerial ();      // uncomment this function to verify serial communication
 
#if 0   // init ISD51 and start user program until the uVision2 Debugger connects
  ISDinit ();        // initialize uVision2 Debugger and continue program run
#endif

#if 0   // init ISD51 and wait until the uVision2 Debugger connects
  ISDwait ();        // wait for connection to uVision2 Debugger
#endif

  for (i = 0; i < sizeof (testarray); i++)  {
    j = testarray[i];
  }

  while (1)  {
#if 1   // init ISD51 only when the uVision2 Debugger tries to connect
    ISDcheck();      // initialize uVision2 Debugger and continue program run
#endif

#ifdef ADC
    ADCON0 |= 0x80;   // start ADC channel 0
#endif
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
    _nop_();
#ifdef ADC
    P3 ^= 0x10;       // toggle LED when using the A/D converter
#else 
    P3++;             // flash with all colors when A/D converter is not used
#endif
    j++;
    _nop_();
    _nop_();
    _nop_();
    delay();
#if 0   // you may use ISDbreak when ISD51 is started with ISDcheck or ISDwait
    ISDbreak ();  // hard coded stop (breakpoint)
#endif
    _nop_();
    _nop_();
    _nop_();
  }
}



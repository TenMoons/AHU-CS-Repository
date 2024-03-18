/*------------------------------------------------------------------------------
AD8Input.C:  MSC 1210 A/D Conversion for 8 single ended channels.
             Uses 0-5V on inputs AIN0 to AIN7 and AINCOM = 2.5V.

Copyright 2003 Keil Software, Inc.
------------------------------------------------------------------------------*/

#include <REG1210.H>
#include <stdio.h>
#include "ISD51.H"

#ifndef XTAL                        // if no XTAL defined use:
  #define XTAL  11059200            // XTAL frequency 11.0592 MHz
#endif

// defines for UART BAUDRATE
#define BAUDRATE          9600      // 9600bps communication baudrate
#define T2RELOAD   (65536-(XTAL/32/BAUDRATE))

// defines for A/D Converter setup
#define A_CLK          (((XTAL+500000)/1000000)-1) // about 1MHz Analog Clock
#define ANA_CLK        (XTAL/(A_CLK+1))            // precise Analog Clock
#define DECIMATION_VAL (ANA_CLK/64/10)             // 10 Hz Decimation
#define CONV_FREQ      (ANA_CLK/64/DECIMATION)     // Conversion Frequency

// defines for conversion to Volts
#define fV    (0xFFFFFF00UL/5)      // Factor for Volts caluculation
#define fmV   ((fV << 2) / 1000)    // Factor for mVolts
#define fuV   ((fmV << 10) / 1000)  // Factor for uVolts

// Helper structure to read in ADC values
union  {
  unsigned char  c[4];              // bytes
  unsigned long  l;                 // unsigned long
} res;


void main(void)  {
  unsigned char k, chan, V;
  unsigned int  mV, uV;

  CKCON = 0;                          // 0 MOVX cycle stretch

// Setup Serial Interface
  T2CON   = 0x34;                     // Use Timer 2 as baudrate generator  */
  RCAP2   = T2RELOAD;                 // baudrate reload factor (RCAP2H | RCAP2L)

  SCON0   = 0x50;                     // enable serial uart & receiver
  PCON   |= 0x80;                     // double baudrate for UART0
  P3DDRL &= 0xF0;                     // set port pins of UART to input/strong drive output
  P3DDRL |= 0x07;                     // set port pins of UART to input/strong drive output


#ifdef ISD51
// The following settings are important for ISD51 (enable flash programming, disable watchdog)
  USEC   = ((XTAL+500000)/1000000)-1; // USEC timer factor
  ONEMS  = (XTAL/1000)-1;             // (MSECH+MSCL) MS Timer counting at 1.0ms

  HMSEC  = 100-1;                     // Hundred MS Timer to 100.0ms
  SECINT = (10-1) | 0x80;             // SECINT= 10 * HMS Timer Rate = 1 sec
                                      // '0x80' will set the MSB for write immediate
  MSINT  = (10-1) | 0x80;             // MSINT = 10ms for Tone period time base

  FTCON  = 0xA5;                      // setup flash programming times
#endif

  PDCON  = 0x14;                      // ON -> ADC-Vref, SPI Systimers. OFF -> PWM, Watchdog
  EA = 1;                             // Enable global interrupt flag


#ifdef ISD51
  ISDwait();                          // wait until ISD51 connects
#else
  TI = 1;                             // enable serial output
#endif

  printf("\nMSC1210 Analog/Dignal Converter Test\n\n");

// Setup ADC
  ADMUX  = 0x08;                    // (AIN+ = AIN0), (AIN- = AINCOM) Voltage from DAC
  ACLK   = A_CLK;                   // set ACLK factor for about 1MHz
  ADCON0 = 0x30;                    // Vref On, Vref Hi, Buff off, BOD off, PGA

  DECIMATION = DECIMATION_VAL;      // Set decimation in ADCON2 & ADCON3
  ADCON1 = 0x00;                    // unipolar, auto, self calibration (offset, gain)


  while (1)  {                      // Repeat Conversions Forever
    printf("\nSingle-Ended 0V to 5V inputs, AINCOM=2.5V\n\n");
    printf("Chan.  Dec.  Rate   Hex Value   Voltage\n");

    for (chan=0; chan<8; chan++) {  // Channels Loop
      ADMUX = (chan<<4) | 8;        // AINP = chan, AINN = AINCOM

// Read Input Volatage
      for (k=0; k<4; k++) {         // ignore 3 conversions for filter to settle after calibration
        while (!(AIE & 0x20));      // Wait for data ready
        res.c[0] = ADRESH ^ 0x80;   // Invert the Most significant bit (only positiv inputs)
        res.c[1] = ADRESM;
        res.c[2] = ADRESL;
        res.c[3] = 0;
      }

      printf ("%3bd %7d %3dHz   ", chan, (int) DECIMATION, (int) CONV_FREQ);
      printf ("0x%06lX    ", (res.l >> 8));

// Convert Result to Volts 
      V = res.l / fV;               // Volts part
      res.l %= fV;
      res.l <<= 2;

      mV = res.l / fmV;             // Millivolts part
      res.l %= fmV;
      res.l <<= 10;
      
      uV = res.l / fuV;             // Microvolts part
      printf ("%bd.%03d%03d\n", V, mV, uV);
    }
  }

}




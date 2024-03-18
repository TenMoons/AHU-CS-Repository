/*------------------------------------------------------------------------------
AD_Interrupt.C:  MSC 1210 A/D Conversion for 1 input signals (-2.5V ... +2.5V)
                 Inputs pairs  AIN0-AIN1  read in an interrupt service routine
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
#define A_CLK      (((XTAL+500000)/1000000)-1) // about 1MHz Analog Clock
#define ANA_CLK    (XTAL/(A_CLK+1))            // precise Analog Clock
#define DECIMATION (ANA_CLK/64/10)             // 10 Hz Decimation
#define CONV_FREQ  (ANA_CLK/64/DECIMATION)     // Conversion Frequency

// defines for conversion to Volts
#define VBIT  (2.5 / 0x800000)      // 0x800000 represents 2.5 Volts

// Helper structure to read in ADC values
static union  {
  unsigned char  c[4];              // bytes
  signed   int   i[2];              // signed words
  signed   long  l;                 // signed long
} res;


static bit  Second_Interrupt;

static void AUXinterrupts (void) interrupt 6  {
  unsigned char x;

  switch (PAI)     {
    case 6:                        // A/D interrupt
      res.c[3] = ADRESL;
      res.c[2] = ADRESM;
      res.i[0] = (char) ADRESH;    // make sign extension
      break;

    case 8:                        // Second Interrupt
      x = SECINT;                  // Dummy Read to Clear SEC Interrupt
      Second_Interrupt = 1;
      break;
  }
  AI = 0;                          // Clear AI before returning
}


void main(void)  {
  CKCON = 0;                          // 0 MOVX cycle stretch

  // Setup Serial Interface
  T2CON   = 0x34;                     // Use Timer 2 as baudrate generator  */
  RCAP2H  = (T2RELOAD >> 8);          // baudrate reload factor
  RCAP2L  = T2RELOAD;

  SCON0   = 0x50;                     // enable serial uart & receiver
  PCON   |= 0x80;                     // double baudrate for UART0
  P3DDRL &= 0xF0;                     // set port pins of UART to input/strong drive output
  P3DDRL |= 0x07;                     // set port pins of UART to input/strong drive output


// The following settings are important for ISD51 (enable flash programming, disable watchdog)
  USEC   = ((XTAL+500000)/1000000)-1; // USEC timer factor
  ONEMS  = (XTAL/1000)-1;             // (MSECH+MSCL) MS Timer counting at 1.0ms

  HMSEC  = 100-1;                     // Hundred MS Timer to 100.0ms
  SECINT = (10-1) | 0x80;             // SECINT= 10 * HMS Timer Rate = 1 sec
                                      // '0x80' will set the MSB for write immediate
  MSINT  = (10-1) | 0x80;             // MSINT = 10ms for Tone period time base

  FTCON  = 0xA5;                      // setup flash programming times

  PDCON  = 0x14;                      // ON -> ADC-Vref, SPI Systimers. OFF -> PWM, Watchdog
  EA     = 1;                         // Enable global interrupt flag

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

  ADCON2 = DECIMATION & 0xFF;       // LSB of decimation
  ADCON3 =(DECIMATION>>8) & 0x07;   // MSB of decimation
  ADCON1 = 0x01;                    // bipolar, auto, self calibration (offset, gain)

  ADMUX = 0x01;                     // AINP = AIN0, AINN = AIN1
  AIE    = 0xA0;                    // Enable the A/D Interrupt
  EAI    = 1;                       // Enable Auxiliary interrupts

  printf("\nInput -2.5V to +2.5V on AIN0-AIN1 channel pair\n\n");

  while (1)  {                      // Repeat Output Forever
    while (!Second_Interrupt)  {    // Wait for Second Interrupt
#ifndef ISD51
      PCON |= 1;                    // Put into Idle Mode
#endif
    }
    Second_Interrupt = 0;
    printf ("%+7.5f Volts\r", res.l * VBIT);
  }

}




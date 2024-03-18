/* FLASH.C - LED Flasher for the Keil MCB251 Evaluation Board with 80C51 device*/
                  

#include <REG390.H>
#include <stdio.h>

void main (void)  {

#ifndef MONITOR
//  init serial interface 19200 baud @ 40MHz
    PCON  |= 0x80;
	SCON0  = 0x50;		         
    TMOD  |= 0x21;           
    TH1    = 0xF8;   
    CKCON |= 0x10;
    TCON   = 0x50;              
    TI     = 1;    
    printf("Serial Interface initiated ...");
#endif

#ifdef MONITOR
  printf("Serial Interface already initiated by monitor");
#endif
  
  while (1) {                         /* Loop forever */
    P1 ^= 0x01;     		    /* Toggle P1.0 each time we print */
    printf ("Hello World\n");   /* Print "Hello World" */
  }
}

/************************************************************************/
/*                                                                      */
/* TITLE  Debug Program                                                 */
/*                                                                      */
/* 1.     Functional Description.                                       */
/*        LED Flasher for Phytecs Rapid Development Kits                */
/*        example code for debug section in the quickstart manual.      */
/*                                                                      */
/* 2.     Modification History.                                         */
/*        H. Klaholz    02/04/02       #1.000, new                      */
/*                                                                      */
/* 3.     NOTICE: Copyright (C) 2001 PHYTEC Technologie Holding AG      */
/*                                                                      */
/* 4.     Build Environment.                                            */
/*        Keil Software Development Tools for 8051, C51, version 6.2x   */
/*                                                                      */
/************************************************************************/

#include <reg390.h>                  /* include DS80C390 header file    */
#include <stdio.h>

/* variables used by Debug example                                      */

unsigned char blink;
unsigned int xdata rhythm[]={60000,40000,20000,10000,8000,4000};

char code reserve [5] _at_ 0x23; //serial interrupt reserved for monitor

/********************** Function LED ************************************/
void led (unsigned char state)  
{
   if(state)                       
     {
     P3_4 = 0;                      /* P3_4 = 0  =>  LED D3 = ON       */
     }  
   else                                
     {
     P3_4 = 1;                      /* P3_4 = 1  =>  LED D3 = OFF      */
     }                               
}

/******************** Function Wait *************************************/
void wait (unsigned int delay)  
{      
   unsigned int i;

   for (i=0; i<(delay * 2); i++) 
   {                                /* wait for delay counts            */
    ;                               /* do nothing                       */
   }                                  
}

/******************* Programm starts here *******************************/
void main (void)  
{

EA = 1;
blink=0;

 while (1)                          /* a cpu never sleeps ;-)            */
 { 
   wait(rhythm[blink]);
   
   led(1);/* turn LED on and Port P3.4 off */

   wait(rhythm[blink]);
    
//   printf("TESTSTRING");

   led(0);/* turn LED off and Port P3.4 on */
      
   blink++;

   if (blink > (sizeof(rhythm)/2)-1) blink =0;
  }
}


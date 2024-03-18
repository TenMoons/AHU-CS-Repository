/* MAIN.C - Test Application for the Atmel AT89C51SND1 Demoboard V2.x */

#include <AT8xC51SND1.H>
#include <stdio.h>

#ifdef MONITOR
char code reserve[3] _at_ 0x23;  				/* For the Serial Interrupt */
#endif

/* Function Prototypes and #Defines for LCD Display */
extern void    lcd_println (char Buffer[16], char);
extern void    lcd_init    (void);
extern void    lcd_clearln (char);

#define LCD_LINE0       (unsigned char)0x80      /* address LCD line 0 */
#define LCD_LINE1       (unsigned char)0xC0      /* address LCD line 1 */

/* Keeps the CPU busy for some time */
void idlecpu (unsigned int time)
{
  int ai;
  for (ai = 0; ai <= time; ai+=2) {
    ai=ai-1;				                     /* Do some stuff */
  }
}

/* Main Routine */
void main (void)
{
#ifndef MONITOR
  SCON  = 0x50;		        /* SCON: mode 1, 8-bit UART, enable rcvr      */
  TMOD |= 0x20;             /* TMOD: timer 1, mode 2, 8-bit reload        */
  TH1   = 0xF7;             /* TH1:  reload value for 1200 baud @ 16MHz   */
  TR1   = 1;                /* TR1:  timer 1 run                          */
  TI    = 1;                /* TI:   set TI to send first char of UART    */
#endif

  lcd_init ();              /* LCD initialization */


  lcd_println ("FlashMon51 Test", LCD_LINE0);
  lcd_println ("LCD LCD LCD LCD", LCD_LINE1);
  lcd_clearln ( LCD_LINE1 );
  
  
	
  while(1) {
    printf ("Serial-Test\n");
    idlecpu (300);
  }

}



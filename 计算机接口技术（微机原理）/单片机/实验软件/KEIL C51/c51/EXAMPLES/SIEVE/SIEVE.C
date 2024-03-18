/*------------------------------------------------------------------------------
SIEVE.C:  Eratosthenes Sieve Prime Number Program in C from Byte Jan 1983.
------------------------------------------------------------------------------*/

#include <intrins.h>
#include <stdio.h>
#include <reg51.h>

#define TRUE 1
#define FALSE 0
#define SIZE 8190

char xdata flags[SIZE+1];

/*------------------------------------------------
------------------------------------------------*/
void main (void)  {
    register int i,k;
    int prime,count,iter;

/*------------------------------------------------
Setup the serial port for 1200 baud at 16MHz.
------------------------------------------------*/
    SCON  = 0x50;                   	/* SCON: mode 1, 8-bit UART, enable rcvr    */
    TMOD |= 0x20;                   	/* TMOD: timer 1, mode 2, 8-bit reload      */
    TH1   = 221;                    	/* TH1:  reload value for 1200 baud @ 16MHz */
    TR1   = 1;                      	/* TR1:  timer 1 run                        */
    TI    = 1;                      	/* TI:   set TI to send first char of UART  */

/*------------------------------------------------
Th following code is an implementation of the 
Sieve of Eratosthenes.
------------------------------------------------*/
    printf("10 iterations\n");
    for (iter = 1; iter <= 10; iter++)	/* do program 10 times */
      {	
        P1 = iter;                      /* output iter on P1 */

	count = 0;			/* initialize prime counter */
	for (i = 0; i <= SIZE; i++)	/* set all flags true */
	  flags[i] = TRUE;
	for (i = 0; i <= SIZE; i++)
        {
	    if (flags[i])		/* found a prime */
	      {
		prime = i + i + 3;	/* twice index + 3 */
		for (k = i + prime; k <= SIZE; k += prime)
		  flags[k] = FALSE;	/* kill all multiples */
		count++;		/* primes found */
	      }
	    }
      }
    printf("%d primes.\n",count);	/* primes found in 10th pass */

    while (1);
  }



/* Blinky.C - LED Flasher for the Keil LPC900 EPM Emulator/Programmer Module */

#include <REG932.H>			// register definition

void delay (unsigned int cnt)
{
  while (--cnt);
}

void main()
{
  unsigned char i;

  P2M1 = 0;

  for(;;)
  { for (i = 0x01; i; i <<= 1)
    { P2 = i;				// simulate running lights
      delay (50000);
    }
    for (i = 0x80; i; i >>= 1)
    { P2 = i;
      delay (50000);
    }
  }
}



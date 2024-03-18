/* ---------------------------------------------------------------------------
 *  Copyright (C) 2003 Dallas Semiconductor Corporation, All Rights Reserved.
 * 
 *  Permission is hereby granted, free of charge, to any person obtaining a
 *  copy of this software and associated documentation files (the "Software"),
 *  to deal in the Software without restriction, including without limitation
 *  the rights to use, copy, modify, merge, publish, distribute, sublicense,
 *  and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included
 *  in all copies or substantial portions of the Software.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 *  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
 *  MERCHANTABILITY,  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 *  IN NO EVENT SHALL DALLAS SEMICONDUCTOR BE LIABLE FOR ANY CLAIM, DAMAGES
 *  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
 *  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
 *  OTHER DEALINGS IN THE SOFTWARE.
 * 
 *  Except as contained in this notice, the name of Dallas Semiconductor
 *  shall not be used except as stated in the Dallas Semiconductor
 *  Branding Policy.
 * ---------------------------------------------------------------------------
 */

/*
 * HelloWorld - template project for working in C with the DS80C400.
 *
 */
#include <stdio.h>
#include <REG400.H>


/*
 * Main entry point.  Initialize the ROM.
 */
void main()
{
	unsigned int data i, j;
    unsigned char data array[10];

    EA = 1;

    // let's print out a little version information...
    printf("DS80C400 Monitor Demonstration\r\n");

    i = 20;
    j = 100;
    array[5] = 1;

    printf("i = %d, j = %d\r\n", i, j);

    i = i +30;
    j = j / 2;
    array[6] = 2;

    printf("i = %d, j = %d\r\n", i, j);

    i--;
    j += 50;
    array[7] = 3;

    printf("i = %d, j = %d\r\n", i, j);

    i++;
    j--;
    array[8] = 10;

    printf("i = %d, j = %d\r\n", i, j);

    i = i & 0x5555;
    j = j ^ 0xffff;
    array[9] = 3;

    printf("i = %d, j = %d\r\n", i, j);

    while(1)
	{
	}
}


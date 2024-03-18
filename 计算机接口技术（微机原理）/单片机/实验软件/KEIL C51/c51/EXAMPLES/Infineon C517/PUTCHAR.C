/***********************************************************************/
/*  Copyright KEIL ELEKTRONIK GmbH 1993                                */
/***********************************************************************/
/*                                                                     */
/*  PUTCHAR.C:  This routine is the general character output of C-51.  */
/*                                                                     */
/*  To translate this file use C51 with the following invocation:      */
/*                                                                     */
/*     C51 PUTCHAR.C                                                   */
/*                                                                     */
/*  To link the modified PUTCHAR.OBJ file to your application use the  */
/*  following L51 invocation:                                          */
/*                                                                     */
/*     L51 <your object file list>, PUTCHAR.OBJ <controls>             */
/*                                                                     */
/***********************************************************************/

#include <reg517.h>

#define XON  0x11
#define XOFF 0x13

char putchar (char c)  {

  if (c == '\n')  {
    if (S1CON & 0x01)  {         /* RI*/
      if (S1BUF == XOFF)  {
        do  {
          S1CON &= 0xFE;         /* RI = 0 */
          while (!(S1CON & 0x01)); /* RI */
        }
        while (S1BUF != XON);
        S1CON &= 0xFE;           /* RI = 0 */
      }
    }
    while (!(S1CON & 0x02));     /* while (!TI); */
    S1CON &= 0xFD;               /* TI = 0 */
    S1BUF = 0x0d;                /* output CR  */
  }
  if (S1CON & 0x01)  {
    if (S1BUF == XOFF)  {
      do  {
        S1CON &= 0xFE;           /* RI = 0 */
        while (!(S1CON & 0x01)); /* while (!RI) */
      }
      while (S1BUF != XON);
      S1CON &= 0xFE;             /* RI = 0 */
    }
  }
  while (!(S1CON & 0x02));       /* while (!TI); */
  S1CON &= 0xFD;                 /* TI = 0 */
  return (S1BUF = c);
}

/***********************************************************************/
/*  Copyright KEIL ELEKTRONIK GmbH 1993                                */
/***********************************************************************/
/*                                                                     */
/*  PUTCHAR.C:  This routine is the general character input of C-51.   */
/*                                                                     */
/*  To translate this file use C51 with the following invocation:      */
/*                                                                     */
/*     C51 GETKEY.C                                                    */
/*                                                                     */
/*  To link the modified GETKEY.OBJ file to your application use the   */
/*  following L51 invocation:                                          */
/*                                                                     */
/*     L51 <your object file list>, GETKEY.OBJ <controls>              */
/*                                                                     */
/***********************************************************************/

#include <reg517.h>

#define CTRLQ  0x11

char _getkey ()  {
  char c;

  do {
    while (!(S1CON & 0x01));
    c = S1BUF;
    S1CON &= 0xFE;   /* RI = 0 */
  } while (c == CTRLQ);   // ignore Ctrl+Q for Monitor51
  return (c);
}

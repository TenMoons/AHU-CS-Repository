/***********************************************************************/
/*  This file is part of the C51 Compiler package                      */
/*  Copyright KEIL ELEKTRONIK GmbH 1993 - 2002                         */
/***********************************************************************/
/*                                                                     */
/*  GETKEY.C:  This routine is the general character input of C51.     */
/*  You may add this file to a uVision2 project.                       */
/*                                                                     */
/*  To translate this file use C51 with the following invocation:      */
/*     C51 GETKEY.C  <memory model>                                    */
/*                                                                     */
/*  To link the modified GETKEY.OBJ file to your application use the   */
/*  following Lx51 invocation:                                         */
/*     Lx51 <your object file list>, GETKEY.OBJ <controls>             */
/*                                                                     */
/***********************************************************************/

#include <reg51.h>

char _getkey ()  {
  char c;

  while (!RI);
  c = SBUF;
  RI = 0;
  return (c);
}

/* 
 *  Fixed Pool Management for Philips 80C51MX
 */

#include "record.h"

#pragma ASM

#if !defined (__C51__) && !defined (__CX51__)
  #include "record.h"
#endif

e_max   EQU 65535 / RecSize                 ; maximum records in a 64KB slot
s64     EQU RecNo / e_max                   ; number of complete 64KB slots
remain  EQU RecNo MOD e_max                 ; remaining rec. in last slot
segsiz  EQU (s64*65536) + (remain*RecSize)  ; size of fixed pool

POOLSEG   SEGMENT HDATA
          RSEG POOLSEG

POOLSTRT: DS      segsiz
          PUBLIC  POOLSTRT

#pragma ENDASM

/*
 * Record a Pointer to Record 'n' in Memory Pool
 */
RECORD far *pRecord (unsigned int n)  {
  void far *p;

  p = p;       // supress unused variable warning
  n = n;       // supress unused variable warning

#pragma ASM
EXTRN CODE (?C?UIDIV)

  MOV    R4,#HIGH e_max        ; seg  = n / e_max;
  MOV    R5,#LOW  e_max        ; slot = n % e_max;
  CALL   ?C?UIDIV              ; gives seg in R4, slot in R6|R7
  MOV    A,R7                  ; p = &POOLSTRT + (seg*65536) + slot
  ADD    A,#BYTE2 (POOLSTRT)
  MOV    R3,A
  MOV    A,R4
  MOV    R2,A
  MOV    A,R5
  MOV    R1,A
#pragma ENDASM

  return (p);
}

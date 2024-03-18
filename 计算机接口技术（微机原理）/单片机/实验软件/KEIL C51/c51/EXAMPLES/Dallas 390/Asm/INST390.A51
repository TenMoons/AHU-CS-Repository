$MOD_CONT  ; Contiguous 22-bit addressing mode

#include <REG390.H>

?ED?STACK  SEGMENT EDATA
  RSEG  ?ED?STACK
Stack_Area:	DS	100	; 100 Bytes

?FD?FAR_CONST SEGMENT HCONST

RSEG ?FD?FAR_CONST
my_const1:      DW      1,2,3,4,5,6,7,8,9,10    ; define content


?FD?FAR_DATA SEGMENT HDATA

RSEG ?FD?FAR_DATA
my_word1:       DSW     10      ; reserve words
my_word2:       DSW     10      


?PR?MYCODE SEGMENT ECODE INBLOCK
Public Reset, func1

                CSEG    AT 0
		DB	02H	; LJMP in Classic 8051 Mode
		DW	WORD0 Reset

                RSEG ?PR?MYCODE

Reset:          MOV     TA,#0xAA        ; Enable access to ACON
                MOV     TA,#0x55
                MOV     ACON,#00000110B ; Extended Stack, 22-bit contigous mode
                MOV     SP,#LOW Stack_Area
                MOV     ESP,#HIGH Stack_Area

Loop:           ANL     DPS,#0xFE       ; SEL DPTR[0]
                MOV     DPTR,#my_const1
                ORL     DPS,#0x01       ; SEL DPTR[1]
                MOV     DPTR,#my_word1
                MOV     R0,#10

                ACALL   move_const2xdata
                LCALL   func1
                AJMP    Loop

func1:          INC     ACC
                RET

move_const2xdata  PROC

                ANL     DPS,#0xFE
move_Loop:      CLR     A
                MOVC    A,@A+DPTR
                INC     DPTR
                INC     DPS
                MOVX    @DPTR,A
                INC     DPTR
                DEC     DPS
                DJNZ    R0,move_Loop
                RET
                ENDP

                END


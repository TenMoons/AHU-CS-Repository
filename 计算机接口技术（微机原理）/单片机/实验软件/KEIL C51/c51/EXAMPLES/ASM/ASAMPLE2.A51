NAME 	STRING_IO
;
EXTRN	BIT    (TXTBIT)
EXTRN	CODE   (PUTCHAR)
PUBLIC	PUT_CRLF, PUTSTRING

STRING_ROUTINES  SEGMENT  CODE

	RSEG  STRING_ROUTINES
; This routine outputs a CR and a LF
CR equ  0DH                ; carriage return
LF equ  0AH                ; line feed 

PUT_CRLF: 
	MOV   A,#CR
        CALL  PUTCHAR
        MOV   A,#LF
        CALL  PUTCHAR
        RET

; Routine outputs a null-terminated string whose
; address is given in DPTR. The string can be
; located in CODE or XDATA memory depending on
; the value of TXTBIT.

PUTSTRING:
; check TXTBIT
   	JB    TXTBIT,PS1
        CLR   A
        MOVC  A,@A+DPTR
        SJMP  PS2
PS1:    MOVX  A,@DPTR
PS2:    JZ    EXIT
        CALL  PUTCHAR
        INC   DPTR
        SJMP  PUTSTRING
EXIT:   RET

	END

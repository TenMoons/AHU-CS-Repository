NAME 	CHAR_IO
;
PUBLIC	PUTCHAR

CHAR_ROUTINES  SEGMENT  CODE
VAR2           SEGMENT  DATA

	RSEG  CHAR_ROUTINES

; This routine outputs a single character to console.
; The character is given in A.
PUTCHAR:
   	JNB  TI,$
   	CLR  TI
   	MOV  SBUF,A
   	RET


; only for demonstration
	RSEG  VAR2
DUMMY:	DS    40H


	END

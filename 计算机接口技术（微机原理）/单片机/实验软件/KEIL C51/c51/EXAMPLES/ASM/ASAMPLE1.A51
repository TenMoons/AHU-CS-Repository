NAME	SAMPLE

EXTRN 	CODE 	(PUT_CRLF, PUTSTRING)
PUBLIC  TXTBIT

PROG	SEGMENT	CODE
CONST	SEGMENT	CODE
VAR1	SEGMENT	DATA
BITVAR	SEGMENT	BIT
STACK	SEGMENT	IDATA

	RSEG  STACK
	DS    10H  ; 16 Bytes Stack

	CSEG  AT   0
	USING	0  ; Register-Bank 0
; Execution starts at address 0 on power-up.
	JMP   START

	RSEG  PROG
; first set Stack Pointer
START:	MOV   SP,#STACK-1

; Initialize serial interface
; Using TIMER 1 to Generate Baud Rates
; Oscillator frequency = 11.059 MHz
	MOV   TMOD,#00100000B		;C/T = 0, Mode = 2
	MOV   TH1,#0FDH
	SETB  TR1
	MOV   SCON,#01010010B

; clear TXTBIT to read form CODE-Memory
	CLR   TXTBIT

; This is the main program. It is a loop,
; which displays the a text on the console.
REPEAT:	
; type message 
	MOV   DPTR,#TXT
	CALL  PUTSTRING
	CALL  PUT_CRLF
; repeat
	SJMP  REPEAT
;
	RSEG  CONST
TXT: 	DB    'TEST PROGRAM',00H

; only for demonstration
	RSEG  VAR1
DUMMY:	DS    21H

; TXTBIT = 0 read text from CODE  Memory
; TXTBIT = 1 read text from XDATA Memory
	RSEG  BITVAR
TXTBIT:	DBIT  1

	END

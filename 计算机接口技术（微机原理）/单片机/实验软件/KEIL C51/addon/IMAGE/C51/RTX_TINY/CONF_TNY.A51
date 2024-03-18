$DEBUGPUBLICS
;------------------------------------------------------------------------------
;  This file is part of the 'RTX-51 tiny' Real-Time Operating System Package
;  Copyright KEIL ELEKTRONIK GmbH 1991
;------------------------------------------------------------------------------
;  CONF_TNY.A51:  This code allows the configuration of the
;                 'RTX-51 tiny' Real-Time Operating System
;
;  To translate this file use A51 with the following invocation:
;
;     A51 CONF_TNY.A51
;
;  To link the modified CONF_TNY.OBJ file to your application use the following
;  BL51 invocation:
;
;     BL51 <your object file list>, CONF_TNY.OBJ <controls>
;
;------------------------------------------------------------------------------
;
;  'RTX-51 tiny' Hardware-Timer
;  ============================
;
;  With the following EQU statements the initialization of the 'RTX-51 tiny'
;  Hardware-Timer can be defined ('RTX-51 tiny' uses the 8051 Timer 0 for 
;  controlling RTX-51 software timers).
;
;		; define the register bank used for the timer interrupt.
INT_REGBANK	EQU	1	; default is Registerbank 1
;
;		; define Hardware-Timer Overflow in 8051 machine cycles.
INT_CLOCK	EQU	10000	; default is 10000 cycles
;
;		; define Round-Robin Timeout in Hardware-Timer Ticks.
TIMESHARING	EQU	5	; default is 5 ticks.
;		; 
;		; note: Round-Robin can be disabled by using value 0.
;
;  Note:   Round-Robin Task Switching can be disabled by using '0' as
;          value for the TIMESHARING equate.
;------------------------------------------------------------------------------
;
;  'RTX-51 tiny' Stack Space
;  =========================
;
;  The following EQU statements defines the size of the internal RAM used
;  for stack area and the minimum free space on the stack.  A macro defines
;  the code executed when the stack space is exhausted.
;
;		; define the highest RAM address used for CPU stack
RAMTOP		EQU	0FFH	; default is address (256-1)
;
FREE_STACK	EQU	20	; default is 20 bytes free space on stack
;
STACK_ERROR	MACRO
		CLR	EA	; disable interrupts
		SJMP	$	; endless loop if stack space is exhausted
		ENDM
;
;------------------------------------------------------------------------------

		NAME	?RTX51_TINY_CONFIG

PUBLIC	?RTX_REGISTERBANK, ?RTX_TIMESHARING, ?RTX_RAMTOP, ?RTX_CLOCK
PUBLIC	?RTX_ROBINTIME, ?RTX_SAVEACC, ?RTX_SAVEPSW
PUBLIC	?RTX_FREESTACK, ?RTX_STACKERROR, ?RTX_CURRENTTASK 

?RTX_TIMESHARING  EQU	-TIMESHARING	
?RTX_RAMTOP	  EQU	RAMTOP
?RTX_FREESTACK    EQU	FREE_STACK
?RTX_CLOCK	  EQU	-INT_CLOCK
?RTX_REGISTERBANK EQU	INT_REGBANK * 8
		  DSEG	AT    ?RTX_REGISTERBANK
		  DS	2     ; temporary space
?RTX_SAVEACC:     DS	1
?RTX_SAVEPSW:     DS	1
?RTX_ROBINTIME:   DS	1
?RTX_CURRENTTASK: DS	1

?RTX?CODE         SEGMENT CODE
                  RSEG  ?RTX?CODE
?RTX_STACKERROR:  STACK_ERROR

		  END

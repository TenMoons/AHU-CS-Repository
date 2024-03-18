;------------------------------------------------------------------------------
;  This file is part of the 'RTX-51 tiny' Real-Time Operating System Package
;  Copyright KEIL ELEKTRONIK GmbH 1991 - 1994
;------------------------------------------------------------------------------
;
;  RTX51TNY.A51:  This module contains all RTX-51 TINY function calls.
;
;  RTX51 TINY VERSION 1.06
;
;------------------------------------------------------------------------------

NAME	?RTX51_TINY

PUBLIC	?RTX_TASKSP
PUBLIC	?RTX_TASKSTATUS
PUBLIC	?RTX_TASKENTRY

PUBLIC  ?RTX_NEXTTASK
PUBLIC	?RTX_NEXTID
PUBLIC	?RTX_TASKIDX
PUBLIC  ?RTX_TS_REQ
PUBLIC  ?RTX_TS_DELAY
PUBLIC  ?RTX_TASKSWITCHING

PUBLIC	_OS_CREATE_TASK
PUBLIC  _OS_WAIT
PUBLIC  _OS_WAIT1
PUBLIC  _OS_WAIT2
PUBLIC  _OS_SEND_SIGNAL
PUBLIC  _ISR_SEND_SIGNAL
PUBLIC  _OS_CLEAR_SIGNAL
PUBLIC  _OS_DELETE_TASK
PUBLIC  OS_RUNNING_TASK_ID

EXTRN	NUMBER (?RTX_MAXTASKN)		; max Task Number
EXTRN	NUMBER (?RTX_TIMESHARING)	; Round Robin Enable & Time Out
EXTRN   NUMBER (?RTX_REGISTERBANK)
EXTRN   NUMBER (?RTX_RAMTOP)
EXTRN   NUMBER (?RTX_CLOCK)
EXTRN	NUMBER (?RTX_FREESTACK)

EXTRN   CODE   (?RTX_STACKERROR)

EXTRN	DATA   (?RTX_CURRENTTASK)
EXTRN   DATA   (?RTX_ROBINTIME)
EXTRN	DATA   (?RTX_SAVEACC)
EXTRN	DATA   (?RTX_SAVEPSW)

saveacc		EQU	R2
savepsw		EQU	R3
robintime	EQU	R4
currenttask	EQU	R5


?RTX?TASKENT?S	  SEGMENT  CODE     	; Segment with Task Entries
RSEG	?RTX?TASKENT?S
?RTX_TASKENTRY:	DS	2

?RTX?TASKSP?S     SEGMENT  IDATA
		RSEG	?RTX?TASKSP?S
?RTX_TASKSP:	DS	1		; Reserve Space for Stack Pointer

?RTX?TASKSTATE?S  SEGMENT  IDATA
		RSEG	?RTX?TASKSTATE?S
?RTX_TASKSTATUS:
TimerVal:	DS	1		; Reserve Space for Timer
TaskState:	DS	1
; Bits in TaskState:
;  TaskState.0  = Wait for Signal
;  TaskState.1  = Wait for TimeOut
;  TaskState.2  = Signal Flag
;  TaskState.3  = TimeOut Flag
;  TaskState.4  = Task Ready (Wait for Running)
;  TaskState.5  = Task Active (enabled with os_create)
;  TaskState.6  = Round Robin Time Out

K_SIG	        EQU	1
K_TMO	        EQU	2
SIG_EVENT	EQU	4
TMO_EVENT	EQU	8
K_READY		EQU	16
K_ACTIVE	EQU	32
K_ROBIN		EQU	64
K_IVL           EQU     128

B_WAITSIG	EQU	0
B_WAITTIM	EQU	1
B_SIGNAL	EQU	2
B_TIMEOUT	EQU	3
B_READY		EQU	4
B_ACTIVE	EQU	5
B_ROBIN		EQU	6
B_INTERVAL	EQU	7

?RTX?BITS	SEGMENT	BIT

		RSEG	?RTX?BITS
?RTX_TS_DELAY:	DBIT	1
?RTX_TS_REQ:	DBIT	1

		CSEG	AT	0BH
		JMP	TIMERINT

?RTX?CODE	SEGMENT	CODE

		RSEG	?RTX?CODE

RETINT:		RETI

NoTimeSharing:	MOV	A,saveacc
		MOV	PSW,savepsw
		RET	

TIMERINT:	CALL	RETINT		; Enable Interrupts again.
		MOV	?RTX_SAVEPSW,PSW
		MOV	PSW,#?RTX_REGISTERBANK
		MOV	saveacc,A
; Update Timer
		CLR	TR0
		MOV	A,TL0
		ADD	A,#LOW (?RTX_CLOCK + 7)
		MOV	TL0,A
		MOV	A,TH0
		ADDC	A,#HIGH (?RTX_CLOCK + 7)
		MOV	TH0,A
		SETB	TR0
; Check Stack
		MOV	A,currenttask
		ADD	A,#?RTX?TASKSP?S+1
		MOV	R0,A
		MOV	A,@R0
		CJNE	currenttask,#?RTX_MAXTASKN,checkstack
		MOV	A,#?RTX_RAMTOP
checkstack:	CLR	C
		SUBB	A,SP
		CJNE	A,#?RTX_FREESTACK,$+3
		JNC	checkstack2
		LJMP	?RTX_STACKERROR
checkstack2:

; Update & Check Task Timers
		MOV	R1,#?RTX_MAXTASKN+1
		MOV	R0,#?RTX?TASKSTATE?S
TIMERLOOP:	DEC	@R0
		MOV	A,@R0
		CLR	F0
		JNZ	NoTimeOut
		SETB	F0
NoTimeOut:	INC	R0		; advance to TaskState
		CLR	EA
		MOV	A,@R0
		JNB	ACC.B_WAITTIM,NoWaitTimeout
		JNB	F0,NoWaitTimeOut
		ORL	A,#(K_READY+TMO_EVENT)
		MOV	@R0,A
NoWaitTimeout:	SETB	EA
		INC	R0
		DJNZ	R1,TIMERLOOP

; Check Round Robin Timeout

		MOV	A,#LOW ?RTX_TIMESHARING
		JZ	NoTimeSharing
		MOV	A,currenttask
		RL	A
		ADD	A,#?RTX?TASKSTATE?S
		MOV	R0,A
		MOV	A,@R0
		CJNE	A,?RTX_ROBINTIME,NoTimeSharing
		MOV	A,saveacc
		MOV	PSW,savepsw
		JNB	?RTX_TS_DELAY,?RTX_TASKSWITCHING
ts_request:	SETB	?RTX_TS_REQ
		RET

		USING	0		; Registerbank 0 for following code
?RTX_TASKSWITCHING:
		PUSH	ACC
		PUSH	PSW
		PUSH	B
		PUSH	DPH
		PUSH	DPL
		PUSH	AR0
		PUSH	AR1
		PUSH	AR2
		PUSH	AR3
		PUSH	AR4
		PUSH	AR5
		PUSH	AR6
		PUSH	AR7
		MOV	A,?RTX_CURRENTTASK
		RL	A
		ADD	A,#?RTX?TASKSTATE?S+1
		MOV	R0,A
		CLR	EA
		MOV	A,@R0
		ORL	A,#K_ROBIN
		MOV	@R0,A
		SETB	EA

; Perform a Task-Switch
SwitchNow:	
;  switchnow ()  {
;      uchar i;
;      uchar limit;

;---- Variable 'current' assigned to Register 'R6' ----
;---- Variable 'next' assigned to Register 'R7' ----
;---- Variable 'i' assigned to Register 'R0' ----
;---- Variable 'limit' assigned to Register 'R5' ----
;
;      next = current;
		SETB	?RTX_TS_DELAY		; Delay Task Switching
		MOV	A,?RTX_CURRENTTASK
		MOV	R7,A
;      while (1)  {
		RL	A
		ADD	A,#?RTX?TASKSTATE?S+1
		MOV	R0,A
?C0001:
;        if (++next == MAXTASKN+1)  next = 0;
		INC     R7
		INC	R0
		INC	R0
		CJNE    R7,#?RTX_MAXTASKN+1,?C0003
		MOV	R7,#0
		MOV	R0,#?RTX?TASKSTATE?S+1
?C0003:
;        if (STATE[next].st & K_READY)  break;
		MOV     A,@R0
		JNB     ACC.B_READY,?C0001
;      }
;

?RTX_NEXTID	EQU	AR7
?RTX_NEXTTASK:	NOP		; for Debugging

;      while (current < next)  {
?C0005:
		MOV     A,?RTX_CURRENTTASK
		CLR     C
		SUBB    A,R7
		JNC     ?C0011

;        current++;
		INC	?RTX_CURRENTTASK
;        i = STKP[current];
		MOV     A,#?RTX?TASKSP?S
		ADD     A,?RTX_CURRENTTASK
		MOV     R0,A
		MOV     A,@R0
		MOV     R5,A
;        STKP[current] = SP;
		MOV     @R0,SP
;        if (current == MAXTASKN) limit = RAMTOP;
		INC	R0
		MOV	A,@R0
		MOV	R6,?RTX_CURRENTTASK
		CJNE	R6,#?RTX_MAXTASKN,?C0007
		MOV	A,#?RTX_RAMTOP
?C0007:
		XCH	A,R5
		MOV	R0,A
;        else                       limit = STKP[current+1];
;
;        while (i != limit)  {
?C0009:
		MOV     A,R0
		XRL     A,R5
		JZ      ?C0005
;          SP++;
;          i++;
;          STACK[SP] = STACK[i];
		INC	R0
		MOV	A,@R0
		PUSH	ACC
		SJMP    ?C0009
;        }
;      }
?C0011:
;
;      while (current > next)  {
		MOV     A,?RTX_CURRENTTASK
		SETB    C
		SUBB    A,R7
		JC      ?C0012
	
		MOV	A,?RTX_CURRENTTASK
		ADD	A,#?RTX?TASKSP?S+1
		MOV	R0,A
		MOV	A,@R0
;        if (current == (MAXTASKN)) i = RAMTOP;
;        else                       i = STKP[current+1];
		MOV	R6,?RTX_CURRENTTASK
		CJNE	R6,#?RTX_MAXTASKN,?C0013
		MOV	A,#?RTX_RAMTOP
?C0013:
		MOV	R5,A
;        limit = STKP[current];
		DEC	R0
		MOV	A,@R0
		XCH	A,R5
		MOV	R0,A
;
;        while (SP != limit)  {
?C0015:
		MOV     A,SP
		XRL     A,R5
		JZ      ?C0016
;          STACK[i] = STACK[SP];
;          i--;
;          SP--;
		POP	ACC
		MOV	@R0,A
		DEC	R0

		SJMP    ?C0015
?C0016:
;        }
;        STKP[current] = i;
		MOV	A,?RTX_CURRENTTASK
		ADD	A,#?RTX?TASKSP?S
		XCH	A,R0
		MOV	@R0,A
;        current--;
		DEC	?RTX_CURRENTTASK
		SJMP	?C0011
?C0012:
;      }

;      RoundRobinTime = STATE[current].timer + ?RTX_TIMESHARING
		MOV	A,?RTX_CURRENTTASK
		RL	A
		ADD	A,#?RTX?TASKSTATE?S
		MOV	R0,A
		MOV	A,@R0
		ADD	A,#LOW ?RTX_TIMESHARING
		MOV	?RTX_ROBINTIME,A
		INC	R0
;       if (STATE[current].st & K_ROBIN)  goto RobinOn;
		CLR	EA
		MOV	A,@R0
		JBC	ACC.B_ROBIN,RobinOn
;       if ((STATE[current].st & K_SIG) && (STATE[current].st & SIG_EVENT)
;          goto SignalOn;
		JNB	ACC.B_WAITSIG,SignalOff
		JB	ACC.B_SIGNAL,SignalOn
SignalOff:
;       if ((STATE[current].st & K_TMO) && (STATE[current].st & TMO_EVENT)
;          goto TimeOutOn;
		JNB	ACC.B_WAITTIM,NoSwitch
		JNB	ACC.B_TIMEOUT,NoSwitch
TimeOutOn:	
		ANL	A,#0F4H
		MOV	@R0,A
		SETB	EA
		MOV	R7,#TMO_EVENT
		CLR	?RTX_TS_DELAY
		CLR	?RTX_TS_REQ
		RET
		
NoSwitch:	SETB	EA
		MOV	R7,#0
		CLR	?RTX_TS_DELAY
		CLR	?RTX_TS_REQ
		RET

SignalOn:	ANL	A,#0F0H
		MOV	@R0,A
		SETB	EA
		MOV	R7,#SIG_EVENT
		CLR	?RTX_TS_DELAY
		CLR	?RTX_TS_REQ
		RET		; Start Task

RobinOn:	MOV	@R0,A
		SETB	EA
		POP	AR7
		POP	AR6
		POP	AR5
		POP	AR4
		POP	AR3
		POP	AR2
		POP	AR1
		POP	AR0
		POP	DPL
		POP	DPH
		POP	B
		POP	PSW
		POP	ACC
		CLR	?RTX_TS_DELAY
		CLR	?RTX_TS_REQ
		RET			; Restart Task
;    }
;  }


;  uchar os_create (uchar no)  {
;    uchar i;
;    uchar p1, p2;
;---- Variable 'p1'  assigned to Register 'R1' ----
;---- Variable 'p2'  assigned to Register 'R5' ----
;---- Variable 'no'  assigned to Register 'R7' ----
;---- Variable 'i'   assigned to Register 'R6' ----
;
;    if (no > MAXTASKN)  return (0xff);
_OS_create_task:
		MOV     A,R7
		SETB    C
		SUBB    A,#?RTX_MAXTASKN
		JC      ?C0010
?C0012_:	MOV     R7,#0FFH
		RET     
?C0010:
;    if (STATE[no].st & K_ACTIVE)  return (0xff);
		MOV	A,#?RTX?TASKSTATE?S+1
		ADD	A,R7
		ADD	A,R7
		MOV     R0,A
		MOV     A,@R0
		JB      ACC.B_ACTIVE,?C0012_
;    STATE[no].st |= K_ACTIVE + K_READY;
		CLR	EA
		MOV	A,@R0
		ORL	A,#K_ACTIVE+K_READY
		MOV     @R0,A
		SETB	EA
;
;    i = current;
		MOV	R6,?RTX_CURRENTTASK
?C0013_:
;    while (i < no)  {
		MOV     A,R6
		CLR	C
		SUBB    A,R7
		JNC     ?C0014
;      i++;
		INC	R6
;      p1 = STKP[i];
		MOV     A,#?RTX?TASKSP?S
		ADD     A,R6
		MOV     R0,A
		MOV     A,@R0
		MOV     R1,A
;      p2 = i == MAXTASKN ? RAMTOP : STKP[i+1];
		INC	R0
		MOV	A,@R0
		DEC	R0
		CJNE    R6,#?RTX_MAXTASKN,?C0015_
		MOV	A,#?RTX_RAMTOP
?C0015_:
		MOV	R5,A

?C0017:
                MOV     A,R5
                XRL     A,R1
                JZ      ?C0018
;      while (p1 != p2)  {
;        p1++;
;        DBYTE[p1-2] = DBYTE[p1];
;      }
		INC	R1
		MOV     A,@R1
		DEC	R1
		DEC	R1
		MOV	@R1,A
		INC	R1
		INC	R1
		SJMP	?C0017
?C0018:
;      STKP[i] -= 2;
		DEC     @R0
		DEC     @R0
;    }    
		SJMP    ?C0013_
?C0014:
;    if (i > no)  SP += 2;
		MOV     A,R6
		SETB    C
		SUBB    A,R7
		JC      ?C0020
		INC     SP
		INC     SP
?C0020:
;    while (i > no)  {
		MOV     A,R6
		SETB    C
		SUBB    A,R7
		JC      ?C0021
;      p1 = i == current ? SP : STKP[i+1];
		MOV     A,#?RTX?TASKSP?S
		ADD     A,R6
		MOV     R0,A
		INC	R0
		MOV     A,@R0
		MOV     R1,A
		MOV     A,R6
		CJNE    A,?RTX_CURRENTTASK,?C0022
		MOV	R1,SP
?C0022:
;      STKP[i] += 2;
		DEC	R0
		INC	@R0
		INC	@R0
;      p2 = STKP[i];
		MOV	A,@R0
		MOV	R5,A
?C0024:
;      while (p1 != p2)  {
		MOV     A,R5
		XRL     A,R1
		JZ      ?C0025
;        DBYTE[p1] = DBYTE[p1-2];
		DEC	R1
		DEC	R1
		MOV	A,@R1
		INC	R1
		INC	R1
		MOV	@R1,A
;        p1--;
		DEC	R1
;      }
		SJMP    ?C0024
?C0025:
;      i--;
		DEC	R6
;    }
		SJMP	?C0020

?C0021:
;
;    DWORD[STKP[no]] = ENTRY[no];
		MOV	A,R7
		ADD     A,#?RTX?TASKSP?S
		MOV	R0,A
		MOV	A,@R0
		INC	A
		MOV	R0,A
		MOV	A,R7
		ADD	A,R7
		INC	A
		MOV	DPTR,#?RTX?TASKENT?S
		MOVC	A,@A+DPTR
		MOV	@R0,A
		INC	R0
		MOV	A,R7
		ADD	A,R7
		MOVC	A,@A+DPTR
		MOV	@R0,A
;    return (0);
		MOV	R7,#0
;  }

		RET

;  os_wait (uchar typ, uchar timeout)  {
_os_wait:
_OS_wait1:			; entry point for 1 parameter
_OS_wait2:			; entry point for 2 parameters
;    uchar st = 0;
;---- Variable 'typ' assigned to Register 'R7' ----
;---- Variable 'timeout' assigned to Register 'R5' ----
;---- Variable 'st' assigned to Register 'R6' ----
		MOV	R6,#0FFH
;
;
		MOV	A,?RTX_CURRENTTASK
		RL	A
		ADD	A,#?RTX?TASKSTATE?S+1
		MOV	R0,A
;    if (typ == 0)  goto no_wait;
		MOV     A,R7
		JZ	no_wait
;
;    if (typ & K_IVL)  {
		CLR	ET0
		JNB     ACC.B_INTERVAL,??C0005
		DEC	R0
;      STATE[current].timer += timeout;
		MOV	A,@R0
		JZ	??C0006_
		ADD	A,R5
		MOV	@R0,A
;      if (!CY)  {
		JZ	??C0006a		; zero means no wait
		JC	??C0006
;        st = TMO_EVENT;
??C0006a:	MOV	R6,#TMO_EVENT
;        goto no_wait;
		INC	R0
		SJMP	no_wait;
;      }
??C0006_:
		MOV	A,R5
		MOV	@R0,A
??C0006:
		INC	R0
;      STATE[current].st |= K_TMO;
		CLR	EA
		MOV     A,@R0
		ORL	A,#K_TMO
		MOV     @R0,A
		SETB	EA
;    }  
??C0005:
;    if (typ & K_TMO)  {
		MOV     A,R7
		JNB     ACC.B_WAITTIM,??C0007
;      if (timeout == 0)  {
		MOV     A,R5
		JNZ     ??C0008
;        st = TMO_EVENT;
		MOV	R6,#TMO_EVENT
;        goto no_wait;
		SJMP	no_wait
;      }
??C0008:
		DEC	R0
;      STATE[current].timer = timeout;
		MOV	@R0,A
;      STATE[current].st |= K_TMO;
		INC	R0
		CLR	EA
		MOV	A,@R0
		ORL	A,#K_TMO
		MOV     @R0,A
		SETB	EA
;    }
??C0007:
;    if (typ & K_SIG)  {
		MOV     A,R7
		JNB     ACC.B_WAITSIG,??C0003
;      if (STATE[current].st & SIG_EVENT)  {
		CLR	EA
		MOV	A,@R0
		JNB     ACC.B_SIGNAL,??C0004
		SETB	EA
;        st = SIG_EVENT;
		MOV     R6,#SIG_EVENT
;        goto no_wait;
		SJMP	no_wait
;      }
??C0004:
;      STATE[current].st |= K_SIG;
		ORL	A,#K_SIG
		ANL	A,#NOT K_READY
		MOV	@R0,A
		SETB	EA
		SJMP	??C0003A
;    }
??C0003:
;    switchnow ();            /* Select Another Task */
		CLR	EA
		MOV	A,@R0
		ANL	A,#NOT K_READY
		MOV     @R0,A
		SETB	EA
??C0003A:	SETB	ET0
		JMP	SwitchNow

no_wait:
;    STATE[current].st &= ~ (st | K_SIG | K_TMO);
;    return (st);
		MOV	A,R6
		MOV	R7,A
		ORL	A,#K_SIG + K_TMO
		CPL	A
		CLR	EA
		ANL	A,@R0
		MOV	@R0,A
		SETB	EA
		SETB	ET0
		RET
;  }



_OS_send_signal:
_isr_send_signal:
;  os_send_signal (uchar taskid)  {
;    uchar data *p;
;---- Variable 'taskid' assigned to Register 'R7' ----
;---- Variable 'p' assigned to Register 'R0' ----
;    if (no > MAXTASKN)  return (0xff);
		MOV     A,R7
		SETB    C
		SUBB    A,#?RTX_MAXTASKN
		JC      ??C0010
		MOV     R7,#0FFH
		RET     
??C0010:

;    p = &STATE[taskid].st;
		MOV     A,R7
		RL	A
		ADD	A,#?RTX?TASKSTATE?S+1
		MOV	R0,A
		CLR	EA
		MOV	A,@R0
;
;    if (*p & K_ACTIVE)  {
		JNB     ACC.B_ACTIVE,?C0026
;      if (*p & K_SIG)  *p |= K_READY;
		JNB     ACC.B_WAITSIG,?C0026
		SETB	ACC.B_READY
;    }
?C0026:
;    *p |= SIG_EVENT;
		SETB	ACC.B_SIGNAL
		XCH	A,@R0
		SETB	EA
		JB	ACC.B_SIGNAL,SIG_PENDING
		MOV	R7,#0
		RET

SIG_PENDING:	MOV	R7,#1
		RET
;  }

_OS_clear_signal:
;  os_clear_signal (uchar taskid)  {
;    uchar data *p;
;---- Variable 'taskid' assigned to Register 'R7' ----
;---- Variable 'p' assigned to Register 'R0' ----
;    if (no > MAXTASKN)  return (0xff);
		MOV     A,R7
		SETB    C
		SUBB    A,#?RTX_MAXTASKN
		JC      _??C0010
		MOV     R7,#0FFH
		RET     
_??C0010:

;    p = &STATE[taskid].st;
		MOV     A,R7
		RL	A
		ADD	A,#?RTX?TASKSTATE?S+1
		MOV	R0,A
		CLR	EA
		MOV	A,@R0
;    *p &= SIG_EVENT;
		CLR	ACC.B_SIGNAL
		XCH	A,@R0
		SETB	EA
		JB	ACC.B_SIGNAL,_SIG_PENDING
		MOV	R7,#0
		RET

_SIG_PENDING:	MOV	R7,#1
		RET
;  }

; uchar os_delete (uchar no)  {
;   uchar i;
;   uchar last, first, check;
;
_OS_delete_task:
;---- Variable 'first' assigned to Register 'R1' ----
;---- Variable 'last' assigned to Register 'R5' ----
;---- Variable 'check' assigned to Register 'R4' ----
;---- Variable 'no' assigned to Register 'R7' ----
; if (no > MAXTASKN)  return (0xff);
		MOV     A,R7
		SETB    C
		SUBB    A,#?RTX_MAXTASKN
		JC      ?C0030
?C0032:		MOV     R7,#0FFH
		RET     
?C0030:
; if (!(STATE[no].st & K_ACTIVE))  return (0xff);

		MOV     A,R7
		RL	A
		ADD     A,#?RTX_TASKSTATUS+1
		MOV     R0,A
		MOV     A,@R0
		JNB     ACC.B_ACTIVE,?C0032
; STATE[no].st &= ~(K_ACTIVE | K_READY | K_SIG | K_TMO | K_ROBIN);
		CLR	EA
		MOV	A,@R0
		ANL     A,#NOT (K_ACTIVE+K_READY+K_SIG+K_TMO+K_ROBIN)
		MOV     @R0,A
		SETB	EA
; if (current == no)  {
		MOV     A,?RTX_CURRENTTASK
		CJNE    A,AR7,?C0033
;   SP = STKP[no];
		MOV     A,#?RTX_TASKSP
		ADD     A,R7
		MOV     R0,A
		MOV     A,@R0
		MOV     SP,A
;   switchnow ();
		LJMP	switchnow
; }

?C0033:
; if (current < no)  {
		JNC     ?C0034
;   last  = (no == MAXTASKN) ? STACKTOP : STKP[no+1];
		MOV     A,#?RTX_TASKSP+1
		ADD     A,R7
		MOV     R0,A
		MOV     A,@R0
		CJNE    R7,#?RTX_MAXTASKN,?C0035
		MOV     A,#?RTX_RAMTOP
?C0035:
		MOV     R5,A
;   first = STKP[no];
		DEC	R0
		MOV     A,@R0
		MOV     R1,A
?C0039:
;   do  {
;     check = STKP[no];
		MOV     A,#?RTX_TASKSP
		ADD     A,R7
		MOV     R0,A
		MOV	R3,A		; save @STKP
		MOV     A,@R0
		MOV     R4,A
;     while (first != check)  {
?C0040:
		MOV     A,R1
		XRL     A,R4
		JZ      ?C0037
;       DBYTE[last] = DBYTE[first];
                                         ; SOURCE LINE # 186
		MOV	R0,AR5
		MOV     A,@R1
		MOV     @R0,A
;       last--;
		DEC     R5
;       first--;
		DEC     R1
;     }
		SJMP    ?C0040
?C0037:
;     STKP[no] = last;
		MOV	R0,AR3		; restore @STKP
		MOV     @R0,AR5
;     no--;
		DEC     R7
;   }  while (current != no);
		MOV     A,?RTX_CURRENTTASK
		CJNE    A,AR7,?C0039
;   return (0);
                MOV	R7,#0
		RET     
; }
?C0034:
; if (current > no)  {
;   last  = STKP[no+1];
		MOV     A,#?RTX_TASKSP+1
		ADD     A,R7
		MOV     R0,A
		MOV     A,@R0
		MOV     R5,A
;   first = STKP[no];
		DEC	R0
		MOV	AR1,@R0
?C0045:
;   do  {
;     no++;
		INC     R7
;     STKP[no] = first;
		MOV     A,#?RTX_TASKSP
		ADD     A,R7
		MOV	R0,A
		MOV     @R0,AR1
;     check = (no == current) ? SP : STKP[no+1];
		INC	R0
		MOV	AR4,@R0
		MOV     A,?RTX_CURRENTTASK
		CJNE	A,AR7,?C0046
		MOV	R4,SP
?C0046:
;     while (last != check)  {
		MOV     A,R5
		XRL     A,R4
		JZ      ?C0043
;       last++;
		INC     R5
;       first++;
		INC     R1
;       DBYTE[first] = DBYTE[last];
		MOV     R0,AR5
		MOV     A,@R0
		MOV     @R1,A
;     }
		SJMP    ?C0046
;   }  while (current != no);
?C0043:
		MOV     A,?RTX_CURRENTTASK
		CJNE	A,AR7,?C0045
;   SP = first;
		MOV     SP,R1
;   return (0);
		MOV     R7,#0
; }
;}
?C0031:
		RET     



; Start RTX-51 Tiny Kernal

EXTRN CODE (?C_STARTUP)
PUBLIC	MAIN

MAIN:		MOV	R0,#?RTX?TASKSP?S
		MOV	@R0,SP
		MOV	A,#?RTX_MAXTASKN
		JZ	main2
		MOV	R7,A
main1:		INC	R0
		MOV	@R0,#?RTX_RAMTOP
		DJNZ	R7,main1
main2:		MOV	R7,#?RTX_MAXTASKN+1
		CLR	A
		MOV	R0,#?RTX?TASKSTATE?S
main1x:		MOV	@R0,A
		INC	R0
		MOV	@R0,A
		INC	R0
		DJNZ	R7,main1x
		MOV	R0,#?RTX?TASKSTATE?S+1
		MOV	@R0,#K_ACTIVE+K_READY
		MOV	DPTR,#?RTX?TASKENT?S
		MOV	A,#1
		MOVC	A,@A+DPTR
		PUSH	ACC
		CLR	A
		MOVC	A,@A+DPTR
		PUSH	ACC
		MOV	?RTX_RobinTime,#LOW ?RTX_TIMESHARING
		ORL	TMOD,#01H	; Timer 0 Mode 1
		MOV	TL0,#LOW (?RTX_CLOCK)
		MOV	TH0,#HIGH (?RTX_CLOCK)
		SETB	TR0
		SETB	EA
		SETB	ET0
		RET		; Start Task 0


os_running_task_id:
		MOV	R7,?RTX_CURRENTTASK
		RET


?RTX_TASKIDX:	DB	?RTX_MAXTASKN		; for Debugging

		END

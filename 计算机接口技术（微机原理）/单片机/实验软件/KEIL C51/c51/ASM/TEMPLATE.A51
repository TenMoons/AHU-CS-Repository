;------------------------------------------------------------------------------
; Source code template for A251/A51 assembler modules.
; Copyright (c) 1995-2000 KEIL Software, Inc.
;------------------------------------------------------------------------------
$NOMOD51                ; disable predefined 8051 registers
#include <reg52.h>      // include CPU definition file (for example, 8052)

;------------------------------------------------------------------------------
; Change names in lowercase to suit your needs.
;
; This assembly template gives you an idea of how to use the A251/A51
; Assembler.  You are not required to build each module this way-this is only
; an example.
;
; All entries except the END statement at the End Of File are optional. 
;
; If you use this template, make sure you remove any unused segment declarations,
; as well as unused variable space and assembly instructions.
;
; This file cannot provide for every possible use of the A251/A51 Assembler.
; Refer to the A51/A251 User's Guide for more information.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; Module name (optional)
;------------------------------------------------------------------------------
NAME            module_name

;------------------------------------------------------------------------------
; Here, you may import symbols form other modules.
;------------------------------------------------------------------------------
EXTRN   CODE   (code_symbol)    ; May be a subroutine entry declared in
                                ; CODE segments or with CODE directive.

EXTRN   DATA   (data_symbol)    ; May be any symbol declared in DATA segments
                                ; segments or with DATA directive.

EXTRN   BIT    (bit_symbol)     ; May be any symbol declared in BIT segments
                                ; or with BIT directive.

EXTRN   XDATA  (xdata_symbol)   ; May be any symbol declared in XDATA segments
                                ; or with XDATA directive.

EXTRN   NUMBER (typeless_symbol); May be any symbol declared with EQU or SET
                                ; directive

;------------------------------------------------------------------------------
; You may include more than one symbol in an EXTRN statement.
;------------------------------------------------------------------------------
EXTRN   CODE (sub_routine1, sub_routine2), DATA (variable_1)

;------------------------------------------------------------------------------
; Force a page break in the listing file.
;------------------------------------------------------------------------------
$EJECT

;------------------------------------------------------------------------------
; Here, you may export symbols to other modules. 
;------------------------------------------------------------------------------
PUBLIC  data_variable
PUBLIC  code_entry              
PUBLIC  typeless_number
PUBLIC  xdata_variable
PUBLIC  bit_variable

;------------------------------------------------------------------------------
; You may include more than one symbol in a PUBLIC statement.
;------------------------------------------------------------------------------
PUBLIC  data_variable1, code_table, typeless_num1, xdata_variable1

;------------------------------------------------------------------------------
; Put the STACK segment in the main module.
;------------------------------------------------------------------------------
?STACK          SEGMENT IDATA           ; ?STACK goes into IDATA RAM.
                RSEG    ?STACK          ; switch to ?STACK segment.
                DS      5               ; reserve your stack space
                                        ; 5 bytes in this example.


$EJECT

;------------------------------------------------------------------------------
; Put segment and variable declarations here.
;------------------------------------------------------------------------------

;------------------------------------------------------------------------------
; DATA SEGMENT--Reserves space in DATA RAM--Delete this segment if not used.
;------------------------------------------------------------------------------
data_seg_name   SEGMENT DATA            ; segment for DATA RAM.
                RSEG    data_seg_name   ; switch to this data segment
data_variable:  DS      1               ; reserve 1 Bytes for data_variable
data_variable1: DS      2               ; reserve 2 Bytes for data_variable1

;------------------------------------------------------------------------------
; XDATA SEGMENT--Reserves space in XDATA RAM--Delete this segment if not used.
;------------------------------------------------------------------------------
xdata_seg_name  SEGMENT XDATA           ; segment for XDATA RAM
                RSEG    xdata_seg_name  ; switch to this xdata segment
xdata_variable: DS      1               ; reserve 1 Bytes for xdata_variable
xdata_array:    DS      500             ; reserve 500 Bytes for xdata_array

;------------------------------------------------------------------------------
; INPAGE XDATA SEGMENT--Reserves space in XDATA RAM page (page size: 256 Bytes)
; INPAGE segments are useful for @R0 addressing methodes.
; Delete this segment if not used.
;------------------------------------------------------------------------------
page_xdata_seg  SEGMENT XDATA INPAGE    ; INPAGE segment for XDATA RAM
                RSEG    xdata_seg_name  ; switch to this xdata segment
xdata_variable1:DS      1               ; reserve 1 Bytes for xdata_variable1

;------------------------------------------------------------------------------
; ABSOLUTE XDATA SEGMENT--Reserves space in XDATA RAM at absolute addresses.
; ABSOLUTE segments are useful for memory mapped I/O.
; Delete this segment if not used.
;------------------------------------------------------------------------------
                XSEG    AT 8000H        ; switch absolute XDATA segment @ 8000H
XIO:            DS      1               ; reserve 1 Bytes for XIO port
XCONFIG:        DS      1               ; reserve 1 Bytes for XCONFIG port

;------------------------------------------------------------------------------
; BIT SEGMENT--Reserves space in BIT RAM--Delete segment if not used.
;------------------------------------------------------------------------------
bit_seg_name    SEGMENT BIT             ; segment for BIT RAM.
                RSEG    bit_seg_name    ; switch to this bit segment
bit_variable:   DBIT    1               ; reserve 1 Bit for bit_variable
bit_variable1:  DBIT    4               ; reserve 4 Bits for bit_variable1

;------------------------------------------------------------------------------
; Add constant (typeless) numbers here.
;------------------------------------------------------------------------------
typeless_number EQU     0DH                     ; assign 0D hex
typeless_num1   EQU     typeless_number-8       ; evaluate typeless_num1

$EJECT

;------------------------------------------------------------------------------
; Provide an LJMP to start at the reset address (address 0) in the main module.
; You may use this style for interrupt service routines.
;------------------------------------------------------------------------------
                CSEG    AT      0       ; absolute Segment at Address 0
                LJMP    start           ; reset location (jump to start)

;------------------------------------------------------------------------------
; CODE SEGMENT--Reserves space in CODE ROM for assembler instructions.
;------------------------------------------------------------------------------
code_seg_name   SEGMENT CODE
        
                RSEG    code_seg_name   ; switch to this code segment

                USING   0               ; state register_bank used
                                        ; for the following program code.  

start:          MOV     SP,#?STACK-1    ; assign stack at beginning

;------------------------------------------------------------------------------
; Insert your assembly program here.  Note, the code below is non-functional.
;------------------------------------------------------------------------------
                ORL     IE,#82H         ; enable interrupt system (timer 0)
                SETB    TR0             ; enable timer 0
repeat_label:   MOV     A,data_symbol
                ADD     A,#typeless_symbol
                CALL    code_symbol
                MOV     DPTR,#xdata_symbol
                MOVX    A,@DPTR
                MOV     R1,A
                PUSH    AR1
                CALL    sub_routine1
                POP     AR1
                ADD     A,R1
                JMP     repeat_label

code_entry:     CALL    code_symbol
                RET

code_table:     DW      repeat_label
                DW      code_entry
                DB      typeless_number
                DB      0
$EJECT

;------------------------------------------------------------------------------
; To include an interrupt service routins, provide an LJMP to the ISR at the
; interrupt vector address.
;------------------------------------------------------------------------------
                CSEG    AT  0BH         ; 0BH is address for Timer 0 interrupt
                LJMP    timer0int

;------------------------------------------------------------------------------
; Give each interrupt function its own code segment.
;------------------------------------------------------------------------------
int0_code_seg   SEGMENT CODE            ; segment for interrupt function
                RSEG    int0_code_seg   ; switch to this code segment
                USING   1               ; register bank for interrupt routine

timer0int:      PUSH    PSW
                MOV     PSW,#08H        ; register bank 1
                PUSH    ACC
                MOV     R1,data_variable
                MOV     DPTR,#xdata_variable
                MOVX    A,@DPTR
                ADD     A,R1
                MOV     data_variable1,A
                CLR     A
                ADD     A,#0
                MOV     data_variable1+1,A
                POP     ACC
                POP     PSW
                RETI
                
;------------------------------------------------------------------------------
; The END directive is ALWAYS required.
;------------------------------------------------------------------------------
                END             ; End Of File



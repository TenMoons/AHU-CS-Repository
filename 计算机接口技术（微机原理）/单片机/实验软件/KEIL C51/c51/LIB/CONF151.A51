;------------------------------------------------------------------------------
;  This file is part of the C51 Compiler package
;  Copyright (c) 1996-2002 Keil Elektronik GmbH and Keil Software, Inc.
;------------------------------------------------------------------------------
;  CONF151.A51:  This code sets the configuration bytes for the Intel 151
;                Microcontroller Family
;
;  To translate this file use A51 with the following invocation:
;
;     A51 CONF151.A51
;
;  To link the CONF151.OBJ file to your application use the following
;  BL51 invocation:
;
;     BL51 CONF151.OBJ, <your object file list> <controls>
;
;------------------------------------------------------------------------------
;
;  151 Configuration Bytes Definition
;
; Wait State for off-chip CODE access (WSA1 & WSA0 Bits)
; WSA        Val  Description
; ---        ---  -----------
WSA  EQU 3  ; 3 = 0 wait state for off-chip code
;           ; 2 = extended to 1 wait state  for off-chip code
;           ; 1 = extended to 2 wait states for off-chip code
;           ; 0 = extended to 3 wait states for off-chip code
;
; Extend ALE pulse
; XALE       Val  Description
; ----       ---  -----------
XALE EQU 1  ; 1 = ALE pulse is one TOSC
;           ; 0 = ALE pulse is three TOSC, this adds one external wait state
;
; Page Mode Select
; PAGE       Val  Description
; ----       ---  -----------
PAGM EQU 1  ; 1 = Non-page Mode (A15:8 on P2, A7:0/D7:0 on P0, 8051 compatible)
;           ; 0 = Page Mode (A15:8/D7:0 on P2, A7:0 on P0)
;
; Wait State for XDATA access (WSB1 & WSB0 Bits)
; WSB        Val  Description
; ---        ---  -----------
WSB  EQU 3  ; 3 = 0 wait state for xdata
;           ; 2 = extended to 1 wait state  for xdata
;           ; 1 = extended to 2 wait states for xdata
;           ; 0 = extended to 3 wait states for xdata
;
; EPROM SIZE  Select the PROM size of your target system
; ----------
PROM_SIZE EQU 0FFFFH  ; 0FFFFH for 64KB EPROM or systems with code banking
;                     ; 07FFFH for 32KB EPROM
;                     ; 03FFFH for 16KB EPROM
;------------------------------------------------------------------------------

CONFIG0		EQU     (WSA*20H)+(XALE*10H)+(PAGM*2)+8DH
CONFIG1		EQU	(WSB*2)+0F9H
	
		CSEG	AT	(0FFF8H AND PROM_SIZE)
		DB	CONFIG0		; Config Byte 0
		DB	CONFIG1		; Config Byte 1

		END

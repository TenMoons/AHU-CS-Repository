; ---------------------------------------------------------------------------
;  Copyright (C) 2003 Dallas Semiconductor Corporation, All Rights Reserved.
; 
;  Permission is hereby granted, free of charge, to any person obtaining a
;  copy of this software and associated documentation files (the "Software"),
;  to deal in the Software without restriction, including without limitation
;  the rights to use, copy, modify, merge, publish, distribute, sublicense,
;  and/or sell copies of the Software, and to permit persons to whom the
;  Software is furnished to do so, subject to the following conditions:
; 
;  The above copyright notice and this permission notice shall be included
;  in all copies or substantial portions of the Software.
; 
;  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
;  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
;  MERCHANTABILITY,  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
;  IN NO EVENT SHALL DALLAS SEMICONDUCTOR BE LIABLE FOR ANY CLAIM, DAMAGES
;  OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
;  ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR
;  OTHER DEALINGS IN THE SOFTWARE.
; 
;  Except as contained in this notice, the name of Dallas Semiconductor
;  shall not be used except as stated in the Dallas Semiconductor
;  Branding Policy.
; ---------------------------------------------------------------------------

$NOMOD51

#include <REG390.H>

;****************************************************************************
; 
; BEGIN CONFIGURABLE OPTIONS
;
; Set USE_MONITOR to 0 to configure this program to load into bank 40 (flash on TINIm400)
; Set USE_MONITOR to 1 to configure this program to load into bank 20 (RAM on TINIm400)
;     where it is suitable for use by the Keil monitor.
;
$set (USE_MONITOR = 1)

;
; Set XTALMULT to 2 or 4 to use the crystal doubler or quadrupler.
; Set XTALMULT to 1 to use the default.  Do not use other
; values for XTALMULT.
;
$set (XTALMULT = 1)

;
; Set the OSCILLATOR_FREQ value to the value of the oscillator you are using.
; The TINIm400 uses a 14745600 Hz oscillator.  DO NOT CHANGE THIS VALUE TO
; REFLECT THE USE OF THE CRYSTAL MULTIPLIER.
;
OSCILLATOR_FREQ equ 14745600

;
; Set SERIAL0_BAUDRATE to the baud rate you want to get standard output at.
; Default is 115200.
;
SERIAL0_BAUDRATE equ 115200

;
; END OF CONFIGURABLE OPTIONS
;
;****************************************************************************
TIMER_RELOAD equ (65536 - ((OSCILLATOR_FREQ) / (32 * SERIAL0_BAUDRATE)))

                name    ?C_STARTUP
                ;
                ; Make sure the compiler does not use the OS flags & bits
                ;
?FLAGS          segment bit
                rseg    ?FLAGS

                org     20H
wos_flags:      dbit    8                                  ; Reserve all, they are not task switched!

?FLAGS2         segment bit
                rseg    ?FLAGS2

                org     27H
rom_flags:      dbit    4

?DIRECTS        segment data at 68H
                rseg    ?DIRECTS

                org     68H
wos_crit_count: DSB     1

                org     6DH
curr_pc:        DSB     3

                org     72H
sched:          DSB     3
ms_count:       DSB     5

                org     7BH
hb_chandle:     DSB     5


                extrn code (?C_START)
                public  ?C_STARTUP

$if (USE_MONITOR = 0)
?C_CPURESET?0   segment code at 400000H
$endif
$if (USE_MONITOR = 1)
?C_CPURESET?0   segment code at 200000H
$endif

                rseg    ?C_CPURESET?0
?C_STARTUP:     sjmp    past_loader_tag
                db     'TINI'                              ; Tag for TINI Environment 1.02c
                                                           ; or later (ignored in 1.02b)
$if (USE_MONITOR = 0)
                db      40H                                ; Target bank
$endif
$if (USE_MONITOR = 1)
                db      20H                                ; Target bank
$endif

past_loader_tag:
                clr     ea                                 ; No interrupts, please

                ;
                ; Make sure we are in contiguous mode
                ;
                mov     ta, #0xAA                          ; Enable access to ACON
                mov     ta, #0x55
                orl     acon, #2                           ; 24 bit mode
                ljmp    sanity_check                       ; Sanity check: Make sure 24 bit mode is on
sanity_check:
                mov     ta, #0xAA                          ; Enable access to MCON
                mov     ta, #0x55
                mov     mcon, #0xAF                        ; Relocate RAM, data memory
                mov     ta, #0xAA                          ; Enable access to ACON
                mov     ta, #0x55
                orl     acon, #0x04                        ; Extended stack

		;
		; Make sure we are in a known state with respect to
		; our fancy data pointers and register banks
		;
                mov     dps, #0
                mov     psw, #0

		;
		; Set stack to 0 (we lose one byte, but don't
		; have to know the size)
		;
                mov     sp,#0
                mov     esp,#0

                ;
                ; Do the Crystal Multiplier
                ;
$if XTALMULT = 2
startup_setxtal_mult_2:
                ;
                ; Multiply crystal frequency by 2
		;
                mov     pmr, #10000010b                    ; Set for crystal * 2
                mov     pmr, #10010010b                    ; Enable multiplier
WaitCrystal:
                mov     a, exif                            ; Wait for multiplier to be ready
                jnb     acc.3, WaitCrystal                 ; Jump if CKRY is low
                mov     pmr, #00010010b                    ; Go to crystal * 2

$elseif XTALMULT = 4
startup_setxtal_mult_4:
                ;
                ; Multiply crystal frequency by 4
		;
                mov     pmr, #10000010b                    ; Set to power up value
                mov     pmr, #10001010b                    ; Set for crystal * 4
                mov     pmr, #10011010b                    ; Enable multiplier
WaitCrystal4:
                mov     a, exif                            ; Wait for multiplier to be ready
                jnb     acc.3, WaitCrystal4                ; Jump if CKRY is low
                mov     pmr, #00011010b                    ; Go to crystal * 4
$endif

		; Enable the serial0, using timer 2 at 115200
                ; Use this equation for the reloads:
                ;     reload H:L = 65536 - (oscillator / (32 * baud))
                ; We now use User Configurable Equates for the serial
		; port settings.  The default is for 115200, which
		; yeilds the following:
                ;     65536 - (14745600 / (32 * 115200)) = 65536 - (14745600 / 3686400)
                ;                                        = 65536 - 4
                ;                                        = 65532
                ;                                        = 0xFFFC
                mov     scon0, #5Ah                        ; 10 bit serial 0, use timer baud rate, enable recieving
                mov     rcap2h, #High(TIMER_RELOAD)        ; Set timer reload high byte
                mov     rcap2l, #Low(TIMER_RELOAD)         ; Set timer reload low bye
                mov     t2con, #30h                        ; Enable timer 2 for serial port
                setb    tr2                                ; Set timer 2 to run

                ; Make sure that we can output to the serial port
                setb    ti


                ljmp    ?C_START

                end

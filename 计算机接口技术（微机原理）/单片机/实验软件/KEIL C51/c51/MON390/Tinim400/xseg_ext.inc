;****************************************************************************
;*
;*  Copyright (C) 2003 Dallas Semiconductor Corporation.
;*  All rights Reserved. Printed in U.S.A.
;*  This software is protected by copyright laws of
;*  the United States and of foreign countries.
;*  This material may also be protected by patent laws of the United States
;*  and of foreign countries.
;*  This software is furnished under a license agreement and/or a
;*  nondisclosure agreement and may only be used or copied in accordance
;*  with the terms of those agreements.
;*  The mere transfer of this software does not imply any licenses
;*  of trade secrets, proprietary technology, copyrights, patents,
;*  trademarks, maskwork rights, or any other form of intellectual
;*  property whatsoever. Dallas Semiconductor retains all ownership rights.
;*
;*     Module Name: XSEG_EXT
;*
;*     Description: Extended equates for xram system variables for the 
;*                  DS80C400 C Libraries
;*
;*        Filename: xseg_ext.inc
;*
;* Dependant Files: none
;*
;*          Author: K
;*
;*        Compiler: A51.EXE
;*
;*         Version: 0.03
;*
;*         Created: 01/20/03
;*
;*   Modifications: 0.03 - Updated to include space for Keil Monitor stuff
;*
;*           Notes:
;*
;****************************************************************************
;


WOS_MAX_TASKS       equ     8

;
; The beginning of the extended XSEG area.  This needs to allow plenty of
; room for the XSEG area of the ROM underneath it.
;
XSEG_EXT_START      equ     8192


;********************************************************************
;   FILE SYSTEM STUFF
;********************************************************************
;
; Filesystem root directory pointer.
;
FS_TRANSACTION_BUFFER   equ     XSEG_EXT_START + 20
FS_SYSTEMLOCK           equ     FS_TRANSACTION_BUFFER + 30
FS_ROOTHANDLE           equ     FS_SYSTEMLOCK + 1            ; this is at 8243, or 2033h
FS_OPENFILES            equ     FS_ROOTHANDLE + 3
FS_LOCKEDFILES          equ     FS_OPENFILES + 24
FS_EXECUTING            equ     FS_LOCKEDFILES + 24
FS_WRITEBUFFER          equ     FS_EXECUTING + 32 + 20  ; This offset needs to change 
                                                        ; if MAX_PROCESSES changes.  it is currently
                                                        ; (20 bytes of padding) + (4 * MAX_PROCESSES)
FS_READBUFFER           equ     FS_WRITEBUFFER + 1
FS_END                  equ     FS_READBUFFER + 1

;
; Simple memory manager, memory manager for file system.
; 256 byte blocks, simple mapping scheme.
;
SMM_START_POINTER       equ     FS_END                  ; Points to beginning of SMM managed memory
SMM_NUM_BLOCKS          equ     SMM_START_POINTER + 3   ; Number of 256-byte blocks allocated to SMM
SMM_OVERHEAD_BLOCKS     equ     SMM_NUM_BLOCKS + 2      ; Number of blocks used on SMM overhead.  The 
                                                        ; next block after this overhead is the first
                                                        ; block available to the file system.
SMM_MAX_FDOPEN          equ     SMM_OVERHEAD_BLOCKS + 1 ; Max number of open File Desc's allowed
SMM_END                 equ     SMM_MAX_FDOPEN + 1


;********************************************************************
; KEIL MONITOR400 STUFF
;********************************************************************

MONITOR_INTERRUPT            equ      SMM_END
MONITOR_HACK_LJMP            equ      MONITOR_INTERRUPT + 5      ; space for 1 ljmp statement (+ 1 byte address) for interrupt
MONITOR_INTERRUPT_END        equ      MONITOR_HACK_LJMP + 4      ; space for 1 ljmp statement for code start






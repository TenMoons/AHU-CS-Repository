;* $Id: //depot/software/FC220/include/TE5_CSOC.inc#3 $
;*
;* Triscend E5 CSoC device register definition file
;*
;* Copyright (c) 2000, 2001 Triscend Corporation. All rights reserved.

;* The following macro definition is needed if you include this
;* file directly, instead of the FastChip project header file
;* Both FastChip project header and source file define their own
;* macros, and set the USE_PROJECT_FILE_MACRO flag to skip the
;* following macro definitions.

$IF (USE_PROJECT_FILE_MACRO)
$ELSE ;* USE_PROJECT_FILE_MACRO
;*======== Required macro definitions ========
CHAR_XDATA  MACRO SYMNAME,SYMLOC
SYMNAME     EQU SYMLOC
            ENDM
CHAR_ARRAY_XDATA  MACRO SYMNAME,SYMLOC,SIZE
SYMNAME     EQU SYMLOC
            ENDM
$ENDIF ;* USE_PROJECT_FILE_MACRO

;* Assume that $NOMOD51 is placed in the top level A51 file(s)
;* in order to prevent A51 assembler from implicitly defining
;* symbols for the default 8051 special function registers.
;* Alternatively, add the NOMOD51 to the assembler control string.
;* Consult Keil documentation if needed.
;
;*======== E5 byte addressable SFR registers ========
    CSEG
    ; -- reserved (P0) --
    SP      DATA   081H
    DPL     DATA   082H
    DPH     DATA   083H
    DPL1    DATA   084H
    DPH1    DATA   085H
    DPS     DATA   086H
    PCON    DATA   087H
    TCON    DATA   088H
    TMOD    DATA   089H
    TL0     DATA   08aH
    TL1     DATA   08bH
    TH0     DATA   08cH
    TH1     DATA   08dH
    CKCON   DATA   08eH
    ; -- reserved (P1) --
    SCON    DATA   098H
    SBUF    DATA   099H
    ; -- reserved (P2) --
    IE      DATA   0a8H
    SADDR   DATA   0a9H
    ; -- reserved (P3) --
    IP      DATA   0b8H
    SADEN   DATA   0b9H
    TA      DATA   0c7H
    T2CON   DATA   0c8H
    T2MOD   DATA   0c9H
    RCAP2L  DATA   0caH
    RCAP2H  DATA   0cbH
    TL2     DATA   0ccH
    TH2     DATA   0cdH
    PSW     DATA   0d0H
    WDCON   DATA   0d8H
    ACC     DATA   0e0H
    EIE     DATA   0e8H
    B       DATA   0f0H
    EIP     DATA   0f8H

;*======== E5 bit addressable SFR registers ========
;*---------------------------- TCON
    TF1     BIT   08fH
    TR1     BIT   08eH
    TF0     BIT   08dH
    TR0     BIT   08cH
    IE1     BIT   08bH
    IT1     BIT   08aH
    IE0     BIT   089H
    IT0     BIT   088H
;*---------------------------- SCON
    SM0     BIT   09fH
    SM1     BIT   09eH
    SM2     BIT   09dH
    REN     BIT   09cH
    TB8     BIT   09bH
    RB8     BIT   09aH
    TI      BIT   099H
    RI      BIT   098H
;*---------------------------- IE
    EA      BIT   0afH
    ; -- reserved --
    ET2     BIT   0adH
    ES      BIT   0acH
    ET1     BIT   0abH
    EX1     BIT   0aaH
    ET0     BIT   0a9H
    EX0     BIT   0a8H
;*---------------------------- IP
    ; -- reserved --
    ; -- reserved --
    PT2     BIT   0bdH
    PS      BIT   0bcH
    PT1     BIT   0bbH
    PX1     BIT   0baH
    PT0     BIT   0b9H
    PX0     BIT   0b8H
;*---------------------------- T2CON
    TF2     BIT   0cfH
    EXF2    BIT   0ceH
    RCLK    BIT   0cdH
    TCLK    BIT   0ccH
    EXEN2   BIT   0cbH
    TR2     BIT   0caH
    C_T2    BIT   0c9H
    CP_RL2  BIT   0c8H
;*---------------------------- PSW
    CY      BIT   0d7H
    AC      BIT   0d6H
    F0      BIT   0d5H
    RS1     BIT   0d4H
    RS0     BIT   0d3H
    OV      BIT   0d2H
    P       BIT   0d0H
;*---------------------------- WDCON
    POR     BIT   0deH
    EHPI    BIT   0ddH
    HPI     BIT   0dcH
    WDIF    BIT   0dbH
    WTRF    BIT   0daH
    EWT     BIT   0d9H
    RWT     BIT   0d8H
;*---------------------------- EIE
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
    EWDI    BIT   0ecH
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
;*---------------------------- EIP
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
    PWDI    BIT   0fcH
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --


;*========= Visible CRU Registers ===
E5CRU_VISIBLE_BASE_ADDR EQU 0f000H
    XSEG
    CHAR_XDATA   CMAP0_TAR,        0ff00H 
    CHAR_XDATA   CMAP0_ALT,        0ff01H 
    CHAR_XDATA   CMAP1_TAR_0,      0ff02H 
    CHAR_XDATA   CMAP1_TAR_1,      0ff03H 
    CHAR_XDATA   CMAP1_TAR_2,      0ff04H 
    CHAR_XDATA   CMAP1_SRC,        0ff05H 
    CHAR_XDATA   CMAP1_CTL,        0ff06H 
    CHAR_XDATA   CMAP1_ALT,        0ff07H 
    CHAR_XDATA   CMAP2_TAR_0,      0ff08H 
    CHAR_XDATA   CMAP2_TAR_1,      0ff09H 
    CHAR_XDATA   CMAP2_TAR_2,      0ff0aH 
    CHAR_XDATA   CMAP2_SRC,        0ff0bH 
    CHAR_XDATA   CMAP2_CTL,        0ff0cH 
    CHAR_XDATA   CMAP2_ALT,        0ff0dH 
    CHAR_XDATA   DMAP0_TAR,        0ff0eH 
    CHAR_XDATA   DMAP1_TAR_0,      0ff0fH 
    CHAR_XDATA   DMAP1_TAR_1,      0ff10H 
    CHAR_XDATA   DMAP1_TAR_2,      0ff11H 
    CHAR_XDATA   DMAP1_SRC,        0ff12H 
    CHAR_XDATA   DMAP1_CTL,        0ff13H 
    CHAR_XDATA   DMAP2_TAR_0,      0ff14H 
    CHAR_XDATA   DMAP2_TAR_1,      0ff15H 
    CHAR_XDATA   DMAP2_TAR_2,      0ff16H 
    CHAR_XDATA   DMAP2_SRC,        0ff17H 
    CHAR_XDATA   DMAP2_CTL,        0ff18H 
    CHAR_XDATA   DMAP3_TAR,        0ff19H 
    CHAR_XDATA   DMAP3_SRC,        0ff1aH 
    CHAR_XDATA   DMAP3_CTL,        0ff1bH 
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
    ; -- reserved --
    CHAR_XDATA   DMASADR0_0,       0ff20H 
    CHAR_XDATA   DMASADR0_1,       0ff21H 
    CHAR_XDATA   DMASADR0_2,       0ff22H 
    CHAR_XDATA   DMASADR0_3,       0ff23H 
    CHAR_XDATA   DMASCNT0_0,       0ff24H 
    CHAR_XDATA   DMASCNT0_1,       0ff25H 
    CHAR_XDATA   DMASCNT0_2,       0ff26H 
    CHAR_XDATA   DMACTRL0_0,       0ff27H 
    CHAR_XDATA   DMACTRL0_1,       0ff28H 
    CHAR_XDATA   DMAEINT0,         0ff29H 
    CHAR_XDATA   DMAINT0,          0ff2aH 
    CHAR_XDATA   DMACADR0_0,       0ff2bH 
    CHAR_XDATA   DMACADR0_1,       0ff2cH 
    CHAR_XDATA   DMACADR0_2,       0ff2dH 
    CHAR_XDATA   DMACADR0_3,       0ff2eH 
    CHAR_XDATA   DMACCNT0_0,       0ff2fH 
    CHAR_XDATA   DMACCNT0_1,       0ff30H 
    CHAR_XDATA   DMACCNT0_2,       0ff31H 
    CHAR_XDATA   DMAPREQ0_0,       0ff32H 
    CHAR_XDATA   DMAPREQ0_1,       0ff33H 
    CHAR_XDATA   DMASADR1_0,       0ff34H 
    CHAR_XDATA   DMASADR1_1,       0ff35H 
    CHAR_XDATA   DMASADR1_2,       0ff36H 
    CHAR_XDATA   DMASADR1_3,       0ff37H 
    CHAR_XDATA   DMASCNT1_0,       0ff38H 
    CHAR_XDATA   DMASCNT1_1,       0ff39H 
    CHAR_XDATA   DMASCNT1_2,       0ff3aH 
    CHAR_XDATA   DMACTRL1_0,       0ff3bH 
    CHAR_XDATA   DMACTRL1_1,       0ff3cH 
    CHAR_XDATA   DMAEINT1,         0ff3dH 
    CHAR_XDATA   DMAINT1,          0ff3eH 
    CHAR_XDATA   DMACADR1_0,       0ff3fH 
    CHAR_XDATA   DMACADR1_1,       0ff40H 
    CHAR_XDATA   DMACADR1_2,       0ff41H 
    CHAR_XDATA   DMACADR1_3,       0ff42H 
    CHAR_XDATA   DMACCNT1_0,       0ff43H 
    CHAR_XDATA   DMACCNT1_1,       0ff44H 
    CHAR_XDATA   DMACCNT1_2,       0ff45H 
    CHAR_XDATA   DMAPREQ1_0,       0ff46H 
    CHAR_XDATA   DMAPREQ1_1,       0ff47H 
    CHAR_XDATA   DMACRC_0,         0ff48H 
    CHAR_XDATA   DMACRC_1,         0ff49H 

    CHAR_XDATA   PROTECT,          0ff60H 
    CHAR_XDATA   SECURITY,         0ff61H 
    CHAR_XDATA   PWDSEL,           0ff62H 
    CHAR_XDATA   PORCTRL,          0ff63H 

    CHAR_XDATA   DMAP4_TAR_0,      0ff80H 
    CHAR_XDATA   DMAP4_TAR_1,      0ff81H 
    CHAR_XDATA   DMAP4_TAR_2,      0ff82H 
    CHAR_XDATA   DMAP4_SRC,        0ff83H 
    CHAR_XDATA   DMAP4_CTL,        0ff84H 
    CHAR_XDATA   DMAP5_TAR_0,      0ff85H 
    CHAR_XDATA   DMAP5_TAR_1,      0ff86H 
    CHAR_XDATA   DMAP5_TAR_2,      0ff87H 
    CHAR_XDATA   DMAP5_SRC,        0ff88H 
    CHAR_XDATA   DMAP5_CTL,        0ff89H 

//
//  ISD51  In-System Debugger for 8051 based microcontrollers
//  Copyright KEIL ELEKTRONIK GmbH and Keil Software, Inc. 2000 - 2003
//  Version 2.03a
//------------------------------------------------------------------------------
//  ISD51.H:  This header file allows the configuration of the ISD51
//            In-System Monitor
//
//  Copy this file to your project folder and add the copy to your uVision2
//  project.  You can customize several parameters of the ISD51 In-System 
//  Monitor within this configuration file.
//
//------------------------------------------------------------------------------
//  ISD51 Memory Space
//  ==================
//
//  The following define specifies the size of the on-chip DATA/IDATA RAM.
//  Most 8051 devices have 256 bytes IDATA RAM.  Some devices offer just
//  128 Bytes.  ISD51 uses 1 Byte in this IDATA.  
//
//  If you are using software breakpoints, each breakpoint requires another 
//  2 Bytes IDATA space.  For example, if two breakpoints are defined, ISD51
//  uses the IDATA locations 0xFB .. 0xFF.

#define RAMSIZE    0x100   // default is 0x100 => 256 bytes IDATA RAM

//  The option "Verify if application in ROM is identical to current project"
//  that is enabled in uVision2 under "Project - Options for Target - Debug -
//  Use ISD51 - Settings" compares ROM content against the current project.
//  CMP_START and CMP_END specify address ranges for comparing memory contents.
//  Outside the specified range CODE memory mismatches are ignored.
#define CMP_START 0x0     // default is 0
#define CMP_END   0xFFFF  // default is 64KB (0xFFFF)

//------------------------------------------------------------------------------
//
//  ISD51 UART Interface
//  ====================
//
//  ISD51 uses a standard on-chip 8051 UART as communication interface.  The
//  following assembler macros allow you to change the UART interface used by 
//  ISD51.

#ifndef __C51__

/* 8051 SFR Register addresses for on-chip 8051 UART */
sfr  SCON = 0x98;
sfr  SBUF = 0x99;
sfr  IE   = 0xA8;

/*  SCON  Bits */
sbit TI   = SCON^1;
sbit RI   = SCON^0;

/* IE Bits */
sbit ES   = IE^4;
sbit EA   = IE^7;

CLR_TI   MACRO             ; Clear Transmit Interrupt Flag 
         CLR     TI        ; No CPU register may be changed here
         ENDM

SET_TI   MACRO             ; Set   Transmit Interrupt Flag
         SETB    TI        ; No CPU register may be changed here
         ENDM

JNB_TI   MACRO   label     ; Jump if Transmit Interrupt Flag not set
         JNB     TI,label  ; PSW may be modified without saving it
         ENDM

WR_SBUF  MACRO             ; Write ACC to SBUF
         MOV     SBUF,A    ; ACC and PSW may be modified without saving it
         ENDM

CLR_RI   MACRO             ; Clear Receiver Interrupt Flag 
         CLR     RI        ; No CPU register may be changed here
         ENDM

JB_RI    MACRO   label     ; Jump if Receiver Interrupt Flag set
         JB      RI,label  ; ACC and PSW may be modified without saving it
         ENDM

JNB_RI   MACRO   label     ; Jump if Receiver Interrupt Flag not set
         JNB     RI,label  ; ACC and PSW may be modified without saving it
         ENDM

RD_SBUF  MACRO             ; Return SBUF in ACC
         MOV    A,SBUF     ; ACC and PSW may be modified without saving it
         ENDM

CLR_ES   MACRO             ; Disable Serial Interrupt
         CLR    ES         ; No CPU register may be changed here
         ENDM

SET_ES   MACRO             ; Enable Serial Interrupt
         SETB   ES         ; No CPU register may be changed here
         ENDM

JNB_ES   MACRO   label     ; Jump if Receiver Interrupt Flag not set
         JNB     ES,label  ; ACC and PSW may be modified without saving it
         ENDM

SAVE_ES  MACRO             ; Save Serial Interrupt enable bit to Carry
         MOV    C,ES       ; ACC and PSW may be modified without saving it
         ENDM

RESTO_ES MACRO             ; Restore Serial Interrupt enable bit from Carry
         MOV    ES,C       ; ACC and PSW may be modified without saving it
         ENDM

SINTRVEC EQU    0x23       ; Interrupt Vector Address of UART interrupt

#endif
//------------------------------------------------------------------------------
//
//  ISD51 CODE MEMORY ACCESS FUNCTIONS FOR HARDWARE BREAKPOINTS 
//  ===========================================================
//
//  For devices that support IAP (In-Application Programming) ISD51 may modify
//  the code memory to insert CALL instructions for flash breakpoints.  The IAP
//  functions are configured below:
//
//  The macro CWRITE defines a flash erase and programming function that writes
//  new content to a Flash CODE ROM block.  The new content data are store in
//  on-chip IDATA RAM at address CBLK.  The Flash CODE ROM block address is
//  passed in the register A:R0 (A is MSB, R0 is LSB).

#define CBLK_SZ   0        // Flash block size for CWRITE, valid are:
                           // 1, 2, 4, 8, 16, 32, 64, and 128 Bytes. 
//  Note: CBLK_SZ  0 disables hardware breakpoints.  IDS51 will use 
//  software breakpoints instead.

#ifndef __C51__

// define a macro that erases and writes new content to a Flash memory block
// R0 contains LOW address, ACC contains HIGH address of Flash memory block
// Macro returns error code in ACC.  ACC=0 indicates no errors

CWRITE  MACRO              ; write new content data to Flash CODE ROM block
                           ; Flash block address in DPTR
        ENDM

#endif


//------------------------------------------------------------------------------
//
//  ISD51 specific Serial User I/O
//  ==============================
//
//  ISD51 offers serial user input/output functions that work via the serial
//  interface that is used for debugging.  The serial user I/O functions are
//  configured below.

//  enable/disable ISD51 specific putchar function for user output.
#define  ISD_PUTCHAR  1    //  set to 0 to disable the putchar function.
                           //  set to 1 to enable the putchar function.

//  enable/disable ISD51 specific _getkey & _iskey function for user input.
#define  ISD_GETKEY   1    //  set to 0 to disable the _getkey/_iskey function.
                           //  set to 1 to enable the _getkey/_iskey function.

//------------------------------------------------------------------------------
//
//  ISD51 Functions
//  ===============
//
//  The following C Macro define the IDS51 functions
#ifdef __C51__

#include <absacc.h>

extern void __isd_init (void);   // ISD51 core init function

#define ISDinit()                                                      \
  if (ES == 0)  {        /* Is ISD51 UART already initialized?     */  \
    __isd_init ();       /* Init ISD51 core & enable ISD interrupt */  \
  }

#define ISDwait()                                                      \
  while (1)  {                                                         \
    if (RI)  {           /* wait until Debugger sends 0xA5 */          \
      if (SBUF == 0xA5)  break;                                        \    
      RI = 0;                                                          \
    }                                                                  \
  }                                                                    \
  __isd_init ();         /* Init ISD51 core & enable ISD interrupt */

#define ISDcheck()                                                     \
  if (ES == 0)  {        /* Is ISD51 UART already initialized?     */  \
    if (RI)  {           /* wait until Debugger sends 0xA5 */          \
      if (SBUF != 0xA5) RI = 0;                                        \
      else              __isd_init (); /* Init core & ISD interrupt */ \
    }                                                                  \
  }                                                                    \

#define ISDdisable()     /* Disable ISD Interrupt                  */  \
    ES = 0;

#define ISDenable()      /* Enable  ISD Interrupt                  */  \
    ES = 1;

#define ISDbreak()       /* hard-code program stop (breakpoint) */     \
    TI = 1;              /* Enter ISD Interrupt function */            \
    _nop_ ();

#if ISD_GETKEY            /* user input function                */          
extern bit _iskey (void); /* check if input character available */
#endif

#endif

//------------------------------------------------------------------------------
//
//  ISD51 HARDWARE BREAKREGISTER SUPPORT
//  ====================================
//
//  ISD51 supports Hardware Breakpoints of some specific 8051 devices.
//  Currently the TI MSC device is supported.  If you are running ISD51 on
//  this device you can uncomment the following define statement if you are
//  NOT using flash breakpoints (see CBLK_SZ).
//
// #define  TI_MSC1210_BREAKS

//------------------------------------------------------------------------------
//
//  ISD51 SPECIAL CONFIGURATIONS
//  ============================
//
// ISD51 needs to be configured for specific device features.  Uncomment one 
// of the following define statements if you are using one of these devices.
//
// TI MSC121x version with EAI bit handling
// #define TI_MSC1210
//
// Philips LPC900 version with two additional SFR write functions
// #define PHILIPS_LPC900

//-----------------------------------------------------------------------------
//---------------- !!! End of User Configuration Part    !!! ------------------
//-----------------------------------------------------------------------------


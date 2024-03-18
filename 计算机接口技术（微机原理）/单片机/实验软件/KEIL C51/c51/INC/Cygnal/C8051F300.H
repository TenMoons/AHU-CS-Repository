/*---------------------------------------------------------------------------
;	Copyright (C) 2001 CYGNAL INTEGRATED PRODUCTS, INC.
; 	All rights reserved.
;
;
; 	FILE NAME  	: C8051F300.H 
; 	TARGET MCUs	: C8051F300, 'F301, 'F302, 'F303 
; 	DESCRIPTION	: Register/bit definitions for the C8051F30x product family.  
;
; 	REVISION 1.1 	
;
;---------------------------------------------------------------------------*/

/*  BYTE Registers  */
sfr P0       = 0x80;    /* PORT 0                                                   */	
sfr SP       = 0x81;    /* STACK POINTER                                            */
sfr DPL      = 0x82;    /* DATA POINTER - LOW BYTE                                  */
sfr DPH      = 0x83;    /* DATA POINTER - HIGH BYTE                                 */
sfr PCON     = 0x87;    /* POWER CONTROL                                            */
sfr TCON     = 0x88;    /* TIMER CONTROL                                            */
sfr TMOD     = 0x89;    /* TIMER MODE                                               */
sfr TL0      = 0x8A;    /* TIMER 0 - LOW BYTE                                       */
sfr TL1      = 0x8B;    /* TIMER 1 - LOW BYTE                                       */
sfr TH0      = 0x8C;    /* TIMER 0 - HIGH BYTE                                      */	
sfr TH1      = 0x8D;    /* TIMER 1 - HIGH BYTE                                      */
sfr CKCON    = 0x8E;    /* CLOCK CONTROL                                            */
sfr PSCTL    = 0x8F;    /* PROGRAM STORE R/W CONTROL                                */
sfr SCON0    = 0x98;    /* SERIAL PORT 0 CONTROL                                    */
sfr SBUF0    = 0x99;    /* SERIAL PORT 0 BUFFER                                     */
sfr CPT0MD   = 0x9D;    /* COMPARATOR 0 MODE                                        */
sfr CPT0MX   = 0x9F;    /* COMPARATOR 0 MUX                                         */
sfr P0MDOUT  = 0xA4;    /* PORT 0 OUTPUT MODE                                       */
sfr IE       = 0xA8;    /* INTERRUPT ENABLE                                         */
sfr OSCXCN   = 0xB1;    /* EXTERNAL OSCILLATOR CONTROL                              */
sfr OSCICN   = 0xB2;    /* INTERNAL OSCILLATOR CONTROL                              */
sfr OSCICL   = 0xB3;    /* INTERNAL OSCILLATOR CALIBRATION                          */
sfr FLSCL    = 0xB6;    /* FLASH SCALE                                         */
sfr FLKEY    = 0xB7;    /* FLASH LOCK & KEY                                         */
sfr IP       = 0xB8;    /* INTERRUPT PRIORITY                                       */
sfr AMX0SL   = 0xBB;    /* ADC 0 MUX CHANNEL SELECTION                              */
sfr ADC0CF   = 0xBC;    /* ADC 0 CONFIGURATION                                      */
sfr ADC0     = 0xBE;    /* ADC 0 DATA                                               */
sfr SMB0CN   = 0xC0;    /* SMBUS CONTROL                                            */
sfr SMB0CF   = 0xC1;    /* SMBUS CONFIGURATION                                      */
sfr SMB0DAT  = 0xC2;    /* SMBUS DATA                                               */
sfr ADC0GT   = 0xC4;    /* ADC0 GREATER-THAN                                        */
sfr ADC0LT   = 0xC6;    /* ADC0 LESS-THAN                                           */
sfr TMR2CN   = 0xC8;    /* TIMER 2 CONTROL                                          */
sfr TMR2RLL  = 0xCA;    /* TIMER 2 RELOAD LOW                                       */
sfr TMR2RLH  = 0xCB;    /* TIMER 2 RELOAD HIGH                                      */
sfr TMR2L    = 0xCC;    /* TIMER 2 LOW BYTE                                         */
sfr TMR2H    = 0xCD;    /* TIMER 2 HIGH BYTE                                        */
sfr PSW      = 0xD0;    /* PROGRAM STATUS WORD                                      */
sfr REF0CN   = 0xD1;    /* VOLTAGE REFERENCE 0 CONTROL                              */
sfr PCA0CN   = 0xD8;    /* PCA0 CONTROL                                             */
sfr PCA0MD   = 0xD9;    /* PCA0 MODE                                                */
sfr PCA0CPM0 = 0xDA;    /* PCA0 MODULE 0 MODE                                       */
sfr PCA0CPM1 = 0xDB;    /* PCA0 MODULE 1 MODE                                       */
sfr PCA0CPM2 = 0xDC;    /* PCA0 MODULE 2 MODE                                       */
sfr ACC      = 0xE0;    /* ACCUMULATOR                                              */
sfr XBR0     = 0xE1;    /* DIGITAL CROSSBAR CONFIGURATION REGISTER 0                */
sfr XBR1     = 0xE2;    /* DIGITAL CROSSBAR CONFIGURATION REGISTER 1                */
sfr XBR2     = 0xE3;    /* DIGITAL CROSSBAR CONFIGURATION REGISTER 2                */
sfr IT01CF   = 0xE4;    /* INT0/INT1 CONFIGURATION                                  */
sfr EIE1     = 0xE6;    /* EXTERNDED INTERRUPT ENABLE 1                              */
sfr ADC0CN   = 0xE8;    /* ADC 0 CONTROL                                            */	
sfr PCA0CPL1 = 0xE9;    /* PCA0 MODULE 1 CAPTURE/COMPARE REGISTER LOW BYTE          */
sfr PCA0CPH1 = 0xEA;    /* PCA0 MODULE 1 CAPTURE/COMPARE REGISTER HIGH BYTE         */
sfr PCA0CPL2 = 0xEB;    /* PCA0 MODULE 2 CAPTURE/COMPARE REGISTER LOW BYTE          */
sfr PCA0CPH2 = 0xEC;    /* PCA0 MODULE 2 CAPTURE/COMPARE REGISTER HIGH BYTE         */
sfr RSTSRC   = 0xEF;    /* RESET SOURCE                                             */
sfr B        = 0xF0;    /* B REGISTER                                               */
sfr P0MDIN   = 0xF1;    /* PORT 0 INPUT MODE REGISTER                               */
sfr EIP1     = 0xF6;    /* EXTERNAL INTERRUPT PRIORITY 1                              */
sfr CPT0CN   = 0xF8;    /* COMPARATOR 0 CONTROL                                     */
sfr PCA0L    = 0xF9;    /* PCA0 COUNTER REGISTER LOW BYTE                           */
sfr PCA0H    = 0xFA;    /* PCA0 COUNTER REGISTER HIGH BYTE                          */
sfr PCA0CPL0 = 0xFB;    /* PCA MODULE 0 CAPTURE/COMPARE REGISTER LOW BYTE           */
sfr PCA0CPH0 = 0xFC;    /* PCA MODULE 0 CAPTURE/COMPARE REGISTER HIGH BYTE          */

/*  BIT Registers  */

/*  TCON  0x88 */
sbit IT0     = TCON ^ 0;   /* EXT INTERRUPT 0 TYPE                                  */
sbit IE0     = TCON ^ 1;   /* EXT INTERRUPT 0 EDGE FLAG                             */
sbit IT1     = TCON ^ 2;   /* EXT INTERRUPT 1 TYPE                                  */
sbit IE1     = TCON ^ 3;   /* EXT INTERRUPT 1 EDGE FLAG                             */
sbit TR0     = TCON ^ 4;   /* TIMER 0 ON/OFF CONTROL                                */
sbit TF0     = TCON ^ 5;   /* TIMER 0 OVERFLOW FLAG                                 */
sbit TR1     = TCON ^ 6;   /* TIMER 1 ON/OFF CONTROL                                */
sbit TF1     = TCON ^ 7;   /* TIMER 1 OVERFLOW FLAG                                 */

/*  SCON0  0x98 */
sbit RI0     = SCON0 ^ 0;  /* RECEIVE INTERRUPT FLAG                                */
sbit TI0     = SCON0 ^ 1;  /* TRANSMIT INTERRUPT FLAG                               */
sbit RB80    = SCON0 ^ 2;  /* RECEIVE BIT 8                                         */
sbit TB80    = SCON0 ^ 3;  /* TRANSMIT BIT 8                                        */
sbit REN0    = SCON0 ^ 4;  /* RECEIVE ENABLE                                        */
sbit MCE0    = SCON0 ^ 5;  /* MULTIPROCESSOR COMMUNICATION ENABLE                   */
sbit S0MODE  = SCON0 ^ 7;  /* SERIAL MODE CONTROL BIT 0                             */

/*  IE  0xA8 */
sbit EX0     = IE ^ 0;     /* EXTERNAL INTERRUPT 0 ENABLE                           */
sbit ET0     = IE ^ 1;     /* TIMER 0 INTERRUPT ENABLE                              */
sbit EX1     = IE ^ 2;     /* EXTERNAL INTERRUPT 1 ENABLE                           */
sbit ET1     = IE ^ 3;     /* TIMER 1 INTERRUPT ENABLE                              */
sbit ES0     = IE ^ 4;     /* UART0 INTERRUPT ENABLE                                */
sbit ET2     = IE ^ 5;     /* TIMER 2 INTERRUPT ENABLE                              */
sbit EA      = IE ^ 7;     /* GLOBAL INTERRUPT ENABLE                               */

/*  IP  0xB8 */
sbit PX0     = IP ^ 0;     /* EXTERNAL INTERRUPT 0 PRIORITY                         */
sbit PT0     = IP ^ 1;     /* TIMER 0 PRIORITY                                      */
sbit PX1     = IP ^ 2;     /* EXTERNAL INTERRUPT 1 PRIORITY                         */
sbit PT1     = IP ^ 3;     /* TIMER 1 PRIORITY                                      */
sbit PS0     = IP ^ 4;     /* UART0 PRIORITY                                        */
sbit PT2     = IP ^ 5;     /* TIMER 2 PRIORITY                                      */

/* SMB0CN 0xC0 */
sbit SI      = SMB0CN ^ 0; /* SMBUS0 INTERRUPT FLAG                                 */
sbit ACK     = SMB0CN ^ 1; /* ACKNOWLEDGE FLAG                                      */
sbit ARBLOST = SMB0CN ^ 2; /* ARBITRATION LOST INDICATOR                            */
sbit ACKRQ   = SMB0CN ^ 3; /* ACKNOWLEDGE REQUEST                                   */
sbit STO     = SMB0CN ^ 4; /* STOP FLAG                                             */
sbit STA     = SMB0CN ^ 5; /* START FLAG                                            */
sbit TXMODE  = SMB0CN ^ 6; /* TRANSMIT MODE INDICATOR                               */
sbit MASTER  = SMB0CN ^ 7; /* MASTER/SLAVE INDICATOR                                */

/*  TMR2CN 0xC8 */
sbit T2XCLK  = TMR2CN ^ 0; /* TIMER 2 EXTERNAL CLOCK SELECT                         */
sbit TR2     = TMR2CN ^ 2; /* TIMER 2 ON/OFF CONTROL                                */
sbit T2SPLIT = TMR2CN ^ 3; /* TIMER 2 SPLIT MODE ENABLE                             */
sbit TF2LEN  = TMR2CN ^ 5; /* TIMER 2 LOW BYTE INTERRUPT ENABLE                     */
sbit TF2L    = TMR2CN ^ 6; /* TIMER 2 LOW BYTE OVERFLOW FLAG                        */
sbit TF2H    = TMR2CN ^ 7; /* TIMER 2 HIGH BYTE OVERFLOW FLAG                       */

/*  PSW 0xD0 */
sbit P       = PSW ^ 0;    /* ACCUMULATOR PARITY FLAG                               */
sbit F1      = PSW ^ 1;    /* USER FLAG 1                                           */
sbit OV      = PSW ^ 2;    /* OVERFLOW FLAG                                         */
sbit RS0     = PSW ^ 3;    /* REGISTER BANK SELECT 0                                */
sbit RS1     = PSW ^ 4;    /* REGISTER BANK SELECT 1                                */
sbit F0      = PSW ^ 5;    /* USER FLAG 0                                           */
sbit AC      = PSW ^ 6;    /* AUXILIARY CARRY FLAG                                  */
sbit CY      = PSW ^ 7;    /* CARRY FLAG                                            */	

/* PCA0CN 0xD8H */
sbit CCF0    = PCA0CN ^ 0; /* PCA0 MODULE 0 CAPTURE/COMPARE FLAG                    */
sbit CCF1    = PCA0CN ^ 1; /* PCA0 MODULE 1 CAPTURE/COMPARE FLAG                    */
sbit CCF2    = PCA0CN ^ 2; /* PCA0 MODULE 2 CAPTURE/COMPARE FLAG                    */
sbit CR      = PCA0CN ^ 6; /* PCA0 COUNTER RUN CONTROL                              */
sbit CF      = PCA0CN ^ 7; /* PCA0 COUNTER OVERFLOW FLAG                            */

/* ADC0CN 0xE8H */
sbit AD0CM0  = ADC0CN ^ 0; /* ADC0 CONVERSION MODE SELECT 0                         */
sbit AD0CM1  = ADC0CN ^ 1; /* ADC0 CONVERSION MODE SELECT 1                         */
sbit AD0CM2  = ADC0CN ^ 2; /* ADC0 CONVERSION MODE SELECT 2                         */
sbit AD0WINT = ADC0CN ^ 3; /* ADC0 WINDOW COMPARE INTERRUPT FLAG                    */
sbit AD0BUSY = ADC0CN ^ 4; /* ADC0 BUSY FLAG                                        */
sbit AD0INT  = ADC0CN ^ 5; /* ADC0 CONVERISION COMPLETE INTERRUPT FLAG              */
sbit AD0TM   = ADC0CN ^ 6; /* ADC0 TRACK MODE                                       */
sbit AD0EN   = ADC0CN ^ 7; /* ADC0 ENABLE                                           */

/* CPT0CN 0xF8H */
sbit CP0HYN0 = CPT0CN ^ 0; /* COMPARATOR 0 NEGATIVE HYSTERESIS 0                    */
sbit CP0HYN1 = CPT0CN ^ 1; /* COMPARATOR 0 NEGATIVE HYSTERESIS 1                    */
sbit CP0HYP0 = CPT0CN ^ 2; /* COMPARATOR 0 POSITIVE HYSTERESIS 0                    */
sbit CP0HYP1 = CPT0CN ^ 3; /* COMPARATOR 0 POSITIVE HYSTERESIS 1                    */
sbit CP0FIF  = CPT0CN ^ 4; /* COMPARATOR 0 FALLING-EDGE INTERRUPT FLAG              */
sbit CP0RIF  = CPT0CN ^ 5; /* COMPARATOR 0 RISING-EDGE INTERRUPT FLAG               */
sbit CP0OUT  = CPT0CN ^ 6; /* COMPARATOR 0 OUTPUT STATE                             */
sbit CP0EN   = CPT0CN ^ 7; /* COMPARATOR 0 ENABLE                                   */

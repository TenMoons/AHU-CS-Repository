/*---------------------------------------------------------------------------
;	Copyright (C) 2002 CYGNAL INTEGRATED PRODUCTS, INC.
; 	All rights reserved.
;
;
; 	FILE NAME  	: C8051F040.H 
; 	TARGET MCUs	: C8051F040, 'F041, 'F042, 'F043 
; 	DESCRIPTION	: Register/bit definitions for the C8051F04x product family.  
;
; 	REVISION 1.2 
;	CHANGES from Rev. 1.1: Properly labled sbit def's for CAN0STA	
;
;---------------------------------------------------------------------------*/

/*  BYTE Registers  */
sfr P0       = 0x80;    /* PORT 0                                       */	
sfr SP       = 0x81;    /* STACK POINTER                                */
sfr DPL      = 0x82;    /* DATA POINTER - LOW BYTE                      */
sfr DPH      = 0x83;    /* DATA POINTER - HIGH BYTE                     */
sfr SFRPAGE  = 0x84;    /* SFR PAGE SELECT                              */
sfr SFRNEXT  = 0x85;    /* SFR STACK NEXT PAGE                          */
sfr SFRLAST  = 0x86;    /* SFR STACK LAST PAGE                          */
sfr PCON     = 0x87;    /* POWER CONTROL                                */
sfr TCON     = 0x88;    /* TIMER CONTROL                                */
sfr CPT0CN   = 0x88;    /* COMPARATOR 0 CONTROL                         */
sfr CPT1CN   = 0x88;    /* COMPARATOR 1 CONTROL                         */
sfr CPT2CN   = 0x88;    /* COMPARATOR 2 CONTROL                         */
sfr TMOD     = 0x89;    /* TIMER MODE                                   */
sfr CPT0MD   = 0x89;    /* COMPARATOR 0 MODE                            */
sfr CPT1MD   = 0x89;    /* COMPARATOR 1 MODE                            */
sfr CPT2MD   = 0x89;    /* COMPARATOR 2 MODE                            */
sfr TL0      = 0x8A;    /* TIMER 0 - LOW BYTE                           */
sfr OSCICN   = 0x8A;    /* INTERNAL OSCILLATOR CONTROL                  */
sfr TL1      = 0x8B;    /* TIMER 1 - LOW BYTE                           */
sfr OSCICL   = 0x8B;    /* INTERNAL OSCILLATOR CALIBRATION              */
sfr TH0      = 0x8C;    /* TIMER 0 - HIGH BYTE                          */
sfr OSCXCN   = 0x8C;    /* EXTERNAL OSCILLATOR CONTROL                  */	
sfr TH1      = 0x8D;    /* TIMER 1 - HIGH BYTE                          */
sfr CKCON    = 0x8E;    /* TIMER 0/1 CLOCK CONTROL                      */
sfr PSCTL    = 0x8F;    /* FLASH WRITE/ERASE CONTROL                    */
sfr P1       = 0x90;    /* PORT 1                                       */
sfr SSTA0    = 0x91;    /* UART 0 STATUS                                */
sfr SFRPGCN  = 0x96;    /* SFR PAGE CONTROL                             */
sfr CLKSEL   = 0x97;    /* SYSTEM CLOCK SELECT                          */
sfr SCON0    = 0x98;    /* UART 0 CONTROL                               */
sfr SCON1    = 0x98;    /* UART 1 CONTROL                               */
sfr SBUF0    = 0x99;    /* UART 0 BUFFER                                */
sfr SBUF1    = 0x99;    /* UART 1 BUFFER                                */
sfr SPI0CFG  = 0x9A;    /* SPI 0 CONFIGURATION                          */
sfr SPI0DAT  = 0x9B;    /* SPI 0 DATA                                   */
sfr P4MDOUT  = 0x9C;    /* PORT 4 OUTPUT MODE                           */
sfr SPI0CKR  = 0x9D;    /* SPI 0 CLOCK RATE CONTROL                     */
sfr P5MDOUT  = 0x9D;    /* PORT 5 OUTPUT MODE                           */
sfr P6MDOUT  = 0x9E;    /* PORT 6 OUTPUT MODE                           */
sfr P7MDOUT  = 0x9F;    /* PORT 7 OUTPUT MODE                           */
sfr P2       = 0xA0;    /* PORT 2                                       */
sfr EMI0TC   = 0xA1;    /* EMIF TIMING CONTROL                          */
sfr EMI0CN   = 0xA2;    /* EMIF CONTROL                                 */
sfr EMI0CF   = 0xA3;    /* EMIF CONFIGURATION                           */
sfr P0MDOUT  = 0xA4;    /* PORT 0 OUTPUT MODE                           */
sfr P1MDOUT  = 0xA5;    /* PORT 1 OUTPUT MODE                           */
sfr P2MDOUT  = 0xA6;    /* PORT 2 OUTPUT MODE CONFIGURATION             */
sfr P3MDOUT  = 0xA7;    /* PORT 3 OUTPUT MODE CONFIGURATION             */
sfr IE       = 0xA8;    /* INTERRUPT ENABLE                             */
sfr SADDR0   = 0xA9;    /* UART 0 SLAVE ADDRESS                         */
sfr SADDR1   = 0xA9;    /* UART 1 SLAVE ADDRESS                         */
sfr P1MDIN   = 0xAD;    /* PORT 1 INPUT MODE                            */
sfr P2MDIN   = 0xAE;    /* PORT 2 INPUT MODE                            */
sfr P3MDIN   = 0xAF;    /* PORT 3 INPUT MODE                            */
sfr P3       = 0xB0;    /* PORT 3                                       */
sfr FLSCL    = 0xB7;    /* FLASH TIMING PRESCALAR                       */
sfr FLACL    = 0xB7;    /* FLASH ACCESS LIMIT                           */
sfr IP       = 0xB8;    /* INTERRUPT PRIORITY                           */
sfr SADEN0   = 0xB9;    /* UART 0 SLAVE ADDRESS MASK                    */
sfr AMX2CF   = 0xBA;    /* ADC 2 MUX CONFIGURATION                      */
sfr AMX0PRT  = 0xBD;    /* ADC 0 MUX PORT PIN SELECT REGISTER           */
sfr AMX0CF   = 0xBA;    /* ADC 0 CONFIGURATION REGISTER                 */
sfr AMX0SL   = 0xBB;    /* ADC 0 AND ADC 1 MODE SELECTION               */
sfr AMX2SL   = 0xBB;    /* ADC 2 MUX CHANNEL SELECTION                  */
sfr ADC0CF   = 0xBC;    /* ADC 0 CONFIGURATION                          */
sfr ADC2CF   = 0xBC;    /* ADC 2 CONFIGURATION                          */
sfr ADC0L    = 0xBE;    /* ADC 0 DATA - LOW BYTE                        */
sfr ADC2     = 0xBE;    /* ADC 2 DATA - LOW BYTE                        */
sfr ADC0H    = 0xBF;    /* ADC 0 DATA - HIGH BYTE                       */
sfr SMB0CN   = 0xC0;    /* SMBUS 0 CONTROL                              */
sfr CAN0STA  = 0xC0;    /* CAN 0 STATUS                                 */
sfr SMB0STA  = 0xC1;    /* SMBUS 0 STATUS                               */
sfr SMB0DAT  = 0xC2;    /* SMBUS 0 DATA                                 */
sfr SMB0ADR  = 0xC3;    /* SMBUS 0 SLAVE ADDRESS                        */
sfr ADC0GTL  = 0xC4;    /* ADC 0 GREATER-THAN REGISTER - LOW BYTE       */
sfr ADC2GT   = 0xC4;    /* ADC 2 GREATER-THAN REGISTER - LOW BYTE       */
sfr ADC0GTH  = 0xC5;    /* ADC 0 GREATER-THAN REGISTER - HIGH BYTE      */
sfr ADC0LTL  = 0xC6;    /* ADC 0 LESS-THAN REGISTER - LOW BYTE          */
sfr ADC2LT   = 0xC6;    /* ADC 2 LESS-THAN REGISTER - LOW BYTE          */
sfr ADC0LTH  = 0xC7;    /* ADC 0 LESS-THAN REGISTER - HIGH BYTE         */
sfr TMR2CN   = 0xC8;    /* TIMER 2 CONTROL                              */
sfr TMR3CN   = 0xC8;    /* TIMER 3 CONTROL                              */
sfr TMR4CN   = 0xC8;    /* TIMER 4 CONTROL                              */
sfr P4       = 0xC8;    /* PORT 4                                       */
sfr TMR2CF   = 0xC9;    /* TIMER 2 CONFIGURATION                        */
sfr TMR3CF   = 0xC9;    /* TIMER 3 CONFIGURATION                        */
sfr TMR4CF   = 0xC9;    /* TIMER 4 CONFIGURATION                        */
sfr RCAP2L   = 0xCA;    /* TIMER 2 CAPTURE REGISTER - LOW BYTE          */
sfr RCAP3L   = 0xCA;    /* TIMER 3 CAPTURE REGISTER - LOW BYTE          */
sfr RCAP4L   = 0xCA;    /* TIMER 4 CAPTURE REGISTER - LOW BYTE          */
sfr RCAP2H   = 0xCB;    /* TIMER 2 CAPTURE REGISTER - HIGH BYTE         */
sfr RCAP3H   = 0xCB;    /* TIMER 3 CAPTURE REGISTER - HIGH BYTE         */
sfr RCAP4H   = 0xCB;    /* TIMER 4 CAPTURE REGISTER - HIGH BYTE         */
sfr TMR2L    = 0xCC;    /* TIMER 2 - LOW BYTE                           */
sfr TMR3L    = 0xCC;    /* TIMER 3 - LOW BYTE                           */
sfr TMR4L    = 0xCC;    /* TIMER 4 - LOW BYTE                           */
sfr TMR2H    = 0xCD;    /* TIMER 2 - HIGH BYTE                          */
sfr TMR3H    = 0xCD;    /* TIMER 3 - HIGH BYTE                          */
sfr TMR4H    = 0xCD;    /* TIMER 4 - HIGH BYTE                          */
sfr SMB0CR   = 0xCF;    /* SMBUS 0 CLOCK RATE                           */
sfr PSW      = 0xD0;    /* PROGRAM STATUS WORD                          */
sfr REF0CN   = 0xD1;    /* VOLTAGE REFERENCE 0 CONTROL                  */
sfr DAC0L    = 0xD2;    /* DAC 0 REGISTER - LOW BYTE                    */
sfr DAC1L    = 0xD2;    /* DAC 1 REGISTER - LOW BYTE                    */
sfr DAC0H    = 0xD3;    /* DAC 0 REGISTER - HIGH BYTE                   */
sfr DAC1H    = 0xD3;    /* DAC 1 REGISTER - HIGH BYTE                   */
sfr DAC0CN   = 0xD4;    /* DAC 0 CONTROL                                */
sfr DAC1CN   = 0xD4;    /* DAC 1 CONTROL                                */
sfr HVA0CN   = 0xD6;    /* HVDA CONTROL REGISTER                        */
sfr PCA0CN   = 0xD8;    /* PCA 0 COUNTER CONTROL                        */
sfr CAN0DATL = 0xD8;    /* CAN 0 DATA - LOW BYTE                        */
sfr P5       = 0xD8;    /* PORT 5                                       */
sfr PCA0MD   = 0xD9;    /* PCA 0 COUNTER MODE                           */
sfr CAN0DATH = 0xD9;    /* CAN 0 DATA - HIGH BYTE                       */
sfr PCA0CPM0 = 0xDA;    /* PCA 0 MODULE 0 CONTROL                       */
sfr CAN0ADR  = 0xDA;    /* CAN 0 ADDRESS                                */
sfr PCA0CPM1 = 0xDB;    /* PCA 0 MODULE 1 CONTROL                       */
sfr CAN0TST  = 0xDB;    /* CAN 0 TEST                                   */
sfr PCA0CPM2 = 0xDC;    /* PCA 0 MODULE 2 CONTROL                       */
sfr PCA0CPM3 = 0xDD;    /* PCA 0 MODULE 3 CONTROL                       */
sfr PCA0CPM4 = 0xDE;    /* PCA 0 MODULE 4 CONTROL                       */
sfr PCA0CPM5 = 0xDF;    /* PCA 0 MODULE 5 CONTROL                       */
sfr ACC      = 0xE0;    /* ACCUMULATOR                                  */
sfr PCA0CPL5 = 0xE1;    /* PCA 0 MODULE 5 CAPTURE/COMPARE - LOW BYTE    */
sfr XBR0     = 0xE1;    /* CROSSBAR CONFIGURATION REGISTER 0            */
sfr PCA0CPH5 = 0xE2;    /* PCA 0 MODULE 5 CAPTURE/COMPARE - HIGH BYTE   */
sfr XBR1     = 0xE2;    /* CROSSBAR CONFIGURATION REGISTER 1            */
sfr XBR2     = 0xE3;    /* CROSSBAR CONFIGURATION REGISTER 2            */
sfr XBR3     = 0xE4;    /* CROSSBAR CONFIGURATION REGISTER 3            */
sfr EIE1     = 0xE6;    /* EXTERNAL INTERRUPT ENABLE 1                  */
sfr EIE2     = 0xE7;    /* EXTERNAL INTERRUPT ENABLE 2                  */
sfr ADC0CN   = 0xE8;    /* ADC 0 CONTROL                                */	
sfr ADC2CN   = 0xE8;    /* ADC 2 CONTROL                                */
sfr P6       = 0xE8;    /* PORT 6                                       */
sfr PCA0CPL2 = 0xE9;    /* PCA 0 MODULE 2 CAPTURE/COMPARE - LOW BYTE    */
sfr PCA0CPH2 = 0xEA;    /* PCA 0 MODULE 2 CAPTURE/COMPARE - HIGH BYTE   */
sfr PCA0CPL3 = 0xEB;    /* PCA 0 MODULE 3 CAPTURE/COMPARE - LOW BYTE    */
sfr PCA0CPH3 = 0xEC;    /* PCA 0 MODULE 3 CAPTURE/COMPARE - HIGH BYTE   */
sfr PCA0CPL4 = 0xED;    /* PCA 0 MODULE 4 CAPTURE/COMPARE - LOW BYTE    */
sfr PCA0CPH4 = 0xEE;    /* PCA 0 MODULE 4 CAPTURE/COMPARE - HIGH BYTE   */
sfr RSTSRC   = 0xEF;    /* RESET SOURCE                                 */
sfr B        = 0xF0;    /* B REGISTER                                   */
sfr EIP1     = 0xF6;    /* EXTERNAL INTERRUPT PRIORITY REGISTER 1       */
sfr EIP2     = 0xF7;    /* EXTERNAL INTERRUPT PRIORITY REGISTER 2       */
sfr SPI0CN   = 0xF8;    /* SPI 0 CONTROL                                */	
sfr CAN0CN   = 0xF8;    /* CAN 0 CONTROL                                */	
sfr P7       = 0xF8;    /* PORT 7                                       */
sfr PCA0L    = 0xF9;    /* PCA 0 TIMER - LOW BYTE                       */
sfr PCA0H    = 0xFA;    /* PCA 0 TIMER - HIGH BYTE                      */
sfr PCA0CPL0 = 0xFB;    /* PCA 0 MODULE 0 CAPTURE/COMPARE - LOW BYTE    */
sfr PCA0CPH0 = 0xFC;    /* PCA 0 MODULE 0 CAPTURE/COMPARE - HIGH BYTE   */
sfr PCA0CPL1 = 0xFD;    /* PCA 0 MODULE 1 CAPTURE/COMPARE - LOW BYTE    */
sfr PCA0CPH1 = 0xFE;    /* PCA 0 MODULE 1 CAPTURE/COMPARE - HIGH BYTE   */
sfr WDTCN    = 0xFF;    /* WATCHDOG TIMER CONTROL                       */
	

/*  BIT Registers  */

/*  TCON  0x88 */
sbit TF1   = TCON ^ 7;              /* TIMER 1 OVERFLOW FLAG      */
sbit TR1   = TCON ^ 6;              /* TIMER 1 ON/OFF CONTROL     */
sbit TF0   = TCON ^ 5;              /* TIMER 0 OVERFLOW FLAG      */
sbit TR0   = TCON ^ 4;              /* TIMER 0 ON/OFF CONTROL     */
sbit IE1   = TCON ^ 3;              /* EXT. INTERRUPT 1 EDGE FLAG */
sbit IT1   = TCON ^ 2;              /* EXT. INTERRUPT 1 TYPE      */
sbit IE0   = TCON ^ 1;              /* EXT. INTERRUPT 0 EDGE FLAG */
sbit IT0   = TCON ^ 0;              /* EXT. INTERRUPT 0 TYPE      */

/*  CPT0CN  0x88 */
sbit CP0EN   = CPT0CN ^ 7;          /* COMPARATOR 0 ENABLE                 */
sbit CP0OUT  = CPT0CN ^ 6;          /* COMPARATOR 0 OUTPUT                 */
sbit CP0RIF  = CPT0CN ^ 5;          /* COMPARATOR 0 RISING EDGE INTERRUPT  */
sbit CP0FIF  = CPT0CN ^ 4;          /* COMPARATOR 0 FALLING EDGE INTERRUPT */
sbit CP0HYP1 = CPT0CN ^ 3;          /* COMPARATOR 0 POSITIVE HYSTERESIS 1  */
sbit CP0HYP0 = CPT0CN ^ 2;          /* COMPARATOR 0 POSITIVE HYSTERESIS 0  */
sbit CP0HYN1 = CPT0CN ^ 1;          /* COMPARATOR 0 NEGATIVE HYSTERESIS 1  */
sbit CP0HYN0 = CPT0CN ^ 0;          /* COMPARATOR 0 NEGATIVE HYSTERESIS 0  */

/*  CPT1CN  0x88 */
sbit CP1EN   = CPT1CN ^ 7;          /* COMPARATOR 1 ENABLE                 */
sbit CP1OUT  = CPT1CN ^ 6;          /* COMPARATOR 1 OUTPUT                 */
sbit CP1RIF  = CPT1CN ^ 5;          /* COMPARATOR 1 RISING EDGE INTERRUPT  */
sbit CP1FIF  = CPT1CN ^ 4;          /* COMPARATOR 1 FALLING EDGE INTERRUPT */
sbit CP1HYP1 = CPT1CN ^ 3;          /* COMPARATOR 1 POSITIVE HYSTERESIS 1  */
sbit CP1HYP0 = CPT1CN ^ 2;          /* COMPARATOR 1 POSITIVE HYSTERESIS 0  */
sbit CP1HYN1 = CPT1CN ^ 1;          /* COMPARATOR 1 NEGATIVE HYSTERESIS 1  */
sbit CP1HYN0 = CPT1CN ^ 0;          /* COMPARATOR 1 NEGATIVE HYSTERESIS 0  */

/*  CPT2CN  0x88 */
sbit CP2EN   = CPT2CN ^ 7;          /* COMPARATOR 2 ENABLE                 */
sbit CP2OUT  = CPT2CN ^ 6;          /* COMPARATOR 2 OUTPUT                 */
sbit CP2RIF  = CPT2CN ^ 5;          /* COMPARATOR 2 RISING EDGE INTERRUPT  */
sbit CP2FIF  = CPT2CN ^ 4;          /* COMPARATOR 2 FALLING EDGE INTERRUPT */
sbit CP2HYP1 = CPT2CN ^ 3;          /* COMPARATOR 2 POSITIVE HYSTERESIS 1  */
sbit CP2HYP0 = CPT2CN ^ 2;          /* COMPARATOR 2 POSITIVE HYSTERESIS 0  */
sbit CP2HYN1 = CPT2CN ^ 1;          /* COMPARATOR 2 NEGATIVE HYSTERESIS 1  */
sbit CP2HYN0 = CPT2CN ^ 0;          /* COMPARATOR 2 NEGATIVE HYSTERESIS 0  */

/*  SCON0  0x98 */
sbit SM00 = SCON0 ^ 7;              /* UART 0 MODE 0            */
sbit SM10 = SCON0 ^ 6;              /* UART 0 MODE 1            */
sbit SM20 = SCON0 ^ 5;              /* UART 0 MCE               */
sbit REN0 = SCON0 ^ 4;              /* UART 0 RX ENABLE         */
sbit TB80 = SCON0 ^ 3;              /* UART 0 TX BIT 8          */
sbit RB80 = SCON0 ^ 2;              /* UART 0 RX BIT 8          */
sbit TI0  = SCON0 ^ 1;              /* UART 0 TX INTERRUPT FLAG */
sbit RI0  = SCON0 ^ 0;              /* UART 0 RX INTERRUPT FLAG */

/*  SCON1  0x98 */
sbit S0MODE = SCON1 ^ 7;            /* UART 1 MODE              */	
sbit MCE1   = SCON1 ^ 5;            /* UART 1 MCE               */
sbit REN1   = SCON1 ^ 4;            /* UART 1 RX ENABLE         */
sbit TB81   = SCON1 ^ 3;            /* UART 1 TX BIT 8          */
sbit RB81   = SCON1 ^ 2;            /* UART 1 RX BIT 8          */
sbit TI1    = SCON1 ^ 1;            /* UART 1 TX INTERRUPT FLAG */
sbit RI1    = SCON1 ^ 0;            /* UART 1 RX INTERRUPT FLAG */

/*  IE  0xA8 */
sbit EA    = IE ^ 7;                /* GLOBAL INTERRUPT ENABLE      */	
sbit ET2   = IE ^ 5;                /* TIMER 2 INTERRUPT ENABLE     */
sbit ES0   = IE ^ 4;                /* UART0 INTERRUPT ENABLE       */
sbit ET1   = IE ^ 3;                /* TIMER 1 INTERRUPT ENABLE     */
sbit EX1   = IE ^ 2;                /* EXTERNAL INTERRUPT 1 ENABLE  */
sbit ET0   = IE ^ 1;                /* TIMER 0 INTERRUPT ENABLE     */
sbit EX0   = IE ^ 0;                /* EXTERNAL INTERRUPT 0 ENABLE  */

/*  IP  0xB8 */
sbit PT2   = IP ^ 5;                /* TIMER 2 PRIORITY					*/	
sbit PS    = IP ^ 4;                /* SERIAL PORT PRIORITY				*/
sbit PT1   = IP ^ 3;                /* TIMER 1 PRIORITY					*/
sbit PX1   = IP ^ 2;                /* EXTERNAL INTERRUPT 1 PRIORITY	*/
sbit PT0   = IP ^ 1;                /* TIMER 0 PRIORITY					*/
sbit PX0   = IP ^ 0;                /* EXTERNAL INTERRUPT 0 PRIORITY	*/		

/* SMB0CN 0xC0 */
sbit BUSY   = SMB0CN ^ 7;           /* SMBUS 0 BUSY                    */
sbit ENSMB  = SMB0CN ^ 6;           /* SMBUS 0 ENABLE                  */
sbit STA    = SMB0CN ^ 5;           /* SMBUS 0 START FLAG              */
sbit STO    = SMB0CN ^ 4;           /* SMBUS 0 STOP FLAG               */
sbit SI     = SMB0CN ^ 3;           /* SMBUS 0 INTERRUPT PENDING FLAG  */
sbit AA     = SMB0CN ^ 2;           /* SMBUS 0 ASSERT/ACKNOWLEDGE FLAG */
sbit SMBFTE = SMB0CN ^ 1;           /* SMBUS 0 FREE TIMER ENABLE       */
sbit SMBTOE = SMB0CN ^ 0;           /* SMBUS 0 TIMEOUT ENABLE          */

/* CAN0STA 0xC0 */
sbit BOFF   = CAN0STA ^ 7;          /* Bus Off Status                  */
sbit EWARN  = CAN0STA ^ 6;          /* Warning Status                  */ 
sbit EPASS  = CAN0STA ^ 5;          /* Error Passive                   */
sbit RXOK   = CAN0STA ^ 4;          /* Received Message Successfully   */
sbit TXOK   = CAN0STA ^ 3;          /* Transmit a Message Successfully */
sbit LEC2   = CAN0STA ^ 2;          /* Last error code bit 2           */
sbit LEC1   = CAN0STA ^ 1;          /* Last error code bit 1           */
sbit LEC0   = CAN0STA ^ 0;          /* Last error code bit            */

/*  TMR2CN  0xC8 */
sbit TF2   = TMR2CN ^ 7;            /* TIMER 2 OVERFLOW FLAG        */
sbit EXF2  = TMR2CN ^ 6;            /* TIMER 2 EXTERNAL FLAG        */
sbit EXEN2 = TMR2CN ^ 3;            /* TIMER 2 EXTERNAL ENABLE FLAG */	
sbit TR2   = TMR2CN ^ 2;            /* TIMER 2 ON/OFF CONTROL       */
sbit CT2   = TMR2CN ^ 1;            /* TIMER 2 COUNTER SELECT       */
sbit CPRL2 = TMR2CN ^ 0;            /* TIMER 2 CAPTURE SELECT       */

/*  TMR3CN  0xC8 */
sbit TF3   = TMR3CN ^ 7;            /* TIMER 3 OVERFLOW FLAG        */
sbit EXF3  = TMR3CN ^ 6;            /* TIMER 3 EXTERNAL FLAG        */
sbit EXEN3 = TMR3CN ^ 3;            /* TIMER 3 EXTERNAL ENABLE FLAG */	
sbit TR3   = TMR3CN ^ 2;            /* TIMER 3 ON/OFF CONTROL       */
sbit CT3   = TMR3CN ^ 1;            /* TIMER 3 COUNTER SELECT       */
sbit CPRL3 = TMR3CN ^ 0;            /* TIMER 3 CAPTURE SELECT       */

/*  TMR4CN  0xC8 */
sbit TF4   = TMR4CN ^ 7;            /* TIMER 4 OVERFLOW FLAG        */
sbit EXF4  = TMR4CN ^ 6;            /* TIMER 4 EXTERNAL FLAG        */
sbit EXEN4 = TMR4CN ^ 3;            /* TIMER 4 EXTERNAL ENABLE FLAG */	
sbit TR4   = TMR4CN ^ 2;            /* TIMER 4 ON/OFF CONTROL       */
sbit CT4   = TMR4CN ^ 1;            /* TIMER 4 COUNTER SELECT       */
sbit CPRL4 = TMR4CN ^ 0;            /* TIMER 4 CAPTURE SELECT       */

/*  PSW 0xD0 */
sbit CY  = PSW ^ 7;                 /* CARRY FLAG              */	
sbit AC  = PSW ^ 6;                 /* AUXILIARY CARRY FLAG    */
sbit F0  = PSW ^ 5;                 /* USER FLAG 0             */
sbit RS1 = PSW ^ 4;                 /* REGISTER BANK SELECT 1  */
sbit RS0 = PSW ^ 3;                 /* REGISTER BANK SELECT 0  */
sbit OV  = PSW ^ 2;                 /* OVERFLOW FLAG           */
sbit F1  = PSW ^ 1;                 /* USER FLAG 1             */
sbit P   = PSW ^ 0;                 /* ACCUMULATOR PARITY FLAG */

/* PCA0CN 0xD8 */
sbit CF   = PCA0CN ^ 7;             /* PCA 0 COUNTER OVERFLOW FLAG   */
sbit CR   = PCA0CN ^ 6;             /* PCA 0 COUNTER RUN CONTROL BIT */
sbit CCF5 = PCA0CN ^ 5;             /* PCA 0 MODULE 5 INTERRUPT FLAG */
sbit CCF4 = PCA0CN ^ 4;             /* PCA 0 MODULE 4 INTERRUPT FLAG */
sbit CCF3 = PCA0CN ^ 3;             /* PCA 0 MODULE 3 INTERRUPT FLAG */
sbit CCF2 = PCA0CN ^ 2;             /* PCA 0 MODULE 2 INTERRUPT FLAG */
sbit CCF1 = PCA0CN ^ 1;             /* PCA 0 MODULE 1 INTERRUPT FLAG */
sbit CCF0 = PCA0CN ^ 0;             /* PCA 0 MODULE 0 INTERRUPT FLAG */


/* ADC0CN 0xE8 */
sbit AD0EN   = ADC0CN ^ 7;          /* ADC 0 ENABLE                   */
sbit AD0TM   = ADC0CN ^ 6;          /* ADC 0 TRACK MODE               */
sbit AD0INT  = ADC0CN ^ 5;          /* ADC 0 EOC INTERRUPT FLAG       */
sbit AD0BUSY = ADC0CN ^ 4;          /* ADC 0 BUSY FLAG                */
sbit AD0CM1  = ADC0CN ^ 3;          /* ADC 0 CONVERT START MODE BIT 1 */
sbit AD0CM0  = ADC0CN ^ 2;          /* ADC 0 CONVERT START MODE BIT 0 */
sbit AD0WINT = ADC0CN ^ 1;          /* ADC 0 WINDOW INTERRUPT FLAG    */


/* ADC2CN 0xE8 */
sbit AD2EN   = ADC2CN ^ 7;          /* ADC 2 ENABLE                   */
sbit AD2TM   = ADC2CN ^ 6;          /* ADC 2 TRACK MODE               */
sbit AD2INT  = ADC2CN ^ 5;          /* ADC 2 EOC INTERRUPT FLAG       */
sbit AD2BUSY = ADC2CN ^ 4;          /* ADC 2 BUSY FLAG                */
sbit AD2WINT = ADC2CN ^ 3;          /* ADC 2 WINDOW INTERRUPT FLAG    */
sbit AD2CM2  = ADC2CN ^ 2;          /* ADC 2 CONVERT START MODE BIT 2 */
sbit AD2CM1  = ADC2CN ^ 1;          /* ADC 2 CONVERT START MODE BIT 1 */
sbit AD2CM0  = ADC2CN ^ 0;          /* ADC 2 CONVERT START MODE BIT 0 */

/* SPI0CN 0xF8 */
sbit SPIF   = SPI0CN ^ 7;           /* SPI 0 INTERRUPT FLAG          */
sbit WCOL   = SPI0CN ^ 6;           /* SPI 0 WRITE COLLISION FLAG    */
sbit MODF   = SPI0CN ^ 5;           /* SPI 0 MODE FAULT FLAG         */
sbit RXOVRN = SPI0CN ^ 4;           /* SPI 0 RX OVERRUN FLAG         */
sbit NSSMD1 = SPI0CN ^ 3;			/* SPI 0 SLAVE SELECT MODE BIT 1 */
sbit NSSMD0 = SPI0CN ^ 2;			/* SPI 0 SLAVE SELECT MODE BIT 0 */
sbit TXBMT  = SPI0CN ^ 1;           /* SPI 0 TX BUFFER EMPTY         */
sbit SPIEN  = SPI0CN ^ 0;           /* SPI 0 SPI ENABLE              */			

/* CAN0CN 0xF8 */
sbit CANINIT = CAN0CN ^ 0;         /* CAN Initialization bit */
sbit CANIE   = CAN0CN ^ 1;         /* CAN Module Interrupt Enable Bit */
sbit CANSIE  = CAN0CN ^ 2;         /* CAN Status change Interrupt Enable Bit */
sbit CANEIE  = CAN0CN ^ 3;         /* CAN Module Error Interrupt Enable Bit */
sbit CANIF   = CAN0CN ^ 4;         /* CAN Module Interrupt Flag */
sbit CANDAR  = CAN0CN ^ 5;         /* CAN Disable Automatic Retransmission bit */
sbit CANCCE  = CAN0CN ^ 6;         /* CAN Configuration Change Enable bit */
sbit CANTEST = CAN0CN ^ 7;         /* CAN Test Mode Enable bit */



/* SFR PAGE DEFINITIONS */
#define  CONFIG_PAGE       0x0F     /* SYSTEM AND PORT CONFIGURATION PAGE */
#define  LEGACY_PAGE       0x00     /* LEGACY SFR PAGE                    */
#define  TIMER01_PAGE      0x00     /* TIMER 0 AND TIMER 1                */
#define  CPT0_PAGE         0x01     /* COMPARATOR 0                       */
#define  CPT1_PAGE         0x02     /* COMPARATOR 1                       */
#define  CPT2_PAGE         0x03     /* COMPARATOR 2                       */
#define  UART0_PAGE        0x00     /* UART 0                             */
#define  UART1_PAGE        0x01     /* UART 1                             */
#define  SPI0_PAGE         0x00     /* SPI 0                              */
#define  EMI0_PAGE         0x00     /* EXTERNAL MEMORY INTERFACE          */
#define  ADC0_PAGE         0x00     /* ADC 0                              */
#define  ADC2_PAGE         0x02     /* ADC 2                              */
#define  SMB0_PAGE         0x00     /* SMBUS 0                            */
#define  TMR2_PAGE         0x00     /* TIMER 2                            */
#define  TMR3_PAGE         0x01     /* TIMER 3                            */
#define  TMR4_PAGE         0x02     /* TIMER 4                            */
#define  DAC0_PAGE         0x00     /* DAC 0                              */
#define  DAC1_PAGE         0x01     /* DAC 1                              */
#define  PCA0_PAGE         0x00     /* PCA 0                              */
#define  CAN0_PAGE         0x01     /* CAN 0                              */

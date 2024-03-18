/*--------------------------------------------------------------------------
C8051F010.H

Header file for Cygnal C8051F018/019
Copyright (c)2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __C8051F010_H__
#define __C8051F010_H__

/*  BYTE Registers  */
sfr ACC       = 0xE0;       /* Accumulator */
sfr ADC0CF    = 0xBC;       /* ADC Configuration */
sfr ADC0CN    = 0xE8;       /* ADC Control */
sfr ADC0GTH   = 0xC5;       /* ADC Greater-Than Data Word (High Byte) */
sfr ADC0GTL   = 0xC4;       /* ADC Greater-Than Data Word (Low Byte) */
sfr ADC0H     = 0xBF;       /* ADC Data Word (High Byte) */
sfr ADC0L     = 0xBE;       /* ADC Data Word (Low Byte) */
sfr ADC0LTH   = 0xC7;       /* ADC Less-Than Data Word (High Byte) */
sfr ADC0LTL   = 0xC6;       /* ADC Less-Than Data Word (Low Byte) */
sfr AMX0CF    = 0xBA;       /* ADC MUX Configuration */
sfr AMX0SL    = 0xBB;       /* ADC MUX Channel Selection */
sfr B         = 0xF0;       /* B Register */
sfr CKCON     = 0x8E;       /* Clock Control 1*/
sfr CPT0CN    = 0x9E;       /* Comparator 0 Control */
sfr CPT1CN    = 0x9F;       /* Comparator 1 Control */
sfr DPH       = 0x83;       /* Data Pointer (High Byte) */
sfr DPL       = 0x82;       /* Data Pointer (Low Byte) */
sfr EIE1      = 0xE6;       /* Extended Interrupt Enable 1 */
sfr EIE2      = 0xE7;       /* Extended Interrupt Enable 2 */
sfr EIP1      = 0xF6;       /* External Interrupt Priority 1 */
sfr EIP2      = 0xF7;       /* External Interrupt Priority 2 */
sfr EMI0CN    = 0xAF;       /* External Memory Interface Control */
sfr FLACL     = 0xB7;       /* Flash Access Limit */
sfr FLSCL     = 0xB6;       /* Flash Memory Timing Prescaler */
sfr IE        = 0xA8;       /* Interrupt Enable */
sfr IP        = 0xB8;       /* Interrupt Priority Control */
sfr OSCICN    = 0xB2;       /* Internal Oscillator Control */
sfr OSCXCN    = 0xB1;       /* External Oscillator Control */
sfr P0        = 0x80;       /* Port 0 Latch */
sfr P1        = 0x90;       /* Port 1 Latch */
sfr P2        = 0xA0;       /* Port 2 Latch */
sfr P3        = 0xB0;       /* Port 3 Latch */
sfr PCA0CN    = 0xD8;       /* Programmable Counter Array 0 Control 1*/
sfr PCA0CPH0  = 0xFA;       /* PCA Capture Module 0 Data Word (High Byte) 1*/
sfr PCA0CPH1  = 0xFB;       /* PCA Capture Module 1 Data Word (High Byte) 1*/
sfr PCA0CPH2  = 0xFC;       /* PCA Capture Module 2 Data Word (High Byte) 1*/
sfr PCA0CPH3  = 0xFD;       /* PCA Capture Module 3 Data Word (High Byte) 1*/
sfr PCA0CPH4  = 0xFE;       /* PCA Capture Module 4 Data Word (High Byte) 1*/
sfr PCA0CPL0  = 0xEA;       /* PCA Capture Module 0 Data Word (Low Byte) 1*/
sfr PCA0CPL1  = 0xEB;       /* PCA Capture Module 1 Data Word (Low Byte) 1*/
sfr PCA0CPL2  = 0xEC;       /* PCA Capture Module 2 Data Word (Low Byte) 1*/
sfr PCA0CPL3  = 0xED;       /* PCA Capture Module 3 Data Word (Low Byte) 1*/
sfr PCA0CPL4  = 0xEE;       /* PCA Capture Module 4 Data Word (Low Byte) 1*/
sfr PCA0CPM0  = 0xDA;       /* Programmable Counter Array 0 Capture/Compare 0 1*/
sfr PCA0CPM1  = 0xDB;       /* Programmable Counter Array 0 Capture/Compare 1 1*/
sfr PCA0CPM2  = 0xDC;       /* Programmable Counter Array 0 Capture/Compare 2 1*/
sfr PCA0CPM3  = 0xDD;       /* Programmable Counter Array 0 Capture/Compare 3 1*/
sfr PCA0CPM4  = 0xDE;       /* Programmable Counter Array 0 Capture/Compare 4 1*/
sfr PCA0H     = 0xF9;       /* PCA Counter/Timer Data Word (High Byte) 1*/
sfr PCA0L     = 0xE9;       /* PCA Counter/Timer Data Word (Low Byte) 1*/
sfr PCA0MD    = 0xD9;       /* Programmable Counter Array 0 Mode 1*/
sfr PCON      = 0x87;       /* Power Control */
sfr PRT0CF    = 0xA4;       /* Port 0 Configuration */
sfr PRT1CF    = 0xA5;       /* Port 1 Configuration */
sfr PRT1IF    = 0xAD;       /* Port 1 Interrupt Flags */
sfr PRT2CF    = 0xA6;       /* Port 2 Configuration */
sfr PRT3CF    = 0xA7;       /* Port 3 Configuration */
sfr PSCTL     = 0x8F;       /* Program Store RW Control */
sfr PSW       = 0xD0;       /* Program Status Word */
sfr RCAP2H    = 0xCB;       /* Counter/Timer 2 Capture (High Byte) 1*/
sfr RCAP2L    = 0xCA;       /* Counter/Timer 2 Capture (Low Byte) 1*/
sfr REF0CN    = 0xD1;       /* Voltage Reference Control Register */
sfr RSTSRC    = 0xEF;       /* Reset Source Register */
sfr SBUF      = 0x99;       /* Serial Data Buffer (UART) 1*/
sfr SCON      = 0x98;       /* Serial Port Control (UART) 1*/
sfr SMB0ADR   = 0xC3;       /* SMBus 0 Address 1*/
sfr SMB0CN    = 0xC0;       /* SMBus 0 Control */
sfr SMB0CR    = 0xCF;       /* SMBus 0 Clock Rate */
sfr SMB0DAT   = 0xC2;       /* SMBus 0 Data 1*/
sfr SMB0STA   = 0xC1;       /* SMBus 0 Status 1*/
sfr SP        = 0x81;       /* Stack Pointer */
sfr SPI0CFG   = 0x9A;       /* Serial Peripheral Interface Configuration 1*/
sfr SPI0CKR   = 0x9D;       /* SPI Clock Rate 1*/
sfr SPI0CN    = 0xF8;       /* SPI Bus Control 1*/
sfr SPI0DAT   = 0x9B;       /* SPI Port 1Data 1*/
sfr T2CON     = 0xC8;       /* Counter/Timer 2 Control 1*/
sfr TCON      = 0x88;       /* Counter/Timer Control 1*/
sfr TH0       = 0x8C;       /* Counter/Timer 0 Data Word (High Byte) 1*/
sfr TH1       = 0x8D;       /* Counter/Timer 1 Data Word (High Byte) 1*/
sfr TH2       = 0xCD;       /* Counter/Timer 2 Data Word (High Byte) 1*/
sfr TL0       = 0x8A;       /* Counter/Timer 0 Data Word (Low Byte) 1*/
sfr TL1       = 0x8B;       /* Counter/Timer 1 Data Word (Low Byte) 1*/
sfr TL2       = 0xCC;       /* Counter/Timer 2 Data Word (Low Byte) 1*/
sfr TMOD      = 0x89;       /* Counter/Timer Mode 1*/
sfr TMR3CN    = 0x91;       /* Timer 3 Control 1*/
sfr TMR3H     = 0x95;       /* Timer 3 High 1*/
sfr TMR3L     = 0x94;       /* Timer 3 Low 1*/
sfr TMR3RLH   = 0x93;       /* Timer 3 Reload High 1*/
sfr TMR3RLL   = 0x92;       /* Timer 3 Reload Low 1*/
sfr WDTCN     = 0xFF;       /* Watchdog Timer Control */
sfr XBR0      = 0xE1;       /* Port I/O Crossbar Configuration 1 */
sfr XBR1      = 0xE2;       /* Port I/O Crossbar Configuration 2 */
sfr XBR2      = 0xE3;       /* Port I/O Crossbar Configuration 3 */


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

/*  SCON  0x98 */
sbit SM0   = SCON ^ 7;              /* SERIAL MODE CONTROL BIT 0           */       
sbit SM1   = SCON ^ 6;              /* SERIAL MODE CONTROL BIT 1           */
sbit SM2   = SCON ^ 5;              /* MULTIPROCESSOR COMMUNICATION ENABLE */
sbit REN   = SCON ^ 4;              /* RECEIVE ENABLE                      */
sbit TB8   = SCON ^ 3;              /* TRANSMIT BIT 8                      */
sbit RB8   = SCON ^ 2;              /* RECEIVE BIT 8                       */
sbit TI    = SCON ^ 1;              /* TRANSMIT INTERRUPT FLAG             */
sbit RI    = SCON ^ 0;              /* RECEIVE INTERRUPT FLAG              */

/*  IE  0xA8 */
sbit EA    = IE ^ 7;                /* GLOBAL INTERRUPT ENABLE      */       
sbit ET2   = IE ^ 5;                /* TIMER 2 INTERRUPT ENABLE     */
sbit ES    = IE ^ 4;                /* SERIAL PORT INTERRUPT ENABLE */
sbit ET1   = IE ^ 3;                /* TIMER 1 INTERRUPT ENABLE     */
sbit EX1   = IE ^ 2;                /* EXTERNAL INTERRUPT 1 ENABLE  */
sbit ET0   = IE ^ 1;                /* TIMER 0 INTERRUPT ENABLE     */
sbit EX0   = IE ^ 0;                /* EXTERNAL INTERRUPT 0 ENABLE  */

/*  IP  0xB8 */
sbit PT2   = IP ^ 5;                /* TIMER 2 PRIORITY                             */     
sbit PS    = IP ^ 4;                /* SERIAL PORT PRIORITY                         */
sbit PT1   = IP ^ 3;                /* TIMER 1 PRIORITY                             */
sbit PX1   = IP ^ 2;                /* EXTERNAL INTERRUPT 1 PRIORITY  */
sbit PT0   = IP ^ 1;                /* TIMER 0 PRIORITY                             */
sbit PX0   = IP ^ 0;                /* EXTERNAL INTERRUPT 0 PRIORITY  */            

/* SMB0CN 0xC0 */
sbit BUSY     =   SMB0CN ^ 7;       /* SMBUS 0 BUSY                    */
sbit ENSMB    =   SMB0CN ^ 6;       /* SMBUS 0 ENABLE                  */
sbit STA      =   SMB0CN ^ 5;       /* SMBUS 0 START FLAG              */
sbit STO      =   SMB0CN ^ 4;       /* SMBUS 0 STOP FLAG               */
sbit SI       =   SMB0CN ^ 3;       /* SMBUS 0 INTERRUPT PENDING FLAG  */
sbit AA       =   SMB0CN ^ 2;       /* SMBUS 0 ASSERT/ACKNOWLEDGE FLAG */
sbit SMBFTE   =   SMB0CN ^ 1;       /* SMBUS 0 FREE TIMER ENABLE       */
sbit SMBTOE   =   SMB0CN ^ 0;       /* SMBUS 0 TIMEOUT ENABLE          */

/*  T2CON  0xC8 */
sbit TF2   = T2CON ^ 7;             /* TIMER 2 OVERFLOW FLAG        */
sbit EXF2  = T2CON ^ 6;             /* EXTERNAL FLAG                */
sbit RCLK  = T2CON ^ 5;             /* RECEIVE CLOCK FLAG           */
sbit TCLK  = T2CON ^ 4;             /* TRANSMIT CLOCK FLAG          */
sbit EXEN2 = T2CON ^ 3;             /* TIMER 2 EXTERNAL ENABLE FLAG */       
sbit TR2   = T2CON ^ 2;             /* TIMER 2 ON/OFF CONTROL       */
sbit CT2   = T2CON ^ 1;             /* TIMER OR COUNTER SELECT      */
sbit CPRL2 = T2CON ^ 0;             /* CAPTURE OR RELOAD SELECT     */

/*  PSW  */
sbit CY    = PSW ^ 7;               /* CARRY FLAG              */     
sbit AC    = PSW ^ 6;               /* AUXILIARY CARRY FLAG    */
sbit F0    = PSW ^ 5;               /* USER FLAG 0             */
sbit RS1   = PSW ^ 4;               /* REGISTER BANK SELECT 1  */
sbit RS0   = PSW ^ 3;               /* REGISTER BANK SELECT 0  */
sbit OV    = PSW ^ 2;               /* OVERFLOW FLAG           */
sbit F1    = PSW ^ 1;               /* USER FLAG 1             */
sbit P     = PSW ^ 0;               /* ACCUMULATOR PARITY FLAG */

/* PCA0CN D8H */
sbit CF    =   PCA0CN ^ 7;          /* PCA 0 COUNTER OVERFLOW FLAG   */
sbit CR    =   PCA0CN ^ 6;          /* PCA 0 COUNTER RUN CONTROL BIT */
sbit CCF4  =   PCA0CN ^ 4;          /* PCA 0 MODULE 4 INTERRUPT FLAG */
sbit CCF3  =   PCA0CN ^ 3;          /* PCA 0 MODULE 3 INTERRUPT FLAG */
sbit CCF2  =   PCA0CN ^ 2;          /* PCA 0 MODULE 2 INTERRUPT FLAG */
sbit CCF1  =   PCA0CN ^ 1;          /* PCA 0 MODULE 1 INTERRUPT FLAG */
sbit CCF0  =   PCA0CN ^ 0;          /* PCA 0 MODULE 0 INTERRUPT FLAG */

/* ADC0CN E8H */
sbit ADCEN    =   ADC0CN ^ 7;       /* ADC 0 ENABLE                              */
sbit ADCTM    =   ADC0CN ^ 6;       /* ADC 0 TRACK MODE                          */
sbit ADCINT   =   ADC0CN ^ 5;       /* ADC 0 CONVERISION COMPLETE INTERRUPT FLAG */
sbit ADBUSY   =   ADC0CN ^ 4;       /* ADC 0 BUSY FLAG                           */
sbit ADSTM1   =   ADC0CN ^ 3;       /* ADC 0 START OF CONVERSION MODE BIT 1      */
sbit ADSTM0   =   ADC0CN ^ 2;       /* ADC 0 START OF CONVERSION MODE BIT 0      */
sbit ADWINT   =   ADC0CN ^ 1;       /* ADC 0 WINDOW COMPARE INTERRUPT FLAG       */
sbit ADLJST   =   ADC0CN ^ 0;       /* ADC 0 RIGHT JUSTIFY DATA BIT              */

/* SPI0CN F8H */
sbit SPIF     =   SPI0CN ^ 7;       /* SPI 0 INTERRUPT FLAG                  */
sbit WCOL     =   SPI0CN ^ 6;       /* SPI 0 WRITE COLLISION FLAG     */
sbit MODF     =   SPI0CN ^ 5;       /* SPI 0 MODE FAULT FLAG          */
sbit RXOVRN   =   SPI0CN ^ 4;       /* SPI 0 RX OVERRUN FLAG          */
sbit TXBSY    =   SPI0CN ^ 3;       /* SPI 0 TX BUSY FLAG                    */
sbit SLVSEL   =   SPI0CN ^ 2;       /* SPI 0 SLAVE SELECT                    */
sbit MSTEN    =   SPI0CN ^ 1;       /* SPI 0 MASTER ENABLE                   */
sbit SPIEN    =   SPI0CN ^ 0;       /* SPI 0 SPI ENABLE                      */     

#endif              

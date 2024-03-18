/*-------------------------------------------------------------------------
AT8XC5122.h    

Header file for Atmel AT8XC5122
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/
#ifndef _AT8XC5122_H_

#define _AT8XC5122_H_

#define Sfr(x, y)       sfr x = y
#define Sbit(x, y, z)   sbit x = y ^ z
#define Sfr16(x,y)      sfr16 x = y

/*----------------------------- C51 CORE -----------------------------------*/

Sfr (SP      , 0x81);           //Stack Pointer
Sfr16 (DPTR  , 0x82);           //16 bit Data Pointer 
Sfr (DPL     , 0x82);           //Data Pointer Low byte
Sfr (DPH     , 0x83);           //Data Pointer High Byte

Sfr (PSW     , 0xD0);           //Program Status Word
Sbit (CY     , PSW   , 7);      //Carry Flag
Sbit (AC     , PSW   , 6);      //Auxilary Carry Flag
Sbit (F0     , PSW   , 5);      //Flag 0 available to the user for general purpose
Sbit (RS1    , PSW   , 4);      //Register Bank Selector bit 1
Sbit (RS0    , PSW   , 3);      //Register Bank Selector bit 0
Sbit (OV     , PSW   , 2);      //Overflow Bit
Sbit (F1     , PSW   , 1);      //General Purpose Flag
Sbit (P      , PSW   , 0);      //Parity Bit

Sfr (A       , 0xE0);           //Accumulator
Sfr (ACC     , 0xE0);           //Accumulator
Sfr (B       , 0xF0);           //B register

/*----------------------- SYSTEM CONFIGURATION -----------------------------*/

Sfr (CKSEL   , 0x85);           //Clock Selection
Sfr (PCON    , 0x87);           //Power Control
Sfr (AUXR    , 0x8E);           //Auxilary Register 0
Sfr (CKCON0  , 0x8F);           //Clock Control Register 0
Sfr (CKRL    , 0x97);           //Clock Reload
Sfr (AUXR1   , 0xA2);           //Auxilary Register 1
Sfr (PLLCON  , 0xA3);           //Phase Lock Loop Control
Sfr (PLLDIV  , 0xA4);           //Phase Lock Loop Divider
Sfr (CKCON1  , 0xAF);           //Clock Control Register 0
Sfr (RCON    , 0xD1);           //Memory Selection

/*---------------------------- INTERRUPTS ----------------------------------*/

Sfr (ISEL    , 0xA1);           //Interrupt Enable Control

Sfr (IEN0    , 0xA8);           //Interrupt Enable Control 0
Sbit (EA     , IEN0  , 7);      //Global Interrupts Enable/Disable Bit
Sbit (ES     , IEN0  , 4);      //Serial Port Interrupt Enable/Disable Bit
Sbit (ET1    , IEN0  , 3);      //Timer 1 Overflow Interrupt Enable/Disable Bit
Sbit (EX1    , IEN0  , 2);      //External Interrupt 1 Enable/Disable Bit
Sbit (ET0    , IEN0  , 1);      //Timer 0 Overflow Interrupt Enable/Disable Bit
Sbit (EX0    , IEN0  , 0);      //External Interrupt 0 Enable/Disable Bit

Sfr (IPH0    , 0xB7);           //Interrupt Priority Control High 0

Sfr (IPL0    , 0xB8);           //Interrupt Priority Control Low  0
Sbit (PSL    , IPL0  , 4);      //Serial Port Interrupt Priority LSB
Sbit (PT1L   , IPL0  , 3);      //Timer 1 Overflow Interrupt Priority LSB
Sbit (PX1L   , IPL0  , 2);      //External Interrupt 1 Priority LSB
Sbit (PT0L   , IPL0  , 1);      //Timer 0 Overflow Interrupt Priority LSB
Sbit (PX0L   , IPL0  , 0);      //External Interrupt 0 Priority LSB

Sfr (IEN1    , 0xB1);           //Interrupt Enable Control 1
Sfr (IPL1    , 0xB2);           //Interrupt Priority Control Low  1
Sfr (IPH1    , 0xB3);           //Interrupt Priority Control High 1

/*------------------------------- PORTS -----------------------------------*/

Sfr (P0      , 0x80);           //Port 0
Sbit (P0_7   , P0    , 7);
Sbit (P0_6   , P0    , 6);
Sbit (P0_5   , P0    , 5);
Sbit (P0_4   , P0    , 4);
Sbit (P0_3   , P0    , 3);
Sbit (P0_2   , P0    , 2);
Sbit (P0_1   , P0    , 1);
Sbit (P0_0   , P0    , 0);

Sfr (PMOD1   , 0x84);           //Port Mode Register 1

Sfr (P1      , 0x90);           //Port 1
Sbit (P1_7   , P1    , 7);
Sbit (P1_6   , P1    , 6);
Sbit (P1_2   , P1    , 2);
Sbit (CCLK1  , P1    , 7);      //Alternate Card Clock
Sbit (CPRES  , P1    , 2);      //Smart Card Presence

Sfr (PMOD0   , 0x91);           //Port Mode Register 0

Sfr (P2      , 0xA0);           //Port 2
Sbit (P2_7   , P2    , 7);
Sbit (P2_6   , P2    , 6);
Sbit (P2_5   , P2    , 5);
Sbit (P2_4   , P2    , 4);
Sbit (P2_3   , P2    , 3);
Sbit (P2_2   , P2    , 2);
Sbit (P2_1   , P2    , 1);
Sbit (P2_0   , P2    , 0);

Sfr (P3      , 0xB0);           //Port 3
Sbit (P3_7   , P3    , 7);
Sbit (P3_6   , P3    , 6);
Sbit (P3_5   , P3    , 5);
Sbit (P3_4   , P3    , 4);
Sbit (P3_3   , P3    , 3);
Sbit (P3_2   , P3    , 2);
Sbit (P3_1   , P3    , 1);
Sbit (P3_0   , P3    , 0);
Sbit (T1     , P3    , 5);      //External Event 1
Sbit (T0     , P3    , 4);      //External Event 0
Sbit (INT1   , P3    , 3);      //External Interrupt 1
Sbit (INT0   , P3    , 2);      //External Interrupt 0
Sbit (TXD    , P3    , 1);      //UART Transmit Port
Sbit (RXD    , P3    , 0);      //UART Receive Port
Sbit (CRST1  , P3    , 5);      //Alternate Card Reset
Sbit (CIO1   , P3    , 4);      //Alternate Card I/O
Sbit (LED3   , P3    , 7);      //Led Number 3
Sbit (LED2   , P3    , 6);      //Led Number 2
Sbit (LED1   , P3    , 4);      //Led Number 1
Sbit (LED0   , P3    , 2);      //Led Number 0

Sfr (P4      , 0xC0);           //Port 4
Sbit (P4_7   , P4    , 7);
Sbit (P4_6   , P4    , 6);
Sbit (P4_5   , P4    , 5);
Sbit (P4_4   , P4    , 4);
Sbit (P4_3   , P4    , 3);
Sbit (P4_2   , P4    , 2);
Sbit (P4_1   , P4    , 1);
Sbit (P4_0   , P4    , 0);
Sbit (LED5   , P4    , 4);      //Led Number 5
Sbit (LED4   , P4    , 3);      //Led Number 4

Sfr (P5      , 0xE8);           //Port 5
Sbit (P5_7   , P5    , 7);
Sbit (P5_6   , P5    , 6);
Sbit (P5_5   , P5    , 5);
Sbit (P5_4   , P5    , 4);
Sbit (P5_3   , P5    , 3);
Sbit (P5_2   , P5    , 2);
Sbit (P5_1   , P5    , 1);
Sbit (P5_0   , P5    , 0);
Sbit (KB7    , P5    , 7);      //Keyboard Input Line 7
Sbit (KB6    , P5    , 6);      //Keyboard Input Line 6
Sbit (KB5    , P5    , 5);      //Keyboard Input Line 5
Sbit (KB4    , P5    , 4);      //Keyboard Input Line 4
Sbit (KB3    , P5    , 3);      //Keyboard Input Line 3
Sbit (KB2    , P5    , 2);      //Keyboard Input Line 2
Sbit (KB1    , P5    , 1);      //Keyboard Input Line 1
Sbit (KB0    , P5    , 0);      //Keyboard Input Line 0


/*------------------------------- TIMERS -----------------------------------*/

Sfr (TCON    , 0x88);           //Timer-Counter 0 and 1 Control
Sbit (TF1    , TCON  , 7);      //Timer 1 Overflow Flag
Sbit (TR1    , TCON  , 6);      //Timer 1 Run Control Bit
Sbit (TF0    , TCON  , 5);      //Timer 0 Overflow Flag
Sbit (TR0    , TCON  , 4);      //Timer 0 Run Control Bit
Sbit (IE1    , TCON  , 3);      //Interrupt 1 Edge Flag
Sbit (IT1    , TCON  , 2);      //Interrupt 1 Type Control Bit
Sbit (IE0    , TCON  , 1);      //Interrupt 0 Edge Flag
Sbit (IT0    , TCON  , 0);      //Interrupt 0 Type Control Bit

Sfr (TMOD    , 0x89);           //Timer-Counter 0 and 1 Configuration
Sfr (TL0     , 0x8A);           //Timer-Counter 0 Low Byte
Sfr (TL1     , 0x8B);           //Timer-Counter 1 Low Byte
Sfr (TH0     , 0x8C);           //Timer-Counter 0 High Byte
Sfr (TH1     , 0x8D);           //Timer-Counter 1 High Byte

/*------------------------------ WATCHDOG --------------------------------*/

Sfr (WDTRST  , 0xA6);           //WatchDog Timer Reset
Sfr (WDTPRG  , 0xA7);           //WatchDog Timer Program

/*--------------------------- USB CONTROLLER -----------------------------*/

Sfr (UFNUML  , 0xBA);           //USB Frame Number Low
Sfr (UFNUMH  , 0xBB);           //USB Frame Number Low
Sfr (USBCON  , 0xBC);           //USB Global Control
Sfr (USBINT  , 0xBD);           //USB Global Interrupt
Sfr (USBIEN  , 0xBE);           //USB Global Interrupt Enable
Sfr (UEPIEN  , 0xC2);           //USB Endpoint Interrupt Enable
Sfr (USBADDR , 0xC6);           //USB Address
Sfr (UEPNUM  , 0xC7);           //USB Endpoint Number
Sfr (UEPSTAX , 0xCE);           //USB Endpoint X Status
Sfr (UEPDATX , 0xCF);           //USB Endpoint X Fifo Data
Sfr (UEPCONX , 0xD4);           //USB Endpoint X Control
Sfr (UEPRST  , 0xD5);           //USB Endpoint Reset
Sfr (UBYCTX  , 0xE2);           //USB Byte Counter Low (EPX)
Sfr (UEPINT  , 0xF8);           //USB Endpoint Interrupt
Sbit (EP6INT , UEPINT, 6);
Sbit (EP5INT , UEPINT, 5);
Sbit (EP4INT , UEPINT, 4);
Sbit (EP3INT , UEPINT, 3);
Sbit (EP2INT , UEPINT, 2);
Sbit (EP1INT , UEPINT, 1);
Sbit (EP0INT , UEPINT, 0);

/*------------------------------- SCIB ----------------------------------*/

Sfr (SCTBUF  , 0xAA);           //Smart Card Transmit Buffer (Write Only)			
Sfr (SCRBUF  , 0xAA);           //Smart Card Receive Buffer (read Only)
Sfr (SCSR    , 0xAB);           //Smart Card Selection Register
Sfr (SCCON   , 0xAC);           //Smart Card Interface Contacts
Sfr (SCETU0  , 0xAC);           //Smart Card ETU Register 0
Sfr (SCISR   , 0xAD);           //Smart Card UART Interface Status
Sfr (SCETU1  , 0xAD);           //Smart Card ETU Register 1
Sfr (SCIIR   , 0xAE);           //Smart Card UART Interrupt Identification
Sfr (SCIER   , 0xAE);           //Smart Card UART Interrupt Enable
Sfr (SCWT0   , 0xB4);           //Smart Card Character-Block Waiting Time Register 0
Sfr (SCGT0   , 0xB4);           //Smart Card Transmit Guard Time Register 0
Sfr (SCWT1   , 0xB5);           //Smart Card Character-Block Waiting Time Register 1
Sfr (SCGT1   , 0xB5);           //Smart Card Transmit Guard Time Register 1
Sfr (SCWT2   , 0xB6);           //Smart Card Character-Block Waiting Time Register 2
Sfr (SCICR   , 0xB6);           //Smart Card Interface Control
Sfr (DCCKPS  , 0xBF);           //DC/DC Converter Reload Register
Sfr (SCWT3   , 0xC1);           //Smart Card Character-Block Waiting Time Register 3
Sfr (SCICLK  , 0xC1);           //Smart Card Clock Prescaler

/*------------------------------- UART ---------------------------------*/

Sfr (SCON    , 0x98);           //UART Interface Control
Sbit (SM0    , SCON  , 7);      //Serial Port Mode Bit 0		
Sbit (FE     , SCON  , 7);      //Framing error Bit
Sbit (SM1    , SCON  , 6);      //Serial Port Mode Bit 1
Sbit (SM2    , SCON  , 5);      //Serial Port Mode Bit 2
Sbit (REN    , SCON  , 4);      //Reception Enable Bit
Sbit (TB8    , SCON  , 3);      //Transmitter bit 8
Sbit (RB8    , SCON  , 2);      //Receiver Bit 8
Sbit (TI     , SCON  , 1);      //Transmit Interrupt Flag
Sbit (RI     , SCON  , 0);      //Receive Interrupt Flag

Sfr (SBUF    , 0x99);           //UART Data Buffer
Sfr (SADDR   , 0xA9);           //Slave Address
Sfr (SADEN   , 0xB9);           //Slave Address Mask

/*------------------------ BAUD RATE GENERATOR -------------------------*/

Sfr (BRL     , 0x9A);           //Baud Rate Relaod
Sfr (BDRCON  , 0x9B);           //Baud Rate Control

/*----------------------------- KEYBOARD -------------------------------*/

Sfr (KBF     , 0x9E);           //Keyboard Flag Register
Sfr (KBE     , 0x9D);           //Keyboard Input Enable Register
Sfr (KBLS    , 0x9C);           //Keyboard Level Selector

/*-------------------------- SPI CONTROLLER ----------------------------*/

Sfr (SPCON   , 0xC3);           //Serial Peripheral Control
Sfr (SPSTA   , 0xC4);           //Serial Peripheral Status-Control
Sfr (SPDAT   , 0xC5);           //Serial Peripheral Data

/*-------------------------------- LED ---------------------------------*/

Sfr (LEDCON0 , 0xF1);           //LED control 0
Sfr (LEDCON1 , 0xE1);           //LED control 1

/*------------------------------ PCMCIA --------------------------------*/

Sfr (PCMADDR , 0xE4);           //PCMCIA Interface Address
Sfr (PCMDATA , 0xE5);           //PCMCIA Interface Data
Sfr (PCMTYPE , 0xE6);           //PCMCIA Interface Configuration
Sfr (PCMINT  , 0xE7);           //PCMCIA Interface Interrupt Enable

/*------------------------------ DECODER -------------------------------*/

Sfr (DECEN  , 0xE4);            //DECODER Interface Enable
Sfr (DECPAG , 0xE5);            //DECODER Interface Page
Sfr (DECONF , 0xE6);            //DECODER Interface Configuration

/*------------------------- EMULATION INTERFACE ------------------------*/

Sfr (EMUCON  , 0xDF);           //EMULATION Interface Control
Sfr (BKPCL   , 0xEF);           //Breakpoint PC Address Low
Sfr (BKPCH   , 0xF7);           //Breakpoint PC Address High
Sfr (ICON    , 0xFF);           //ICE Control Register

#endif  /* _AT8XC5122_H_ */

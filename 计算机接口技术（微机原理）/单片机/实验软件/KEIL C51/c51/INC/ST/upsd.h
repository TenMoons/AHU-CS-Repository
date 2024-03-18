/*--------------------------------------------------------------------------
UPSD.H

Header file for STMicroelectronics PSM uPSD3XXX microcontroller memory system.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __UPSD_H__
#define __UPSD_H__

/* ------------------------------ */
/* Standard 8051 MCU Registers    */
/* ------------------------------ */
// sfr P0    = 0x80;		// Port 0 - Always used for External Memory Access
sfr P1    = 0x90;		// Port 1
// sfr P2    = 0xA0;		// Port 2 - Always used for External Memory Access
sfr P3    = 0xB0;		// Port 3
sfr PSW   = 0xD0;		// Program Status Word
sfr ACC   = 0xE0;		// Accumulator
sfr B     = 0xF0;		// Register B
sfr SP    = 0x81;		// Stack Pointer
sfr DPL   = 0x82;		// Data Pointer low byte
sfr DPH   = 0x83;		// Data Pointer high byt
sfr PCON  = 0x87;		// MCU Power Control Register
sfr TCON  = 0x88;		// Timer / Counter Control
sfr TMOD  = 0x89;		// Timer / Counter Mode
sfr TL0   = 0x8A;		// Timer 0 low byte
sfr TL1   = 0x8B;		// Timer 1 low byte
sfr TH0   = 0x8C;		// Timer 0 high byte
sfr TH1   = 0x8D;		// Timer 1 high byte
sfr IE    = 0xA8;		// Interrupt Enable (main)
sfr IP    = 0xB8;		// Interrupt Priority (main) 
sfr SCON  = 0x98;		// UART0 Serial Control
sfr SBUF  = 0x99;		// UART0 Serial Buffer

/* ------------------------ */
/*  Common 8052 Extensions  */
/* ------------------------ */
sfr T2CON  = 0xC8;	// Timer 2 Control
sfr T2MOD  = 0xC9;	// Timer 2 Mode 
sfr RCAP2L = 0xCA;	// Timer 2 Reload low byte
sfr RCAP2H = 0xCB;	// Timer 2 Reload high byte
sfr TL2    = 0xCC;	// Timer 2 low byte
sfr TH2    = 0xCD;	// Timer 2 high byte

/* ------------------------ */
/*  UPSD 3200 Extensions    */
/* ------------------------ */
sfr P4 =0xC0;		// New port 4
sfr P1SFS    = 0x91;	// Port 1 I/O select
sfr P3SFS    = 0x93;	// Port 3 I/O select
sfr P4SFS    = 0x94;	// Port 4 I/O select
// --- ADC SFRs ---
sfr ASCL    = 0x95;	// ADC Clock Prescaler 8-bit
sfr ADAT   = 0x96;	// ADC Data Value
sfr ACON   = 0x97;	// ADC Control Register
// --- UART2 SFRS ----
sfr SCON2     = 0x9A;	// UART2 Serial Control
sfr SBUF2    = 0x9B;	// UART2 Serial Buffer
// --- PWM SFRs -----
sfr PWMCON   = 0xA1;	// PWM Polarity Control
sfr PWM0  = 0xA2;		// PWM0 Duty Cycle
sfr PWM1  = 0xA3;		// PWM1 Duty Cycle
sfr PWM2  = 0xA4;		// PWM2 Duty Cycle
sfr PWM3  = 0xA5;		// PWM3 Duty Cycle
sfr PWM4H  = 0xAA;	// PWM4 High Duty Cycle
sfr PWM4L  = 0xAB;	// PWM4 Low Duty Cycle
sfr PSCL0L   = 0xB1;	// 8bit PWM Prescaler low
sfr PSCL0H   = 0xB2;	// 8bit PWM Prescaler high
sfr PSCL1L   = 0xB3;	// 16bit PWM Prescaler low
sfr PSCL1H   = 0xB4;	// 16bit PWM Prescaler high
// --- WDT SFRs ---
sfr WDRST   = 0xA6;	// Watch Dog Reset
sfr WDKEY   = 0xAE;	// Watch Dog Key Enable
// --- INTERRUPT 2 SFRs ---
sfr IEA   = 0xA7;		// Interrupt Enable (2nd)
sfr IPA    = 0xB7;	// Interrupt Priority (2nd)
// --- I2C S1/S2 & DDC SFRs ---
sfr S1SETUP  = 0xD1;	// DDC-I2C S1 Setup Control
sfr S2SETUP  = 0xD2;	// I2C S2 Setup Control
sfr RAMBUF    = 0xD4;	// DDC Ram Buffer Access
sfr DDCDAT    = 0xD5;	// DDC I2C Xmit register
sfr DDCADR    = 0xD6;	// DDC Memory Address Pointer
sfr DDCCON    = 0xD7;	// DDC Control Register
sfr S1CON    = 0xD8;	// DDC I2C S1 Control
sfr S1STA   = 0xD9;	// DDC I2C Status
sfr S1DAT   = 0xDA;	// DDC I2C Data Hold Register
sfr S1ADR     = 0xDB;   // DDC I2C Bus Address
sfr S2CON    = 0xDC;	// I2C S2 Control
sfr S2STA   = 0xDD;	// I2C S2 Status
sfr S2DAT   = 0xDE;	// I2C S2 Data Hold Register
sfr S2ADR  = 0xDF;	// I2C S2 Bus Address
// --- USB SFRs ---
sfr USCL  = 0xE1;		// USB Clock 8bit prescaler register
sfr UDT1  = 0xE6;		// USB End Point 1 Data Register
sfr UDT0   = 0xE7;	// USB End Point 0 Data register
sfr UISTA   = 0xE8;	// USB Interrupt Status
sfr UIEN   = 0xE9;	// USB Interrupt Enable
sfr UCON0   = 0xEA;	// USB End Point 0 Control
sfr UCON1    = 0xEB;	// USB End Point 1 Control
sfr UCON2    = 0xEC;	// USB End Point 2 Control
sfr USTA  = 0xED;		// USB End Point 0 Status
sfr UADR  = 0xEE;		// USB Address Register
sfr UDR0  = 0xEF;		// USB Endpoint 0 Data Receive

/* --------------------------- */
/*  Common 8051 BIT Registers  */
/* --------------------------- */
/*  PSW  */
sbit CY    = PSW^7;	// Carry
sbit AC    = PSW^6;	// 
sbit F0    = PSW^5;
sbit RS1   = PSW^4;
sbit RS0   = PSW^3;
sbit OV    = PSW^2;	// Overflow
sbit P     = PSW^0; 	//8052 only

/*  TCON  */
sbit TF1   = TCON^7;
sbit TR1   = TCON^6;
sbit TF0   = TCON^5;
sbit TR0   = TCON^4;
sbit IE1   = TCON^3;
sbit IT1   = TCON^2;
sbit IE0   = TCON^1;
sbit IT0   = TCON^0;

/*  IE  */
sbit EA    = IE^7;	// Enable All interrupts
sbit ET2   = IE^5; 	// Timer 2
sbit ES    = IE^4;	// Usart 0	
sbit ET1   = IE^3;	// Timer 1
sbit EX1   = IE^2;	// External Int1
sbit ET0   = IE^1;	// Timer 0
sbit EX0   = IE^0;	// External Int0

/*  IP  */
sbit PT2   = IP^5;	// Timer 2
sbit PS    = IP^4;	// Usart 0
sbit PT1   = IP^3;	// Timer 1
sbit PX1   = IP^2;	// Ext Int1
sbit PT0   = IP^1;	// Timer 0
sbit PX0   = IP^0;	// Ext Int 0

/*    P4   */
sbit PWMCH4   = P4^7;	// PWM4 (16-bit)
sbit PWMCH3   = P4^6;	// PWM3
sbit PWMCH2   = P4^5;	// PMW2
sbit PWMCH1   = P4^4;	// PMW1
sbit PWMCH0   = P4^3;	// PMW0 (8-bit)
sbit DDCVSYNC   = P4^2;	// DDC Vsync input
sbit DDCSCL   = P4^1;	// DDC SCL
sbit DDCSDA   = P4^0;	// DDC SDA

/*  P3  */
sbit I2CSC = P3^7;	// I2C Serial Clock
sbit I2CSD = P3^6;	// I2C Serial Data
sbit T1    = P3^5;	// Timer 1 Input
sbit T0    = P3^4;	// Timer 0 Input
sbit INT1  = P3^3;	// Ext Int 1 / Timer 1 Gate	
sbit INT0  = P3^2;	// Ext Int 0 / Timer 0 Gate
sbit TXD   = P3^1;	// USART0
sbit RXD   = P3^0;	// USART0

/*  SCON  */
sbit SM0   = SCON^7;
sbit SM1   = SCON^6;
sbit SM2   = SCON^5;
sbit REN   = SCON^4;
sbit TB8   = SCON^3;
sbit RB8   = SCON^2;
sbit TI    = SCON^1;
sbit RI    = SCON^0;

/*  P1  */
sbit ADC3  = P1^7;	// ADC Input 3
sbit ADC2  = P1^6;	// ADC Input 2
sbit ADC1  = P1^5;	// ADC Input 1
sbit ADC0  = P1^4;	// ADC Input 0
sbit TXD2  = P1^3;	// USART2
sbit RXD2  = P1^2;	// USART2
sbit T2EX  = P1^1; 	// Timer2 Triger
sbit T2    = P1^0; 	// Timer2 Input
             
/*  T2CON  */
sbit TF2    = T2CON^7;
sbit EXF2   = T2CON^6;
sbit RCLK   = T2CON^5;
sbit TCLK   = T2CON^4;
sbit EXEN2  = T2CON^3;
sbit TR2    = T2CON^2;
sbit C_T2   = T2CON^1;
sbit CP_RL2 = T2CON^0;


/*    PCON   */
//sbit SMOD   = PCON^7;		// Baud Rate bit for USART	
//sbit SMOD2   = PCON^6;	// Baud Rate bit for USART2
//sbit LVREN   = PCON^5;	// Low voltage Reset enable
//sbit UCLK   = PCON^4;		// Reserved
//sbit GF1   = PCON^3;		// General Flag1
//sbit GF0   = PCON^2;		// General Flag0
//sbit PD   = PCON^1;		// Power Down Mode
//sbit IDLE   = PCON^0;		// Idle Mode


 /*    TMOD   */
//sbit GATE1   = TMOD^7;
//sbit C_T1   = TMOD^6;
//sbit M11   = TMOD^5;
//sbit M10   = TMOD^4;
//sbit GATE0   = TMOD^3;
//sbit C_T0   = TMOD^2;
//sbit M01   = TMOD^1;
//sbit M00   = TMOD^0;


/* -------------------- */
/* BIT REGISTERS FOR UPSD */
/* -------------------- */

/*    P1SFS - controls I/O features on P1   */
//sbit P1S7   = P1SFS^7;	// ADC3
//sbit P1S6   = P1SFS^6;	// ADC2
//sbit P1S5   = P1SFS^5;	// ADC1
//sbit P1S4   = P1SFS^4;	// ADC0
//sbit P1S3   = P1SFS^3;	// UART2 TX
//sbit P1S2   = P1SFS^2;	// UART2 RX
//sbit P1S1   = P1SFS^1;	// Timer2 Triger
//sbit P1S0   = P1SFS^0;	// Timer2

/*    P3SFS   */
//sbit P3S7   = P3SFS^7;	// I2C Clock
//sbit P3S6   = P3SFS^6;	// I2C Data
// Remaining bits set using standard 8051 method when IP is enabled.

/*    P4SFS   */
//sbit P4S7   = P4SFS^7;	// PWM4 (16-bit)
//sbit P4S6   = P4SFS^6;	// PWM3
//sbit P4S5   = P4SFS^5;	// PMW2
//sbit P4S4   = P4SFS^4;	// PMW1
//sbit P4S3   = P4SFS^3;	// PMW0 (8-bit)
//sbit P4S2   = P4SFS^2;	// DDC Vsync input
//sbit P4S1   = P4SFS^1;	// DDC SCL
//sbit P4S0   = P4SFS^0;	// DDC SDA

/*    ACON   */
//sbit P1S7   = ACON^7;
//sbit P1S6   = ACON^6;
//sbit ADEN   = ACON^5;
//sbit P1S4   = ACON^4;
//sbit ADS1   = ACON^3;
//sbit ADS0   = ACON^2;
//sbit ADST   = ACON^1;
//sbit ADSF   = ACON^0;

/*  SCON 2  */
//sbit SM02   = SCON2^7;
//sbit SM12   = SCON2^6;
//sbit SM22   = SCON2^5;
//sbit REN2   = SCON2^4;
//sbit TB82   = SCON2^3;
//sbit RB82   = SCON2^2;
//sbit TI2    = SCON2^1;
//sbit RI2    = SCON2^0;

/*    PWMCON   */
//sbit PWML   = PWMCON^7;
//sbit PWMP   = PWMCON^6;
//sbit PWME   = PWMCON^5;
//sbit CFG4   = PWMCON^4;
//sbit CFG3   = PWMCON^3;
//sbit CFG2   = PWMCON^2;
//sbit CFG1   = PWMCON^1;
//sbit CFG0   = PWMCON^0;

 /*  IEA  */
//sbit EDDC    = IEA^7;
//sbit ET2   = IEA^5; 
//sbit ES2    = IEA^4;
//sbit ES2   = IEA^3;
//sbit EX1   = IEA^2;
//sbit EI2C   = IEA^1;
//sbit EUSB   = IEA^0;

/*  IPA  */
//sbit PDDC   = IPA^7;
//sbit PS2    = IPA^5;
//sbit PT1   = IPA^3;
//sbit PX1   = IPA^2;
//sbit PI2C   = IPA^1;
//sbit PUSB   = IPA^0;

/*  DDCCON  */
//sbit EDDC    = DDCCON^7;
//sbit EX_DAT   = DDCCON^6; 
//sbit SWENB   = DDCCON^5; 
//sbit DDC_AX    = DDCCON^4;
//sbit DDC_INT   = DDCCON^3;
//sbit DDC1EN   = DDCCON^2;
//sbit SWHINT   = DDCCON^1;
//sbit M0   = DDCCON^0;

/*  S1SETUP  */
//sbit SETUP1    = S1SETUP^7;
/*  S2SETUP  */
//sbit SETUP2    = S2SETUP^7;

/*  S1CON  */
sbit CR2    = S1CON^7;
sbit ENI1   = S1CON^6; 
sbit STA   = S1CON^5; 
sbit STO    = S1CON^4;
sbit ADDR   = S1CON^3;
sbit AA   = S1CON^2;
sbit CR1   = S1CON^1;
sbit CR0   = S1CON^0;

/*  S1STA  */
//sbit GC    = S1STA^7;
//sbit STOP   = S1STA^6; 
//sbit INTR   = S1STA^5; 
//sbit TX_MD    = S1STA^4;
//sbit BBUSY   = S1STA^3;
//sbit BLOST   = S1STA^2;
//sbit ACK_R   = S1STA^1;
//sbit SLV   = S1STA^0;

/*  S2CON  */
//sbit CR2    = S2CON^7;
//sbit EN1   = S2CON^6; 
//sbit STA   = S2CON^5; 
//sbit STO    = S2CON^4;
//sbit ADDR   = S2CON^3;
//sbit AA   = S2CON^2;
//sbit CR1   = S2CON^1;
//sbit CR0   = S2CON^0;

/*  S2STA  */
//sbit GC    = S2STA^7;
//sbit STOP   = S2STA^6; 
//sbit INTR   = S2STA^5; 
//sbit TX_MD    = S2STA^4;
//sbit BBUSY   = S2STA^3;
//sbit BLOST   = S2STA^2;
//sbit ACK_R   = S2STA^1;
//sbit SLV   = S2STA^0;

/*  UISTA  */
sbit SUSPND    = UISTA^7;
//sbit STOP   = UISTA^6; 
sbit RSTF   = UISTA^5; 
sbit TXD0F    = UISTA^4;
sbit RXD0F   = UISTA^3;
sbit RXD1F   = UISTA^2;
sbit EOPF   = UISTA^1;
sbit RESUMF   = UISTA^0;

/*  UIEN  */
//sbit SUSPNDIE    = UIEN^7;
//sbit STOP   = UIEN^6; 
//sbit RSTF   = UIEN^5; 
//sbit TXD0IE    = UIEN^4;
//sbit RXD0IE   = UIEN^3;
//sbit RXD1IE   = UIEN^2;
//sbit EOPIE   = UIEN^1;
//sbit RESUMIE   = UIEN^0;

/*  UCON0  */
//sbit TSEQ0    = UCON0^7;
//sbit STALL0   = UCON0^6; 
//sbit TX0E   = UCON0^5; 
//sbit RX0E    = UCON0^4;
//sbit TP0SIZ3   = UCON0^3;
//sbit TP0SIZ2   = UCON0^2;
//sbit TP0SIZ1   = UCON0^1;
//sbit TP0SIZ0   = UCON0^0;

/*  UCON1  */
//sbit TSEQ1    = UCON1^7;
//sbit EP12SEL   = UCON1^6; 
//sbit TX0E   = UCON1^5; 
//sbit FRESUM    = UCON1^4;
//sbit TP1SIZ3   = UCON1^3;
//sbit TP1SIZ2   = UCON1^2;
//sbit TP1SIZ1   = UCON1^1;
//sbit TP1SIZ0   = UCON1^0;

/*  UCON2  */
//sbit TSEQ1    = UCON2^7;
//sbit EP12SEL   = UCON2^6; 
//sbit TX0E   = UCON2^5; 
//sbit SOUT    = UCON2^4;
//sbit EP2E   = UCON2^3;
//sbit EP1E   = UCON2^2;
//sbit STALL2   = UCON2^1;
//sbit STALL1   = UCON2^0;

/*  USTA  */
//sbit RSEQ    = USTA^7;
//sbit SETUP   = USTA^6; 
//sbit IN   = USTA^5; 
//sbit OUT    = USTA^4;
//sbit RP0SIZ3   = USTA^3;
//sbit RP0SIZ2   = USTA^2;
//sbit RP0SIZ1   = USTA^1;
//sbit RP0SIZ0   = USTA^0;

/*  UADR  */
//sbit USBEN    = UADR^7;
//sbit UADDR6   = UADR^6; 
//sbit UADDR5   = UADR^5; 
//sbit UADDR4   = UADR^4;
//sbit UADDR3   = UADR^3;
//sbit UADDR2   = UADR^2;
//sbit UADDR1   = UADR^1;
//sbit UADDR0   = UADR^0;

#endif


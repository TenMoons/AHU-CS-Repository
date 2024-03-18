/*--------------------------------------------------------------------------
AT89S8252

Header file for the Atmel AT89S8252.
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __AT89S8252_H__
#define __AT89S8252_H__

/*------------------------------------------------
Byte Registers

Note: Only Registers located on addresses that
are evenly divisible by 8 are bit addressable.
All other registers use bit masks.
------------------------------------------------*/
sfr P0      = 0x80;     /* Port 0 */
sfr SP      = 0x81;     /* Stack Pointer */
sfr DPL     = 0x82;     /* Data Pointer Low Byte */
sfr DP0L    = 0x82;     /* Alternate Definition */
sfr DPH     = 0x83;     /* Data Pointer High Byte */
sfr DP0H    = 0x83;     /* Alternate Definition */
sfr DP1L    = 0x84;     /* Data Pointer 1 Low Byte , different to AT89C52 */
sfr DP1H    = 0x85;     /* Data Pointer 1 High Byte , different to AT89C52 */
sfr SPDR    = 0x86;     /* SPI Data Register , different to AT89C52 */
sfr PCON    = 0x87;     /* Power Control Register */

sfr TCON    = 0x88;     /* Timer Control Register */
sfr TMOD    = 0x89;     /* Timer Mode Control Register */
sfr TL0     = 0x8A;     /* Timer 0 Low Byte */
sfr TL1     = 0x8B;     /* Timer 1 Low Byte */
sfr TH0     = 0x8C;     /* Timer 0 High Byte */
sfr TH1     = 0x8D;     /* Timer 1 High Byte */

sfr P1      = 0x90;     /* Port 1 */
sfr WMCON   = 0x96;     /* Watchdog and Memory Control Register */
sfr SCON    = 0x98;     /* Serial Port Control */
sfr SBUF    = 0x99;     /* Serial Port Buffer */

sfr P2      = 0xA0;     /* Port 2 */
sfr IE      = 0xA8;     /* Interrupt Enable Register 0 */
sfr SPSR    = 0xAA;     /* SPI Status Register , different to AT89C52 */

sfr P3      = 0xB0;     /* Port 3 */
sfr IP      = 0xB8;     /* Interrupt Priority Register */

sfr T2CON   = 0xC8;     /* Timer 2 Control */
sfr T2MOD	= 0xC9;     /* Timer 2 Mode */
sfr RCAP2L  = 0xCA;     /* Timer 2 Capture Low Byte */
sfr RCAP2H  = 0xCB;     /* Timer 2 Capture High Byte */
sfr TL2     = 0xCC;     /* Timer 2 Low Byte */
sfr TH2     = 0xCD;     /* Timer 2 High Byte */

sfr PSW     = 0xD0;     /* Program Status Word */
sfr SPCR    = 0xD5;     /* SPI Control Register , different to AT89C52 */

sfr ACC     = 0xE0;     /* Accumulator */

sfr B       = 0xF0;     /* B Register */

/*------------------------------------------------
P0 (0x80) Bit Registers
------------------------------------------------*/
sbit P0_0 = 0x80;
sbit P0_1 = 0x81;
sbit P0_2 = 0x82;
sbit P0_3 = 0x83;
sbit P0_4 = 0x84;
sbit P0_5 = 0x85;
sbit P0_6 = 0x86;
sbit P0_7 = 0x87;

/*------------------------------------------------
PCON (0x87) Bit Values
------------------------------------------------*/
#define IDL_    0x01    /* Idle Mode Bit: 1=Active */

#define STOP_   0x02    /* Stop Mode Bit: 1=Active */
#define PD_     0x02    /* Alternate definition */

#define GF0_    0x04    /* General Purpose Flag 0 */
#define GF1_    0x08    /* General Purpose Flag 1 */
#define SMOD_   0x80    /* Double Baud Rate Bit for use with Timer 1 */

/*------------------------------------------------
TCON (0x88) Bit Registers
------------------------------------------------*/
sbit IT0  = 0x88;       /* Interrupt 0 Type Control Bit */
sbit IE0  = 0x89;       /* Interrupt 0 Edge Flag */
sbit IT1  = 0x8A;       /* Interrupt 1 Type Control Bit */
sbit IE1  = 0x8B;       /* Interrupt 1 Edge Flag */
sbit TR0  = 0x8C;       /* Timer 0 Run Control Bit */
sbit TF0  = 0x8D;       /* Timer 0 Overflow Flag */
sbit TR1  = 0x8E;       /* Timer 1 Run Control Bit */
sbit TF1  = 0x8F;       /* Timer 1 Overflow Flag */

/*------------------------------------------------
TMOD (0x89) Bit Values
------------------------------------------------*/
#define T0_M0_   0x01   /* Timer 0 Mode Bit 0 */
#define T0_M1_   0x02   /* Timer 0 Mode Bit 1 */
#define T0_CT_   0x04   /* Timer 0 Counter/Timer Select: 0=Counter, 1=Timer */
#define T0_GATE_ 0x08   /* Timer 0 Gate Control */

#define T1_M0_   0x10   /* Timer 1 Mode Bit 0 */
#define T1_M1_   0x20   /* Timer 1 Mode Bit 1 */
#define T1_CT_   0x40   /* Timer 1 Counter/Timer Select: 0=Counter, 1=Timer */
#define T1_GATE_ 0x80   /* Timer 1 Gate Control */

#define T1_MASK_ 0xF0   /* Timer 0 Mask */
#define T0_MASK_ 0x0F   /* Timer 1 Mask */

/*------------------------------------------------
P1 (0x90) Bit Registers
------------------------------------------------*/
sbit P1_0 = 0x90;
sbit P1_1 = 0x91;
sbit P1_2 = 0x92;
sbit P1_3 = 0x93;
sbit P1_4 = 0x94;
sbit P1_5 = 0x95;
sbit P1_6 = 0x96;
sbit P1_7 = 0x97;

sbit T2   = 0x90;       /* External input to Timer/Counter 2, clock out */
sbit T2EX = 0x91;       /* Timer/Counter 2 capture/reload trigger & dir ctl */

sbit SS   = 0x94;       /* SPI: SS - Slave port select input */
sbit MOSI = 0x95;       /* SPI: MOSI - Master data output, slave data input */
sbit MISO = 0x96;       /* SPI: MISO - Master data input, slave data output */
sbit SCK  = 0x97;       /* SPI: SCK - Master clock output, slave clock input */

/*------------------------------------------------
WMCON (0x96) Bit Values
------------------------------------------------*/
#define WDTEN_   0x01

#define WDTRST_  0x02   /* Watchdog Timer Reset and EEPROM Ready,/Busy Flag */
#define EERDY_   0x02   /* Watchdog Timer Reset and EEPROM Ready,/Busy Flag */

#define DPS_     0x04   /* Data Pointer Select: 0=DP0, 1=DP1 */
#define EEMEN_   0x08   /* Internal EEPROM Access Enable: 1=Enabled */
#define EEMWE_   0x10   /* Internal EEPROM Write Enable: 1=Enabled */
#define PS0_     0x20   /* Prescaler bit 0 for the Watchdog Timer */
#define PS1_     0x40   /* Prescaler bit 1 for the Watchdog Timer */
#define PS2_     0x80   /* Prescaler bit 2 for the Watchdog Timer */
                        /* 000 =   16ms Timeout */
                        /* 001 =   32ms Timeout */
                        /* 010 =   64ms Timeout */
                        /* 011 =  128ms Timeout */
                        /* 100 =  256ms Timeout */
                        /* 101 =  512ms Timeout */
                        /* 110 = 1024ms Timeout */
                        /* 111 = 2048ms Timeout */

/*------------------------------------------------
SCON (0x98) Bit Registers
------------------------------------------------*/
sbit RI   = 0x98;       /* Receive Interrupt Flag */
sbit TI   = 0x99;       /* Transmit Interrupt Flag */
sbit RB8  = 0x9A;       /* 9th data bit received */
sbit TB8  = 0x9B;       /* 9th data bit to be transmitted in modes 2 & 3 */
sbit REN  = 0x9C;       /* Receive Enable */
sbit SM2  = 0x9D;       /* Serial Port Mode Bit 2 */
sbit SM1  = 0x9E;       /* Serial Port Mode Bit 1 */
sbit SM0  = 0x9F;       /* Serial Port Mode Bit 0 */

/*------------------------------------------------
P2 (0xA0) Bit Registers
------------------------------------------------*/
sbit P2_0 = 0xA0;
sbit P2_1 = 0xA1;
sbit P2_2 = 0xA2;
sbit P2_3 = 0xA3;
sbit P2_4 = 0xA4;
sbit P2_5 = 0xA5;
sbit P2_6 = 0xA6;
sbit P2_7 = 0xA7;

/*------------------------------------------------
IE (0xA8) Bit Registers
------------------------------------------------*/
sbit EX0  = 0xA8;       /* External Interrupt 0 Enable: 1=Enabled */
sbit ET0  = 0xA9;       /* Timer 0 Interrupt Enable: 1=Enabled */
sbit EX1  = 0xAA;       /* External Interrupt 1 Enable: 1=Enabled */
sbit ET1  = 0xAB;       /* Timer 1 Interrupt Enable: 1=Enabled */
sbit ES   = 0xAC;       /* SPI and UART Interrupt Enable: 1=Enabled */
sbit ET2  = 0xAD;       /* Timer 2 Interrupt Enable: 1=Enabled */

sbit EA   = 0xAF;       /* Global Interrupt Enable: 0=Disable all interrupts */

/*------------------------------------------------
SPSR (0xAA) Bit Values - Reset Value = 0000.0000
------------------------------------------------*/
#define WCOL_   0x40    /* SPI Write Collision Flag: 1=Collision */
#define SPIF_   0x80    /* SPI Interrupt Flag */

/*------------------------------------------------
P3 (0xB0) Bit Registers (Mnemonics & Ports)
------------------------------------------------*/
sbit P3_0 = 0xB0;
sbit P3_1 = 0xB1;
sbit P3_2 = 0xB2;
sbit P3_3 = 0xB3;
sbit P3_4 = 0xB4;
sbit P3_5 = 0xB5;
sbit P3_6 = 0xB6;
sbit P3_7 = 0xB7;

sbit RXD  = 0xB0;       /* Serial data input */
sbit TXD  = 0xB1;       /* Serial data output */
sbit INT0 = 0xB2;       /* External interrupt 0 */
sbit INT1 = 0xB3;       /* External interrupt 1 */
sbit T0   = 0xB4;       /* Timer 0 external input */
sbit T1   = 0xB5;       /* Timer 1 external input */
sbit WR   = 0xB6;       /* External data memory write strobe */
sbit RD   = 0xB7;       /* External data memory read strobe */

/*------------------------------------------------
IP (0xB8) Bit Registers
------------------------------------------------*/
sbit PX0  = 0xB8;       /* External Interrupt 0 Priority Bit */
sbit PT0  = 0xB9;       /* Timer 0 Interrupt Priority Bit */
sbit PX1  = 0xBA;       /* External Interrupt 1 Priority Bit */
sbit PT1  = 0xBB;       /* Timer 1 Interrupt Priority Bit */
sbit PS   = 0xBC;       /* Serial Port Interrupt Priority Bit */   
sbit PT2  = 0xBD;       /* Timer 2 Interrupt Priority Bit */

/*------------------------------------------------
T2CON (0xC8) Bit Registers
------------------------------------------------*/
sbit CP_RL2= 0xC8;      /* 0=Reload, 1=Capture select */
sbit C_T2 = 0xC9;       /* 0=Timer, 1=Counter */
sbit TR2  = 0xCA;       /* 0=Stop timer, 1=Start timer */
sbit EXEN2= 0xCB;       /* Timer 2 external enable */
sbit TCLK = 0xCC;       /* 0=Serial clock uses Timer 1 overflow, 1=Timer 2 */
sbit RCLK = 0xCD;       /* 0=Serial clock uses Timer 1 overflow, 1=Timer 2 */
sbit EXF2 = 0xCE;       /* Timer 2 external flag */
sbit TF2  = 0xCF;       /* Timer 2 overflow flag */

/*------------------------------------------------
T2MOD (0xC9) Bit Values
------------------------------------------------*/
#define DCEN_   0x01    /* 1=Timer 2 can be configured as up/down counter */
#define T2OE_   0x02    /* Timer 2 output enable */

/*------------------------------------------------
PSW (0xD0) Bit Registers
------------------------------------------------*/
sbit P    = 0xD0;       /* Parity Flag */
sbit FL   = 0xD1;       /* User Flag */
sbit OV   = 0xD2;       /* Overflow Flag */
sbit RS0  = 0xD3;       /* Register Bank Select Bit 0 */
sbit RS1  = 0xD4;       /* Register Bank Select Bit 1 */
sbit F0   = 0xD5;       /* User Flag 0 */
sbit AC   = 0xD6;       /* Auxiliary Carry Flag */
sbit CY   = 0xD7;       /* Carry Flag */

/*------------------------------------------------
SPCR (0xD5) Bit Values - Reset Value = 0000.01XX
------------------------------------------------*/
#define SPR0_   0x01    /* SPI Clock Rate Select bit 0 */
#define SPR1_   0x02    /* SPI Clock Rate Select bit 1 */
                        /* 00 = Fosc / 4   */
                        /* 01 = Fosc / 16  */
                        /* 10 = Fosc / 64  */
                        /* 11 = Fosc / 128 */

#define CPHA_   0x04    /* SPI Clock Phase */
#define CPOL_   0x08    /* SPI Clock Polarity */
#define MSTR_   0x10    /* SPI Master/Slave Select: 0=Slave, 1=Master */
#define DORD_   0x20    /* SPI Data Order: 0=MSB First, 1=LSB First */
#define SPE_    0x40    /* SPI Enable: 0=Disabled, 1=Enabled */
#define SPIE_   0x80    /* SPI Interrupt Enable: 0=Disabled, 1=Enabled */

/*------------------------------------------------
Interrupt Vectors:
Interrupt Address = (Number * 8) + 3
------------------------------------------------*/
#define IE0_VECTOR	0  /* 0x03 External Interrupt 0 */
#define TF0_VECTOR	1  /* 0x0B Timer 0 */
#define IE1_VECTOR	2  /* 0x13 External Interrupt 1 */
#define TF1_VECTOR	3  /* 0x1B Timer 1 */
#define SIO_VECTOR	4  /* 0x23 Serial port */

#define TF2_VECTOR	5  /* 0x2B Timer 2 */
#define EX2_VECTOR	5  /* 0x2B External Interrupt 2 */

#endif


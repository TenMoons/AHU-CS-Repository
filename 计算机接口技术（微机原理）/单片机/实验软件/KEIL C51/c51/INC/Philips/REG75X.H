/*------------------------------------------------------------------
REG75x.H

Header file for the Philips 8xC750/751/752 
Copyright (c) 1995-2002 Keil Elektronik GmbH  All rights reserved.

Definition of CPU Type in the main program:

  #define P87C750
  #include <reg75x.h>

  other possible types: 83C750, 87C751, 83C751, 87C752, 83C752 

NOTE:
The Bits IDLE, XSTR and XSTP are named twice in the Philips Data 
Handbook in I2C CONTROL and I2C STATUS SFRs.  Therefore in this Regfile 
they are renamed to _IDLE, _XSTR and _XSTP in the I2CSTA register. 
------------------------------------------------------------------*/

#if defined P87C750
 #define CPUTYPE 750
#endif

#if defined P83C750
 #define CPUTYPE 750
#endif

#if defined P87C751
 #define CPUTYPE 751
#endif

#if defined P83C751
 #define CPUTYPE 751
#endif

#if defined P87C752
 #define CPUTYPE 752
#endif

#if defined P83C752
 #define CPUTYPE 752
#endif

/*  BYTE Register  */
sfr P0   = 0x80;
sfr SP   = 0x81;
sfr DPL  = 0x82;
sfr DPH  = 0x83;
sfr PCON = 0x87;
sfr TCON = 0x88;
sfr TL   = 0x8A;
sfr RTL  = 0x8B;
sfr TH   = 0x8C;
sfr RTH  = 0x8D;

sfr P1   = 0x90;
sfr IE   = 0xA8;
sfr P3   = 0xB0;
sfr PSW  = 0xD0;
sfr ACC  = 0xE0;
sfr B    = 0xF0;

#if CPUTYPE != 750
 sfr I2CFG = 0xD8; /* 8xC751/752 only */
 sfr I2CON = 0x98; /* 8xC751/752 only */
 sfr I2DAT = 0x99; /* 8xC751/752 only */
 sfr I2STA = 0xF8; /* 8xC751/752 only */
#endif

#if CPUTYPE == 752
 sfr ADAT  = 0x84; /* 8xC752 only */
 sfr ADCON = 0xA0; /* 8xC752 only */
 sfr PWENA = 0xFE; /* 8xC752 only */
#endif


/*  BIT Register  */
/*  PSW   */
sbit CY   = PSW^7;
sbit AC   = PSW^6;
sbit F0   = PSW^5;
sbit RS1  = PSW^4;
sbit RS0  = PSW^3;
sbit OV   = PSW^2;
sbit P    = PSW^0;

/*  TCON  */
sbit GATE = TCON^7;
sbit CT   = TCON^6;
sbit TF   = TCON^5;
sbit TR   = TCON^4;
sbit IE0  = TCON^3;
sbit IT0  = TCON^2;
sbit IE1  = TCON^1;
sbit IT1  = TCON^0;

/*  IE   */
sbit EA   = IE^7;

#if CPUTYPE == 752
 sbit EAD  = IE^6; /* 8xC752 only */
 sbit ETI  = IE^5; /* 8xC752 only */
 sbit ES   = IE^4; /* 8xC752 only */
 sbit EPWM = IE^3; /* 8xC752 only */
#endif

#if CPUTYPE == 751
 sbit EI2  = IE^4; /* 8xC751 only */
 sbit ETI  = IE^3; /* 8xC751 only */
#endif

sbit EX1  = IE^2;
sbit ET0  = IE^1;
sbit EX0  = IE^0;


#if CPUTYPE != 750
 /* I2CFG */
 sbit  SLAVEN = I2CFG^7; /* 8xC752/751 */
 sbit  MASTRQ = I2CFG^6; /* 8xC752/751 */
 sbit  CLRTI  = I2CFG^5; /* 8xC752/751 */
 sbit  TIRUN  = I2CFG^4; /* 8xC752/751 */
 sbit  CT1    = I2CFG^1; /* 8xC752/751 */
 sbit  CT0    = I2CFG^0; /* 8xC752/751 */

 /* I2CON/READ */
 sbit  RDAT   = I2CON^7; /* 8xC752/751 */
 sbit  ATN    = I2CON^6; /* 8xC752/751 */
 sbit  DRDY   = I2CON^5; /* 8xC752/751 */
 sbit  ARL    = I2CON^4; /* 8xC752/751 */
 sbit  STR    = I2CON^3; /* 8xC752/751 */
 sbit  STP    = I2CON^2; /* 8xC752/751 */
 sbit  MASTER = I2CON^1; /* 8xC752/751 */

 /* I2CON/WRITE */
 sbit  CXA    = I2CON^7; /* 8xC752/751 */
 sbit  IDLE   = I2CON^6; /* 8xC752/751 */
 sbit  CDR    = I2CON^5; /* 8xC752/751 */
 sbit  CARL   = I2CON^4; /* 8xC752/751 */
 sbit  CSTR   = I2CON^3; /* 8xC752/751 */
 sbit  CSTP   = I2CON^2; /* 8xC752/751 */
 sbit  XSTR   = I2CON^1; /* 8xC752/751 */
 sbit  XSTP   = I2CON^0; /* 8xC752/751 */

 /* I2STA */
 sbit  _IDLE  = I2STA^6; /* 8xC752/751, renamed */
 sbit  XDATA  = I2STA^5; /* 8xC752/751 */
 sbit  XACTV  = I2STA^4; /* 8xC752/751 */
 sbit  MAKSTR = I2STA^3; /* 8xC752/751 */
 sbit  MAKSTP = I2STA^2; /* 8xC752/751 */
 sbit  _XSTR  = I2STA^1; /* 8xC752/751, renamed */
 sbit  _XSTP  = I2STA^0; /* 8xC752/751, renamed */
#endif

#if CPUTYPE == 752
 /* ADAT (8xC752 only) */
 sbit  ENADC = ADAT^5; /* 8xC752 only */
 sbit  ADCI  = ADAT^4; /* 8xC752 only */
 sbit  ADCS  = ADAT^3; /* 8xC752 only */
 sbit  AADR2 = ADAT^2; /* 8xC752 only */
 sbit  AADR1 = ADAT^1; /* 8xC752 only */
 sbit  AADR0 = ADAT^0; /* 8xC752 only */

 /* Port0 */
 sbit   PWM0 = P0^4; /* 8xC752 only */
#endif

#if CPUTYPE != 750
 sbit   SDA  = P0^1; /* 8xC751/752 only */
 sbit   SCL  = P0^0; /* 8xC751/752 only */
#endif

/* Port1 */
sbit   T0   = P1^7;
sbit   INT1 = P1^6;
sbit   INT0 = P1^5;

#if CPUTYPE == 752
 sbit   ADC4 = P1^4; /* 8xC752 only */
 sbit   ADC3 = P1^3; /* 8xC752 only */
 sbit   ADC2 = P1^2; /* 8xC752 only */
 sbit   ADC1 = P1^1; /* 8xC752 only */
 sbit   ADC0 = P1^0; /* 8xC752 only */
#endif

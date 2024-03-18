/*H**************************************************************************
* NAME: at89c5114.h         
* PURPOSE: inlcude file for KEIL 
*****************************************************************************/

#define Sfr(x, y)       sfr x = y
#define Sbit(x, y, z)   sbit x = y^z
#define Sfr16(x,y)      sfr16 x = y


/*----------------------------------------*/
/* Include file for 8051 SFR Definitions  */
/*----------------------------------------*/

/*  BYTE Register  */
Sfr (P0, 0x80);        
Sbit (P0_7, 0x80, 7);
Sbit (P0_6, 0x80, 6);
Sbit (P0_5, 0x80, 5);
Sbit (P0_4, 0x80, 4);
Sbit (P0_3, 0x80, 3);
Sbit (P0_2, 0x80, 2);
Sbit (P0_1, 0x80, 1);
Sbit (P0_0, 0x80, 0);

Sfr (P2, 0xA0); 
Sbit (P2_3, 0xA0, 3);
Sbit (P2_2, 0xA0, 2);
Sbit (P2_1, 0xA0, 1);
Sbit (P2_0, 0xA0, 0);
       
Sfr (P3, 0xB0);        
Sbit (P3_7, 0xB0, 7);
Sbit (P3_6, 0xB0, 6);
Sbit (P3_5, 0xB0, 5);
Sbit (P3_4, 0xB0, 4);
Sbit (P3_3, 0xB0, 3);
Sbit (P3_2, 0xB0, 2);
Sbit (P3_1, 0xB0, 1);
Sbit (P3_0, 0xB0, 0);

Sfr (P3M1, 0xd5);
Sfr (P3M2, 0xe4);

Sfr (P4, 0xC0);        
Sbit (P4_3, 0xC0, 3);
Sbit (P4_2, 0xC0, 2);
Sbit (P4_1, 0xC0, 1);
Sbit (P4_0, 0xC0, 0);

Sfr (P4M1, 0xd6);

/* P2 */
Sbit (RD, 0xB0, 7);
Sbit (WR, 0xB0, 6);
Sbit (T0, 0xB0, 4);
Sbit (INT0, 0xB0, 2);

/* P4 */
Sbit (INT1, 0xC0, 3);
Sbit (T1, 0xC0, 1); 

Sfr (PSW,0xD0);
Sbit (CY, 0xD0, 7);
Sbit (AC, 0xD0, 6);
Sbit (F0, 0xD0, 5);
Sbit (RS1, 0xD0, 4);
Sbit (RS0, 0xD0, 3);
Sbit (OV, 0xD0, 2);
Sbit (UD, 0xD0, 1);
Sbit (P, 0xD0, 0);

Sfr (ACC, 0xE0);       
Sfr (B, 0xF0); 
Sfr (SP, 0x81);        
Sfr (DPL, 0x82);       
Sfr (DPH, 0x83);       

Sfr (PCON, 0x87);      

/*------------------ TIMERS registers ---------------------*/
Sfr (TCON, 0x88);
Sbit (TF1, 0x88, 7);
Sbit (TR1, 0x88, 6);
Sbit (TF0, 0x88, 5);
Sbit (TR0, 0x88, 4);
Sbit (IE1, 0x88, 3);
Sbit (IT1, 0x88, 2);
Sbit (IE0, 0x88, 1);
Sbit (IT0, 0x88, 0);
        
Sfr (TMOD, 0x89);      
Sfr (TL0, 0x8A);       
Sfr (TL1, 0x8B);       
Sfr (TL2, 0xCC);       
Sfr (TH0, 0x8C);       
Sfr (TH1, 0x8D);       
Sfr (TH2, 0xCD);       
Sfr (WDTRST, 0xA6);    
Sfr (WDTPRG, 0xA7);    

/*------------------- ADC registers -------------------------*/
Sfr (ADCA, 0xF7);
Sfr (ADCF, 0xF6);
Sfr (ADCLK, 0xF2);
Sfr (ADCON, 0xF3);
Sfr (ADDH, 0xF5);
Sfr (ADDL, 0xF4);

/*------------------- FLASH EEPROM registers ----------------*/
Sfr (FCON, 0xD1);
Sfr (AUXR, 0x8E);
Sfr (AUXR1, 0xA2);


/*------------------- IT registers --------------------------*/
Sfr (IEN0, 0xA8);      
Sfr (IPH0, 0xB7);      
Sfr (IPL0, 0xB8);      
Sfr (IOR, 0xA5);

/*  IE0  */
Sbit (EA, 0xA8, 7);
Sbit (EADC, 0xA8, 6);
Sbit (EW1, 0xA8, 5);
Sbit (EW0, 0xA8, 4);
Sbit (ET1, 0xA8, 3);
Sbit (EX1, 0xA8, 2);
Sbit (ET0, 0xA8, 1);
Sbit (EX0, 0xA8, 0);

/* IPL0 */
Sbit (PADC, 0xB8, 6);
Sbit (PW1, 0xB8, 5);
Sbit (PW0, 0xB8, 4);
Sbit (PT1, 0xB8, 3);
Sbit (PX1, 0xB8, 2);
Sbit (PT0, 0xB8, 1);
Sbit (PX0, 0xB8, 0);

/*--------------------- PCA registers -----------------------------*/

/*--------------------- PWM registers -----------------------------*/

Sfr (W0CH, 0xEC);
Sfr (W0CL, 0xED);
Sfr (W0CON, 0xE8);
Sfr (W0FH, 0xEA);
Sfr (W0FL, 0xEB);
Sfr (W0IC, 0xEE);
Sfr (W0MOD, 0xE9);
Sfr (W0R0H, 0xD9);
Sfr (W0R0L, 0xDA);
Sfr (W0R1H, 0xDB);
Sfr (W0R1L, 0xDC);
Sfr (W0R2H, 0xDD);
Sfr (W0R2L, 0xDE);

Sfr (W1CH, 0xFC);
Sfr (W1CL, 0xFD);
Sfr (W1CON, 0xF8);
Sfr (W1FH, 0xFA);
Sfr (W1FL, 0xFB);
Sfr (W1IC, 0xFE);
Sfr (W1R0H, 0xC9);
Sfr (W1R0L, 0xCA);

/* W0CON */
Sbit (W0UP, 0xE8, 7);
Sbit (W0R, 0xE8, 6);
Sbit (W0OS, 0xE8, 3);
Sbit (W0EN2, 0xE8, 2);
Sbit (W0EN1, 0xE8, 1);
Sbit (W0EN0, 0xE8, 0);

/* W1CON */
Sbit (W1UP, 0xF8, 7);
Sbit (W1R, 0xF8, 6);
Sbit (W1ECLK, 0xF8, 4);
Sbit (W1CPS1, 0xF8, 3);
Sbit (W1CPS0, 0xF8, 2);
Sbit (W1INV0, 0xF8, 1);
Sbit (W1EN0, 0xF8, 0);


/*-------------------- OSC control registers ----------------------*/

Sfr (CKCON, 0x8F);
Sfr (CKRL, 0x97);
Sfr (CKSEL, 0x85);
Sfr (OSCBFA, 0x9F);
Sfr (OSCCON, 0x86);












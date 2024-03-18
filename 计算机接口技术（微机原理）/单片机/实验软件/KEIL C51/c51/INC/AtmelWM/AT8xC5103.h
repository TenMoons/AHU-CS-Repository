/*-------------------------------------------------------------------------
AT8xC5103.H    

Header file for AtmelWM AT8xC5103 product
Copyright (c) 1988-2002 Keil Elektronik GmbH and Keil Software, Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __AT8xC5103_H__
#define __AT8xC5103_H__

#define Sfr(x, y)     sfr x = y
#define Sbit(x, y, z) sbit x = y^z
#define Sfr16(x,y)    sfr16 x = y

/*----------------------------------------*/
/* Include file for 8051 SFR Definitions  */
/*----------------------------------------*/

/*  BYTE Register  */


Sfr (P1 , 0x90);        

Sbit (P1_7 , 0x90, 7);
Sbit (P1_6 , 0x90, 6);
Sbit (P1_5 , 0x90, 5);
Sbit (P1_4 , 0x90, 4);
Sbit (P1_3 , 0x90, 3);
Sbit (P1_2 , 0x90, 2);
Sbit (P1_1 , 0x90, 1);
Sbit (P1_0 , 0x90, 0);




       
Sfr (P3 , 0xB0);        

Sbit (P3_7 , 0xB0, 7);
Sbit (P3_6 , 0xB0, 6);
Sbit (P3_5 , 0xB0, 5);
Sbit (P3_4 , 0xB0, 4);
Sbit (P3_3 , 0xB0, 3);
Sbit (P3_2 , 0xB0, 2);
Sbit (P3_1 , 0xB0, 1);
Sbit (P3_0 , 0xB0, 0);

Sbit (RD , 0xB0, 7);
Sbit (WR , 0xB0, 6);
Sbit (T1 , 0xB0, 5);
Sbit (T0 , 0xB0, 4);
Sbit (INT1 , 0xB0, 3);
Sbit (INT0 , 0xB0, 2);
Sbit (TXD , 0xB0, 1);
Sbit (RXD , 0xB0, 0);

Sfr (PSW , 0xD0);       

Sbit (CY  , 0xD0  , 7);
Sbit (AC  , 0xD0  , 6);
Sbit (F0  , 0xD0  , 5);
Sbit (RS1 , 0xD0  , 4);
Sbit (RS0 , 0xD0  , 3);
Sbit (OV  , 0xD0  , 2);
Sbit (UD  , 0xD0  , 1);
Sbit (P   , 0xD0  , 0);

Sfr (ACC , 0xE0);       
Sfr (B , 0xF0); 
Sfr (SP , 0x81);        
Sfr (DPL , 0x82);       
Sfr (DPH , 0x83);       

Sfr (PCON , 0x87);      
Sfr (CKCON0 , 0x8F);     
Sfr (CKCON1 , 0xAF);

/*------------------ TIMERS registers ---------------------*/
Sfr (TCON , 0x88);
Sbit (TF1 , 0x88, 7);
Sbit (TR1 , 0x88, 6);
Sbit (TF0 , 0x88, 5);
Sbit (TR0 , 0x88, 4);
Sbit (IE1 , 0x88, 3);
Sbit (IT1 , 0x88, 2);
Sbit (IE0 , 0x88, 1);
Sbit (IT0 , 0x88, 0);
        
Sfr (TMOD , 0x89);      


Sfr (TL0 , 0x8A);       
Sfr (TL1 , 0x8B);       
Sfr (TL2 , 0xCC);       
Sfr (TH0 , 0x8C);       
Sfr (TH1 , 0x8D);       
      
  
Sfr (WDTRST , 0xA6);    
Sfr (WDTPRG , 0xA7);    




/*-------------------- IT registers -----------------------*/
Sfr (IEN0  , 0xA8);      
Sfr (IEN1  , 0xB1);      
Sfr (IPH0 , 0xB7);      
Sfr (IPH1 , 0xB3);      
Sfr (IPL0 , 0xB8);      
Sfr (IPL1 , 0xB2);      



/*  IEN0  */
Sbit (EA   , 0xA8, 7);
Sbit (EC   , 0xA8, 6);
Sbit (ET2  , 0xA8, 5);
Sbit (ES   , 0xA8, 4);
Sbit (ET1  , 0xA8, 3);
Sbit (EX1  , 0xA8, 2);
Sbit (ET0  , 0xA8, 1);
Sbit (EX0  , 0xA8, 0);


/*--------------------- PCA registers -----------------------------*/
Sfr (CCON , 0xD8);      
Sfr (CMOD , 0xD9);      
Sfr (CH , 0xF9);        
Sfr (CL , 0xE9);        
Sfr (CCAP0H  , 0xFA);   
Sfr (CCAP0L  , 0xEA);   
Sfr (CCAPM0  , 0xDA);   
Sfr (CCAP1H  , 0xFB);   
Sfr (CCAP1L  , 0xEB);   
Sfr (CCAPM1  , 0xDB);   
Sfr (CCAP2H  , 0xFC);   
Sfr (CCAP2L  , 0xEC);   
Sfr (CCAPM2  , 0xDC);   
Sfr (CCAP3H  , 0xFD);   
Sfr (CCAP3L  , 0xED);   
Sfr (CCAPM3  , 0xDD);   
Sfr (CCAP4H  , 0xFE);   
Sfr (CCAP4L  , 0xEE);   
Sfr (CCAPM4  , 0xDE);   
/* CCON */
Sbit (CF   , 0xD8, 7);
Sbit (CR   , 0xD8, 6);

Sbit (CCF4   , 0xD8, 4);
Sbit (CCF3  , 0xD8, 3);
Sbit (CCF2  , 0xD8, 2);
Sbit (CCF1  , 0xD8, 1);
Sbit (CCF0  , 0xD8, 0);

/*-------------------- SPI ---------------------- -----------------*/
Sfr ( SPCON, 0xC3 );
Sfr ( SPSTA, 0xC4 );
Sfr ( SPDAT, 0xC5 );

/*------ Misc ----------------------------------------------------*/
Sfr ( AUXR , 0x8E);
Sfr ( AUXR1, 0xA2);

/*------ Pads Control --------------------------------------------*/
Sfr ( P1M1, 0xD4);
Sfr ( P1M2, 0xE2);
Sfr ( P3M1, 0xD5);
Sfr ( P3M2, 0xE4);

#endif

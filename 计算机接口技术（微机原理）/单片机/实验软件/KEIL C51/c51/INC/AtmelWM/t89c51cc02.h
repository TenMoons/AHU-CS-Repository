/*-------------------------------------------------------------------------
T89C51CC02.h           

Header file for AtmelWM T89C51CC02
Copyright c 1988-2002 Keil Elektronik GmbH and Keil Software^Inc.
All rights reserved.
--------------------------------------------------------------------------*/

#ifndef __T89C51CC02_H__
#define __T89C51CC02_H__

/*  BYTE Register  */
sfr P1 = 0x90;	

sbit P1_7 = 0x90^7;
sbit P1_6 = 0x90^6;
sbit P1_5 = 0x90^5;
sbit P1_4 = 0x90^4;
sbit P1_3 = 0x90^3;
sbit P1_2 = 0x90^2;
sbit P1_1 = 0x90^1;
sbit P1_0 = 0x90^0;

sfr P2 = 0xA0;	
sbit P2_1 = 0xA0^1;
sbit P2_0 = 0xA0^0;


sfr P3 = 0xB0;	

sbit P3_7 = 0xB0^7;
sbit P3_6 = 0xB0^6;
sbit P3_5 = 0xB0^5;
sbit P3_4 = 0xB0^4;
sbit P3_3 = 0xB0^3;
sbit P3_2 = 0xB0^2;
sbit P3_1 = 0xB0^1;
sbit P3_0 = 0xB0^0;

sbit T1 = 0xB0^5;
sbit T0 = 0xB0^4;
sbit INT1 = 0xB0^3;
sbit INT0 = 0xB0^2;
sbit TXD = 0xB0^1;
sbit RXD = 0xB0^0;

sfr P4 = 0xC0;	

sfr PSW = 0xD0;	

sbit CY  = 0xD0^7;
sbit AC  = 0xD0^6;
sbit F0  = 0xD0^5;
sbit RS1 = 0xD0^4;
sbit RS0 = 0xD0^3;
sbit OV  = 0xD0^2;
sbit UD  = 0xD0^1;
sbit P   = 0xD0^0;

sfr ACC = 0xE0;	
sfr B = 0xF0;	
sfr SP = 0x81;	
sfr DPL = 0x82;	
sfr DPH = 0x83;	
sfr DPTR = 0x82;

sfr PCON = 0x87;	
sfr CKCON = 0x8F;	

/*------------------ TIMERS registers ---------------------*/
sfr TCON = 0x88;
sbit TF1 = 0x88^7;
sbit TR1 = 0x88^6;
sbit TF0 = 0x88^5;
sbit TR0 = 0x88^4;
sbit IE1 = 0x88^3;
sbit IT1 = 0x88^2;
sbit IE0 = 0x88^1;
sbit IT0 = 0x88^0;
	
sfr TMOD = 0x89;	

sfr  T2CON = 0xC8;
sbit TF2   = 0xC8^7;
sbit EXF2  = 0xC8^6;
sbit RCLK  = 0xC8^5;
sbit TCLK  = 0xC8^4;
sbit EXEN2 = 0xC8^3;
sbit TR2   = 0xC8^2;
sbit C_T2  = 0xC8^1;
sbit CP_RL2 = 0xC8^0;
	
sfr T2MOD = 0xC9;	
sfr TL0 = 0x8A;	
sfr TL1 = 0x8B;	
sfr TL2 = 0xCC;	
sfr TH0 = 0x8C;	
sfr TH1 = 0x8D;	
sfr TH2 = 0xCD;	
sfr RCAP2L = 0xCA;	
sfr RCAP2H = 0xCB;	
sfr WDTRST = 0xA6;	
sfr WDTPRG = 0xA7;	


/*------------------- UART registers ------------------------*/
sfr SCON = 0x98;	
sbit SM0  = 0x98^7;
sbit FE   = 0x98^7;
sbit SM1  = 0x98^6;
sbit SM2  = 0x98^5;
sbit REN  = 0x98^4;
sbit TB8  = 0x98^3;
sbit RB8  = 0x98^2;
sbit TI   = 0x98^1;
sbit RI   = 0x98^0;

sfr SBUF = 0x99;	
sfr SADEN = 0xB9;	
sfr SADDR = 0xA9;	

/*-------------------- ADC registers ----------------------*/
sfr ADCLK = 0xF2;	
sfr ADCON = 0xF3;	
#define MSK_ADCON_PSIDLE 0x40
#define MSK_ADCON_ADEN   0x20
#define MSK_ADCON_ADEOC  0x10
#define MSK_ADCON_ADSST  0x08
#define MSK_ADCON_SCH    0x07
sfr ADDL = 0xF4;	
#define MSK_ADDL_UTILS	 0x03
sfr ADDH = 0xF5;	
sfr ADCF = 0xF6;	

/*-------------------- FLASH EEPROM registers ------------*/
sfr FCON  = 0xD1;	
#define MSK_FCON_FBUSY 0x01
#define MSK_FCON_FMOD  0x06
#define MSK_FCON_FPS   0x08
#define MSK_FCON_FPL   0xF0
sfr EECON  = 0xD2;	
#define MSK_EECON_EEBUSY 0x01
#define MSK_EECON_EEE    0x02
#define MSK_EECON_EEPL   0xF0
sfr AUXR1  = 0xA2;	
#define MSK_AUXR1_ENBOOT 0x20
/*-------------------- IT registers -----------------------*/
sfr IPL1 = 0xF8;	
sfr IPH1 = 0xF7;	
sfr IEN0  = 0xA8;	
sfr IPL0 = 0xB8;	
sfr IPH0 = 0xB7;	
sfr IEN1  = 0xE8;	

/*  IEN0  */
sbit EA   = 0xA8^7;
sbit EC   = 0xA8^6;
sbit ET2  = 0xA8^5;
sbit ES   = 0xA8^4;
sbit ET1  = 0xA8^3;
sbit EX1  = 0xA8^2;
sbit ET0  = 0xA8^1;
sbit EX0  = 0xA8^0;

/*  IEN1  */
sbit ETIM = 0xE8^2;
sbit EADC = 0xE8^1;
sbit ECAN = 0xE8^0;

/*--------------------- PCA registers --------------------*/
sfr CCON = 0xD8;	
sbitCF  = 0xD8^7;
sbitCR  = 0xD8^6;
sbitCCF1 = 0xD8^1;
sbitCCF0 = 0xD8^0;

sfr CMOD = 0xD9;	
sfr CH = 0xF9;	
sfr CL = 0xE9;	
sfr CCAP0H  = 0xFA;	
sfr CCAP0L  = 0xEA;	
sfr CCAPM0  = 0xDA;	
sfr CCAP1H  = 0xFB;	
sfr CCAP1L  = 0xEB;	
sfr CCAPM1  = 0xDB;	

/*------------------- CAN registers --------------------------*/
sfr CANGIT = 0x9B;
#define MSK_CANGIT_CANIT	0x80
#define MSK_CANGIT_OVRTIM       0x20
#define MSK_CANGIT_OVRBUF	0x10	
#define MSK_CANGIT_SERG		0x08
#define MSK_CANGIT_CERG		0x04
#define MSK_CANGIT_FERG		0x02
#define MSK_CANGIT_AERG		0x01

sfr CANTEC = 0x9C;	
sfr CANREC = 0x9D;	
sfr CANTCON = 0xA1;	
sfr CANMSG = 0xA3;	
sfr CANTTCL = 0xA4;	
sfr CANTTCH = 0xA5;	
sfr CANGSTA = 0xAA;	
#define MSK_CANGSTA_OVFG	0x40
#define MSK_CANGSTA_TBSY	0x10
#define MSK_CANGSTA_RBSY	0x08
#define MSK_CANGSTA_ENFG	0x04
#define MSK_CANGSTA_BOFF	0x02
#define MSK_CANGSTA_ERRP	0x01

sfr CANGCON = 0xAB;	
#define MSK_CANGCON_ABRQ   	0x80
#define MSK_CANGCON_OVRQ   	0x40
#define MSK_CANGCON_TTC   	0x20
#define MSK_CANGCON_SYNCTTC     0x10
#define TTC_EOF                 0x10
#define TTC_SOF		        0x00
#define MSK_CANGCON_AUTBAUD     0x08
#define MSK_CANGCON_ENA  	0x02
#define MSK_CANGCON_GRES 	0x01


sfr CANTIML = 0xAC;	
sfr CANTIMH = 0xAD;	
sfr CANSTMPL = 0xAE;	
sfr CANSTMPH = 0xAF;	
sfr CANPAGE = 0xB1;	
sfr CANSTCH = 0xB2;	
#define MSK_CANSTCH_DLCW  0x80
#define MSK_CANSTCH_TxOk  0x40
#define MSK_CANSTCH_RxOk  0x20
#define MSK_CANSTCH_BERR  0x10
#define MSK_CANSTCH_SERR  0x08
#define MSK_CANSTCH_CERR  0x04
#define MSK_CANSTCH_FERR  0x02
#define MSK_CANSTCH_AERR  0x01

sfr CANCONCH = 0xB3;	
#define MSK_CANCONCH_IDE  0x10
#define MSK_CANCONCH_DLC  0x0F
#define MSK_CANCONCH_CONF 0xC0
#define DLC_MAX    8
#define CH_DISABLE 0x00
#define CH_RxENA   0x80
#define CH_TxENA   0x40
#define CH_RxBENA  0xC0

sfr CANBT1 = 0xB4;
#define CAN_PRESCALER_MIN  0
#define CAN_PRESCALER_MAX  63
	
sfr CANBT2 = 0xB5;
#define MSK_CANBT2_SJW  0x60
#define MSK_CANBT2_PRS  0x0E
#define CAN_SJW_MIN  0
#define CAN_SJW_MAX  3
#define CAN_PRS_MIN  0
#define CAN_PRS_MAX  7
	
sfr CANBT3 = 0xB6;
#define MSK_CANBT3_PHS2 0x70
#define MSK_CANBT3_PHS1 0x0E
#define CAN_PHS2_MIN 0
#define CAN_PHS2_MAX 7
#define CAN_PHS1_MIN 0
#define CAN_PHS1_MAX 7
	
sfr CANSIT = 0xBB;	

sfr CANIDT1 = 0xBC;	
sfr CANIDT2 = 0xBD;	
sfr CANIDT3 = 0xBE;	
sfr CANIDT4 = 0xBF;	
#define MSK_CANIDT4_RTRTAG 0x04

sfr CANGIE = 0xC1;	
#define MSK_CANGIE_ENRX    0x20
#define MSK_CANGIE_ENTX    0x10
#define MSK_CANGIE_ENERCH  0x08
#define MSK_CANGIE_ENBUF   0x04
#define MSK_CANGIE_ENERG   0x02

sfr CANIE = 0xC3;	
sfr CANIDM1 = 0xC4;	
sfr CANIDM2 = 0xC5;	
sfr CANIDM3 = 0xC6;	
sfr CANIDM4 = 0xC7;
#define MSK_CANIDM4_RTRMSK 0x04
#define MSK_CANIDM4_IDEMSK 0x01 
	
sfr CANEN = 0xCF;	

#endif


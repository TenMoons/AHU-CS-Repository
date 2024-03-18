/*REV.  2.0    11th February 2002
  ADuC812  Apps, Analog Devices Inc.*/

/*  BYTE Register  */
sfr   P0        = 0x80;
sfr   SP        = 0x81;
sfr   DPL       = 0x82;
sfr   DPH       = 0x83;
sfr   DPP       = 0x84;
sfr   PCON      = 0x87;
sfr   TCON      = 0x88;
sfr   TMOD      = 0x89;
sfr   TL0       = 0x8A;
sfr   TL1       = 0x8B;
sfr   TH0       = 0x8C;
sfr   TH1       = 0x8D;
sfr   P1        = 0x90;
sfr   SCON      = 0x98;
sfr   SBUF      = 0x99;
sfr   I2CDAT    = 0x9A;
sfr   I2CADD    = 0x9B;
sfr   P2        = 0xA0;
sfr   IE        = 0xA8;
sfr   IE2       = 0xA9;
sfr   P3        = 0xB0;
sfr   IP        = 0xB8;
sfr   ECON      = 0xB9;
sfr   ETIM1     = 0xBA; //AR
sfr   ETIM2     = 0xBB;
sfr   ETIM3     = 0xC4;
sfr   EDATA1    = 0xBC;
sfr   EDATA2    = 0xBD;
sfr   EDATA3    = 0xBE;
sfr   EDATA4    = 0xBF;
sfr   WDCON     = 0xC0;
sfr   EADRL     = 0xC6;
sfr   T2CON     = 0xC8;
sfr   RCAP2L    = 0xCA;
sfr   RCAP2H    = 0xCB;
sfr   TL2       = 0xCC;
sfr   TH2       = 0xCD;
sfr   PSW       = 0xD0;
sfr   DMAL      = 0xD2;
sfr   DMAH      = 0xD3;
sfr   DMAP      = 0xD4;
sfr   ADCCON2   = 0xD8;
sfr   ADCDATAL  = 0xD9;
sfr   ADCDATAH  = 0xDA;
sfr   PSMCON    = 0xDF;
sfr   ACC       = 0xE0;
sfr   I2CCON    = 0xE8;
sfr   DCON      = 0xE8;
sfr   ADCCON1   = 0xEF;
sfr   B         = 0xF0;
sfr   ADCOFSL   = 0xF1;
sfr   ADCOFSH   = 0xF2;
sfr   ADCGAINL  = 0xF3;
sfr   ADCGAINH  = 0xF4;
sfr   ADCCON3   = 0xF5;
sfr   SPIDAT    = 0xF7;
sfr   SPICON    = 0xF8;
sfr   DAC0L     = 0xF9;
sfr   DAC0H     = 0xFA;
sfr   DAC1L     = 0xFB;
sfr   DAC1H     = 0xFC;
sfr   DACCON    = 0xFD;

/* BIT Register..... */
/* TCON */
sbit  TF1       = 0x8F;
sbit  TR1       = 0x8E;
sbit  TF0       = 0x8D;
sbit  TR0       = 0x8C;
sbit  IE1       = 0x8B;
sbit  IT1       = 0x8A;
sbit  IE0       = 0x89;
sbit  IT0       = 0x88;
/* P1 */
sbit  T2EX      = 0x91;
sbit  T2        = 0x90;
/* SCON */
sbit  SM0       = 0x9F;
sbit  SM1       = 0x9E;
sbit  SM2       = 0x9D;
sbit  REN       = 0x9C;
sbit  TB8       = 0x9B;
sbit  RB8       = 0x9A;
sbit  TI        = 0x99;
sbit  RI        = 0x98;
/* IE */
sbit  EA        = 0xAF;
sbit  EADC      = 0xAE;
sbit  ET2       = 0xAD;
sbit  ES        = 0xAC;
sbit  ET1       = 0xAB;
sbit  EX1       = 0xAA;
sbit  ET0       = 0xA9;
sbit  EX0       = 0xA8;
/* P3 */
sbit  RD        = 0xB7;
sbit  WR        = 0xB6;
sbit  T1        = 0xB5;
sbit  T0        = 0xB4;
sbit  INT1      = 0xB3;
sbit  INT0      = 0xB2;
sbit  TXD       = 0xB1;
sbit  RXD       = 0xB0;
/* IP */
sbit  PSI       = 0xBF;
sbit  PADC      = 0xBE;
sbit  PT2       = 0xBD;
sbit  PS        = 0xBC;
sbit  PT1       = 0xBB;
sbit  PX1       = 0xBA;
sbit  PT0       = 0xB9;
sbit  PX0       = 0xB8;
/* WDCON */
sbit  PRE2      = 0xC7;
sbit  PRE1      = 0xC6;
sbit  PRE0      = 0xC5;
sbit  WDR1      = 0xC3;
sbit  WDR2      = 0xC2;
sbit  WDS       = 0xC1;
sbit  WDE       = 0xC0;
/* T2CON */
sbit  TF2       = 0xCF;
sbit  EXF2      = 0xCE;
sbit  RCLK      = 0xCD;
sbit  TCLK      = 0xCC;
sbit  EXEN2     = 0xCB;
sbit  TR2       = 0xCA;
sbit  CNT2      = 0xC9;
sbit  CAP2      = 0xC8;
/* PSW */
sbit  CY        = 0xD7;
sbit  AC        = 0xD6;
sbit  F0        = 0xD5;
sbit  RS1       = 0xD4;
sbit  RS0       = 0xD3;
sbit  OV        = 0xD2;
sbit  F1        = 0xD1;
sbit  P         = 0xD0;
/* ADCCON2 */
sbit  ADCI      = 0xDF;
sbit  DMA       = 0xDE;
sbit  CCONV     = 0xDD;
sbit  SCONV     = 0xDC;
sbit  CS3       = 0xDB;
sbit  CS2       = 0xDA;
sbit  CS1       = 0xD9;
sbit  CS0       = 0xD8;
/*  I2CCON  */
sbit  MDO       = I2CCON^7;
sbit  MDE       = I2CCON^6;
sbit  MCO       = I2CCON^5;
sbit  MDI       = I2CCON^4;
sbit  I2CM      = I2CCON^3;
sbit  I2CRS     = I2CCON^2;
sbit  I2CTX     = I2CCON^1;
sbit  I2CI      = I2CCON^0;
/*  DCON  */
sbit  D1        = DCON^7;
sbit  D1EN      = DCON^6;
sbit  D0        = DCON^5;
sbit  D0EN      = DCON^3;
/* SPICON */
sbit  ISPI      = 0xFF;
sbit  WCOL      = 0xFE;
sbit  SPE       = 0xFD;
sbit  SPIM      = 0xFC;
sbit  CPOL      = 0xFB;
sbit  CPHA      = 0xFA;
sbit  SPR1      = 0xF9;
sbit  SPR0      = 0xF8;

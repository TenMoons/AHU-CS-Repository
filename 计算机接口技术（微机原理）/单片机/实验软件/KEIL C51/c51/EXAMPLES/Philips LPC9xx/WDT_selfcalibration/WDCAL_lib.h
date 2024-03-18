// wdcal_lib.h
#ifndef WDCAL_LIB
#define WDCAL_LIB

#define ADRSTAT 510			// EEPROM adresses to save status 
#define ADRWDFQ 511			// and result of calibration

#define MESWD 0				// Constants for calibration status
#define USERC 1	

#define WDTOSC 	0x44		// UCFG1 values to set up different clock sources
#define RCOSC	0x43
#define CRYOSC	0x40

extern void msec(int x);
extern void WDT_ISR();
extern void T0_ISR();
extern void EEPROMwrite(unsigned int adr, unsigned char dat);
extern unsigned char EEPROMread(unsigned int adr);
extern void WDcal(); 
extern void setUCFG(unsigned char ucfg);

#endif


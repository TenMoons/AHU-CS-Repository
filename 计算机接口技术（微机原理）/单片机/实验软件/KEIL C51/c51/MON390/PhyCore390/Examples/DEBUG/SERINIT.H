//-------------------------------------------------------------------------
// Header File for SerInit
//-------------------------------------------------------------------------
#ifndef _SERINIT_H_                 
#define _SERINIT_H_                 
 
#ifdef  SerInitInfo
 #ifndef SerInitInfoVariable
 #define SerInitInfoVariable
  extern unsigned int   SerInitBDrmInfo; //global variable
  extern unsigned char  SerInitSCONInfo; //global variable
  extern unsigned char  SerInitPCONInfo; //global variable
  extern unsigned char  SerInitTCONInfo; //global variable
  extern unsigned char  SerInitTimerInfo; //global variable
  extern unsigned char  SerInitHighInfo; //global variable
  extern unsigned char  SerInitLowInfo; //global variable
 #endif
#endif   
void SerInit(void);                  /* function prototype                  */


#endif //_SERINIT_H_

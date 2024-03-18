// cstm_lib.h

#ifndef CSTM_LIB
#define CSTM_LIB

// User specific functions
extern void init();
extern void UART_init();
extern void UART_ISR(void);
extern void sendtoPC(char * dat);

extern unsigned char sendRQ;		// global flag
									// for polling
#endif 

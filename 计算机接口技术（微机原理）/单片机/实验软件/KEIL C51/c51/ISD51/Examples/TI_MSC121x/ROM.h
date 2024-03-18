/*------------------------------------------------------------------------------
ROM.H:  Header file for all TI MSC 1210 C-style boot-ROM functions

Copyright 2003 Keil Software, Inc.
------------------------------------------------------------------------------*/

extern void put_string(char code *string);
extern char page_erase (int faddr, char fdata, char fdm);
extern char write_flash (int faddr, char fdata, char fdm);
extern char write_flash_chk (int faddr, char fdata, char fdm);
extern char write_flash_byte (int faddr, char fdata, char fdm);
extern char faddr_data_read(char);
extern char data_x_c_read(int addr);
extern void tx_byte(char);
extern void tx_hex(char);
extern void putok(void);
extern char rx_byte(void);
extern char rx_byte_echo(void);
extern char rx_hex_echo(void);
extern char rx_double_echo(void);
extern char rx_word_echo(void);
extern void autobaud(void);
extern void putspace4(void);
extern void putspace3(void);
extern void putspace2(void);
extern void putspace1(void);
extern void putcr(void);


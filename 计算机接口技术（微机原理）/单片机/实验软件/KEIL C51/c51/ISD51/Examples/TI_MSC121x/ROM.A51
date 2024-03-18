
PUBLIC	_put_string		; void put_string(char code *string);
PUBLIC	_page_erase		; char page_erase (int faddr, char fdata, char fdm)
PUBLIC	write_flash		; char write_flash (int faddr, char fdata, char fdm)
PUBLIC	_write_flash_chk	; char write_flash_chk (int faddr, char fdata, char fdm)
PUBLIC	_write_flash_byte	; char write_flash_byte (int faddr, char fdata, char fdm)
PUBLIC	_faddr_data_read	; char faddr_data_read(char);
PUBLIC	_data_x_c_read		; char data_x_c_read(int addr);
PUBLIC	_tx_byte		; void tx_byte(char);
PUBLIC	_tx_hex			; void tx_hex(char);
PUBLIC  putok			; void putok(void);
PUBLIC	rx_byte			; char rx_byte(void);
PUBLIC	rx_byte_echo		; char rx_byte_echo(void);
PUBLIC	rx_hex_echo		; char rx_hex_echo(void);
PUBLIC	rx_hex_double_echo	; char rx_double_echo(void);
PUBLIC	rx_hex_word_echo	; char rx_word_echo(void);
PUBLIC  autobaud		; void autobaud(void);
PUBLIC	putspace4		; void putspace4(void)
PUBLIC	putspace3		; void putspace3(void)
PUBLIC	putspace2		; void putspace2(void)
PUBLIC	putspace1		; void putspace1(void)
PUBLIC  putcr			; void putcr(void);


;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;
; Interface to C compatible Boot ROM Build In Routines
;
	CSEG AT 0FFD5H
_put_string:			; void put_string(char *string);

	CSEG AT	0FFD7H
_page_erase:			; char page_erase (int faddr, char fdata, char fdm)

	CSEG AT 0FFD9H	
write_flash:			; DPTR = address, acc = data (Not callable by C programs)	 

	CSEG AT 0FFDBH
_write_flash_chk:		; char write_flash_chk (int faddr, char fdata, char fdm)

	CSEG AT 0FFDDH
_write_flash_byte:		; char write_flash_byte (int faddr, char fdata, char fdm)

	CSEG AT 0FFDFH
_faddr_data_read:		; char faddr_data_read(char);

	CSEG AT 0FFE1H
_data_x_c_read:			; char data_x_c_read(int addr);

	CSEG AT 0FFE3H
_tx_byte:			; void tx_byte(char);

	CSEG AT 0FFE5H
_tx_hex:			; void tx_hex(char);

	CSEG AT 0FFE7H
putok:				; void putok(void);

	CSEG AT 0FFE9H
rx_byte:			; char rx_byte(void);

	CSEG AT 0FFEBH
rx_byte_echo:			; char rx_byte_echo(void);

	CSEG AT 0FFEDH
rx_hex_echo:			; char rx_hex_echo(void);

	CSEG AT 0FFEFH
rx_hex_double_echo:			; char rx_double_echo(void);

	CSEG AT 0FFF1H
rx_hex_word_echo:			; char rx_word_echo(void);

	CSEG AT 0FFF3H
autobaud:			; void autobaud(void);

	CSEG AT 0FFF5H
putspace4:			; void putspace4(void)

	CSEG AT 0FFF7H
putspace3:			; void putspace3(void)

	CSEG AT 0FFF9H
putspace2:			; void putspace2(void)

	CSEG AT 0FFFBH
putspace1:			; void putspace1(void)

	CSEG AT 0FFFDH
putcr:				; void putcr(void);

	END


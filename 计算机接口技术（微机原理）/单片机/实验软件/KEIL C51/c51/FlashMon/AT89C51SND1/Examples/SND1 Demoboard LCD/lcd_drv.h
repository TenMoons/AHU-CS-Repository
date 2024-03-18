/*H**************************************************************************
* $RCSfile: lcd_drv.h,v $         
*----------------------------------------------------------------------------
* Copyright (c) 2002 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      $Name: DEMO_FAT_2_0_0 $      
* REVISION:     $Revision: 1.5 $     
* FILE_CVSID:   $Id: lcd_drv.h,v 1.5 2002/05/24 09:51:15 njourdan Exp $       
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the LCD controller definition
*
* NOTES:
* Definition for Hitachi HD44780 LCD controller:
*
* - 2x16 characters
* - 8 bit interface
*
* DB7:0     = AD7:0
* RS        = A0
* R/W       = '0' not used, busy is never tested
* E         = P3.6/WR# inverted
*****************************************************************************/

#ifndef _LCD_DRV_H_
#define _LCD_DRV_H_

/*_____ I N C L U D E S ____________________________________________________*/


/*_____ M A C R O S ________________________________________________________*/
/*H**************************************************************************
* $RCSfile: disp.h,v $         
*----------------------------------------------------------------------------
* Copyright (c) 2002 Atmel.
*----------------------------------------------------------------------------
* RELEASE:      $Name: DEMO_FAT_2_0_0 $      
* REVISION:     $Revision: 1.8 $     
* FILE_CVSID:   $Id: disp.h,v 1.8 2002/11/08 08:32:55 ffosse Exp $       
*----------------------------------------------------------------------------
* PURPOSE:
* This file contains the high level display definition
*****************************************************************************/

#ifndef _DISP_H_
#define _DISP_H_

/*_____ I N C L U D E S ____________________________________________________*/

#include "lcd_drv.h"          /* lcd driver definition */ 


/*_____ M A C R O S ________________________________________________________*/


/*----- LCD positons ----*/
#define POS_HOME        LCD_LINE0, 0

#define POS_LOCK        LCD_LINE0, 0

#define POS_MEM         LCD_LINE0, 5

#define POS_REPEAT      LCD_LINE0, 10

#define POS_SOUND       LCD_LINE0, 6
#define POS_SOUND_LVL   LCD_LINE0, 7

#define POS_FILE        LCD_LINE1, 2

#define POS_TIME        LCD_LINE0, 11
#define POS_MINUTE      LCD_LINE0, 11
#define POS_SECOND      LCD_LINE0, 14


/*----- CGRAM -----*/
#define CHAR_SPARE1     0x00                /* spare icon address */
#define CHAR_MODE       0x01                /* mode icon address */
#define CHAR_STATE      0x02                /* state icon address */
#define CHAR_TYPE       0x02                /* file type icon address */
#define CHAR_SOUND      0x03                /* sound icon address */
#define CHAR_MEM        0x04                /* memory icon address */
#define CHAR_REPEAT     0x05                /* repeat icon address */
#define CHAR_LOCK       0x06                /* lock icon address */
#define CHAR_SPARE2     0x07                /* spare icon address */

#define CGRAM_SPARE1    CHAR_SPARE1*CGRAM_CHAR_SIZE
#define CGRAM_MODE      CHAR_MODE*CGRAM_CHAR_SIZE
#define CGRAM_STATE     CHAR_STATE*CGRAM_CHAR_SIZE
#define CGRAM_TYPE      CHAR_TYPE*CGRAM_CHAR_SIZE
#define CGRAM_SOUND     CHAR_SOUND*CGRAM_CHAR_SIZE
#define CGRAM_MEM       CHAR_MEM*CGRAM_CHAR_SIZE
#define CGRAM_REPEAT    CHAR_REPEAT*CGRAM_CHAR_SIZE
#define CGRAM_LOCK      CHAR_LOCK*CGRAM_CHAR_SIZE
#define CGRAM_SPARE2    CHAR_SPARE2*CGRAM_CHAR_SIZE


/* memory type */
#define SYMB_CHIP       0
#define SYMB_CARD       1
#define SYMB_CARD1      2
#define SYMB_CARD2      3
#define SYMB_NO_MEM     4

/* repeat type */
#define SYMB_NO_REPEAT  0
#define SYMB_REP_DIR    1
#define SYMB_REP_FILE   2
#define SYMB_REP_A      3
#define SYMB_REP_B      4


/*_____ D E F I N I T I O N ________________________________________________*/

/* Menu Structure */
typedef struct
{
  unsigned char  state;
  char  disp[18];
} St_menu;


/*_____ D E C L A R A T I O N ______________________________________________*/

#define Print_char(c)                   Lcd_put_char(c)
#define Print_home(l)                   Lcd_put_cmd(l)

void    print_init (void);
void    print_state_blank (void);
void    print_state_stop (void);
void    print_state_play (void);
void    print_state_pause (void);
void    print_state_record (void);
void    print_state_error (void);
void    print_mode_song (void);
void    print_mode_voice (void);
void    print_mode_mass (void);
void    print_mode_tool (void);
void    print_sound (void);
void    print_sound_level (void);
void    print_voice_vol (char);
void    print_kbd_lock (void);
void    print_kbd_unlock (void);
void    print_mem (Byte);
void    print_repeat (Byte);
void    print_screen (char code *);
void    print_string (char code *);
void    print_decim (Byte, bit);
void    print_time (unsigned char, unsigned char);
void    print_min (Byte);
void    print_sec (Byte);
void    print_file_name (void);
void    print_file_type (void);

bit     print_name (char pdata *);


#endif  /* _DISP_H_ */



/*----- LCD timing -----*/
/* Clock */
#define X2_MODE                             /* X2 mode */
#undef X2_MODE                              /* no X2 mode */

#define FOSC            16000               /* oscillator frequency (KHz) */

#ifdef X2_MODE
    #define FPER        FOSC
#else
    #define FPER        FOSC/2
#endif
#define TEMPO_40US   (unsigned char)(0.0019*FPER)    /* tempo duration of 40 us */
#define TEMPO_1_5MS  (unsigned int)(0.06*FPER)    /* tempo duration of 1.5 ms */
#define TEMPO_30MS   (TEMPO_1_5MS * 20)     /* tempo duration of 30 ms */

/*----- LCD control -----*/
#define LCD_NB_LINE     (unsigned char)0x02      /* 2 display lines */
#define LCD_NB_COLUMN   (unsigned char)0x10      /* 16 characters per line */

#define C_R             (char)0x0D
#define L_F             (char)0x0A
#define B_S             (char)0x08

/*----- LCD command -----*/
#define LCD_CLR         (unsigned char)0x01      /* clear entire display */

#define LCD_HOME        (unsigned char)0x02      /* cursor back to home position */

#define LCD_SET         (unsigned char)0x04      /* set cursor move direction and specifies shift or display */
#define LCD_NO_INC      (unsigned char)0x00      /* inc OFF */
#define LCD_INC         (unsigned char)0x02      /* inc ON */
#define LCD_NO_SHIFT    (unsigned char)0x00      /* no shift */
#define LCD_SHIFT       (unsigned char)0x01      /* shift entire display */

#define LCD_DISPLAY     (unsigned char)0x08      /* control Display,cursor,blink - ON / OFF */
#define LCD_DISP_OFF    (unsigned char)0x08      /* display OFF */
#define LCD_DISP_ON     (unsigned char)0x0C      /* display ON */
#define LCD_CURS_OFF    (unsigned char)0x00      /* cursor OFF */
#define LCD_CURS_ON     (unsigned char)0x02      /* cursor ON */
#define LCD_BLINK_OFF   (unsigned char)0x00      /* cursor blink OFF */
#define LCD_BLINK_ON    (unsigned char)0x01      /* cursor blink ON */

#define LCD_CURS        (unsigned char)0x10      /* move Cursor and shift display */
#define LCD_CURS_SHIFT  (unsigned char)0x00      /* cursor shift */
#define LCD_DISP_SHIFT  (unsigned char)0x08      /* display shift */
#define LCD_RIGHT       (unsigned char)0x04      /* cursor/display shift right */
#define LCD_LEFT        (unsigned char)0x00      /* cursor/display shift left */

#define LCD_FCTSET      (unsigned char)0x20      /* Set: 4 bits mode , nb of lines, nb of dot matrix */
#define LCD_4BIT        (unsigned char)0x00      /* command for 4 bit mode */
#define LCD_8BIT        (unsigned char)0x10      /* command for 8 bit mode */
#define LCD_1_LINE      (unsigned char)0x00      /* set in 1 Line mode */
#define LCD_2_LINE      (unsigned char)0x08      /* set in 2 Line mode */
#define LCD_5x8DOTS     (unsigned char)0x00      /* set in 5*8 dots   */
#define LCD_5x11DOTS    (unsigned char)0x04      /* set in 5*11 dots   */

#define LCD_CGRAM       (unsigned char)0x40      /* Set CG RAM address */
#define LCD_DDRAM       (unsigned char)0x80      /* Set DD RAM adresse */
#define LCD_BF          (unsigned char)0x08      /* busy flag */
#define LCD_SHIFT       (unsigned char)0x01      /* shift ON */
#define LCD_DATA        (unsigned char)0x0F      /* data mask on 4 bit  */
#define LCD_LINE0       (unsigned char)0x80      /* line 0 command */
#define LCD_LINE1       (unsigned char)0xC0      /* line 1 command */
#define LCD_LINE_OFFSET (unsigned char)0x40      /* line address offset */

/*----- CGRAM -----*/
#define CGRAM_CHAR_SIZE (unsigned char)0x08      /* 8 patterns to define a char */


/*_____ D E F I N I T I O N ________________________________________________*/

extern  xdata unsigned char  lcd_cmd;
extern  xdata unsigned char  lcd_data;


/*_____ D E C L A R A T I O N ______________________________________________*/

#define Lcd_cur_on()                    lcd_cmd = (LCD_DISP_ON | LCD_CURS_ON | LCD_BLINK_ON)
#define Lcd_cur_off()                   lcd_cmd = LCD_DISP_ON
#define Lcd_put_char(c)                 lcd_data = c
#define Lcd_put_cmd(c)                  lcd_cmd = c

void    lcd_init (void);
void    lcd_clr (void);
void    lcd_set_cur (unsigned char, unsigned char);
void    lcd_cgram (unsigned char, unsigned char code *);
void    lcd_putchar (char);
void    lcd_println (char Buffer[16], char line);
void    lcd_clearln (char line);




#endif  /* _LCD_DRV_H_ */



#include "lcd_drv.h"                        /* lcd driver definition */

/* LCD */
#define LCD_CMD_ADD     0x8880              /* Command register address */
#define LCD_DAT_ADD     0xC881              /* Data register address */

unsigned char xdata lcd_cmd _at_ LCD_CMD_ADD;
unsigned char xdata lcd_data _at_ LCD_DAT_ADD;

static  unsigned char    lcd_line;               /* save the cursor position */

static  void    lcd_wr_cmd (char);
static  void    lcd_wr_data (char);

void lcd_init (void)
{
unsigned int  data  i;

  for (i = 0; i < TEMPO_30MS; i++);     /* initialization delay */

  lcd_wr_cmd(LCD_FCTSET | LCD_8BIT | LCD_2_LINE | LCD_5x8DOTS);
  lcd_wr_cmd(LCD_DISPLAY | LCD_DISP_ON | LCD_CURS_OFF | LCD_BLINK_OFF);
  lcd_wr_cmd(LCD_SET | LCD_INC | LCD_RIGHT);
  lcd_wr_cmd(LCD_CLR);
  for (i = 0; i < TEMPO_1_5MS; i++);    /* clear delay */
  lcd_line = LCD_LINE0;
}


void lcd_set_cur (unsigned char line, unsigned char column)
{
  lcd_line = line;                      /* update the line position */
  lcd_wr_cmd(line | column);            /* write the new cursor position */
}


void lcd_putchar (char c)
{
  switch (c)
  {
    case C_R:                   /* Carriage Return */
    {
      lcd_set_cur(lcd_line, 0);
      break;
    }

    case L_F:                   /* Line Feed + Carriage Return */
    {
      lcd_set_cur((lcd_line + LCD_LINE_OFFSET), 0);
      break;
    }

    default:
    {
      lcd_wr_data(c);           /* write the character to the display */
      break;
    }
  }
}


void lcd_wr_cmd (char cmd)
{
unsigned char  data  i;

  lcd_cmd = cmd;
  for (i = 0; i < TEMPO_40US; i++);
}


void lcd_wr_data (char dat)
{
unsigned char  data  i;

  lcd_data = dat;
  for (i = 0; i < TEMPO_40US - 4; i++);
}


void lcd_println(char InBuffer[16], char line)
{
char BuffIx = 0;
char idata BCach;

  lcd_set_cur (line, 0);
  while ((BCach = InBuffer[BuffIx]) != '\0'){
    if (BCach == '\n') continue;
    lcd_putchar (BCach);
    BuffIx++;
  }
}

void lcd_clearln(char line)
{
  lcd_println("                ", line);
}

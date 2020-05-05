#include <avr/io.h>
#include <util/delay.h>

#define LCD_DDR         DDRD
#define LCD_PORT        PORTD

#define LCD_RS			(1 << PD4)
#define LCD_E			(1 << PD5)
#define LCD_D4			(1 << PD0)
#define LCD_D5			(1 << PD1)
#define LCD_D6			(1 << PD2)
#define LCD_D7			(1 << PD3)

#define LCD_INIT         0x30

#define LCD_FUNCTION_SET 0x20
#define LCD_DISPLAY_SET  0x08

#define LCD_4BIT_MODE    0x02
#define LCD_FONT_5X8     0x00
#define LCD_TWO_LINE     0x08
#define LCD_CLEAR		 0x01
#define LCD_HOME		 0x02

#define LCD_DISPLAY_ON   0x04
#define LCD_DISPLAY_OFF  0x00
#define LCD_CURSOR_OFF   0x00
#define LCD_BLINK_OFF    0x00

#define LCD_ENTRY_MODE   0x04
#define LCD_DDRAM_SET    0x80

void lcd_init();
void lcd_command(unsigned char command);
void lcd_write(unsigned char data);
void lcd_clear();
void lcd_home();
void lcd_move(unsigned char col, unsigned char row);
void lcd_text(char *text);

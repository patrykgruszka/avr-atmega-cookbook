#include "hd44780.h"

void lcd_init()
{
    // set outputs
    LCD_DDR |= LCD_RS;
    LCD_DDR |= LCD_E;
    LCD_DDR |= LCD_D4; 
    LCD_DDR |= LCD_D5;
    LCD_DDR |= LCD_D6;
    LCD_DDR |= LCD_D7;
    _delay_ms(16);

    // set RS and E to 0
    LCD_PORT &= ~LCD_RS;
    LCD_PORT &= ~LCD_E;

    // init sequence
    for(int i = 0; i < 3; i++) {
        lcd_write_nibble(LCD_INIT); 
        _delay_ms(5);
    }

    // set 4-bit mode
    lcd_write_nibble(0x02);
    _delay_ms(5);


    lcd_command(LCD_FUNCTION_SET | LCD_4BIT_MODE | LCD_FONT_5X8 | LCD_TWO_LINE);
    lcd_command(LCD_DISPLAY_SET | LCD_CURSOR_OFF | LCD_BLINK_OFF);
    lcd_command(LCD_CLEAR);
    _delay_ms(5);
    lcd_command(LCD_DISPLAY_SET | LCD_DISPLAY_ON);
    lcd_command(LCD_HOME);
    _delay_ms(5);
}

void lcd_command(unsigned char command)
{
    LCD_PORT &= ~LCD_RS;
    lcd_write_nibble(command >> 4);
    lcd_write_nibble(command);
    _delay_us(50);
}

void lcd_write(unsigned char data)
{
    LCD_PORT |= LCD_RS;
    lcd_write_nibble(data >> 4);
    lcd_write_nibble(data);
    _delay_us(50);
}

void lcd_home()
{
    lcd_command(LCD_HOME);
    _delay_ms(5);
}

void lcd_clear()
{
    lcd_command(LCD_CLEAR);
    _delay_ms(5);
}

void lcd_move(unsigned char col, unsigned char row)
{
    lcd_command(LCD_DDRAM_SET | (0x40 * row) + col);
}

void lcd_text(char *text)
{
    while(*text) {
        lcd_write(*text++);
    }
}

void lcd_write_nibble(unsigned char nibble)
{
    LCD_PORT |= LCD_E;
    
    if (nibble & 0x01)
        LCD_PORT |= LCD_D4;
    else
        LCD_PORT &= ~LCD_D4;

    if (nibble & 0x02)
        LCD_PORT |= LCD_D5;
    else
        LCD_PORT &= ~LCD_D5;

    if (nibble & 0x04)
        LCD_PORT |= LCD_D6;
    else
        LCD_PORT &= ~LCD_D6;

    if (nibble & 0x08)
        LCD_PORT |= LCD_D7;
    else
        LCD_PORT &= ~LCD_D7;

    LCD_PORT &= ~LCD_E;
}


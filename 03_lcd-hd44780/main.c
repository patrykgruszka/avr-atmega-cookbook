#define F_CPU 1000000UL

#include <avr/io.h>
#include "hd44780.h"

int main(void)
{
  lcd_init();

  int i = 0;
  char text[16];

  while(1)
  {
    lcd_clear();
    lcd_home();

    sprintf(text, "i: %d", i);
    lcd_text(text);

    lcd_move(0, 1);

    if (i % 3 == 0 && i % 5 == 0) {
        lcd_text("Fizz Buzz");
    } else if (i % 3 == 0) {
        lcd_text("Fizz");
    } else if (i % 5 == 0) {
        lcd_text("Buzz");
    }

    _delay_ms(1000);
    i++;
  }
}

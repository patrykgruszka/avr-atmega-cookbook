#include <avr/io.h>
#include <util/delay.h>

#define F_CPU 1000000UL

int main(void)
{
  DDRD = 0xFF;                  // set PB0..PB7 as output
  PORTD = 0x00;                 // all LEDs off

  while(1) {
    PORTD++;                    // increment PORTD value 
    _delay_ms(1000);
    if (PORTD == 0xFF) {        // when PORTD value equals 255
        PORTD = 0x00;           // reset value to 0
    }
  }
}

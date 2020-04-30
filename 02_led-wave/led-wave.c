#include <avr/io.h>
#include <util/delay.h>


int main(void)
{
  DDRD = 0xFF;                           // set PB0..PB7 as output
  PORTD = 0x01;                          // PB0 LED on
  int direction = 1;                     // direciton right

  for(int i = 1;;i++) {
    _delay_ms(80);

    if (direction == 1) {
      PORTD <<= 1;                       // << shifts left and adds zeros at the right
      if (i % 7 == 0) direction = -1;    // on 7th iteration change direction to left
    } else {
      PORTD >>= 1;                       // >> shifts right and adds zeros at the left
      if (i % 7 == 0) direction = 1;     // on 7th iteration change direction to right
    }

  }
}

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
    DDRB = 0x01;          // set PB0 as output
    while(1)
    {
        PORTB = 0x01;     // LED on
        _delay_ms(200);
        PORTB = 0x00;     // LED off 
        _delay_ms(200);
    }
}

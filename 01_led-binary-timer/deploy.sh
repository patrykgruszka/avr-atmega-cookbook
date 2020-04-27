sudo avr-gcc -mmcu=atmega8 led-binary-timer.c -o led-binary-timer.elf
sudo avr-objcopy -O ihex led-binary-timer.elf led-binary-timer.hex
sudo avrdude -c usbasp -p m8 -U flash:w:led-binary-timer.hex

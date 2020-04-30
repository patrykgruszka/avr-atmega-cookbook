sudo avr-gcc -mmcu=atmega8 led-wave.c -o led-wave.elf
sudo avr-objcopy -O ihex led-wave.elf led-wave.hex
sudo avrdude -c usbasp -p m8 -U flash:w:led-wave.hex

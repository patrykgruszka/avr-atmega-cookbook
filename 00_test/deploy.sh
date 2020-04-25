sudo avr-gcc -mmcu=atmega8 main.c -o main.elf
sudo avr-objcopy -O ihex main.elf main.hex
sudo avrdude -c usbasp -p m8 -U flash:w:main.hex

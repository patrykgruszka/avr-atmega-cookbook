sudo avr-gcc -Os -mmcu=atmega8 main.c hd44780.c -o main
sudo avr-objcopy -O ihex main main.hex
sudo avrdude -c usbasp -p m8 -U flash:w:main.hex

## Assembler project

This is a project for teaching the basic principles of avr assembler

## Commands

1. Install avrdude on Gentoo linux
	```shell
	emerge -av dev-embedded/avrdude
	```
1. Read the fuses with avrdude
	``` shell
	avrdude -c usbasp -p t2313 -U hfuse:r:-:h -U lfuse:r:-:h
	```
1. Read flash memory
	```shell
	avrdude -p t2313 -c usbasp -U flash:r:/tmp/flash_dump.hex:r
	```
1. Read eeprom memory
	```shell
	avrdude -p t2313 -c usbasp -U eeprom:r:/tmp/eeprom_dump.raw:r
	```

## Get Started

1. Clone the repository
	```shell
	git clone git@github.com:thedetukov/assembler-project.git
	```
1. Enter into cloned directory
	```shell
	cd assembler-project/src/
	```
1. Generate hex file command
	```shell
	avra 1-1.asm
	```
1. Start program
	```shell
	avrdude -p t2313 -c usbasp -U flash:w:1-1.hex:i
	```

## References
- [AVR instraction set](http://lyons42.com/AVR/Opcodes/AVRAllOpcodes.html)
- [Delay in assembly for avr microcontrollers](https://stackoverflow.com/questions/24097526/how-to-make-a-delay-in-assembly-for-avr-microcontrollers)
- [Read the fuses with avrdude](https://stackoverflow.com/questions/74260385/how-to-read-the-fuses-with-avrdude)
- [Convert Binary to Hexadecimal](https://www.geeksforgeeks.org/how-to-convert-binary-to-hexadecimal/)
- [Stack abstract data type](https://en.wikipedia.org/wiki/Stack_(abstract_data_type))

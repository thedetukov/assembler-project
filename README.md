## Assemble project

Introduction to assembler.
Assembly language is a low-level language that is used 
within an operating system to automatically 
convert a source program (given to a computer) into machine language.

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
cd assembler-project/assembler-1
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
1. AVR instraction set
```shell
http://lyons42.com/AVR/Opcodes/AVRAllOpcodes.html
```
1. Delay in assembly for avr microcontrollers
```shell
https://stackoverflow.com/questions/24097526/how-to-make-a-delay-in-assembly-for-avr-microcontrollers
```
1. Read the fuses with avrdude
```shell
https://stackoverflow.com/questions/74260385/how-to-read-the-fuses-with-avrdude
```
1. Convert Binary to Hexadecimal
```shell
https://www.geeksforgeeks.org/how-to-convert-binary-to-hexadecimal/
```

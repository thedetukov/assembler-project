## Assemble projects

    Introduction to assembler.
    Assembly language is a low-level language that is used 
    within an operating system to automatically 
    convert a source program (given to a computer) into machine language.

## Commands
    Install avrdude on Gentoo linux
    ```shell
    emerge -av dev-embedded/avrdude
    ```
    Read the fuses with avrdude
    ``` shell
    avrdude -c usbasp -p t2313 -U hfuse:r:-:h -U lfuse:r:-:h
    ```
    Read flash memory
    ```shell
    avrdude -p t2313 -c usbasp -U flash:r:/tmp/flash_dump.hex:r
    ```
    Read eeprom memory
    ```shell
    avrdude -p t2313 -c usbasp -U eeprom:r:/tmp/eeprom_dump.raw:r
    ```

## Get Started

1. Clone the repository
	```shell
	git clone git@github.com:thedetukov/assembler-project.git
	```
2. Enter into cloned directory
	```shell
	cd assmbler-project/assembler-1
	```
3. Generate hex file command
    ```shell
    avra 1-1.asm
    ```
4. Start program
    ```shell
    avrdude -p t2313 -c usbasp -U flash:w:1-1.hex:i
    ```

## References
1. AVR instraction set
    ```shell
    http://lyons42.com/AVR/Opcodes/AVRAllOpcodes.html
    ```
2. Delay in assembly for avr microcontrollers
    ```shell
    https://stackoverflow.com/questions/24097526/how-to-make-a-delay-in-assembly-for-avr-microcontrollers
    ```
3. Read the fuses with avrdude
    ```shell
    https://stackoverflow.com/questions/74260385/how-to-read-the-fuses-with-avrdude
    ```
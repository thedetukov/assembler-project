.DEVICE ATtiny2313A

; Config PORTB and PORTD for output
SER r16 ; set 0xff
OUT $11,r16
OUT $17,r16 

LDI r19, 0x0
RCALL EEPROM_read
MOV r4, r20

LDI r19, 0x1
RCALL EEPROM_read
MOV r5, r20


loop:
RCALL EEPROM_read

SER r30
SER r31


RCALL set_and_sleep

INC r19
CPI r19, 128
BRNE loop
LDI r19, 2

RJMP loop

#include "1-common.inc"


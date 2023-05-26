.DEVICE ATtiny2313A

; Configure PORTB and PORTD for output
SER r16 ; set 0xff
OUT $11,r16
OUT $17,r16

begin:

LDI r30,0xf5
LDI r31,0xfa
RCALL set_and_sleep

LDI r30,0xea
LDI r31,0xfd
RCALL set_and_sleep

RJMP begin

#include "1-common.inc"

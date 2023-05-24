.DEVICE ATtiny2313A

; Configure PORTB and PORTD for output
SER r16 ; set 0xff
OUT $11,r16
OUT $17,r16

begin:

;1
LDI r30,0xfc
LDI r31,0xff
RCALL set_and_sleep








;2
LDI r30,0xf9
LDI r31,0xff
RCALL set_and_sleep

;3
LDI r30,0xf3
LDI r31,0xff
RCALL set_and_sleep


;4
LDI r30,0xe7
LDI r31,0xff
RCALL set_and_sleep


;5
LDI r30,0xef
LDI r31,0xfe
RCALL set_and_sleep


;6
LDI r30,0xff
LDI r31,0xfc
RCALL set_and_sleep


;7
LDI r30,0xff
LDI r31,0xf1
RCALL set_and_sleep


;8
LDI r30,0xfe
LDI r31,0xfb
RCALL set_and_sleep


RJMP begin


#include "1-common.inc"

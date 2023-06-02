

sleep:

POP r26
POP r27
POP r28
POP r29

	MOV		r21,	r28
sleep_1:
	MOV		r22,	r29
sleep_2:
	LDI		r23,	250
sleep_3:
	DEC		r23
	NOP
	BRNE	sleep_3

	DEC		r21
	BRNE	sleep_2

	DEC		r22
	BRNE	sleep_1

PUSH r27
PUSH r26

RET

set_and_sleep:
	OUT $18,r30
	OUT $12,r31
	RCALL sleep
RET

; This function does not take any parameters.
; and does not perform any operations.
halt:
	NOP
	RJMP halt

; To the address, if we want to read it, put it in register r19,
; subtracting the result is put into register r20
; This should be registered on port $1d.
EEPROM_read:
	; Wait for completion of previous write;
	SBIC 0x1c,1 ; Check 1(EEPE) to bit 1 of EECR
	RJMP EEPROM_read
	; Set up address in address registers;
	OUT $1e,r19 ; EEAR;
	
	; Start eeprom read by writing EERE;
	SBI 0x1c,0 ; Set 1(EERE) to bit 0 of EECR
	; Read data from data register;
	IN r20,$1d ; EEDR;
	RET


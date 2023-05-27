; This function delays the operation of the microcontroller.
; With this algorithm the microcontroller can't do anything else 
; while executing the delay because you are using it to count cycles.

sleep:
	MOV		r21,	r4		; One clock cycle;
sleep_1:
	MOV		r22,	r5		; One clock cycle;
sleep_2:
	LDI		r23,	250		; One clock cycle;
sleep_3:
	DEC		r23				; One clock cycle;
	NOP						; One clock cycle;
	BRNE	sleep_3			; Two clock cycles when jumping to sleep_3, 1 clock when continuing to DEC;

	DEC		r22				; One clock cycle;
	BRNE	sleep_2			; Two clock cycles when jumping to sleep_2, 1 clock when continuing to DEC;

	DEC		r21				; One clock cycle;
	BRNE	sleep_1			; Two clock cycles when jumping to Delay1, 1 clock when continuing to RET;
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


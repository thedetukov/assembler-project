sleep:
	POP		r21
sleep_1:
	POP		r22
sleep_2:
	LDI		r23,	250
sleep_3:
	DEC		r23
	NOP
	BRNE	sleep_3

	DEC		r22
	BRNE	sleep_2

	DEC		r21
	BRNE	sleep_1
RET

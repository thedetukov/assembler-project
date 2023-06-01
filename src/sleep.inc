POP r26
POP r27
POP r28
POP r29

sleep:
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

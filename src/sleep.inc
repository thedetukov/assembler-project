#include "tn2313def_for_avra.inc"

LDI R16, LOW(RAMEND)		; установливаем указатель стека на последний адрес ОЗУ
OUT SPL, R16				; записать в SPL значение из R16

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

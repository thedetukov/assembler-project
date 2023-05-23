sleep:
    LDI     r21,   2
sleep_1:
    LDI     r22,   125     
sleep_2:
    LDI     r23,   250     
sleep_3:
    DEC     r23            
    NOP                     
    BRNE    sleep_3          

    DEC     r22            
    BRNE    sleep_2          

    DEC     r21            
    BRNE    sleep_1
RET

set_and_sleep:
    OUT $18,r30
    OUT $12,r31
    RCALL sleep
RET

halt:
    NOP
RJMP halt
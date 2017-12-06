CODE SEGMENT
ASSUME CS:CODE,DS:CODE,ES:CODE,SS:CODE

    PPIC_Control EQU 1EH
    PPIC EQU 1CH 
    PPIB EQU 1AH
    PPIA EQU 18H

    ORG 1000H
    
    MOV AL, 10000000B
    OUT PPIC_Control, AL     ; Take PortA, PortB, PortC to output modes
    
    MOV AL, 11111111B
    OUT PPIC, AL             ; Since all columns should be lit at the same time
    
    MOV AL, 11111111B
    OUT PPIA, AL             ; We'll never light up the green lights
                             ; So, output 11111111 to turn off all green outputs
    
L1: MOV AL, 11111110B        ; Since only one row to be lit at a time
    MOV CX, 08H
L2: OUT PPIB, AL
    CALL TIMER
    STC
    ROL AL, 1
    LOOP L2
    JMP L1
    INT 3

; TIMER procedure    
TIMER: PUSH CX
       MOV CX, 8FFFH
TIMERLOOP: NOP
    NOP
    NOP
    NOP
    LOOP TIMERLOOP
    POP CX
    RET
    ;
CODE ENDS
END

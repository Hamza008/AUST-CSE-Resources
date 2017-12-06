CODE SEGMENT
    ASSUME CS:CODE,DS:CODE,ES:CODE,SS:CODE
    
    PPIC_Control EQU 1EH
    PPIC EQU 1CH
    PPIB EQU 1AH
    PPIA EQU 18H
    
    ORG 1000H
    MOV AL, 10000000B
    OUT PPIC_Control, AL
    
    MOV AL, 11111111B
    OUT PPIA, AL
    
L1: MOV AH, 00000001B
    CALL DISPLAY_A
    JMP L1
    

; Calling this procedure destroys AH
DISPLAY_A:
    MOV SI, OFFSET FONT
    MOV CX, 08H
DISPLOOP: MOV AL, BYTE PTR CS:[SI]
    OUT PPIB, AL    
    MOV AL, AH
    OUT PPIC, AL
    CALL TIMER
    INC SI
    CLC
    ROL AH, 1
    LOOP DISPLOOP
    RET
    ;


; TIMER procedure
TIMER:  PUSH CX
        MOV CX, 300
TIMER1: NOP
        NOP
        NOP
        NOP
        LOOP TIMER1
        POP CX
        RET
        ;


FONT:   DB 11111111B        ; Mask for the column on the far left
        DB 11000000B
        DB 10110111B
        DB 01110111B
        DB 01110111B
        DB 10110111B
        DB 11000000B
        DB 11111111B        ; Mask for the column on the far right
        ;

CODE ENDS
END

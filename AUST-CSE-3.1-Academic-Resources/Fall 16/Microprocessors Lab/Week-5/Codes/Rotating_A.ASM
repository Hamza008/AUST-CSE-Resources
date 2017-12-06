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
    
    MOV BL, 1H
L1: MOV AH, BL
    CALL MANY_TIMES_A
    CLC
    ROR BL, 1
    JMP L1
    
; Displays the letter 'A' 50 times, so ensure that 'A' is displayed
; for a long time at a fixed position before rotating it to the left
; --------- Calling this procedure destroys AH, maintains CX
MANY_TIMES_A:
    PUSH CX
    MOV CX, 50 ; Show this letter 50 times
MTA_L: CALL DISPLAY_A
    LOOP MTA_L
    POP CX
    RET
    ;

	
; Displays 'A' once at a position
; --------- Calling this procedure destroys AH, maintains CX
DISPLAY_A:
    PUSH CX
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
    POP CX
    RET
    ;


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


FONT:   DB 11111111B
        DB 11000000B
        DB 10110111B
        DB 01110111B
        DB 01110111B
        DB 10110111B
        DB 11000000B
        DB 11111111B
        ;

CODE ENDS
END


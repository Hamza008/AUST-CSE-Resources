CODE SEGMENT
        ASSUME CS:CODE
        PPI_Control EQU 1FH
        PPIA EQU 19H

        ORG 1000H

        MOV AL, 10000000B
        OUT PPI_Control, AL

        MOV AX, 1000H
        MOV DS, AX

L2:     MOV SI, 0H        ; Now, DS:SI = 10000:0000
        MOV CX, 0AH
L1:     MOV AL, BYTE PTR DS:[SI]
        CMP CX, 00H
        JE L2
        OUT PPIA, AL
        CALL TIMER
        CALL TIMER
        CALL TIMER
        INC SI
        DEC CX
        JMP L1

        INT 3

; Write the TIMER procedure now
TIMER:  PUSH CX
        MOV CX, 8FFFH
TIMER1: NOP
        LOOP TIMER1
        POP CX
        RET


; Masks = C0, F9, A4, B0, 99, 92, 82, F8, 80, 90

CODE ENDS
END

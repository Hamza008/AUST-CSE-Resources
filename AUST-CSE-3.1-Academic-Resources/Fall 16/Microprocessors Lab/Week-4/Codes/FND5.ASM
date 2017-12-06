CODE SEGMENT
        ASSUME CS:CODE
        PPI_Control EQU 1FH  ; 'EQU' is similar to macro in C
        PPIA EQU 19H

        ORG 1000H

        MOV AL, 10000000B
        OUT PPI_Control, AL  ; Now PortA is in output mode

        MOV AL, 92H           ; The bitmask for the digit 5
        OUT PPIA, AL         ; Display the digit!
        INT 3

CODE ENDS
END

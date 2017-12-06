CODE SEGMENT
    ASSUME CS:CODE
    ORG 1000H
    
    MOV AX, 1000H
    MOV DS, AX
    MOV SI, 0H
    MOV CX, 6H ; We want to calculate factorial(CX)
    CALL fact
    MOV WORD PTR DS:[SI], AX
    HLT


fact:
    CMP CX, 0H
    JNE COMPUTE_FACT
    MOV AX, 1H
    JMP RETURN_LABEL
COMPUTE_FACT:
    DEC CX
    CALL fact
    INC CX
    MUL CX
RETURN_LABEL:
    INT 3


CODE ENDS
END

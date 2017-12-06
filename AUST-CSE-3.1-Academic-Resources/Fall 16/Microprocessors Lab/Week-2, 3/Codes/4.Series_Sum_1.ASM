CODE SEGMENT
    ASSUME CS:CODE
    ORG 1000H
    
    MOV AX, 1000H
    MOV DS, AX
    MOV SI, 0H ; DS:SI = 1000H:0000H
    MOV CX, 9H ; Load the value of 'n' in CX
    MOV AX, 0H ; Initially SUM = 0
LOOPLABEL:
    ADD AX, CX
    DEC CX
    CMP CX, 0H
    JNE LOOPLABEL
    
    MOV WORD PTR DS:[SI], AX
	INT 3
   
CODE ENDS
END

CODE SEGMENT
    ASSUME CS:CODE
    ORG 1000H
    
    MOV AX, 1000H
    MOV DS, AX
    MOV SI, 0H ; DS:SI = 1000H:0000H
    MOV AX, 005AH ; Load the number of which we want to check the parity of, into AX
    TEST AX, 0001H ; TEST instruction is similar to AND instruction
    JZ EVEN
    JNZ ODD
EVEN:
    MOV BL, 0H
    JMP DONE
ODD:
    MOV BL, 1H
    JMP DONE
DONE:
    MOV DS:[SI], BL
    INT 3
   
CODE ENDS
END

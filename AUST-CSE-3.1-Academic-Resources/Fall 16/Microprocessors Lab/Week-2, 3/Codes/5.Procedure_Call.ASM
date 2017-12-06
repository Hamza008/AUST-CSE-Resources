CODE SEGMENT
    ASSUME CS:CODE
    ORG 1000H
    
    
    MOV AX, 1000H
    MOV DS, AX
    MOV SI, 0H ; DS:SI = 1000H:0000H
    MOV CX, 09H ; Load the value of 'n1' to CX
    CALL series_sum ; Now AX hold the value of the sum 1+2+...n1
    MOV WORD PTR DS:[SI], AX
    MOV CX, 64H ; Load the value of 'n2' to CX
    CALL series_sum ; Now AX hold the value of the sum 1+2+...n2
    ADD SI, 2H
    MOV WORD PTR DS:[SI], AX
    INT 3

series_sum:
    PUSH CX ; Make a backup of the value stored in CX during procedure call
    MOV AX, 0H
LOOP_LABEL:
    ADD AX, CX
    LOOP LOOP_LABEL
    POP CX
    RET
   
CODE ENDS
END
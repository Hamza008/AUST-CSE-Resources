CODE SEGMENT ; We start a segment named 'CODE'
    ASSUME CS:CODE ; We tell the assembler to point the CS register to the segment named 'CODE'
    ORG 1000H ; ORG is an indication on where to put the next piece of code/data, related to the current segment.
	
    MOV AX, 1234H
    MOV BX, 4321H
    ADD AX, BX
    INT 3
   
CODE ENDS
END

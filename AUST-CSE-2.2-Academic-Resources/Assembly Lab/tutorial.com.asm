
;DS<=64kb CS<=64kb
.model small 


;the is stack, SP = Stack pointer(top of the stack),BP = Base pointer(bottom of the stack),
; at begining SP = 254, and with push it starts decreasing
.stack 256 


;this is the data section, where all the variables are declared
.data
message db ?

;the code section, where all all codes are written
.code
main proc ;intializing the procedure with name "main"
    
mov ax, @data  
mov ds, ax     ;initialize the DS(data segment) register, or else garbage value would be printed

                
lea dx, message
mov ah, 09h    ;print string
int 21h
                    


mov ah, 4ch    ;exits the program
int 21h

main endp




.model small
.stack 256 


;this is the data section, where all the variables are declared
.data


;the code section, where all all codes are written
.code
ProgramStart:
                    

;returns the program
mov ah, 4ch
int 21h

end ProgramStart




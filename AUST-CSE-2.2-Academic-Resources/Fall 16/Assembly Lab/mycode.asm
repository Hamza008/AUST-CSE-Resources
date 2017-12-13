.model small
.stack 100h
.data
    msg1 db " Out of Range $"  
    msg2 db " In Range $"
.code
main proc
     mov ax, @data
     mov ds, ax
     
     mov ah, 01h
     int 21h
     
     mov ch, al
     sub ch, '0' 
     
     mov ah, 09h
     
     

     cmp ch, 3
     jge skip2
skip1:     
     lea dx, msg1
     int 21h
     jmp skip3     
 
skip2:     
     lea dx, msg2
     int 21h
      
      
skip3:      
     mov ah, 4ch
     int 21h
    
    
main endp    
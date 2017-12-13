.model small
.stack 256

.data
msg1 db "Enter num1 : $"
msg2 db "Enter num2 : $"
num1 db ?
num2 db ?

.code
main proc
     
     mov ax, @data
     mov ds, ax
     
     mov ah, 09h
     lea dx, msg1
     int 21h
     
     mov ah, 01h
     int 21h
     
     mov num1, al
     sub num1, 30h
     
     mov ah, 09h
     lea dx, msg2
     int 21h
     
     mov ah, 01h
     int 21h
     
     mov num2, al
     sub num2, 30h
     
     mov dl, num1
     add dl, num2
     add dl, 30h
     
     mov ah, 02h
     int 21h
    
     mov ah, 4ch
     int 21h
     
main endp    
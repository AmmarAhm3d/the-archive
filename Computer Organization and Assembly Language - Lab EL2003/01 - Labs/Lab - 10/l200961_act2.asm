[org 0x0100]
mov ah, 0
mov al, 13h
int 10h
mov cx, x
mov dx, y
mov al, c
l11:  
        inc dx
        mov ah, 0ch 
        int 10h
        inc cx
        cmp cx, x+w
        jbe l11

mov al, 13h
int 10h
;mov cx, x
;mov dx, y
mov al, c
l111:    dec dx
        mov ah, 0ch
        int 10h
        inc cx
        cmp cx, x+w+w+1
        jbe l111
mov al, 13h
int 10h
mov cx, x
mov dx, y
mov al, c
l1111:     dec dx
        mov ah, 0ch 
        int 10h
        inc cx
        cmp cx, x+w
        jbe l1111

mov al, 13h
int 10h
mov al, c
l11111:    inc dx
        mov ah, 0ch ; put pixel
        int 10h
        inc cx
        cmp cx, x+w+w
        jbe l11111
mov ah,00
int 16h
mov ax, 0x4c00
int 0x21
x equ 80
y equ 100
c equ 90
w equ 70
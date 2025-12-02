[org 0x0100]
    mov si,0
    mov di,0
jmp start
S1: db 2,4,5,7,9
S2: db 1,3,4,6,7
S: db 0, 0, 0, 0, 0
start:
L1: mov al,[S1+si]
    mov bl,[S2+di]
    cmp al,bl
    je Xd
    cmp al,bl
    jl Xd
    mov dx,0
    mov dl,al
    add di,1
    cmp di,5
    jne L1

Xd: add si,1
    cmp si,5
    je end
    jmp L1

end:    
mov ax, 0x4c00
int 0x21

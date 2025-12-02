[org 0x0100]

jmp start
    sum: dw 0
    l: dw 0
    r: dw 0

seperate_dig_sum:
    push ax
    push bx
    push cx
    push dx


    mov dx, 0
    mov bx, 0x10
    mov cx, 4
    l1:
        div bx
        add [sum], dx
        loop l1

    pop dx
    pop cx
    pop bx
    pop ax
ret

start:
    mov ax, 0x0961
    call seperate_dig_sum
    mov ax, [sum]
    shr ax, 2
    mov [r], ax
    add ax, 3
    mov [l], ax

mov ax, 0x4c00
int 0x21
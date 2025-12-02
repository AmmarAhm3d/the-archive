[org 0x0100]

	jmp start

	num1: dw 111,999,888,11,99,88,88,1,9,8,8

	start:
	mov ax,0
	mov bx,0
	loop1:
	add ax,[num1 + bx]
	add bx,2
	sub cx,2
	cmp bx,22
	jnz loop1

mov ax,0x4c00

int 0x21
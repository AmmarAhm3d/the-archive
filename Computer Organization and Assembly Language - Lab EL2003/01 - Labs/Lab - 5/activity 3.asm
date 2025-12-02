[org 0x0100]
	mov ax,8
	mov cx,0
	mov bx,0
	l2:	cmp ax,[array+bx]
		je l1

	l1:	add cx,1
		add bx,2
		cmp bx,22
		jne l2

mov ax, 0x4c00 ;    terminate the program
int 0x21
array: dw 1,9,9,9,8,8,8,8,8,8,1,1,9,9,8,8,8,8,1,9,8,8

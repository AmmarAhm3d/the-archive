[org 0x0100]
	
	mov dx,0
	mov ax,[array]
	mov bx,2
	mov cx,10
	
	l1:
		cmp ax,[array+bx]
		ja scenario
		mov dx,[array+bx]
		mov ax,dx
		add bx,2
		sub cx,1
		jz finish
		jmp l1

	scenario:
		mov dx,ax
		add bx,2
		sub cx,1
		jz finish
		jmp l1


finish:
	mov ax,0x4c00
	int 0x21

array: dw 111, 999, 888, 888, 11, 99, 88, 88, 1, 9, 8, 8
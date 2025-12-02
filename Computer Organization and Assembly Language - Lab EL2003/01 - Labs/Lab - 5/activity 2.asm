[org 0x0100]
	jmp start
	bin:
		push bp
		mov bp,sp
		push ax
		push bx
		push dx
		push cx
		push si
		push di
		mov cx,0
		mov dx,0
		mov bx,[bp+4]
	l1:
		shr bx,1
		jnc X
		add dx,1
	X:
		add cx,1
		cmp cx,16
		jne l1
		pop di
		pop si
		pop cx
		pop dx
		pop bx
		pop ax
		pop bp 
		ret 2


	start:	 
	mov ax,0x0961
	push ax
	call bin

mov ax,0x4c00
int 0x21
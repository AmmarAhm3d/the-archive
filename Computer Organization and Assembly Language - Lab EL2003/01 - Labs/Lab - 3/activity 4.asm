[org 0x0100]

	jmp start
	num: dw 4
	
	start:
		mov dx, [num]
		mov cx, [num]
		mov bx, [num]
		jmp l1
	
	l2:
		add cx,dx
		sub ax, 1
		cmp ax,1
		jne l2
		mov dx, cx
		jmp l1
		
	l1:
		sub bx, 1
		mov ax, bx
		cmp ax,1
		jne l2
		jmp terminate
	
 terminate:
	 mov ax, 0x4c00 ; terminate program
	 int 0x21
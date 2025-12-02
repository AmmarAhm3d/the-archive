[org 0x0100]

	jmp start
	array: dw 1, 9, 9,9, 8, 8,8, 8, 8,8, 1, 1, 9, 9, 8, 8, 8, 8, 1, 9, 8, 8
	num: dw 8	;suppose 8 is the element we want to find
	
	start:
		mov bx, array
		mov cx, 22 		;22 is size of array variable
		mov ax, [num]
		mov dx, 0
		jmp check
	
	check:
		cmp ax, bx
		je compare
		add bx, 2
		sub cx, 1
		jnz check
		jmp terminate
	
	compare:
		add dx, 1
		add bx, 2
		sub cx, 1
		jnz check
		jmp terminate
	
	
 terminate:
	 mov ax, 0x4c00 ; terminate program
	 int 0x21
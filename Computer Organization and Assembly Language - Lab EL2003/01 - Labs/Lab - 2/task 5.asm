[org 0x0100] ;we will see org directive later
	
	jmp start 

	fib_nums: dw 0,0,0,0,0,0,0,0,0,0

	start:
	mov bx, fib_nums

	mov word [bx], 0
	add bx, 2
	mov word [bx],1
	add bx,2

	mov si, fib_nums 
	mov di, fib_nums
	add di, 2
	mov word cx,4

	loop1:
	 add ax, [si]
	 add ax, [di]
	 mov [bx], ax
	 add bx,2
	 add di,2
	 add si,2
	 add cx,2
	 mov word ax,0
	 cmp cx, 20
	jne loop1 
		
		
mov ax, 0x4c00 ;terminate the program
int 0x21
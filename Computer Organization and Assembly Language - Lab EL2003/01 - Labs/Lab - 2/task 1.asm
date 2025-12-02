[org 0x0100] ;we will see org directive later
	
	mov ax, 0
	mov ax, 25h		;load 25h
	mov bx, 0
	mov dx, bx
	mov bx, ax		;swapping
	mov ax, dx
	mov cx, 0
	mov cx, [0x270]	;load the content
	mov ax, [num]
	mov ax, [num+2]
	mov ax, [num+4]
	mov dx, 0
	mov dx, [num+4]
	mov dx, [num+2]
	mov dx, [num]
	
mov ax, 0x4c00 ;terminate the program
int 0x21

num: dw 12,25,10
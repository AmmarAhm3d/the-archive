[org 0x0100] ;we will see org directive later
	
	mov ax,0
	mov bx,0
	mov cx,0
	mov ax, 200h
	mov bx, 150h
	mov word [250], 50h
	mov word [200], 25h
	mov bx, [200]
	mov ax, bx
	mov cx, [0x250]
	
mov ax, 0x4c00 ;terminate the program
int 0x21

arr: dw 1,2,7,5,10
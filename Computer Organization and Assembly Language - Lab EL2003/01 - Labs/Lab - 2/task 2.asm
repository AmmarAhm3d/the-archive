; a program to add ten numbers 
[org 0x0100] 
	 mov bx, num1 	; point bx to first number 
	 mov cx, 10 	; load count of numbers in cx 
	 mov ax, 0 		; initialize sum to zero 
	l1: 
		add ax, [bx] ; add number to ax 
		add bx, 2 	; advance bx to next number 
		sub cx, 1 	; numbers to be added reduced 
		jnz l1 		; if numbers remain add next 
	 mov [total], ax ; write back sum in memory 

mov ax, 0x4c00 ; terminate program 
int 0x21 

num1: dw 10, 20, 30, 40, 50, 10, 20, 30, 40, 50 
total: dw 0
n1: dw 10
n2:	dw 20
n3: dw 30
n4: dw 40
n5: dw 50
sum: dw 0
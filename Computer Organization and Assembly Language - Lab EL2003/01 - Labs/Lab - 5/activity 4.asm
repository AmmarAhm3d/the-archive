[org 0x100]

	mov ax, 0961h
	mov [num1], ax
	not ax
	mov bx, ax
	mov [num2], bx
	not ax

	mov cx, 17
	l1: shr ax, 1
		jnc s1
		add [mulr], bx

	s1: shl bx, 1
		dec cx
		cmp cx, 1
		jnc l1          
		
	mov ax, [num1]
	mov [conc], ax
	mov bx, [num2]
	mov [conc + 2], bx

	mov ax, [conc]
	add [mulr], ax
	mov ax, [conc + 2]
	adc [mulr + 2], ax

	mov ax, [mulr]
	mov bx, [mulr + 2]

mov ax, 0x4c00
int 0x21

f: dd 0
num1: dd 0
num2: dd 0
conc: dd 0
mulr: dd 0
[org 0x0100]

	mov ax, 0961
	mov bx, ax
	not bx
	mov word [multiplicand], ax
	mov word [multiplier], bx
	
	mov cl, 16
	mov bx, 1
	
	checkbit:
		test bx, [multiplier]
		jz skip
		
		
		mov ax, [multiplicand]
		add [result], ax
		mov ax, [multiplicand + 2]
		adc [result + 2], ax
		
	skip:
		shl word [multiplicand], 1
		rcl word [multiplicand + 2], 1
		shl bx , 1

	dec cl
	jnz checkbit
	
	mov ax, 0961
	mov bx, ax
	not bx
	
	add bx, [result]
	adc ax, [result+2]
	
	mov [f], bx
	mov [f+2], ax

	mov ax, 0x4c00
	int 0x21
	
f: dd 0

multiplicand: dd 0961
multiplier: dw 0
result: dd 0
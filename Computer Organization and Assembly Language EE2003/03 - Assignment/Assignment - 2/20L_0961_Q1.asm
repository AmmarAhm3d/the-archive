[org 0x0100] 
jmp start
num1:db 0101000111100111b
num2:db 111100b
len1: dw 16
len2: dw 6
startIndex: dw 0
flag: dw 0
	
	func:
		mov ax,[num1]
		mov bx,[num2]
		mov cx,[len2]
		mov si,0
		mov di,0
		mov dx,[len1]

	s7:
		rcr byte[num1],1
		jc s10
		jmp s3

	s10:	mov si,1
			jmp s4

	s3:	mov si,0

	s4:	rcr byte[num2],1
		jc s5
		jmp s6

	s5:	mov di,1
		jmp s9

	s6:	mov di,0

	s9:
		cmp si,di
		jne s8

		dec dx
		cmp dx,0
		je return
		dec cx
		cmp cx,1
		jne s7
		dec dx
		mov word [startIndex],dx
		mov word [flag],1
		ret

	s8:
		mov cx,[len2]
		mov [num2],bx
		dec dx
		cmp dx,0
		jne s7

	return:	mov word[flag],-1
			ret

	start:
		call func
		mov ax,[flag]
		mov ax,[startIndex]

mov ax,0x4c00
int 21h
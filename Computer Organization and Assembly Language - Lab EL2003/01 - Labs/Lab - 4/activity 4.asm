[org 0x0100]

	jmp start
	f:dw 0
	start:
		mov ax,1105
		not ax
		mov bx,ax
		mov ax,1105
		or ax,bx
		mov dx,ax
		mov ax,1105
		xor ax,0x1bcd
		and dx,ax
		mov [f],dx

mov ax, 0x4c00 ; terminate program
int 0x21
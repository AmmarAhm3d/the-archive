[org 0x0100]
	jmp start
	
	clrscr:
		push bp
		mov bp,sp
		mov es,[bp+6]
		mov di,0
	l1:
		mov word [es:di],0x0721
		add di,2
		cmp di,[bp + 4]
		jnz l1

		ret 4

	start:
		mov ax,0xb800
		push ax
		mov ax,4000
		push ax
		call clrscr


mov ax,0x4c00
int 0x21
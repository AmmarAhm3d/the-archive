[org 0x0100]

	jmp start

	;calling nested loops
	delay:
	mov cx, oxffff
	d0:	loop d0
	mov cx, 0xffff
	d1:	loop d1
	mov cx, 0xffff
	d2:	loop d2
	mov cx, 0xffff
	d3:	loop d3
	mov cx, 0xffff
	d4:	loop d4
	mov cx, 0xffff
	d5:	loop d5
	mov cx, 0xffff
	d6:	loop d6
	mov cx, 0xffff
	d7:	loop d7
	mov cx, 0xffff
	d8:	loop d8
	mov cx, 0xffff
	d9:	loop d9
	ret
	
	start:
	call delay

mov ax, 0x4c00
int 0x21
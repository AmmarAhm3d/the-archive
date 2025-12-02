[org 0x0100]
	
	num : db 4
	jmp start

	start:
		mov cl, 4
		mov bl,[num]
		mov dl,[num]

	checkbit :
		shr dl, 1
		jnc skip

	add al,bl

	skip :
		shl bl,1
		dec cl	
		jnz checkbit 

mov ax, 0x4c00
int 0x21
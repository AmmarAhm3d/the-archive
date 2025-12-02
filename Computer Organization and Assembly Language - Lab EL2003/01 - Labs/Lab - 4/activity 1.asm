[org 0x0100]

 start:				
	mov ax,  0x0961
	mov bx, 1010101010101010b
	mov dx, 0101010101010101b
	and bx,ax
	and dx,ax
	shr bx,1
	shl dx,1
	or bx,dx
	mov ax,bx
	
mov ax, 0x4c00
int 0x21
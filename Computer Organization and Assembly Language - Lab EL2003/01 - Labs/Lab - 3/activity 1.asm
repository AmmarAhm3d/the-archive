[org 0x0100]

	mov ax, 0x1254	;ZF=0,CF=0,SF=0,OF=0
	mov bx, 0x0FFF	;ZF=0,CF=0,SF=0,OF=0
	add ax, 0xEDAB	;ZF=0,CF=0,SF=1,OF=0
	add ax, bx		;ZF=0,CF=1,SF=0,OF=0
	add bx, 0xF001	;ZF=1,CF=1,SF=0,OF=0
	
 mov ax, 0x4c00 ; terminate program
 int 0x21
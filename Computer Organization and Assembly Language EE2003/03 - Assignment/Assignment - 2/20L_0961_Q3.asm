[org 0x0100] 
	
	jmp start
	
	structure:	
			push bp
			mov bp,sp
			sub sp,8
			push word [bp + 2]
			push ax 			;pushing registers / 5 LVs
			push bx 
			push si
			push di 
			push cx 
				mov ax,[bp + 2]	;ret address in ax
				mov [bp - 8],ax	;this stores ra in proper location b4 ret call
				mov ax,[bp + 4]	;accessing 4 i/ps from stack
				mov bx,[bp + 6]
				mov cx,[bp + 8]
				mov dx,[bp + 10]
								; moving 3 o/ps to stack
				mov word [bp + 12],ax
				mov word [bp + 14],bx
				mov word [bp + 16],cx
				
			pop di
			pop si
			pop cx
			pop bx
			pop ax
			pop bp
			ret 10
			

	start:	
			sub sp,6
			mov ax,0x0201
			push ax
			mov ax,0x0202
			push ax
			mov ax,0x0203
			push ax
			mov ax,0x0204
			push ax
			call structure
			xor ax,ax
			xor bx,bx
			xor cx,cx
			pop ax
			pop bx
			pop cx
 
 mov ax, 0x4c00 ; terminate program 
 int 0x21
[org 0x0100] 
jmp start
array1: dw 6, 7,3, 9, 100, 5, 1, 50
lenArray: dw 8
swap : dw 0
minimum : dw 0
maximum: dw 0
median: dw 0

	bubblesort:
		push bp
		mov bp, sp
		push ax
		push bx
		push cx

		mov bx,[bp+6]
		mov cx, [lenArray]
		dec cx 
		shl cx, 1 ; turn into byte count
		mainloop: mov si, 0 
				  mov byte [swap], 0 
		innerloop: 
			 mov ax, [bx+si] 
			 cmp ax, [bx+si+2] 
			 jbe noswap 

			 mov dx, [bx+si+2]
			 mov [bx+si], dx 
			 mov [bx+si+2], ax 
			 mov byte [swap], 1 
		noswap: 
			 add si, 2 
			 cmp si, cx 
			 jne innerloop 

			 cmp byte [swap], 1
			 je mainloop
		mov bx,array1
		pop cx
		pop bx
		pop ax
		pop bp
		ret

	statsofarray:
		call bubblesort
		push ax
		push bx
		push cx
		mov ax,[array1]
		mov [minimum],ax
		mov ax,[minimum]
		mov ax,[array1+14]
		mov [maximum],ax
		mov ax,[lenArray]
		mov bl, 2
		div bx
		mov cl, al
		mov bx,cx
		;mov ax,[array1+bx]
		mov [median], ax
		pop cx
		pop bx
		pop ax
		ret


	start:
		mov ax, array1
		push ax
		call statsofarray
mov ax, 0x4c00 
int 21h
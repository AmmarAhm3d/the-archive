; hello world in assembly
[org 0x0100]
	 jmp start
	 message1: db 'my name is ammar ahmed'
	 message2: db 'my roll # is 20L-'
	 message3: db  ',i love praying 5 times'
	 length1: dw 22
	 length2: dw 17
	 length3: dw 22
	clrscr: 
		 push es
		 push ax
		 push di 
		 mov ax, 0xb800
		 mov es, ax 
		 mov di, 0 

	nextloc: 
		 mov word [es:di], 0x0720 
		 add di, 2 
		 cmp di, 4000 
		 jne nextloc 
		 pop di
		 pop ax
		 pop es
		 ret

	printnum: 
		 push bp
		 mov bp, sp
		 push es
		 push ax
		 push bx
		 push cx
		 push dx
		 push di
		 mov ax, 0xb800
		 mov es, ax 
		 mov ax, [bp+4] 
		 mov bx, 10 
		 mov cx, 0 
	nextdigit: 
		 mov dx, 0 
		 div bx 
		 add dl, 0x30 
		 push dx 
		 inc cx 
		 cmp ax, 0 
		 jnz nextdigit 
		 mov di, 0 
	nextpos: 
		 pop dx 
		 mov dh, 0x07 
		 mov [es:di], dx 
		 add di, 2 
		 loop nextpos 
		 pop di
		 pop dx
		 pop cx
		 pop bx
		 pop ax
		 pop es
		 pop bp
		 ret 2
	printstr: 
		 mov bp, sp
		 push bp
		 push es
		 push ax
		 push cx
		 push si
		 push di
		 mov bx,[bp+8]
		 mov ax, 0xb800
		 mov es, ax 
		 mov di, bx
		 mov si, [bp+6] 
		 mov cx, [bp+4] 
		 mov ah, 0x07 
	nextchar: 
		 mov al, [si] 
		 mov [es:di], ax 
		 add di, 2 
		 add si, 1 
		 loop nextchar 
		 pop di
		 pop si
		 pop cx
		 pop ax
		 pop es
		 pop bp
		 ret 6

	start: 
		 call clrscr
		 mov bx,0
		 push bx
		 mov ax, message1
		 push ax 

		 push word [length1] 
		 call printstr

		 mov bx,22
		 push bx
		 mov ax, message2
		 push ax 
		 push word [length2] 
		 call printstr

		 mov bx,38
		 push bx
		 mov ax, 0x0961
		 push ax 
		 call printnum 

		 mov bx,60
		 push bx
		 mov ax, message3
		 push ax 
		 push word [length3] 
		 call printstr 


 mov ax, 0x4c00 
 int 0x21
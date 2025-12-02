[org 0x0100]

jmp start

clrscr:

	push es
	push ax
	push cx
	push di
	
	mov ax, 0xb800
	mov es, ax 
	xor di, di 
	mov ax, 0x0720 
	mov cx, 2000 
	cld 
	rep stosw 
	pop di 
	
	pop cx
	pop ax
	pop es
	ret 


printstr:

	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di
	push ds
	pop es 

	mov di, [bp+4] 
	mov cx, 0xffff 
	xor al, al 
	repne scasb 
	mov ax, 0xffff 
	sub ax, cx 
	dec ax 
	jz exit 

	mov cx, ax 
	mov ax, 0xb800
	mov es, ax 
	mov al, 80 
	mul byte [bp+8] 
	add ax, [bp+10] 
	shl ax, 1 
	mov di,ax 
	mov si, [bp+4] 
	mov ah, [bp+6] 
	cld 

nextchar:

	lodsb 
	stosw 
	loop nextchar 

exit: 
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 8


rev:
	push bp
	mov bp, sp
	push es
	push ax
	push cx
	push si
	push di
	push ds
	pop es 
	
	mov di, [bp+4] 
	mov cx, 0xffff 
	xor al, al 
	repne scasb 
	mov ax, 0xffff 
	sub ax, cx 
	sub ax,1
	
	mov cx,ax
	
	mov bx,[bp + 4]
	add bx,ax
	mov si,[bp + 6]

	l1:
		mov byte dl,[bx]
		mov byte [si],dl
		sub bx,1
		add si,1
		sub cx,1
		cmp cx,0
		jne l1
	
	mov byte [si + 1],0
	pop di
	pop si
	pop cx
	pop ax
	pop es
	pop bp
	ret 4
	

start:

call clrscr

mov ax,0
push ax
push ax
mov ax,0x07
push ax
mov ax,message1

call printstr

mov ax,message2
push ax
mov ax,message1
push ax

call rev

mov ax,1
push ax
push ax
mov ax,0x07
push ax
mov ax,message2

call printstr

mov ax,0x4c00
int 0x21

message1 : db 'I am Mr X',0
message2 : db ''

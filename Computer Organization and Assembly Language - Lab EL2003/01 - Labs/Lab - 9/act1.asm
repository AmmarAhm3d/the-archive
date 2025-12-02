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


copy:
	push bp
	mov bp, sp
	push ax
	push bx
	push cx
	push dx
	push si
	push di
	
	xor si,si
	xor di,di
	xor cx,cx
	mov bx,[bp + 6]
	mov di,[bp + 4]
l1:
	mov byte al,[bx + si]

	mov dl,0x20
	cmp al,dl
	je skip
	
	mov dl,0x21
	cmp al,dl
	je skip
	
	mov dl,0x2C
	cmp al,dl
	je skip

	mov dl,0x3F
	cmp al,dl
	je skip
	
	mov dx,0x2E
	cmp al,dl
	je skip 

	mov dl,0x26
	cmp al,dl
	je skip
	
	cmp al,cl
	je finish
	
	mov byte [di],al
	add si,1
	add di,1
	jmp l1
	
	skip:
		add si,1
		jmp l1
	
finish:
	mov byte [di],0
	pop di
	pop si
	pop dx
	pop cx
	pop bx
	pop ax
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
push ax

call printstr

mov ax,message1
push ax
mov ax,message2
push ax

call copy

mov ax,1
push ax
push ax
mov ax,0x03
push ax
mov ax,message2
push ax

call printstr

mov ax,0x4c00
int 0x21


message1 : db 'Mr. Ali, Usman, & Anwar! Doing what???? want to travel????',0
message2 : db ''



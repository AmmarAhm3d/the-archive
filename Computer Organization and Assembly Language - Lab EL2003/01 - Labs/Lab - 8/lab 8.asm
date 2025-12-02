[org 0x0100]

	jmp start
	message1: db 'Name: Ammar Ahmed',0 ; string to be printed 
	message2: db 'Institute: FAST School of Computing',0 
	message3: db 'Roll #: 21L-6246',0 
	message4: db 'Address: lahore pakistan',0 
	message5: db 'email ID: l200961@lhr.nu.edu.pk',0 
	clrscr:
	push es
	push ax
	push di
	mov ax , 0xb800
	mov es,ax
	mov di,0
	nextchar:
	mov word[es:di],0x0720
	add di,2
	cmp di,4000
	jne nextchar
	pop di
	pop ax
	pop es
	ret
	strlen: push bp 
	 mov bp,sp 
	 push es 
	 push cx 
	 push di 
	 les di, [bp+4] ; point es:di to string 
	 mov cx, 0xffff ; load maximum number in cx 
	 xor al, al ; load a zero in al 
	 repne scasb ; find zero in the string 
	 mov ax, 0xffff ; load maximum number in ax 
	 sub ax, cx ; find change in cx 
	 dec ax ; exclude null from length 
	 pop di 
	 pop cx 
	 pop es 
	 pop bp 
	 ret 4 
	sleep:
	push cx
	push dx
	mov dx,10
	sleep1:
	mov cx,0xFFFF
	delay:
	loop delay
	dec dx
	cmp dx,0
	jne sleep1
	pop dx
	pop cx
	ret

	printstr: push bp 
	 mov bp, sp 
	 push es 
	 push ax 
	 push cx 
	 push si 
	 push di 
	 push ds 
	 pop es ; load ds in es 
	 mov di, [bp+4] ; point di to string 
	 mov cx, 0xffff ; load maximum number in cx 
	 xor al, al ; load a zero in al 
	 repne scasb ; find zero in the string 
	 mov ax, 0xffff ; load maximum number in ax 
	 sub ax, cx ; find change in cx 
	 dec ax ; exclude null from length 
	 jz exit ; no printing if string is empty
	 mov cx, ax ; load string length in cx 
	 mov ax, 0xb800 
	 mov es, ax ; point es to video base 
	 mov al, 80 ; load al with columns per row 
	 mul byte [bp+8] ; multiply with y position 
	 add ax, [bp+10] ; add x position 
	 shl ax, 1 ; turn into byte offset 
	 mov di,ax ; point di to required location 
	 mov si, [bp+4] ; point si to string 
	 mov ah, [bp+6] ; load attribute in ah 
	 cld ; auto increment mode 
	nextchar1: lodsb ; load next char in al 
	 stosw ; print char/attribute pair 
	call sleep
	 loop nextchar1 ; repeat for the whole string 
	exit: pop di 
	 pop si 
	 pop cx 
	 pop ax 
	 pop es 
	 pop bp 
	 ret 8 
	start: 
	call clrscr ; call the clrscr subroutine 


	 mov ax, 0
	 push ax ; push x position 
	 mov ax, 0 
	 push ax ; push y position 
	 mov ax, 1 ; blue on black attribute 
	 push ax ; push attribute 
	 mov ax, message1 
	 push ax ; push address of message 
	 call printstr ; call the printstr subroutine 

	mov ax, 0
	 push ax ; push x position 
	 mov ax, 1 
	 push ax ; push y position 
	 mov ax, 1 ; blue on black attribute 
	 push ax ; push attribute 
	 mov ax, message2 
	 push ax ; push address of message 
	 call printstr ; call the printstr subroutine


	mov ax, 0
	 push ax ; push x position 
	 mov ax, 2
	 push ax ; push y position 
	 mov ax, 1 ; blue on black attribute 
	 push ax ; push attribute 
	 mov ax, message3 
	 push ax ; push address of message 
	 call printstr ; call the printstr subroutine

	mov ax, 0
	 push ax ; push x position 
	 mov ax, 3
	 push ax ; push y position 
	 mov ax, 1 ; blue on black attribute 
	 push ax ; push attribute 
	 mov ax, message4 
	 push ax ; push address of message 
	 call printstr ; call the printstr subroutine


	mov ax, 0
	 push ax ; push x position 
	 mov ax, 4
	 push ax ; push y position 
	 mov ax, 1 ; blue on black attribute 
	 push ax ; push attribute 
	 mov ax, message5 
	 push ax ; push address of message 
	 call printstr ; call the printstr subroutine


mov ax, 0x4c00
int 21h


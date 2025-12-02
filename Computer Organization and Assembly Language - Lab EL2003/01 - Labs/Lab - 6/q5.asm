 [org 0x0100]

 sum: dw 0
 r: dw 0
 l: dw 0
 f: dw 0

	jmp start

	
	sum_of_f:
		push ax
		push bx
		push cx
		push dx
		push di
		push si

		mov ax, 4 ; stores val
		mov bx, 4 ; multiplty ax with this number
		mov cx, 7 ; will run main loop
		mov si, -1 ; decides square of number

		mainloop:
			dec cx
			add [f], ax
			cmp cx, 0
			je exit
			add si, 1
			mov di, si
			mov ax, 4
			l2:
				mul bx
				cmp di, 0
				je mainloop
				dec di
				jmp l2

		exit:
			pop si
			pop di
			pop dx
			pop cx
			pop bx
			pop ax
			ret

	seperate_dig_sum:
		push ax
		push bx
		push cx
		push dx

		mov dx, 0
		mov bx, 0x10
		mov cx, 4
		l2:
			div bx
			add [sum], dx
			loop l2

		pop dx
		pop cx
		pop bx
		pop ax

		mov ax, [sum]
		shr ax, 2
		mov [r], ax
		add ax, 3
		mov [l], ax

		ret


	start:
		mov ax, 0x0961
		call seperate_dig_sum
		call sum_of_f
		mov ax, [f]

 mov ax, 0x4c00
 int 0x21
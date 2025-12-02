[org 0x100]

jmp start
message: db 'circle'
len: dw 6
ast :db '*' 
length1: dw 20 
length2: dw 5
p :db '+' len1: dw 20 m: db '-' len2:dw 5 


cls:

	push es 
	push ax 
	push di
	mov ax, 0xb800 
	mov es, ax ; 
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

print: push bp 
mov bp,sp 
push es 
push ax 
push cx 
push si 
push di
mov ax,0xb800 
mov es,ax

mov al,80
mul byte[bp+12] 
add ax,[bp+10] 
shl ax,1
mov di,ax
mov ah,[bp+8] 
mov si,[bp+6] 
mov cx,[bp+4] 
mov al,[si]
next1:
mov word[es:di],ax 
add di,2
loop next1
pop di 
pop si 
pop cx 
pop ax 
pop ax 
pop bp 
ret 10
print2: 
push bp 
mov bp,sp 
push es 
push ax 
push cx 
push si 
push di
mov ax,0xb800 
mov es,ax
mov al,80
mul byte[bp+12] 
add ax,[bp+10] 
shl ax,1
mov di,ax
mov ah,[bp+8]
 mov si,[bp+6]
 mov cx,[bp+4]
 mov al,[si]
next2:
mov word[es:di],ax add di,156
loop next2
pop di pop si pop cx pop ax pop ax pop bp ret 10
print3: push bp mov bp,sp

push es push ax push cx push si push di
mov ax,0xb800 mov es,ax
mov al,80
mul byte[bp+12] add ax,[bp+10] shl ax,1
mov di,ax
mov ah,[bp+8] mov si,[bp+6] mov cx,[bp+4] mov al,[si]
next3:
mov word[es:di],ax sub di , 164
loop next3
pop di pop si pop cx pop ax pop ax pop bp ret 10

printrec: push bp mov bp,sp push es push ax push cx push si push di
mov ax,0xb800 mov es,ax
mov al,80
mul byte[bp+12] add ax,[bp+10] shl ax,1
mov di,ax
mov ah,[bp+8] mov si,[bp+6] mov cx,[bp+4] mov al,[si]
next1:
mov word[es:di],ax add di,2
loop next1

pop di pop si pop cx pop ax pop ax pop bp ret 10
printrec2: push bp mov bp,sp push es push ax push cx push si push di
mov ax,0xb800 mov es,ax
mov al,80
mul byte[bp+12] add ax,[bp+10] shl ax,1
mov di,ax
mov ah,[bp+8] mov si,[bp+6] mov cx,[bp+4] mov al,[si]
next2:
mov word[es:di],ax add di,160
loop next2
pop di pop si pop cx pop ax pop ax pop bp ret 10


drawcircle:
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
	mov ax, [bp+8]  
	mov bx, 10  
	mov cx, 0  
	nextdigit: 
	mov dx, 0  
	div bx   
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
	mov word[es:di],0x0720
	add di,2
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
	push bp
	mov bp,sp	
	mov ax, 0xb800
	mov es,ax
	mov ax,0
	mov ah,0x09
	mov al,"*"

	mov di,2088
	mov word[es:di],ax

	mov di,1928
	mov word[es:di],ax

	mov di,1768
	mov word[es:di],ax

	mov di,1456
	mov word[es:di],ax

	mov di,1610
	mov word[es:di],ax

	mov di,1452
	mov word[es:di],ax

	mov di,1460
	mov word[es:di],ax

	mov di,1622
	mov word[es:di],ax

	mov di,1784
	mov word[es:di],ax

	mov di,1944
	mov word[es:di],ax

	mov di,2104
	mov word[es:di],ax

	mov di,2262
	mov word[es:di],ax

	mov di,2420
	mov word[es:di],ax


	mov di,2416
	mov word[es:di],ax

	mov di,2412
	mov word[es:di],ax

	mov di,2250
	mov word[es:di],ax

	mov al," "

	mov di,1460
	mov word[es:di],ax

	mov di,1452
	mov word[es:di],ax

	mov di,2412
	mov word[es:di],ax

	mov di,2420
	mov word[es:di],ax
		
	pop bp
	ret 8

drawdiamond:	
	;subroutine to draw diamond on screen
				push bp		;stack order: x [bp+4], y [bp+6]
				mov bp, sp
				push es
				push di
				push ax
				push cx
	mov ax, 0xb800
	mov es, ax
	mov al, 80
	mul byte [bp+6]
	add ax, [bp+4]
	shl ax, 1
	mov di, ax
	
	mov ax, 0x3F2A	;white asterisk on aqua background
	mov cx, 3
	rep stosw		;stosw-> mov [es:di], ax		rep-> repeats cx times
	
	add di, 156
	mov [es:di], ax
				
				pop cx
				pop ax
				pop di
				pop es
				pop bp
				ret 4	;x, y

start:
call cls
mov ax, message
push ax 
push word [len] 
call drawcircle

mov ax , 15
push ax
mov ax , 30
push ax
mov ax , 2
push ax
mov ax , ast push ax
push word [length1] call print
mov ax , 10
push ax
mov ax , 40
push ax
mov ax , 2
push ax
mov ax , ast push ax
push word [length2] call print2
mov ax , 15 push ax mov ax , 50 push ax mov ax , 2


push ax
mov ax , ast push ax
push word [length2] call print3

mov ax,9
push ax
mov ax,23
push ax
mov ax,4
push ax
mov ax,p push ax
push word[len1] call printrec
mov ax,13 push ax mov ax,23 push ax mov ax,4
;r ;c ;col

push ax
mov ax,p push ax
push word[len1] call printrec
mov ax,9
push ax
mov ax,23
push ax
mov ax,4
push ax
mov ax,m push ax
push word[len2] call printrec2
mov ax,9
push ax
mov ax,42
push ax
mov ax,4
push ax
mov ax,m push ax
push word[len2] call printrec2
mov ax,50
push ax
mov ax,60
push ax
call drawdiamond

end_:
mov ax,0x4c00
int 0x21
[org 0x100]
jmp strt
strlen:
           push bp
            mov bp, sp
            push di
            push es
            push ds

            push ds 
            pop es
            mov di, [bp+4]
            mov cx, 0xffff
            xor al, al
            repne scasb
            mov ax, 0xffff
            sub ax, cx
            dec ax

            pop ds
            pop es
            pop di
            pop bp
            ret

pstr:  	    push bp 
            mov bp, sp
            pusha

            mov ax, 0xb800 
            mov es, ax
            mov dx, 800
            
            mov cx, 4
            mov si, 10
            
            l1: push cx
                push si

                mov di, dx
                mov bx, [bp + si]

                mov si, bx
                push si
                call strlen
                pop si
                mov cx, ax

                mov ax, 0
                int 16h

                mov ah, 0x07

                cld
                nchar:   lodsb
                            stosw
                            loop nchar
                pop si
                pop cx
                sub si, 2
                add dx, 160
                loop l1

            popa
			pop bp
            ret



strt:
push m1
push m2
push m3
push m4
call pstr

mov ax, 0x4C00
int 0x21

m1: db 'Hi! I am Ammar.', 0
m2: db 'I am OK.', 0
m3: db 'I Study at FAST.', 0
m4: db 'My Roll No is 20L-0961.', 0
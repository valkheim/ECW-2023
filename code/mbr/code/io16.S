cls:
	push ax
	mov ax, 0x0003
	int 0x10
	pop ax
	ret

ln_16:
	push ax
	mov ah, 0x0e ; teletype output
	mov al, 0x0d ; carriage return
	int 0x10
	mov al, 0x0a ; newline
	int 0x10
	pop ax
	ret

print_16:
	pusha
	mov ah, 0x0e ; teletype output

_print_16_char:
	mov al, [bx]
	cmp al, 0
	je print_16_char_

	int 0x10
	inc bx
	jmp _print_16_char

print_16_char_:
	popa
	ret

println_16:
	call print_16
	call ln_16
	ret

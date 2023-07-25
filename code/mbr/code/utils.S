idle:
	; Allow the user to press a key, then reboot
	xor	ax, ax
	int	0x16
	int	0x19	; load sector at chs=0,0,1 into memory at 0:7C00h (reboot)

	; int 0x19 should never return.  In case it does anyway,
	; invoke the BIOS reset code...
	push 0xf000
	push 0xfff0
	retf


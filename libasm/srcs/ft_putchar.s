
section .text
	global	_ft_putchar
	extern	_ft_putstr
	
_ft_putchar:
	push	rdi
	mov		rsi, rsp
	mov		rdx, 1
	mov		rdi, 1
	mov		rax, 0x2000004
	syscall
	pop		rdi
	ret

section .data
NULL:  
	.none db "(null)", 0

section .text
	global	_ft_putstr
	extern 	_ft_strlen
	
_ft_putstr:
	cmp		rdi, 0x00
	je		go_null

print_str:
	push	rdi
	call	_ft_strlen
	pop		rsi
	mov 	rdx, rax
	mov		rdi, 1
	mov		rax, 0x2000004
	syscall
	ret

go_null:
	lea		rdi, [rel NULL.none]
	jmp		print_str
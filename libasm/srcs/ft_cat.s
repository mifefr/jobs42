# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_cat.s                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/28 19:04:45 by abruyere          #+#    #+#              #
#    Updated: 2015/05/28 19:04:47 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_cat

_ft_cat:
	push	r8
	cmp		rdi, 0
	jl		Lret
	
Lloop:
	mov		r9, rdi
	mov		rsi, rsp
	mov		rdx, 1
	mov		rax, 0x2000003
	syscall
	jc		Lret
    cmp     rax, 0
	jle     Lret
	mov		rdi, 1
	mov		rdx, rax
	mov		rax, 0x2000004
	syscall
	jc		Lret
	cmp		rax, -1
	je		Lret
	mov		rdi, r9
	jmp		Lloop

Lret:
	pop		r8
	ret

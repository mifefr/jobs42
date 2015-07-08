# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strnew.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/28 18:19:07 by abruyere          #+#    #+#              #
#    Updated: 2015/05/28 18:19:09 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_strnew
	extern	_ft_memset
	extern	_malloc
	
_ft_strnew:
	cmp		rdi, 0
	je		Exit
	push	rdi
	call	_malloc
	
_init:
	pop		rdx
	mov		rdi, rax
	mov		rsi, 0x00
	call	_ft_memset
	ret

Exit:
	xor		rax, rax
	ret

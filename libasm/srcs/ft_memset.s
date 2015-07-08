# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memset.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/26 17:42:57 by abruyere          #+#    #+#              #
#    Updated: 2015/05/28 17:26:02 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_memset

_ft_memset:
	push	rdi
	cmp		rdi, 0
	je		Exit
	mov		rax, rsi
	mov		rcx, rdx
	cld
	rep		stosb

Exit:	
	pop		rax
	ret

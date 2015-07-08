# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_memcpy.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/28 17:25:28 by abruyere          #+#    #+#              #
#    Updated: 2015/05/28 17:25:32 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global	_ft_memcpy

_ft_memcpy:
	push    rdi
	cmp		rdi, 0
	je		Exit
    mov     rax, rsi
    mov     rcx, rdx
    cld
    rep     movsb

Exit:	
	pop     rax
    ret

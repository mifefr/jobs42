# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_strlen.s                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/05/10 14:38:09 by abruyere          #+#    #+#              #
#    Updated: 2015/05/10 14:38:12 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_strlen

_ft_strlen:
	cmp		rdi, 0x00
	je		Exit
	xor		rcx, rcx
	dec 	rcx
	xor		rax, rax
	cld
	repnz	scasb
	not 	rcx
	dec		rcx
	mov		rax, rcx
	ret
	
Exit:
	xor		rax, rax
	ret

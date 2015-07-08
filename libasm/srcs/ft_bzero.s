# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_bzero.s                                         :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:21:19 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:21:22 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_bzero

_ft_bzero:
	cmp	rsi, 0x0
	jle	_exit

_loop:
	dec	rsi
	mov	byte [rdi+rsi], 0x0
	jmp	_ft_bzero

_exit:
	ret

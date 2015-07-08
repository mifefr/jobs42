# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isascii.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:22:17 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:22:18 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isascii

_ft_isascii:
	cmp	rdi, 0
	jl	_exit
	cmp	rdi, 127
	jg	_exit
	mov	rax, 1
	ret 

_exit:
	mov	rax, 0
	ret

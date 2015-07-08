# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isprint.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:23:00 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:23:01 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isprint

_ft_isprint:
	cmp	rdi, 32
	jl	_exit
	cmp	rdi, 126
	jg	_exit
	mov	rax, 1
	ret 

_exit:
	mov	rax, 0
	ret

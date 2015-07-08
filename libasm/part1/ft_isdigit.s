# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isdigit.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:22:41 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:22:42 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isdigit

_ft_isdigit:
	cmp	rdi, 48
	jl	_exit
	cmp	rdi, 57
	jg	_exit
	mov	rax, 1
	ret 

_exit:
	mov	rax, 0
	ret

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_islower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:22:50 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:22:52 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_islower

_ft_islower:
	cmp	rdi, 97
	jl	_exit
	cmp	rdi, 122
	jg	_exit
	mov	rax, 1
	ret 

_exit:
	mov	rax, 0
	ret

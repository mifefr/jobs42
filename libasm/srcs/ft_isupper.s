# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:23:09 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:23:11 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isupper

_ft_isupper:
	cmp	rdi, 65
	jl	_exit
	cmp	rdi, 90
	jg	_exit
	mov	rax, 1
	ret 

_exit:
	mov	rax, 0
	ret

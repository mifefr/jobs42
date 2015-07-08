# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_toupper.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:23:22 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:23:24 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_toupper
	extern _ft_islower

_ft_toupper:
	call _ft_islower
	cmp rax, 1
	je	_ft_change
	mov rax, rdi
	ret

_ft_change:
	sub	rdi, 32
	mov rax, rdi
	ret

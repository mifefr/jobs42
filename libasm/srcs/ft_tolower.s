# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_tolower.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:23:16 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:23:17 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_tolower
	extern _ft_isupper

_ft_tolower:
	call _ft_isupper
	cmp rax, 1
	je	_ft_change
	mov rax, rdi
	ret

_ft_change:
	add	rdi, 32
	mov rax, rdi
	ret

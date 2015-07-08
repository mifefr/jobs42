# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_is_alpha.s                                      :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:22:07 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:22:09 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isalpha
	extern _ft_isupper
	extern _ft_islower

_ft_isalpha:
	call _ft_isupper
	cmp	rax, 1
	je	_exit
	call _ft_islower

_exit:
	ret

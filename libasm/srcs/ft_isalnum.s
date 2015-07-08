# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    ft_isalnum.s                                       :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/04/02 15:21:49 by abruyere          #+#    #+#              #
#    Updated: 2015/04/02 15:21:52 by abruyere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

section .text
	global _ft_isalnum
	extern _ft_isalpha
	extern _ft_isdigit

_ft_isalnum:
	call _ft_isalpha
	cmp	rax, 1
	je	_exit
	call _ft_isdigit

_exit:
	ret

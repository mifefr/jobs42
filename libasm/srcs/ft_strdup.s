# **************************************************************************** ##                                                                              ##                                                         :::      ::::::::    ##    ft_strdup.s                                        :+:      :+:    :+:    ##                                                     +:+ +:+         +:+      ##    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         ##                                                 +#+#+#+#+#+   +#+            ##    Created: 2015/05/28 17:33:09 by abruyere          #+#    #+#              ##    Updated: 2015/05/28 17:33:11 by abruyere         ###   ########.fr        ##                                                                              ## **************************************************************************** #section .text	global	_ft_strdup	extern	_ft_memcpy	extern	_ft_strnew	extern	_ft_strlen	_ft_strdup:		push 	rdi	call	_ft_strlen	mov		rdx, rax	mov		rdi, rax	inc		rdi	call	_ft_strnew	mov		rdi, rax	pop		rsi	call	_ft_memcpy	ret
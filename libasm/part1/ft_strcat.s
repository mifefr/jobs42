# **************************************************************************** ##                                                                              ##                                                         :::      ::::::::    ##    ft_strcat.s                                        :+:      :+:    :+:    ##                                                     +:+ +:+         +:+      ##    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         ##                                                 +#+#+#+#+#+   +#+            ##    Created: 2015/04/02 15:27:13 by abruyere          #+#    #+#              ##    Updated: 2015/04/02 15:27:16 by abruyere         ###   ########.fr        ##                                                                              ## **************************************************************************** #section .text	global _ft_strcat_ft_strcat:	mov 	r8, 0	mov		r9, 0	_loop1:	cmp		byte [rdi + r8], 0x0	je 		_loop2	inc 	r8	jmp 	_loop1_loop2:	cmp		byte[rsi + r9], 0x0	je		_exit	mov		r10b, byte[rsi + r9]	mov		byte [rdi + r8 + r9], r10b	inc		r9	jmp		_loop2_exit:	mov	byte[rdi + r8 + r9], 0x0	mov rax, rdi	ret
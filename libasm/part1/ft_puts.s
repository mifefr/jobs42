# **************************************************************************** ##                                                                              ##                                                         :::      ::::::::    ##    ft_puts.s                                          :+:      :+:    :+:    ##                                                     +:+ +:+         +:+      ##    By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+         ##                                                 +#+#+#+#+#+   +#+            ##    Created: 2015/04/17 20:55:44 by abruyere          #+#    #+#              ##    Updated: 2015/04/17 20:55:45 by abruyere         ###   ########.fr        ##                                                                              ## **************************************************************************** #section .text	global _ft_puts	extern _ft_strlen_ft_puts:	mov rcx, rdi	call _ft_strlen	mov rbx, 1	mov rcx, rax	mov	rax, 0x2000004	syscall	mov rax, 1	mov rbx, 0	syscallend:	ret
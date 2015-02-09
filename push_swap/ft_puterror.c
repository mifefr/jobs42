/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:08:05 by abruyere          #+#    #+#             */
/*   Updated: 2015/02/09 18:08:08 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_puterror(char *str)
{
	ft_putstr("Error\n");
	ft_putstr(str);
	ft_putchar('\n');
	exit(0);
	return (0);
}

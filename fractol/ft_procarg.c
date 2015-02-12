/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_procarg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 09:50:57 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/14 17:11:14 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_procarg(char	*str)
{
	if (!(strcmp(str, "-Julia")))
		return (1);
	if (!(strcmp(str, "-Mandelbrot")))
		return (2);
	if (!(strcmp(str, "-Modulo")))
		return (3);
	return (-1);
}

int		ft_listarg(char	*str)
{
	ft_putstr("Vous avez saisie le nom d'une fractale inconue :\n");
	ft_putstr(str);
	ft_putchar('\n');
	ft_putchar('\n');
	ft_putstr("Voici la liste des fractales connuent par ce programme : \n\n");
	ft_putstr("               -Julia      (./fractol -Julia)\n");
	ft_putstr("               -Mandelbrot (./fractol -Mandelbrot)\n");
	ft_putstr("               -Modulo     (./fractol -Modulo)\n");
	return (0);
}

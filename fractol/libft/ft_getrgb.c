/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getrgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 14:49:15 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/03 15:05:24 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_getrgb(char *color)
{
	if (!ft_strcmp(color, "blue"))
		return (0x0000FF);
	if (!ft_strcmp(color, "green"))
		return (0x008000);
	if (!ft_strcmp(color, "yellow"))
		return (0xFFFF00);
	if (!ft_strcmp(color, "black"))
		return (0x000000);
	if (!ft_strcmp(color, "lime"))
		return (0x00FF00);
	if (!ft_strcmp(color, "red"))
		return (0xFF0000);
	if (!ft_strcmp(color, "magenta"))
		return (0xFF00FF);
	if (!ft_strcmp(color, "silver"))
		return (0xC0C0C0);
	if (!ft_strcmp(color, "gray"))
		return (0x808080);
	if (!ft_strcmp(color, "maroon"))
		return (0x800000);
	if (!ft_strcmp(color, "purple"))
		return (0x800080);
	else
		return (0xFFFFFF);
}

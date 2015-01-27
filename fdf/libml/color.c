/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/27 15:17:36 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/01 09:36:18 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libml.h"

int		get_rgb(char *color)
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

char	*get_color(char *rgb)
{
	if (ft_strcmp(rgb, "0x0000FF"))
		return ("blue");
	if (ft_strcmp(rgb, "0x00800"))
		return ("green");
	if (ft_strcmp((char *)rgb, "0xFFFF00"))
		return ("yellow");
	if (ft_strcmp((char *)rgb, "0x000000"))
		return ("black");
	if (ft_strcmp((char *)rgb, "0x00FF00"))
		return ("lime");
	if (ft_strcmp((char *)rgb, "0xFF0000"))
		return ("red");
	if (ft_strcmp((char *)rgb, "0xFF00FF"))
		return ("magenta");
	if (ft_strcmp((char *)rgb, "0xC0C0C0"))
		return ("silver");
	if (ft_strcmp((char *)rgb, "0x808080"))
		return ("gray");
	if (ft_strcmp((char *)rgb, "0x800000"))
		return ("maroon");
	if (ft_strcmp((char *)rgb, "0x800080"))
		return ("purple");
	if (ft_strcmp((char *)rgb, "0xFFFFFF"))
		return ("white");
	return ("unknow");
}

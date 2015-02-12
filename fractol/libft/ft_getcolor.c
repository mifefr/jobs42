/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getcolor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 14:49:58 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/03 15:38:42 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_getcolor(char *rgb)
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

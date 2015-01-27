/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_makep.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/09 17:08:09 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/29 14:22:41 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_givecolor(int z)
{
	if (z < 0)
		return (get_rgb("blue"));
	if (z == 0)
		return (get_rgb("green"));
	else
		return (get_rgb("maroon"));
}

t_point	ft_makep(int x, int y, int z)
{
	t_point p;

	p.x = x * 50;
	p.y = y * 50;
	p.z = z;
	p.rgb = ft_givecolor(p.z);
	return (p);
}

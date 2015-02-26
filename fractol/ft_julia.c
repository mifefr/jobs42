/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_julia.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:49:21 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/16 16:46:16 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_julia(t_mlxenv e)
{
	t_jul	p;

	p = e.p;

	int h = p.h;
	int w = p.w;
	while (p.x < w)
	{
		while (p.y < h)
		{
			p.z_r = 1.5 * (p.x - w / 2) / (0.5 * p.zoom * w) + p.movex;
			p.z_i = (p.y - h / 2) / (0.5 * p.zoom * h) + p.movey;
			while (p.i < p.iterationmax)
			{
				p.o_r = p.z_r;
				p.o_i = p.z_i;
				p.z_r = p.o_r * p.o_r - p.o_i * p.o_i + p.c_r;
				p.z_i = 2 * p.o_r * p.o_i + p.c_i;
				if ((p.z_r * p.z_r + p.z_i * p.z_i) > 4)
					break ;
				p.i++;
			}
			p.color = ft_gethexa(ft_getcol(p.iterationmax, p.i * 255), ft_getcol(p.iterationmax, p.i * 256), ft_getcol(p.iterationmax, p.i * 256));
			//if (p.i == p.iterationmax)
			mlx_pixel_put(e.mlx, e.window, p.x, p.y, p.color);
			p.i = 0;
			p.y++;
		}
		p.y = 0;
		p.x++;
	}
	return (0);
}

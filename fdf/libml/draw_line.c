/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/26 14:50:54 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/13 20:05:45 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libml.h"

void	draw_line(t_point p, t_point p2, t_mlxenv *e)
{
	int		l;
	float	inc[2];
	float	xy[2];

	l = (abs(p2.x - p.x) > abs(p2.y - p.y)) ? abs(p2.x - p.x) : abs(p2.y - p.y);
	inc[0] = (float)(p2.x - p.x) / (float)l;
	inc[1] = (float)(p2.y - p.y) / (float)l;
	xy[0] = p.x + 0.5;
	xy[1] = p.y + 0.5;
	while (l-- > 0)
	{
		mlx_pixel_put(e->mlx, e->window, xy[0], xy[1], p2.rgb);
		xy[0] += inc[0];
		xy[1] += inc[1];
	}
}

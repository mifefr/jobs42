/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_draw.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:46:38 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/29 16:56:12 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libml.h"

void	mouse_draw(t_point p, t_mlxenv *e)
{
	static t_point	p2;

	if (p2.x != 0 || p2.y != 0)
		draw_line(p, p2, e);
	else
		mlx_pixel_put(e->mlx, e->window, p.x, p.y, get_rgb("silver"));
	p2.x = p.x;
	p2.y = p.y;
}

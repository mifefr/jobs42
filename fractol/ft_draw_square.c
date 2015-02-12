/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/26 17:22:10 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/26 17:22:17 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void    ft_draw_square(int sqr, int x, int y, t_mlxenv *e)
{
    int limitx;
    int limity;
    int xi;

    limitx = x + sqr;
    limity = y + sqr;
    if (sqr <= 0)
        return ;
    while (y < limity)
    {
        xi = x;
        while (xi < limitx)
        {
            mlx_pixel_put(e->mlx, e->window, xi, y, 0xFFFFFF);
            xi++;
        }
        y++;
    }
}

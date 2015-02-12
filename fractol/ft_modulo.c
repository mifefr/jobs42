/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_modulo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 14:49:38 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/13 14:49:41 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	ft_modulo(int i, int x, int y, t_mlxenv e)
{
    t_jul   p;
    int     zoom;

    p = e.p;
    zoom = p.zoom / pow(3, i);
    ft_draw_square(zoom, (x - (zoom / 2)), (y - (zoom / 2)), &e);
    if (i < p.iterationmax && zoom > 1)
    {
        ft_modulo(i + 1, (x + zoom), (y + zoom), e);
        ft_modulo(i + 1, (x + zoom), y, e);
        ft_modulo(i + 1, (x + zoom), (y - zoom), e);
        ft_modulo(i + 1, x, y - zoom, e);
        ft_modulo(i + 1, x, y + zoom, e);
        ft_modulo(i + 1, x - zoom, y + zoom, e);
        ft_modulo(i + 1, x - zoom, y, e);
        ft_modulo(i + 1, x - zoom, y - zoom, e);
    }
    return (0);
}
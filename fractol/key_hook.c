/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:56:22 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/13 19:19:31 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, t_mlxenv *e)
{
	if (keycode == 65362)
	{
		e->p.iterationmax = e->p.iterationmax * 2;
		ft_julia(*e);
	}
	if (keycode == 65364)
	{
		e->p.iterationmax = e->p.iterationmax / 2;
		ft_julia(*e);
	}
	if (keycode == 65451)
	{
		e->p.zoom = e->p.zoom + 1;
		ft_julia(*e);
	}
	if (keycode == 65453 && e->p.zoom != 1)
	{
		e->p.zoom = e->p.zoom - 1;
		ft_julia(*e);
	}
	if (keycode == 65307)
		exit (0);
	return (0);
}

int		key_hookm(int keycode, t_mlxenv *e)
{
	if (keycode == 65362)
	{
		e->p.iterationmax = e->p.iterationmax * 2;
		ft_mandelbrot(*e);
	}
	if (keycode == 65364)
	{
		e->p.iterationmax = e->p.iterationmax / 2;
		ft_mandelbrot(*e);
	}
	if (keycode == 65451)
	{
		e->p.zoom = e->p.zoom + 1;
		ft_mandelbrot(*e);
	}
	if (keycode == 65453 && e->p.zoom != 1)
	{
		e->p.zoom = e->p.zoom - 1;
		ft_mandelbrot(*e);
	}
	if (keycode == 65307)
		exit (0);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 09:34:58 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/14 19:07:12 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_makejulia(t_mlxenv e)
{
	t_jul	p;

	p.h = 900;
	p.w = 1200;
	if (!(e.window))
	{
		e.mlx = mlx_init();
		e.window = mlx_new_window(e.mlx, p.w, p.h, "fractale");
	}
	p.zoom = 1;
	p.movex = 0;
	p.movey = 0;    
	p.iterationmax = 300;
	p.c_r = -0.7;
	p.c_i = 0.27015;
	p.x = 0;
	p.y = 0;
	p.i = 0;
	e.p = p;
	ft_julia(e);
	mlx_key_hook(e.window, key_hook, &e);
	mlx_mouse_hook(e.window, mouse_hook, &e);
	mlx_expose_hook(e.window, expose_hook, &e);
	mlx_hook(e.window, 6,64, mouse_win, &e);
	mlx_loop(e.mlx);
	return (0);
}

int		ft_makemandelbrot(t_mlxenv e)
{
	t_jul	p;

	
	p.h = 900;
	p.w = 1200;
	if (!(e.window))
	{
		e.mlx = mlx_init();
		e.window = mlx_new_window(e.mlx, p.w, p.h, "fractale");
	}
	p.zoom = 1;
	p.movex = -0.5;
	p.movey = 0;
	p.iterationmax = 300;
	e.p = p;
	ft_mandelbrot(e);
	mlx_key_hook(e.window, key_hookm, &e);
	mlx_mouse_hook(e.window, mouse_hook, &e);
	//mlx_expose_hook(e.window, expose_hook, &e);
	mlx_loop(e.mlx);
	return (0);
}

int		ft_makemodulo(t_mlxenv e)
{
	t_jul	p;

	p.i = 0;
	p.h = 900;
	p.w = 1200;
	p.x = 0;
	p.y = 0;
	p.iterationmax = 10;
	p.zoom = 9;
	if (!(e.window))
	{
		e.mlx = mlx_init();
		e.window = mlx_new_window(e.mlx, p.w, p.h, "fractale");
	}
	ft_modulo(p.i, p.x, p.y, e);
	mlx_loop(e.mlx);
	return (0);
}

int		processing(int type)
{
	t_mlxenv		e;
	if (type == 1)
		ft_makejulia(e);
	else if (type == 2)
		ft_makemandelbrot(e);
	else
		ft_makemodulo(e);
	return (0);
}

int		main(int argc, char **argv, char **env)
{
	int		type;

	if (argc != 2)
		exit(ft_error("[Main]: Nombre d'arguments incorect."));
	if (env[0] == NULL)
		exit(ft_error("[Main]: Environnement desactive."));
	if ((type = ft_procarg(argv[1])) == -1)
		exit(ft_listarg(argv[1]));
	else
	{
		processing(type);
	}
	return (0);
}

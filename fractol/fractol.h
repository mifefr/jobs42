/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/05 09:32:54 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/14 19:08:55 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H

# define FRACTOL_H

# include "libft/libft.h"
# include <mlx.h> 
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

typedef	struct	s_jul
{
	int				x;
	int				y;
	double			zoom;
	int				iterationmax;
	double			c_r;
	double			c_i;
	double			z_r;
	double			z_i;
	double			o_r;
	double			o_i;
	double			movex;
	double			movey;
	int				i;
	int				color;
	int				h;
	int				w;
}				t_jul;

typedef	struct	s_mlxenv
{
	void		*mlx;
	void		*window;
	void		*image;
	t_jul		p;
}				t_mlxenv;

int				ft_getcol(int imax, int i);
int				ft_gethexa(int r, int g, int b);
int				ft_julia(t_mlxenv e);
int				ft_mandelbrot(t_mlxenv e);
int				ft_modulo(int i, int x, int y, t_mlxenv e);
int				ft_listarg(char *str);
int				ft_procarg(char	*str);
int				mouse_hook(int button, int x, int y, t_mlxenv *e);
int				key_hook(int keycode, t_mlxenv *e);
int				expose_hook(t_mlxenv *e);
int				mouse_win(int x,int y, t_mlxenv *e);
int				key_hookm(int keycode, t_mlxenv *e);
void			ft_draw_square(int sqr, int x, int y, t_mlxenv *e);
#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libml.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 21:59:29 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/30 16:28:37 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBML_H

# define LIBML_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../libft/libft.h"

typedef	struct	s_point
{
	int				x;
	int				y;
	int				z;
	int				rgb;
}				t_point;

typedef	struct	s_list
{
	t_point			p;
	int				i;
	struct s_list	*next;
	struct s_list	*down;
}				t_list;

typedef	struct	s_mlxenv
{
	void		*mlx;
	void		*window;
	t_list		*head;
}				t_mlxenv;

typedef	struct	s_read
{
	int				i;
	int				j;
	char			**text;
}				t_read;

void			draw_line(t_point p, t_point p2, t_mlxenv *e);
int				get_rgb(char *color);
char			*get_color(char *rgb);
void			mouse_draw(t_point p, t_mlxenv *e);
int				mouse_hook(int button, int x, int y, t_mlxenv *e);
int				key_hook(int keycode, t_mlxenv *e);
int				ft_expose_hook(t_mlxenv *e);
void			ft_draw(t_list *head, t_mlxenv e);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:51:06 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/11 15:15:36 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libml.h"

int		mouse_hook(int button, int x, int y, t_mlxenv *e)
{
	t_point	p;

	p.x = x;
	p.y = y;
	if (button == 1)
	{
		mouse_draw(p, e);
	}
	return (0);
}

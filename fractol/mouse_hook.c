/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:46:38 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/14 17:08:44 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int button, int x, int y, t_mlxenv *e)
{
//gestion des couleurs pour le bouton 1
	if (button == 1)
	{
		e->p.zoom = e->p.zoom * 2;
		/*e->p.movex = (x / e->p.w) + 0.5;
		e->p.movey = (y / e->p.h) + 0.5;
		*/
		ft_julia(*e);
	}
	return (button + x + y);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 09:56:22 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/30 15:29:11 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libml.h"

int		key_hook(int keycode, t_mlxenv *e)
{
	(void)e;
	if (keycode == 65307)
		exit (0);
	return (0);
}

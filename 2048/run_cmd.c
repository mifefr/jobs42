/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_cmd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:27:43 by abruyere          #+#    #+#             */
/*   Updated: 2015/03/01 01:29:16 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game_2048.h"

void	run_cmd(void)
{
	ft_putstr("Voici les touches dirrectionelles\n\n");
	ascii_art_comdir();
	ft_putstr("\n\nQuitter :\n");
	ascii_art_exit();
	ft_putstr("\n\nAcceuil :\n");
	ascii_art_home();
}

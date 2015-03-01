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
	int	ch;

	ch = 0;
	initscr();
	clear();
	printw("Voici les touches dirrectionelles\n\n");
	ascii_art_comdir();
	printw("\n\nQuitter :\n");
	ascii_art_exit();
	printw("\n\nAcceuil :\n");
	ascii_art_home();
	noecho();
	keypad(stdscr, TRUE);	
	while (42)
	{
				
		ch = getch();
		//printw("%d", ch);
		if (ch == 27)
			exit(0);
		if (ch == 127)
		{
			endwin();
			make_title();
		}
		refresh();
	}
}

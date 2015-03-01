/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_title.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:33:48 by abruyere          #+#    #+#             */
/*   Updated: 2015/03/01 01:36:38 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "game_2048.h"

void	ask_param(void)
{
	int ch;

	ch = 0;
	initscr();
	printw("Veuillez choisir la taille de votre grille :\n");
	printw("(entre 4 et 9 cases !!!)");
	noecho();
	while(42)
	{
		ch = getch();
		if (ch > 51 && ch < 58)
		{
			endwin();
			run_game(ch - 48);
		}
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

int		choose_opt(void)
{
	int	ch;

	ch = 0;
	ascii_art_2048();
	ascii_art_thegame();
	printw("1 : jouer à 2048\n2 : accéder aux commandes.");
	printw("\n3 : consulter les scores.\n");
	printw("4 : quitter le jeu\n");
	noecho();
	
	while (42)
	{
				
		ch = getch();
		//printw("%d", ch);
		if (ch == 49)
			return (1);
		if (ch == 50)
			return (2);
		if (ch == 51)
			return (3);
		if (ch == 52)
			return (4);
		refresh();
	}
	return (0);
}
//cette fonction est la fonction de depart du jeu qui 
////peux etre apellé de n'importe ou !
int		make_title(void)
{
	int	choose;

	initscr();
	clear();
	printw("Que voulez vous faire ?\n");
	choose = choose_opt();
	endwin();
	if (choose == 1)
		ask_param();
	if (choose == 2)
		run_cmd();
//	if (choose == 3)
//		run_score();
//	if (choose == 4)
//		run_exit();
	return (0);
}

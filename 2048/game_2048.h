/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_2048.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 01:32:52 by abruyere          #+#    #+#             */
/*   Updated: 2015/03/01 01:33:03 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_2048_H
# define GAME_2048_H

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <ncurses.h>

typedef struct	s_game
{
	int			**tab;
	int			size;
}				t_game;

enum e_const
{
	WIN_VALUE = 2048
};

int				make_title(void);

// void			run_game(t_game *game);
/*
 * **	appel de init_tab et begin_tab dans le main avant appel de run_game
 * **	
 * **	1 -> attente d'un mov sur le clavier
 * **	2 -> envoyer a move_action
 * **	3 -> verifier si gagner is_win == 1
 * **	4 -> compte les cases vides
 * **	5 -> si case vide ALORS nbr random + place random SINON verif si perdu
 * **	6 -> si pas perdu la boucle est bouclee -> 1
 * */

void			ft_error(char *msg); // exit si message erreur

t_game			*init_tab(int size);
void			begin_tab(t_game *game);
void				move_action(t_game *game, int move); 
void			show_grid(t_game *game);

int				nbr_empty(t_game *game);
int				is_win(t_game *game);
int				is_end(t_game *game);

int				random_place(int max);
int				random_nbr(void);

int				keyboard_move(void);
void	ascii_art_thegame(void);
void	ascii_art_2048(void);
void	ascii_art_comdir(void);
void	ascii_art_exit(void);
void	ascii_art_home(void);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/30 17:42:33 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/30 16:32:06 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_draw(t_list *head, t_mlxenv e)
{
	while (head->next != NULL)
	{
		if (head->next->p.y == head->p.y)
			draw_line(ft_makeiso(head->p), ft_makeiso(head->next->p), &e);
		if ((head->down))
			draw_line(ft_makeiso(head->p), ft_makeiso(head->down->p), &e);
		head = head->next;
	}
}

t_list	*ft_read(char *file)
{
	int		fd;
	char	*line;
	t_read	r;
	t_list	*head;

	head = NULL;
	r.text = NULL;
	r.j = 0;
	if (open(file, O_RDONLY) == -1)
		exit(ft_error2("[Read]: FD non vallable"));
	fd = open(file, O_RDONLY);
	while (get_next_line((int const)fd, &line) > 0)
	{
		if (line[0] == '\0')
			break ;
		r.i = 0;
		r.text = ft_strsplit(line, ' ');
		while (r.text[r.i = r.i + 1])
			head = prevelem(head, ft_makep(r.i, r.j, ft_atoi(r.text[r.i])));
		r.j = r.j + 1;
	}
	if (!head)
		exit(ft_error("[Read]: Fichier non interpretable.]"));
	ft_rev(&head);
	return (head);
}

int		main(int argc, char **argv, char **env)
{
	t_mlxenv		e;
	t_list			*head;

	if (argc != 2)
		exit(ft_error("[Main]: Erreur d'arguments."));
	if (env[0] == NULL)
		exit(ft_error("[Main]: Environnement desactive."));
	head = ft_read(argv[1]);
	head = ft_setdown(head);
	e.mlx = mlx_init();
	e.window = mlx_new_window(e.mlx, 5000, 5000, "Le FDF");
	mlx_key_hook(e.window, key_hook, &e);
	mlx_mouse_hook(e.window, mouse_hook, &e);
	e.head = head;
	mlx_expose_hook(e.window, &ft_expose_hook, &e);
	ft_draw(head, e);
	mlx_loop(e.mlx);
	return (0);
}

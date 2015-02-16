/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/30 17:54:48 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/30 18:00:50 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

void	processing(t_pile *pa, t_pile *pb)
{
	if (is_order(pa))
		exit(0);
	
	processing (pa, pb);
}

void	push_swap(int nbe, char **list)
{
	int		i;
	t_pile	*pa;
	t_pile	*pb;

	pa = new_elem(pa);
	pb = new_elem(pb);
	i = 0;
	while (i < nbe)
	{
		pa = add_elem(pa, (int)list[i]);
		i++;
	}
	processing(pa, pb);
}

int	 	main(int argc, char **argv)
{
	int i;

	i = 0;
	if (argc == 1)
		ft_puterror("");
	push_swap(argc - 1, argv);
	return (0);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:09:26 by abruyere          #+#    #+#             */
/*   Updated: 2015/02/09 18:09:28 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *pile)
{
	t_pile	*pilebeg;
	t_pile	*pileend;

	pileend = pile;
	pileend->next = NULL;
	pile->next->prev = NULL;
	pilebeg = pile->next;
	while (pile->next != NULL)
		pile = pile->next;
	pile->next = pileend;
	pile = pilebeg;
}

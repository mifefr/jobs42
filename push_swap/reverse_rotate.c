/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:08:54 by abruyere          #+#    #+#             */
/*   Updated: 2015/02/09 18:08:56 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_pile *pile)
{
	t_pile	*pilebeg;

	pilebeg = pile;
	while (pile->next != NULL)
		pile = pile->next;
	pile->prev->next = NULL;
	pile->prev = NULL;
	pile->next = pilebeg;
	pile->next->prev = pile;
}

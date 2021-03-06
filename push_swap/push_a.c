/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:08:22 by abruyere          #+#    #+#             */
/*   Updated: 2015/02/09 18:08:25 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_pile	*pilea, t_pile *pileb)
{
	t_pile	*pilerec;
	t_pile	*pilebeg;

	t_pilebeg = pilea;
	pilerec = pileb;
	pilea = pilea->next;
	pilea->prev = NULL;
	while (pilea->next != NULL)
		pilea = pile->next;
	pilea->next = pilerec;
	pilea->next->prev = pilea;
	pilea->next->next = NULL;
	pilea = pilebeg;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/09 18:09:37 by abruyere          #+#    #+#             */
/*   Updated: 2015/02/09 18:09:41 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*swap(t_pile *origin)
{
	t_pile	*ret;

	ret = origin;
	origin = origin->next;
	origin->next = ret;
	origin->next->next = ret->next->next;
	return (origin);
}

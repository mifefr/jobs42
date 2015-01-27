/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/08 20:03:58 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/29 16:34:47 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_list	*ft_rev(t_list **list)
{
	t_list	*cur_elem;
	t_list	*prev_elem;
	t_list	*next_elem;

	cur_elem = *list;
	prev_elem = NULL;
	next_elem = NULL;
	while (cur_elem != NULL)
	{
		*list = cur_elem;
		prev_elem = cur_elem->next;
		cur_elem->next = next_elem;
		next_elem = cur_elem;
		cur_elem = prev_elem;
	}
	return (prev_elem);
}

t_list	*ft_setdown(t_list *head)
{
	t_list	*br;
	t_list	*ret;

	ret = head;
	while (head->next)
	{
		br = head;
		while ((br))
		{
			if (br->p.x == head->p.x && br->p.y == (head->p.y + (1 * 50)))
			{
				head->down = br;
				head->down->i = head->i + 1;
				break ;
			}
			br = br->next;
		}
		head = head->next;
	}
	return (ret);
}

t_list	*newelem(t_point p)
{
	t_list	*ptr;

	ptr = (t_list*)malloc(sizeof(t_list));
	ptr->p = p;
	ptr->next = NULL;
	ptr->down = NULL;
	ptr->i = 0;
	return (ptr);
}

t_list	*prevelem(t_list *head, t_point p)
{
	t_list	*new;

	if (head == NULL)
		return (newelem(p));
	new = newelem(p);
	new->next = head;
	return (new);
}

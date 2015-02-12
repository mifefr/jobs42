/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 12:15:18 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/03 14:23:39 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*l;
	t_list	*e;

	if (!lst || !f)
		return (NULL);
	if ((l = f(lst)) == NULL)
		return (NULL);
	e = l;
	while (lst->next)
	{
		lst = lst->next;
		if ((e->next = f(lst)) == NULL)
			return (NULL);
		e = e->next;
	}
	return (l);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 12:12:02 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/03 12:50:12 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	if (alst == NULL)
		return ;
	if (*alst && *del != NULL)
		del((*alst)->content, (*alst)->content_size);
	ft_memdel((void **)alst);
}

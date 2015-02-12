/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 11:40:42 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/03 14:27:43 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*ptr;

	ptr = (t_list*)malloc(sizeof(t_list));
	if (ptr == NULL)
		return (NULL);
	ptr->next = NULL;
	if (content == NULL)
	{
		ptr->content = NULL;
		(*ptr).content_size = 0;
		return (ptr);
	}
	if ((ptr->content = (void *)ft_memalloc(content_size)) == NULL)
		return (NULL);
	ft_memcpy(ptr->content, content, content_size);
	ptr->content_size = content_size;
	return (ptr);
}

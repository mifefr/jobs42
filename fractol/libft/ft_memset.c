/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:09:25 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/09 12:39:42 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *s, int c, size_t n)
{
	char	*list;
	size_t	i;

	list = (char *)s;
	i = 0;
	while (i < n)
	{
		list[i] = c;
		i++;
	}
	return (s);
}

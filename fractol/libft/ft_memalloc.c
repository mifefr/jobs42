/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 15:55:48 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 14:50:03 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

void	*ft_memalloc(size_t size)
{
	char	*tab;
	int		i;

	if (size == 0)
		return (NULL);
	i = 0;
	tab = (char*)malloc(size * sizeof(char));
	if (!tab)
		return (NULL);
	while (size > 0)
	{
		tab[i] = '\0';
		i++;
		size--;
	}
	return ((void*)tab);
}

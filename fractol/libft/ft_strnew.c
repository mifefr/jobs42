/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/05 16:30:15 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/09 12:53:05 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char *ft_strnew(size_t size)
{
	char	*tab;
	int		i;

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
	return (tab);
}

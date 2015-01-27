/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:34:24 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/04 18:42:44 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*adest;
	char	*asrc;
	char	tab[n];
	int		i;

	i = 0;
	adest = (char*)dest;
	asrc = (char*)src;
	while (n != 0)
	{
		tab[i] = asrc[i];
		n--;
		i++;
	}
	while (i != 0)
	{
		adest[n] = tab[n];
		i--;
		n++;
	}
	return (dest);
}

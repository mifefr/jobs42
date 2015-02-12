/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:23:52 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 18:48:32 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void *ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	char	*adest;
	char	*asrc;
	int		i;

	i = 0;
	adest = (char*)dest;
	asrc = (char*)src;
	while (n != 0)
	{
		if (asrc[i] == c)
			return (adest + (i + 1));
		adest[i] = asrc[i];
		i++;
		n--;
	}
	return (NULL);
}

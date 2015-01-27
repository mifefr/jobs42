/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 18:17:36 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/04 18:27:38 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*adest;
	char	*asrc;
	int		i;

	i = 0;
	adest = (char*)dest;
	asrc = (char*)src;
	while (n != 0)
	{
		adest[i] = asrc[i];
		n--;
		i++;
	}
	return (dest);
}

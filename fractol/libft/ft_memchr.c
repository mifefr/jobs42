/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:42:06 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/02 15:24:23 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	if (s && n > 0)
	{
		while (n--)
		{
			if (*ptr == (unsigned char)c)
				return ((void *)ptr);
			ptr++;
		}
	}
	return (NULL);
}

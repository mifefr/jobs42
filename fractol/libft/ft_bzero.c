/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 16:17:19 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/09 11:27:20 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*list;
	size_t			i;

	list = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		list[i] = 0;
		i++;
	}
}

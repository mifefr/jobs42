/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 19:51:43 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/07 23:03:53 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*as1;
	char	*as2;
	int		i;

	as1 = (char*)(s1);
	as2 = (char*)(s2);
	i = 0;
	while (n != 0)
	{
		if (as1[i] != as2[i])
			return (as1[i] - as2[i]);
		n--;
		i++;
	}
	return (0);
}

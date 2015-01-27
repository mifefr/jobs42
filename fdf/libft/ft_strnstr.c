/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:04:39 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 18:42:44 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t		s2_len;
	size_t		count;
	char		*as1;

	if (s1)
	{
		s2_len = ft_strlen(s2);
		as1 = (char *)s1;
		if (ft_strlen(as1) < (int)s2_len)
			return (NULL);
		if (!s2_len)
			return (as1);
		if (s2_len > n)
			return (NULL);
		count = n - s2_len + 1;
		while (count)
		{
			if (!ft_memcmp(as1, s2, s2_len))
				return (as1);
			as1++;
			count--;
		}
	}
	return (NULL);
}

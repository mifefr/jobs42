/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 12:48:28 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 11:16:39 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *s1, const char *s2)
{
	const char	*sentence;
	const char	*chain;

	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 != '\0')
	{
		sentence = s1;
		chain = s2;
		while (*sentence == *chain && *sentence != '\0' && *chain != '\0')
		{
			sentence++;
			chain++;
		}
		if (*chain == '\0')
			return ((char*)s1);
		s1++;
	}
	return (NULL);
}

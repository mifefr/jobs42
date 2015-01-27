/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 18:01:32 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/09 13:02:46 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*as;
	int		i;
	size_t	j;

	if (s == NULL)
		return (NULL);
	i = start;
	j = 0;
	as = (char*)malloc((len + 1) * sizeof(char));
	if (as)
	{
		while (j < len)
		{
			as[j] = s[i];
			j++;
			i++;
		}
		as[j] = '\0';
	}
	else
		return (NULL);
	return (as);
}

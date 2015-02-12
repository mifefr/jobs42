/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/10 21:14:16 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 22:52:09 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (dup)
	{
		while (s[i] != '\0')
		{
			dup[i] = s[i];
			i++;
		}
		dup[i] = '\0';
	}
	else
		return (NULL);
	return (dup);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_n.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/03 11:18:15 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/29 16:54:47 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup_n(const char *s)
{
	char	*dup;
	int		i;

	i = 0;
	dup = (char *)malloc(sizeof(char) * (ft_strlen(s) + 2));
	if (dup)
	{
		while (s[i] != '\0')
		{
			dup[i] = s[i];
			i++;
		}
		dup[i++] = '\n';
		dup[i] = '\0';
	}
	return (dup);
}

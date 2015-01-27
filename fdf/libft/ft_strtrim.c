/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:25:27 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 18:41:01 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char *ft_strtrim(char const *s)
{
	char	*as;
	int		size;
	int		i;
	int		j;

	if (s == NULL)
		return (NULL);
	i = 0;
	j = 0;
	if (s[i] == '\0')
		return ((char*)s);
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
		i++;
	size = ft_strlen(s) - 1;
	if (size + 1 == i)
		return ("");
	while (s[size] == ' ' || s[size] == '\t' || s[size] == '\n')
		size--;
	size = size - i + 1;
	if (!(as = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (j < size)
		as[j++] = s[i++];
	as[size] = '\0';
	return (as);
}

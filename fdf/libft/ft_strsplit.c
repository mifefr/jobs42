/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 21:26:11 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 22:32:23 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_trim(char *s, char c)
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
	while (s[i] == c)
		i++;
	size = ft_strlen(s) - 1;
	if (size + 1 == i)
		return ("");
	while (s[size] == c)
		size--;
	size = size - i + 1;
	if (!(as = (char *)malloc((size + 1) * sizeof(char))))
		return (NULL);
	while (j < size)
		as[j++] = s[i++];
	as[size] = '\0';
	return (as);
}

int		ft_nbwords(char *s, char c)
{
	int		i;
	int		nb;

	nb = 1;
	i = 0;
	while (s[i] != '\0')
	{
		while (s[i] != c && s[i] != '\0')
			i++;
		nb++;
		while (s[i] == c && s[i] != '\0')
			i++;
	}
	return (nb);
}

int		ft_count(char *str, int i, int c)
{
	int		count;

	count = 0;
	while (str[i] != c && str[i] != '\0')
	{
		i++;
		count++;
	}
	return (count);
}

char	**ft_strsplit(char const *s, char c)
{
	char	*str;
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	k = 0;
	if ((str = ft_trim((char*)s, c)) == NULL)
		return (NULL);
	if (!(tab = (char**)malloc((ft_nbwords(str, c) + 1) * sizeof(char*))))
		return (NULL);
	while (str[i] != '\0')
	{
		if (!(tab[j] = (char*)malloc((ft_count(str, i, c) + 1) * sizeof(char))))
			return (NULL);
		while (str[i] != c && str[i] != '\0')
			tab[j][k++] = str[i++];
		tab[j++][k] = '\0';
		while (str[i] == c)
			i++;
		k = 0;
	}
	return (tab);
}

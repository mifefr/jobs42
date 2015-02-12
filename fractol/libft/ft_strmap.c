/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:47:26 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/09 12:54:47 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*news;

	news = (char*)malloc(ft_strlen((char*)s) * sizeof(char));
	i = 0;
	while (s[i] != '\0')
	{
		news[i] = f(s[i]);
		i++;
	}
	news[i] = '\0';
	return (news);
}

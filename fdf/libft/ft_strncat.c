/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 11:39:33 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/09 15:46:17 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char	*cur;

	cur = s1;
	while (*cur != '\0')
	{
		cur++;
	}
	while (*s2 != '\0' && n > 0)
	{
		*cur = *s2;
		cur++;
		s2++;
		n--;
	}
	*cur = '\0';
	return (s1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 13:56:03 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/10 18:44:23 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	len;
	unsigned int	counter;
	char			*as;

	if (s == NULL)
		return (NULL);
	if (f == NULL)
		return (ft_strdup(s));
	len = (unsigned int)ft_strlen(s);
	as = ft_strnew(len);
	counter = 0;
	while (counter < len)
	{
		as[counter] = f(counter, s[counter]);
		counter++;
	}
	return (as);
}

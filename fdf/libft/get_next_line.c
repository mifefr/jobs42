/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/11 17:54:30 by abruyere          #+#    #+#             */
/*   Updated: 2014/11/30 21:54:06 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		make_line(char ***line, char **ret, char **tmp)
{
	if ((*tmp = ft_strchr(*ret, '\n')))
	{
		**line = *ret;
		*ret = *tmp + 1;
		**tmp = '\0';
		return (1);
	}
	else
	{
		if (*ret != NULL)
		{
			**line = *ret;
			*ret = NULL;
			return (1);
		}
		return (0);
	}
}

int		get_next_line(int const fd, char **line)
{
	char		buf[BUFF_SIZE + 1];
	char		*tmp;
	static char	*ret;
	int			i;

	if (!line)
		return (-1);
	while ((!ft_strchr(ret, '\n')))
	{
		if ((i = read(fd, buf, BUFF_SIZE)) < 1)
			break ;
		buf[i] = 0;
		if (ret == 0)
			ret = ft_strdup(buf);
		else
			ret = ft_strjoin(ret, buf);
	}
	i = make_line(&line, &ret, &tmp);
	return (i);
}

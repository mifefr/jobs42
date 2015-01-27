/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/30 15:46:27 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/30 15:51:24 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_error(char const *msg)
{
	ft_putendl(msg);
	return (0);
}

int		ft_error2(char const *msg)
{
	perror(msg);
	return (0);
}

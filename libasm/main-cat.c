/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/28 19:05:42 by abruyere          #+#    #+#             */
/*   Updated: 2015/05/28 20:18:14 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libfts.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int fd;

	fd = open(argv[1], O_RDONLY);
	if (argc == 2)
	{
		ft_cat(fd);
	}
	return (0);
}

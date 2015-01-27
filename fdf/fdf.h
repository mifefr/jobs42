/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/12/01 08:39:41 by abruyere          #+#    #+#             */
/*   Updated: 2014/12/30 16:35:15 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H

# define FDF_H

# include "libml/libml.h"
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>

t_point	ft_makep(int x, int y, int z);
t_list	*prevelem(t_list *head, t_point p);
t_list	*ft_rev(t_list **list);
void	ft_showp(t_point p);
t_list	*ft_setdown(t_list *head);
t_point	ft_makeiso(t_point pts);
int		ft_givenbcolumn(t_list *head);
int		ft_givenbline(t_list *head);
int		ft_error(char const *msg);
int		ft_error2(char const *msg);

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abruyere <abruyere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/03 15:35:00 by abruyere          #+#    #+#             */
/*   Updated: 2015/01/03 15:35:36 by abruyere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_valabs(int nb)
{
	return ((nb < 0) ? nb * (-1) : nb);
}

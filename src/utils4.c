/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 12:50:53 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 12:22:11 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	next_isrevsort(int *tab, int size)
{
	if (size == 0)
		return (0);
	if (tab[0] > tab[1] && size > 0)
		return (0);
	return (1);
}

int	next_issorted(int *tab, int size)
{
	/*if (tab[0] == 100 || tab[0] == 75)
		ft_printf("size = %d\n", size);*/
	if (size == 0)
		return (0);
	if (tab[0] < tab[1] && size > 0)
		return (0);
	return (1);
}
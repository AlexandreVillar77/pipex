/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 16:06:17 by avillar           #+#    #+#             */
/*   Updated: 2022/04/04 15:37:39 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	*ft_numtabcpy(int *src, int size)
{
	int	i;
	int	*dst;

	i = 0;
	dst = malloc(sizeof(int) * size);
	if (!dst)
		return (0);
	while (i < size)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	catchmid(int *tab, int size)
{
	return (tab[size / 2]);
}

void	init_chunk(t_swap *swap, int n, int s, int e, int size)
{
	swap->chunk[n].num = n;
	swap->chunk[n].index_s = s;
	swap->chunk[n].index_e = e;
	swap->chunk[n].size = size;
}

void	remalloc_chunk(t_swap *swap, int num)
{
	(void)swap;
	(void)num;
}

int	find_min(int *x, int size)
{
	int	i;
	int	min;

	i = 0;
	min = x[i];
	while (i < size)
	{
		if (min > x[i])
			min = x[i];
		i++;
	}
	return (min);
}

int	find_min_afsort(int *x, int size)
{
	int	i;
	int	min;

	i = 0;
	while (i < size && x[i] < x[i + 1])
		i++;
	min = find_min(x + i, size);
	return (min);
}
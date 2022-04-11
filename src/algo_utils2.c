/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:16:15 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 12:21:16 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	push25_tob(t_swap *swap, int min)
{
	int	i;
	int v;

	i = 0;
	v = 0;
	swap->chunk_size = swap->aini_size * 0.25;
	if (swap->asize < swap->chunk_size)
		return ;
	while (v < swap->chunk_size && i < swap->asize)
	{
		if (swap->a[i] < min)
		{
			topa_tob(swap, swap->a[i]);
			i = 0;
			v++;
		}
		i++;
	}
}

int	find_max_under(int *x, int size, long int top)
{
	int	i;
	int	max;

	i = 0;
	max = x[i];
	while (i < size)
	{
		if (max < x[i] && x[i] < top)
			max = x[i];
		i++;
	}
	return (max);
}

int	find_min_under(int *x, int size, long int top)
{
	int	i;
	int	min;

	i = 0;
	min = x[i];
	while (i < size)
	{
		if (min > x[i] && x[i] > top)
			min = x[i];
		i++;
	}
	return (min);
}

int	find_quart3(t_swap *swap)
{
	int	to;
	int	*rtn;	

	to = swap->aini_size - (swap->aini_size * 0.25);
	rtn = fact_sort(swap->a, swap->asize);
	return (rtn[to]);
}

int	find_quart2(t_swap *swap)
{
	int	to;
	int	*rtn;	

	to = swap->aini_size - (swap->aini_size * 0.50);
	rtn = fact_sort(swap->a, swap->asize);
	return (rtn[to]);
}
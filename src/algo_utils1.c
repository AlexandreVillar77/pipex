/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 16:06:59 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 12:22:25 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	push50perto_b(t_swap *swap)
{
	int	i;
	int	mid;
	int	v;

	i = 0;
	mid = catchmid(fact_sort(swap->a, swap->asize), swap->asize);
	while (i < swap->asize)
	{
		if (swap->a[i] <= mid)
		{
			v = swap->a[i];
			if (i < swap->asize / 2)
			{
				while (swap->a[0] != v)
					ra(swap);
			}
			else
			{
				while (swap->a[0] != v)
					rra(swap);
			}
			i = 0;
			pb(swap);
		}
		i++;
	}
}

int	find_max(int *x, int size)
{
	int	i;
	int	max;

	i = 0;
	max = x[i];
	while (i < size)
	{
		if (max < x[i])
			max = x[i];
		i++;
	}
	return (max);
}

int	find_max_afsort(int *x, int size)
{
	int	i;
	int	max;

	i = 0;
	while (i < size - 1 && x[i] < x[i + 1])
		i++;
	max = find_max(x + i, size);
	return (max);
}

int	topa_tob(t_swap *swap, int x)
{
	int	i;
	int	v;

	i = -1;
	v = 0;
	while (++i < swap->asize && v == 0)
	{
		if (swap->a[i] == x)
		{
			v = swap->a[i];
			if (i < swap->asize / 2)
			{
				while (swap->a[0] != x)
					ra(swap);
			}
			else
			{
				while (swap->a[0] != x)
					rra(swap);
			}
			pb(swap);
		}
	}
	return (0);
}

int	topb_toa(t_swap *swap, int x)
{
	int	i;
	int	v;

	i = -1;
	v = 0;
	while (++i < swap->bsize && v == 0)
	{
		if (swap->b[i] == x)
		{
			v = swap->b[i];
			if (i < swap->bsize / 2)
			{
				while (swap->b[0] != x)
					rb(swap);
			}
			else
			{
				while (swap->b[0] != x)
					rrb(swap);
			}
			pa(swap);
			return (0);
		}
	}
	return (1);
}
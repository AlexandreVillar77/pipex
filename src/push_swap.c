/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:52:35 by avillar           #+#    #+#             */
/*   Updated: 2022/04/07 13:41:14 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sort_a(t_swap *swap)
{
	int	min;
	int	cut;

	cut = 0;
	while (is_sorted(swap->a, swap->asize) == 1)
	{
		min = find_min(swap->a, swap->asize);
		cut++;
		topa_tob(swap, min);
	}
	while (swap->bsize > 0)
		pa(swap);
}

void	sort_b(t_swap *swap)
{
	int	max;
	int	s;

	s = 0;
	while (swap->bsize > 0)
	{
		s++;
		max = find_max(swap->b, swap->bsize);
		topb_toa(swap, max);
	}
	while (next_issorted(swap->a, --s) == 0)
		pb(swap);
}

void	algo1(t_swap *swap)
{
	push50perto_b(swap);
	sort_b(swap);
	sort_a(swap);
}

int	main(int argc, char **argv)
{
	t_swap	swap;

	if (argc < 2)
		return (1);
	swap = parse(argv[1]);
	if (parse_check(argv[1]) == 1 || parse_nodup(&swap) == 1)
		return (1);
	if (is_sorted(swap.a, swap.asize) == 0)
		return (0);
	algo1(&swap);
	return (0);
}
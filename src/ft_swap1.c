/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 16:27:58 by avillar           #+#    #+#             */
/*   Updated: 2022/04/04 16:02:49 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	sa(t_swap *swap)
{
	int	s;

	s = swap->a[0];
	swap->a[0] = swap->a[1];
	swap->a[1] = s;
	ft_printf("sa\n");
}

void	sb(t_swap *swap)
{
	int	s;

	s = swap->b[0];
	swap->b[0] = swap->b[1];
	swap->b[1] = s;
	ft_printf("sb\n");
}

void	ss(t_swap *swap)
{
	sa(swap);
	sb(swap);
	ft_printf("ss\n");
}

void	ra(t_swap *swap)
{
	int	i;
	int	first;

	i = 0;
	while (i < swap->asize - 1)
	{
		if (i == 0)
			first = swap->a[i];
		swap->a[i] = swap->a[i + 1];
		i++;
	}
	swap->a[i] = first;
	ft_printf("ra\n");
}

void	pb(t_swap *swap)
{
	swap->b = remalloc(swap->b, swap->bsize + 1, swap->bsize);
	swap->bsize = swap->bsize + 1;
	if (!swap->b)
		return ;
	pdown_b(swap);
	swap->b[0] = swap->a[0];
	pup_a(swap);
	swap->a = remalloc(swap->a, swap->asize - 1, swap->asize);
	swap->asize = swap->asize - 1;
	ft_printf("pb\n");
}

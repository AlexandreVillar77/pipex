/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_swap2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 12:26:10 by avillar           #+#    #+#             */
/*   Updated: 2022/04/04 16:03:01 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

void	pdown_b(t_swap *swap)
{
	int	i;
	int	s;
	int	s2;

	i = 0;
	s = swap->b[i];
	while (i < swap->bsize - 1)
	{
		s2 = s;
		s = swap->b[i + 1];
		swap->b[i + 1] = s2;
		i++;
	}
}

void	pdown_a(t_swap *swap)
{
	int	i;
	int	s;
	int	s2;

	i = 0;
	s = swap->a[i];
	while (i < swap->asize - 1)
	{
		s2 = s;
		s = swap->a[i + 1];
		swap->a[i + 1] = s2;
		i++;
	}
}

void	pup_a(t_swap *swap)
{
	int	i;
	int	s;
	int	s2;

	i = swap->asize;
	s = swap->a[i];
	while (i > 0)
	{
		s2 = s;
		s = swap->a[i - 1];
		swap->a[i - 1] = s2;
		i--;
	}
}

void	pup_b(t_swap *swap)
{
	int	i;
	int	s;
	int	s2;

	i = swap->bsize;
	s = swap->b[i];
	while (i > 0)
	{
		s2 = s;
		s = swap->b[i - 1];
		swap->b[i - 1] = s2;
		i--;
	}
}

void	pa(t_swap *swap)
{
	swap->a = remalloc(swap->a, swap->asize + 1, swap->asize);
	swap->asize = swap->asize + 1;
	if (!swap->a)
		return ;
	pdown_a(swap);
	swap->a[0] = swap->b[0];
	pup_b(swap);
	swap->b = remalloc(swap->b, swap->bsize - 1, swap->bsize);
	swap->bsize = swap->bsize - 1;
	ft_printf("pa\n");
}

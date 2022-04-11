/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_utils3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 12:05:54 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 12:06:30 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/includes.h"

int	find_quart1(t_swap *swap)
{
	int	to;
	int	*rtn;	

	to = swap->aini_size - (swap->aini_size * 0.75);
	rtn = fact_sort(swap->a, swap->asize);
	return (rtn[to]);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:35:13 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 13:35:50 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int		countcase(char const *s, char c)
{
	int		res;
	int		i;

	i = 0;
	res = 0;
	while (s[i])
	{
		if (s[i] == c)
			res++;
		i++;
	}
	return (res + 1);
}

int		sizel(char const *s, int i, char c)
{
	int		len;

	len = 0;
	while (s[i] != c && s[i])
	{
		len++;
		i++;
	}
	return (len);
}

void	fill_tab(char const *s, char c, int x, char *dst)
{
	int		i;

	i = 0;
	while (s[x] != c && s[x])
	{
		dst[i] = s[x];
		i++;
		x++;
	}
	dst[i] = '\0';
}

int		skipc(const char *s, char c, int i)
{
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**rtn;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = 0;
	if (s == 0)
		return (0);
	if (!(rtn = malloc(sizeof(char*) * (countcase(s, c) + 1))))
		return (0);
	i = skipc(s, c, i);
	while (j <= countcase(s, c) && s[i])
	{
		len = sizel(s, i, c);
		if (!(rtn[j] = malloc(sizeof(char) * len + 1)))
			return (0);
		fill_tab(s, c, i, rtn[j]);
		i += len;
		i = skipc(s, c, i);
		j++;
	}
	rtn[j] = 0;
	return (rtn);
}
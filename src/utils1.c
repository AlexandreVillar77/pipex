/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:33:23 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 13:33:42 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i == 4)
		return (1);
	return(0);
}

int	ft_search(char *str)
{
	int	i;
	char s[4] = "PATH";

	i = 0;
	while (str[i])
	{
		if (str[0] == 'P')
			if (ft_strcmp(str + i, s) == 1)
			{
				return (1);
			}
		i++;
	}
	return (0);
}

char	*ft_substr(char **envp)
{
	int		i;
	int		res;

	i = 0;
	while (envp[i])
	{
		res = ft_search(envp[i]);
		if (res == 1)
			break;
		i++;
	}
	return (envp[i] + 5);
}
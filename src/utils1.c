/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:33:23 by avillar           #+#    #+#             */
/*   Updated: 2022/04/11 14:50:23 by avillar          ###   ########.fr       */
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
	return (0);
}

int	ft_search(char *str)
{
	int		i;
	char	*s;

	s = "PATH";
	i = 0;
	while (str[i])
	{
		if (str[0] == 'P')
			if (ft_strcmp(str + i, s) == 1)
				return (1);
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
			return (envp[i] + 5);
		i++;
	}
	return (NULL);
}

t_arg	init_arg(t_arg *arg, char **envp, char **argv)
{
	arg->cmd1_arg = ft_split(argv[2], ' ');
	if (arg->cmd1_arg[0][0] == '/')
		arg->cmd1_arg[0][ft_strlen(arg->cmd1_arg[0]) - 1] = '\0';
	arg->cmd2_arg = ft_split(argv[3], ' ');
	if (arg->cmd2_arg[0][0] == '/')
		arg->cmd2_arg[0][ft_strlen(arg->cmd2_arg[0]) - 1] = '\0';
	arg->path = ft_split(ft_substr(envp), ':');
	arg->envp = envp;
	return (*arg);
}

void	free_arg(t_arg *arg)
{
	int	i;

	i = -1;
	if (arg->cmd1_arg[0])
	{
		while (arg->cmd1_arg[++i])
			free(arg->cmd1_arg[i]);
		free(arg->cmd1_arg);
	}
	i = -1;
	if (arg->cmd2_arg[0])
	{
		while (arg->cmd2_arg[++i])
			free(arg->cmd2_arg[i]);
		free(arg->cmd2_arg);
	}
	i = -1;
	if (arg->path)
	{
		while (arg->path[++i])
			free(arg->path[i]);
		free(arg->path);
	}
}

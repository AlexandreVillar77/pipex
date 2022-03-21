/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:32:36 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 13:32:56 by avillar          ###   ########.fr       */
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

/*
int	*init_end(char *f1, char *f2)
{
	int	end[2];
	int fd;

	fd = open(f1, O_RDWR);
	if (fd < 1)
		return (NULL);
	end[0] = fd;
	fd = open(f2, O_RDWR);
	if (fd < 1)
		return (NULL);
	end[1] = fd;
	return (end);
}
*/
/*int	pipex(int f1, int f2, char **argv, char **envp)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	parent = fork();
	if (parent < 0)
	{
		perror("Fork:");
		return (1);
	}
	if(parent == 0)
		child_process(f1, argv[2]);
	else
		parent_process(f2, argv[3]);
	return (0);
}*/

int	main(int argc, char **argv, char **envp)
{
	//int	f1;
	//int	f2;
	//int	i;

	//i = 0;
	if (argc < 5 || argc > 5 || !envp)
	{
		ft_printf("Error, wrong number of argumet\n");
		ft_printf("or cannot reach environnemnt variable PATH.\n");
		return (1);
	}
	//f1 = open(argv[1], O_RDONLY);
	//f2 = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	/*if (f1 < 0 || f2 < 0)
	{
		ft_printf("Cannot open %s or create %s\n", argv[1], argv[4]);
		return (1);
	}
	pipex(f1, f2, argv, envp);*/
	(void)argv;
	/*while (envp[i])
	{
		ft_printf("envp = %s\n", envp[i]);
		i++;
	}*/
	ft_printf("rtn = %s\n", ft_substr(envp));
	return (0);
}
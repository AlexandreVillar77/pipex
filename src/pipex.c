/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:25:57 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 13:39:20 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

int	pipex(int f1, int f2, char **argv, char **envp)
{
	/*int		end[2];
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
	return (0);*/
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;

	if (argc < 5 || argc > 5 || !envp)
	{
		ft_printf("Error, wrong number of argumet\n");
		ft_printf("or cannot reach environnemnt variable PATH.\n");
		return (1);
	}
	f1 = open(argv[1], O_RDONLY);
	f2 = open (argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
	{
		ft_printf("Cannot open %s or create %s\n", argv[1], argv[4]);
		return (1);
	}
	pipex(f1, f2, argv, envp);
	return (0);
}
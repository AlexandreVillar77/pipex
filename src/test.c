/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:32:36 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 15:38:13 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"
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

void	childpro1(int fd, t_arg *data, int *end)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(fd, STDIN_FILENO) < 0 || dup2(end[1], STDOUT_FILENO) < 0)
		return (perror("Dup2: "));
	close(end[0]);
	while (data->path[++i])
	{
		cmd = ft_strjoin(data->path[i], data->cmd1_arg[0]);
		execve(cmd, data->cmd1_arg + 1, data->envp);
		//perror(cmd);
		free(cmd);
	}
	exit(EXIT_FAILURE);
}

void	pipex(int f1, int f2, t_arg *data)
{
	int		end[2];
	pid_t	parent;

	pipe(end);
	(void)f2;
	parent = fork();
	if (parent < 0)
		return (perror("Fork:"));
	if(parent == 0)
		childpro1(f1, data, end);
	close(end[0]);
	close(end[1]);
}

int	main(int argc, char **argv, char **envp)
{
	int	f1;
	int	f2;
	t_arg	data;

	if (argc < 5 || argc > 5 || !envp)
	{
		ft_printf("Error, wrong number of argumet\n");
		ft_printf("or cannot reach environnemnt variable PATH.\n");
		return (1);
	}
	f1 = open(argv[1], O_RDONLY);
	f2 = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (f1 < 0 || f2 < 0)
	{
		ft_printf("Cannot open %s or create %s\n", argv[1], argv[4]);
		return (1);
	}
	init_arg(&data, envp, argv);
	pipex(f1, f2, &data);
	free_arg(&data);
	//ft_printf("rtn = %s\n", ft_substr(envp));
	return (0);
}
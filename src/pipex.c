/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:25:57 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 16:50:56 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/includes.h"

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
		if (!cmd)
			break ;
		if (access(cmd, X_OK) == 0)
			execve(cmd, data->cmd1_arg, data->envp);
		free(cmd);
	}
	close(fd);
	perror(data->cmd1_arg[0]);
	exit (EXIT_FAILURE);
}

void	childpro2(int fd, t_arg *data, int *end)
{
	int		i;
	char	*cmd;

	i = -1;
	if (dup2(fd, STDOUT_FILENO) < 0 || dup2(end[0], STDIN_FILENO) < 0)
		return (perror("Dup2: "));
	close(end[1]);
	close(fd);
	while (data->path[++i])
	{
		cmd = ft_strjoin(data->path[i], data->cmd2_arg[0]);
		if (!cmd)
			break ;
		if (access(cmd, X_OK) == 0)
			execve(cmd, data->cmd2_arg, data->envp);
		free(cmd);
	}
	perror(data->cmd2_arg[0]);
	exit (EXIT_FAILURE);
}

void	pipex(int f1, int f2, t_arg *data)
{
	int		end[2];
	int		status;
	pid_t	child1;
	pid_t	child2;

	if (pipe(end) == -1)
		return (perror("Pipe: "));
	child1 = fork();
	if (child1 < 0)
		return (perror("Fork: "));
	if (child1 == 0)
		childpro1(f1, data, end);
	child2 = fork();
	if (child2 < 0)
		return (perror("Fork: "));
	if (child2 == 0)
		childpro2(f2, data, end);
	close(end[0]);
	close(end[1]);
	waitpid(child1, &status, 0);
	waitpid(child2, &status, 0);
}

int	main(int argc, char **argv, char **envp)
{
	int		f1;
	int		f2;
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
	close(f1);
	close(f2);
	free_arg(&data);
	return (0);
}

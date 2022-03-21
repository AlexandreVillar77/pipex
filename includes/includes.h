/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   includes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avillar <avillar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 11:18:33 by avillar           #+#    #+#             */
/*   Updated: 2022/03/21 13:41:38 by avillar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INCLUDES_H
# define INCLUDES_H

# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <ft_printf.h>

typedef	struct	s_arg{
	char	**path;
	char	**cmd1_arg;
	char	**cmd2_arg;
}				t_arg;

//fichier ft_split.c
int		countcase(char const *s, char c);
int		sizel(char const *s, int i, char c);
void	fill_tab(char const *s, char c, int x, char *dst);
int		skipc(const char *s, char c, int i);
char	**ft_split(char const *s, char c);

//fichier utils1.c
int		ft_strcmp(char *s1, char *s2);
int		ft_search(char *str);
char	*ft_substr(char **envp);

#endif
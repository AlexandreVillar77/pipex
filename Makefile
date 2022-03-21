# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avillar <avillar@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/21 11:11:31 by avillar           #+#    #+#              #
#    Updated: 2022/03/21 15:41:15 by avillar          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= pipex

SRCS		=		pipex.c			\
					ft_split.c		\
					utils1.c		\
					ft_strjoin.c	\

SRC			=		test.c			\
					ft_split.c		\
					ft_strjoin.c	\
					utils1.c		\

CFLAG = -Wall -Wextra -Werror

FSAN = -g3 -fsanitize=address

OBJS = $(addprefix src/, ${SRCS:.c=.o})

CC	= gcc

all: ft_printf/libprintf.a ${NAME}

.c.o:
	$(CC) $(CFLAG) -Ift_printf -c -I/includes/includes.h $< -o $@

${NAME}: ${OBJS}
	${CC} ${OBJS} -Lft_printf -lprintf -o $(NAME)

ft_printf/libprintf.a:
	make -C ft_printf

clean:
		rm -f ${OBJS}

fclean:	clean
	make -C ft_printf fclean
	rm -f ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2019/06/27 14:17:46 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS = main.c \
	   move_cursor_of_line.c \

INCLUDES = shell.h

OBJS = $(SRCS:.c=.o)
CC=gcc -g -Wall -Wextra -Werror -ltermcap -L ./libft -lft

all:
	make -C libft
	$(CC) $(SRCS) -I $(INCLUDES) -o $(NAME)

clean:
	rm -rf $(OBJS)
	make clean -C libft
fclean: clean
	rm -rf $(NAME)
	make fclean -C libft
re: fclean all


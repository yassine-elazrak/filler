# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2019/07/25 16:50:57 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRCS =	srcs/main.c \
		srcs/ft_put.c \
		srcs/ft_treat_cmd.c  \
		srcs/ft_treat.c  \
		srcs/ft_var.c \
		srcs/ft_read_cmd.c \
		srcs/ft_execute.c  \
		srcs/ft_free.c \
		termcap/move_cursor_of_line.c \
		termcap/ft_treat_line.c  \
		built/ft_set_2.c  \
		built/ft_setenv.c  \
		built/ft_cd.c   \
		built/ft_echo.c \

INCLUDES = .

FLAGS = -Wall -Wextra -Werror

all: libft_ $(NAME)

libft_:
	make -C libft

$(NAME): $(SRCS) $(INCLUDES)/shell.h libft/libft.a
	gcc -o $(NAME) $(FLAGS) $(SRCS) -ltermcap -L ./libft -lft -I $(INCLUDES)

clean:
	make clean -C libft

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all


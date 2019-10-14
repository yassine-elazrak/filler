# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/27 15:04:02 by yelazrak          #+#    #+#              #
#    Updated: 2019/06/24 17:10:34 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = sh_21

SRCS = mini.c \
		ft_cmd.c \
		built.c \
		ft_cd.c \
		ft_echo.c \
		 ft_set.c \
		ft_spar.c \


OBJS = $(SRCS:.c=.o)

INCLUDES = shell.h

CC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME):
	@make  -C libft
	@$(CC) $(SRCS) libft/libft.a -I $(INCLUDES) -o  $(NAME)
clean :
	@rm -rf $(OBJS)
	@make clean -C libft
fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
re: fclean all

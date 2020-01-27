# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2020/01/27 17:45:29 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yelazrak.filler

c_srcs = ft_flood.o \
		 ft_get_.o \
		 ft_read_.o \
		 main.o \

INCLUDES = .
CFLAGS = -Wall -Wextra -Werror
CC=gcc
all: libft_ $(NAME)

libft_:
	@make -C libft

$(NAME): $(c_srcs) $(INCLUDES)/filler.h libft/libft.a
	gcc -o $(NAME) $(FLAGS) $(c_srcs) -L ./libft -lft -I $(INCLUDES)
clean:
	@make clean -C libft
	@rm -rf $(c_srcs)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all

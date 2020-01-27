# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/26 18:43:13 by yelazrak          #+#    #+#              #
#    Updated: 2020/01/27 14:34:38 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = yelazrak.filler

c_srcs = ft_flood.c \
		 ft_get_.c \
		 ft_read_.c \
		 main.c \

objs = $(c_srcs:.c=.o)
INCLUDES = .

FLAGS = -g -Wall -Wextra -Werror

all: libft_ $(NAME)

libft_:
	@make -C libft

$(NAME): $(objs) $(INCLUDES)/filler.h libft/libft.a
	gcc -o $(NAME) $(FLAGS) $(objs) -L ./libft -lft -I $(INCLUDES)

$(objs): %.o : %.c 
	gcc  $(FLAGS) -c $< -o $@   -I $(INCLUDES)
clean:
	@make clean -C libft
	@rm -rf $(objs)

fclean: clean
	@make fclean -C libft
	@rm -rf $(NAME)

re: fclean all



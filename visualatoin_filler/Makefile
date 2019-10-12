# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/10 22:11:03 by yelazrak          #+#    #+#              #
#    Updated: 2019/10/10 22:14:08 by yelazrak         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = visu
SRC = .c ft_filler.c\
 		ft_read.c \
  		main.c \
 
		
OBJ = OBJS = $(SRC:.c=.o)
INC = -I includes -I libft/includes
INC +=  -L lib/lib -l SDL2-2.0.0 -l SDL2_ttf
FLGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME):
        @make -C libft
        @gcc -c $(FLGS) $(SRC) -I includes -I libft/includes
        @gcc $(FLGS) $(OBJ) libft/libft.a  -o $(NAME) $(INC)
clean:
        @rm -rf $(OBJ)
        @make clean -C libft
fclean: clean
        @make fclean -C libft
        @rm -rf $(NAME)
re: fclean all
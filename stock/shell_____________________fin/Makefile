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
		termcap/ft_key.c  \
		termcap/move_line_of_key.c \
		built/ft_set_2.c  \
		built/ft_setenv.c  \
		built/ft_cd.c   \
		built/ft_echo.c \


OBJS = $(SRCS:.c=.o)

INCLUDES = .

FLAGS = -Wall -Wextra -Werror

all: libft_ $(NAME)

libft_:
	make -C libft

$(NAME): $(OBJS) $(INCLUDES)/shell.h libft/libft.a
	gcc -o $(NAME) $(FLAGS) $(OBJS) -ltermcap -L ./libft -lft -I $(INCLUDES)

$(OBJS):%.o : %.c

		gcc  $(FLAGS) -o $@ -c $<   -I $(INCLUDES)
clean:
	make clean -C libft
	rm -rf $(OBJS)

fclean: clean
	make fclean -C libft
	rm -rf $(NAME)

re: fclean all

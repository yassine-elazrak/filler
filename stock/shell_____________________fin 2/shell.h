/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:34:56 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 16:17:33 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHELL_H
# define SHELL_H

# include <stdio.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <termios.h>
# include <dirent.h>
# include <curses.h>
# include <term.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/stat.h>
# include <unistd.h>
# include <sys/ioctl.h>

# define cclear() ft_putstr("\033[H\033[J")

typedef struct			s_cmd_tab
{
	char				**str;
	struct s_cmd_tab	*next;
}						t_cmd_tab;

typedef struct			s_var
{
	int					index;
	int					start;
	char				*tmp;
	char				*string;
	char				*var;
	char				t;
	char				c;
}						t_var;

typedef struct			s_envp
{
	char				*data;
	struct s_envp		*next;
}						t_envp;

typedef struct			s_init
{
	int					s_col;
	int					s_row;
	int					s_l;
	int					n_col;
	int					n_row;
	int					z_col;
	int					z_row;
	int					s_cursor;
	char				*out_put;
	t_envp				*ls;
	struct s_init		*next;
}						t_init;

int						ft_string_cmd(int flg, t_init *init);
void					ft_free_lst(t_envp **env);
void					ft_name(char **line);
int						my_putchar(int c);
int						key_4_of_cursor(char *str, t_init *init);
void					move_cursor_and_mangemant_fonction(char *str
		, t_init *init, t_envp *env);
void					ft_env(t_envp *env);
void					ft_copy(char **environ, t_envp **env);
void					ft_alloc_str(t_envp **head, char *new_data);
void					ft_separe_cmd(char *str,
		t_envp **lst_g, char c, t_init *init);
void					ft_treat_cmd(char *cmd,
		t_cmd_tab **list, t_init *init, t_envp *env);
char					**ft_catpath(t_envp *env);
char					*ft_var_envp(char *str, t_envp *env);
void					ft_display(char *cmd, t_init *init, t_envp *env);
void					ft_execut(char **line, t_envp *env);
void					ft_init_output(t_init *init);
void					ft_setenv(char **str, t_envp *env);
void					ft_unsetenv(char **str, t_envp **env);
char					*ft_strtrim_treat(char *s);
void					ft_path_cd(char **tab_cmd, t_envp *env);
void					ft_echo(char **argv);
void					ft_init_cmd(t_init *init);
void					ft_exit(t_init **list, t_cmd_tab **lst, t_envp *env);
void					ft_free_lst_tab(t_cmd_tab **head);
void					ft_free_lst(t_envp **lst);
void					ft_search_cmd_3(t_cmd_tab **head, char **new_data);
void					ft_init_output(t_init *init);
char					*ft_read_variable(char *str, t_envp *env);
char					*ft_user(char *str, t_envp *env);
char					**ft_treat_var(char **str, t_envp *env);
void					ft_treat_cmd(char *cmd, t_cmd_tab **list,
		t_init *init, t_envp *env);
void					ft_read(char *buffer, int position,
		t_init *init, t_envp *env);
void					ft_free_var(t_envp **tmp, char **str, char **data);
void					del_char_of_line(char **line, t_init *init);

#endif

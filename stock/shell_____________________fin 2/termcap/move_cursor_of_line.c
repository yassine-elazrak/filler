/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cursor_of_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 14:10:42 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 16:42:15 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void		ft_alloc_str(t_envp **head, char *new_data)
{
	t_envp	*new;
	t_envp	*last;

	if (!(new = (t_envp*)malloc(sizeof(t_envp))))
		return ;
	last = *head;
	new->data = ft_strdup(new_data);
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return ;
	}
	while (last->next != NULL)
		last = last->next;
	last->next = new;
	return ;
}

int			ft_cat_of_line(char *str, t_init *init)
{
	char	*line;
	char	*temp;
	char	*t_line;

	if (init->out_put == NULL)
		init->out_put = ft_strnew(0);
	line = init->out_put;
	temp = ft_strsub(line, 0, init->s_cursor);
	t_line = ft_strjoin(temp, str);
	free(temp);
	init->out_put = ft_strjoin(t_line, &init->out_put[init->s_cursor]);
	free(t_line);
	free(line);
	init->s_cursor += ft_strlen(str);
	init->s_l = ft_strlen(init->out_put);
	return (ft_strlen(init->out_put));
}

int			my_putchar(int c)
{
	write(1, &c, 1);
	return (0);
}

void		ft_cat_string_of_line(t_init *init, char *str)
{
	char	*name;
	char	*cmd;

	ft_cat_of_line(str, init);
	name = getenv("TERM");
	tgetent(NULL, name);
	cmd = tgetstr("cd", NULL);
	tputs(cmd, 0, my_putchar);
	ft_putstr_fd(&init->out_put[init->s_cursor - ft_strlen(str)], 1);
	if (init->s_cursor != init->s_l)
	{
		ft_putstr_fd("\033[", 1);
		ft_putnbr_fd(ft_strlen(&init->out_put[init->s_cursor]), 1);
		ft_putstr_fd("D", 1);
	}
}

void		move_cursor_and_mangemant_fonction(char *str,
		t_init *init, t_envp *env)
{
	if ((str[0] == 27) && (str[1] == 91) && key_4_of_cursor(str, init) != 0)
		return ;
	else if (str[0] == 10 && ft_strlen(str) == 1)
	{
		ft_putchar('\n');
		if (ft_strcmp(&init->out_put[14], "") != 0)
			ft_display(&init->out_put[14], init, env);
		ft_init_output(init);
	}
	else if (str[0] == 9)
		return ;
	else if (str[0] == 127)
	{
		del_char_of_line(&init->out_put, init);
		return ;
	}
	else
		ft_cat_string_of_line(init, str);
}

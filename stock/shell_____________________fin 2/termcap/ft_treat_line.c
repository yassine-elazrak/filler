/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 15:21:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 15:35:21 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	del_char_of_line(char **line, t_init *init)
{
	char	*t_line;
	char	*t_2_line;
	char	*cmd;
	char	*name;

	t_line = *line;
	if (!(init->s_l > 14 && init->s_cursor > 14))
		return ;
	t_2_line = ft_strsub(t_line, 0, init->s_cursor - 1);
	*line = ft_strjoin(t_2_line, &t_line[init->s_cursor]);
	name = getenv("TERM");
	tgetent(NULL, name);
	cmd = tgetstr("cd", NULL);
	tputs(tgetstr("le", NULL), 0, my_putchar);
	tputs(cmd, 0, my_putchar);
	if (init->s_cursor == init->s_l + 1)
		tputs(tgetstr("nd", NULL), 0, my_putchar);
	ft_putstr_fd(&t_line[init->s_cursor], 1);
	ft_putstr_fd("\033[", 1);
	ft_putnbr_fd(ft_strlen(&t_line[init->s_cursor]) - 1, 1);
	ft_putstr_fd("D", 1);
	(init->s_l)--;
	(init->s_cursor)--;
	free(t_2_line);
	free(t_line);
}

void	ft_init_output(t_init *init)
{
	free(init->out_put);
	init->s_cursor = 14;
	init->s_l = 14;
	init->n_col = 0;
	init->n_row = 0;
	ft_name(&init->out_put);
	ft_putstr_fd(init->out_put, 1);
}

int		key_4_of_cursor(char *str, t_init *init)
{
	if (str[2] == 65)
		return (1);
	if (str[2] == 67)
	{
		if (init->s_l > init->s_cursor)
		{
			(init->s_cursor)++;
			tputs(tgetstr("nd", NULL), 0, my_putchar);
		}
		return (1);
	}
	if (str[2] == 66)
		return (1);
	if (str[2] == 68)
	{
		if (init->s_cursor > 14)
		{
			(init->s_cursor)--;
			tputs(tgetstr("le", NULL), 0, my_putchar);
		}
		return (1);
	}
	return (0);
}

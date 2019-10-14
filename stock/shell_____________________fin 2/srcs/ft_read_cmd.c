/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_cmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 20:15:42 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 15:49:23 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void			ft_management_of_cmd(t_cmd_tab *lst, t_init *init, t_envp *env)
{
	if (ft_strcmp(lst->str[0], "setenv") == 0)
		ft_setenv(lst->str, env);
	else if (ft_strcmp(lst->str[0], "unsetenv") == 0)
		ft_unsetenv(lst->str, &env);
	else if (ft_strcmp(lst->str[0], "echo") == 0)
		ft_echo(lst->str);
	else if (ft_strcmp(lst->str[0], "env") == 0)
		ft_env(env);
	else if ((ft_strcmp(lst->str[0], "cd") == 0))
		ft_path_cd(lst->str, env);
	else if (ft_strcmp(lst->str[0], "exit") == 0)
		ft_exit(&init, &lst, env);
	else
		ft_execut(lst->str, env);
}

void			ft_display(char *cmd, t_init *init, t_envp *env)
{
	t_cmd_tab	*lst;
	t_cmd_tab	*tmp;

	lst = NULL;
	tmp = NULL;
	ft_treat_cmd(cmd, &lst, init, env);
	tmp = lst;
	if (ft_strcmp(&init->out_put[14], "") == 0)
		return ;
	while (lst)
	{
		ft_management_of_cmd(lst, init, env);
		lst = lst->next;
	}
	ft_free_lst_tab(&tmp);
}

void			ft_name(char **line)
{
	char		*str;
	char		*tmp;

	str = ft_strdup("(azrak)");
	tmp = ft_strjoin(str, "\u27A2");
	free(str);
	str = ft_strjoin(tmp, "\u27A3");
	*line = ft_strjoin(str, " ");
	free(tmp);
	free(str);
}

void			ft_read(char *buffer, int position, t_init *init, t_envp *env)
{
	static char	*t;
	char		*tmp;

	if (t == NULL)
		t = ft_strnew(0);
	if (position < 4)
	{
		tmp = t;
		t = ft_strjoin(t, buffer);
		free(tmp);
		move_cursor_and_mangemant_fonction(t, init, env);
		free(t);
		t = NULL;
	}
	else
	{
		tmp = t;
		if (t[0] == '\0')
			t = ft_strdup(buffer);
		else
			t = ft_strjoin(t, buffer);
		free(tmp);
	}
}

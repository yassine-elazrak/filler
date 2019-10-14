/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_execute.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:49:29 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/24 21:12:21 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

char		**ft_tab_lst(t_envp *lst)
{
	t_envp	*tmp;
	int		i;
	char	**array;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	if (!(array = (char **)malloc(sizeof(char*) * (i + 1))))
		return (NULL);
	i = 0;
	while (lst)
	{
		array[i] = ft_strdup(lst->data);
		i++;
		lst = lst->next;
	}
	array[i] = NULL;
	return (array);
}

char		*ft_strjoin_path(char *path, char *cmd)
{
	char	*tmp;
	char	*tmp_2;

	if (cmd[0] == '/')
		return (ft_strdup(cmd));
	if (cmd[0] == '\\')
	{
		tmp = ft_strdup(path);
		tmp_2 = ft_strjoin(tmp, "/");
		free(tmp);
		tmp = ft_strjoin(tmp_2, cmd + 1);
		free(tmp_2);
		return (tmp);
	}
	tmp = ft_strdup(path);
	tmp_2 = ft_strjoin(tmp, "/");
	free(tmp);
	tmp = ft_strjoin(tmp_2, cmd);
	free(tmp_2);
	return (tmp);
}

void		ft_exec_cmd(char *file, char **line, t_envp *env)
{
	pid_t	child_pid;
	char	**envp;

	child_pid = fork();
	envp = ft_tab_lst(env);
	if (child_pid == -1)
	{
		perror(NULL);
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(file, line, envp) != -1)
		{
			exit(0);
		}
	}
	else
		wait(NULL);
	ft_tabfree(&envp);
}

void		ft_missg(char *str, char ***array)
{
	ft_tabfree(array);
	ft_putstr("minishell: command not found:");
	ft_putendl(str);
}

void		ft_execut(char **line, t_envp *env)
{
	int		i;
	char	*cmd;
	char	**array;

	i = -1;
	if (access(line[0], F_OK) != -1)
	{
		ft_exec_cmd(line[0], line, env);
		return ;
	}
	if (!(array = ft_catpath(env)))
		return ;
	while (array[++i])
	{
		cmd = ft_strjoin_path(array[i], line[0]);
		if (access(cmd, F_OK) != -1 && ft_strlen(line[0]))
		{
			ft_exec_cmd(cmd, line, env);
			free(cmd);
			ft_tabfree(&array);
			return ;
		}
		free(cmd);
	}
	ft_missg(line[0], &array);
}

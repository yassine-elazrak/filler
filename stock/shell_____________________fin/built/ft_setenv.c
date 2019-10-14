/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:39:46 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 12:44:43 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void			ft_unsetenv_1(char *str, t_envp **env)
{
	t_envp		*lst;
	t_envp		*tmp;

	lst = *env;
	tmp = (*env)->next;
	str = ft_strjoin(str, "=");
	while (tmp)
	{
		if (ft_strncmp(tmp->data, str, ft_strlen(str)) == 0)
		{
			lst->next = tmp->next;
			ft_free_var(&tmp, &str, &tmp->data);
			return ;
		}
		tmp = tmp->next;
		lst = lst->next;
	}
	free(str);
}

int				ft_setenv_1(char **str, t_envp *env)
{
	t_envp		*tmp;
	char		*tmp_2;
	char		*tmp_3;

	tmp = env;
	while (tmp)
	{
		if (ft_strncmp(tmp->data, str[1], ft_strlen(str[1])) == 0)
		{
			tmp_2 = tmp->data;
			tmp_3 = ft_strjoin(str[1], "=");
			tmp->data = ft_strjoin(tmp_3, str[2]);
			free(tmp_3);
			free(tmp_2);
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

static int		ft_check(char **str)
{
	int			i;

	i = 0;
	while (str[i])
	{
		if (i > 0 && ft_strchr(str[i], '='))
		{
			ft_putstr("setenv: Variable name must");
			ft_putendl(" contain alphanumeric characters.");
			return (-2);
		}
		i++;
	}
	return (i);
}

void			ft_setenv(char **str, t_envp *env)
{
	int			i;
	char		*tmp;
	char		*tmp_2;

	i = 0;
	if (0 > (i = ft_check(str)))
		return ;
	if (i == 1)
		ft_env(env);
	else if (i > 3)
		ft_putendl("setenv: Too many arguments.");
	else
	{
		if (ft_setenv_1(str, env))
			return ;
		tmp = ft_strjoin(str[1], "=");
		if (str[2])
			tmp_2 = ft_strjoin(tmp, str[2]);
		else
			tmp_2 = ft_strdup(tmp);
		free(tmp);
		ft_alloc_str(&env, tmp_2);
		free(tmp_2);
	}
}

void			ft_unsetenv(char **str, t_envp **env)
{
	int			i;

	i = 1;
	while (str[i])
	{
		ft_unsetenv_1(str[i], env);
		i++;
	}
}

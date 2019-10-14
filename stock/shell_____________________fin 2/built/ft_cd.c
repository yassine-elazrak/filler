/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 16:47:44 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/24 22:34:00 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void		ft_chang_var_envp(t_envp *env)
{
	char	*tmp_2;
	char	**buffer;
	char	**buffer_2;

	if (!(buffer = (char **)malloc(sizeof(char *) * 4)))
		return ;
	buffer[0] = ft_strdup("setenv");
	buffer[1] = ft_strdup("OLDPWD");
	if (!(tmp_2 = ft_var_envp("PWD", env)))
		return ;
	buffer[2] = ft_strdup(tmp_2);
	buffer[3] = NULL;
	ft_setenv(buffer, env);
	ft_tabfree(&buffer);
	if (!(tmp_2 = getcwd(NULL, 0)))
		return ;
	if (!(buffer_2 = (char **)malloc(sizeof(char *) * 4)))
		return ;
	buffer_2[0] = ft_strdup("setenv");
	buffer_2[1] = ft_strdup("PWD");
	buffer_2[2] = ft_strdup(tmp_2);
	buffer_2[3] = NULL;
	free(tmp_2);
	ft_setenv(buffer_2, env);
	ft_tabfree(&buffer_2);
}

char		*ft_cd(char **tab_cmd, t_envp *env)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (!(tab_cmd[1]))
	{
		if ((tmp = ft_var_envp("HOME", env)))
			str = ft_strdup(tmp);
	}
	else if ((tab_cmd[2]))
		ft_putendl("cd : Too many arguments.");
	else if (ft_strcmp(tab_cmd[1], "~") == 0)
	{
		if ((tmp = ft_var_envp("HOME", env)))
			str = ft_strdup(tmp);
	}
	else if (ft_strcmp(tab_cmd[1], "-") == 0)
	{
		if ((tmp = ft_var_envp("OLDPWD", env)))
			str = ft_strdup(tmp);
	}
	else
		str = ft_strdup(tab_cmd[1]);
	return (str);
}

void		ft_path_cd(char **tab_cmd, t_envp *env)
{
	char	*str;

	if (!(str = ft_cd(tab_cmd, env)))
		return ;
	if (chdir(str) != -1)
		ft_chang_var_envp(env);
	else
	{
		ft_putstr("cd: no such file or directory:");
		ft_putendl(tab_cmd[1]);
	}
	ft_strdel(&str);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_var.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:51:53 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/27 09:12:00 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int					ft_var_join(char *string, char **va_r, t_envp *env)
{
	char			*tmp;
	char			*var;

	var = *va_r;
	if ((tmp = ft_var_envp(string, env)))
	{
		*va_r = ft_strjoin(var, tmp);
		free(var);
		free(string);
		return (1);
	}
	free(string);
	return (0);
}

static void			ft_var(char *str, int *valuer, char **va_r, t_envp *env)
{
	t_var			lst;

	lst.var = *va_r;
	lst.index = *valuer;
	if (ft_strchr(str, '$') && lst.var == NULL)
		lst.var = ft_strsub(str, 0, ft_strchr(str, '$') - str);
	else if (lst.var == NULL)
		lst.var = ft_strnew(0);
	while (str[lst.index] == '$')
		lst.index++;
	lst.start = lst.index;
	while (str[lst.index] != '$' && str[lst.index] != '\0')
		lst.index++;
	lst.string = ft_strsub(str, lst.start, lst.index - lst.start);
	lst.tmp = lst.string;
	lst.string = ft_strtrim_treat(lst.string);
	free(lst.tmp);
	if (ft_var_join(lst.string, &lst.var, env))
	{
		lst.tmp = lst.var;
		*va_r = ft_strdup(lst.var);
		free(lst.tmp);
	}
	*valuer = lst.index;
}

char				*ft_read_variable(char *str, t_envp *env)
{
	int				index;
	char			*var;
	int				value;

	index = 0;
	value = 0;
	var = NULL;
	while (str[index])
	{
		if (str[index] == '\'')
			value++;
		if (str[index] == '$' && (value % 2) == 0)
		{
			ft_var(str, &index, &var, env);
			index--;
		}
		index++;
	}
	return (var);
}

int					my_ls_of_user(char *name)
{
	DIR				*dir;
	struct dirent	*file;

	if (!(dir = opendir("/Users")))
	{
		perror(NULL);
		exit(1);
	}
	else
	{
		while ((file = readdir(dir)) != NULL)
		{
			if (ft_strcmp(file->d_name, name) == 0)
			{
				closedir(dir);
				return (1);
			}
		}
		closedir(dir);
	}
	ft_putstr("minishell");
	ft_putstr("no such user or named directory:");
	ft_putstr(name);
	return (0);
}

char				*ft_user(char *str, t_envp *env)
{
	char			*tmp;
	char			*tmp_2;

	tmp_2 = NULL;
	tmp = NULL;
	if (str[1] == '/')
	{
		if ((tmp = ft_var_envp("HOME", env)))
			tmp_2 = ft_strjoin(tmp, &str[1]);
	}
	else
	{
		if (ft_strcmp(str, "~") == 0)
		{
			if ((tmp = ft_var_envp("HOME", env)))
			{
				tmp_2 = ft_strdup(tmp);
			}	
		}
		else
		{
			if (my_ls_of_user(&str[1]) == 1)
				tmp_2 = ft_strjoin("/Users/", &str[1]);		
		}
	}
	return (tmp_2);
}

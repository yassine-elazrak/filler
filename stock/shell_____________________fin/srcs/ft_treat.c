/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 18:57:43 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/27 09:09:42 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

char		*ft_var_envp(char *str, t_envp *env)
{
	char	*tmp;

	while (env)
	{
		if (ft_strncmp(env->data, str, ft_strlen(str)) == 0)
		{
			tmp = ft_strchr(env->data, '=');
			return (tmp + 1);
		}
		env = env->next;
	}
	return (NULL);
}

char		**ft_treat(char **str)
{
	int		i;
	char	**buffer;

	i = 0;
	buffer = NULL;
	while (str[i])
		i++;
	if (!(buffer = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	while (str[i])
	{
		buffer[i] = ft_strtrim_treat(str[i]);
		i++;
	}
	buffer[i] = NULL;
	ft_tabfree(&str);
	return (buffer);
}

void		ft_cmd_tab(char *cmd, t_cmd_tab **list, t_envp *env)
{
	char	**str;

	str = NULL;
	str = ft_strsplit(cmd, ' ');
	str = ft_treat_var(str, env);
	str = ft_treat(str);
	ft_search_cmd_3(list, str);
}

void		ft_treat_cmd(char *cmd, t_cmd_tab **list, t_init *init, t_envp *env)
{
	t_envp *lst;
	t_envp *tmp;

	lst = NULL;
	tmp = NULL;
	(void)env;
	ft_separe_cmd(cmd, &lst, ';', init);
	tmp = lst;
	if (lst == NULL)
		return ;
	while (lst)
	{
		ft_cmd_tab(lst->data, list, env);
		lst = lst->next;
	}
	ft_free_lst(&tmp);
}

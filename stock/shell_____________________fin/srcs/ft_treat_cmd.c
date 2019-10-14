/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treat_cmd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 17:04:41 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/27 09:04:34 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void		ft_home(t_envp *env, char **str, char ***tt, int i)
{
	char	**t;
	char	*tmp;

	t = *tt;
	if ((tmp = ft_user(str[i], env)))
	{
		t[i] = ft_strdup(tmp);
		free(tmp);
	}
	// else
	// {
	// 	if ((tmp = ft_var_envp("HOME", env)))
	// 		t[i] = ft_strdup(tmp);
	// 	else
	// 	{
	// 		return ;
	// 	}
		
	// }
}

void		ft_treat_var_2(char **str, char ***tt, char *tmp, t_envp *env)
{
	int		i;
	char	**t;

	i = -1;
	t = *tt;
	while (str[++i])
	{
		if (str[i][0] == '$' || ft_strchr(str[i], '$'))
		{
			if ((tmp = ft_read_variable(str[i], env)))
			{
				t[i] = ft_strdup(tmp);
				free(tmp);
			}
			else
				t[i] = ft_strdup(str[i]);
		}
		else if (str[i][0] == '~')
			ft_home(env, str, &t, i);
		else
			t[i] = ft_strdup(str[i]);
	}
	t[i] = NULL;
}

char		**ft_treat_var(char **str, t_envp *env)
{
	char	**t;
	char	*tmp;
	int		i;

	i = 0;
	tmp = NULL;
	(void)env;
	while (str[i])
		i++;
	if (!(t = (char **)malloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = 0;
	ft_treat_var_2(&str[i], &t, tmp, env);
	ft_tabfree(&str);
	return (t);
}

void		ft_search_cmd_3(t_cmd_tab **head, char **new_data)
{
	t_cmd_tab *new;
	t_cmd_tab *last;

	if (!(new = (t_cmd_tab*)malloc(sizeof(t_cmd_tab))))
		return ;
	last = *head;
	new->str = new_data;
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

char		*ft_strtrim_treat(char *s)
{
	char	*t;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	j = ft_strlen(s);
	while ((s[j - 1] == '\'' || s[j - 1] == '"' || s[j - 1] == '\''))
	{
		j--;
	}
	while ((s[i] == '\'' || s[i] == '\'' || s[i] == '"'))
	{
		j--;
		i++;
	}
	if (j <= 0)
		j = 0;
	t = ft_strsub(s, i, j);
	return (t);
}

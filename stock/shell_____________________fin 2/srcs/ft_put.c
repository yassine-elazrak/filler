/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 14:22:32 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/24 20:40:16 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

int			ft_check(char *t, char c)
{
	int		i;

	i = 0;
	while (t[i])
	{
		if (t[i] == ' ')
			i++;
		else if (t[i] == c)
		{
			ft_putstr("minishell: parse error near `");
			ft_putchar(c);
			ft_putchar(c);
			ft_putendl("\'");
			return (1);
		}
		else
			return (0);
	}
	return (0);
}

void		ft_init_cmd(t_init *init)
{
	char	*tmp;

	tmp = ft_strsub(init->out_put, 0, 14);
	free(init->out_put);
	init->s_cursor = 14;
	init->s_l = 14;
	init->n_col = 0;
	init->n_row = 0;
	init->out_put = ft_strdup(tmp);
	free(tmp);
}

int			ft_check_var(char *str, t_var *lst, t_init *init, t_envp **lst_g)
{
	if (ft_check(&str[lst->index + 1], lst->c))
	{
		ft_init_cmd(init);
		ft_free_lst(lst_g);
		return (0);
	}
	lst->string = ft_strsub(str, lst->start, lst->index - lst->start);
	if (ft_strlen(lst->string) != 0)
		ft_alloc_str(lst_g, lst->string);
	free(lst->string);
	lst->start = lst->index + 1;
	return (0);
}

void		ft_join(char *str, t_var *lst, t_envp **lst_g)
{
	lst->string = ft_strsub(str, lst->start, lst->index - lst->start);
	if (ft_strlen(lst->string) != 0)
		ft_alloc_str(lst_g, lst->string);
	free(lst->string);
}

void		ft_separe_cmd(char *str, t_envp **lst_g, char c, t_init *init)
{
	t_var	lst;

	lst.index = -1;
	lst.start = 0;
	lst.c = c;
	while (str[++lst.index])
	{
		if (str[lst.index] == '"' || str[lst.index] == '\'')
		{
			lst.t = str[lst.index];
			lst.index++;
			while (str[lst.index] != lst.t && str[lst.index])
				lst.index++;
			if (str[lst.index] != lst.t)
			{
				ft_putendl("error command");
				ft_init_cmd(init);
				ft_free_lst(lst_g);
				return ;
			}
		}
		if (str[lst.index] == c)
			ft_check_var(str, &lst, init, lst_g);
	}
	ft_join(str, &lst, lst_g);
}

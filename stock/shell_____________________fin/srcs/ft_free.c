/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 10:17:02 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 15:50:59 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void			ft_free_lst(t_envp **lst)
{
	if ((*lst))
	{
		if ((*lst)->next)
			ft_free_lst(&(*lst)->next);
		free((*lst)->data);
		free(*lst);
		*lst = NULL;
	}
}

void			ft_free_lst_tab(t_cmd_tab **head)
{
	t_cmd_tab	*lst;
	t_cmd_tab	*tmp;

	lst = *head;
	while (lst)
	{
		tmp = lst;
		ft_tabfree(&lst->str);
		lst = lst->next;
		free(tmp);
	}
}

void			ft_free_var(t_envp **tmp, char **str, char **data)
{
	free(*data);
	free(*tmp);
	free(*str);
}

void			ft_exit(t_init **list, t_cmd_tab **lst, t_envp *env)
{
	t_init		*init;

	init = *list;
	free(init->out_put);
	free(init);
	ft_free_lst(&env);
	ft_free_lst_tab(lst);
	exit(1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 20:23:25 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/24 15:13:47 by mmostafa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	ft_env(t_envp *env)
{
	int		i;
	t_envp	*envp;

	i = 0;
	envp = env;
	while (envp)
	{
		ft_putendl(envp->data);
		envp = envp->next;
	}
}

void	ft_copy(char **environ, t_envp **env)
{
	int i;

	i = 0;
	while (environ[i])
	{
		ft_alloc_str(env, environ[i]);
		i++;
	}
}

char	**ft_catpath(t_envp *env)
{
	char **array;
	char *tmp;

	tmp = NULL;
	if (!(tmp = ft_var_envp("PATH", env)))
	{
		ft_putchar('\n');
		ft_putendl("PATH : Undefined variable.");
		return (NULL);
	}
	array = ft_strsplit(tmp, ':');
	return (array);
}

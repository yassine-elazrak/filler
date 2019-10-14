/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/21 16:09:56 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 15:16:49 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void	ft_flag(char ***k, char **t)
{
	char		*l;
	char		**d;

	if (!(d = (char **)malloc(sizeof(char *) * 7)))
		return ;
	if (!(l = ft_strnew(5)))
		return ;
	d[0] = ft_strdup("\\t");
	d[1] = ft_strdup("\\a");
	d[2] = ft_strdup("\\r");
	d[3] = ft_strdup("\\v");
	d[4] = ft_strdup("\\b");
	d[5] = ft_strdup("\\n");
	d[6] = NULL;
	l[0] = '\t';
	l[1] = '\a';
	l[2] = '\r';
	l[3] = '\v';
	l[4] = '\b';
	l[5] = '\n';
	*k = d;
	*t = l;
}

void	ft_c(char **t)
{
	int		b;
	int		a;
	char	**d;
	char	*l;
	int		i;

	ft_flag(&d, &l);
	i = -1;
	while (d[++i])
	{
		a = ft_strlen((*t));
		if ((ft_strstr((*t), d[i])))
		{
			b = ft_strlen(ft_strstr((*t), d[i]));
			(*t)[a - b] = l[i];
			ft_memmove(&(*t)[(a - b) + 1], &(*t)[(a - b) + 2], b);
			(*t)[a - 1] = '\0';
		}
	}
	ft_putstr((*t));
	ft_tabfree(&d);
	free(l);
}

void	ft_echo(char **av)
{
	int		i;
	int		j;

	i = 1;
	j = 0;
	if (av[1])
	{
		if (ft_strcmp(av[1], "-n") == 0)
		{
			i = 2;
			j = 1;
		}
		while (av[i])
		{
			ft_c(&av[i]);
			ft_putchar(' ');
			i++;
		}
	}
	if (j == 0)
		ft_putchar('\n');
}

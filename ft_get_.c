/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 19:08:56 by yelazrak          #+#    #+#             */
/*   Updated: 2020/01/27 15:02:09 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_new__(t_point **list, int x, int y, int z)
{
	t_point		*new;
	t_point		*lst;

	new = NULL;
	lst = *list;
	if (!(new = (t_point *)malloc(sizeof(t_point))))
		return ;
	new->next = NULL;
	new->x = x;
	new->y = y;
	new->z = z;
	if (*list == NULL)
		*list = new;
	else
	{
		while (lst->next)
			lst = lst->next;
		lst->next = new;
	}
}

static void		ft_get__piece(t_filler *filler)
{
	int			i;
	int			j;
	char		*line;

	i = -1;
	line = NULL;
	filler->lst = NULL;
	while (++i < filler->y_p)
	{
		get_next_line(0, &line);
		j = -1;
		while (++j < filler->x_p)
		{
			if (line[j] == '*')
				ft_new__(&filler->lst, j, i, 1);
			else
				ft_new__(&filler->lst, j, i, 0);
		}
		ft_strdel(&line);
	}
}

static void		ft_vide_memoir__(t_filler *filler)
{
	t_point		*tmp;
	t_point		*tmp_free;

	tmp_free = NULL;
	tmp = filler->lst;
	while (tmp)
	{
		tmp_free = tmp;
		tmp = tmp->next;
		free(tmp_free);
	}
	ft_free_mp_(filler);
	filler->lst = NULL;
}

void			ft_get_size_piece_(char *str, t_filler *filler)
{
	char		**d_split;

	d_split = NULL;
	d_split = ft_strsplit(ft_strstr(str, " "), ' ');
	filler->y_p = ft_atoi(d_split[0]);
	filler->x_p = ft_atoi(d_split[1]);
	ft_tabfree(&d_split);
	ft_get__piece(filler);
	ft_flood__(filler);
	ft_get_score___of_mp_(filler);
	ft_vide_memoir__(filler);
	ft_putnbr(filler->y_p);
	ft_putchar(' ');
	ft_putnbr(filler->x_p);
	ft_putchar('\n');
}

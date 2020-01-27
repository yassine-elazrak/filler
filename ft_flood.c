/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flood.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 22:02:20 by yelazrak          #+#    #+#             */
/*   Updated: 2020/01/27 17:15:10 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int				ft_index_pos___(t_filler *f, t_point *l, int a, int c)
{
	if (l->x < f->x_t - 1 && f->map[l->y][l->x] == c &&
		f->map[l->y][l->x + 1] == 0)
		f->map[l->y][l->x + 1] = a;
	if (l->x > 0 && f->map[l->y][l->x] == c && f->map[l->y][l->x - 1] == 0)
		f->map[l->y][l->x - 1] = a;
	if (l->y < f->y_t - 1 && f->map[l->y][l->x] == c &&
		f->map[l->y + 1][l->x] == 0)
		f->map[l->y + 1][l->x] = a;
	if (l->y > 0 && f->map[l->y][l->x] == c && f->map[l->y - 1][l->x] == 0)
		f->map[l->y - 1][l->x] = a;
	if (l->y < f->y_t - 1 && l->x < f->x_t - 1 &&
		f->map[l->y][l->x] == 0 && f->map[l->y + 1][l->x + 1] == c)
		f->map[l->y][l->x] = a;
	if (l->y > 0 && l->x < f->x_t - 1 && f->map[l->y][l->x] == 0 &&
		f->map[l->y - 1][l->x + 1] == c)
		f->map[l->y][l->x] = a;
	if (l->y < f->y_t - 1 && l->x > 0 && f->map[l->y][l->x] == 0 &&
		f->map[l->y + 1][l->x - 1] == c)
		f->map[l->y][l->x] = a;
	if (l->y > 0 && l->x > 0 && f->map[l->y][l->x] == 0 &&
		f->map[l->y - 1][l->x - 1] == c)
		f->map[l->y][l->x] = a;
	return (0);
}

void			ft_flood__(t_filler *filler)
{
	int			i;
	int			j;
	int			c;
	t_point		lst;

	c = 3;
	while (++c < (filler->x_t + filler->y_t + 4))
	{
		j = -1;
		while (++j < filler->y_t)
		{
			i = -1;
			while (++i < filler->x_t)
			{
				lst.x = i;
				lst.y = j;
				if (c == 4)
					ft_index_pos___(filler, &lst, c, filler->yo_index);
				else
					ft_index_pos___(filler, &lst, c, c - 1);
			}
		}
	}
}

int				ft_get__and__check___scor__(t_filler *filler, int x, int y)
{
	t_point		*tmp;
	int			c;

	c = 0;
	tmp = filler->lst;
	filler->s_cor_tmp = 0;
	while (tmp)
	{
		if ((tmp->x + x < 0) || tmp->x + x >= filler->x_t ||
		tmp->y + y < 0 || tmp->y + y >= filler->y_t)
			return (-1);
		if (tmp->z == 1 &&
		filler->map[tmp->y + y][tmp->x + x] == filler->yo_index)
			return (-1);
		if (tmp->z == 1)
			filler->s_cor_tmp += filler->map[tmp->y + y][tmp->x + x];
		if (tmp->z == 1 &&
		filler->map[tmp->y + y][tmp->x + x] == filler->my_index)
			c++;
		tmp = tmp->next;
	}
	if (c == 1)
		return (0);
	return (-1);
}

void			ft_get_score___of_mp_(t_filler *filler)
{
	int			x;
	int			y;

	y = -1;
	filler->s_cor = -1;
	while (++y < filler->y_t)
	{
		x = -1;
		while (++x < filler->x_t)
		{
			if ((ft_get__and__check___scor__(filler, x, y)) == 0)
			{
				if (filler->s_cor == -1 || filler->s_cor > filler->s_cor_tmp)
				{
					filler->s_cor = filler->s_cor_tmp;
					filler->x_p = x;
					filler->y_p = y;
				}
			}
		}
	}
}

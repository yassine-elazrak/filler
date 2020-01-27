/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 15:04:00 by yelazrak          #+#    #+#             */
/*   Updated: 2020/01/27 17:35:56 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static void		ft_get_play_(char *str, t_filler *filler)
{
	int			i;

	i = ft_strlen("$$$ exec p1 :");
	if (ft_strstr(str, ".filler"))
	{
		if (ft_strncmp(str, "$$$ exec p1 :", i) == 0)
		{
			filler->my_index = 1;
			filler->yo_index = 2;
		}
		else
		{
			filler->my_index = 2;
			filler->yo_index = 1;
		}
	}
}

static int		*ft_int__new(char *str, t_filler *filler)
{
	int			i;
	int			*con_int_;

	con_int_ = NULL;
	if (!(con_int_ = (int *)malloc(sizeof(int) * filler->x_t)))
		return (NULL);
	i = -1;
	while (str[++i])
	{
		if (str[i] == 'o' || str[i] == 'O')
			con_int_[i] = 1;
		else if (str[i] == 'x' || str[i] == 'X')
			con_int_[i] = 2;
		else
			con_int_[i] = 0;
	}
	return (con_int_);
}

static void		ft_get__mp(t_filler *filler)
{
	int			i;
	char		*line;

	i = -1;
	line = NULL;
	if (!(filler->map = (int **)malloc(sizeof(int *) * filler->y_t)))
		return ;
	while (++i < filler->y_t)
	{
		get_next_line(0, &line);
		filler->map[i] = ft_int__new(ft_strchr(line, ' ') + 1, filler);
		ft_strdel(&line);
	}
	get_next_line(0, &line);
	ft_get_size_piece_(line, filler);
	ft_strdel(&line);
}

static void		ft_get_size_map_(char *str, t_filler *filler)
{
	char		**d_split;
	char		*line;

	d_split = NULL;
	line = NULL;
	d_split = ft_strsplit(ft_strstr(str, " "), ' ');
	filler->y_t = ft_atoi(d_split[0]);
	filler->x_t = ft_atoi(d_split[1]);
	ft_tabfree(&d_split);
	get_next_line(0, &line);
	ft_strdel(&line);
	ft_get__mp(filler);
}

int				ft_read_(t_filler *filler)
{
	char		*line;
	int			i;

	line = NULL;
	i = ft_strlen("Plateau");
	while (get_next_line(0, &line))
	{
		if ((ft_strncmp(line, "$$$", 3) == 0))
			ft_get_play_(line, filler);
		if (ft_strncmp(line, "Plateau", i) == 0)
			ft_get_size_map_(line, filler);
		ft_strdel(&line);
	}
	return (1);
}

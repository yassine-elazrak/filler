/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 14:55:07 by yelazrak          #+#    #+#             */
/*   Updated: 2020/01/27 17:14:29 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void			ft_free_mp_(t_filler *filler)
{
	int			i;

	i = 0;
	while (i < filler->y_t)
	{
		free(filler->map[i]);
		i++;
	}
	free(filler->map);
	filler->map = NULL;
}

int				main(void)
{
	t_filler	*filler;

	if (!(filler = (t_filler *)malloc(sizeof(t_filler))))
		return (0);
	ft_memset((void *)filler, '\0', sizeof(t_filler));
	while (42)
	{
		if (ft_read_(filler))
		{
			ft_memdel((void **)&filler);
			return (0);
		}
	}
	return (0);
}

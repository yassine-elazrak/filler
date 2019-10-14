/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabfree.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 18:51:27 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/26 15:08:48 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_tabfree(char ***t)
{
	size_t i;
	char **tab;

	i = 0;
	tab = *t;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(*t);
}
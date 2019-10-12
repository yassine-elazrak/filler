/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 12:15:46 by yelazrak          #+#    #+#             */
/*   Updated: 2019/04/07 13:00:31 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_strclr(char *s)
{
	size_t i;
	size_t j;

	i = 0;
	if (!s)
		return ;
	j = ft_strlen(s);
	while (i < j)
	{
		s[i] = '\0';
		i++;
	}
}

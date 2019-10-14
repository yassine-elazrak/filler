/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 17:12:53 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/24 17:19:29 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sh_21.h"

void	ft_ter()
{
	char *name_term;
	 struct termios term;

if (!(name_term = getenv("TERM")))
	return ;
	if( tcgetattr(0,&term) == -1)
		return ;
	term.c_lfalg &= ~(ICANON);
	TR==
}
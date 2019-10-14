/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/27 16:38:03 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/27 18:34:42 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"


int		ft_key_compinitoin(char *str, t_init *init)
{
	 if ((str[1] == 91) && str[2] == 70)
	{
		ft_string_cmd(2, init);
		return (1);
	}	
	else if ((str[1] == 91) && str[2] == 72)
	{
		ft_string_cmd(1, init);
		return (1);
	}
	else if (str[1] == 102)
	{
		ft_string_cmd(8, init);
		return (1);
	}	
	else if (str[1] == 98)
	{
		ft_string_cmd(7, init);
		return (1);
	}
	return (0);
}



int		ft_key_compinitoin_2(char *str, t_init *init)
{
	 if ((str[1] == 91) && str[2] == 49 && str[3] == 59 && str[4] == 53 && str[5] == 65)
	{
		ft_string_cmd(10, init);
		return (1);
	}	
	else if ((str[1] == 91) && str[2] == 49 && str[3] == 59 && str[4] == 53 && str[5] == 66)
	{
		ft_string_cmd(9, init);
		return (1);
	}
	return (0);
}

int		key_4_of_cursor(char *str, t_init *init)
{
	if (ft_key_compinitoin(str, init))
	{
		return (1);
	}
	else if (ft_key_compinitoin_2(str, init))
	{
		return (1);
	}
	else if ((str[1] == 91) && str[2] == 65)
		return (1);
	else if ( (str[1] == 91) && str[2] == 67)
	{	
		ft_move_cursor_right(init);	
		return (1);
	}
	else if ((str[1] == 91) && str[2] == 66)
	{
		
		return (1);
	}
	else if ((str[1] == 91) && str[2] == 68)
	{
		ft_move_cursor_left(init);			
		return (1);
	}
	else
		return (0);
	return (1);
}
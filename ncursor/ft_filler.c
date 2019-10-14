/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:12:57 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/13 14:36:35 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void    ft_init_00(t_init *init, t_filler *filler)
{


    filler->p1 = ft_strdup("players/carli.filler");
     filler->p2 = ft_strdup("players/superjeannot.filler");
     init->i = ft_strlen(filler->p1) > ft_strlen(filler->p2) ? ft_strlen(filler->p1) : ft_strlen(filler->p2);  
    init->w = filler->x +  init->i + 15 ;
     init->h = (filler->y);
     init->x0 = init->w -  init->i - 4;
     init->y0 = 2;
}

void    ft_put_image(t_filler  *filler, t_init *init)
{
    int i;
    int j;
    i  = -1;
      wclear(init->win);
    while (++i < filler->y )
    {
        j = -1;
        while (++j < filler->x)
        {
            if (filler->map[i][j] == 'o' || (filler->map[i][j] == 'O'))
                 mvwaddch(init->win, i, j, 'O');
            else if (filler->map[i][j] == 'X' || filler->map[i][j] == 'x' )
                mvwaddch(init->win, i, j, 'X');
            else 
                mvwaddch(init->win, i, j, '.'); 
                 refresh();        
        }
    } 
    
}
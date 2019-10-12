/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_filler.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 20:12:57 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/08 12:05:27 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


void    ft_init_00(t_init *init, t_filler *filler)
{
    int i;


    i = filler->y > filler->x ? filler->y : filler->x;
    init->a = 900 / i;
    init->w = filler->x * init->a +filler->x ;
     init->h = (filler->y) * init->a + (filler->y) + 200 ;
     printf("a = [%d]       i = [%d]\n",init->a, i);

}

void    ft_put_image(t_filler  *filler, t_init *init)
{
    int i;
    int j;
    int a;
    int b;
    SDL_Rect        rect;

    i  = -1;
    b = 200;
    while (++i < filler->y)
    {
        j = -1;
        a = 0;
        while (++j < filler->x)
        {
            rect.w = init->a;
            rect.y = b;  
            rect.x = a;
            rect.h = init->a ;
            if (filler->map[i][j] == 'o' || (filler->map[i][j] == 'O'))
                SDL_FillRect(init->surf, &rect, SDL_MapRGB( init->surf->format, 255, 25,25));
            else if (filler->map[i][j] == 'X')
                 SDL_FillRect(init->surf, &rect, SDL_MapRGB( init->surf->format, 5, 25,225));
            else 
             SDL_FillRect(init->surf, &rect, SDL_MapRGB( init->surf->format, 255, 255,255));
            a += init->a + 1;
        }
        b += init->a + 1;
    }
}
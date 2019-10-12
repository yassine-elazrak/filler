/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:29:36 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/11 14:59:30 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define  FILLER_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include "libft/libft.h"
#include "SDL2/SDL_ttf.h"
#include "SDL2/SDL_image.h"

# define WIDTH 1400
# define HEIGHT 1000



typedef struct      s_init
{
    SDL_Window      *win;
    SDL_Surface     *surf;
    SDL_Rect        rect;
    SDL_Event       event;
    int             quit;
    double             w;
    double             h;
    int                 a;

}                   t_init;



typedef struct      s_filler
{
  char              **map;
  int               y;
  int               x;
  char              *p1;
  char              *p2;

}                   t_filler;




void    ft_put_image(t_filler  *filler, t_init *init);
void    ft_init_00(t_init *init, t_filler *filler);
int     ft_read(t_filler *filler);
void    ft_print(t_filler *filler);



#endif


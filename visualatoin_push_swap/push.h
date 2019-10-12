/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:29:36 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/04 16:41:55 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_H
# define PUSH_H

#include "SDL2/SDL.h"
#include <stdio.h>
#include "libft/libft.h"


# define WIDTH 1000
# define HEIGHT 1000
typedef struct          s_val
{
    SDL_Rect            rect;
    int					data;
	int					size;
	int					pos;
	struct  s_val		*end;
	struct  s_val		*prev;
    struct  s_val       *next;
    
}                       t_val;


typedef struct      s_init
{
    SDL_Window      *win;
    SDL_Surface     *surf;
    SDL_Rect        rect;
    SDL_Event       event;
    int             quit;
    double             w;
    double             h;
    t_val           *lst;

}                   t_init;


void		ft_print(t_val *tmp, char *str);
void        ft_remplissage(int argc, char **argv, t_init *init);













#endif


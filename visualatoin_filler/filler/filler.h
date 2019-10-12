/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:56:01 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/07 18:33:07 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
#define FILLER_H
#include "libft/libft.h"
#include <stdio.h>


typedef struct              s_point
{
   int                      x;
   int                      y;
   struct  s_point          *next;
   
}                           t_point;


typedef struct              s_filler
{
    int                     x0;
    int                     y0;
    char                    *p2;
    char                    *p1;
    int                     score;
    int                     x;
    int                     y;
    int                     x_p;
    int                     y_p;
    int                    p_2;
    int                    p_1;
    int                    **map;
    char                    **piece;
    t_point                 *lst;
    t_point                 *put;
}                           t_filler;

void                        ft_get_tail(char *str, t_filler *filler);
void                        ft_flood(t_filler *filler);
void                        ft_print(int **str ,int y ,int x);
void                        ft_get_score(t_filler *filler);
void                        ft_get_player(t_filler *filler, char *str);

#endif
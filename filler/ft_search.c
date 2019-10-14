/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 08:34:35 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/12 17:09:24 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"



void        ft_print(int **str ,int y ,int x)
{
    int i;
    int j;

    i = -1;
    dprintf(2,"-------------------------------------------------------\n");
    while (++i < y)
    {
        j = -1;
        ft_putchar_fd('|',2);
        while (++j < x)
        {
            dprintf(2,"%d",str[i][j]);
        }
          ft_putchar_fd('|',2);
        ft_putchar_fd('\n',2);
    }
}



    
int     ft_put_piece(t_filler *filler, int x,int y)
{
    t_point     *tmp;
    int         a;
    int         c;

    tmp = filler->lst;
    a = 0;
    c = 0;
   
    while (tmp)
    { 

        if ((tmp->x + x < 0) || tmp->x + x >= filler->x || tmp->y + y <  0 || tmp->y + y >= filler->y)
                return (-1);      
        if (filler->map[tmp->y + y][tmp->x + x] == filler->p_2)
             return (-1);
        a += filler->map[tmp->y + y][tmp->x + x];
        if (filler->map[tmp->y + y][tmp->x + x] == filler->p_1)
            c++;
        tmp = tmp->next;    
    }
    if (c == 1 )
    {
         if ((filler->x0 + x < 0) || filler->x0 + x >= filler->x || filler->y0 + y <  0 || filler->y0 + y >= filler->y)
                return (-1); 
        if ( filler->score == -1)
        {
            filler->score = a;
            filler->x_p = x - filler->x0;
            filler->y_p = y - filler->y0;
        }
        else if (a < filler->score)
        {
            filler->score = a;
            filler->x_p = x - filler->x0;
            filler->y_p = y-filler->y0;
       }
    }   
    return (0);
}


void    ft_get_score(t_filler *filler)
{
    int x;
    int y;

    x = -1;
    y = -1;
    while (++y < filler->y)
    {
        x = -1;
        while (++x < filler->x)
        {
            
            ft_put_piece(filler, x, y);
        }
    }
}

int     ft_check_pos(t_filler *filler , t_point *lst, int a, int c)
{ 
    if ( lst->x < filler->x - 1 && filler->map[lst->y][lst->x] == c && filler->map[lst->y][lst->x + 1] == 0)
        filler->map[lst->y][lst->x + 1] = a;
    if ( lst->x  > 0 && filler->map[lst->y][lst->x] == c && filler->map[lst->y][lst->x - 1] == 0)
        filler->map[lst->y][lst->x - 1] = a;
    if ( lst->y < filler->y - 1 && filler->map[lst->y][lst->x] == c && filler->map[lst->y + 1][lst->x] == 0)
        filler->map[lst->y + 1][lst->x] = a;
    if (lst->y > 0 && filler->map[lst->y][lst->x] == c && filler->map[lst->y - 1][lst->x] == 0)
        filler->map[lst->y - 1][lst->x] = a;
     if (  lst->y  < filler->y - 1  && lst->x < filler->x - 1 && filler->map[lst->y][lst->x] == 0 &&///
     filler->map[lst->y + 1][lst->x + 1] == c )
        filler->map[lst->y][lst->x] = a;///
     if (lst->y > 0 && lst->x  < filler->x - 1 && filler->map[lst->y][lst->x] == 0 &&//
    filler->map[lst->y - 1][lst->x + 1] == c)
        filler->map[lst->y][lst->x] = a;       
     if ( lst->y < filler->y  - 1 && lst->x > 0 && filler->map[lst->y][lst->x] == 0 &&//
     filler->map[lst->y + 1][lst->x - 1] == c)/////
       filler->map[lst->y][lst->x] = a;
     if ( lst->y > 0 && lst->x > 0 && filler->map[lst->y][lst->x] == 0 &&
     filler->map[lst->y -1][lst->x - 1] == c)
        filler->map[lst->y][lst->x] = a;
    return (0);  
}

void        ft_search_positoin(t_point *lst, t_filler *filler, int player,int c)
{
    int       i;
    int       j;

    i = -1;
    j = -1;
    while (++i < filler->y)
    {
        j = -1;
        while (++j <filler->x)
        {
           
            lst->x = j;
            lst->y = i;
            ft_check_pos(filler , lst, c, player);
        }
    }

}

void    ft_flood(t_filler *filler)
{
    t_point lst;
    char    c;
    int     i;

    i = 0;
    c = 1;
   
    while (i < filler->y)
    {  
        if (i == 0)
            ft_search_positoin(&lst, filler, filler->p_2, c);
        else
            ft_search_positoin(&lst, filler,c - 1, c);
        
        i++;
        c++;
    } 
   
    ft_get_score(filler); 
    ft_putnbr(filler->y_p);
    ft_putchar(' ');
    ft_putnbr(filler->x_p);
    ft_putchar('\n');
    dprintf(2,"\n scor44 = |%d |    x = %d      y = %d  \n",filler->p_2, filler->x_p, filler->y_p);
}




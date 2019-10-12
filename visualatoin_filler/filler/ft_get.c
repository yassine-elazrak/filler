/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 14:00:11 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/07 19:01:41 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void        ft_new(t_point **list, int x, int y)
{
    t_point *new;
    t_point *lst;

    new = NULL;
    lst = *list;
    if (!(new = (t_point *)malloc(sizeof(t_point))))
        return ;
    new->next = NULL;
    new->x = x;
    new->y = y;
    // dprintf(2, "\n|tmp->x = %d tmp->y = %d|\n\n",new->x,new->y);
   
    if (*list == NULL)
        *list = new;
    else
    {
        while (lst->next)
            lst  = lst->next;
        lst->next = new;
    }
}

void        ft_get_cord(t_filler *filler)
{
    int i;
    int j;
    int x;
    int y;
    int a;

    i = -1;
    a = 0;
    while (++i < filler->y_p)
    {
        j = -1;//ft_putendl_fd(filler->piece[i],2);
        while (++j < filler->x_p)
        {
            if (a == 0 && filler->piece[i][j] == '*')
            {
                filler->x0 = j;
                filler->y0 = i;
                a = 1;
            }
            if (filler->piece[i][j] == '*')
                ft_new(&filler->lst, j - filler->x0, i - filler->y0);
        }
    }
}

void       ft_piece(char *str, t_filler *filler)
{

    int     i;
    char    *line;
    char    **tab;

    line = NULL;
        tab = ft_strsplit(str,' ');
        filler->x_p = ft_atoi(tab[2]);
        filler->y_p = ft_atoi(tab[1]);
        if (!(filler->piece = (char **)malloc(sizeof(char *) * filler->y_p)))
            return ;
        i = 0;
        while (i < filler->y_p)
        {   
            get_next_line(0,&line);
            filler->piece[i] = ft_strdup(line);
           //ft_putendl_fd(filler->piece[i], 2);
            i++;
            ft_strdel(&line);
        }
        ft_get_cord(filler);
        //ft_putendl_fd("yassine\n", 2);
        ft_flood(filler);
        ft_print(filler->map,filler->y, filler->x);
       ft_tabfree(&tab);
}

int *ft_strdup_nbr(char *str, int a)
{
    int *tab;
    int i;

    i = 0;
    if (!(tab = (int *)malloc(sizeof(int) * a)))
        return (NULL);
    while (i < a)
    {
        if (str[i] == 'o' || str[i] == 'O')
            tab[i] = -1;
        else if (str[i] == 'X')
            tab[i] = -2;
        else
            tab[i] = 0;
        i++;
    }
    return (tab);
}

void    ft_get_tail(char *str, t_filler *filler)
{
    int i;
    char   *line;
    char **tab;

    i = 0;
    line = NULL;
    tab = NULL;
    if (ft_strstr(str,"Plateau"))
    {
        
        tab = ft_strsplit(str,' ');
        filler->y = ft_atoi(tab[1]);
        filler->x = ft_atoi(tab[2]);
        if (!(filler->map = (int **)malloc(sizeof(int *) * filler->y)))
            return ;
       get_next_line(0,&line);
       ft_strdel(&line);
        while (get_next_line(0,&line))
        {
           if (ft_strncmp(line,"Piece",ft_strlen("Piece")) == 0)
            {
                ft_piece(line, filler);
                 ft_strdel(&line);
                return ;
            }
            filler->map[i] = ft_strdup_nbr(ft_strchr(line, ' ') + 1, filler->x);
           // ft_putendl_fd(filler->map[i], 2);
           
            i++;
            ft_strdel(&line);
        }
        ft_tabfree(&tab);
    }
}


// int main()
// {
//     t_filler *filler;

//     filler = NULL;

//     if (!(filler = (t_filler * )malloc(sizeof(t_filler))))
//         return 0;

//     filler->lst = NULL;
//     filler->y_p = 3;
//     filler->x_p = 3;
//     filler->piece = (char **)malloc(sizeof(char *)*3);
//     filler->piece[0] = ft_strdup("..*"); 
//      filler->piece[1] = ft_strdup("***"); 
//       filler->piece[2] = ft_strdup("*.*"); 
//       ft_get_cord(filler);
//       t_point *lst;

//       lst = filler->lst;
//       while(lst)
//       {
//            printf("x = [%d]            y = [%d]\n",lst->x,lst->y);
//            lst = lst->next;
//       }
//       return 0;

// }
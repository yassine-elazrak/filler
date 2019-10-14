/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 09:18:59 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/08 10:12:14 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


// void        ft_free_lst(t_filler *filler)
// {
//   ft_tabfree(&filler->piece);
//   ft_free_int(&filler->map, filler->y);
//   ft_strdel(&filler->p1);
//   ft_strdel(&filler->p2);

// }
void ft_print(t_filler *filler)
{
    int i;
    dprintf(2, "plate y = %d        plat x =%d   = \n",filler->y, filler->x);
    while (i < filler->y)
    {
        ft_putendl_fd(filler->map[i], 2);
        i++;
    }
}
void          ft_get_player(t_filler *filler, char *str)
{
     
      if (ft_strncmp(str, "$$$ exec p2",ft_strlen("$$$ exec p2")) == 0)
      {
          filler->p2 = ft_strdup(ft_strchr(str, '['));
         
      }   
    if (ft_strncmp(str, "$$$ exec p1",ft_strlen("$$$ exec p1")) == 0)
      {
          filler->p1 = ft_strdup(ft_strchr(str, '['));
      }
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
        if (!(filler->map = (char **)malloc(sizeof(char *) * filler->y)))
            return ;
       get_next_line(0,&line);
       ft_strdel(&line);
        while (get_next_line(0,&line))
        {
           if (ft_strncmp(line,"Piece",ft_strlen("Piece")) == 0)
            {
                // ft_piece(line, filler);
                //  ft_strdel(&line);
                return ;
            }
            filler->map[i] = ft_strdup(ft_strchr(line, ' ') + 1);
           // ft_putendl_fd(filler->map[i], 2);
           
            i++;
            ft_strdel(&line);
        }
        ft_tabfree(tab);
    }
}

int  ft_read(t_filler *filler)
{
    char *line;
    ///t_filler *filler; 

    line = NULL;
    //filler = NULL;
 
          while (get_next_line(0,&line))
          {
              if (ft_strncmp(line,"$$$",ft_strlen("$$$")) == 0)
                    ft_get_player(filler, line);

                if (ft_strncmp(line,"Plateau",ft_strlen("Plateau")) == 0)
                    ft_get_player(filler, line);
                if (ft_strncmp(line,"Plateau",ft_strlen("Plateau")) == 0)
                {
                  ft_get_tail(line, filler);
                  ft_strdel(&line);
                   return 0;
                }
            ft_strdel(&line);
          }

    return 0;
}

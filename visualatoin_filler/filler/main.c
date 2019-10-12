/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/05 13:14:44 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/07 19:06:53 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include "filler.h"


void          ft_free_int(int ***str, int j)
{
  int i;

  i = 0;
  while (i < j)
  {
     ft_memdel((void **)str[i]);
    i++;
  }
  ft_memdel((void **)str);
}

void        ft_free_lst(t_filler *filler)
{
  ft_tabfree(&filler->piece);
  ft_free_int(&filler->map, filler->y);
  ft_strdel(&filler->p1);
  ft_strdel(&filler->p2);

}
void          ft_get_player(t_filler *filler, char *str)
{
     
      if (ft_strncmp(str, "$$$ exec p2",ft_strlen("$$$ exec p2")) == 0)
      {
          filler->p2 = ft_strdup(ft_strchr(str, '['));
          if (ft_strstr(str, "a.out"))
          {
            filler->p_1 = -2;
            filler->p_2 = -1;
          }
         
      }   
    if (ft_strncmp(str, "$$$ exec p1",ft_strlen("$$$ exec p1")) == 0)
      {
          filler->p1 = ft_strdup(ft_strchr(str, '['));
      }
}

int  ft_read(void)
{
    char *line;
    t_filler *filler; 

    line = NULL;
    filler = NULL;
 
    if (!(filler = (t_filler *)malloc(sizeof(t_filler))))
      return (0);
          filler->lst = NULL;       
          filler->score = -1;   
          filler->p_1 = -1;
          filler->p_2 = -2;
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


int main(int argc, char **argv)
{
 // while (1)
  {
    ft_read();

  }
  return (0);
}

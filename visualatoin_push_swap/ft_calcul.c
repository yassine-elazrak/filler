/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calcul.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:29:13 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/04 17:52:54 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

// void		ft_index(t_val *lst_a, int *tab, int s_t)
// {
	
// 	while (lst_a->next)
// 	{
// 		lst_a->pos = ft_search(tab, lst_a->data , 0,  s_t - 1);
// 		lst_a = lst_a->next;
// 	}
// }
void		ft_print(t_val *tmp, char *str)
{
	ft_putendl(str);
	if (tmp  == NULL)
		return;
	while (tmp)
	{
	  printf("data == [%d]  \n", tmp->data);
  // printf("data == [%d]   width = [%d]   heigth = [%d]   x = [%d]    y = [%d]\n",tmp->data), tmp->rect.w, tmp->rect.h,  tmp->rect.x,  tmp->rect.y);
		tmp = tmp->next;
	}
		printf("\n---------------------\n");
}


// void        ft_new(t_init *init, int data)
// {
//     t_val  *new;

//     new = NULL;
//     if (!(new = (t_val *)malloc(sizeof(t_val))))
//         return ;
//     new->data  = data;
//     new->next = NULL;
//     if (init->lst == NULL)
//     {
//         init->lst = new;
//         return ;
//     }
//     new->next =  init->lst;
//     init->lst = new;
// }  
 
 void	ft_new(	t_val **lst, int data)
{
	t_val *new;

	new = NULL;
	if (*lst == NULL)
	{
		if (!(*lst = (	t_val *)malloc(sizeof(	t_val))))
				return ;
		(*lst)->data = data;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		(*lst)->size = 1;
		(*lst)->end = (*lst);
		return ;
	}
	if (!(new = (t_val *)malloc(sizeof(t_val))))
			return ;
	new->next = NULL;
	new->data = data;
	new->size = (*lst)->size + 1;
	(*lst)->prev = new;
	new->end = (*lst)->end;
	new->next = (*lst);
	(*lst) = new;
}



 void    ft_get_dimentoin(t_init *init)
{
    t_val *lst;
    int     i;
    int     a;

    lst = NULL;
    a = 0;
    i = init->w;
    lst  = init->lst;
    while (lst)
    {
        lst->rect.w = 200;//(int)lst->data * i; 
        lst->rect.y = a;  
        lst->rect.x = 10;
        lst->rect.h = init->h ;
   //printf("data == [%d]   width = [%d]   heigth = [%d]   x = [%d]    y = [%d]\n\n",lst->data, lst->rect.w, lst->rect.h,  lst->rect.x,  lst->rect.y);

        //printf("x = [%d]        y = [%d]    \n", lst->rect.h,  lst->rect.w);
        //ft_print(lst, "lst_a");
       
        SDL_FillRect(init->surf, &lst->rect, SDL_MapRGB( init->surf->format, 255, 255,255));
         lst = lst->next;
         SDL_UpdateWindowSurface( init->win);
        a += 10 + init->h;
    }
}

void ft_remplissage(int argc, char **argv,t_init *init)
{
    int i;
    int max;
    int mini;
    int  a;

    i  = argc - 1;
    max = ft_atoi(argv[1]);
    mini = ft_atoi(argv[1]);
    while (i > 0)
    {
       a = ft_atoi(argv[i]);
       ft_new(&init->lst, a);
        if (a < mini)
            mini = a;
        if (a > max)
            max = a;
        i--;
    }
    a = (int)(HEIGHT / (argc - 1));
    init->h  = a - 13;
     a = (int)(WIDTH  / abs(max - mini));
     init->w = a;
    ft_get_dimentoin(init);
}


// int main(int argc, char **argv)
// {
//     int i;
//     t_init init;

//     init.lst = NULL;
//     init.h = 0;
//     init.w = 0;

//     ft_remplissage(argc, argv, &init);
// }



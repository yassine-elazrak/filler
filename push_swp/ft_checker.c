/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:30:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/05 11:29:46 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"




int ft_search(int arr[], int x, int l, int r) 
{ 
    if (r >= l) 
    { 
        int mid = l + (r - l) / 2; 
        if (arr[mid] == x) 
            return mid;  
        if (arr[mid] > x) 
            return ft_search(arr, x, l, mid - 1); 
        return ft_search(arr, x, mid + 1, r); 
    } 
    return 0; 
} 
 
//  if ((*pvot_b)->next)
// 		{
// 			 pvot = ft_get_pvot(tab, (*pvot_b)->data, (*pvot_b)->next->data, s_t);
// 				tmp = (*pvot_b);
// 			(*pvot_b) = (*pvot_b)->next;
// 			pvot = ft_get_pvot(tab, (*pvot_b)->data, pvot, s_t);
// 			if ((*pvot_b)->next)
// 				pvot = ft_get_pvot(tab, (*pvot_b)->next->data, pvot, s_t);
// 			// if ((*pvot_b)->next->next != NULL)
// 			 	//pvot = ft_get_pvot(tab, (*pvot_b)->next->next->data, pvot, s_t);
				
// 				free(tmp);
// 		}

int			ft_get_pvot(int *tab, int a, int b, int s_t)
{
  
	a = ft_search(tab, a, 0, s_t);
	b = ft_search(tab, b, 0, s_t);
   // printf("av =  %d    bv =    %d ,   char = |%d|  \n",a,b ,tab[a  + ((b - a) / 2)]);
	if (a < b)
		return (tab[a  + ((b - a) / 3)]);	
	return (tab[b + ((a - b) / 3)]);
}

int 	ft_is_sort(int *tab, int s_t, t_init *lst)
{
    int i;
    t_init *lst_a;
    t_init *end;

    lst_a = lst->end;
    end = lst->end;
   i  = lst_a->data;
	while (lst_a)
	{
         
		   --s_t;
		if (lst_a->data != tab[s_t])
		{
            lst->end = end;
            if (lst_a->next)
			    return (lst_a->next->data);
            else
            {
                 return (lst_a->data);
            }
            
		}
        i  = lst_a->data;
		lst_a = lst_a->prev;
     
	}
    lst->end = end;
	return (i);
}

void	ft_exec(t_init **lst_a, t_init **lst_b, char *str)
{
	//ft_putendl_fd(str, 1);
    (void)lst_a;
    (void)lst_b;
	ft_checker(str, lst_a, lst_b);
	//ft_strdel(&str);
}

void	ft_checker(char	*str,t_init **lst_a, t_init **lst_b)
{

	if (ft_strcmp(str, "pb") == 0)
	{
			ft_push(lst_a, lst_b);
	}
	if (ft_strcmp(str, "pa") == 0)
	{
			ft_push(lst_b, lst_a);
	}
	if (ft_strcmp(str, "sa") == 0)
	{
		ft_swap(&(*lst_a)->data, &(*lst_a)->next->data);
		ft_swap(&(*lst_a)->pos, &(*lst_a)->next->pos);
	}
	if (ft_strcmp(str, "sb") == 0)
	{
		ft_swap(&(*lst_b)->data, &(*lst_b)->next->data);
		ft_swap(&(*lst_b)->pos, &(*lst_b)->next->pos);
	}
	if (ft_strcmp(str, "ss") == 0)
	{
		ft_swap(&(*lst_a)->data, &(*lst_a)->next->data);
		ft_swap(&(*lst_b)->data, &(*lst_b)->next->data);
		ft_swap(&(*lst_a)->pos, &(*lst_a)->next->pos);
		ft_swap(&(*lst_b)->pos, &(*lst_b)->next->pos);
	}
	if (ft_strcmp(str, "ra") == 0)
	{
		///printf("stra = %d			end = %d			\n",(*lst_a)->data,(*lst_a)->end->data);
		ft_rotate(lst_a, &(*lst_a)->end);
		//printf("fffstra = %d			ffffend = %d			\n",(*lst_a)->data,(*lst_a)->end->data);

	}
	if (ft_strcmp(str, "rb") == 0)
		ft_rotate(lst_b, &(*lst_b)->end);
	if (ft_strcmp(str, "rr") == 0)
	{
		ft_rotate(lst_a, &(*lst_a)->end);
		ft_rotate(lst_b, &(*lst_b)->end);
	}
	if (ft_strcmp(str, "rra") == 0)
	{
	
		ft_reverse_rotate(lst_a, &((*lst_a)->end));
	}
	if (ft_strcmp(str, "rrb") == 0)
		ft_reverse_rotate(lst_b, &(*lst_b)->end);
	if (ft_strcmp(str, "rrr") == 0)
	{
			ft_reverse_rotate(lst_a, &(*lst_a)->end);
			ft_reverse_rotate(lst_b, &(*lst_b)->end);
	}

	ft_print(*lst_a,"list_a",str);
	ft_print(*lst_b, "lst_b", str);
}

int			ft_check_sort(t_init *lst_a)
{
	while(lst_a->next)
	{
		if (lst_a->data > lst_a->next->data)
		{
			ft_putendl("KO");
			return (0);
		}
		lst_a = lst_a->next;
	}
	return (1);
}
// int main(int argc, char **argv)
// {
// 	int		i;
// 	t_init	*lst_a;
// 	t_init	*lst_b;
// 	char  *str;
// 	char	**line;

// 	lst_a = NULL;
// 	lst_b = NULL;
// 	str = NULL;
// 	line = NULL;
// 	if (argc == 1)
// 		return (0);
// 	i = argc ;
// 	while (--i > 0)
// 		ft_new(&lst_a,atoi(argv[i]));
// 	get_next_line(0, &str);
// 	line = ft_strsplit(str, ' ');
// 	ft_strdel(&str);
// 	i = -1;
// 	while (line[++i])
// 		ft_check(line[i], &lst_a, &lst_b);
// 	if (ft_check_sort(lst_a))
// 		ft_putendl("OK");
// 	return (0);
// }
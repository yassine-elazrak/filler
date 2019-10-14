/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:07:12 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/03 10:44:59 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// static int			ft_search(int *tab, int cas_search, int s_0,int s_t)
// {
// 	int valuer;
//     int r_s;
// printf("vvvv=%d         s_0 = %d        s_t = %d\n",cas_search,s_0, s_t);
// // if (s_0 == s_t)
// //     return (s_t);
// 	valuer = tab[s_0 + ((s_t - s_0) / 2)];//ft_putendl("jhdjhdhkhg");
// 	if ( cas_search == valuer)
// 		return (s_0  + ((s_t - s_0) / 2));
// 	if ( cas_search > valuer)
// 		 return (ft_search(tab,  cas_search, (s_0 + ((s_t - s_0) / 2)), s_t));
// 	else
// 		 return (ft_search(tab,  cas_search , s_0,  (s_0 + ((s_t - s_0) / 2))));
// }

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
		return (tab[a  + ((b - a) / 4)]);	
	return (tab[b + ((a - b) / 4)]);
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
	ft_putendl_fd(str, 1);
    (void)lst_a;
    (void)lst_b;
	ft_checker(str, lst_a, lst_b);
	//ft_strdel(&str);
}

void    ft_push_swap_ab(t_init **lst_a, t_init **lst_b,int pvot, int pvot_b)
{
    	if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->data > pvot) &&
       (((*lst_b)->data < (*lst_b)->end->data)))
            ft_exec(lst_a, lst_b, "rr");
    
     else if (( *lst_b != NULL && (*lst_b)->next != NULL && ( (*lst_b)->data > (*lst_b)->end->data) &&
        (*lst_b)->data < (*lst_b)->end->data))
            ft_exec(lst_a, lst_b, "rrr");
    else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->data > (*lst_a)->next->data) &&
        (*lst_b)->data < (*lst_b)->next->data)
            ft_exec(lst_a, lst_b, "ss");
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->end->data < pvot ))
            ft_exec(lst_a, lst_b, "rra");
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > pvot))
    {
            ft_exec(lst_a, lst_b, "ra");
    }
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > (*lst_a)->next->data))
            ft_exec(lst_a, lst_b, "sa");

     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->data > (*lst_b)->data))
            ft_exec(lst_a, lst_b, "rrb");
   
 
  
    else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data < (*lst_b)->next->data))
            ft_exec(lst_a, lst_b, "sb");
    
     else  if (( *lst_b != NULL && (*lst_b)->next != NULL && ((*lst_b)->data <(*lst_b)->end->data)))// || (*lst_b)->data < pvot_b)))
    {
       // printf("pvot_bbb = %d     pvot = %d\n",pvot_b, pvot);
            ft_exec(lst_a, lst_b, "rb");
    }
     
    // else if ( *lst_a != NULL && (*lst_a)->next != NULL  &&  (*lst_a)->data <= pvot)
    //  {
    //     ft_exec(lst_a, lst_b, "pb");
    //    // ft_push_swap_c(lst_a, lst_b, pvot);
     
    //  } 

}
void    ft_push_swap_a(t_init **lst_a, t_init **lst_b,int pvot, int pvot_b)
{
    	if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->data > pvot) &&
       (((*lst_b)->data < (*lst_b)->end->data)))
            ft_exec(lst_a, lst_b, "rr");
    
     else if (( *lst_b != NULL && (*lst_b)->next != NULL && ( (*lst_b)->data > (*lst_b)->end->data) &&
        (*lst_b)->data < (*lst_b)->end->data))
            ft_exec(lst_a, lst_b, "rrr");
    else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->data > (*lst_a)->next->data) &&
        (*lst_b)->data < (*lst_b)->next->data)
            ft_exec(lst_a, lst_b, "ss");
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->end->data < pvot ))
            ft_exec(lst_a, lst_b, "rra");
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > pvot))
    {
            ft_exec(lst_a, lst_b, "ra");
    }
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > (*lst_a)->next->data))
            ft_exec(lst_a, lst_b, "sa");

     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->data > (*lst_b)->data))
            ft_exec(lst_a, lst_b, "rrb");
   
 
  
    else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data < (*lst_b)->next->data))
            ft_exec(lst_a, lst_b, "sb");
    
     else  if (( *lst_b != NULL && (*lst_b)->next != NULL && ((*lst_b)->data <(*lst_b)->end->data)))// || (*lst_b)->data < pvot_b)))
    {
       // printf("pvot_bbb = %d     pvot = %d\n",pvot_b, pvot);
            ft_exec(lst_a, lst_b, "rb");
    }
     
    else if ( *lst_a != NULL && (*lst_a)->next != NULL  &&  (*lst_a)->data <= pvot)
     {
        ft_exec(lst_a, lst_b, "pb");
       // ft_push_swap_c(lst_a, lst_b, pvot);
     
     } 

}

void    ft_push_swap_b(t_init **lst_a, t_init **lst_b,int pvot)
{
  
    if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data < pvot) &&
        (*lst_a)->data > (*lst_a)->end->data)
            ft_exec(lst_a, lst_b, "rr");
     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->data > pvot) &&
        (*lst_a)->data > (*lst_a)->end->data )
            ft_exec(lst_a, lst_b, "rrr");
     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->data > (*lst_a)->next->data) &&
        (*lst_b)->data < (*lst_b)->next->data)
            ft_exec(lst_a, lst_b, "ss");
  
     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->data > pvot))
            ft_exec(lst_a, lst_b, "rrb");   
       else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->end->data < (*lst_a)->data ))
            ft_exec(lst_a, lst_b, "rra");   
    else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data < (*lst_b)->next->data))
            ft_exec(lst_a, lst_b, "sb");
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > (*lst_a)->next->data))
            ft_exec(lst_a, lst_b, "sa");   
   else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data < pvot))
    {
            ft_exec(lst_a, lst_b, "rb");
    }
    else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > (*lst_a)->end->data))
    {
            ft_exec(lst_a, lst_b, "ra");
           ///ft_push_swap_a(lst_a, lst_b, pvot, 0);
    }
    else if ( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data >= pvot)
        ft_exec(lst_a, lst_b, "pa");
   // ft_push_swap_a(lst_a, lst_b, pvot);

}







































// void    ft_push_swap_b(t_init **lst_a, t_init **lst_b, int pvot)
// {
//     if ( *lst_b != NULL && (*lst_b)->data < pvot)
//         ft_exec(lst_a, lst_b, "pa");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->data < pvot) &&
//         (*lst_b)->data > (*lst_b)->end->data)
//             ft_exec(lst_a, lst_b, "rr");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->end->data < pvot) &&
//         (*lst_b)->data > (*lst_b)->end->data)
//             ft_exec(lst_a, lst_b, "rrr");
//     else if (((*lst_a)->data > (*lst_a)->next->data))
//             ft_exec(lst_a, lst_b, "sa");
//     else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->data > pvot))
//             ft_exec(lst_a, lst_b, "ra");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->data > (*lst_a)->next->data) &&
//         (*lst_b)->data < (*lst_b)->next->data)
//             ft_exec(lst_a, lst_b, "ss");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->data < (*lst_b)->next->data))
//             ft_exec(lst_a, lst_b, "sb");
//     //ft_push_swap_b(lst_a, lst_b, pvot);

// }

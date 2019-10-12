/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:07:12 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/05 12:54:02 by yelazrak         ###   ########.fr       */
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

// int ft_search(int arr[], int x, int l, int r) 
// { 
//     if (r >= l) 
//     { 
//         int mid = l + (r - l) / 2; 
//         if (arr[mid] == x) 
//             return mid;  
//         if (arr[mid] > x) 
//             return ft_search(arr, x, l, mid - 1); 
//         return ft_search(arr, x, mid + 1, r); 
//     } 
//     return 0; 
// } 
 
// //  if ((*pvot_b)->next)
// // 		{
// // 			 pvot = ft_get_pvot(tab, (*pvot_b)->pos, (*pvot_b)->next->pos, s_t);
// // 				tmp = (*pvot_b);
// // 			(*pvot_b) = (*pvot_b)->next;
// // 			pvot = ft_get_pvot(tab, (*pvot_b)->pos, pvot, s_t);
// // 			if ((*pvot_b)->next)
// // 				pvot = ft_get_pvot(tab, (*pvot_b)->next->pos, pvot, s_t);
// // 			// if ((*pvot_b)->next->next != NULL)
// // 			 	//pvot = ft_get_pvot(tab, (*pvot_b)->next->next->pos, pvot, s_t);
				
// // 				free(tmp);
// // 		}

// int			ft_get_pvot(int *tab, int a, int b, int s_t)
// {
  
// 	a = ft_search(tab, a, 0, s_t);
// 	b = ft_search(tab, b, 0, s_t);
//    // printf("av =  %d    bv =    %d ,   char = |%d|  \n",a,b ,tab[a  + ((b - a) / 2)]);
// 	if (a < b)
// 		return (tab[a  + ((b - a) / 3)]);	
// 	return (tab[b + ((a - b) / 3)]);
// }

// int 	ft_is_sort(int *tab, int s_t, t_init *lst)
// {
//     int i;
//     t_init *lst_a;
//     t_init *end;

//     lst_a = lst->end;
//     end = lst->end;
//    i  = lst_a->pos;
// 	while (lst_a)
// 	{
         
// 		   --s_t;
// 		if (lst_a->pos != tab[s_t])
// 		{
//             lst->end = end;
//             if (lst_a->next)
// 			    return (lst_a->next->pos);
//             else
//             {
//                  return (lst_a->pos);
//             }
            
// 		}
//         i  = lst_a->pos;
// 		lst_a = lst_a->prev;
     
// 	}
//     lst->end = end;
// 	return (i);
// }

// void	ft_exec(t_init **lst_a, t_init **lst_b, char *str)
// {
// 	ft_putendl_fd(str, 1);
//     (void)lst_a;
//     (void)lst_b;
// 	ft_checker(str, lst_a, lst_b);
// 	//ft_strdel(&str);
// }
int     ft_nbrlen(int x, int a)
{
        int i;
        int j;
        char *str_x;
        char *str_a;

        str_x = ft_itoa(x);
        str_a = ft_itoa(a);
        i  = ft_strlen(str_x);
        j  = ft_strlen(str_a);
        if (i != j)
        {
                 free(str_a);
                 free(str_x);
                 return(1);
        }               
        if (i == 1 && j == 1)
        {
                 free(str_a);
                free(str_x);
                return (0);
        }
       if (ft_strncmp(str_a, str_x, j -1) == 0) 
       {
                free(str_a);
                free(str_x);        
                return (0);
       }
        return (1);
}


void    ft_rrr(t_init **lst_a, t_init **lst_b)
{
         if (( *lst_b != NULL && (*lst_b)->next != NULL))
                return ;
         if ((ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos) == 0 && ((*lst_a)->pos == (*lst_a)->end->pos + 1 || (*lst_a)->pos == (*lst_a)->end->pos - 1)) && 
         (ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos) == 0 && ((*lst_a)->pos == (*lst_a)->end->pos + 1 || (*lst_a)->pos == (*lst_a)->end->pos - 1))) 
          ft_exec(lst_a, lst_b, "rrr");


}
void    ft_ss(t_init **lst_a, t_init **lst_b)
{
         if (( *lst_b != NULL && (*lst_b)->next != NULL) && ( *lst_a != NULL && (*lst_a)->next != NULL))
                return ;
        if (ft_nbrlen((*lst_a)->pos , (*lst_a)->next->pos) == 0 &&
         ft_nbrlen((*lst_a)->pos , (*lst_b)->next->pos) == 0 && (*lst_a)->pos < (*lst_a)->next->pos  && (*lst_b)->pos < (*lst_b)->next->pos + 1)
                ft_exec(lst_a, lst_b, "ss");
        

}

void             ft_rra(t_init **lst_a, t_init **lst_b)
{
         if (( *lst_a != NULL && (*lst_a)->next != NULL))
                return ;
        if (ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos == 0) && (*lst_a)->pos > (*lst_a)->end->pos)
        {
                if ((*lst_b)->pos > (*lst_a)->end->pos && (*lst_a)->pos > (*lst_b)->pos)
                        return ;
                ft_exec(lst_a, lst_b, "rra");

        }
                

}

void             ft_ra(t_init **lst_a, t_init **lst_b)
{
         if (( *lst_a != NULL && (*lst_a)->next != NULL))
                return ;
        if (ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos == 0) && (*lst_a)->pos == (*lst_a)->end->pos + 1)
        {
                // if ((*lst_b)->pos > (*lst_a)->end->pos && (*lst_a)->pos > (*lst_b)->pos)
                //         return ;
                ft_exec(lst_a, lst_b, "ra");

        }
}

void             ft_rrb(t_init **lst_a, t_init **lst_b)
{
         if (( *lst_a != NULL && (*lst_a)->next != NULL))
                return ;
        if (ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos == 0) && (*lst_a)->pos == (*lst_a)->end->pos + 1)
        {
                // if ((*lst_b)->pos > (*lst_a)->end->pos && (*lst_a)->pos > (*lst_b)->pos)
                //         return ;
                ft_exec(lst_a, lst_b, "rrb");
        }
}




void    ft_push_swap_a(t_init **lst_a, t_init **lst_b)
{
        
    	// if (( (*lst_b) != NULL && (*lst_b)->next != NULL  && ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos)) == 0)
        // {
        //         ft_putendl("jhjhsjgjsfj");
        //     ft_exec(lst_a, lst_b, "rr");
    
        // }
//       if (( *lst_b != NULL && (*lst_b)->next != NULL &&  ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos) == 0) &&
//      ft_nbrlen((*lst_b)->pos , (*lst_b)->end->pos) == 0 )
//             ft_exec(lst_a, lst_b, "rrr");
        ft_rrr(lst_a, lst_b);
//     if (( *lst_b != NULL && (*lst_b)->next != NULL &&  (*lst_a)->pos > (*lst_a)->next->pos) && ft_nbrlen((*lst_a)->pos , (*lst_a)->next->pos) == 0 &&
//          ft_nbrlen((*lst_a)->pos , (*lst_b)->next->pos) == 0)
//             ft_exec(lst_a, lst_b, "ss");
                ft_ss(lst_a, lst_b);
//     if (( *lst_a != NULL && (*lst_a)->next != NULL &&  ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos) == 0))
//             ft_exec(lst_a, lst_b, "rra");
        ft_rra(lst_a, lst_b);
        ft_ra(lst_a, lst_b);
//    if (( *lst_a != NULL && (*lst_a)->next != NULL && ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos) == 0))
//     {
//             ft_exec(lst_a, lst_b, "ra");
//     }
        if (( *lst_a != NULL && (*lst_a)->next != NULL &&  (*lst_a)->pos > (*lst_a)->next->pos && ft_nbrlen((*lst_a)->pos , (*lst_a)->next->pos) == 0))
            ft_exec(lst_a, lst_b, "sa");
        if (( *lst_b != NULL && (*lst_b)->next != NULL && ft_nbrlen((*lst_b)->pos , (*lst_b)->end->pos) == 0))
            ft_exec(lst_a, lst_b, "rrb");
        if (( *lst_b != NULL && (*lst_b)->next != NULL && 
     ft_nbrlen((*lst_a)->pos , (*lst_b)->next->pos) == 0))
            ft_exec(lst_a, lst_b, "sb");
    
//        if (( *lst_b != NULL && (*lst_b)->next != NULL &&
//        ft_nbrlen((*lst_b)->pos , (*lst_b)->end->pos) == 0))
//        {
//             ft_exec(lst_a, lst_b, "rb");
//       }
     if ( *lst_b != NULL &&  (ft_nbrlen((*lst_a)->pos , (*lst_b)->pos) == 0 ||
     ft_nbrlen((*lst_b)->pos , (*lst_a)->next->pos) == 0 || ft_nbrlen((*lst_b)->pos , (*lst_a)->end->pos) == 0))
        ft_exec(lst_a, lst_b, "pa");
     
     if ( *lst_a != NULL && (*lst_a)->next != NULL && ft_nbrlen((*lst_a)->pos , (*lst_a)->next->pos) &&
     ft_nbrlen((*lst_a)->pos , (*lst_a)->end->pos))
     {
        ft_exec(lst_a, lst_b, "pb");
       
     } 
}

// void    ft_push_swap_b(t_init **lst_a, t_init **lst_b,int pvot)
// {
  
//     if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->pos< pvot) &&
//         (*lst_a)->pos > (*lst_a)->end->pos)
//             ft_exec(lst_a, lst_b, "rr");
//      else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->pos > pvot) &&
//         (*lst_a)->pos > (*lst_a)->end->pos )
//             ft_exec(lst_a, lst_b, "rrr");
//      else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->pos > (*lst_a)->next->pos) &&
//         (*lst_b)->pos< (*lst_b)->next->pos)
//             ft_exec(lst_a, lst_b, "ss");
  
//      else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->pos > pvot))
//             ft_exec(lst_a, lst_b, "rrb");   
//        else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->end->pos < (*lst_a)->pos ))
//             ft_exec(lst_a, lst_b, "rra");   
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->pos< (*lst_b)->next->pos))
//             ft_exec(lst_a, lst_b, "sb");
//     else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->pos > (*lst_a)->next->pos))
//             ft_exec(lst_a, lst_b, "sa");   
//    else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->pos< pvot))
//     {
//             ft_exec(lst_a, lst_b, "rb");
//     }
//     else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->pos > (*lst_a)->end->pos))
//     {
//             ft_exec(lst_a, lst_b, "ra");
//            ///ft_push_swap_a(lst_a, lst_b, pvot, 0);
//     }
//     else if ( *lst_b != NULL &&  (*lst_b)->pos>= pvot)
//         ft_exec(lst_a, lst_b, "pa");
//    // ft_push_swap_a(lst_a, lst_b, pvot);

// }







































// void    ft_push_swap_b(t_init **lst_a, t_init **lst_b, int pvot)
// {
//     if ( *lst_b != NULL && (*lst_b)->pos< pvot)
//         ft_exec(lst_a, lst_b, "pa");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->end->pos < pvot) &&
//         (*lst_b)->pos> (*lst_b)->end->pos)
//             ft_exec(lst_a, lst_b, "rr");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->end->pos < pvot) &&
//         (*lst_b)->pos> (*lst_b)->end->pos)
//             ft_exec(lst_a, lst_b, "rrr");
//     else if (((*lst_a)->pos > (*lst_a)->next->pos))
//             ft_exec(lst_a, lst_b, "sa");
//     else if (( *lst_a != NULL && (*lst_a)->next != NULL && (*lst_a)->pos > pvot))
//             ft_exec(lst_a, lst_b, "ra");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_a)->pos > (*lst_a)->next->pos) &&
//         (*lst_b)->pos< (*lst_b)->next->pos)
//             ft_exec(lst_a, lst_b, "ss");
//     else if (( *lst_b != NULL && (*lst_b)->next != NULL && (*lst_b)->pos< (*lst_b)->next->pos))
//             ft_exec(lst_a, lst_b, "sb");
//     //ft_push_swap_b(lst_a, lst_b, pvot);

// }

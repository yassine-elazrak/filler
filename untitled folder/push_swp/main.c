/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 16:25:55 by yelazrak          #+#    #+#             */
/*   Updated: 2019/09/18 09:47:00 by yelazrak         ###   ########.fr       */
/*i                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>



int 	ft_is_sort_envers(int *tab, int s_t, t_init *lst)
{
    int i;
    t_init *lst_a;
    t_init *end;

    lst_a = lst->end;
    end = lst->end;
   i  = lst_a->data;
   s_t = -1;
	while (lst_a)
	{ 
		   ++s_t;
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

// void	ft_exec(t_init **lst_a, t_init **lst_b, char *str)
// {
// 	ft_putendl_fd(str, 1);
// 	ft_checker(str, lst_a, lst_b);
// 	ft_strdel(&str);
// }


// int 	ft_is(int *tab, int s_t, t_init *lst_a)
// {
//     int i;

//    i  = lst_a->end->data;
// 	while (lst_a->end->prev)
// 	{
         
// 		   --s_t;
// 		if (lst_a->end->data != tab[s_t])
// 		{
// 			return (0);
// 		}
//         i  = lst_a->end->data;
// 		lst_a->end = lst_a->end->prev;
     
// 	}
// 	return (1);
// }


// int		ft_sort_b(int *tab, t_init **lst_a, t_init **lst_b, t_init **pvot_b)
// {
// 		t_init *tmp;
// 		int pvot;
// 		int pvot_bb;
// 		int	s_r;
// 		static int	s_t;



// 		tmp =  NULL;
// 		if ((*pvot_b)->next)
// 		{
// 			 pvot = ft_get_pvot(tab, (*pvot_b)->data, (*pvot_b)->next->data, s_t);
// 				tmp = (*pvot_b);
// 			//pvot =  (*pvot_b)->next->data;
// 			(*pvot_b) = (*pvot_b)->next;
// 			////pvot = ft_get_pvot(tab, (*pvot_b)->data, tmp->data , s_t);
// 			//if ((*pvot_b)->next)
// 			///	pvot = ft_get_pvot(tab, (*pvot_b)->next->data, pvot , s_t);
// 			//printf("pvot == [%d] \n", pvot);
// 			// if ((*pvot_b)->next->next != NULL)
// 			 	//pvot = ft_get_pvot(tab, (*pvot_b)->next->next->data, pvot, s_t);
				
// 				free(tmp);
// 		}
// 		else
// 		{
// 			pvot = (*pvot_b)->data;
// 		 }
// 			while(pvot_max(*lst_b, (*pvot_b)->data, pvot))
// 			{

// 				if (*lst_b == NULL)
// 					return (0);
// 		// 		s_r = ft_is_sort_envers(tab, s_t, *lst_b);
// 		// 		 if ( s_r == (*lst_b)->data)
// 	  	// 		 {
// 		// 			  // ft_push_swap_b(lst_a, lst_b, pvot);
// 		//  /// printf("is sort = [|%d|] 		data = ][|%d|] \n ", s_r,(*lst_a)->data );
// 		//   	 	ft_new(pvot_b, (*lst_b)->data);
// 		//   // printf("\n\n ++++++++s_r === |%d|		data = |%d|\n\\n", s_r, (*lst_a)->data);
// 	   	// 		return (0);
// 	   	// 		}
// 				ft_push_swap_b(lst_a, lst_b, pvot);
// 			}
// 		return (0);
// }

int		ft_quick_swap(t_init **lst_a, t_init **lst_b, t_init **pvot_a, t_init **pvot_b)
{
	static int *tab;
	static int pvot;
	int pvot_bb;
	int	s_r;
		t_init *tmp = NULL;
	static int	s_t;


	

	 if (*lst_b == NULL)
	{
		s_t = (*lst_a)->size;
		tab = ft_new_and_sort(*lst_a, s_t);
	}
	s_r = ft_is_sort(tab, s_t, *lst_a);
	if (s_r == (*lst_a)->data && (*lst_b) == NULL)
	{
		return (0);
	}	
	else if (s_r == (*lst_a)->data)
	{
		 // tmp =  NULL;
		if ((*pvot_b)->next)
		{
			 pvot = ft_get_pvot(tab, (*pvot_b)->data, (*pvot_b)->next->data, s_t);
			 tmp = (*pvot_b);
			//pvot =  (*pvot_b)->next->data;
			(*pvot_b) = (*pvot_b)->next;
			// pvot = ft_get_pvot(tab, (*pvot_b)->data, tmp->data , s_t);
			// if ((*pvot_b)->next)
			 	pvot = ft_get_pvot(tab, (*pvot_b)->data, pvot , s_t);
			//printf("pvot == [%d] \n", pvot);
			// if ((*pvot_b)->next->next != NULL)
			 	//pvot = ft_get_pvot(tab, (*pvot_b)->next->next->data, pvot, s_t);
				
				free(tmp);
		}
		else
		{
			pvot = (*pvot_b)->data;
		 }
			while(pvot_max(*lst_b, (*pvot_b)->data, pvot))
			{

				if (*lst_b == NULL)
					return (0);
		// 		s_r = ft_is_sort_envers(tab, s_t, *lst_b);
		// 		 if ( s_r == (*lst_b)->data)
	  	// 		 {
		// 			  // ft_push_swap_b(lst_a, lst_b, pvot);
		//  /// printf("is sort = [|%d|] 		data = ][|%d|] \n ", s_r,(*lst_a)->data );
		//   	 	ft_new(pvot_b, (*lst_b)->data);
		//   // printf("\n\n ++++++++s_r === |%d|		data = |%d|\n\\n", s_r, (*lst_a)->data);
	   	// 		return (0);
	   	// 		}
				ft_push_swap_b(lst_a, lst_b, pvot);
			}
		return (0);
	}
	//if (pvot < tab[s_t - 1] - 10)
	{
		pvot = ft_get_pvot(tab, (*pvot_b)->data, (*pvot_a)->data, s_t);
		//pvot = ft_get_pvot(tab, (*pvot_b)->data, pvot, s_t);
		//pvot = ft_get_pvot(tab, (*pvot_b)->data, pvot, s_t);
			//pvot = ft_get_pvot(tab, (*pvot_b)->data, pvot, s_t);
	///pvot = ft_get_pvot(tab, (*pvot_a)->data, pvot, s_t);
	//pvot = ft_get_pvot(tab, (*pvot_a)->data, pvot, s_t);			
	if (pvot != (*pvot_b)->data)
	{
	 	ft_new(pvot_b, pvot);
	} 
	// else
	// {
		
	// 	ft_push_swap_a(lst_a, lst_b, tab[s_t -1], pvot_bb);
	// 	//ft_push_swap_a(lst_a, lst_b, (*pvot_b)->next->data, pvot_bb);
	
	// }
	
	//printf("\npvot = [%d]\n", pvot);
	 //pvot_bb = ft_get_pvot(tab, (*pvot_b)->data, pvot, s_t);

	while(pvot_min(*lst_a, (*pvot_a)->data,  pvot))
	{
		
		s_r = ft_is_sort(tab, s_t, *lst_a);
	   if ( s_r == (*lst_a)->data)
	   {
		 /// printf("is sort = [|%d|] 		data = ][|%d|] \n ", s_r,(*lst_a)->data );
		   ft_new(pvot_a, (*lst_a)->data);
		 
		  // printf("\n\n ++++++++s_r === |%d|		data = |%d|\n\\n", s_r, (*lst_a)->data);
	   			return (0);
	   }
		
		ft_push_swap_a(lst_a, lst_b, pvot, pvot_bb);
	}
	return (0);
}
}

void	ft_print_tab(int *tab, int s)
{
	int i;

	i = 0;
	while(i < s )
	{
		printf("|%d|\n", tab[i]);
		i++;
	}
}


void		ft_mangement_sort(t_init **lst_a, t_init **lst_b)
{
	t_init 	*pvot_a;
	t_init	*pvot_b;
	int *tab;
	int s_t;
	int r_s;
	(void)lst_b;

	pvot_a = NULL;
	pvot_b = NULL;
	s_t = (*lst_a)->size;
	tab = ft_new_and_sort(*lst_a, s_t);//ft_print_tab(tab, s_t);
	//printf("a= %d\n b = %d\n",tab[s_t - 1], tab[0]);
	
	ft_new(&pvot_a, tab[s_t - 1]);
	ft_new(&pvot_b, tab[0]);

	int i;

	i = 0;
		while (i < 2000)
		{
			i++;
			ft_quick_swap(lst_a, lst_b, &pvot_a, &pvot_b);
		}
		
		
			ft_print(*lst_a,"list_a");
		 ft_print(*lst_b, "lst_b");

	
}

int main(int argc, char **argv)
{
	t_init	*lst_a;
	t_init  *lst_b;

	int i;

	lst_b = NULL;
	lst_a = NULL;
	// lst_a->size = 0;
	// lst_b->size = 0;
	if (argc == 1)
		return (0);
	i = argc ; //ft_putendl("hdjkdgfgdfkjgdjksfdj\n");
	ft_putendl(argv[1]);
	while (--i > 0)
		ft_new(&lst_a,atoi(argv[i]));	

	//ft_print(lst_a,"list_a");
	ft_mangement_sort(&lst_a, &lst_b);
	return 0;
}




		
		
		
		
		
		
		
		














































































	
		
		
		
		/*
quicksort(int n)
    if n == 1 return
    int top_half_len = 0
    choose a median //it's up to you to determine the best way to do this
    for 0 to n {    //filter all values above the median into list 2
        if (value > median) {
            push list 1 top to list 2 //list 2 stores the larger half
            top_half_len++
        }
        rotate list 1 forward
    }

    //reverse the list back to original position
    rotate list 1 backward (n - top_half_len) times

    //push larger half onto smaller half
    push list 2 top to list 1 top_half_len times

    //recursively call this on the larger half
    quicksort(top_half_len)

    //rotate smaller half to front
    rotate list 1 forward top_half_len times

    //recursively call this on smaller half
    quicksort(n - top_half_len) 

    //reverse list back to original position
    rotate list 1 backward top_half_len times*/

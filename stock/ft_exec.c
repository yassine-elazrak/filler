/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 10:00:20 by yelazrak          #+#    #+#             */
/*   Updated: 2019/09/29 18:32:27 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int 	pvot_max(t_init *lst, int pos, int pvot)
{
	(void)pos;
	while (lst)
	{
		if (lst->data > pvot)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int		 pvot_min(t_init *lst_a,int pos, int pvot)
{
	(void)pos;
	t_init *lst;
	lst = NULL;

	lst = lst_a;
	///lst->data != pos &&
	while( lst)
	{
		if (lst->data < pvot)
			return (1);
		lst = lst->next;
	}
	return (0);
}

int		pvot_get_min(t_init *lst, int valuer, int pvot)
{
	(void)valuer;
	//lst->data != valuer &&
	while ( lst)
	{
		if (lst->data <= pvot)
			return (pvot);
		lst = lst->next;
	}
	return (pvot);
}
 
static void ft_quicksort(int list[],int m,int n)
{
    int key;
	int i;
	int j;
    if( m < n)
    {
      
        key = list[m];
        i = m+1;
        j = n;
        while(i <= j)
        {
            while((i <= n) && (list[i] <= key))
                i++;
            while((j >= m) && (list[j] > key))
                j--;
            if( i < j)
                ft_swap(&list[i],&list[j]);
        }
        ft_swap(&list[m],&list[j]);
        ft_quicksort(list,m,j-1);
        ft_quicksort(list,j+1,n);
    }
}


int			*ft_new_and_sort(t_init *lst_a, int s_t)
{
	int *tab;
	int i;

	i = 0;
	if (!(tab = (int *)malloc(sizeof(int) * (s_t))))
	   	return (NULL);
	while (i < s_t)
	{
		
		tab[i] = lst_a->data;
		i++;
		lst_a = lst_a->next;
	}
   ft_quicksort(tab, 0, s_t - 1);
	return (tab);
}

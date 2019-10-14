/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_instruction.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 16:17:29 by yelazrak          #+#    #+#             */
/*   Updated: 2019/09/30 18:49:57 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void		ft_print(t_init *tmp, char *str)
{
	ft_putendl(str);
	if (tmp  == NULL)
		return;
	while (tmp)
	{
		printf("next == %d \n",tmp->data);
		tmp = tmp->next;
	}
		printf("\n---------------------\n");
}

void	ft_new(t_init **lst, int data)
{
	t_init *new;

	new = NULL;
	if (*lst == NULL)
	{
		if (!(*lst = (t_init *)malloc(sizeof(t_init))))
				return ;
		(*lst)->data = data;
		(*lst)->next = NULL;
		(*lst)->prev = NULL;
		(*lst)->size = 1;
		(*lst)->end = (*lst);
		return ;
	}
	if (!(new = (t_init *)malloc(sizeof(t_init))))
			return ;
	new->next = NULL;
	new->data = data;
	new->size = (*lst)->size + 1;
	(*lst)->prev = new;
	new->end = (*lst)->end;
	new->next = (*lst);
	(*lst) = new;
}

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp  = *a;
	*a   = *b;
	*b   =  tmp;
}

void	ft_push(t_init **lst, t_init **list)
{
	t_init *tmp;

	if(!(*lst))
		return ;
	tmp =  *lst; //printf("lst val= [%d]		end value [%d]\n\n",(*lst)->data, (*lst)->end->data);
	//printf("ss = [|%d|]\n", (*lst)->end->data);
	(*lst) = (*lst)->next;
	if ((*lst))
	{
		(*lst)->end = tmp->end;
		(*lst)->prev = NULL;
		(*lst)->size -= 1;
		
	}
	else
	{
		(*lst)->end = NULL;
		(*lst)->prev = NULL;
		(*lst)->next = NULL;
	}
	
	if (*list == NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		tmp->size += 1;
		tmp->end = tmp;
	}
	else
	{
		(*list)->prev = tmp;
		tmp->end = (*list)->end;
		tmp->prev = NULL;
		tmp->size += 1;
		tmp->next = *list;
	}	
	
	*list = tmp;
	//printf("end= %d\n",(*list)->end->data);
}

void	ft_rotate(t_init **lst_start, t_init **lst_end)
{
	t_init *tmp;
	
	if(!(*lst_start))
		return ;
	tmp = (*lst_start);
	(*lst_start) = (*lst_start)->next;
	(*lst_start)->end = tmp;

	
	tmp->next = NULL;
	tmp->prev = (*lst_end);
	(*lst_end)->next = tmp;
//	printf("end= %d\n",(*lst_start)->next->data);
}

void	ft_reverse_rotate(t_init **lst_start, t_init **lst_end)
{
	t_init *tmp;

	if(!(*lst_start))
		return ;
	tmp = (*lst_end);
	(*lst_end) = (*lst_end)->prev;	
	(*lst_end)->next = NULL;
	tmp->end =(*lst_end);
	 tmp->prev = NULL;
	  tmp->next = NULL;
	(*lst_start)->prev = tmp;
	tmp->next = (*lst_start);
	(*lst_start) = tmp;

}
	





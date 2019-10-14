/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:30:04 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/03 09:55:39 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
	if (ft_strcmp(str, "sb") == 0)
		ft_swap(&(*lst_b)->data, &(*lst_b)->next->data);
	if (ft_strcmp(str, "ss") == 0)
	{
		ft_swap(&(*lst_a)->data, &(*lst_a)->next->data);
		ft_swap(&(*lst_b)->data, &(*lst_b)->next->data);
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

	// ft_print(*lst_a,"list_a");
	// ft_print(*lst_b, "lst_b");
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
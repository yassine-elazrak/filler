/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/05 15:02:08 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/01 11:21:04 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include "libft/libft.h"


typedef struct			s_init
{
	int					data;
	int					size;
	struct s_init 		*next;
	struct s_init		*end;
	struct s_init		*prev;
}						t_init;


void					ft_checker(char *str, t_init **lst_a, t_init **lst_b);
void					ft_lst_new(t_init **lst, int data);
void					ft_new(t_init **lst, int data);
void					ft_swap(int *a, int *b);
void					ft_push(t_init **lst, t_init **list);
void					ft_reverse_rotate(t_init **lst_start, t_init **lst_end);
void					ft_rotate(t_init **lst_start, t_init **lst_end);
void					ft_print(t_init *tmp, char *str);


int						ft_is_sort(int *tab, int s_t, t_init *lst_a);
int						ft_get_pvot(int *tab, int a, int b, int s_t);
int						pvot_max(t_init *lst, int pos, int pvot);
int						pvot_min(t_init *lst,int pos, int pvot);
int						pvot_get_min(t_init *lst, int valuer, int pvot);
int						*ft_new_and_sort(t_init *lst_a, int s_t);

void    				ft_push_swap_b(t_init **lst_a, t_init **lst_b, int pvot);
void    				ft_push_swap_a(t_init **lst_a, t_init **lst_b, int pvot, int b);
void					ft_exec(t_init **lst_a, t_init **lst_b, char *str);


void					ft_print_tab(int *tab, int s);

void 					ft_push_swap_aaaa(t_init **lst_a, t_init **lst_b,int pvot, int pvot_b);












#endif

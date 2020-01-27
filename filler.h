/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 17:16:27 by yelazrak          #+#    #+#             */
/*   Updated: 2020/01/27 17:38:12 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "./libft/libft.h"
# include <stdio.h>

typedef struct		s_point
{
	int				x;
	int				y;
	int				z;
	struct s_point	*next;
}					t_point;

typedef struct		s_filler
{
	int				**map;
	int				x_p;
	int				y_p;
	int				x_t;
	int				y_t;
	int				s_cor;
	int				s_cor_tmp;
	int				my_index;
	int				yo_index;
	t_point			*lst;
}					t_filler;

int					ft_read_(t_filler *filler);
void				ft_flood__(t_filler *filler);
void				ft_get_score___of_mp_(t_filler *filler);
void				ft_get_size_piece_(char *str, t_filler *filler);
void				ft_free_mp_(t_filler *filler);
void				ft_free_piece_(t_filler *filler);
void				printf_char__(t_filler *filler);
void				printf_int__(t_filler *filler);

#endif

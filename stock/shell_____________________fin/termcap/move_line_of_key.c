/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_line_of_key.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 18:53:36 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/27 19:13:43 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void		ft_move_cursor_right(t_init *init)
{
	if(init->s_cursor < init->s_l)
	{
		init->s_cursor++;
		tputs(tgetstr("nd", NULL), 0, my_putchar);
	}				
}

void		ft_move_cursor_left(t_init *init)
{
	if(init->s_cursor > 14)
	{
		init->s_cursor--;
		tputs(tgetstr("le", NULL), 0, my_putchar);
	}				
}
void		ft_move_down(t_init *init)
{
	int i;
	int line;
	int  pos;

	i = tgetnum("co");
	pos = (init->s_cursor - 4) / i;
	line = init->s_l / i;
	if (init->s_l % i != 0)
		line++;
	if ((init->s_cursor - 4) % i != 0)
		pos++;

 	if ( pos <= line  && ((init->s_cursor - 4) % i) == (init->s_l - 4) % i)
	 {
		ft_putstr_fd(("\033[1B"),1);
		//tputs((tgetstr("do", NULL)),0,my_putchar);
		init->s_cursor += i;
		if (init->s_cursor > init->s_l )
			init->s_cursor = init->s_l ;
	}

}
void		ft_move_up(t_init *init)
{
	int i;
	int line;
	int  pos;

	i = tgetnum("co");
	pos = (init->s_cursor - 4) / i;
	line = init->s_l / i;
	if (init->s_l % i != 0)
		line++;
	if ((init->s_cursor - 4) % i != 0)
		pos++;
	//printf("pos = %d   line= %d  sl= %d   i = %d  ini->s_cursor= %d \n",pos, line, init->s_l, i, init->s_cursor);
	if  (pos >= 1 )
	{
		ft_putstr_fd(("\033[1A"),1);
		init->s_cursor -= i;
		if (init->s_cursor < 13 )
			init->s_cursor = 14;
	}
	
}

int ft_string_cmd(int flg,t_init *init)
{

	if (flg == HOME)
	{
		while(init->s_cursor >  14  && init->out_put[init->s_cursor - 1] != '\n')
			ft_move_cursor_left(init);
	}
	else if (flg == END)
	{
		while(init->s_cursor < init->s_l && init->out_put[init->s_cursor + 1] != '\n')
			ft_move_cursor_right(init);
	}
	if (flg == MOT_LEFT)
	{
		if(init->out_put[init->s_cursor ] == ' ')
			ft_move_cursor_left(init);
		while(init->s_cursor >  14  && init->out_put[init->s_cursor] != ' ')
			ft_move_cursor_left(init);
	}
	else if (flg == MOT_RIGHT)
	{
		if(init->out_put[init->s_cursor ] == ' ')
			ft_move_cursor_right(init);

		while(init->s_cursor < init->s_l && init->out_put[init->s_cursor ] != ' ')
			ft_move_cursor_right(init);
	}
	
	else if (flg == LINE_UP )
	{
		ft_move_up(init);
	}
				
	else if (flg == LINE_DOWN )
	{
		ft_move_up(init);
	}
				
	else
		return (0);
	return (1);
}



/*
void	ft_copy_of_line(char **line,t_init *init,int start,int size)
{
	char *t_line;

	t_line = *line;
	init->tmp = ft_strsub(t_line,start,size);
}

void	ft_copy_and_delete(char **line,t_init *init,int start,int size)
{
	char *t_line;
	char str;

	t_line = *line;
	ft_copy_of_line(line,init,start,size);
	str = ft_strsub(t_line,0,init->s_l - start);
	*line = ft_strjoin(str,&t_line[start + size]);
	free(str);
	free(t_line);
}

void	ft_coller_of_line(char **line,t_init *init,int position)
{
	char *t_line;
	char  *tmp;
	char str;

	t_line = *line;
	str = ft_strsub(t_line,0,init->s_l - position);
	tmp = ft_strjoin(str,init->tmp);
	*line = ft_strjoin(tmp,&t_line[position]);
	free(tmp);
	free(str);
	free(t_line);
}
*/

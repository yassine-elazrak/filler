/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_corsor_of_line.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:10:42 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/27 15:04:49 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"

int ft_cat_of_line(char **out_put,char *str,int *cursor)
{
	char *line;
	char *temp;
	char t_line;

	line = *out_put;
	if (line == NULL)
		line = ft_strnew(0);
	temp = ft_strsub(line,0,*cursor);
	t_line = ft_strjoin(temp,str);
	free(temp);
    *out_put = ft_strjoin(t_line,&line[*cursor]);
	free(t_line);
	free(line);
	*cursor += ft_strlen(str);
	return (ft_strlen(line));
}

void	goto_x_y(int y,int x)
{
	ft_putstr("\033["); 
	ft_putnbr(x);	
	ft_putstr(";"); 
	ft_putnbr(y); 
	ft_putstr("H");
}

int		my_putchar(int c)
{
	ft_putchar_fd(2,c);
	return (0);
}


void	ft_put_cursor(char *line,int i)
{
	char *cmd;

	cmd = getstr("cd",NULL);
	tputs(cmd,1,my_putchar);
	goto_x_y(0,i);
	ft_putstr_fd(1,line);
}


int		key_4_of_cursor(char *str,int *cursor,int s_l)
{
	if (str[0] == 27)
	{
		if (str[1] == 91)
		{		
			if (str[2] == 65)
				return (1);			
			if (str[2] == 67)
			{
				if (s_l > *cursor)
				{
					(*i)++;					
					ft_put_cursor(line,*cursor);	
				}
				return (1)			
			}
			if (str[2] == 66)
				return (1);	
			if (str[2] == 68)
			{
				if (*cursor > 0)
				{
					(*cursor)--;
					ft_put_cursor(line,*cursor);
				}
				return (1);
			}
		}
	}
	return (0);
}

void    	del_char_of_line(char **line,int *i,int *s_l)
{
	char *t_line;
	char *t_2_line;

	t_line = *line;
	if (s_l == 0)
		return;
	else 
	{
		t_2_line = ft_strsub(t_line,0,*i);
		*line = ft_strjoin(t_2_line,&t_line[*i + 1]);
		*s_l--;
		*i--;
		ft_put_cursor(*line,*i);
		free(t_2_line);
		free(t_line);
	}
}



void		move_cursor_and_mangemant_fonction(char *str)
{
	int cursor;
	static char *out_put;
	static int s_l;

	if (key_4_cursor(str,&cursor,s_l))
		return ;
	else if (str[0])
	{
		del_char_of_line(&cursor,&cursor,&s_l)
			return ;
	}
	else 
	{
		ft_cat_of_line(str,&cursor);
	}
}

			



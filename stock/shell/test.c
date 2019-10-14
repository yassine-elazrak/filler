/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 06:21:50 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/27 19:10:05 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <term.h>
#include <termios.h>
#include <unistd.h>
#include <curses.h>
#include <curses.h>
#include <term.h>
#include <term.h>
#include<signal.h> 
#include <unistd.h> 
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <sys/stat.h>
#include <string.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
#include<stdio.h>

#define cursorforward(x) printf("\033[%dC", (x))
#define cursorbackward(x) printf("\033[%dD", (x))



//#define cclear() ft_putstr("\033[K");
#define cclear()	ft_putstr("\033[H\033[J")
void gotoxy(x,y)  {ft_putstr("\033["); ft_putnbr(x);	ft_putstr(";"); ft_putnbr(y); ft_putstr("H");}

int my_putchar(int c) { return fputc(c, stderr); }
void	ft_curser(int i)
{
	char *cmstr;
	cmstr = tgetstr("cm", NULL);
	tputs(tgoto(cmstr, 0, 0), 1, my_putchar);

}

void	ft_move(int i, char *d)
{
	ft_memmove(d + i,d + i +  1,4444);

}


void	ft_push(char *d, int i)
{
	int a;

	//cclear(); 
	// a = ft_readd();
	// char *cmstr;
	// cmstr = tgetstr("dc", NULL);
	// tputs(tgoto(cmstr, 0, i + a), 1, my_putchar);
	ft_putstr_fd(d,1);
	gotoxy(0,i + a);

}
void	ft_key_4(char *b,char *d,int *i,int j)
{
	ft_putchar('#');
	

	if (b[0] == 27)
	{
		if (b[1] == 91)
		{		
			if (b[2] == 65)
				return;			
			if (b[2] == 67)
			{
				if (j > *i)
				{
					(*i)++;					
					ft_push(d,*i);	
				}			
			}
			if (b[2] == 66)
				return;	
			if (b[2] == 68)
			{
				if (*i > 0)
				{
						(*i)--;
					ft_push(d,*i);
				}
			}
		}
	}
}
void	ft_enter(char *line,char **environ,char **ar)
{

	// char ***str;
	//  if (!(str = ft_separe(line)))
	// 		exit(1);
	// 		ft_bzero(line,ft_strlen(line));
	// 	ft_display(str,environ,ar);

}
void  ft_key(char *b,char **environ,char **ar)
{
	static int i;
	char *cmstr;
	int j;
	int a = 0;
	static char d[4444];

	j = ft_strlen(d);
	 if (b[0] == 27)
	 	ft_key_4(b,d,&i,j);
	else if (b[0] == 9)
		ft_putstr_fd("tab", 1);
	else if (b[0] == 10)
	{
		ft_enter(d,environ,ar);
		// ft_term(environ,ar);
		//  ft_bzero(d,4444);
		//  ft_bzero(b,4);
		//  cclear();

		return;

	}
		
	 else if (b[0] == 127 && j)
	{
		 cmstr = tgetstr("dc", NULL);
		 //tgoto(cmstr, 0, i + a)
		tputs(cmstr, 1, my_putchar);
		ft_move(i,d);
		 if (i == j && i > 0)
		 	i--;
		if (i >= 0)
			ft_push(d,i);
	}
	else
	{
		if (i == j)
			ft_strcat(d,b);
		i++;
		ft_push(d,i);
	}
}

void	ft_term(char **environ,char **ar)
{
	struct termios t;
	char b[4];

	
	// gotoxy(0,0);
  	tcgetattr(0, &t);
  	t.c_lflag &= ~ICANON;
  	t.c_lflag &= ~ECHO;
  	t.c_cc[VMIN] = 1;
  	t.c_cc[VTIME] = 0;
	bzero(b,4);
 	tcsetattr(0, TCSADRAIN, &t);
	//ft_read();
	while (read(0, b, 4))
    {
		ft_key(b,environ,ar) ;
		bzero(b,4);	
    }
}



int main (int argc, char **argv, char **envp) 
{
	char *line;
	char **ar;
	char **environ;
	
	(void)argc;
	(void)argv;
	cclear();
	ft_term(envp,argv);
	return (0);
}

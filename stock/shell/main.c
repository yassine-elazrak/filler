/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 07:14:36 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/06 08:31:38 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"
#define KEY_ESCAPE  0x001b

// static int kbesc(void)
// {
//     int c;

//     if (!kbhit()) return KEY_ESCAPE;
//     c = llgetch();
//     if (c == '[') {
//         switch (getch()) {
//             case 'A':
//                 c = KEY_UP;
//                 break;
//             case 'B':
//                 c = KEY_DOWN;
//                 break;
//             case 'C':
//                 c = KEY_LEFT;
//                 break;
//             case 'D':
//                 c = KEY_RIGHT;
//                 break;
//             default:
//                 c = 0;
//                 break;
//         }
//     } else {
//         c = 0;
//     }
//     if (c == 0) while (kbhit()) getch();
//     return c;
// }

// static int kbget(void)
// {
//     int c;

//     c = llgetch();
//     return (c == KEY_ESCAPE) ? kbesc() : c;
// }
int my_putchar(int c) { return fputc(c, stderr); }
void	ft_read()
{
	char cwd[1024];
	char *t;

	getcwd(cwd,1024);
	ft_putstr( "["); 
 	ft_putstr(ANSI_COLOR_BLUE);
		if ((t = ft_strstr(cwd,"/Users/yelazrak")) != NULL)
			{
				ft_putstr("~");
		  		ft_putstr(t + 16);
			}
			else
		  		ft_putstr(cwd);
		 ft_putstr(ANSI_COLOR_RESET);
		ft_putstr( "]"); 
}

// void    screen()
// {
//     char buf[1024];
//     char *str;

//     tgetent(buf, getenv("TERM"));
//     str = tgetstr("cl", NULL);
//     fputs(str, stdout);
// }

int main (int argc, char **argv, char **envp) 
{
	char *line;
	char **ar;
	char **environ;
	char ***str;
	int i;
	int c;
	unsigned char b;
	 char           *name_term;
  //char *line;
  struct termios term;
	
	(void)argc;
	(void)argv;
	i = 0;
	//bzero(b,4);
	if ((name_term = getenv("TERM")) == NULL)
     return (-1);
  		//tgetent(NULL, name_term);
     //tgetent(NULL, name_term);
	if (tcgetattr(0, &term) == -1)
      return (-1);
  	term.c_lflag &= ~(ICANON); // Met le terminal en mode canonique.
	term.c_lflag &= ~(ECHO); // les touches tapées ne s'inscriront plus dans le terminal
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;

	 tcsetattr(0, TCSADRAIN, &term);
	
	
	while(1)
	{
		
		ft_read();
	
		while (read(0,&b,1) > 0)
		{
			//c = kbget();
        	if (b == KEY_ENTER || b == KEY_ESCAPE || b == KEY_UP || b == KEY_DOWN) 
           		 ft_putstr("54546");
        
			write(1,&b,1);
		}

		//  get_next_line(0,&line);
		// 	ft_putstr_fd(line,1);
			free(line);
	}
}
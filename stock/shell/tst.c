 #include "shell.h"

// // User-defined Signal Handler 
// #include<stdio.h> 
// #include<signal.h> 
  
// // Handler for SIGINT, caused by 
// // Ctrl-C at KKKEYboard 
// void handle_sigint(int sig) 
// { 
//     printf("Caught signal %d\n", sig); 
// } 
  
// int main() 
// { 
//     signal(SIGINT, handle_sigint); 
//     while (1) ; 
//     return 0; 
// }
// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   ft_cmd.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/05/27 14:25:17 by yelazrak          #+#    #+#             */
// /*   Updated: 2019/06/01 02:55:15 by yelazrak         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "shell.h"

// extern char **environ;

// void	ft_env(char **envp)
// {
// 	int i;

// 	i = 0;
// 	while(envp[i])
// 		ft_putendl(envp[i++]);
// }

// t_lst *ft_alstnew(char *t)
// {
// 	t_lst *new;
// 	if (!(new = (t_lst*)malloc(sizeof(t_lst))))
// 		return (NULL);
// 	new->str = ft_strdup(t);
// }

// void	ft_allocation(t_lst **tmp, char *t)
// {
// 	t_lst *lst;

// 	lst = *tmp;
// 	if (*tmp)
// 	{
// 		while (lst->next)
// 			lst = lst->next;
// 		lst->next = ft_alstnew(t);
// 	}
// 	else
// 	{
// 		*tmp = ft_alstnew(t);
// 	}
// }

// void ft_copy(char ***env,char **environ)
// {
// 	char **p;
// 	int i;

// 	i = 0;
// 	while(environ[i])
// 		i++;
// 	p = (char **)malloc(sizeof(char *)*(i + 1));
// 	i = -1;
// 	while(environ[++i])
// 		p[i] = ft_strdup(environ[i]);
// 	p[i] = NULL;
// 	*env = p;

// }

// void	ft_setenv(char ***env,char *t)
// {
// 	char **p;
// 	char **environ;
// 	int i;

// 	i = 0;
// 	environ = *env;
// 	while(environ[i])
// 		i++;
// 	p = (char **)malloc(sizeof(char *)*(i + 2));
// 	i = -1;
// 	while(environ[++i])
// 		p[i] = ft_strdup(environ[i]);
// 	p[i++] = ft_strdup(t);
// 	p[i] = NULL;
	
// 	ft_tabfree(*env);
// 	*env = p;
//  	//ft_env(p);

// }

// void	ft_unsetenv(char ***env,char *t)
// {

// 	char **environ;
// 	char **p;
// 	int i;
// 	int j;
// 	int k;

// 	i = -1;
// 	j = 0;
// 	k = 0;
// 	environ = *env;
// 	while(environ[++i])
// 	{
// 		if (ft_strcmp(environ[i],t) == 0)
// 			j = i;
// 	}
// 	p = (char **)malloc(sizeof(char *)*i);
	
// 	printf("i = %d j = %d\n",i,j);
// 	i = 0;
// 	while(environ[i])
// 	{
// 		if(i != j)
// 		{
// 			p[k] = ft_strdup(environ[i]);
// 			k++;
// 		}
// 		i++;
// 	}
// 	p[k] = NULL;
// 	ft_tabfree(*env);
// 	env = &p;
// }

// void	ft_execut(char **ar,char **line, char **envp)
// {
// 	pid_t pid;
// 	char *t;
// 	int i = 0;

// 	pid = fork();
// 	if (pid == -1)
// 	{
// 		perror(NULL);
// 		exit(1);
// 	}
// 	else if (pid == 0)
// 	{	
// 		while(ar[i]) 
// 		{
// 			t = ft_stat(ar[i],line[0]);
// 			if (execve(ft_stat(ar[i],line[0]),line,envp) != -1)
// 			{
// 					free(t);
// 					break;
// 			}
// 			free(t);
// 			i++;
// 		}
// 	}
// 	else
// 	{
// 		wait(NULL);
// 	}

// }


// void	ft_cd(char *t)
// {
// 	char *p;

// 	if (ft_strcmp(t,"~") == 0)
// 	{
// 		p = ft_strdup("/Users/yelazrak");
// 	}
// 	else
// 	{
// 		p = ft_strdup(t);
// 	}
// 	if (chdir(p) == -1)
// 	{
// 		free(p);
// 		return ;
// 	}
// 	free(p);
		
// }

// void ft_flag(char ***k, char **t)
// {
//   char *l;
//   char **d;

//   if (!(d = (char **)malloc(sizeof(char *)* 7)))
//     return ;
//   if (!(l = ft_strnew(6)))
//     return ;
//   d[0] = ft_strdup("\\t");
//   d[1] = ft_strdup("\\a");
//   d[2] = ft_strdup("\\r");
//   d[3] = ft_strdup("\\v");
//   d[4] = ft_strdup("\\b");
//   d[5] = ft_strdup("\\n");
//   d[6] = NULL;
//   l[0] = '\t';
//   l[1] = '\a';
//   l[2] = '\r';
//   l[3] = '\v';
//   l[4] = '\b';
//   l[5] = '\n';
//   l[6] = '\0';
// 	*k = d;
// 	*t = l;
// }

// void  ft_c(char **t)
// {
//   int b;
//   int a;
//   int i ;
//   char *k;
//   char *p;
//   char **d = NULL;
//   char *l = NULL;
  
//   ft_flag(&d,&l);
//   p = *t;
//   i = 0;
//   while (d[i])
//   {
//       a = ft_strlen(p);
//       if((k = ft_strstr(p,d[i])))
//       {
//         b = ft_strlen(k);
//          p[a - b] = l[i];
//          ft_memmove(&p[a - b + 1],&p[a - b + 2] ,b);
//          p[a- 1] = '\0';
//       }
//       i++;
//   }
//             ft_putstr(p);
// }
 
// void path(char *t,char **environ)
// {
// 	int i;
// 	int l;
// 	char *p;

// 	i = 0;
// 	p  = NULL;
// 	p = ft_strrchr(t,'=');
// 	l = p - t;
// 	while (environ[i] )
// 	{
// 		if(ft_strncmp(environ[i],t,l) == 0)
// 			ft_putstr(environ[i + l]);
// 	}
// 	if (p)
// 		ft_putstr(p);
// }

// void	ft_verf(char *t)
// {
// 	int j;

// 	j = ft_strlen(t);
// 	if (t[0] == '"' || t[0] == '\'' || t[j - 1] == '"' || t[j - 1] == '\'')
// 	{
// 		if (t[0] != t[j - 1])
// 		{
// 			ft_putstr("you are forgot to close");
// 			ft_putendl(" ");
// 			exit(1);
// 		}
// 		else
// 		  {
// 			ft_memmove(t,t + 1,j);
// 			t[j-2] = '\0';
// 		  }			
// 	}
// }

// void	ft_echo(char **av,char **environ)
// {
// 	int i;
// 	int j;

// 	i = 1;
// 	j = 0;
// 	if (ft_strcmp(av[1],"-n") == 0)
// 	{
// 		i = 2;
// 		j = 1;
// 	}
// 	while(av[i])
// 	{
// 		ft_verf(av[i]);
// 		if(av[i][0] == '$')
// 			path(&av[i][0],environ);
// 		else
//       ft_c(&av[i]);
//     ft_putchar(' ');
// 		i++;
// 	}
// 	if (j == 0)
// 		ft_putchar('\n');
// }

// char ***ft_separe(char *line)
// {
//   char ***d;
//   char **t;
//   int i;
//   int j;

//   i = 0;
//   j = 0;
// if (ft_strstr(line,";;"))
// 	{
// 		ft_putendl("zsh: parse error near `;;'");
// 			return (NULL);
// 	}
//   while (line[j])
//   {
//     if (line[j] == ';')
//         i++;
//     j++;
//   }
//   if (!(d = (char ***)malloc(sizeof(char **) * (i + 1))))
//     return (0);
//   t = ft_strsplit(line,';');
//   i = 0;
//   j = 0;
//   while (t[i])
//   {
//       d[i] = ft_strsplit(t[i], ' ');
//       i++;
//   }
//   d[i] = NULL;
//   return (d);
// }

// int	ft_info(char *t)
// {
// 	struct stat ss;
// 	t = ft_stat(".",t);

// 	if (0 > lstat(t,&ss) )
// 		return (-1);
// 	if 	(S_ISDIR(ss.st_mode))
// 		return (1);
// 	else
// 		return (-1);
	
// }
// \033[l;cH

// Move the cursor to line l and column c.

// \033[nA

// Move the cursor up n lines.

// \033[nB

// Move the cursor down n lines.

// \033[nC

// Move the cursor forward n characters.

// \033[nD

// Move the cursor backward n characters.

// \033[2J

// Clear the screen and move the cursor to the upper-left corner (line 0, column 0).

// \033[K

// Clear from the cursor position to the end of the current line.

// \033[s

// Store the current cursor position. ...



#include <stdio.h>

// #define cclear() ft_putstr("\033[H\033[J")
// void gotoxy(x,y)  {ft_putstr("\033["); ft_putnbr(x);	ft_putstr(";"); ft_putnbr(y); ft_putstr("H");}
// //printf("%d;%dH", (x), (y))

// int main(void)
// {
//     int number;

//     cclear();
//     printf(
//         "Enter your number in the box below\n"
//         "+-----------------+\n"
//         "|                 |\n"
//         "+-----------------+\n"
//     );
//     gotoxy(9, 9);
//     scanf("%d", &number);
//     return 0;
// }
// {}
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <unistd.h>

#define cursorforward(x) printf("\033[%dC", (x))
#define cursorbackward(x) printf("\033[%dD", (x))

#define KKKKEY_ESCAPE  0x001b
#define KKKKEY_ENTER   0x000a
#define KKKKEY_UP      0x0105
#define KKKKEY_DOWN    0x0106
#define KKKKEY_LEFT    0x0107
#define KKKKEY_RIGHT   0x0108

static struct termios term, oterm;

static int gggetch();
static int kbhit(void);
static int kbesc(void);
static int kbget(void);

static int gggetch()
{  
    int c = 0;

    tcgetattr(0, &oterm);
    memcpy(&term, &oterm, sizeof(term));
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VMIN] = 1;
    term.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &term);
    c = getchar();
    tcsetattr(0, TCSANOW, &oterm);
    return c;
}

static int kbhit(void)
{
    int c = 0;

    tcgetattr(0, &oterm);
    memcpy(&term, &oterm, sizeof(term));
    term.c_lflag &= ~(ICANON | ECHO);
    term.c_cc[VMIN] = 0;
    term.c_cc[VTIME] = 1;
    tcsetattr(0, TCSANOW, &term);
    c = getchar();
    tcsetattr(0, TCSANOW, &oterm);
    if (c != -1) ungetc(c, stdin);
    return ((c != -1) ? 1 : 0);
}

static int kbesc(void)
{
    int c;

    if (!kbhit()) return KKKKEY_ESCAPE;
    c = gggetch();
    if (c == '[') {
        switch (gggetch()) {
            case 'A':
                c = KKKKEY_UP;
                break;
            case 'B':
                c = KKKKEY_DOWN;
                break;
            case 'C':
                c = KKKKEY_LEFT;
                break;
            case 'D':
                c = KKKKEY_RIGHT;
                break;
            default:
                c = 0;
                break;
        }
    } else {
        c = 0;
    }
    if (c == 0) while (kbhit()) gggetch();
    return c;
}

static int kbget(void)
{
    int c;

    c = gggetch();
    return (c == KKKKEY_ESCAPE) ? kbesc() : c;
}

int main(void)
{
    int c;

    while (1) {
        c = kbget();
        if (c == KKKKEY_ENTER || c == KKKKEY_ESCAPE || c == KKKKEY_UP || c == KKKKEY_DOWN) {
            break;
        } else
        if (c == KKKKEY_RIGHT) {
            cursorbackward(1);
        } else
        if (c == KKKKEY_LEFT) {
            cursorforward(1);
        } else {
            putchar(c);
        }
    }
    printf("\n");
    return 0;
}
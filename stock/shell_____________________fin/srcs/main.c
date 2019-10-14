/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:59:40 by yelazrak          #+#    #+#             */
/*   Updated: 2019/07/25 18:50:35 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../shell.h"

void				ft_init_terminal(struct termios *term)
{
	term->c_lflag &= ~ICANON;
	term->c_lflag &= ~ECHO;
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
}

void				ft_catsh(int sig)
{
	char			*str;

	(void)sig;
	ft_putchar('\n');
	ft_name(&str);
	ft_putstr_fd(str, 1);
}

int					main(int argc, char **argv, char **envp)
{
	struct termios	term;
	char			buffer[4];
	int				position;
	t_init			*init;
	t_envp			*env;

	env = NULL;
	(void)argv;
	(void)argc;
	if (!(init = (t_init *)malloc(sizeof(t_init))))
		return (0);
	tcgetattr(0, &term);
	ft_init_terminal(&term);
	tcsetattr(0, TCSADRAIN, &term);
	ft_putstr("\033[H\033[J");
	init->out_put = ft_strnew(0);
	signal(SIGINT, ft_catsh);
	ft_init_output(init);
	ft_copy(envp, &env);
	while ((position = read(0, buffer, 4)))
	{
		buffer[position] = '\0';
		ft_read(buffer, position, init, env);
	}
	return (0);
}

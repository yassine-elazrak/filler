/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 10:59:40 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/27 15:07:12 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shell.h"








int main(int ac,char **av,char**envp)
{
	struct termios term;
	char buffer[4];
	int position;

	tcgetattr(0,&term);
	term.c_lflag &=~ CANON;
	term.c_lflag &=~ ECHO;
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(0,TCSADRAIN,&term);

	while ((position= read(0,buffer,4)))
	{
		buffer[position] = '\0';
		move_cursor_and_mangemant_fonction(buffer);
	}
	return (0);
}

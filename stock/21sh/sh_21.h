/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:38:34 by yelazrak          #+#    #+#             */
/*   Updated: 2019/06/24 17:11:55 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SH_21_H
# define SH_21_H

#include <fcntl.h>
#include<signal.h> 
#include <unistd.h> 
#include <unistd.h>
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <dirent.h>
#include <sys/stat.h>
#include <string.h>
# include "libft/libft.h"
# include "libft/get_next_line.h"
#include <stdio.h>
#define ANSI_COLOR_BLUE    "\x1b[35m"
#define ANSI_COLOR_RESET   "\x1b[0m"



typedef struct		s_lst
{
	char *data;
	struct s_lst *next;
}					t_lst;




#endif
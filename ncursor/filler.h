/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 17:29:36 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/13 14:49:23 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define  FILLER_H


#include <stdio.h>
#include "libft/libft.h"
#include <curses.h>
 #include <sys/ioctl.h>

# include <curses.h>
# include <locale.h>

# define COLOR_PINK "\033[1;35m"
# define COLOR_RESET "\033[0m"
# define DELAY 10000
# define SCALE_LEN 40
# define LBL_IND 15
# define GREEN_LEAF "\xF0\x9F\x8D\x80"
# define RED_LEAF "\xF0\x9F\x8D\x81"

# define WIDTH 1400
# define HEIGHT 1000



typedef struct      s_init
{
   WINDOW           *win;
    int               w;
    int                h;
    int                 i;
    int                 x0;
    int                 y0;

}                   t_init;



typedef struct      s_filler
{
  char              **map;
  int               y;
  int               x;
  char              *p1;
  char              *p2;

}                   t_filler;




void    ft_put_image(t_filler  *filler, t_init *init);
void    ft_init_00(t_init *init, t_filler *filler);
int     ft_read(t_filler *filler);
void    ft_print(t_filler *filler);
void		ft_print_plyer(t_filler *filler, t_init *init);



#endif




// /*
// ** -------------------------- External Headers ---------------------------------
// */

// # include <math.h>
// # include <fcntl.h>
// # include <errno.h>
// # include <time.h>
// # include <sys/time.h>

// /*
// ** -------------------------- Internal Libraries -------------------------------
// */

// # include "../libraries/fsdl/include/fsdl.h"
// # include "../libraries/libft/include/libft.h"

// /*
// ** -------------------------- Internal Frameworks ------------------------------
// */

// # include "../frameworks/SDL2.framework/headers/SDL.h"
// # include "../frameworks/SDL2_ttf.framework/headers/SDL_ttf.h"
// # include "../frameworks/SDL2_image.framework/headers/SDL_image.h"

// /*
// ** --------------------------- Internal Headers --------------------------------
// */

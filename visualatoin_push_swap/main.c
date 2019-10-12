/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/03 15:13:34 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/04 17:53:32 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push.h"

int main(int argc, char **argv)
{
    
    t_init init;

    init.quit = 0;
    init.rect.x = 500;
    init.rect.y = 0;
    init.rect.w = 1;
    init.rect.h = 800;
    init.lst = NULL;

    SDL_Init(SDL_INIT_EVERYTHING);//(SDL_INIT_VIDEO);

     init.win = SDL_CreateWindow("push_swap",SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        WIDTH,                               // width, in pixels
        HEIGHT, SDL_WINDOW_SHOWN);
         init.surf =  SDL_GetWindowSurface( init.win);
         SDL_FillRect( init.surf, NULL, SDL_MapRGB( init.surf->format, 5, 5, 0));
        SDL_FillRect( init.surf,&init.rect,SDL_MapRGB( init.surf->format, 255, 225,5));
       // SDL_BlitSurface(surf,&c,surf,NULL); 
        ft_remplissage(argc, argv, &init);

        SDL_UpdateWindowSurface( init.win);
        while ( init.quit == 0)
        {
            SDL_PollEvent(& init.event);
            if( init.event.type == SDL_QUIT || ( init.event.key.keysym.sym == SDLK_ESCAPE))
            {
                 init.quit = 1;
                break;
            }
        }
        // SDL_Delay(30000);
        SDL_FreeSurface( init.surf);
        SDL_DestroyWindow( init.win);
        SDL_Quit();
        return (0);

}

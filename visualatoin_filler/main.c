// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   main.c                                             :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2019/10/03 15:13:34 by yelazrak          #+#    #+#             */
// /*   Updated: 2019/10/08 12:02:13 by yelazrak         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

 #include "filler.h"


//⇒  gcc main.c -I /Users/yelazrak/brew/Cellar/sdl2/2.0.10/include   -L /Users/yelazrak/brew/Cellar/sdl2/2.0.10/lib  -l SDL2-2.0.0 -l SDL2_ttf libft/libft.a
//⇒  gcc ft_calcul.c main.c -I include -L /Users/yelazrak/brew/Cellar/sdl2/2.0.9_1/lib -l SDL2-2.0.0 libft/libft.a
///./filler_vm -f maps/map02 -p1 players/grati.filler -p2 players/superjeannot.filler |./a.out 2>d

//g++ test.cpp glad/glad.c -I/Library/Frameworks/SDL2.framework/Headers -F/Library/Frameworks -framework SDL2


void      ft_print_plyer(t_init *init)
{ 
    SDL_Rect rect; 
    SDL_Surface *missage = NULL;
    //char *text = "yassine";
     TTF_Font *font = NULL; 
     SDL_Color  textcolor = {255,255,255};



    TTF_Init();
 
  font = TTF_OpenFont("FreeSerif.ttf",30);
  missage = TTF_RenderText_Solid(font, "player 1", textcolor);
  rect.x = init->w / 4;
  rect.y = 20;
  SDL_BlitSurface(missage, NULL, init->surf,&rect);
   missage = TTF_RenderText_Solid(font, "yassine", textcolor);
  rect.x = init->w / 4;
  rect.y = 50;
  SDL_BlitSurface(missage, NULL, init->surf,&rect);
   missage = TTF_RenderText_Solid(font, "player 1", textcolor);
  rect.x = init->w / 4 * 2 ;
  rect.y = 20;
  SDL_BlitSurface(missage, NULL, init->surf,&rect);
   missage = TTF_RenderText_Solid(font, "azrak", textcolor);
  rect.x = init->w / 4 * 2;
  rect.y = 50;
  SDL_BlitSurface(missage, NULL, init->surf,&rect);
}

int main(int argc, char **argv)
{
    
    t_init init;
    t_filler filler;
    SDL_Rect  recit;

    filler.x = 400;
    filler.y = 300;
    init.quit  = 0;
  
     ft_read(&filler);
    ft_init_00(&init, &filler);
    SDL_Init(SDL_INIT_EVERYTHING);//(SDL_INIT_VIDEO);

     init.win = SDL_CreateWindow("filler",SDL_WINDOWPOS_UNDEFINED,           // initial x position
        SDL_WINDOWPOS_UNDEFINED,           // initial y position
        init.w,                               // width, in pixels
      init.h, SDL_WINDOW_SHOWN);
         init.surf =  SDL_GetWindowSurface( init.win);
         SDL_FillRect( init.surf, NULL, SDL_MapRGB( init.surf->format, 5, 5, 0));


           recit.h  = 150;
    recit.w = init.w -10 ;
    recit.x = 10;
    recit.y = 10;
       SDL_FillRect( init.surf,&recit,SDL_MapRGB( init.surf->format, 0, 191,255));

      ft_print_plyer(&init);
  
     // SDL_BlitSurface(surf,&c,surf,NULL); 
    
        ft_print(&filler);
        ft_put_image(&filler, &init);
        SDL_UpdateWindowSurface( init.win);
        while ( init.quit == 0)
        {
           ft_read(&filler);
            SDL_UpdateWindowSurface( init.win);
            ft_print(&filler);
          ft_put_image(&filler, &init);
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


// #include <stdlib.h>
// #include "filler.h"
// #include "SDL2/SDL.h"
// #include "SDL2/SDL_ttf.h"

// #define WINDOW_WIDTH 300
// #define WINDOW_HEIGHT (WINDOW_WIDTH)

// /*
// - x, y: upper left corner.
// - texture, rect: outputs.
// */
// void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
//         TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
//     int text_width;
//     int text_height;
//     SDL_Surface *surface;
//     SDL_Color textColor = {255, 255, 255, 0};

//     surface = TTF_RenderText_Solid(font, text, textColor);
//     *texture = SDL_CreateTextureFromSurface(renderer, surface);
//     text_width = surface->w;
//     text_height = surface->h;
//     SDL_FreeSurface(surface);
//     rect->x = x;
//     rect->y = y;
//     rect->w = text_width;
//     rect->h = text_height;
// }

// int main(int argc, char **argv) {
//     SDL_Event event;
//     SDL_Rect rect1, rect2;
//     SDL_Renderer *renderer;
//     SDL_Texture *texture1, *texture2;
//     SDL_Window *window;
//     char *font_path;
//     int quit;

//     if (argc == 1) {
//         font_path = "FreeSans.ttf";
//     } else if (argc == 2) {
//         font_path = argv[1];
//     } else {
//         fprintf(stderr, "error: too many arguments\n");
//         exit(EXIT_FAILURE);
//     }

//     /* Inint TTF. */
//     SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
//     SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
//     TTF_Init();
//     TTF_Font *font = TTF_OpenFont(font_path, 24);
//     if (font == NULL) {
//         fprintf(stderr, "error: font not found\n");
//         exit(EXIT_FAILURE);
//     }
//     get_text_and_rect(renderer, 0, 0, "hello", font, &texture1, &rect1);
//     get_text_and_rect(renderer, 0, rect1.y + rect1.h, "world", font, &texture2, &rect2);

//     quit = 0;
//     while (!quit) {
//         while (SDL_PollEvent(&event) == 1) {
//             if (event.type == SDL_QUIT) {
//                 quit = 1;
//             }
//         }
//         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
//         SDL_RenderClear(renderer);

//         /* Use TTF textures. */
//         SDL_RenderCopy(renderer, texture1, NULL, &rect1);
//         SDL_RenderCopy(renderer, texture2, NULL, &rect2);

//         SDL_RenderPresent(renderer);
//     }

//     /* Deinit TTF. */
//     SDL_DestroyTexture(texture1);
//     SDL_DestroyTexture(texture2);
//     TTF_Quit();

//     SDL_DestroyRenderer(renderer);
//     SDL_DestroyWindow(window);
//     SDL_Quit();
//     return EXIT_SUCCESS;
// }




// int main(int argc, char **argv)
// {
    
//     t_init init;
//     t_filler filler;

//     filler.x = 400;
//     filler.y = 300;
//     init.quit  = 0;
//     //  ft_read(&filler);
//      ft_init_00(&init, &filler);
//     SDL_Init(SDL_INIT_EVERYTHING);//(SDL_INIT_VIDEO);

//      init.win = SDL_CreateWindow("filler",SDL_WINDOWPOS_UNDEFINED,           // initial x position
//         SDL_WINDOWPOS_UNDEFINED,           // initial y position
//         1000,                               // width, in pixels
//      100, SDL_WINDOW_SHOWN);
//          init.surf =  SDL_GetWindowSurface( init.win);
//          SDL_FillRect( init.surf, NULL, SDL_MapRGB( init.surf->format, 5, 5, 0));
//           SDL_UpdateWindowSurface( init.win);

//         SDL_Delay(30000);
//         SDL_FreeSurface( init.surf);
//         SDL_DestroyWindow( init.win);
//         SDL_Quit();
//   // TTF_Init();
//   // SDL_Surface *missage = NULL;
//   // char *text = "yassine";
//   // TTF_Font *font = NULL;

//   // SDL_Color  textcolor = {255,244,233};

//   // font = NULL;
//   // //TTF_OpenFont("a.ttf",28);
//   // missage = TTF_RenderText_Solid(font, text, textcolor);
//   // SDL_Rect rect;
//   // rect.x = 10;
//   // rect.y = 10;

//   // SDL_BlitSurface(missage, NULL, init.surf,&rect);
//  return 0;
// }


// // #include <stdlib.h>
// // #include <stdio.h>


// // int main(int argc, char *argv[])
// // {
// //     SDL_Surface *ecran = NULL, *texte = NULL, *fond = NULL;
// //     SDL_Rect position;
// //     SDL_Event event;
// //     TTF_Font *police = NULL;
// //     SDL_Color couleurNoire = {0, 0, 0};
// //     int continuer = 1;

// //     SDL_Init(SDL_INIT_VIDEO);
// //     TTF_Init();

// //     ecran = SDL_SetVideoMode(640, 480, 32, 0);
// //     SDL_WM_SetCaption("Gestion du texte avec SDL_ttf", NULL);

// //     fond = IMG_Load("moraira.jpg");

// //     /* Chargement de la police */
// //     police = TTF_OpenFont("angelina.ttf", 65);
// //     /* Écriture du texte dans la SDL_Surface texte en mode Blended (optimal) */
// //     texte = TTF_RenderText_Blended(police, "Salut les Zér0s !", couleurNoire);

// //     while (continuer)
// //     {
// //         SDL_WaitEvent(&event);
// //         switch(event.type)
// //         {
// //             case SDL_QUIT:
// //                 continuer = 0;
// //                 break;
// //         }

// //         SDL_FillRect(ecran, NULL, SDL_MapRGB(ecran->format, 255, 255, 255));

// //         position.x = 0;
// //         position.y = 0;
// //         SDL_BlitSurface(fond, NULL, ecran, &position); /* Blit du fond */

// //         position.x = 60;
// //         position.y = 370;
// //         SDL_BlitSurface(texte, NULL, ecran, &position); /* Blit du texte */
// //         ///SDL_Flip(ecran);
// //     }

// //     TTF_CloseFont(police);
// //     TTF_Quit();

// //     SDL_FreeSurface(texte);
// //     SDL_Quit();

// //     return EXIT_SUCCESS;
// // }
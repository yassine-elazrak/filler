/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/11 17:27:52 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/11 17:28:15 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ncurses.h>
 
#define TICKRATE 100
 
#define WORLD_WIDTH 50
#define WORLD_HEIGHT 20
 
#define SNAKEY_LENGTH 40
 
enum direction { UP, DOWN, RIGHT, LEFT };
 
typedef struct spart {
    int x;
    int y;
} snakeypart;
 
int move_snakey(WINDOW *win, int direction,
                snakeypart snakey[]);
 
int main(int argc, char *argv[]) {	
 
    WINDOW *snakeys_world;
    int offsetx, offsety, i, ch;
 
    initscr();
    noecho();
    cbreak();
    timeout(TICKRATE);
    keypad(stdscr, TRUE);
 
    printw("PieceOfCakeSnake v. 1.0  -  Press x to quit...");
 
    refresh();
 
    offsetx = (COLS - WORLD_WIDTH) / 2;
    offsety = (LINES - WORLD_HEIGHT) / 2;
 
    snakeys_world = newwin(WORLD_HEIGHT, 
                           WORLD_WIDTH, 
                           offsety, 
                           offsetx);
 
    snakeypart snakey[SNAKEY_LENGTH];
 
    int sbegx = (WORLD_WIDTH - SNAKEY_LENGTH) / 2;
    int sbegy = (WORLD_HEIGHT - 1) / 2;
 
    for (i = 0; i < SNAKEY_LENGTH; i++) {
        snakey[i].x = sbegx + i;
        snakey[i].y = sbegy;
    }
 
    int cur_dir = RIGHT;
 
    while ((ch = getch()) != 'x') {
        move_snakey(snakeys_world, cur_dir, snakey);
        if(ch != ERR) {
            switch(ch) {
                case KEY_UP:
                    cur_dir = UP;
                    break;
                case KEY_DOWN:
                    cur_dir = DOWN;
                    break;
                case KEY_RIGHT:
                    cur_dir = RIGHT;
                    break;
                case KEY_LEFT:
                    cur_dir = LEFT;
                    break;
                default:
                    break;
            }
 
        }
    }
 
    delwin(snakeys_world);
 
    endwin();
 
    return 0;
 
}
 
int move_snakey(WINDOW *win, int direction,
                snakeypart snakey[]) {
 
    wclear(win);
 
    for (int i = 0; i < SNAKEY_LENGTH - 1; i++) {
        snakey[i] = snakey[i + 1];
        mvwaddch(win, snakey[i].y, snakey[i].x, '#');
    }
 
    int x = snakey[SNAKEY_LENGTH - 1].x;
    int y = snakey[SNAKEY_LENGTH - 1].y;
    switch (direction) {
        case UP:
            y - 1 == 0 ? y = WORLD_HEIGHT - 2 : y--;
            break;
        case DOWN:
            y + 1 == WORLD_HEIGHT - 1 ? y = 1 : y++;
            break;
        case RIGHT:
            x + 1 == WORLD_WIDTH - 1 ? x = 1 : x++;
            break;
        case LEFT:
            x - 1 == 0 ? x = WORLD_WIDTH - 2 : x--;
            break;
        default:
            break;
    }
 
    snakey[SNAKEY_LENGTH - 1].x = x;
    snakey[SNAKEY_LENGTH - 1].y = y;
 
    mvwaddch(win, y, x, '#');
 
    box(win, 0 , 0);
 
    wrefresh(win);
 
    return 0;
}
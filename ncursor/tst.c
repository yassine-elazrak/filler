/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tst.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yelazrak <yelazrak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/12 17:35:45 by yelazrak          #+#    #+#             */
/*   Updated: 2019/10/13 15:04:04 by yelazrak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "filler.h"

/*
   int main(int argc, char **argv)
   {
   initscr();
   cbreak();
   noecho();
   clear();
   mvaddstr("sggshdghsgdhsgkghks");


   return (0);
   }
   */
void rectangle(int y1, int x1, int y2, int x2)
{
	mvhline(y1, x1, 0, x2-x1);
	mvhline(y2, x1, 0, x2-x1);
	mvvline(y1, x1, 0, y2-y1);
	mvvline(y1, x2, 0, y2-y1);
	mvaddch(y1, x1, ACS_ULCORNER);
	mvaddch(y2, x1, ACS_LLCORNER);
	mvaddch(y1, x2, ACS_URCORNER);
	mvaddch(y2, x2, ACS_LRCORNER);
}

// int main() {
// 	WINDOW * Win = initscr();
// 	noecho();
// 	crmode();
// 	WINDOW * win = newwin(100, 100, 1, 1);
// 	box(Win,0,0); // This works
// 	move(90,90);
// 	start_color();
// 	init_pair(4, COLOR_RED, COLOR_GREEN); /* create foreground / background combination */
// //	attron(COLOR_PAIR(4)); /* use the above combination */
// //	rectangle(4,4,5,5);
// 	//printw("Some text");
// //	attroff(COLOR_PAIR(4));
// //	*/


// 	attron(COLOR_PAIR(4));
// 	mvwvline(win, 20, 20, 'g', 2);
// 	//rectangle(8,8,7,8);
// 	attroff(COLOR_PAIR(4));
// 	//rectangle(3, 3, 4,4);
// 	//box(win,20,20); // no output
// 	//waddstr(win, "6565665656565");
// 	wbkgd(a,COLOR_PAIR(1));
// 	wrefresh(a);
// 	wrefresh(win);
// 	refresh();
// 	getch();
// 	endwin();
// }


// mvwaddch(win, y, x, '#');
 
//     box(win, 0 , 0);
 
//     wrefresh(win);
// void    ft_size_terminal(t_init *init)
// {
//     struct ttysize ts;
//     ioctl(0, TIOCGSIZE, &ts);

//     init->s_line =  ts.ts_lines;
//     init->s_col =  ts.ts_cols;
// }


void draw_borders(WINDOW *screen, t_filler *filler, t_init *init)
 {
	  int x, y, y0,x0,i; //getmaxyx(screen, y, x);
  // 4 corners 
  x = filler->x + 6;
  y = filler->y + 6;
  x0 = 4;
  y0 = 4;

   //wclear(screen);
//   creen, 40,40);
  	mvwprintw(screen, y0, x0, "+");
	mvwprintw(screen, y - 1, x0, "+");
    mvwprintw(screen, y0, x - 1, "+");
	mvwprintw(screen, y - 1, x - 1, "+"); 
	 // sides 
	 i = x0;
	 while (++i < (y - 1))
	  { 
		  	mvwprintw(screen, i, x0, "|");
	   		mvwprintw(screen, i, x - 1, "|"); 
	   } 
	   i = y0;
	   while (++i < (x - 1))
	    { 
			mvwprintw(screen, y0, i, "-"); 
			mvwprintw(screen, y - 1, i, "-");
		 }
		//  ft_put_image(filler, init);
		//  ft_print_plyer(filler, NULL);
		// box(screen,0,0);
		// 	wrefresh(screen); 
}

void		ft_print_plyer(t_filler *filler, t_init *init)
{ 
	start_color();
	init_pair(4, COLOR_RED, COLOR_GREEN); 
	attron(COLOR_PAIR(4));
	 mvprintw(6, filler->x + 18 , "players 1");
	attroff(COLOR_PAIR(4));
	init_pair(8, COLOR_RED, COLOR_GREEN); 
	attron(COLOR_PAIR(4));
 	mvprintw(10, filler->x + 18, "players 2");
	attroff(COLOR_PAIR(4));
	init_pair(4, COLOR_RED, COLOR_GREEN); 
	attron(COLOR_PAIR(4));
	 mvprintw(12, filler->x + 18, "%s",filler->p1);
	attroff(COLOR_PAIR(4));
	init_pair(4, COLOR_RED, COLOR_GREEN); 
	attron(COLOR_PAIR(4));
	 mvprintw(14, filler->x + 18, "%s",filler->p1);
	attroff(COLOR_PAIR(4));
	
}

int main() 
{
	t_init init;
	t_filler filler;
	int c;


	ft_read(&filler);
   ft_init_00(&init, &filler);
	initscr();
	noecho();
	crmode();
	init.win = newwin( filler.y + 8,  filler.x + 10, 1, 1);
	box(init.win,0,0); 
	//ft_read(&filler);
   ft_init_00(&init, &filler);
	// ft_print_plyer(&filler, NULL);
	//draw_borders(init.win, &filler, &init);	
	//refresh();
	// ft_print_plyer(&filler, NULL);
	//ft_print_plyer(&filler, &init);
	// start_color();
	// init_pair(4, COLOR_RED, COLOR_GREEN); 
	// attron(COLOR_PAIR(4));

	// attroff(COLOR_PAIR(4));
	//wrefresh(init.win);
	// //init_pair(8, COLOR_RED, COLOR_GREEN); 
	// attron(COLOR_PAIR(4));
 	// mvaddstr(10, filler.x  , "players 2\n");	refresh();
	// attroff(COLOR_PAIR(4));
	// //init_pair(4, COLOR_RED, COLOR_GREEN); 
	// attron(COLOR_PAIR(4));
	//  mvprintw(12, filler.x + 10 , "%s\n",filler.p1);
	// attroff(COLOR_PAIR(4));
	// //init_pair(4, COLOR_RED, COLOR_GREEN); 
	// // attron(COLOR_PAIR(4));
	//   mvprintw(14, filler.x + 10 , "%s\n",filler.p2);
	// // attroff(COLOR_PAIR(4));
	// //box(init.win,0,0); 
	// dprintf(2,"x = %d\n",filler.x);
	// dprintf(2,"y = %d\n",filler.y);
	// dprintf(2,"x0 = %d\n",init.x0);
	// dprintf(2,"y0 = %d\n",init.y0);
	// dprintf(2,"i =%d\n",init.i);
	// 	dprintf(2,"w = %d\n",init.w);
	// dprintf(2,"h = %d\n",init.h);
	

	//ft_print_plyer(&filler, &init);
	 
	 ft_put_image(&filler, &init);


	//refresh();

	refresh();
	wrefresh(init.win);
	 while ((c = getch()) != 'x')
	 ;
	endwin();
}



// int main(int argc, char *argv[]) 
// { int parent_x, parent_y, new_x, new_y;
//  int score_size = 3; 
// // ... 
// draw_borders(field); 
// draw_borders(score);
//  while(1)
//   { 
// 	  getmaxyx(stdscr, new_y, new_x);
//    if (new_y != parent_y || new_x != parent_x)
//     { parent_x = new_x; parent_y = new_y;
//     wresize(field, new_y - score_size, new_x); 
// 	wresize(score, score_size, new_x);
// 	 mvwin(score, new_y - score_size, 0);
// 	  wclear(stdscr); 
// 	 wclear(field); 
// 	 wclear(score);
// 	  draw_borders(field); 
// 	  draw_borders(score); } // draw to our windows 
// 	  mvwprintw(field, 1, 1, "Field");
// 	   mvwprintw(score, 1, 1, "Score");
// 	   // refresh each window 
// 	   wrefresh(field); 
// 	   wrefresh(score); 
// } // ...
// }



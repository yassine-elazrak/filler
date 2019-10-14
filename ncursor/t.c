#include  <ncurses.h>
#include  <stdio.h>
#include  <stdlib.h>
#include  <string.h>

int  main () 
{ 
    const  int  width  =  50 ; 
    const  int  height  =  20 ;

    if  ( ! initscr ()) 
    { 
        fprintf ( stderr ,  "Error initialising ncurses. \n " ); 
        exit ( 1 ); 
    }

    initscr (); 
    curs_set ( 0 ); 
    refresh ();

    int  offsetx  =  ( COLS  -  width )  /  2 ; 
    int  offsety  =  ( LINES  -  height )  /  2 ;

    WINDOW  * win  =  newwin ( height ,  width ,  offsety ,  offsetx );

    char  hello []  =  "Hello, world!" ;

    mvaddstr ( LINES / 2 ,  ( COLS - strlen ( hello )) / 2 ,  hello ); 
    box ( win ,  0 ,  0 );
    mvaddstr ( 200 ,  ( COLS - strlen ( hello )) / 2 ,  hello );
    wrefresh ( win ); 
    getch ();

    delwin ( win ); 
    endwin (); 
}
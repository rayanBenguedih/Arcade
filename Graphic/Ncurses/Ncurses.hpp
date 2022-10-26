/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Ncurses
*/

#ifndef NCURSES_HPP_
#define NCURSES_HPP_

#include <iostream>
#include <curses.h>
#include <vector>

extern WINDOW *stdscr;

class Ncurses {
    public:
        static WINDOW *_newwin(int height, int width, int startY, int startX);
        static WINDOW *_initscr(void);
        static int _keypad(WINDOW *, bool);
        static void _wprintw(WINDOW *target, std::string message);
        static int _mvwprintw(WINDOW *target, int y, int x, std::string print, ...);
        static int _wrefresh(WINDOW *target);
        static int _wgetch(WINDOW *win);
        static int _wattron(WINDOW *target, int color_pair);
        static int _wattroff(WINDOW *target, int color_pair);
        static int _wclear(WINDOW *target);
        static int _delwin(WINDOW *target);
        static int _endwin(void);
        static int _start_color(void);
        static int _init_pair(int, int, int);
        static int _init_color(short, short, short, short);
        static int _wbkgd(WINDOW *target, chtype color_pair);
        static int _curs_set(int);
        static int _noecho(void);
        static int _cbreak(void);
        static int _nodelay(WINDOW *target, bool);
        static int _waddch(WINDOW *target, chtype chara);
        static int _mvwaddch(WINDOW *target, int y, int x, chtype ch);
        static std::vector<int> _getmaxyx(WINDOW *target, int y, int x);

        chtype _full = ' '|A_REVERSE;

        // Main d'exemple 

        // void main()
        // {
        //     initscr();
        //     start_color();
        //     init_pair(1,COLOR_MAGENTA, COLOR_CYAN);
        //     WINDOW *win = newwin(10,10,1,1);
        //     wbkgd(win,COLOR_PAIR(1));
        //     wprintw(win,"Hello, World.");
        //     wrefresh(win);
        //     getch();
        //     delwin(win);
        //     endwin();
        // }
};

#endif /* !NCURSES_HPP_ */

/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Ncurses
*/

#include "Ncurses.hpp"

WINDOW *Ncurses::_newwin(int height, int width, int startY, int startX)
{
    WINDOW *tmp = newwin(height, width, startY, startX);

    if (tmp == NULL)
        throw std::invalid_argument("Error: can't create the window");
    return tmp;
}

WINDOW *Ncurses::_initscr(void)
{
    return initscr();
}

int Ncurses::_keypad(WINDOW *w, bool bf)
{
    return keypad(w, bf);
}

void Ncurses::_wprintw(WINDOW *target, std::string str)
{
    wprintw(target, str.c_str());
}

int Ncurses::_mvwprintw(WINDOW *target, int y, int x, std::string print, ...)
{
    va_list argv;

    return mvwprintw(target, y, x, print.c_str(), argv);
}

int Ncurses::_wrefresh(WINDOW *win)
{
    return wrefresh(win);
}

int Ncurses::_wgetch(WINDOW *win)
{
    return wgetch(win);
}

int Ncurses::_wattron(WINDOW *target, int color_pair)
{
    return wattron(target, color_pair);
}

int Ncurses::_wattroff(WINDOW *target, int color_pair)
{
    return wattroff(target, color_pair);
}

int Ncurses::_wclear(WINDOW *target)
{
    return wclear(target);
}

int Ncurses::_delwin(WINDOW *target)
{
    return delwin(target);
}

int Ncurses::_endwin(void)
{
    return endwin();
}

int Ncurses::_start_color(void)
{
    return start_color();
}

int Ncurses::_init_pair(int index, int foreground, int background)
{
    return init_pair(index, foreground, background);
}
int Ncurses::_init_color(short a, short red, short blue, short green)
{
    return init_color(a, red, blue, green);
}

int Ncurses::_wbkgd(WINDOW *target, chtype color_pair)
{
    return wbkgd(target, color_pair);
}

int Ncurses::_curs_set(int choice)
{
    return curs_set(choice);
}

int Ncurses::_noecho(void)
{
    return noecho();
}

int Ncurses::_cbreak(void)
{
    return _cbreak();
}

int Ncurses::_waddch(WINDOW *target, chtype chara)
{
    return waddch(target, chara);
}

int Ncurses::_mvwaddch(WINDOW *target, int y, int x, chtype ch)
{
    return mvwaddch(target, y, x, ch);
}

int Ncurses::_nodelay(WINDOW *target, bool b)
{
    return (nodelay(target, b));
}

std::vector<int> Ncurses::_getmaxyx(WINDOW *target, int y, int x)
{
    (void)x;
    (void)y;
    return {getmaxy(target), getmaxx(target)};
}
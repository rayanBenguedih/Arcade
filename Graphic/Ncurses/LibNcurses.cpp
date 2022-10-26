/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** LibNcurses
*/

#include <iostream>
#include <vector>

#include "LibNcurses.hpp"
#include <unistd.h>


LibNcurses::LibNcurses()
{
    this->_libName = "NCURSES";
    this->_win = NULL;
    this->_win2 = NULL;
    this->_win3 = NULL;

    this->_keys.insert({'A', arcade::KEY_A});
    this->_keys.insert({'B', arcade::KEY_B});
    this->_keys.insert({'C', arcade::KEY_C});
    this->_keys.insert({'D', arcade::KEY_D});
    this->_keys.insert({'E', arcade::KEY_E});
    this->_keys.insert({'F', arcade::KEY_F});
    this->_keys.insert({'G', arcade::KEY_G});
    this->_keys.insert({'H', arcade::KEY_H});
    this->_keys.insert({'I', arcade::KEY_I});
    this->_keys.insert({'J', arcade::KEY_J});
    this->_keys.insert({'K', arcade::KEY_K});
    this->_keys.insert({'L', arcade::KEY_L});
    this->_keys.insert({'M', arcade::KEY_M});
    this->_keys.insert({'N', arcade::KEY_N});
    this->_keys.insert({'O', arcade::KEY_O});
    this->_keys.insert({'P', arcade::KEY_P});
    this->_keys.insert({'Q', arcade::KEY_Q});
    this->_keys.insert({'R', arcade::KEY_R});
    this->_keys.insert({'S', arcade::KEY_S});
    this->_keys.insert({'T', arcade::KEY_T});
    this->_keys.insert({'U', arcade::KEY_U});
    this->_keys.insert({'V', arcade::KEY_V});
    this->_keys.insert({'W', arcade::KEY_W});
    this->_keys.insert({'X', arcade::KEY_X});
    this->_keys.insert({'Y', arcade::KEY_Y});
    this->_keys.insert({'Z', arcade::KEY_Z});
    this->_keys.insert({'0', arcade::NUMBER_0});
    this->_keys.insert({'1', arcade::NUMBER_1});
    this->_keys.insert({'2', arcade::NUMBER_2});
    this->_keys.insert({'3', arcade::NUMBER_3});
    this->_keys.insert({'4', arcade::NUMBER_4});
    this->_keys.insert({'5', arcade::NUMBER_5});
    this->_keys.insert({'6', arcade::NUMBER_6});
    this->_keys.insert({'7', arcade::NUMBER_7});
    this->_keys.insert({'8', arcade::NUMBER_8});
    this->_keys.insert({'9', arcade::NUMBER_9});
    this->_keys.insert({KEY_UP, arcade::ARROW_U});
    this->_keys.insert({KEY_DOWN, arcade::ARROW_D});
    this->_keys.insert({KEY_LEFT, arcade::ARROW_L});
    this->_keys.insert({KEY_RIGHT, arcade::ARROW_R});
}

LibNcurses::~LibNcurses() {}

void LibNcurses::draw_borders(WINDOW *screen) {
    int x = 0;
    int y = 0;
    int i = 0;

    x = _getmaxyx(screen, y, x)[1];
    y = _getmaxyx(screen, y, x)[0];

    _mvwprintw(screen, 0, 0, "+");
    _mvwprintw(screen, y - 1, 0, "+");
    _mvwprintw(screen, 0, x - 1, "+");
    _mvwprintw(screen, y - 1, x - 1, "+");
    for (i = 1; i < (y - 1); i++) {
        _mvwprintw(screen, i, 0, "|");
        _mvwprintw(screen, i, x - 1, "|");
    }
    for (i = 1; i < (x - 1); i++) {
        _mvwprintw(screen, 0, i, "-");
        _mvwprintw(screen, y - 1, i, "-");
    }
}

void LibNcurses::drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths)
{
    std::string m1 = "   ###    ########   ######     ###    ########  ########";
    std::string m2 = "  ## ##   ##     ## ##    ##   ## ##   ##     ## ##      ";
    std::string m3 = " ##   ##  ##     ## ##        ##   ##  ##     ## ##      ";
    std::string m4 = "##     ## ########  ##       ##     ## ##     ## ######  ";
    std::string m5 = "######### ##   ##   ##       ######### ##     ## ##      ";
    std::string m6 = "##     ## ##    ##  ##    ## ##     ## ##     ## ##      ";
    std::string m7 = "##     ## ##     ##  ######  ##     ## ########  ########";
    int mLen = m1.length() / 2;
    int input = 0;
    int color = 1;

    if (this->_win == NULL && this->_win2 == NULL && this->_win3 == NULL) {
        _initscr();
        _start_color();
        _init_pair(1, COLOR_CYAN, COLOR_BLACK);
        _init_pair(10, COLOR_BLUE, COLOR_BLACK);
        _init_pair(11, COLOR_CYAN, COLOR_BLACK);
        _init_pair(12, COLOR_GREEN, COLOR_BLACK);
        _init_pair(13, COLOR_RED, COLOR_BLACK);
        _init_pair(14, COLOR_YELLOW, COLOR_BLACK);
        _init_pair(15, COLOR_MAGENTA, COLOR_BLACK);
        _init_pair(16, COLOR_WHITE, COLOR_BLACK);
        try {
            this->_win = _newwin(13, _getmaxyx(stdscr, input, color)[1], 0, 0);
            this->_win2 = _newwin(_getmaxyx(stdscr, input, color)[0] - 13, _getmaxyx(stdscr, input, color)[1] / 2, 13, 0);
            this->_win3 = _newwin(_getmaxyx(stdscr, input, color)[0] - 13, _getmaxyx(stdscr, input, color)[1] / 2, 13, _getmaxyx(stdscr, 0, 0)[1] / 2);
        } catch(const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        _keypad(_win, true);
        _curs_set(false);
        _noecho();
        _nodelay(_win, true);
    }

    while(1) {
        color = rand() % 6 + 10;

        _wattron(this->_win, COLOR_PAIR(color));
        this->draw_borders(this->_win);
        _wattroff(this->_win, COLOR_PAIR(color));
        this->draw_borders(this->_win2);
        this->draw_borders(this->_win3);

        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 2, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m1);
        _wattroff(this->_win, COLOR_PAIR(color));
        color = rand() % 6 + 10;
        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 3, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m2);
        _wattroff(this->_win, COLOR_PAIR(color));
        color = rand() % 6 + 10;
        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 4, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m3);
        _wattroff(this->_win, COLOR_PAIR(color));
        color = rand() % 6 + 10;
        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 5, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m4);
        _wattroff(this->_win, COLOR_PAIR(color));
        color = rand() % 6 + 10;
        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 6, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m5);
        _wattroff(this->_win, COLOR_PAIR(color));
        color = rand() % 6 + 10;
        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 7, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m6);
        _wattroff(this->_win, COLOR_PAIR(color));
        color = rand() % 6 + 10;
        _wattron(this->_win, COLOR_PAIR(color));
        _mvwprintw(this->_win, 8, (_getmaxyx(this->_win, 0, 0)[1] / 2 - mLen), m7);
        _wattroff(this->_win, COLOR_PAIR(color));

        _mvwprintw(this->_win2, 1, 1, "Graphical Librairies:");
        if (displayersPaths.size() != 0)
            for (size_t i = 0; i != displayersPaths.size(); i++) {
                if (!strcasecmp("ncurses", displayersPaths[i].c_str())) {
                    _wattron(this->_win2, COLOR_PAIR(color));
                    _mvwaddch(this->_win2, 2 + i, 3, ACS_DIAMOND);
                    _wattroff(this->_win2, COLOR_PAIR(color));
                } else
                    _mvwaddch(this->_win2, 2 + i, 3, ACS_DIAMOND);
                _mvwprintw(this->_win2, 2 + i, 5, displayersPaths[i]);
            }

        _mvwprintw(this->_win2, 3 + displayersPaths.size(), 1, "Games:");
        if (gamesPaths.size() != 0)
            for (size_t i = 0; i != gamesPaths.size(); i++) {
                if (!strcasecmp(this->_actualGame.c_str(), gamesPaths[i].c_str())) {
                    _wattron(this->_win2, COLOR_PAIR(color));
                    _mvwaddch(this->_win2, 4 + displayersPaths.size() + i, 3, ACS_DIAMOND);
                    _wattroff(this->_win2, COLOR_PAIR(color));
                } else
                    _mvwaddch(this->_win2, 4 + displayersPaths.size() + i, 3, ACS_DIAMOND);
                _mvwprintw(this->_win2, 4 + displayersPaths.size() + i, 5, gamesPaths[i]);
            }

        _mvwprintw(this->_win3, 1, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 3), "KEYMAP");
        _mvwprintw(this->_win3, 3, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "Changing Graphics");
        _mvwprintw(this->_win3, 4, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "       Previous        : 1");
        _mvwprintw(this->_win3, 5, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "       Next            : 2");
        _mvwprintw(this->_win3, 6, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "Changing Games");
        _mvwprintw(this->_win3, 7, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "       Previous        : 4");
        _mvwprintw(this->_win3, 8, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "       Next            : 5");
        _mvwprintw(this->_win3, 9, (_getmaxyx(this->_win3, 0, 0)[1] / 2 - 18), "LEAVE THE PROGRAM      : 0");

        _mvwprintw(this->_win3, 12, 18, "IN THE MENU PRESS ");
        _wattron(this->_win3, COLOR_PAIR(1));
        _mvwprintw(this->_win3, 12, 37, "'L'");
        _wattroff(this->_win3, COLOR_PAIR(1));
        _mvwprintw(this->_win3, 12, 41, " TO LAUNCH THE FIRST GAME");

        ////////////// GESTION DES TOUCHES //////////////////////////////

        input = _wgetch(this->_win);

        if (input != -1) {
            if (std::toupper(input) == 'L') {
                this->_input = arcade::KEY_L;
                _wclear(this->_win);
                _wclear(this->_win2);
                _wclear(this->_win3);
                _delwin(this->_win);
                _delwin(this->_win2);
                _delwin(this->_win3);
                this->_win = NULL;
                this->_win2 = NULL;
                this->_win3 = NULL;
                return;
            }
        }

        if (this->_keys.count(std::toupper(input)) > 0) {
            this->_input = this->_keys.at(std::toupper(input));
            return;
        }

        /////////////////////////////////////////////////////////////////
        _wrefresh(this->_win);
        _wrefresh(this->_win2);
        _wrefresh(this->_win3);
    }
}

void LibNcurses::drawGame(std::vector<std::string> map)
{
    int input = 0;
    int x = 0;
    int y = 0;
    std::string tmp;

    if (this->_win == NULL && this->_win2 == NULL && this->_win3 == NULL) {
        _initscr();
        _start_color();
        _init_pair(1, COLOR_BLUE, COLOR_BLACK);
        _init_pair(2, COLOR_RED, COLOR_BLACK);
        _init_pair(3, COLOR_MAGENTA, COLOR_BLACK);
        _init_pair(4, COLOR_YELLOW, COLOR_BLACK);
        _init_pair(5, COLOR_WHITE, COLOR_BLACK);
        _init_pair(6, COLOR_CYAN, COLOR_BLACK);

        try {
            this->_win = _newwin(_getmaxyx(stdscr, x, y)[0], _getmaxyx(stdscr, x, y)[1] / 2, 0, 0);
            this->_win2 = _newwin(_getmaxyx(stdscr, x, y)[0] / 2, _getmaxyx(stdscr, x, y)[1] / 2, 0, _getmaxyx(stdscr, x, y)[1] / 2);
            this->_win3 = _newwin(_getmaxyx(stdscr, x, y)[0] / 2, _getmaxyx(stdscr, x, y)[1] / 2, _getmaxyx(stdscr, x, y)[0] / 2, _getmaxyx(stdscr, x, y)[1] / 2);
        } catch(const std::exception &e) {
            std::cerr << e.what() << '\n';
        }
        _keypad(_win, true);
        _curs_set(false);
        _noecho();
        _nodelay(_win, true);
    }

    _wclear(this->_win);
    _wclear(this->_win2);
    _wclear(this->_win3);

    this->draw_borders(this->_win);
    this->draw_borders(this->_win2);
    this->draw_borders(this->_win3);

    for (size_t i = 2; i != map.size(); i++) {
        for (size_t j = 0; j != map[i].size(); j++) {
            tmp = map[i][j];
            if (map[i][j] == 'P') {
                _wattron(this->_win, COLOR_PAIR(4));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(4));
                continue;
            }
            if (map[i][j] == 'R') {
                _wattron(this->_win, COLOR_PAIR(2));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(2));
                continue;
            }
            if (map[i][j] == 'B') {
                _wattron(this->_win, COLOR_PAIR(6));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(6));
                continue;
            }
            if (map[i][j] == 'J') {
                _wattron(this->_win, COLOR_PAIR(4));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(4));
                continue;
            }
            if (map[i][j] == 'V') {
                _wattron(this->_win, COLOR_PAIR(3));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(3));
                continue;
            }
            if (map[i][j] == 'H') {
                _wattron(this->_win, COLOR_PAIR(1));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(1));
                continue;
            }
            if (map[i][j] == 'Q') {
                _wattron(this->_win, COLOR_PAIR(4));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(4));
                continue;
            }
            if (map[i][j] == 'D') {
                _wattron(this->_win, COLOR_PAIR(6));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, ACS_HLINE);
                _wattroff(this->_win, COLOR_PAIR(6));
                continue;
            }
            if (map[i][j] == 'F') {
                _wattron(this->_win, COLOR_PAIR(4));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, ACS_DIAMOND);
                _wattroff(this->_win, COLOR_PAIR(4));
                continue;
            }
            if (map[i][j] == '#') {
                _wattron(this->_win, COLOR_PAIR(6));
                _mvwprintw(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, tmp);
                _wattroff(this->_win, COLOR_PAIR(6));
                continue;
            }
            if (map[i][j] == 'o') {
                _wattron(this->_win, COLOR_PAIR(5));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, ACS_BULLET);
                _wattroff(this->_win, COLOR_PAIR(5));
                continue;
            }
            if (map[i][j] == 'O') {
                _wattron(this->_win, COLOR_PAIR(5));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, ACS_DIAMOND);
                _wattroff(this->_win, COLOR_PAIR(5));
                continue;
            }
            if (map[i][j] == 'U') {
                _wattron(this->_win, COLOR_PAIR(1));
                _mvwaddch(this->_win, ((_getmaxyx(this->_win, y, x)[0] / 2) - map.size() / 2) + i, ((_getmaxyx(this->_win, y, x)[0] / 2) - map[2].size() / 4) + j, _full);
                _wattroff(this->_win, COLOR_PAIR(1));
            }
        }
    }
    int color = rand() % 4;
    _wattron(this->_win, COLOR_PAIR(color));
    _mvwprintw(this->_win2, 2, 3, "SCORE");
    _wattroff(this->_win, COLOR_PAIR(color));
    _mvwprintw(this->_win2, 3, 3, map[0]);

    _wattron(this->_win, COLOR_PAIR(2));
    _mvwprintw(this->_win2, 5, 3, "HP");
    _wattroff(this->_win, COLOR_PAIR(2));
    _mvwprintw(this->_win2, 6, 3, map[1]);

    _wrefresh(this->_win);
    _wrefresh(this->_win2);
    _wrefresh(this->_win3);

    input = _wgetch(this->_win);

    if (input == -1) {
        this->_input = arcade::NONE;
    }

    if (std::toupper(input) == 'M') {
        this->_input = arcade::KEY_M;
        _wclear(this->_win);
        _wclear(this->_win2);
        _wclear(this->_win3);
        _delwin(this->_win);
        _delwin(this->_win2);
        _delwin(this->_win3);
        this->_win = NULL;
        this->_win2 = NULL;
        this->_win3 = NULL;
        return;
    }

    if (this->_keys.count(std::toupper(input)) > 0)
        this->_input = this->_keys.at(std::toupper(input));

    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}

bool LibNcurses::isRunning(void)
{
    return true;
}

arcade::KeyboardKeys LibNcurses::getInput(void)
{
    return this->_input;
}

std::string LibNcurses::getName(void)
{
    return this->_libName;
}

void LibNcurses::loadGameAssets(std::string actualGamePath, std::vector<std::string> map)
{
    (void)actualGamePath;
    (void)map;
    return;
}

void LibNcurses::loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath)
{
    this->_actualGame = actualGamePath;
    (void)gameLibPath;
    (void)displayerlibPath;
    return;
}

void LibNcurses::destroyWindow(void)
{
    _wclear(this->_win);
    _wclear(this->_win2);
    _wclear(this->_win3);
    _delwin(this->_win);
    _delwin(this->_win2);
    _delwin(this->_win3);
    _endwin();
    this->_win = NULL;
    this->_win2 = NULL;
    this->_win3 = NULL;
}

extern "C" std::shared_ptr<LibNcurses> entryPoint(void)
{
    return std::make_shared<LibNcurses>();
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** LibNcurses
*/

#ifndef LIBNCURSES_HPP_
#define LIBNCURSES_HPP_

#include "Ncurses.hpp"
#include "../../Displayer/IDisplayer.hpp"
#include "../../Game/IGame.hpp"

#include <map>
#include <memory>
#include <chrono>
#include <thread>
#include <strings.h>

class LibNcurses : public Ncurses, public arcade::displayer::IDisplayer {
    public:
        LibNcurses();
        ~LibNcurses();

        void drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths);
        void drawGame(std::vector<std::string> map);

        void loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath);
        void loadGameAssets(std::string actualGamePath, std::vector<std::string> map);

        void destroyWindow(void);

        bool isRunning(void);

        arcade::KeyboardKeys getInput(void);

        std::string getName(void);
        void draw_borders(WINDOW *target);

    protected:
        std::string _libName;
        WINDOW *_win;
        WINDOW *_win2;
        WINDOW *_win3;

        arcade::KeyboardKeys _input;

        std::map<int, arcade::KeyboardKeys> _keys;
        std::vector<std::string> _games;
        std::vector<std::string> _graphics;
        std::string _actualGame;

        // std::vector<float> _playerPos;
        // int _hp;
        // arcade::entity::EntityState _playerState;

        // std::vector<arcade::entity::Vector> _enemyPos;
        // std::vector<arcade::entity::EntityState> _enemyState;
        // std::vector<arcade::entity::Direction> _enemyDir;

        // arcade::entity::Direction _playerDir;

        //              MENU
        // title = n._newwin(13, 190, 0, 0);
        // lib = n._newwin(39, 95, 13, 0);
        // keymap = n._newwin(39, 95, 13, 95);

        // game = n._newwin(52, 190, 0, 0);
        // lib = n._newwin(35, 90, 0, 100);
        // score = n._newwin(17, 90, 35, 100);
};

#endif /* !LIBNCURSES_HPP_ */
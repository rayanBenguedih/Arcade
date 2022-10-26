/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Classes for the Pacman game
*/

#ifndef PACMAN
    #define PACMAN

#include "../../AGame.hpp"
#include <iostream>
#include <unordered_map>
#include <time.h>

namespace arcade
{
    namespace game
    {
        class Pacman : public AGame
        {
            private:
                std::pair<std::size_t, std::size_t> _pacman;
                std::vector<std::pair<std::size_t, std::size_t>> _ghosts;
                std::vector<std::pair<std::size_t, std::size_t>> _ghostsBasePos;
                std::vector<char> _underGhost;
                std::string _ghostOrder = "VBRJ";
                std::vector<bool> _isVulne;
                clock_t _clock;
                std::size_t _pacgome = 0;

                void pacmanDirection(void);
                void resetPacman(std::vector<std::string>, bool);
                void updateGhost(size_t, size_t);
                void getHardMap(void);
                bool read_map(std::string file);
                void moveGhosts(void);
                void decideMovement(short, std::pair<short, short>);
                void placeMovingElements(bool);
            public:
                Pacman(void);

                void update(void);
                std::vector<std::string> getDatas(void);
                void setInput(arcade::KeyboardKeys input);

                std::pair<std::size_t, std::size_t> getPacmanPos(void) const;
                void updateDisplayedMap(void);
        };
    }
}
#endif

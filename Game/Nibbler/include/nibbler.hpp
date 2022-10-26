/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Classes for the Nibbler game
*/

#ifndef NIBBLER
    #define NIBBLER

#include "../../AGame.hpp"
#include <iostream>
#include <unordered_map>

namespace arcade
{
    namespace game
    {
        class Nibbler : public AGame
        {
            private:
                std::size_t _size = 3;
                std::vector<std::pair<std::size_t, std::size_t>> _snakeBodyPos;
                std::pair<std::size_t, std::size_t> _fruitsPos;

                void snakeDirection(void);
                void getHardMap(void);
                bool addBodyPart(void);
                void addFruit(void);
                void updateDisplayedMap(void);
                bool read_map(std::string file);
            public:
                Nibbler(void);

                void update(void);
                std::vector<std::string> getDatas(void);
                void setInput(arcade::KeyboardKeys input);
                std::size_t getSize(void) const;
                std::pair<std::size_t, std::size_t> getBodyPos(std::size_t);
                std::vector<std::pair<std::size_t, std::size_t>> getBodyPos(void) const;
        };
    }
}
#endif

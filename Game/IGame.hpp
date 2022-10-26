/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Interface for the games
*/

#ifndef IGAME
#define IGAME

#include <vector>
#include <memory>
#include "../Displayer/IDisplayer.hpp"

namespace arcade
{
    namespace entity
    {
        enum Direction {
            LEFT,
            RIGHT,
            UP,
            DOWN,
            NONE
        };
    };

    namespace game
    {
        class IGame
        {
            public:
                virtual ~IGame() = default;

                virtual void update(void) = 0;

                virtual std::vector<std::string> getDatas(void) = 0;
                virtual void setInput(arcade::KeyboardKeys input) = 0;
        };
    };
};

#endif

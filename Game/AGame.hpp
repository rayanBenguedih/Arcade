/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Basic classes for the games
*/

#include "IGame.hpp"


namespace arcade
{
    namespace game
    {
        class Map
        {
            private:
                std::vector<std::string> _map;
                std::vector<std::string> _displayedMap;
            protected:
                std::vector<std::string> getMap(void) const;
                void setMap(std::vector<std::string>);
                void updateMap(std::size_t, std::size_t, char);
                short isFreeSpace(std::size_t, std::size_t) const;
                std::vector<std::string> getDisplayedMap(void) const;
                void setDisplayedMap(std::vector<std::string>);
        };

        class AGame : public IGame , public arcade::game::Map
        {
            protected:
                std::size_t _score = 0;
                std::size_t _health;
                float _multiplicator = 1;

                std::vector<std::pair<std::string, std::string>> _keyMap;
                arcade::KeyboardKeys _input;
                arcade::KeyboardKeys _direction = ARROW_R;
            public:
                virtual void update(void) = 0;
                virtual std::vector<std::string> getDatas(void) = 0;
                virtual void setInput(arcade::KeyboardKeys input) = 0;
        };
    };
};

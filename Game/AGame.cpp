/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Functions for the AGame.hpp file
*/

#include "AGame.hpp"
#include <iostream>
std::vector<std::string> arcade::game::Map::getMap(void) const
{
    return (this->_map);
}

void arcade::game::Map::updateMap(std::size_t line, std::size_t linePos, char change)
{
    this->_displayedMap[line][linePos] = change;
}

void arcade::game::Map::setMap(std::vector<std::string> newMap)
{
    this->_map = newMap;
}


short arcade::game::Map::isFreeSpace(std::size_t posY, std::size_t posX) const
{
    if (posY >= this->_displayedMap.size() || posX >= this->_displayedMap[posY].length())
        return (0);
    switch (this->_displayedMap[posY][posX]) {
        case (' '):
            return (0);
            break;
        case ('F'):
            return (2);
            break;
        case ('o'):
            return (3);
            break;
        case ('O'):
            return (4);
            break;
        case ('B'): case ('J'): case ('R'): case ('V'):
            return (5);
            break;
        case ('U'):
            return (6);
        case ('D'):
            return (7);
        default:
            return (1);
            break;
    }
    return (1);
}

std::vector<std::string> arcade::game::Map::getDisplayedMap(void) const
{
    return (this->_displayedMap);
}

void arcade::game::Map::setDisplayedMap(std::vector<std::string> map)
{
    this->_displayedMap = map;
}

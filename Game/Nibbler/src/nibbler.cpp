/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** The Nibbler game
*/

#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <memory>
#include "../include/nibbler.hpp"

//---------------------------Template functions--------------------------------

arcade::game::Nibbler::Nibbler(void)
{
    this->_keyMap.push_back({"GO RIGHT", "ARROW RIGHT"});
    this->_keyMap.push_back({"GO LEFT", "ARROW LEFT"});
    this->_health = 1;
    srand(time(0));
    if (read_map("./map/Nibbler/map.txt") == false)
        this->getHardMap();
    this->_snakeBodyPos.push_back({15, 35});
    this->_snakeBodyPos.push_back({15, 34});
    this->_snakeBodyPos.push_back({15, 33});
    this->_snakeBodyPos.push_back({15, 32});
    this->addFruit();
    this->setDisplayedMap(this->getMap());
}

void arcade::game::Nibbler::update(void)
{
    short nextCase = 1;
    std::pair<std::size_t, std::size_t> prevBody;
    size_t place = this->_size;

    if (this->_health == 0)
        return;
    for (; place > 0; place--) {
        prevBody = this->getBodyPos(place - 1);
        this->_snakeBodyPos[place].second = prevBody.second;
        this->_snakeBodyPos[place].first = prevBody.first;
    }

    try {
        snakeDirection();
        nextCase = this->isFreeSpace(this->_snakeBodyPos[0].first, this->_snakeBodyPos[0].second);
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Error while moving the snake" << std::endl;
    }

    if (nextCase == 1) {
        this->_health = 0;
    } else if (nextCase == 2) {
        if (this->addBodyPart() == false) {
            this->_health = 0;
        }
        this->addFruit();
        this->_multiplicator += 0.5;
        this->_score += 10 * this->_multiplicator;
        this->_size++;
    }
}

std::vector<std::string> arcade::game::Nibbler::getDatas(void)
{
    std::vector<std::string> datas;
    std::vector<std::string> map = this->getMap();
    std::vector<std::pair<std::size_t, std::size_t>> snakePart = this->getBodyPos();

    datas.push_back(std::to_string(this->_score));
    datas.push_back(std::to_string(this->_health));

    map[snakePart[0].first][snakePart[0].second] = 'H';
    for (std::size_t snakePartPos = 1; snakePartPos < snakePart.size(); snakePartPos++) {
        map[snakePart[snakePartPos].first][snakePart[snakePartPos].second] = 'Q';
    }
    map[this->_fruitsPos.first][this->_fruitsPos.second] = 'F';
    datas.insert(datas.end(), map.begin(), map.end());
    this->setDisplayedMap(map);
    return (datas);
}

void arcade::game::Nibbler::setInput(arcade::KeyboardKeys input)
{
    if (input == ARROW_R || input == ARROW_L) {
        this->_input = input;
    } else
        this->_input = NONE;
}

//-----------------------End of template functions-----------------------------

//--------------------Non class or template function---------------------------



//------------------Enf of non class or template function----------------------

//------------------------Nibbler's class function-----------------------------

bool arcade::game::Nibbler::read_map(std::string file)
{
    std::fstream map_content(file);
    std::vector<std::string> map;

    if (map_content.is_open() == false) {
        std::cerr << file + ": cannot open the file" << std::endl;
        return (false);
    } else {
        while (std::getline(map_content, file)) {
            map.push_back(file);
        }
    }
    this->setMap(map);
    return (true);
}

void arcade::game::Nibbler::snakeDirection(void)
{
    if (this->_input != NONE) {
        if (this->_input == ARROW_R) {
            if (this->_direction == ARROW_U) {
                this->_direction = ARROW_R;
            } else if (this->_direction == ARROW_R) {
                this->_direction = ARROW_D;
            } else if (this->_direction == ARROW_D) {
                this->_direction = ARROW_L;
            } else {
                this->_direction = ARROW_U;
            }
        } else {
            if (this->_direction == ARROW_U) {
                this->_direction = ARROW_L;
            } else if (this->_direction == ARROW_R) {
                this->_direction = ARROW_U;
            } else if (this->_direction == ARROW_D) {
                this->_direction = ARROW_R;
            } else {
                this->_direction = ARROW_D;
            }
        }
    }

    switch (this->_direction) {
        case (ARROW_R):
            this->_snakeBodyPos[0].second++;
            break;
        case (ARROW_U):
            this->_snakeBodyPos[0].first--;
            break;
        case (ARROW_D):
            this->_snakeBodyPos[0].first++;
            break;
        case (ARROW_L):
            this->_snakeBodyPos[0].second--;
            break;
        default:
            break;
    }
}

std::size_t arcade::game::Nibbler::getSize(void) const
{
    return (this->_size);
}

std::pair<std::size_t, std::size_t> arcade::game::Nibbler::getBodyPos(std::size_t part)
{
    return (this->_snakeBodyPos[part]);
}

std::vector<std::pair<std::size_t, std::size_t>> arcade::game::Nibbler::getBodyPos(void) const
{
    return (this->_snakeBodyPos);
}

bool arcade::game::Nibbler::addBodyPart(void)
{
    std::pair<std::size_t, std::size_t> prev = this->getBodyPos(this->_size);

    if (this->isFreeSpace(prev.first - 1, prev.second) == 0) {
        this->_snakeBodyPos.push_back({prev.first - 1, prev.second});
        return (true);
    }
    if (this->isFreeSpace(prev.first + 1, prev.second) == 0) {
        this->_snakeBodyPos.push_back({prev.first + 1, prev.second});
        return (true);
    }
    if (this->isFreeSpace(prev.first, prev.second - 1) == 0) {
        this->_snakeBodyPos.push_back({prev.first, prev.second - 1});
        return (true);
    }
    if (this->isFreeSpace(prev.first, prev.second + 1) == 0) {
        this->_snakeBodyPos.push_back({prev.first, prev.second + 1});
        return (true);
    }
    return (false);
}

void arcade::game::Nibbler::addFruit(void)
{
    std::size_t pos_x = 0;
    std::size_t pos_y = 0;
    bool is_free = true;
    unsigned short placedFruits = 0;

    do {
        pos_x = rand() % 68 + 1;
        pos_y = rand() % 28 + 1;
        for (std::pair<std::size_t, std::size_t> body : this->_snakeBodyPos) {
            if (pos_x == body.second && pos_y == body.first) {
                is_free = false;
                break;
            }
        }
        if (isFreeSpace(pos_y, pos_x) == 0) {
            this->_fruitsPos = {pos_y, pos_x};
            placedFruits++;
        }
    } while (is_free == false);
}

void arcade::game::Nibbler::getHardMap(void)
{
    std::vector<std::string> map;
    map.push_back("######################################################################");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                #                    #                              #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#              #                                    #                #");
    map.push_back("#              #                                    #                #");
    map.push_back("#              #                                    #                #");
    map.push_back("#              #                                    #                #");
    map.push_back("#              #                                    #                #");
    map.push_back("#              #                                    #                #");
    map.push_back("#              #                                    #                #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#          #                #         #         #               #    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("#                                                                    #");
    map.push_back("######################################################################");
    this->setMap(map);
}

//----------------------Enf of Nibbler's class function------------------------


extern "C" std::shared_ptr<arcade::game::Nibbler> entryPoint(void)
{
    return std::make_shared<arcade::game::Nibbler>();
}

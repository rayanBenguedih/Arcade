/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** The Pacman game
*/

#include <time.h>
#include <math.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>
#include <memory>
#include "../include/pacman.hpp"

//---------------------------Template functions--------------------------------

arcade::game::Pacman::Pacman(void)
{
    this->_keyMap.push_back({"GO UP", "ARROW UP"});
    this->_keyMap.push_back({"GO DOWN", "ARROW DOWN"});
    this->_keyMap.push_back({"GO RIGHT", "ARROW RIGHT"});
    this->_keyMap.push_back({"GO LEFT", "ARROW LEFT"});
    this->_health = 3;

    srand(time(0));
    if (read_map("./map/Pacman/map.txt") == false)
        this->getHardMap();
    for (int i = 0; i < 4; i++)
        this->_ghosts.push_back({0, 0});
    this->resetPacman(this->getMap(), true);
    this->_ghostsBasePos = this->_ghosts;
}

void arcade::game::Pacman::update(void)
{
    std::pair<std::size_t, std::size_t> pacManPos = getPacmanPos();
    std::vector<std::string> map = this->getDisplayedMap();

    if (this->_health == 0)
        return;
    try {

        if (((float) (clock() - this->_clock) / CLOCKS_PER_SEC) >= 10.0) {
            for (int i = 0; i < 4; i++)
                this->_isVulne[i] = false;
        }
        map[pacManPos.first][pacManPos.second] = ' ';
        this->setDisplayedMap(map);
        this->moveGhosts();
        pacmanDirection();
    } catch (const std::exception &e) {
        std::cerr << e.what() << std::endl;
        std::cerr << "Error while moving Pacman" << std::endl;
    }
}

std::vector<std::string> arcade::game::Pacman::getDatas(void)
{
    std::vector<std::string> datas;
    std::vector<std::string> map = this->getDisplayedMap();

    datas.push_back(std::to_string(this->_score));
    datas.push_back(std::to_string(this->_health));
    this->placeMovingElements(false);
    map = this->getDisplayedMap();
    datas.insert(datas.end(), map.begin(), map.end());
    return (datas);
}

void arcade::game::Pacman::setInput(arcade::KeyboardKeys input)
{
    if (input == ARROW_R || input == ARROW_L || input == ARROW_D || input == ARROW_U) {
        this->_input = input;
    } else if (input == KEY_R) {
        this->resetPacman(this->getMap(), true);
    } else {
        this->_input = NONE;
    }
}

//-----------------------End of template functions-----------------------------


//------------------------Pacman's class function-----------------------------

bool arcade::game::Pacman::read_map(std::string file)
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

void arcade::game::Pacman::decideMovement(short nextCase, std::pair<short, short> movement)
{
    bool bad = false;
    int scoreToAdd = 0;

    switch (nextCase) {
        case (6):
            nextCase = 0;
            this->updateGhost(this->_pacman.first + movement.first, this->_pacman.second + movement.second);
            for (int i = 0; i < 4; i++) {
                if (this->_isVulne[i] == false) {
                    if (scoreToAdd == 0)
                        scoreToAdd = 200;
                    else
                        scoreToAdd += scoreToAdd;
                    nextCase++;
                }
            }
            break;
        case (5):
            this->_health--;
            resetPacman(this->getMap(), false);
            this->_ghosts = this->_ghostsBasePos;
            bad = true;
            break;
        case (4):
            this->_clock = clock();
            for (int i = 0; i < 4; i++)
                this->_isVulne[i] = true;
            scoreToAdd += 50;
            break;
        case (3):
            scoreToAdd += 10;
            break;
        case (0):
            break;
        default:
            bad = true;
            break;
    }

    if (bad == false) {
        this->_pacman.first += movement.first;
        this->_pacman.second += movement.second;
    }
    this->_score += scoreToAdd;
}

void arcade::game::Pacman::pacmanDirection(void)
{
    short nextCase = 1;
    std::pair<short, short> movement = {0, 0};

    if (this->_input != NONE) {
        this->_direction = this->_input;
        this->_input = NONE;
    }

    switch (this->_direction) {
        case (ARROW_R):
            movement.second++;
            break;
        case (ARROW_U):
            movement.first--;
            break;
        case (ARROW_D):
            movement.first++;
            break;
        case (ARROW_L):
            movement.second--;
            break;
        default:
            break;
    }
    nextCase = this->isFreeSpace(this->_pacman.first + movement.first, this->_pacman.second + movement.second);

    if (this->_pacman.first == 11 && this->_pacman.second == 27 && movement.second == 1) {
        this->_pacman.second = 0;
        movement = {0, 0};
    } else if (this->_pacman.first == 11 && this->_pacman.second == 0 && movement.second == -1) {
        this->_pacman.second = 27;
        movement = {0, 0};
    }
    decideMovement(nextCase, movement);
}

std::pair<std::size_t, std::size_t> arcade::game::Pacman::getPacmanPos(void) const
{
    return (this->_pacman);
}

void arcade::game::Pacman::getHardMap(void)
{
    std::vector<std::string> map;
    map.push_back("############################");  // 0
    map.push_back("#Oooooooooooo##oooooooooooO#");  // 1
    map.push_back("#o####o#####o##o#####o####o#");  // 2
    map.push_back("#o####o#####o##o#####o####o#");  // 3
    map.push_back("#oooooooooooooooooooooooooo#");  // 4
    map.push_back("#o####o##o########o##o####o#");  // 5
    map.push_back("#oooooo##oooo##oooo##oooooo#");  // 6
    map.push_back("######o#####o##o#####o######");  // 7
    map.push_back("     #o##oooo##oooo##o#     ");  // 8
    map.push_back("     #o##ooooRooooo##o#     ");  // 9
    map.push_back("######o##o###DD###o##o######");  // 10
    map.push_back("oooooooooo# BVJ  #oooooooooo");  // 11
    map.push_back("######o##o########o##o######");  // 12
    map.push_back("     #o##ooooPooooo##o#     ");  // 13
    map.push_back("     #o##oooo##oooo##o#     ");  // 14
    map.push_back("######o##o########o##o######");  // 15
    map.push_back("#oooooooooooo##oooooooooooo#");  // 16
    map.push_back("#o####o#####o##o#####o####o#");  // 17
    map.push_back("#ooo##oooooooooooooooo##ooo#");  // 18
    map.push_back("###o##o##o########o##o##o###");  // 19
    map.push_back("#oooooo##oooo##oooo##oooooo#");  // 20
    map.push_back("#o##########o##o##########o#");  // 21
    map.push_back("#OooooooooooooooooooooooooO#");  // 22
    map.push_back("############################");  // 23
    this->setMap(map);
}

void arcade::game::Pacman::resetPacman(std::vector<std::string> map, bool init)
{
    this->_isVulne.clear();
    this->_underGhost.clear();
    this->_clock = 0;

    for (int i = 0; i < 4; i++) {
        this->_isVulne.push_back(false);
        this->_underGhost.push_back(' ');
    }

    if (init == false) {
        for (int i = 0; i < 4; i++) {
            this->updateMap(this->_ghosts[i].first, this->_ghosts[i].second, this->_underGhost[i]);
        }
    }

    for (std::size_t y = 0; y < map.size(); y++) {
        for (std::size_t x = 0; x < map[y].size(); x++) {
            switch (map[y][x]) {
                case ('P'):
                    this->_pacman = {y, x};
                    map[y][x] = ' ';
                    break;
                case ('V'):
                    this->_ghosts[0] = {y, x};
                    map[y][x] = ' ';
                    break;
                case ('B'):
                    this->_ghosts[1] = {y, x};
                    map[y][x] = ' ';
                    break;
                case ('R'):
                    this->_ghosts[2] = {y, x};
                    map[y][x] = ' ';
                    break;
                case ('J'):
                    this->_ghosts[3] = {y, x};
                    map[y][x] = ' ';
                    break;
                case ('o'): case ('O'):
                    this->_pacgome++;
                    break;
                default:
                    break;
            }
        }
    }
    if (init == true)
        this->setDisplayedMap(map);
}

void arcade::game::Pacman::updateGhost(size_t y, size_t x)
{
    for (short ghost = 0; ghost < 4; ghost++) {
        if (this->_ghosts[ghost].first == y && this->_ghosts[ghost].second == x) {
            this->_isVulne[ghost] = false;
            this->_ghosts[ghost].first = this->_ghostsBasePos[ghost].first;
            this->_ghosts[ghost].second = this->_ghostsBasePos[ghost].second;
            this->_underGhost[ghost] = ' ';
        }
    }
}

void arcade::game::Pacman::moveGhosts(void)
{
    std::pair<short, short> movement = {0, 0};
    short nextCase = 1;
    std::vector<std::string> map = this->getDisplayedMap();
    char tmp = ' ';

    for (int i = 0; i < 4; i++) {
        nextCase = rand() % 4;

        switch (nextCase) {
            case (0):
                movement = {1, 0};
                break;
            case (1):
                movement = {0, 1};
                break;
            case (2):
                movement = {-1, 0};
                break;
            default:
                movement = {0, -1};
                break;
        }

        nextCase = this->isFreeSpace(this->_ghosts[i].first + movement.first, this->_ghosts[i].second + movement.second);

        if (nextCase == 1 || nextCase == 5 || (nextCase == 7 && movement.first == 1))
            continue;

        this->updateMap(this->_ghosts[i].first, this->_ghosts[i].second, this->_underGhost[i]);
        if (this->_ghosts[i].first == 11 && this->_ghosts[i].second == 27 && movement.second == 1) {
            this->_ghosts[i].second = 0;
        } else if (this->_ghosts[i].first == 11 && this->_ghosts[i].second == 0 && movement.second == -1) {
            this->_ghosts[i].second = 27;
        } else {
            this->_ghosts[i].first += movement.first;
            this->_ghosts[i].second += movement.second;
        }

        if (this->_pacman.first == this->_ghosts[i].first && this->_pacman.second == this->_ghosts[i].second) {
            this->_health--;
            resetPacman(this->getMap(), false);
            this->_ghosts = this->_ghostsBasePos;
            return;
        }

        tmp = map[this->_ghosts[i].first][this->_ghosts[i].second];
        if (tmp == 'o' || tmp == 'O' || tmp == 'D')
            this->_underGhost[i] = tmp;
        else
            this->_underGhost[i] = ' ';
    }
    this->placeMovingElements(true);
}

void arcade::game::Pacman::placeMovingElements(bool ghost)
{
    std::pair<std::size_t, std::size_t> pac = this->getPacmanPos();
    std::vector<std::string> map = this->getDisplayedMap();

    if (ghost == false) {
        map[pac.first][pac.second] = 'P';
    } else {
        for (int i = 0; i < 4; i++) {
            if (this->_isVulne[i] == true) {
                map[this->_ghosts[i].first][this->_ghosts[i].second] = 'U';
            } else {
                map[this->_ghosts[i].first][this->_ghosts[i].second] = this->_ghostOrder[i];
            }
        }
    }
    this->setDisplayedMap(map);
}

//----------------------Enf of Pacman's class function------------------------


extern "C" std::shared_ptr<arcade::game::Pacman> entryPoint(void)
{
    return std::make_shared<arcade::game::Pacman>();
}

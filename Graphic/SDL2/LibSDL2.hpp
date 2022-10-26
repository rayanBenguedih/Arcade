/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** LibSDL2
*/

#ifndef LIBSDL2_HPP_
#define LIBSDL2_HPP_

#include <iostream>
#include <map>
#include <unordered_map>
#include <memory>
#include <chrono>
#include <thread>

#include "Sdl.hpp"
#include "../../Displayer/IDisplayer.hpp"
#include "../../Game/IGame.hpp"

class LibSDL2 : public SDL, public arcade::displayer::IDisplayer {
    public:
        LibSDL2();
        ~LibSDL2();

        void drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths);
        void drawGame(std::vector<std::string> map);
        
        void loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath);
        void loadGameAssets(std::string actualGamePath, std::vector<std::string> map);

        void destroyWindow(void);

        bool isRunning(void);

        arcade::KeyboardKeys getInput(void);

        std::string getName(void);
        void fillVectorGame(std::vector<std::string> paths);
        void fillVectorGraph(std::vector<std::string> paths);
        void launchButton(void);
        void clearSurface(std::vector<SDL_Surface *> &s) const;
        void clearTexture(std::vector<SDL_Texture *> &t) const;
        void clearRect(std::vector<SDL_Rect> &r) const;
        void _setNewPos(std::vector<std::string> map);
        void _resetEnemyPos(void);
        void _resetItemPos(void);
        void _updateRectPos(std::vector<std::string> map);
        void _textureProblem(void);


        SDL_Rect createRect(int i, int j, size_t sizeX, size_t sizeY) const;

    protected:
        std::string _libName;
        bool _isRunning;
        std::pair<int, int> _playerPos;
        std::pair<int, int> _playerPosOld;
        std::vector<std::pair<int , int>> _bodyPos;
        std::vector<std::pair<int , int>> _bodyPosOld;
        std::unordered_map<char, std::pair<int, int>> _enemiesPos;
        std::unordered_map<char, std::pair<int, int>> _enemiesPosOld;
        std::unordered_map<char, std::vector<std::pair<int, int>>> _itemsPos;
        std::unordered_map<char, std::vector<std::pair<int, int>>> _itemsPosOld;
        bool _isU;
        bool _spriteSheetLoaded;

        Mix_Music *_music; // destroy

        SDL_Surface *_problemSurface; // destroy
        SDL_Texture *_problemTexture; // destroy
        SDL_Rect _problemRect; // clear

        std::vector<SDL_Surface *> _controlSurface; // destroy
        std::vector<SDL_Texture *> _controlTexture; // destroy
        std::vector<SDL_Rect> _controlRect; // clear

        SDL_Window *_win; // destroy
        SDL_Renderer *_renderer; // destroy
        SDL_Event _events; // NONE
        TTF_Font *_font; // destroy (segfault)

        SDL_Color _colorTitle;
        SDL_Rect _rectTitle;

        SDL_Surface *_transparent;  // destroy

        SDL_Rect _rectGraphBackground;
        SDL_Rect _rectGraph;
        SDL_Color _colorGame;
        std::vector<SDL_Texture *> _graphTextures; // destroy
        std::vector<SDL_Surface *> _graphSurfaces; // destroy
        std::vector<SDL_Rect> _graphTextRects; // clear

        SDL_Rect _rectGameBackground;
        SDL_Rect _rectGame;
        SDL_Color _colorGraph;
        std::vector<SDL_Texture *> _gameTextures; // destroy
        std::vector<SDL_Surface *> _gameSurfaces; // destroy
        std::vector<SDL_Rect> _gameTextRects; // clear

        SDL_Color _colorLaunch;
        SDL_Rect _rectLaunch;
        SDL_Surface *_launchSurface; // destroy
        SDL_Texture *_launchTexture; // destroy

        SDL_Surface *_scoreSurface; // destroy
        SDL_Texture *_scoreTexture; // destroy
        SDL_Rect _scoreRect;

        SDL_Surface *_healthSurface; // destroy
        SDL_Texture *_healthTexture; // destroy
        SDL_Rect _healthRect; // NONE

        SDL_Surface *_titleSurface; // destroy
        SDL_Texture *_titleTexture; // destroy
        SDL_Surface *_menuBckgdSurface; // destroy
        SDL_Surface *_gameBckgdSurface; // destroy
        SDL_Texture *_menuBckgdTexture; // destroy
        SDL_Texture *_gameBckgdTexture; // destroy

        arcade::KeyboardKeys _input;
        std::map<SDL_Keycode, arcade::KeyboardKeys> _keys;
        std::string _actualGame;

        std::vector<SDL_Rect> _actualGameMap;

        struct _mouseositions {
            int x;
            int y;
        } _mousePos;

        SDL_Surface *_spriteSheet; // destroy
        SDL_Texture *_spriteSheetTexture; // destroy

        SDL_Texture *_wallTexture; // destroy
        SDL_Surface *_wallSurface; // destroy
        std::vector<SDL_Rect> _wallRect; // clear

        SDL_Rect _doorRectSurface; // NONE
        std::vector<SDL_Rect> _doorRect; // clear

        SDL_Rect _playerSurfaceRect; // NONE
        SDL_Rect _playerRect; // NONE

        std::vector<SDL_Rect> _bodySurfaceRect; // clear
        std::vector<SDL_Rect> _bodyRect; // clear

        std::unordered_map<char, SDL_Rect> _ennemySurfaceRect;
        std::unordered_map<char, SDL_Rect> _ennemyRects;

        std::vector<SDL_Rect> _itemSurfaceRect;
        std::vector<SDL_Rect> _itemRects;

        std::vector<SDL_Rect> _specialRect;
        std::vector<SDL_Rect> _specialSurfaceRect;
};

#endif /* !LIBSDL2_HPP_ */
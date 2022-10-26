/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** LibSDL2
*/

#include "LibSDL2.hpp"

LibSDL2::LibSDL2()
{

    #if SDL_BYTEORDER == SDL_BIG_ENDIAN
        Uint32 rmask = 0xff000000;
        Uint32 gmask = 0x00ff0000;
        Uint32 bmask = 0x0000ff00;
        Uint32 amask = 0x000000ff;
    #else
        Uint32 rmask = 0x000000ff;
        Uint32 gmask = 0x0000ff00;
        Uint32 bmask = 0x00ff0000;
        Uint32 amask = 0xff000000;
    #endif

    this->_libName = "SDL2";
    this->_win = NULL;
    this->_renderer = NULL;
    this->_font = NULL;
    this->_titleSurface = NULL;
    this->_rectTitle = {575, 10, 0, 0};

    this->_rectGame = {150, 300, 500, 700};
    this->_rectGraph = {1220, 300, 500, 700};

    this->_titleTexture = NULL;
    this->_menuBckgdSurface = NULL;
    this->_menuBckgdTexture = NULL;
    this->_gameBckgdSurface = NULL;
    this->_gameBckgdTexture = NULL;
    this->_colorTitle = {196, 22, 167, 255};
    this->_colorGame = {255, 255, 255, 255};
    this->_colorGraph = {255, 255, 255, 255};
    this->_transparent = _SDL_CreateRGBSurface(0, 50, 50, 32, rmask, gmask, bmask, amask);

    this->_launchSurface = NULL;
    this->_launchTexture = NULL;
    this->_rectLaunch = {735, 950, 400, 50};
    this->_colorLaunch = {0, 0, 0, 255};

    this->_scoreSurface = NULL;
    this->_scoreTexture = NULL;
    this->_scoreRect.x = 0;
    this->_scoreRect.y = 0;
    this->_scoreRect.w = 300;
    this->_scoreRect.h = 20;

    this->_healthSurface = NULL;
    this->_healthTexture = NULL;
    this->_healthRect.x = 0;
    this->_healthRect.y = 30;
    this->_healthRect.w = 150;
    this->_healthRect.h = 20;

    this->_doorRectSurface = {913, 156, 52, 14};
    this->_problemRect = {1440, 10, 0, 0};

    this->_mousePos = {0, 0};

    this->_wallSurface = NULL;
    this->_wallTexture = NULL;

    this->_isRunning = false;
    this->_isU = false;
    this->_input = arcade::NONE;

    this->_music = NULL;

    this->_enemiesPos.insert(std::pair<char, std::pair<int, int>>('R', {-1, -1}));
    this->_enemiesPos.insert(std::pair<char, std::pair<int, int>>('B', {-1, -1}));
    this->_enemiesPos.insert(std::pair<char, std::pair<int, int>>('J', {-1, -1}));
    this->_enemiesPos.insert(std::pair<char, std::pair<int, int>>('V', {-1, -1}));

    this->_itemsPos.insert(std::pair<char, std::vector<std::pair<int, int>>>('O', {std::pair<int, int>{-1, -1}}));
    this->_itemsPos.insert(std::pair<char, std::vector<std::pair<int, int>>>('o', {std::pair<int, int>{-1, -1}}));
    this->_itemsPos.insert(std::pair<char, std::vector<std::pair<int, int>>>('F', {std::pair<int, int>{-1, -1}}));

    this->_ennemyRects.insert(std::pair<char, SDL_Rect>('R', {0, 0, 0, 0}));
    this->_ennemyRects.insert(std::pair<char, SDL_Rect>('B', {0, 0, 0, 0}));
    this->_ennemyRects.insert(std::pair<char, SDL_Rect>('J', {0, 0, 0, 0}));
    this->_ennemyRects.insert(std::pair<char, SDL_Rect>('V', {0, 0, 0, 0}));
    this->_ennemyRects.insert(std::pair<char, SDL_Rect>('U', {0, 0, 0, 0}));

    this->_ennemySurfaceRect.insert(std::pair<char, SDL_Rect>('R', {0, 0, 0, 0}));
    this->_ennemySurfaceRect.insert(std::pair<char, SDL_Rect>('B', {0, 0, 0, 0}));
    this->_ennemySurfaceRect.insert(std::pair<char, SDL_Rect>('J', {0, 0, 0, 0}));
    this->_ennemySurfaceRect.insert(std::pair<char, SDL_Rect>('V', {0, 0, 0, 0}));
    this->_ennemySurfaceRect.insert(std::pair<char, SDL_Rect>('U', {0, 0, 0, 0}));

    this->_keys.insert({SDLK_a, arcade::KEY_A});
    this->_keys.insert({SDLK_b, arcade::KEY_B});
    this->_keys.insert({SDLK_c, arcade::KEY_C});
    this->_keys.insert({SDLK_d, arcade::KEY_D});
    this->_keys.insert({SDLK_e, arcade::KEY_E});
    this->_keys.insert({SDLK_f, arcade::KEY_F});
    this->_keys.insert({SDLK_g, arcade::KEY_G});
    this->_keys.insert({SDLK_h, arcade::KEY_H});
    this->_keys.insert({SDLK_i, arcade::KEY_I});
    this->_keys.insert({SDLK_j, arcade::KEY_J});
    this->_keys.insert({SDLK_k, arcade::KEY_K});
    this->_keys.insert({SDLK_l, arcade::KEY_L});
    this->_keys.insert({SDLK_m, arcade::KEY_M});
    this->_keys.insert({SDLK_n, arcade::KEY_N});
    this->_keys.insert({SDLK_o, arcade::KEY_O});
    this->_keys.insert({SDLK_p, arcade::KEY_P});
    this->_keys.insert({SDLK_q, arcade::KEY_Q});
    this->_keys.insert({SDLK_r, arcade::KEY_R});
    this->_keys.insert({SDLK_s, arcade::KEY_S});
    this->_keys.insert({SDLK_t, arcade::KEY_T});
    this->_keys.insert({SDLK_u, arcade::KEY_U});
    this->_keys.insert({SDLK_v, arcade::KEY_V});
    this->_keys.insert({SDLK_w, arcade::KEY_W});
    this->_keys.insert({SDLK_x, arcade::KEY_X});
    this->_keys.insert({SDLK_y, arcade::KEY_Y});
    this->_keys.insert({SDLK_z, arcade::KEY_Z});
    this->_keys.insert({SDLK_0, arcade::NUMBER_0});
    this->_keys.insert({SDLK_1, arcade::NUMBER_1});
    this->_keys.insert({SDLK_2, arcade::NUMBER_2});
    this->_keys.insert({SDLK_3, arcade::NUMBER_3});
    this->_keys.insert({SDLK_4, arcade::NUMBER_4});
    this->_keys.insert({SDLK_5, arcade::NUMBER_5});
    this->_keys.insert({SDLK_6, arcade::NUMBER_6});
    this->_keys.insert({SDLK_7, arcade::NUMBER_7});
    this->_keys.insert({SDLK_8, arcade::NUMBER_8});
    this->_keys.insert({SDLK_9, arcade::NUMBER_9});
    this->_keys.insert({SDLK_UP, arcade::ARROW_U});
    this->_keys.insert({SDLK_DOWN, arcade::ARROW_D});
    this->_keys.insert({SDLK_LEFT, arcade::ARROW_L});
    this->_keys.insert({SDLK_RIGHT, arcade::ARROW_R});
}

LibSDL2::~LibSDL2() {}

void LibSDL2::clearTexture(std::vector<SDL_Texture *> &textures) const
{
    for (auto texture : textures) {
        _SDL_DestroyTexture(texture);
    }
    textures.clear();
}

void LibSDL2::clearSurface(std::vector<SDL_Surface *> &surfaces) const
{
    for (auto surface : surfaces) {
        _SDL_DestroySurface(surface);
    }
    surfaces.clear();
}

void LibSDL2::clearRect(std::vector<SDL_Rect> &rects) const
{
    rects.clear();
}

void LibSDL2::fillVectorGame(std::vector<std::string> paths)
{
    int start = 300 + 100;
    this->_colorGame.a = 255;
    this->_colorGame.r = rand() % 255;
    this->_colorGame.g = rand() % 255;
    this->_colorGame.b = rand() % 255;

    this->clearSurface(this->_gameSurfaces);
    this->clearTexture(this->_gameTextures);
    this->clearRect(this->_gameTextRects);

    this->_gameSurfaces.push_back(_TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, "Games"));
    this->_gameTextures.push_back(_SDL_CreateTextureFromSurface(this->_renderer, this->_gameSurfaces[0]));
    int middle = this->_rectGame.w / 2 + this->_rectGame.x - 230;
    this->_gameTextRects.push_back({310, 300, 200, 100});

    for (std::size_t i = 0; i != paths.size(); i++) {
        if (strcasecmp(paths[i].c_str(), this->_actualGame.c_str()) == 0)
            this->_gameSurfaces.push_back(_TTF_RenderText_Solid(this->_font, this->_colorGame, paths[i].c_str()));
        else
            this->_gameSurfaces.push_back(_TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, paths[i].c_str()));
        this->_gameTextures.push_back(_SDL_CreateTextureFromSurface(this->_renderer, this->_gameSurfaces[i + 1]));
        this->_gameTextRects.push_back({middle, start, 200, 50});
        start += 50;
    }
}

void LibSDL2::fillVectorGraph(std::vector<std::string> paths)
{
    int start = 300 + 100;
    this->_colorGraph.a = 255;
    this->_colorGraph.r = rand() % 255;
    this->_colorGraph.g = rand() % 255;
    this->_colorGraph.b = rand() % 255;

    this->clearSurface(this->_graphSurfaces);
    this->clearTexture(this->_graphTextures);
    this->clearRect(this->_graphTextRects);

    this->_graphSurfaces.push_back(_TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, "Graphical libraries"));
    this->_graphTextures.push_back(_SDL_CreateTextureFromSurface(this->_renderer, this->_graphSurfaces[0]));
    this->_graphTextRects.push_back({1260, 300, 400, 100});

    for (std::size_t i = 0; i != paths.size(); i++) {
        if (strcasecmp(paths[i].c_str(), this->_libName.c_str()) == 0)
            this->_graphSurfaces.push_back(_TTF_RenderText_Solid(this->_font, this->_colorGraph, paths[i].c_str()));
        else
            this->_graphSurfaces.push_back(_TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, paths[i].c_str()));
        this->_graphTextures.push_back(_SDL_CreateTextureFromSurface(this->_renderer, this->_graphSurfaces[i + 1]));
        this->_graphTextRects.push_back({1240, start, 200, 50});
        start += 50;
    }
}

void LibSDL2::drawMenu(std::vector<std::string> gamesPaths, std::vector<std::string> displayersPaths)
{
    this->fillVectorGame(gamesPaths);
    this->fillVectorGraph(displayersPaths);

    _SDL_RenderClear(this->_renderer);
    _SDL_RenderCopy(this->_renderer, this->_menuBckgdTexture, NULL, NULL);
    _SDL_RenderCopy(this->_renderer, this->_titleTexture, NULL, &this->_rectTitle);
    _SDL_RenderCopy(this->_renderer, this->_launchTexture, NULL, &this->_rectLaunch);
    _SDL_RenderFillRect(this->_renderer, this->_rectGame);
    _SDL_RenderFillRect(this->_renderer, this->_rectGraph);

    for (size_t i = 0; i != this->_gameTextures.size(); i++)
        _SDL_RenderCopy(this->_renderer, this->_gameTextures[i], NULL, &this->_gameTextRects[i]);
    
    for (size_t i = 0; i != this->_graphTextures.size(); i++)
        _SDL_RenderCopy(this->_renderer, this->_graphTextures[i], NULL, &this->_graphTextRects[i]);

    _SDL_RenderPresent(this->_renderer);

    while (_SDL_PollEvent(&this->_events) == 1)
    {
        if (this->_events.type == SDL_QUIT)
            this->_isRunning = false;

        if (this->_events.button.button == SDL_BUTTON_LEFT)
        {
            this->_mousePos.x = this->_events.button.x;
            this->_mousePos.y = this->_events.button.y;
            if (this->_rectLaunch.x < this->_mousePos.x && this->_mousePos.x < this->_rectLaunch.x + this->_rectLaunch.w &&
                this->_rectLaunch.y < this->_mousePos.y && this->_mousePos.y < this->_rectLaunch.y + this->_rectLaunch.h) {
                this->_input = arcade::KEY_L;
                return;
            }
        }

        if (this->_events.type == SDL_KEYDOWN)
            if (this->_keys.count(this->_events.key.keysym.sym))
            {
                this->_input = this->_keys.at(this->_events.key.keysym.sym);
                return;
            }
    }
    this->_input = arcade::NONE;
}

void LibSDL2::_resetEnemyPos(void)
{
    this->_enemiesPos['R'] = {-1, -1};
    this->_enemiesPos['J'] = {-1, -1};
    this->_enemiesPos['B'] = {-1, -1};
    this->_enemiesPos['V'] = {-1, -1};
}

void LibSDL2::_resetItemPos(void)
{
    this->_itemsPos['O'].clear();
    this->_itemsPos['o'].clear();
    this->_itemsPos['F'].clear();
}

void LibSDL2::_setNewPos(std::vector<std::string> map)
{
    this->_resetEnemyPos();
    this->_resetItemPos();
    this->_bodyPosOld = this->_bodyPos;
    this->_itemsPos.clear();
    size_t nbrOfU = 0;

    this->_isU = false;
    this->_bodyPos.clear();

    for (size_t i = 2; i != map.size(); i++) {
        for (size_t j = 0; j != map[i].size(); j++) {
            if (map[i][j] == 'R' || (nbrOfU == 0 && map[i][j] == 'U')) {
                this->_enemiesPosOld = this->_enemiesPos;
                this->_enemiesPos['R'] = {j, i};
                if (map[i][j] == 'U') {
                    nbrOfU++;
                    this->_isU = true;
                }
            }
            if (map[i][j] == 'J' || (nbrOfU == 1 && map[i][j] == 'U')) {
                this->_enemiesPosOld = this->_enemiesPos;
                this->_enemiesPos['J'] = {j, i};
                if (map[i][j] == 'U')
                    nbrOfU++;
            }
            if (map[i][j] == 'B' || (nbrOfU == 2 && map[i][j] == 'U')) {
                this->_enemiesPosOld = this->_enemiesPos;
                this->_enemiesPos['B'] = {j, i};
                if (map[i][j] == 'U')
                    nbrOfU++;
            }
            if (map[i][j] == 'V' || (nbrOfU == 3 && map[i][j] == 'U')) {
                this->_enemiesPosOld = this->_enemiesPos;
                this->_enemiesPos['V'] = {j, i};
                if (map[i][j] == 'U')
                    nbrOfU++;
            }
            if (map[i][j] == 'Q') {
                this->_bodyPos.push_back({j, i});
            }
            if (map[i][j] == 'O' || map[i][j] == 'o' || map[i][j] == 'F') {
                this->_itemsPosOld = this->_itemsPos;
                this->_itemsPos[map[i][j]].push_back({j, i});
            }
            if (map[i][j] == 'P' || map[i][j] == 'H') {
                this->_playerPosOld = this->_playerPos;
                this->_playerPos = {j, i};
            }
        }
    }
}

void LibSDL2::_updateRectPos(std::vector<std::string> map)
{
    // int sizeY = map[2].size();
    // int ratioY = 980 / sizeY;
    // int res = 0;

    this->_bodyRect.clear();
    this->_itemRects.clear();
    this->_specialRect.clear();
    int nbrofU = 0;

    for (size_t i = 2; i != map.size(); i++) {
        for (size_t j = 0; j != map[i].size(); j++) {
            if (map[i][j] == 'P' || map[i][j] == 'H') {
                this->_playerRect = createRect(j, i, map.size(), map[i].size());
                // res = this->_playerPos.first - this->_playerPosOld.first;
                // this->_playerRect.x = (res > 0) ? this->_playerRect.x + ratioY : this->_playerRect.x;
                // this->_playerRect.x = (res < 0) ? this->_playerRect.x - ratioY : this->_playerRect.x;
                // res = this->_playerPos.second - this->_playerPosOld.second;
                // this->_playerRect.y = (res > 0) ? this->_playerRect.y + ratioY : this->_playerRect.y;
                // this->_playerRect.y = (res < 0) ? this->_playerRect.y - ratioY : this->_playerRect.y;
            }

            if (map[i][j] == 'Q')
                this->_bodyRect.push_back(this->createRect(j, i, map.size(), map[i].size()));
            if (map[i][j] == 'R')
                this->_ennemyRects['R'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'J' || (nbrofU == 1 && map[i][j] == 'U'))
                this->_ennemyRects['J'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'B' || (nbrofU == 2 && map[i][j] == 'U'))
                this->_ennemyRects['B'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'V' || (nbrofU == 3 && map[i][j] == 'U'))
                this->_ennemyRects['V'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'F' || map[i][j] == 'o')
                this->_itemRects.push_back(this->createRect(j, i, map.size(), map[i].size()));
            if (map[i][j] == 'O')
                this->_specialRect.push_back(this->createRect(j, i, map.size(), map[i].size()));
            
            if (map[i][j] == 'U') {
                if (nbrofU == 0)
                    this->_ennemyRects['R'] = this->createRect(j, i, map.size(), map[i].size());
                else if (nbrofU == 1)
                    this->_ennemyRects['J'] = this->createRect(j, i, map.size(), map[i].size());
                else if (nbrofU == 2)
                    this->_ennemyRects['B'] = this->createRect(j, i, map.size(), map[i].size());
                else
                    this->_ennemyRects['V'] = this->createRect(j, i, map.size(), map[i].size());
                nbrofU++;
            }
        }
    }
    if (nbrofU > 0)
        this->_isU = true;
    else
        this->_isU = false;
}

void LibSDL2::_textureProblem(void)
{
    _SDL_RenderClear(this->_renderer);
    if (this->_problemSurface == NULL)
        this->_problemSurface = _TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, "PROBLEM WHEN TRYING TO LOAD THE SPRITESHEET!");
    if (this->_problemTexture == NULL)
        this->_problemTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_problemSurface);
    _SDL_RenderCopy(this->_renderer, this->_problemTexture, NULL, &this->_problemRect);
}

void LibSDL2::drawGame(std::vector<std::string> map)
{
    _SDL_RenderClear(this->_renderer);

    if (!this->_spriteSheetLoaded) {
        this->_textureProblem();
        return;
    }

    this->_setNewPos(map);
    this->_updateRectPos(map);
    size_t cpt = 0;

    for (size_t i = 0; i != this->_wallRect.size(); i++)
        _SDL_RenderCopy(this->_renderer, this->_wallTexture, NULL, &this->_wallRect[i]);

    for (size_t i = 0; i != this->_itemsPos['o'].size(); i++) {
        this->_itemRects[i].w /= 2;
        this->_itemRects[i].h /= 2;
        this->_itemRects[i].x += this->_itemRects[i].w / 2;
        this->_itemRects[i].y += this->_itemRects[i].h / 2;
        _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_itemSurfaceRect[0], &this->_itemRects[i]);
    }

    for (size_t i = 0; i != this->_itemsPos['O'].size(); i++)
        _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_specialSurfaceRect[0], &this->_specialRect[i]);

    for (size_t i = 0; i != this->_itemsPos['F'].size(); i++)
        _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_itemSurfaceRect[0], &this->_itemRects[i]);

    for (size_t i = 0; i != this->_bodyRect.size(); i++) {
        _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_bodySurfaceRect[cpt], &this->_bodyRect[i]);
        cpt = (cpt == 2) ? 0 : cpt + 1;
    }
    
    _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_playerSurfaceRect, &this->_playerRect);

    if (this->_enemiesPos['R'].first != -1) {
        if (this->_isU == true)
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['U'], &this->_ennemyRects['R']);
        else
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['R'], &this->_ennemyRects['R']);
    }

    if (this->_enemiesPos['J'].first != -1) {
        if (this->_isU == true)
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['U'], &this->_ennemyRects['J']);
        else
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['J'], &this->_ennemyRects['J']);
    }

    if (this->_enemiesPos['B'].first != -1) {
        if (this->_isU == true)
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['U'], &this->_ennemyRects['B']);
        else
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['B'], &this->_ennemyRects['B']);
    }

    if (this->_enemiesPos['V'].first != -1) {
        if (this->_isU == true)
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['U'], &this->_ennemyRects['V']);
        else
            _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_ennemySurfaceRect['V'], &this->_ennemyRects['V']);
    }

    if (this->_scoreSurface != NULL)
        _SDL_DestroySurface(this->_scoreSurface);
    std::string score = "SCORE: " + map[0];
    this->_scoreSurface = _TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, score.c_str());
    if (this->_scoreTexture != NULL)
        _SDL_DestroyTexture(this->_scoreTexture);
    this->_scoreTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_scoreSurface);

    if (this->_healthSurface != NULL)
        _SDL_DestroySurface(this->_healthSurface);
    std::string health = "HP: " + map[1];
    this->_healthSurface = _TTF_RenderText_Solid(this->_font, {255, 255, 255, 255}, health.c_str());
    if (this->_healthTexture != NULL)
        _SDL_DestroyTexture(this->_healthTexture);
    this->_healthTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_healthSurface);

    _SDL_RenderCopy(this->_renderer, this->_scoreTexture, NULL, &this->_scoreRect);
    _SDL_RenderCopy(this->_renderer, this->_healthTexture, NULL, &this->_healthRect);

    for (size_t i = 0; i != this->_doorRect.size(); i++)
        _SDL_RenderCopy(this->_renderer, this->_spriteSheetTexture, &this->_doorRectSurface, &this->_doorRect[i]);

    _SDL_RenderPresent(this->_renderer);

    while (_SDL_PollEvent(&this->_events) == 1)
    {
        if (this->_events.type == SDL_QUIT)
            this->_isRunning = false;

        if (this->_events.button.button == SDL_BUTTON_LEFT) {
            this->_mousePos.x = this->_events.button.x;
            this->_mousePos.y = this->_events.button.y;
            if (this->_rectLaunch.x < this->_mousePos.x && this->_mousePos.x < this->_rectLaunch.x + this->_rectLaunch.w &&
                this->_rectLaunch.y < this->_mousePos.y && this->_mousePos.y < this->_rectLaunch.y + this->_rectLaunch.h) {
                this->_input = arcade::KEY_L;
                return;
            }
        }

        if (this->_events.type == SDL_KEYDOWN)
            if (this->_keys.count(this->_events.key.keysym.sym))
            {
                this->_input = this->_keys.at(this->_events.key.keysym.sym);
                return;
            }
    }
    this->_input = arcade::NONE;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
}


SDL_Rect LibSDL2::createRect(int i, int j, size_t sizeX, size_t sizeY) const
{
    SDL_Rect rect;

    if (this->_actualGame == "NIBBLER")
    {
        int ratioX = 1440 / sizeY;
        int ratioY = 980 / sizeY;

        int startX = (1920 - (ratioX * sizeY)) / 2;
        int startY = (1080 - (ratioY * sizeX)) / 2;

        rect.x = startX + (i * ratioY);
        rect.y = startY + (j * ratioY);
        rect.w = ratioY;
        rect.h = ratioY;
    }
    else
    {
        int ratioX = 1440 / sizeY;
        int ratioY = 980 / sizeX;

        int startX = (1920 - (ratioX * sizeY)) / 2;
        int startY = (1080 - (ratioY * sizeX)) / 2;

        rect.x = startX + (i * ratioY);
        rect.y = startY + (j * ratioY);
        rect.w = ratioY;
        rect.h = ratioY;
    }

    return rect;
}

void LibSDL2::loadGameAssets(std::string actualGamePath, std::vector<std::string> map)
{
    std::cout << "Initialisation loading game assets" << std::endl;
    // int nbrOfU = 0;

    this->_actualGame.clear();
    for (size_t i = 0; i != actualGamePath.length(); i++)
        this->_actualGame += std::toupper(actualGamePath[i]);

    std::cout << "Current game name : " << this->_actualGame << std::endl;
    std::cout << "DONE\n" << std::endl;

    std::cout << "Loading game assets..." << std::endl;
    std::cout << "Sprite Sheet..." << std::endl;
    try {
        if (!_SDL_WasInit(SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_VIDEO))
            _SDL_Init(SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
        if (!_TTF_WasInit())
            _TTF_Init();
        if (this->_win == NULL)
            this->_win = _SDL_CreateWindow("ARCADE", 0, 0, 1920, 1080, SDL_WINDOW_RESIZABLE);
        _SDL_RenderClear(this->_renderer);
        if (this->_renderer == NULL)
            this->_renderer = _SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED);
        if (this->_font == NULL)
            this->_font = _TTF_OpenFont("Assets/arcade.ttf", 25);
        if (this->_spriteSheet != NULL)
            _SDL_DestroySurface(this->_spriteSheet);
        this->_spriteSheet = _IMG_load("Assets/" + this->_actualGame + "/spriteSheet.png");
        if (this->_spriteSheetTexture != NULL)
            _SDL_DestroyTexture(this->_spriteSheetTexture);
        this->_spriteSheetTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_spriteSheet);
        std::cout << "DONE" << std::endl;

        std::cout << "Loading music..." << std::endl;

        if (this->_music == NULL) {
            _MIX_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
            this->_music = _MIX_LoadMUS("Assets/NGYU_music.mp3");
            this->_MIX_PlayMusic(this->_music, -1);
        }

        std::cout << "DONE" << std::endl;

        std::cout << "Wall Texture..." << std::endl;
        if (this->_wallSurface != NULL)
            _SDL_DestroySurface(this->_wallSurface);
        if (this->_wallTexture != NULL)
            _SDL_DestroyTexture(this->_wallTexture);
        this->_wallSurface = _IMG_load("Assets/wall_test.png");
        this->_wallTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_wallSurface);
        std::cout << "DONE\n" << std::endl;

        if (this->_bodyRect.size() != 0)
            this->_bodyRect.clear();
        if (this->_itemRects.size() != 0)
            this->_itemRects.clear();
        if (this->_wallRect.size() != 0)
            this->_wallRect.clear();

        this->_isRunning = true;
        this->_spriteSheetLoaded = true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        this->_isRunning = false;
        if (this->_spriteSheet == NULL)
            this->_spriteSheetLoaded = false;
        return;
    }

    std::cout << "Initialisation Position map..." << std::endl;
    for (size_t i = 2; i != map.size(); i++) {
        for (size_t j = 0; j != map[i].size(); j++) {
            if (map[i][j] == 'P' || map[i][j] == 'H')
                this->_playerRect = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'R')
                this->_ennemyRects['R'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'B')
                this->_ennemyRects['B'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'J')
                this->_ennemyRects['J'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'V')
                this->_ennemyRects['V'] = this->createRect(j, i, map.size(), map[i].size());
            if (map[i][j] == 'Q')
                this->_bodyRect.push_back(this->createRect(j, i, map.size(), map[i].size()));
            if (map[i][j] == 'F' || map[i][j] == 'o')
                this->_itemRects.push_back(this->createRect(j, i, map.size(), map[i].size()));
            if (map[i][j] == 'O')
                this->_specialRect.push_back(this->createRect(j, i, map.size(), map[i].size()));
            if (map[i][j] == '#')
                this->_wallRect.push_back(this->createRect(j, i, map.size(), map[i].size()));
            if (map[i][j] == 'D')
                this->_doorRect.push_back(this->createRect(j, i, map.size(), map[i].size()));
            // if (map[i][j] == 'R' || (map[i][j] == 'U' && this->_enemiesPos['R'].first != -1))
            // {
            //     this->_enemiesPos['R'] = {j, i};
            //     if (map[i][j] == 'U')
            //     {
            //         nbrOfU++;
            //         this->_isU = true;
            //     }
            // }
            // if (map[i][j] == 'J' || (map[i][j] == 'U' && this->_enemiesPos['J'].first != -1))
            // {
            //     this->_enemiesPos['J'] = {j, i};
            //     if (map[i][j] == 'U')
            //         nbrOfU++;
            // }
            // if (map[i][j] == 'B' || (map[i][j] == 'U' && this->_enemiesPos['B'].first != -1))
            // {
            //     this->_enemiesPos['B'] = {j, i};
            //     if (map[i][j] == 'U')
            //         nbrOfU++;
            // }
            // if (map[i][j] == 'V' || (map[i][j] == 'U' && this->_enemiesPos['V'].first != -1))
            // {
            //     this->_enemiesPos['V'] = {j, i};
            //     if (map[i][j] == 'U')
            //         nbrOfU++;
            // }
            if (map[i][j] == 'Q')
            {
                this->_bodyPos.push_back({j, i});
            }
            if (map[i][j] == 'o' || map[i][j] == 'F')
            {
                this->_itemsPos[map[i][j]].push_back({j, i});
            }
            if (map[i][j] == 'P' || map[i][j] == 'H')
            {
                this->_playerPos = {j, i};
            }
        }
    }

    for (size_t i = 0; i != this->_doorRect.size(); i++)
        this->_doorRect[i].h /= 2;

    if (this->_actualGame == "PACMAN") {
        this->_itemSurfaceRect.clear();
        this->_playerSurfaceRect = {21, 4, 48, 70};
        this->_ennemySurfaceRect['R'] = {21, 348, 75, 75};
        this->_ennemySurfaceRect['B'] = {21, 434, 75, 75};
        this->_ennemySurfaceRect['V'] = {21, 519, 76, 76};
        this->_ennemySurfaceRect['J'] = {21, 605, 75, 75};
        this->_ennemySurfaceRect['U'] = {708, 348, 75, 75};
        this->_itemSurfaceRect.push_back({192, 4, 70, 70});
        this->_specialSurfaceRect.push_back({530, 85, 172, 172});
    }
    else if (this->_actualGame == "NIBBLER") {
        this->_itemSurfaceRect.clear();
        this->_playerSurfaceRect = {346, 172, 115, 143};
        this->_bodySurfaceRect.push_back({515, 6, 107, 116});
        this->_bodySurfaceRect.push_back({663, 8, 88, 111});
        this->_bodySurfaceRect.push_back({772, 7, 107, 115});
        this->_itemSurfaceRect.push_back({1558, 28, 156, 156});
        this->_itemSurfaceRect.push_back({1564, 192, 169, 169});
    }

    std::cout << "    Initialisation DONE\n" << std::endl;
}

void LibSDL2::loadMenuAssets(std::string actualGamePath, std::vector<std::string> gameLibPath, std::vector<std::string> displayerlibPath)
{
    (void)gameLibPath;
    (void)displayerlibPath;

    this->_actualGame.clear();
    for (size_t i = 0; i != actualGamePath.length(); i++)
        this->_actualGame += std::toupper(actualGamePath[i]);

    try
    {
        if (!_SDL_WasInit(SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_VIDEO))
            _SDL_Init(SDL_INIT_EVENTS | SDL_INIT_AUDIO | SDL_INIT_VIDEO);
        if (!_TTF_WasInit())
            _TTF_Init();
        if (this->_win == NULL)
            this->_win = _SDL_CreateWindow("ARCADE", 0, 0, 1920, 1080, SDL_WINDOW_RESIZABLE);
        if (this->_renderer == NULL)
            this->_renderer = _SDL_CreateRenderer(this->_win, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (this->_menuBckgdSurface == NULL)
            this->_menuBckgdSurface = _IMG_load("Assets/menuBackground.jpg");
        if (this->_menuBckgdTexture == NULL)
            this->_menuBckgdTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_menuBckgdSurface);

        if (this->_font == NULL)
            this->_font = _TTF_OpenFont("Assets/arcade.ttf", 25);
        if (this->_titleSurface == NULL)
            this->_titleSurface = _TTF_RenderText_Solid(this->_font, this->_colorTitle, "ARCADE");
        if (this->_titleTexture == NULL)
            this->_titleTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_titleSurface);
        if (this->_rectTitle.w == 0 && this->_rectTitle.h == 0)
        {
            this->_rectTitle.w = 750;
            this->_rectTitle.h = 300;
            _SDL_QueryTexture(this->_titleTexture, NULL, 0, this->_rectTitle.w, this->_rectTitle.h);
        }
        if (this->_launchSurface == NULL)
            this->_launchSurface = _TTF_RenderText_Solid(this->_font, this->_colorLaunch, "Click here to launch");
        if (this->_launchTexture == NULL) {
            this->_launchTexture = _SDL_CreateTextureFromSurface(this->_renderer, this->_launchSurface);
            _SDL_QueryTexture(this->_launchTexture, NULL, 0, this->_rectLaunch.w, this->_rectLaunch.h);
        }

        if (this->_music == NULL) {
            _MIX_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
            this->_music = _MIX_LoadMUS("Assets/NGYU_music.mp3");
            this->_MIX_PlayMusic(this->_music, -1);
        }

        this->_isRunning = true;
    }
    catch (const std::exception &e)
    {
        std::cerr << e.what() << '\n';
        this->_isRunning = false;
    }

    _SDL_FillRect(this->_transparent, &this->_rectGame, _SDL_MapRGBA(this->_transparent->format, 0, 0, 0, 150));
    _SDL_FillRect(this->_transparent, &this->_rectGraph, _SDL_MapRGBA(this->_transparent->format, 0, 0, 0, 150));
}

void LibSDL2::destroyWindow(void)
{
    this->_isRunning = false;

    if (this->_win != NULL)
    {
        _SDL_DestroyWindow(this->_win);
        this->_win = NULL;
    }

    if (this->_renderer != NULL)
    {
        _SDL_DestroyRenderer(this->_renderer);
        this->_renderer = NULL;
    }

    if (_TTF_WasInit())
    {
        _TTF_Quit();
    }

    if (_SDL_WasInit(SDL_INIT_VIDEO))
    {
        _SDL_Quit();
    }

    if (this->_titleSurface != NULL)
    {
        _SDL_DestroySurface(this->_titleSurface);
        this->_titleSurface = NULL;
    }

    if (this->_titleTexture != NULL)
    {
        _SDL_DestroyTexture(this->_titleTexture);
        this->_titleTexture = NULL;
    }

    if (this->_font != NULL)
    {
        // _TTF_CloseFont(this->_font);
        this->_font = NULL;
    }

    if (this->_launchSurface != NULL)
    {
        _SDL_DestroySurface(this->_launchSurface);
        this->_launchSurface = NULL;
    }

    if (this->_launchTexture != NULL)
    {
        _SDL_DestroyTexture(this->_launchTexture);
        this->_launchTexture = NULL;
    }

    // if (this->_transparent != NULL)
    // {
    //     _SDL_DestroySurface(this->_transparent);
    //     this->_transparent = NULL;
    // }

    if (this->_menuBckgdTexture != NULL)
    {
        _SDL_DestroyTexture(this->_menuBckgdTexture);
        this->_menuBckgdTexture = NULL;
    }

    if (this->_menuBckgdSurface != NULL)
    {
        _SDL_DestroySurface(this->_menuBckgdSurface);
        this->_menuBckgdSurface = NULL;
    }

    if (this->_gameBckgdTexture != NULL)
    {
        _SDL_DestroyTexture(this->_gameBckgdTexture);
        this->_gameBckgdTexture = NULL;
    }

    if (this->_gameBckgdSurface != NULL)
    {
        _SDL_DestroySurface(this->_gameBckgdSurface);
        this->_gameBckgdSurface = NULL;
    }

    if (this->_music != NULL) {
        _MIX_DestroyMusic(this->_music);
        this->_music = NULL;
        _MIX_CloseAudio();
    }

    this->_bodySurfaceRect.clear();
    this->_bodyRect.clear();
    this->_itemSurfaceRect.clear();
    this->_itemRects.clear();
    this->_specialRect.clear();
    this->_specialSurfaceRect.clear();

    if (this->_wallTexture != NULL)
        _SDL_DestroyTexture(this->_wallTexture);
    this->_wallTexture = NULL;

    if (this->_wallSurface != NULL)
        _SDL_DestroySurface(this->_wallSurface);
    this->_wallSurface = NULL;

    this->_wallRect.clear();

    this->_doorRect.clear();

    if (this->_spriteSheet != NULL)
        _SDL_DestroySurface(this->_spriteSheet);
    this->_spriteSheet = NULL;

    if (this->_spriteSheetTexture != NULL)
        _SDL_DestroyTexture(this->_spriteSheetTexture);
    this->_spriteSheetTexture = NULL;

    if (this->_scoreSurface != NULL)
        _SDL_DestroySurface(this->_scoreSurface);
    this->_scoreSurface = NULL;

    if (this->_scoreTexture != NULL)
        _SDL_DestroyTexture(this->_scoreTexture);
    this->_scoreTexture = NULL;

    if (this->_healthSurface != NULL)
        _SDL_DestroySurface(this->_healthSurface);
    this->_healthSurface = NULL;

    if (this->_healthTexture != NULL)
        _SDL_DestroyTexture(this->_healthTexture);
    this->_healthTexture = NULL;

    if (this->_problemSurface != NULL)
    {
        _SDL_DestroySurface(this->_problemSurface);
        this->_problemSurface = NULL;
    }

    if (this->_problemTexture != NULL)
    {
        _SDL_DestroyTexture(this->_problemTexture);
        this->_problemTexture = NULL;
    }

    for (auto i : this->_graphSurfaces)
    {
        _SDL_DestroySurface(i);
    }
    this->_graphSurfaces.clear();

    for (auto i : this->_graphTextures)
    {
        _SDL_DestroyTexture(i);
    }
    this->_graphTextures.clear();

    this->_graphTextRects.clear();

    for (auto i : this->_controlSurface)
    {
        _SDL_DestroySurface(i);
    }
    this->_controlSurface.clear();

    for (auto i : this->_controlTexture)
    {
        _SDL_DestroyTexture(i);
    }
    this->_controlTexture.clear();
    this->_controlRect.clear();

    for (auto i : this->_gameTextures)
    {
        _SDL_DestroyTexture(i);
    }
    this->_gameTextures.clear();

    for (auto i : this->_gameSurfaces)
    {
        _SDL_DestroySurface(i);
    }
    this->_gameSurfaces.clear();

    this->_gameTextRects.clear();
}

bool LibSDL2::isRunning(void)
{
    return this->_isRunning;
}

arcade::KeyboardKeys LibSDL2::getInput(void)
{
    return this->_input;
}

std::string LibSDL2::getName(void)
{
    return this->_libName;
}

extern "C" std::shared_ptr<LibSDL2> entryPoint(void)
{
    return std::make_shared<LibSDL2>();
}
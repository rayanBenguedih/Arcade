/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Sdl
*/

#include "Sdl.hpp"

int SDL::_SDL_Init(Uint32 flags)
{
    int tmp = SDL_Init(flags);

    if (tmp != 0)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

Uint32 SDL::_SDL_WasInit(Uint32 flags)
{
    return SDL_WasInit(flags);
}

void SDL::_SDL_Quit(void)
{
    return SDL_Quit();
}

int SDL::_TTF_Init(void)
{
    int tmp = TTF_Init();

    if (tmp != 0)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

int SDL::_TTF_WasInit(void)
{
    return TTF_WasInit();
}

TTF_Font *SDL::_TTF_OpenFont(std::string file, int ptsize)
{
    TTF_Font *tmp = TTF_OpenFont(file.c_str(), ptsize);
    
    if (tmp == NULL)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

void SDL::_TTF_CloseFont(TTF_Font *font)
{
    return TTF_CloseFont(font);
}

SDL_Surface *SDL::_TTF_RenderText_Solid(TTF_Font *font, SDL_Color color, std::string text)
{
    return TTF_RenderText_Solid(font, text.c_str(), color);
}

void SDL::_TTF_Quit(void)
{
    return TTF_Quit();
}

int SDL::_SDL_QueryTexture(SDL_Texture *texture, Uint32 *format, int access, int width, int height)
{
    return SDL_QueryTexture(texture, format, &access, &width, &height);
}

int SDL::_SDL_RenderFillRect(SDL_Renderer *renderer, SDL_Rect rect)
{
    return SDL_RenderFillRect(renderer, &rect);
}

SDL_Surface *SDL::_SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask)
{
    return SDL_CreateRGBSurface(flags, width, height, depth, Rmask, Gmask, Bmask, Amask);
}

int SDL::_SDL_RenderDrawRect(SDL_Renderer *renderer, SDL_Rect rect)
{
    return SDL_RenderDrawRect(renderer, &rect);
}

Uint32 SDL::_SDL_MapRGBA(const SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return SDL_MapRGBA(format, r, g, b, a);
}

SDL_Window *SDL::_SDL_CreateWindow(std::string title, int x, int y, int width, int height, Uint32 flags)
{
    SDL_Window *tmp = SDL_CreateWindow(title.c_str(), x, y, width, height, flags);

    if (tmp == nullptr)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

void SDL::_SDL_DestroyWindow(SDL_Window *target)
{
    return SDL_DestroyWindow(target);
}

SDL_Renderer *SDL::_SDL_CreateRenderer(SDL_Window *target, int index, Uint32 flags)
{
    SDL_Renderer *tmp = SDL_CreateRenderer(target, index, flags);

    if (tmp == nullptr)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

void SDL::_SDL_DestroyRenderer(SDL_Renderer *target)
{
    return SDL_DestroyRenderer(target);
}

void SDL::_SDL_SetWindowTitle(SDL_Window *target, std::string newTitle)
{
    return SDL_SetWindowTitle(target, newTitle.c_str());
}

int SDL::_SDL_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a)
{
    return SDL_SetRenderDrawColor(renderer, r, g, b, a);
}

int SDL::_SDL_FillRect(SDL_Surface *surface, SDL_Rect *rect, Uint32 color)
{
    return SDL_FillRect(surface, rect, color);
}

int SDL::_SDL_RenderClear(SDL_Renderer *renderer)
{
    return SDL_RenderClear(renderer);
}

SDL_Surface *SDL::_SDL_LoadBMP(std::string file)
{
    SDL_Surface *tmp = SDL_LoadBMP(file.c_str());

    if (tmp == NULL)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

SDL_Texture *SDL::_SDL_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface)
{
    SDL_Texture *tmp = SDL_CreateTextureFromSurface(renderer, surface);

    if (tmp == NULL)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

SDL_Surface *SDL::_IMG_load(std::string file)
{
    SDL_Surface *tmp = IMG_Load(file.c_str());

    if (tmp == NULL)
        throw std::invalid_argument(SDL_GetError());
    return tmp;
}

std::string SDL::_SDL_GetError(void)
{
    std::string tmp(SDL_GetError());
    return tmp;
}

void SDL::_SDL_RenderPresent(SDL_Renderer *renderer)
{
    return SDL_RenderPresent(renderer);
}

int SDL::_SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect)
{
    return SDL_RenderCopy(renderer, texture, srcrect, dstrect);
}

void SDL::_SDL_Delay(Uint32 ms)
{
    return SDL_Delay(ms);
}

int SDL::_SDL_PollEvent(SDL_Event *event)
{
    return SDL_PollEvent(event);
}

void SDL::_SDL_DestroyTexture(SDL_Texture *texture)
{
    return SDL_DestroyTexture(texture);
}

void SDL::_SDL_DestroySurface(SDL_Surface *surface)
{
    return SDL_FreeSurface(surface);
}

int SDL::_MIX_OpenAudio(int frequency, Uint16 format, int channel, int chunksize)
{
    return Mix_OpenAudio(frequency, format, channel, chunksize);
}

Mix_Music *SDL::_MIX_LoadMUS(std::string file)
{
    return Mix_LoadMUS(file.c_str());
}

void SDL::_MIX_CloseAudio(void)
{
    return Mix_CloseAudio();
}

void SDL::_MIX_DestroyMusic(Mix_Music *music)
{
    return Mix_FreeMusic(music);
}

int SDL::_MIX_PlayMusic(Mix_Music *music, int loop)
{
    return Mix_PlayMusic(music, loop);
}
/*
** EPITECH PROJECT, 2022
** B-OOP-400-LIL-4-1-arcade-pierre-jean.descarpentries
** File description:
** Sdl
*/

#ifndef SDL_HPP_
#define SDL_HPP_

#include <exception>
#include <iostream>

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_mixer.h>

class SDL {
    public:
        static int _SDL_Init(Uint32 flags);
        static Uint32 _SDL_WasInit(Uint32 flags);
        static void _SDL_Quit(void);

        static int _TTF_Init(void);
        static int _TTF_WasInit(void);
        static TTF_Font *_TTF_OpenFont(std::string file, int ptsize);
        static void _TTF_CloseFont(TTF_Font *font);
        static SDL_Surface *_TTF_RenderText_Solid(TTF_Font *font, SDL_Color color, std::string text);
        static void _TTF_Quit(void);

        static int _SDL_QueryTexture(SDL_Texture *texture, Uint32 *format, int access, int width, int height);
        static int _SDL_RenderFillRect(SDL_Renderer *renderer, SDL_Rect rect);
        static int _SDL_FillRect(SDL_Surface *surface, SDL_Rect *rect, Uint32 color);
        static SDL_Surface *_SDL_CreateRGBSurface(Uint32 flags, int width, int height, int depth, Uint32 Rmask, Uint32 Gmask, Uint32 Bmask, Uint32 Amask);
        static Uint32 _SDL_MapRGBA(const SDL_PixelFormat *format, Uint8 r, Uint8 g, Uint8 b, Uint8 a);

        static SDL_Surface *_IMG_load(std::string file);

        static SDL_Window *_SDL_CreateWindow(std::string title, int x, int y, int width, int height, Uint32 flags);
        static void _SDL_DestroyWindow(SDL_Window *target);

        static SDL_Renderer *_SDL_CreateRenderer(SDL_Window *target, int index, Uint32 flags);
        static void _SDL_DestroyRenderer(SDL_Renderer *target);

        static void _SDL_SetWindowTitle(SDL_Window *target, std::string newTitle);
        static int _SDL_SetRenderDrawColor(SDL_Renderer *renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
        static int _SDL_RenderDrawRect(SDL_Renderer *renderer, SDL_Rect rect);
        static int _SDL_RenderClear(SDL_Renderer *renderer);
        static SDL_Surface *_SDL_LoadBMP(std::string file);
        static SDL_Texture *_SDL_CreateTextureFromSurface(SDL_Renderer *renderer, SDL_Surface *surface);
        static void _SDL_RenderPresent(SDL_Renderer *renderer);
        static int _SDL_RenderCopy(SDL_Renderer *renderer, SDL_Texture *texture, const SDL_Rect *srcrect, const SDL_Rect *dstrect);

        static void _SDL_DestroyTexture(SDL_Texture *texture);
        static void _SDL_DestroySurface(SDL_Surface *surface);

        static std::string _SDL_GetError(void);

        static void _SDL_Delay(Uint32 ms);
        static int _SDL_PollEvent(SDL_Event *event);

        static int _MIX_OpenAudio(int frequency, Uint16 format, int channel, int chunksize);
        static Mix_Music *_MIX_LoadMUS(std::string file);
        static void _MIX_CloseAudio(void);
        static void _MIX_DestroyMusic(Mix_Music *music);
        static int _MIX_PlayMusic(Mix_Music *music, int loop);
};

#endif /* !SDL_HPP_ */

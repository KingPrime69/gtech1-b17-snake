#ifndef MAIN_HPP
#define MAIN_HPP
#include "HeadSnake.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class MainSDLWindow{
    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *title, int x, int y);
    SDL_Renderer *GetRenderer(void);
    SDL_Window *window;

    private:
    SDL_Renderer *renderer;
    HeadSnake *main_snake;
};

#endif
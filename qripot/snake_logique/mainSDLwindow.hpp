#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>


class MainSDLWindow{
    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *title, int x, int y);
    SDL_Renderer *GetRenderer(void);

    private:
    SDL_Renderer *renderer;
    SDL_Window *window;
};

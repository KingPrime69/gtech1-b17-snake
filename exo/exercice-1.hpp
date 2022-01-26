#ifndef EXERCICE1_HPP
#define EXERCICE1_HPP

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
    SDL_Window *window;
    SDL_Renderer *renderer;
};

#endif
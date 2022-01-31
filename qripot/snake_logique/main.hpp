#ifndef MAIN_HPP
#define MAIN_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class MainSDLWindow{
    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *title, int x, int y);
    SDL_Renderer *GetRenderer(void);
    SDL_Renderer *renderer;


    private:
    Snake *main_snake;
    SDL_Window *window;
};
#endif
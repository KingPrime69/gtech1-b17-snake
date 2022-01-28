#ifndef EXERCICE3_HPP
#define EXERCICE3_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class MainSDLWindow{
    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *title, int x, int y);
    SDL_Renderer *GetRenderer(void);
    void Square();
    void keyboard();

    private:
    int x;
    int y;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Rect *square;
};

#endif
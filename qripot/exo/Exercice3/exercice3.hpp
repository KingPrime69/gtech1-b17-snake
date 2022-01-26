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
    void Draw();
    void Refresh();

    private:
    int game;
    int X;
    int Y;
    int w;
    SDL_Window *window;
    SDL_Renderer *renderer;
};
#endif
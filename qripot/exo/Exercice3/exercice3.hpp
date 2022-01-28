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
    void verifKey(bool game);
    void mouv(const char *dir);
    bool continuer;

    private:
    int X;
    int Y;
    int w;
    SDL_Surface *surface;
    SDL_Rect rect;
    SDL_Window *window;
    SDL_Renderer *renderer;
};
#endif
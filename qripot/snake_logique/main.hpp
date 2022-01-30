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
    void Draw();
    void verifKey(bool game);
    void mouv(const char *dir);
    void refresh();
    void follow();
    bool continuer;
    void DrawAppel();  


    private:
    int aX1; 
    int aY1;
    int aX;
    int aY;
    int mX;
    int mY;
    int speed;
    int X;
    int Y;
    int w;
    SDL_Surface *surface;
    SDL_Rect head;
    SDL_Rect body1;
    SDL_Rect body2;
    SDL_Window *window;
    SDL_Renderer *renderer;
    int pW;
    SDL_Rect apple;
};
#endif
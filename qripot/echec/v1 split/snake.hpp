#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Snake {
    public:
    Snake();
    ~Snake();
    int InitSnake();
    void mouv(const char *dir);
    void follow();
    SDL_Rect head;
    SDL_Rect body1;
    SDL_Rect body2;
    SDL_Rect GetHead();
    SDL_Rect GetBody();

    int X;
    int Y;
    int aX1; 
    int aY1;
    int aX;
    int aY;
    bool ref;

    private:
    int speed;
    int w;
};
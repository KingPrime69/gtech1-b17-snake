#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define w 50

class Snake {
    public:
    int number;
    Snake *next;
    int Init();
    Snake();
    ~Snake();
    int InitSnake();
    void mouv(const char *dir);
    SDL_Rect head;
    SDL_Rect GetHead();
    int addStart();

    int X;
    int Y;

    private:
    int speed;
};
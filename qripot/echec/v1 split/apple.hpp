#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Apple{
    public:
    Apple();
    ~Apple();
    int InitApple();
    SDL_Rect apple;
    SDL_Rect GetApple();

    private:
    int pW;
};
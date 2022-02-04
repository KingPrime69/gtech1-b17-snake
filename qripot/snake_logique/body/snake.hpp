#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Segment.hpp"
#include "../mainSDLwindow.hpp"

class Snake {
    public:
    Snake();
    ~Snake();
    int addStart();
    Segment GetHead();

    void Draw(MainSDLWindow wind);
    void Refresh(MainSDLWindow wind);
    int InitSnake();
    void Mouv(const char *dir);
    Segment *head;

    private:
    MainSDLWindow wind;   
    SDL_Rect body;
    char dir;
    int speed;
};
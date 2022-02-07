#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Segment.hpp"
#include "../mainSDLwindow.hpp"

class Snake {
    public:
    Snake(MainSDLWindow *wind);
    ~Snake();
    int addStart();
    Segment GetHead();

    void Draw();
    void Refresh();
    int InitSnake();
    void Mouv(char dir);
    Segment *head;
    void CheckBorder();
    bool border;
    void AddSeg();

    void MouvAll();

    private:
    int Xpre;
    int Ypre;
    int scale;
    MainSDLWindow *wind;   
    SDL_Rect body;
    SDL_Rect follow;
    char dir;
    int speed;
};
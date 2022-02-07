#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Segment.hpp"
#include "../mainSDLwindow.hpp"

class Snake {
    public:
    
    Segment *head;
    
    Snake(MainSDLWindow *wind);
    ~Snake();

    int addStart();
    Segment GetHead();
    void Draw();
    void Refresh();
    int InitSnake();
    void Mouv();
    void CheckBorder();
    bool border;
    void AddSeg();

    void MouvAll();

    private:
    char DirPre;
    int Xpre;
    int Ypre;
    int scale;
    MainSDLWindow *wind;   
    SDL_Rect body;
    SDL_Rect follow;
    int speed;
};
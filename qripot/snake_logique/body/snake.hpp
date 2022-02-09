#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Segment.hpp"
#include "../mainSDLwindow.hpp"
#include "../apple.hpp"

class Snake{
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
    void DeleteSeg(int segmentpos);
    int getLen();

    void random();
    bool eat;

    SDL_Rect BG();

    private:
    char DirPre;
    int Xpre;
    int Ypre;
    int scale;
    MainSDLWindow *wind;   
    SDL_Rect body;
    SDL_Rect follow;
    int speed;
    SDL_Rect background;

    SDL_Rect apple;
    int pW;

    bool self;

    int countX;
    int countY;
};
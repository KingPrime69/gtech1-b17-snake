#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "Segment.hpp"
#include "../mainSDLwindow.hpp"


class Snake{
    public:
    
    Segment *head;
    
    Snake(MainSDLWindow *wind);
    ~Snake();

    void Draw();
    void Refresh();
    void Mouv();
    void AddSeg();
    void DeleteSeg(int segmentpos);
    int getLen();

    void random();
    void CheckCol();

    bool border;

    private:
    int scale;
    MainSDLWindow *wind;   
    SDL_Rect body;
    SDL_Rect background;

    SDL_Rect apple;
    bool eat;
    int pW;
    int countX;
    int countY;
    int rand_apple;
};
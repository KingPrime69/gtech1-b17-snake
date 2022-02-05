#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#define Width 50

class Segment{
    public:
        Segment *next;
        Segment(int x, int y, char dir);
        ~Segment();
        int GetX();
        int GetY();
        void SetX(int x);
        void SetY(int y);
        char GetDir();
        void SetDirOp(char ChangeDir);
        int nbSeg;
    
    private:
        int x;
        int y; 
        char dir;
};
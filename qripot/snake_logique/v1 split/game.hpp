#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include "snake.hpp"
#include "apple.hpp"
#include "main.hpp"

class Game {
    public:
    Game();
    ~Game();
    bool continuer;
    void Draw(MainSDLWindow wind);
    void verifKey(bool game); 
    void refresh(MainSDLWindow wind);
    Snake s;
    Apple a;
    bool ref;

    private:
    int aY;
    int aX;
    int aX1;
    int aY1;
};
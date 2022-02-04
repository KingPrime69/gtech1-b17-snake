#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "body/snake.hpp"

class Game {
    public:
        Game();
        ~Game();
        void verifKey(bool game, Snake *s);

    private:
        int aY;
        int aX;
        int aX1;
        int aY1;
};
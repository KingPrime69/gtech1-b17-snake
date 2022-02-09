#pragma once

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

#include "body/snake.hpp"
#include "body/Segment.hpp"

class Game {
    public:
        Game(Snake *s);
        ~Game();
        void verifKey(bool continuer);
        bool game;

    private:
        Snake *s;
        Segment *seg;
        bool pause;
};
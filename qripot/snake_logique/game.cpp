#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Game::Game(Snake *s)
{
    this->s = s;
}

Game::~Game()
{
}

void Game::verifKey(bool continuer)
{
    SDL_Event(event);
    while (SDL_PollEvent(&event))
    {
        if (event.type == SDL_QUIT || s->border == true)
        {
            printf("delete\n");
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            game = false;
        }

        else if (event.type == SDL_KEYDOWN)
        {
            if (event.key.keysym.sym == SDLK_UP)
            {
                if (s->head->GetDir() == 'D')
                    return;
                this->s->head->SetDir('U');
            }
            if (event.key.keysym.sym == SDLK_DOWN)
            {
                if (s->head->GetDir() == 'U')
                    return;
                this->s->head->SetDir('D');
            }
            if (event.key.keysym.sym == SDLK_LEFT)
            {
                if (s->head->GetDir() == 'R')
                    return;
                this->s->head->SetDir('L');
            }
            if (event.key.keysym.sym == SDLK_RIGHT)
            {
                if (s->head->GetDir() == 'L')
                    return;
                this->s->head->SetDir('R');
            }
        }
        if(s->eat == true)
            s->random();
    }
    this->s->Mouv();
}
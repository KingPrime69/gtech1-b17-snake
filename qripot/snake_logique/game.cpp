#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Game::Game(Snake *s, Segment *seg){
    this->s = s;
    this->seg = seg;
}

Game::~Game(){

}

void Game::verifKey(bool continuer){
    SDL_Event(event);
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) {
            printf("delete\n");
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            game = false;
        }

        else if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym==SDLK_UP) {
                this->seg->SetDirection('D');
                this->s->Mouv('U');
            }
            if (event.key.keysym.sym==SDLK_DOWN) {
                this->seg->SetDirection('U');
                this->s->Mouv('D');
            }
            if (event.key.keysym.sym==SDLK_LEFT) {
                this->seg->SetDirection('R');
                this->s->Mouv('L'); 
            }
            if (event.key.keysym.sym==SDLK_RIGHT) {
                this->seg->SetDirection('L');
                this->s->Mouv('R');
            }
        }
        else if(event.type == SDL_KEYUP){
                this->s->Mouv('N');
        }
    }
}
#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Game::Game(Snake *s){
    this->s = s;
}

Game::~Game(){

}

void Game::verifKey(bool continuer){
    SDL_Event(event);
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT || s->border == true) {
            printf("delete\n");
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            game = false;
        }

        else if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym==SDLK_UP) {
                this->s->Mouv('U');
            }
            if (event.key.keysym.sym==SDLK_DOWN) {
                this->s->Mouv('D');
            }
            if (event.key.keysym.sym==SDLK_LEFT) {
                this->s->Mouv('L'); 
            }
            if (event.key.keysym.sym==SDLK_RIGHT) {
                this->s->Mouv('R');
            }
        }
        else if(event.type == SDL_KEYUP){
                this->s->Mouv('N');
        }
    }
}
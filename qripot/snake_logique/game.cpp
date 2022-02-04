#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Game::Game(){
    
}

Game::~Game(){

}

void Game::verifKey(bool game, Snake *s){
    SDL_Event(event);
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) {
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
        }

        else if (event.type == SDL_KEYDOWN){
            if (event.key.keysym.sym==SDLK_UP) {
                s->Mouv("up");
            }
            if (event.key.keysym.sym==SDLK_DOWN) {
                s->Mouv("down");
            }
            if (event.key.keysym.sym==SDLK_LEFT) {
                s->Mouv("left");
            }
            if (event.key.keysym.sym==SDLK_RIGHT) {
                s->Mouv("right");
            }
        }
        else if(event.type == SDL_KEYUP){
                s->Mouv(NULL);
        }
    }
}
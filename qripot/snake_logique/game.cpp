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
            if (event.key.keysym.sym==SDLK_n) {
                printf("création d'un nouveau segment\n");
                s->AddSeg();
            }
            if (event.key.keysym.sym==SDLK_UP) {
                this->s->head->SetDir('U');
                this->s->Mouv();
                if(this->s->head->GetDirOp() != 'D')
                    this->s->head->SetDirOp('U');
            }
            if (event.key.keysym.sym==SDLK_DOWN) {
                this->s->head->SetDir('D');
                this->s->Mouv();
                if(this->s->head->GetDirOp() != 'U')
                    this->s->head->SetDirOp('D');
            }
            if (event.key.keysym.sym==SDLK_LEFT) {
                this->s->head->SetDir('L');
                this->s->Mouv(); 
                if(this->s->head->GetDirOp() != 'R')
                    this->s->head->SetDirOp('L');
            }
            if (event.key.keysym.sym==SDLK_RIGHT) {
                this->s->head->SetDir('R');
                this->s->Mouv();
                if(this->s->head->GetDirOp() != 'L')
                    this->s->head->SetDirOp('R');
            }
        }
    }
}
#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Game::Game(){
    Snake snake;
    this->s = snake;

    Apple apple;
    this->a = apple;

    // this->s= new Snake();
}

Game::~Game(){
    delete &s;
    delete &a;


}

void Game::Draw(MainSDLWindow wind){
    SDL_SetRenderDrawColor(wind.GetRenderer(),255,0,0,255);
    SDL_RenderFillRect(wind.GetRenderer(), &s.GetHead());
    SDL_SetRenderDrawColor(wind.GetRenderer(),0,0,255,255); 
    SDL_RenderFillRect(wind.GetRenderer(), &s.GetBody()); 
    SDL_RenderPresent(wind.GetRenderer());

    //apple
    SDL_SetRenderDrawColor(wind.GetRenderer(),255,0,0,255); 
    SDL_RenderFillRect(wind.GetRenderer(), &a.GetApple());  
    SDL_RenderPresent(wind.GetRenderer());
}

void Game::refresh(MainSDLWindow wind){
    SDL_SetRenderDrawColor(wind.GetRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(wind.GetRenderer());
    Draw(wind);
}

void Game::verifKey(bool game){
    SDL_Event(event);
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) {
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            continuer = false;
        }

        else if (event.type == SDL_KEYDOWN){
            aX = s.GetHead().x;
            aY = s.GetHead().y;
            aX1 = s.GetBody().x;
            aY1 = s.GetBody().y;
            if (event.key.keysym.sym==SDLK_UP) {
                s.mouv("up");
            }
            if (event.key.keysym.sym==SDLK_DOWN) {
                s.mouv("down");
            }
            if (event.key.keysym.sym==SDLK_LEFT) {
                s.mouv("left");
            }
            if (event.key.keysym.sym==SDLK_RIGHT) {
                s.mouv("right");
            }
        }
        else if(event.type == SDL_KEYUP){
                s.mouv(NULL);
        }
    }
}
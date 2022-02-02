#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Snake::Snake(){
    this->next = NULL;
}

Snake::~Snake(){

}

int Snake::InitSnake(){
    number = 0;
    X=650;
    Y=450;
    speed = 50;
    head = {X, Y, w, w};
    if(next == NULL){
        next->number = 1;
    }
}

int Snake::addStart(){
    next->head;
}

void Snake::mouv(const char *dir){
    if(dir == "up"){
        head.y-=speed;
    }
    else if(dir == "down"){
        head.y+=speed;
    }
    else if(dir == "left"){
        head.x-=speed;
    }
    else if(dir == "right"){
        head.x+=speed;
    }
}

SDL_Rect Snake::GetHead(){
    return this->head;
}

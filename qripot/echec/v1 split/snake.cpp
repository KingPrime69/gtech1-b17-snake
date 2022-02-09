#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Snake::Snake(){
    head.h = 0;
    head.w = 0;
    head.x = 0;
    head.y = 0;    
}

Snake::~Snake(){
}


int Snake::InitSnake(){
    X=650;
    Y=450;
    w=50;
    speed = 50;
    head = {X, Y, w, w};
    body1 = {X, Y+50, w, w};
    body2 = {X, Y+100, w, w};
}

void Snake::mouv(const char *dir){
    if(dir == "up"){
        head.y-=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        ref = true;
    }
    else if(dir == "down"){
        head.y+=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        ref = true;
    }
    else if(dir == "left"){
        head.x-=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        ref = true;
    }
    else if(dir == "right"){
        head.x+=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        ref = true;
    }
}

SDL_Rect Snake::GetHead(){
    return this->head;
}

SDL_Rect Snake::GetBody(){
    return this->body1;
}

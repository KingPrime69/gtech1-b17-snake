#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Snake::Snake(){

}

Snake::~Snake(){

}

int Snake::InitSnake(){
    continuer = true;
    X=650;
    Y=450;
    w=50;
    speed = 50;
    head = {X, Y, w, w};
    body1 = {X, Y+50, w, w};
    body2 = {X, Y+100, w, w};
}
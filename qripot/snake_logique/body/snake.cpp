#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Snake::Snake(MainSDLWindow *wind){
    this->head = NULL;
    this->wind = wind;

    Segment *seg = new Segment(800, 300, 'U');

    this->head = seg;

}

Snake::~Snake(){
}

Segment Snake::GetHead(){
    return *head;
}

void Snake::Draw(){
    Segment *temp = head;

    if(head == NULL){
        return;
    }
     
    do{
        body.x = temp->GetX();
        body.y = temp->GetY();
        body.w = Width;
        body.h = Width;
        SDL_SetRenderDrawColor(wind->GetRenderer(),255,0,0,255);
        SDL_RenderFillRect(wind->GetRenderer(), &body);
        SDL_RenderPresent(wind->GetRenderer());
        if(temp->next!=NULL){
            temp = temp->next;
        }
    }
    while(temp->next != NULL);
    return;


/*
    //apple
    SDL_SetRenderDrawColor(wind.GetRenderer(),255,0,0,255); 
    SDL_RenderFillRect(wind.GetRenderer(), &body);  
    SDL_RenderPresent(wind.GetRenderer());
  */  
}

void Snake::Refresh(){
    SDL_SetRenderDrawColor(this->wind->GetRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(this->wind->GetRenderer());
    Draw();
    return;
}

void Snake::Mouv(char dir){
    if(dir == 'U'){
        if(head->GetDir() != 'D'){
            head->SetY(head->GetY()-10);
            head->GetY();
            Refresh();
        }
    }
    else if(dir == 'D'){
        if(head->GetDir() != 'U'){
            head->SetY(head->GetY()+10);
            head->GetY();
            Refresh();
        }
    }
    else if(dir == 'L'){
        if(head->GetDir() != 'R'){
            head->SetX(head->GetX()-10);
            head->GetX();
            Refresh();
        }
    }
    else if(dir == 'R'){
        if(head->GetDir() != 'L'){
            head->SetX(head->GetX()+10);
            head->GetX();
            Refresh();
        }
    }
    printf("dir : %c\n", head->GetDir());
}
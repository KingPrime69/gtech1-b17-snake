#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Snake::Snake(MainSDLWindow *wind){
    this->head = NULL;
    this->wind = wind;

    Segment *seg = new Segment(650, 450, "up");

    this->head = seg;
    if(head->next == NULL)
        printf("WHY\n");

}

Snake::~Snake(){
    printf("STOP BULLY PLSSSSSSSS\n");
}

Segment Snake::GetHead(){
    return *head;
}

void Snake::Draw(){
    printf("Marche\n");
    Segment *temp = head;

    if(head == NULL){
        printf("MERDE\n");
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
}

void Snake::Mouv(const char *dir){
    if(dir == "up"){
        if(head->next->GetDir() != *"down")
            body.y-=speed;
            Refresh();
    }
    else if(dir == "down"){
        if(head->next->GetDir() != *"up")
        body.y+=speed;
        Refresh();
    }
    else if(dir == "left"){
        if(head->next->GetDir() != *"right")
        body.x-=speed;
        Refresh();
    }
    else if(dir == "right"){
        if(head->next->GetDir() != *"left")
        body.x+=speed;
        Refresh();
    }
}
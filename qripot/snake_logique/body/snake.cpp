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

Segment Snake::GetHead(){
    return *head;
}

void Snake::Draw(MainSDLWindow wind){
    printf("Marche\n");
    Segment *temp = head;

    Segment *seg = new Segment(650, 450, "up");

    if(head == NULL)
    printf("MERDE\n");
        return;

    if (temp->next == NULL)
        printf("tu fais chier");

    do{
        printf("Z\n");
        body.x = head->GetX();
        printf("E\n");
        body.y = head->GetY();
        printf("U\n");
        body.w = Width;
        printf("B\n");
        body.h = Width;
        printf("I\n");
        SDL_SetRenderDrawColor(wind.GetRenderer(),255,0,0,255);
        SDL_RenderFillRect(wind.GetRenderer(), &body);
        if(temp->next!=NULL)
            temp = temp->next;
    }
    while(temp->next != NULL);
    SDL_RenderClear(wind.GetRenderer());
    SDL_RenderPresent(wind.GetRenderer());


/*
    //apple
    SDL_SetRenderDrawColor(wind.GetRenderer(),255,0,0,255); 
    SDL_RenderFillRect(wind.GetRenderer(), &body);  
    SDL_RenderPresent(wind.GetRenderer());
  */  
}

void Snake::Refresh(MainSDLWindow wind){
    SDL_SetRenderDrawColor(wind.GetRenderer(), 0, 0, 0, 255);
    SDL_RenderClear(wind.GetRenderer());
    Draw(wind);
}

void Snake::Mouv(const char *dir){
    if(dir == "up"){
        if(head->next->GetDir() != *"down")
            body.y-=speed;
            Refresh(wind);
    }
    else if(dir == "down"){
        if(head->next->GetDir() != *"up")
        body.y+=speed;
        Refresh(wind);
    }
    else if(dir == "left"){
        if(head->next->GetDir() != *"right")
        body.x-=speed;
        Refresh(wind);
    }
    else if(dir == "right"){
        if(head->next->GetDir() != *"left")
        body.x+=speed;
        Refresh(wind);
    }
}
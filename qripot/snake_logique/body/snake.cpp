#include "snake.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Snake::Snake(MainSDLWindow *wind){
    this->head = NULL;
    this->wind = wind;

    Segment *seg = new Segment(800, 400, 'U');

    this->head = seg;
    this->scale = 50;
    this->border = false;
    AddSeg();
    random();
    this->eat = false;
    this->self = false;
}

Snake::~Snake(){
}

Segment Snake::GetHead(){
    return *head;
}

int Snake::getLen(void)
{
    Segment *temp = head;
    int bodyLen = 0;

    if (temp == NULL)
    {
        return 0;
    }

    while (temp != NULL)
    {
        bodyLen++;
        temp = temp->next;
    }

    return bodyLen;
}

void Snake::DeleteSeg(int segmentpos){
    Segment *temp1 = head, *temp2 = NULL;

    if (getLen() < segmentpos)
        return;
    temp1 = head;
    if (segmentpos == 1)
    {
        head = head->next;
        delete temp1;
        return;
    }
    while (segmentpos-- > 1)
    {
        temp2 = temp1;
        temp1 = temp1->next;
    }
    temp2->next = temp1->next;
    delete temp1;

}
void Snake::AddSeg(){

    int Xpos = head->GetX();
    int Ypos = head->GetY();

    if(head->GetDir() == 'U'){
        Ypos -= scale;
    }
    if(head->GetDir() == 'D'){
        Ypos += scale;
    }
    if(head->GetDir() == 'L'){
        Xpos -= scale;
    }
    if(head->GetDir() == 'R'){
        Xpos += scale;
    }
    Segment *newBody = new Segment(Xpos, Ypos, head->GetDir());
    newBody->SetX(Xpos);
    newBody->SetY(Ypos);
    newBody->next = head;
    head = newBody;
}

void Snake::Draw(){
    Segment *temp = head;

    if(head == NULL){
        return;
    }

    background.w = Width;
    background.h = Width;

    do{
        body.x = temp->GetX();
        body.y = temp->GetY();
        body.w = Width;
        body.h = Width;
        SDL_SetRenderDrawColor(wind->GetRenderer(),73,119,238,255);
        if (temp == head)
            SDL_SetRenderDrawColor(wind->GetRenderer(),119,73,238,255);
        SDL_RenderFillRect(wind->GetRenderer(), &body);
        SDL_SetRenderDrawColor(wind->GetRenderer(),255,0,0,255); 
        SDL_RenderFillRect(wind->GetRenderer(), &apple);  

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
    bool casse = true;
    for(countX = 0; countX<25; countX++){
        for(countY = 0; countY<17; countY++){
            background.x = countX*Width;
            background.y = countY*Width;
            if(casse == true){
                SDL_SetRenderDrawColor(wind->GetRenderer(),170,215,81,255);
                casse = false;
            }
            else{
                casse = true;
                SDL_SetRenderDrawColor(wind->GetRenderer(),162,209,73,255);
            }
            SDL_RenderFillRect(wind->GetRenderer(), &background); 
        }
    }
    Draw();
}

void Snake::Mouv(){
    if (head == NULL){
        return;
    }

    if(eat == true)
        AddSeg();
    DeleteSeg(getLen());
    AddSeg();
    CheckBorder();
    Refresh();
}

void Snake::random(){
    using std::cout;
    using std::endl;

    constexpr int MIN_X = 1;
    constexpr int MAX_X = 24;
    constexpr int MIN_Y = 1;
    constexpr int MAX_Y = 16;
    constexpr int RAND_NUMS_TO_GENERATE = 1;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distrX(MIN_X, MAX_X);
    std::uniform_int_distribution<int> distrY(MIN_Y, MAX_Y);
    
    cout << endl;

    pW = 25;
    apple = {distrX(eng)*50+12, distrY(eng)*50+12, pW, pW};
}

void Snake::CheckBorder(){
    Segment *temp = head;
    if(head->GetX() > -1 && head->GetX() < 1201 && head->GetY() > -1 && head->GetY() < 801){
        border = false;
    }
    else{
        border = true;
    }

    if(apple.x == head->GetX()+12 && apple.y == head->GetY()+12){
        eat = true;
    }
    else{
        eat = false;
    }

    while(temp->next != NULL){
    if(head->GetX() == temp->next->GetX() && head->GetY() == temp->next->GetY()){
        border = true;
    }
    if(temp->next != NULL)
        temp = temp->next;

    }
}
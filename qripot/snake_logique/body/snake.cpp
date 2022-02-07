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

}

Snake::~Snake(){
}

Segment Snake::GetHead(){
    return *head;
}

void Snake::AddSeg(){
    Segment *newBody = new Segment(Xpre, Ypre, DirPre);
    newBody->next = head;
    head = newBody;

    printf("en boucle\n");
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
}

void Snake::Mouv(){
    Xpre = head->GetX();
    Ypre = head->GetY();
    DirPre = head->GetDir();

    Segment *temp = head;
    if (head == NULL){
        return;
    }
 
    do{
        if(temp->GetDir() == 'U'){
            if(temp->GetDirOp() != 'D'){
            temp->SetY(temp->GetY()-scale);
            this->head->SetDirOp('U');
            }
        }
        if(temp->GetDir() == 'D'){
            if(temp->GetDirOp() != 'U'){
                temp->SetY(temp->GetY()+scale);
                this->head->SetDirOp('D');
            }
        }
        if(temp->GetDir() == 'L'){
            if(temp->GetDirOp() != 'R'){
                temp->SetX(temp->GetX()-scale);
                this->head->SetDirOp('L');
            }
        }
        if(temp->GetDir() == 'R'){
            if(temp->GetDirOp() != 'L'){
                temp->SetX(temp->GetX()+scale);
                this->head->SetDirOp('R');
            }
        }
        if(temp->next!=NULL){
            temp = temp->next;
        }
    }while(temp->next != NULL);
    Refresh();
    /*if(head->GetDir() == 'U'){
            head->SetY(head->GetY()-scale);
            Refresh();
            this->head->SetDirOp('U');
        }
    }
    else if(head->GetDir() == 'D'){
        if(head->GetDirOp() != 'U'){
            head->SetY(head->GetY()+scale);
            Refresh();
            this->head->SetDirOp('D');
        }
    }
    else if(head->GetDir() == 'L'){
        if(head->GetDirOp() != 'R'){
            head->SetX(head->GetX()-scale);
            Refresh();
            this->head->SetDirOp('L');
        }
    }
    else if(head->GetDir() == 'R'){
        if(head->GetDirOp() != 'L'){
            head->SetX(head->GetX()+scale);
            Refresh();
            this->head->SetDirOp('R');
        }
    }*/
    CheckBorder();
}

void Snake::CheckBorder(){
    if(head->GetX() > -1 && head->GetX() < 1201 && head->GetY() > -1 && head->GetY() < 801){
        border = false;
    }
    else{
        printf("bordure de la map toucher, fin du jeu\n");
        border = true;
    }
}
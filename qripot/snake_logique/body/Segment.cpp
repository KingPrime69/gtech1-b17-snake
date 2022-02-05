#include "Segment.hpp"

Segment::Segment(int x, int y, char dir){
    this->x = x;
    this->y = y;
    this->dir = dir;
    this->nbSeg = 0;
    this->next = NULL;
}

Segment::~Segment(){
    this->x=0;
    this->y=0;
    this->dir = *"";
}

void Segment::SetX(int x){
    this->x = x;
}

void Segment::SetY(int y){
    this->y = y;
}

int Segment::GetX(){
    return this->x;
}

int Segment::GetY(){
    return this->y;
}


void Segment::SetDirOp(char ChangeDir){
    printf("change dir to :%s\n", &ChangeDir);
    this->dir = ChangeDir;
}

char Segment::GetDir(){
    return this->dir;
}

#include "Segment.hpp"

Segment::Segment(int x_, int y_, char dir_){
    this->x = x_;
    this->y = y_;
    this->dir = dir_;
    this->next = NULL;
}

Segment::~Segment(){
}

void Segment::SetX(int x_){
    this->x = x_;
}

void Segment::SetY(int y_){
    this->y = y_;
}

int Segment::GetX(){
    return this->x;
}

int Segment::GetY(){
    return this->y;
}

void Segment::SetDir(char dir){
    this->dir = dir;
}

char Segment::GetDir(){
    return this->dir;
}


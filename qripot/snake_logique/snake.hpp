#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class Snake{
    public:
    Snake();
    ~Snake();
    int InitSnake();
    void Draw();
    void verifKey(bool game);
    void mouv(const char *dir);
    void refresh();
    void follow();
    bool continuer;


    private:
    MainSDLWindow *main_window;
    Apple *m_apple;
    SDL_Rect head;
    SDL_Rect body1;
    SDL_Rect body2;
    int aX1; 
    int aY1;
    int aX;
    int aY;
    int mX;
    int mY;
    int speed;
    int X;
    int Y;
    int w;
};
#endif
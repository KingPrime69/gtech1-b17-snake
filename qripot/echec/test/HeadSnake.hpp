#ifndef HEADSNAKE_HPP
#define HEADSNAKE_HPP

#include "main.hpp"


class HeadSnake{
    public:
    HeadSnake();
    ~HeadSnake();
    int InitH(void);
    void Draw();
    void verifKey(bool game);
    void mouv(const char *dir);
    void refresh();
    bool continuer;

    private:
    SDL_Renderer *rend_snake;
    MainSDLWindow *mainSDLwindow;
    int speed;
    int X;
    int Y;
    int w;
    SDL_Rect head;
};

#endif
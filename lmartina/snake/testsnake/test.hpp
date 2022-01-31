#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class MainSDLWindow{
    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *title, int x, int y);
    SDL_Renderer *GetRenderer(void);
    void Draw();
    void verifKey(bool game);
    void mouv(const char *dir);
    void refresh();
    bool continuer;
    void handle_input();
    void show();

    private:
    Uint32 frame_time_interval;
    Uint32 frame_time_start;
    Uint32 frame_rate;
    int speed;
    int X;
    int Y;
    int w;
    SDL_Surface *surface;
    SDL_Rect rect;
    SDL_Rect wall;
    SDL_Rect box;
    int xVel, yVel;
    SDL_Window *window;
    SDL_Renderer *renderer;
};
#endif
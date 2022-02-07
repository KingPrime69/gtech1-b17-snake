#ifndef TEST_HPP
#define TEST_HPP

#include <SDL2/SDL.h>
#include <SDL/SDL_ttf.h>
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
    TTF_Font *font;
    SDL_Rect rect;
    SDL_Surface *surface;
    SDL_Window *window;
    SDL_Renderer *renderer;
    SDL_Surface *TTF_RenderText_Shaded(TTF_Font *font, const char *text, SDL_Color fg, SDL_Color fond);
};
#endif
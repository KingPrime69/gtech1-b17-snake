#include "body/snake.hpp"
#include "mainSDLwindow.hpp"
#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

#define FPSLimit  152

void SDL_Limit_FPS(unsigned int limit, int FPS)
{
    unsigned int ticks = SDL_GetTicks();
    if (limit < ticks)
        return;
    else if (limit > ticks + FPS)
        SDL_Delay(FPS);
    else
        SDL_Delay(limit - ticks);
}

int main(void){
    MainSDLWindow *main_window = new MainSDLWindow();
    main_window->Init("Snake Game", 1250, 850);
    main_window->GetRenderer();

    Snake *main_snake = new Snake(main_window);
    main_snake->Draw();

    Game *game_run = new Game(main_snake);
    game_run->game = true;

    while(game_run->game == true){
        unsigned int frame_limit = SDL_GetTicks() + FPSLimit;
        game_run->verifKey(true);
        SDL_Limit_FPS(frame_limit, FPSLimit);
    }


    if (game_run != NULL)
        delete game_run;
        
    if (main_snake != NULL)
        delete main_snake;


    if (main_window != NULL)
        delete main_window;


}





/* compile:
 g++ main.cpp mainSDLwindow.cpp body/snake.cpp body/Segment.cpp game.cpp -lSDL2 -o main
 */
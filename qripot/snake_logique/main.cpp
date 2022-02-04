#include "body/snake.hpp"
#include "mainSDLwindow.hpp"
#include "game.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

int main(void){
    MainSDLWindow *main_window = new MainSDLWindow();
    main_window->Init("Snake Game", 1250, 850);
    main_window->GetRenderer();

    Snake *main_snake = new Snake(main_window);
    main_snake->Draw();


    Game *game_run = new Game();
    game_run->verifKey(true, main_snake);

    SDL_Delay(2000);
        
    if (main_snake != NULL)
        delete main_snake;

    if (game_run != NULL)
        delete game_run;

    if (main_window != NULL)
        delete main_window;


    // if (seg != NULL)
    //     delete seg;

}




/* compile:
 g++ main.cpp mainSDLwindow.cpp body/snake.cpp body/Segment.cpp game.cpp -lSDL2 -o main
 */
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
    printf("B\n");
    main_window->GetRenderer();
    printf("I\n");
    

    Snake *main_snake = new Snake();
    printf("T\n");
    main_snake->Draw(*main_window);

    Segment *seg = new Segment(650, 450, "up");


    Game *game_run = new Game();
    printf("E\n");
    game_run->verifKey(true, *main_snake);

    if (main_window != NULL)
        delete main_window;

    if (main_snake != NULL)
        delete main_snake;

    if (seg != NULL)
        delete seg;

    if (game_run != NULL)
        delete game_run;
}




/* compile:
 g++ main.cpp mainSDLwindow.cpp body/snake.cpp body/Segment.cpp game.cpp -lSDL2 -o main
 */
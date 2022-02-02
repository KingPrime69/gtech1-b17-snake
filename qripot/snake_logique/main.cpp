#include "snake.cpp"
#include "mainSDLwindow.cpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

void main(void){
    MainSDLWindow *main_window = new MainSDLWindow();
    main_window->Init("Snake Game", 1250, 850);

    Snake *main_snake = new Snake();

    if (main_snake != NULL)
        delete main_snake;

    if (main_window != NULL)
        delete main_window;
}
#include "main.hpp"

#include "game.hpp"
#include "snake.hpp"
#include "apple.hpp"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

//25 ligne
//17 colone

int main(int argc, char *argv[]){
    MainSDLWindow *main_window = new MainSDLWindow();
    main_window->Init("Snake Game", 1250, 850);

    Game *main_game = new Game();
    main_game->Draw(*main_window);
    main_game->continuer = true;

    while(main_game->continuer == true){
        main_game->verifKey(true);
        if(main_game->ref == true){
            main_game->refresh(*main_window);
            main_game->ref=false;
        }
    }

    if (main_game != NULL)
        delete main_game;

    if (main_window != NULL)
        delete main_window;
}
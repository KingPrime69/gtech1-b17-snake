#include "exercice3.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

MainSDLWindow::MainSDLWindow(){
    this->window = NULL;
    this->renderer = NULL;
}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int MainSDLWindow::Init(const char *title, int x, int y){
    if(SDL_Init(SDL_INIT_VIDEO) < 0){
       printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
       return EXIT_FAILURE;
    return EXIT_SUCCESS;
    SDL_CreateWindow("Une fenetre SDL" , SDL_WINDOWPOS_CENTERED , 
    SDL_WINDOWPOS_CENTERED , 600 , 600 , SDL_WINDOW_RESIZABLE);
    }
    SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if(renderer == NULL)
{
    printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
    return EXIT_FAILURE;
}
SDL_Delay(3000);
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this ->renderer;
}

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 1", 600, 600);
    SDL_Event e;
    for (;;) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            SDL_Log("Program quit after %i ticks", e.quit.timestamp);
            break;
        }
    }
    if (main_window != NULL)
        delete main_window;
}
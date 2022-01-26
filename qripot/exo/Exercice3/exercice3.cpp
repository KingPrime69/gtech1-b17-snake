#include "exercice3.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

MainSDLWindow::MainSDLWindow(){
    this->window = NULL;
    this->renderer = NULL;
}

int MainSDLWindow::Init(const char *title, int x, int y){

    if(SDL_Init(SDL_INIT_VIDEO) < 0){
       printf("Erreur d'initialisation de la SDL : %s",SDL_GetError());
       return EXIT_FAILURE;
    }

    X=260;
    Y=260;
    w=50;
    game = 1;

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_RESIZABLE);

    if(window == NULL){
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL){
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    SDL_RenderClear(renderer);
    Draw();
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this ->renderer;
}

void MainSDLWindow::Draw(){
    SDL_Event e;   
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_Rect rect = {X, Y, w, w};
    while (game == 1){
    const Uint8 *keystates = SDL_GetKeyboardState(NULL);

        if (keystates[SDL_SCANCODE_UP]) {
            rect.x++;
        }
        if (keystates[SDL_SCANCODE_DOWN]) {
            rect.x--;
        }
        if (keystates[SDL_SCANCODE_LEFT]) {
            rect.y++;
        }
        if (keystates[SDL_SCANCODE_RIGHT]) {
            rect.y--;
        }
        SDL_RenderFillRect(renderer, &rect); 
        SDL_RenderPresent(renderer);
        for (;;) {
            SDL_PollEvent(&e);
            if (e.type == SDL_QUIT) {
                SDL_Log("Program quit after %i ticks", e.quit.timestamp);
                game = 0;
                break;
            }
        }
    }
}

void MainSDLWindow::Refresh(){

}

MainSDLWindow::~MainSDLWindow(){
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 3", 600, 600);
    
    if (main_window != NULL)
        delete main_window;
}
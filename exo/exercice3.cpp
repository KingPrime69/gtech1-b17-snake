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
    }

    window = SDL_CreateWindow(title,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_RESIZABLE);

    if(window == NULL){
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL){
        printf("Erreur lors de la creation d'un renderer : %s",SDL_GetError());
        return EXIT_FAILURE;
    }
    Square();
    return EXIT_SUCCESS;

}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this ->renderer;
}

    
void MainSDLWindow::Square(){
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255 );
    square{x,y,100,100};
    SDL_RenderFillRect(renderer, &square);
    SDL_RenderPresent(renderer);
}

void MainSDLWindow::keyboard(){
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);
    if (keystates[SDL_SCANCODE_UP]) {
        square.x+=10;
    }
    if (keystates[SDL_SCANCODE_DOWN]) {
        square.x-=10;
    }
    if (keystates[SDL_SCANCODE_LEFT]) {
        square.y-=10;
    }
    if (keystates[SDL_SCANCODE_RIGHT]) {
        square.y+=10;
    }
}

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 3", 1920, 1080);
    SDL_Event e;
    for (;;) {
        SDL_PollEvent(&e);
        if (e.type == SDL_QUIT) {
            SDL_Log("Program quit after %i ticks", e.quit.timestamp);
            printf("Je Voudrai un Bonhomme de Neige!");
            break;
        }
    }
    if (main_window != NULL)
        delete main_window;
}

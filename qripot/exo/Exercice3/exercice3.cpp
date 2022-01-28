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

    frame_rate = 20;
    continuer = true;
    X=500;
    Y=500;
    w=50;
    speed = 5;
    rect = {X, Y, w, w};

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, x, y, SDL_WINDOW_RESIZABLE);

    if(window == NULL){
        printf("Erreur lors de la creation d'une fenetre : %s",SDL_GetError());
        return EXIT_FAILURE;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(renderer == NULL){
        printf("Erreur lors de la creation d'un renderer : %s\n",SDL_GetError());
        return EXIT_FAILURE;
    }

    Draw();
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this ->renderer;
}

void MainSDLWindow::Draw(){
    SDL_SetRenderDrawColor(renderer,255,0,0,255);
    SDL_RenderFillRect(renderer, &rect); 
    SDL_BlitSurface(surface, NULL, surface, &rect);
    SDL_RenderPresent(renderer);
    frame_time_interval = SDL_GetTicks() - frame_time_start;
}

void MainSDLWindow::refresh(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    Draw();
}

void MainSDLWindow::verifKey(bool game){
    if(frame_rate < frame_time_interval){
        SDL_Delay(20);
    }
    frame_time_start = SDL_GetTicks();
    SDL_Event(event);
    SDL_PollEvent(&event);
    if (event.type == SDL_QUIT) {
        SDL_Log("Program quit after %i ticks", event.quit.timestamp);
        continuer = false;
    }

    else if (event.type == SDL_KEYDOWN){   
        if (event.key.keysym.sym==SDLK_UP) {
            mouv("up");
        }
        if (event.key.keysym.sym==SDLK_DOWN) {
            mouv("down");
        }
        if (event.key.keysym.sym==SDLK_LEFT) {
            mouv("left");
        }
        if (event.key.keysym.sym==SDLK_RIGHT) {
            mouv("right");
        }
    }
    else if(event.type == SDL_KEYUP){
            mouv(NULL);
    }
}

void MainSDLWindow::mouv(const char *dir){
    if(dir == "up"){
        rect.y-=speed;
        refresh();
    }
    else if(dir == "down"){
        rect.y+=speed;
        refresh();
    }
    else if(dir == "left"){
        rect.x-=speed;
        refresh();
    }
    else if(dir == "right"){
        rect.x+=speed;
        refresh();
    }
}

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 3", 1000, 1000);

    while(main_window->continuer == true){
        main_window->verifKey(true);
    }

    if (main_window != NULL)
        delete main_window;
}
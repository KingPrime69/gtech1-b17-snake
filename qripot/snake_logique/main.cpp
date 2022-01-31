#include "main.hpp"
#include "snake.cpp"
#include "apple.cpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

//25 ligne
//17 colone

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

    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this ->renderer;
}

void Snake::Draw(){
    SDL_SetRenderDrawColor(main_window->renderer,255,0,0,255);
    SDL_RenderFillRect(main_window->renderer, &head);
    SDL_SetRenderDrawColor(main_window->renderer,0,0,255,255); 
    SDL_RenderFillRect(main_window->renderer, &body1); 
    SDL_SetRenderDrawColor(main_window->renderer,100,100,255,255); 
    SDL_RenderFillRect(main_window->renderer, &body2);  
    SDL_RenderPresent(main_window->renderer);
}

void Snake::refresh(){
    SDL_SetRenderDrawColor(main_window->renderer, 0, 0, 0, 255);
    SDL_RenderClear(main_window->renderer);
    Draw();
    m_apple->DrawAppel();
}

void Snake::verifKey(bool game){
    SDL_Event(event);
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) {
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            continuer = false;
        }

        else if (event.type == SDL_KEYDOWN){
            aX = head.x;
            aY = head.y;
            aX1 = body1.x;
            aY1 = body1.y;
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
}

void Snake::mouv(const char *dir){
    if(dir == "up"){
        head.y-=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        refresh();
    }
    else if(dir == "down"){
        head.y+=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        refresh();
    }
    else if(dir == "left"){
        head.x-=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        refresh();
    }
    else if(dir == "right"){
        head.x+=speed;
        body1.y = aY;
        body1.x = aX;
        body2.y = aY1;
        body2.x = aX1;
        refresh();
    }
} 

/*
void MainSDLWindow::follow(){

}
*/

void Apple::DrawAppel(){
    SDL_SetRenderDrawColor(main_window->renderer,255,0,0,255); 
    SDL_RenderFillRect(main_window->renderer, &apple);  
    SDL_RenderPresent(main_window->renderer);
}

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 3", 1250, 850);

    Snake *main_snake;
    main_snake = NULL;
    main_snake = new Snake();

    while(main_snake->continuer == true){
        main_snake->verifKey(true);
    }
    if (main_snake != NULL)
        delete main_snake;
    if (main_window != NULL)
        delete main_window;
}
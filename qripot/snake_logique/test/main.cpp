#include "main.hpp"
#include "HeadSnake.hpp"
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
    main_snake->Draw();
    return EXIT_SUCCESS;
}

SDL_Renderer * MainSDLWindow::GetRenderer(void){
    return this ->renderer;
}

HeadSnake::HeadSnake(){
    continuer = true;
    X=500;
    Y=500;
    w=50;
    speed = 10;
    head = {X, Y, w, w};
    this->rend_snake;
   
}

HeadSnake::~HeadSnake(){

}

int HeadSnake::InitH(void){
    rend_snake = SDL_CreateRenderer(mainSDLwindow->window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    if(rend_snake == NULL){
        printf("Erreur lors de la creation d'un renderer : %s\n",SDL_GetError());
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

void HeadSnake::Draw(){
    SDL_SetRenderDrawColor(rend_snake,255,0,0,255);
    SDL_RenderFillRect(rend_snake, &head); 
    SDL_RenderPresent(rend_snake);
}

void HeadSnake::refresh(){
    //SDL_SetRenderDrawColor(mainSDLwindow->renderer, 0, 0, 0, 255);
    SDL_RenderClear(rend_snake);
    Draw();
}

void HeadSnake::verifKey(bool game){
    SDL_Event(event);
    while(SDL_PollEvent(&event)){
        if (event.type == SDL_QUIT) {
            SDL_Log("Program quit after %i ticks", event.quit.timestamp);
            continuer = false;
        }

        else if (event.type == SDL_KEYDOWN){ 
            if (event.key.keysym.sym==SDLK_UP) {
                mouv("up");
                mouv(NULL);
            }
            if (event.key.keysym.sym==SDLK_DOWN) {
                mouv("down");
                mouv(NULL);
            }
            if (event.key.keysym.sym==SDLK_LEFT) {
                mouv("left");
                mouv(NULL);
            }
            if (event.key.keysym.sym==SDLK_RIGHT) {
                mouv("right");
                mouv(NULL);
            }
        }
        else if(event.type == SDL_KEYUP){
                mouv(NULL);
        }
    }
}

void HeadSnake::mouv(const char *dir){
    if(dir == "up"){
        head.y-=speed;
        refresh();
    }
    else if(dir == "down"){
        head.y+=speed;
        refresh();
    }
    else if(dir == "left"){
        head.x-=speed;
        refresh();
    }
    else if(dir == "right"){
        head.x+=speed;
        refresh();
    }
} 

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 3", 1000, 1000);

    HeadSnake *head_snake;
    head_snake = NULL;
    head_snake = new HeadSnake();

    while(head_snake->continuer == true){
        head_snake->verifKey(true);
    }

    if (main_window != NULL)
        delete main_window;
}
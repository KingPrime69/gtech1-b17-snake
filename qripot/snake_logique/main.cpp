#include "main.hpp"
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

    

    continuer = true;
    X=650;
    Y=450;
    w=50;
    speed = 50;
    head = {X, Y, w, w};
    body1 = {X, Y+50, w, w};
    body2 = {X, Y+100, w, w};

    using std::cout;
    using std::endl;

    constexpr int MIN_X = 1;
    constexpr int MAX_X = 25;
    constexpr int MIN_Y = 1;
    constexpr int MAX_Y = 17;
    constexpr int RAND_NUMS_TO_GENERATE = 1;

    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distrX(MIN_X, MAX_X);
    std::uniform_int_distribution<int> distrY(MIN_Y, MAX_Y);

    for (int n = 0; n < RAND_NUMS_TO_GENERATE; ++n) {
        cout << distrX(eng) << "; ";
        cout << distrY(eng) << "; ";
    }
    cout << endl;

    pW = 25;
    apple = {distrX(eng)*50+12, distrY(eng)*50+12, pW, pW};

    printf("%d\n", distrX(eng));

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
    SDL_RenderFillRect(renderer, &head);
    SDL_SetRenderDrawColor(renderer,0,0,255,255); 
    SDL_RenderFillRect(renderer, &body1); 
    SDL_SetRenderDrawColor(renderer,100,100,255,255); 
    SDL_RenderFillRect(renderer, &body2);  
    SDL_RenderPresent(renderer);
}

void MainSDLWindow::refresh(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    Draw();
    DrawAppel();
}

void MainSDLWindow::verifKey(bool game){
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

void MainSDLWindow::mouv(const char *dir){
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

void MainSDLWindow::DrawAppel(){
    SDL_SetRenderDrawColor(renderer,255,0,0,255); 
    SDL_RenderFillRect(renderer, &apple);  
    SDL_RenderPresent(renderer);
    printf("%d, %d \n", apple.x, apple.y);

}

int main(int argc, char *argv[]){
    MainSDLWindow *main_window;
    main_window = NULL;
    main_window = new MainSDLWindow();
    main_window->Init("exercice 3", 1250, 850);

    while(main_window->continuer == true){
        main_window->verifKey(true);
    }

    if (main_window != NULL)
        delete main_window;
}
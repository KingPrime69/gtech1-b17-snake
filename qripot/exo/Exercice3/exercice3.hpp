#ifndef EXERCICE3_HPP
#define EXERCICE3_HPP

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>

class MainSDLWindow{
    public:
    MainSDLWindow();
    ~MainSDLWindow();
    int Init(const char *title, int x, int y);
    SDL_Renderer *GetRenderer(void);

    private:
    SDL_Window *window;
    SDL_Renderer *renderer;
};

void keyboard() {
  const Uint8 *keystates = SDL_GetKeyboardState(NULL);

  if (keystates[SDL_SCANCODE_UP]) {
     ...
  }
  if (keystates[SDL_SCANCODE_DOWN]) {
    ...
  }
  if (keystates[SDL_SCANCODE_LEFT]) {
    ...
  }
  if (keystates[SDL_SCANCODE_RIGHT]) {
    ...
  }
}
#endif
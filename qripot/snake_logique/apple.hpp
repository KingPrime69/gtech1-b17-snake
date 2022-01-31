#ifndef APPLE_HPP
#define APPLE_HPP

class Apple{
    public:
    Apple();
    ~Apple();
    int InitApple();
    void DrawAppel();  

    private:
    MainSDLWindow *main_window;
    Snake *main_snake;
    MainSDLWindow *m_window;
    int pW;
    SDL_Rect apple;
};
#endif
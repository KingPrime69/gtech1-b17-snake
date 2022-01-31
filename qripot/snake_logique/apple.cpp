#include "apple.hpp"
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <random>
#include <iostream>

Apple::Apple(){

}

Apple::~Apple(){

}

int Apple::InitApple(){
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
}
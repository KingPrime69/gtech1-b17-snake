# gtech1-b17-snake
Snake was programmed in C++ with the SDL2 library

# Authors
- KingPrime69
- XiiNox83

# How to compile it
Install SDL2 dev tools :
sudo apt install libsdl2-dev

So we compile with the command:
g++ main.cpp mainSDLwindow.cpp body/snake.cpp body/Segment.cpp game.cpp -lSDL2 -o main

# How to start the game
We can start the game thanks to the command:
./main

# How to play
The snake can move through the grid of the game at a continuous pace. The player can change direction using the directional arrows on the keyboard. 

The goal is to eat apples to make your snake grow more and more. But be careful where you set foot. You are not allowed to hit the borders of the screen or any of the segments of the snake.

You need to get the highest possible score without colliding with items other than apples.

# The Fruits
In the game we can meet different types of fruits :

- Simple Fruits : These are the fruits with the most common effects, this allows you to grow your snake by 1 segment.
- Double fruits: These are some special fruits, this allows you to acquire not 1 segment but this time 2.
- Dangerous fruits: These fruits are rather harmful to the snake, if it eats it poisons itself and therefore loses 1 segment.

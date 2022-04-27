#include <iostream>
#include <stdexcept>

#include "Game.h"

int main() {
    try {
        printf("1\n");
        Game game;
        game.run();
    } catch (std::exception& exeption) {
        std::cout << std::endl << "EXCEPTION: " << exeption.what() << std::endl;
    }
}
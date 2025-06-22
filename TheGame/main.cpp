

#include "engine.hpp"


int main()
{

    Engine game;

    if (!game.init()){
        return -1;
    }

    while (game.isOpen())
    {
        // returns false if the app is closed
        if (!game.update()) {
            return 0;
        }
        game.draw();
    }

}
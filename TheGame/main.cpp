

#include "engine.hpp"


int main()
{

    Engine game;

    // returns false if engine couldn't initialize
    if (!game.init()){
        return -1;
    }

    while (game.isOpen())
    {
        // returns false if the app was closed
        if (!game.update()) {
            return 0;
        }
        game.render();
    }

}


#include "engine.hpp"
#include "player.hpp"
#include "resourceManager.hpp"


int main()
{

    Engine game;

    // returns false if engine couldn't initialize
    if (!game.init()){
        return -1;
    }

    ResourceManager resManager;
    resManager.loadTexture("../TheGame/resources/spritesheets/drifter-idle.png");
    Player player(&resManager, 1);

    while (game.isOpen())
    {
        // returns false if the app was closed
        if (!game.update()) {
            return 0;
        }
        player.draw(game.getWindow());
        game.render();
    }

}


#include <sprite.hpp>

#include "engine.hpp"
#include "player.hpp"

int main() {
    Engine game;
    game.createWindow({1400, 700}, "LongLostDrifter");

    // returns false if engine couldn't initialize
    if (!game.initRenderer()) {
        return -1;
    }

    game.resourceManager->loadTexture(
        "../TheGame/resources/spritesheets/Drifter.png");

    Player Drifter(&game);
    Sprite Drifter_Sprite(&game, 1, 7, 11);
    Drifter.setSprite(&Drifter_Sprite);

    while (game.isOpen()) {
        // returns false if the app was closed
        if (!game.update()) {
            return 0;
        }

        Drifter.update();
        Drifter.draw(game.getWindow());
        game.render();
    }
}


#include "engine.hpp"
#include "player.hpp"
#include "resourceManager.hpp"

int main() {
  Engine game({1400, 700}, "Lost Lore v0.0.1 SFML + IMGUI");

  // returns false if engine couldn't initialize
  if (!game.init()) {
    return -1;
  }

  ResourceManager resManager;
  resManager.loadTexture("../TheGame/resources/spritesheets/Drifter.png");

  Player drifter(&resManager, 1, 7, 11, sf::Vector2i(0, 0));

  while (game.isOpen()) {
    // returns false if the app was closed
    if (!game.update()) {
      return 0;
    }

    drifter.draw(game.getWindow());
    game.render();
  }
}
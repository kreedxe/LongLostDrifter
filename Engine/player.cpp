

#include "player.hpp"

Player::Player(ResourceManager* resourceManager, int textureID, int Xtiles,
               int Ytiles, sf::Vector2i idleTile)
    : Texture_Xtiles(Xtiles),
      Texture_Ytiles(Ytiles),
      Texture_TileSizeX(resourceManager->getTexture(textureID)->getSize().x /
                        Xtiles),
      Texture_TileSizeY(resourceManager->getTexture(textureID)->getSize().y /
                        Ytiles),
      Texture_CurrentTile(idleTile),
      Texture(resourceManager->getTexture(textureID)),
      Sprite(*Texture, sf::IntRect({0, 0}, {50, 37})),
      position({200, 200}) {
  Sprite.setPosition(position);
}

Player::~Player() {}

void Player::draw(sf::RenderWindow& window) { window.draw(Sprite); }
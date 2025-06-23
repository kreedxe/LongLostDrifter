

#include "player.hpp"


Player::Player(ResourceManager* resourceManager, int textureID):
texture(resourceManager->getTexture(textureID)),
sprite(*texture),
position({200, 200})
{
    sprite.setPosition(position);
}


Player::~Player()
{

}


void Player::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}
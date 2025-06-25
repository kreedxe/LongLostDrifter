

#include "player.hpp"

Player::Player(Engine* engine) : sprite(nullptr), game(nullptr) {
    game = engine;
}

Player::~Player() {}

void Player::draw(sf::RenderWindow* window) {
    window->draw(*sprite->sf_Sprite);
}

void Player::setSprite(Sprite* sprite) { this->sprite = sprite; }
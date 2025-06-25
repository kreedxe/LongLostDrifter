

#include "player.hpp"

Player::Player(Engine* engine) : sprite(nullptr), game(nullptr) {
    game = engine;
}

Player::~Player() {}

void Player::draw(sf::RenderWindow* window) { window->draw(*sprite->s_Sprite); }

void Player::setSprite(Sprite* sprite) { this->sprite = sprite; }

void Player::update() {
    velocity = {0, 0};
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
        velocity.y -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
        velocity.y += 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
        velocity.x -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
        velocity.x += 1;
    }

    if (velocity.x && velocity.y) {
        velocity = velocity.normalized();
    }

    position += velocity * speed * game->DeltaTime;

    sprite->s_Sprite->setPosition(position);
}
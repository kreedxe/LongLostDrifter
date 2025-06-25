

#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <engine.hpp>
#include <sprite.hpp>

class Player {
private:
    sf::Vector2f position = {0, 0};
    Engine* game;
    Sprite* sprite;

    sf::Vector2f velocity = {0, 0};
    float speed = 5.0f;

public:
    Player(Engine* engine);
    ~Player();

    void setSprite(Sprite* sprite);
    void update();
    void draw(sf::RenderWindow* window);
};
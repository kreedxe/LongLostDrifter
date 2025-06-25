

#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <engine.hpp>
#include <sprite.hpp>

class Player {
private:
    sf::Vector2f position;
    Engine* game;
    Sprite* sprite;

public:
    Player(Engine* engine);
    ~Player();

    void setSprite(Sprite* sprite);
    void draw(sf::RenderWindow* window);
};
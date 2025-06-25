
#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <engine.hpp>

class Sprite {
public:
    sf::Sprite* s_Sprite = nullptr;

private:
    Engine* s_Engine = nullptr;

    sf::Texture* s_Texture = nullptr;
    sf::Vector2u s_Texture_Size = {1, 1};
    uint s_Texture_ID = 0;

    sf::Vector2u s_Tile_Amount = {1, 1};
    sf::Vector2i s_Tile_Size = {1, 1};

    sf::Vector2i s_Tilesets_Idle = {0, 0};

public:
    Sprite(Engine* engine, uint textureID, uint TilesInX, uint TilesInY);
    ~Sprite();

private:
    sf::IntRect getTileRect(sf::Vector2i Tile);
};
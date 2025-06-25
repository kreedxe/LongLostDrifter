
#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <engine.hpp>

class Sprite {
public:
    sf::Sprite* sf_Sprite;

private:
    Engine* game;
    sf::Texture* sf_Texture;

    sf::Vector2u Texture_Tiles;
    sf::Vector2f Texture_TileSize;
    sf::Vector2u Texture_Size;

    sf::Vector2u Tilesets_Idle;
    uint textureID;

public:
    Sprite(Engine* engine, uint textureID, uint TilesInX, uint TilesInY);
    ~Sprite();
};
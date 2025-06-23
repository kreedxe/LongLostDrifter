

#pragma once


#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>
#include <resourceManager.hpp>


class Player 
{

private:
    sf::Vector2f position;
    sf::Texture* texture;
    sf::Sprite sprite;

public:
    Player(ResourceManager* resourceManager, int textureID);
    ~Player();

    void draw(sf::RenderWindow& window);

};
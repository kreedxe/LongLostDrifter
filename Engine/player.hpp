

#pragma once

#include <imgui-SFML.h>
#include <imgui.h>

#include <SFML/Graphics.hpp>
#include <resourceManager.hpp>

class Player {
 private:
  sf::Vector2f position;
  sf::Texture* Texture;
  sf::Sprite Sprite;

  int Texture_Xtiles;
  int Texture_Ytiles;
  int Texture_TileSizeX;
  int Texture_TileSizeY;

  sf::Vector2i Texture_CurrentTile;

 public:
  Player(ResourceManager* resourceManager, int textureID, int Xtiles,
         int Ytiles, sf::Vector2i idleTile);
  ~Player();

  void draw(sf::RenderWindow& window);
};
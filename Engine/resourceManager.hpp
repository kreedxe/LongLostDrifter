

#pragma once

#include <SFML/Graphics.hpp>

class ResourceManager {
 private:
  std::vector<sf::Texture*> textures;

 public:
  int loadTexture(std::string path);
  sf::Texture* getTexture(int id);

  ResourceManager();
  ~ResourceManager();
};
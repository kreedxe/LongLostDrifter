

#include "resourceManager.hpp"

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {
  for (int i = 0; i < textures.size(); i++) {
    delete textures.at(i);
  }
}

int ResourceManager::loadTexture(std::string path) {
  sf::Texture* texture = new sf::Texture();
  texture->loadFromFile(path);
  textures.push_back(texture);

  return textures.size();
}

sf::Texture* ResourceManager::getTexture(int id) { return textures.at(id - 1); }
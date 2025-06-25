

#include "resourceManager.hpp"

#include <iostream>

ResourceManager::ResourceManager() {}

ResourceManager::~ResourceManager() {
    for (int i = 0; i < textures.size(); i++) {
        delete textures.at(i);
    }
}

int ResourceManager::loadTexture(std::string path) {
    sf::Texture* texture = new sf::Texture();
    if (texture->loadFromFile(path)) {
        textures.push_back(texture);
    } else {
        std::cout << "Failed to load texture: " << path << " with ID "
                  << textures.size() << std::endl;
    }

    return textures.size();
}

sf::Texture* ResourceManager::getTexture(int id) { return textures.at(id - 1); }
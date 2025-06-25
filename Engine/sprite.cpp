

#include <sprite.hpp>

Sprite::Sprite(Engine* engine, uint textureID, uint TilesInX, uint TilesInY)
    : game(nullptr),
      sf_Texture(nullptr),
      sf_Sprite(nullptr),
      Tilesets_Idle(sf::Vector2u(0, 0)),
      textureID(0),
      Texture_Size(sf::Vector2u()),
      Texture_Tiles(sf::Vector2u()),
      Texture_TileSize(sf::Vector2f()) {
    game = engine;
    this->textureID = textureID;
    sf_Texture = game->resourceManager->getTexture(this->textureID);
    sf_Sprite = new sf::Sprite(*sf_Texture);

    Texture_Size = sf_Texture->getSize();
    Texture_Tiles = sf::Vector2u(TilesInX, TilesInY);
    Texture_TileSize = sf::Vector2f(Texture_Size.x / Texture_Tiles.x,
                                    Texture_Size.y / Texture_Tiles.y);

    sf_Sprite->setTextureRect(
        sf::IntRect(sf::Vector2i(0, 0), sf::Vector2i(Texture_TileSize)));
}

Sprite::~Sprite() { delete sf_Sprite; }
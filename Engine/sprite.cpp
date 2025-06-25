

#include <sprite.hpp>

Sprite::Sprite(Engine* engine, uint textureID, uint TilesInX, uint TilesInY) {
    s_Engine = engine;
    s_Texture_ID = textureID;
    s_Texture = s_Engine->resourceManager->getTexture(s_Texture_ID);
    s_Sprite = new sf::Sprite(*s_Texture);

    s_Texture_Size = s_Texture->getSize();
    s_Tile_Amount = sf::Vector2u(TilesInX, TilesInY);
    s_Tile_Size = sf::Vector2i(s_Texture_Size.x / s_Tile_Amount.x,
                               s_Texture_Size.y / s_Tile_Amount.y);

    s_Sprite->setTextureRect(getTileRect(s_Tilesets_Idle));
    s_Sprite->setScale({5, 5});
}

Sprite::~Sprite() { delete s_Sprite; }

sf::IntRect Sprite::getTileRect(sf::Vector2i Tile) {
    return sf::IntRect(
        sf::Vector2i(Tile.x * s_Tile_Size.x, Tile.y * s_Tile_Size.y),
        s_Tile_Size);
}
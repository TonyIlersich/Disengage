#include "AssetManager.h"

sf::Texture AssetManager::preloadedTextures[Texture::NUM_TEXTURES];

void AssetManager::init()
{
	// TODO: handle failure to load images
	const std::string prefix = "../Assets/Sprites/";
	preloadedTextures[Texture::BLOCK_EMPTY].loadFromFile(prefix + "block_empty.png");
	preloadedTextures[Texture::BLOCK_HULL].loadFromFile(prefix + "block_hull.png");
}

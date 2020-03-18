#pragma once

#include "includes.h"

class AssetManager
{
public:

	enum Texture
	{
		NONE = -1,
		BLOCK_EMPTY = 0,
		BLOCK_HULL,
		NUM_TEXTURES
	};

	static sf::Texture preloadedTextures[Texture::NUM_TEXTURES];

	static void init();
};

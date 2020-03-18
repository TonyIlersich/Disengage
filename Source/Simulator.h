#pragma once

#include "includes.h"
#include "GameObject.h"

class Simulator
{
	static std::vector<GameObject*> gameObjects;

public:

	static void init();
	static void update();
	static void drawTo(sf::RenderTarget& target);
	static void addObject(GameObject* object);
};
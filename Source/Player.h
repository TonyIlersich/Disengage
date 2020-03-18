#pragma once

#include "includes.h"
#include "GameObject.h"

class PlayerObject;

class Player
{
	static PlayerObject playerObject;

public:

	static void init();
	static void update();
	static sf::Vector2f getPosition();
};

class PlayerObject : public GameObject
{
	sf::CircleShape circle;

protected:

	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

public:

	PlayerObject();
	void update() override;
};
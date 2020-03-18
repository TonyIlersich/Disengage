#include "Simulator.h"
#include "Spaceship.h"

std::vector<GameObject*> Simulator::gameObjects;

void Simulator::init()
{
	gameObjects.reserve(1000);
	Spaceship* ss = new Spaceship();
	ss->loadFromFile("basic.spaceship");
	gameObjects.push_back(ss);
}

void Simulator::update()
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]) gameObjects[i]->update();
	}
}

void Simulator::drawTo(sf::RenderTarget& target)
{
	for (size_t i = 0; i < gameObjects.size(); i++)
	{
		if (gameObjects[i]) target.draw(*gameObjects[i]);
	}
}

void Simulator::addObject(GameObject* object)
{
	gameObjects.push_back(object);
}

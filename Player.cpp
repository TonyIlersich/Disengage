#include "Player.h"
#include "Simulator.h"
#include "TimeManager.h"
#include "InputManager.h"

//==============================================================================
// PLAYER
//==============================================================================

PlayerObject Player::playerObject;

void Player::init()
{
	Simulator::addObject(&playerObject);
}

void Player::update()
{
	sf::Vector2f direction;
	if (InputManager::isKeyDown(InputManager::KeyName::MOVE_UP))
	{
		direction += sf::Vector2f(0, -1);
	}
	if (InputManager::isKeyDown(InputManager::KeyName::MOVE_DOWN))
	{
		direction += sf::Vector2f(0, 1);
	}
	if (InputManager::isKeyDown(InputManager::KeyName::MOVE_LEFT))
	{
		direction += sf::Vector2f(-1, 0);
	}
	if (InputManager::isKeyDown(InputManager::KeyName::MOVE_RIGHT))
	{
		direction += sf::Vector2f(1, 0);
	}
	const sf::Vector2f step = direction * TimeManager::getFrameDuration().asSeconds();
	playerObject.move(step);
}

//==============================================================================
// PLAYER OBJECT
//==============================================================================

void PlayerObject::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(circle, getTransform());
}

PlayerObject::PlayerObject()
{
	circle.setRadius(.5);
	circle.setOrigin(.5, .5);
	circle.setFillColor(sf::Color::Green);
}

void PlayerObject::update()
{
}

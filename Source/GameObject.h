#pragma once

#include "includes.h"
#include "CollisionUtils.h"

class GameObject :
	public sf::Drawable,
	public sf::Transformable,
	public CollisionUtils::Collidable
{
public:

	virtual void update() = 0;
};
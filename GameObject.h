#pragma once

#include "includes.h"

class GameObject : public sf::Drawable, public sf::Transformable
{
public:

	virtual void update() = 0;
};
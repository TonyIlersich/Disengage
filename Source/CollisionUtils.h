#pragma once

#include "includes.h"

namespace CollisionUtils
{
	typedef uint16_t LayerMask;
	constexpr LayerMask
		NONE		=    0x0,
		SPACESHIP	=    0x1,
		BLOCK		=    0x2,
		PLAYER		=    0x4,
		RESERVED04	=    0x8,
		RESERVED05	=   0x10,
		RESERVED06	=   0x20,
		RESERVED07	=   0x40,
		RESERVED08	=   0x80,
		RESERVED09	=  0x100,
		RESERVED10	=  0x200,
		RESERVED11	=  0x400,
		RESERVED12	=  0x800,
		RESERVED13	= 0x1000,
		RESERVED14	= 0x2000,
		RESERVED15	= 0x4000,
		RESERVED16	= 0x8000,
		ALL			= 0xffff;

	float cross2D(const sf::Vector2f& v, const sf::Vector2f& w);

	bool checkIntersection(
		const sf::Vector2f& a,
		const sf::Vector2f& b,
		const sf::Vector2f& c,
		const sf::Vector2f& d,
		sf::Vector2f& result
	);

	typedef std::vector<sf::Vector2f> PointVec;

	bool checkIntersection(
		const Collidable& col1,
		const Collidable& col2,
		PointVec& results
	);

	class Collidable : sf::Transformable
	{
		friend bool checkIntersection(
			const Collidable& col1,
			const Collidable& col2,
			PointVec& results
		);

	protected:

		LayerMask layerMask;
		PointVec points;
		sf::Vector2f centerOfMass;
	};
}
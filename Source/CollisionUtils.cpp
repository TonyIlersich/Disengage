#include "CollisionUtils.h"
#include "MathUtils.h"

float CollisionUtils::cross2D(const sf::Vector2f& v, const sf::Vector2f& w)
{
	return v.x * w.y - v.y * w.x;
}

bool CollisionUtils::checkIntersection(
	const sf::Vector2f& a,
	const sf::Vector2f& b,
	const sf::Vector2f& c,
	const sf::Vector2f& d,
	sf::Vector2f& result)
{
	const sf::Vector2f ab = b - a;
	const sf::Vector2f cd = d - c;
	const sf::Vector2f ac = c - a;
	const float t = cross2D(ac, cd / cross2D(ab, cd));
	const float u = cross2D(ac, ab / cross2D(ab, cd));
	if (cross2D(ab, cd) != 0.f && inRange(t, 0, 1) && inRange(u, 0, 1))
	{
		result = a + t * ab;
		return true;
	}
	return false;
}

// TODO: look for ways to optimize, currently O(nm)
bool CollisionUtils::checkIntersection(const Collidable& col1, const Collidable& col2, PointVec& results)
{
	results.clear();
	sf::Vector2f poi;
	const sf::Transform& t1 = col1.getTransform();
	const sf::Transform& t2 = col2.getTransform();
	const int n1 = col1.points.size();
	const int n2 = col2.points.size();
	for (int i = 0; i < n1; i++)
	{
		const sf::Vector2f& a = t1.transformPoint(col1.points[i]);
		const sf::Vector2f& b = t1.transformPoint(col1.points[(i + 1) % n1]);
		for (int j = 0; j < n2; j++)
		{
			const sf::Vector2f& c = t2.transformPoint(col2.points[j]);
			const sf::Vector2f& d = t2.transformPoint(col2.points[(j + 1) % n1]);
			if (checkIntersection(a, b, c, d, poi))
			{
				results.push_back(poi);
			}
		}
	}
	return results.size() > 1;
}

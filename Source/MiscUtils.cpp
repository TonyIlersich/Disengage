#include "MiscUtils.h"

template <typename T>
size_t MiscUtils::hashVector(const sf::Vector2<T>& v)
{
	return std::hash<T>()(v.x) ^ std::hash<T>()(v.y);
}

template size_t MiscUtils::hashVector<int>(const sf::Vector2<int>&);

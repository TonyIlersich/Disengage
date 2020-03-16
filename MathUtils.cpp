#include "MathUtils.h"

float clamp(float x, float a, float b)
{
	float low = std::min(a, b);
	float high = std::max(a, b);
	return x < low ? low : (x > high ? high : x);
}

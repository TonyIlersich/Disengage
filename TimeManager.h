#pragma once

#include "includes.h"

struct Stopwatch;

class TimeManager
{
	static sf::Time frameStart;
	static sf::Time frameDuration;
	static sf::Clock realTime;
	static Stopwatch gameTime;

public:

	static void onFrameStart();
	static void pause();
	static void unpause();
	static bool getIsPaused();
	static sf::Time getRealTime();
	static sf::Time getGameTime();
	static sf::Time getFrameDuration();
};

struct Stopwatch
{
	sf::Time accumulatedTime;
	sf::Clock clock;
	bool isPaused;

public:

	Stopwatch();
	void pause();
	void unpause();
	bool getIsPaused();
	sf::Time getTime();
};
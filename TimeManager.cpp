#include "TimeManager.h"

//==============================================================================
// TIMEMANAGER
//==============================================================================

sf::Time TimeManager::frameStart;
sf::Time TimeManager::frameDuration;
sf::Clock TimeManager::realTime;
Stopwatch TimeManager::gameTime;

void TimeManager::onFrameStart()
{
	sf::Time now = realTime.getElapsedTime();
	frameDuration = now - frameStart;
	frameStart = now;
	// TEMP: print framerate
	std::cout << "FPS: " << std::setprecision(3) <<  1 / frameDuration.asSeconds() << std::endl;
}

void TimeManager::pause()
{
	gameTime.pause();
}

void TimeManager::unpause()
{
	gameTime.unpause();
}

bool TimeManager::getIsPaused()
{
	return gameTime.getIsPaused();
}

sf::Time TimeManager::getRealTime()
{
	return realTime.getElapsedTime();
}

sf::Time TimeManager::getGameTime()
{
	return gameTime.getTime();
}

sf::Time TimeManager::getFrameDuration()
{
	return frameDuration;
}

//==============================================================================
// STOPWATCH
//==============================================================================

Stopwatch::Stopwatch() : accumulatedTime{ sf::Time::Zero }, isPaused{ false } {}

void Stopwatch::pause()
{
	if (isPaused) return;
	isPaused = true;
	accumulatedTime += clock.getElapsedTime();
}

void Stopwatch::unpause()
{
	if (!isPaused) return;
	isPaused = false;
	clock.restart();
}

bool Stopwatch::getIsPaused()
{
	return isPaused;
}

sf::Time Stopwatch::getTime()
{
	if (isPaused) return accumulatedTime;
	else return clock.getElapsedTime() + accumulatedTime;
}

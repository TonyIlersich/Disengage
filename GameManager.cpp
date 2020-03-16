#include "GameManager.h"
#include "WindowManager.h"
#include "InputManager.h"
#include "TimeManager.h"
#include "Simulator.h"
#include "Player.h"

void GameManager::init()
{
	WindowManager::init();
	InputManager::init();
	Simulator::init();
	Player::init();
}

bool GameManager::update()
{
	TimeManager::onFrameStart();
	InputManager::onFrameStart();
	WindowManager::handleEvents();
	Player::update();
	Simulator::update();
	WindowManager::update();
	WindowManager::redraw();
	return WindowManager::isOpen();
}

void GameManager::run()
{
	init();
	while (update());
}

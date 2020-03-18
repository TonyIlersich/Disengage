#include "WindowManager.h"
#include "InputManager.h"
#include "Simulator.h"
#include "Player.h"
#include "TimeManager.h"
#include "MathUtils.h"

sf::RenderWindow WindowManager::window;
float WindowManager::zoom = 10.f;
float WindowManager::targetZoom = 10.f;

float WindowManager::getWindowAspect()
{
	sf::Vector2f size(window.getSize());
	return size.x / size.y;
}

void WindowManager::resetView()
{
	const sf::Vector2f prevCenter = window.getView().getCenter();
	const sf::Vector2f center = Player::getPosition() * .1f + prevCenter * .9f;
	const sf::Vector2f size = sf::Vector2f(zoom, zoom / getWindowAspect());
	window.setView(sf::View(center, size));
}

void WindowManager::init()
{
	window.create(sf::VideoMode(640, 360), "Disengage");
	window.setVerticalSyncEnabled(true);
	window.setKeyRepeatEnabled(false);
	resetView();
}

void WindowManager::handleEvents()
{
	sf::Event e;
	while (window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window.close();
			break;
		case sf::Event::Resized:
			resetView();
			break;
		case sf::Event::LostFocus:
			TimeManager::pause();
			InputManager::onLoseFocus();
			break;
		case sf::Event::GainedFocus:
			InputManager::onGainFocus();
			break;
		case sf::Event::KeyPressed:
			InputManager::onKeyPressed(e.key);
			break;
		case sf::Event::KeyReleased:
			InputManager::onKeyReleased(e.key);
			break;
		case sf::Event::MouseWheelScrolled:
			InputManager::onMouseScroll(e.mouseWheelScroll);
			break;
		}
	}
}

void WindowManager::update()
{
	constexpr float minZoom = 10;
	constexpr float maxZoom = 100;
	constexpr float numZoomLevels = 20;
	const float zoomLevelFactor = std::pow(maxZoom / minZoom, 1.f / numZoomLevels);
	float zoomDelta = InputManager::getScrollDelta().y;
	targetZoom *= pow(zoomLevelFactor, -zoomDelta);
	targetZoom = clamp(targetZoom, minZoom, maxZoom);
	zoom = targetZoom * .2f + zoom * .8f;
	resetView();
}

void WindowManager::redraw()
{
	window.clear();
	Simulator::drawTo(window);
	window.display();
}

bool WindowManager::isOpen()
{
	return window.isOpen();
}

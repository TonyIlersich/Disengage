#pragma once

#include "includes.h"

class WindowManager
{
	static sf::RenderWindow window;
	static float zoom;
	static float targetZoom;

	static float getWindowAspect();
	static void resetView();

public:

	static void init();
	static void handleEvents();
	static void update();
	static void redraw();
	static bool isOpen();
};
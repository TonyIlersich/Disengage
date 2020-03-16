#pragma once

#include "includes.h"

class InputManager
{
public:

	enum InputMode
	{
		IN_MENU,
		IN_GAME
	};
	enum KeyName
	{
		NONE = -1,
		MOVE_UP = 0,
		MOVE_DOWN,
		MOVE_LEFT,
		MOVE_RIGHT,
		PAUSE,
		NUM_KEY_NAMES
	};
	enum KeyState
	{
		UP,
		PRESSED,
		DOWN,
		RELEASED
	};

private:

	static InputMode inputMode;
	static sf::Keyboard::Key keyBindings[KeyName::NUM_KEY_NAMES];
	static KeyState keyStates[KeyName::NUM_KEY_NAMES];
	static sf::Vector2f scrollDelta;

public:

	static void init();
	static void onFrameStart();
	static void onLoseFocus();
	static void onGainFocus();
	static void onKeyPressed(const sf::Event::KeyEvent& keyEvent);
	static void onKeyReleased(const sf::Event::KeyEvent& keyEvent);
	static void onMouseScroll(const sf::Event::MouseWheelScrollEvent& scrollEvent);
	static bool isKeyDown(KeyName keyName);
	static KeyState getKeyState(KeyName keyName);
	static sf::Vector2f getScrollDelta();
};
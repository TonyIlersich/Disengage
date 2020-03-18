#include "InputManager.h"

bool InputManager::hasFocus;
InputManager::InputMode InputManager::inputMode;
sf::Keyboard::Key InputManager::keyBindings[KeyName::NUM_KEY_NAMES];
InputManager::KeyState InputManager::keyStates[KeyName::NUM_KEY_NAMES];
sf::Vector2f InputManager::scrollDelta;

void InputManager::init()
{
	// default keybindings
	for (int i = 0; i < KeyName::NUM_KEY_NAMES; i++)
	{
		keyBindings[i] = sf::Keyboard::Unknown;
	}
	keyBindings[KeyName::MOVE_UP] = sf::Keyboard::W;
	keyBindings[KeyName::MOVE_DOWN] = sf::Keyboard::S;
	keyBindings[KeyName::MOVE_LEFT] = sf::Keyboard::A;
	keyBindings[KeyName::MOVE_RIGHT] = sf::Keyboard::D;
	keyBindings[KeyName::PAUSE] = sf::Keyboard::Escape;
	onLoseFocus();
	onGainFocus();
}

void InputManager::onFrameStart()
{
	for (int i = 0; i < KeyName::NUM_KEY_NAMES; i++)
	{
		switch (keyStates[i])
		{
		case KeyState::PRESSED:
			keyStates[i] = KeyState::DOWN;
			break;
		case KeyState::RELEASED:
			keyStates[i] = KeyState::UP;
			break;
		}
	}
	scrollDelta = sf::Vector2f(0.f, 0.f);
}

void InputManager::onLoseFocus()
{
	hasFocus = false;
	for (int i = 0; i < KeyName::NUM_KEY_NAMES; i++)
	{
		keyStates[i] = KeyState::UP;
	}
}

void InputManager::onGainFocus()
{
	hasFocus = true;
	for (int i = 0; i < KeyName::NUM_KEY_NAMES; i++)
	{
		if (isKeyDown((KeyName)i))
		{
			keyStates[i] = KeyState::DOWN;
		}
	}
}

void InputManager::onKeyPressed(const sf::Event::KeyEvent& keyEvent)
{
	if (!hasFocus) return;
	for (int i = 0; i < KeyName::NUM_KEY_NAMES; i++)
	{
		if (keyBindings[i] == keyEvent.code)
		{
			keyStates[i] = KeyState::PRESSED;
		}
	}
}

void InputManager::onKeyReleased(const sf::Event::KeyEvent& keyEvent)
{
	if (!hasFocus) return;
	for (int i = 0; i < KeyName::NUM_KEY_NAMES; i++)
	{
		if (keyBindings[i] == keyEvent.code)
		{
			keyStates[i] = KeyState::RELEASED;
		}
	}
}

void InputManager::onMouseScroll(const sf::Event::MouseWheelScrollEvent& scrollEvent)
{
	if (!hasFocus) return;
	switch (scrollEvent.wheel)
	{
	case sf::Mouse::HorizontalWheel:
		scrollDelta.x += scrollEvent.delta;
		break;
	case sf::Mouse::VerticalWheel:
		scrollDelta.y += scrollEvent.delta;
		break;
	}
}

bool InputManager::isKeyDown(KeyName keyName)
{
	return hasFocus && sf::Keyboard::isKeyPressed(keyBindings[keyName]);
}

InputManager::KeyState InputManager::getKeyState(KeyName keyName)
{
	return hasFocus ? KeyState::UP : keyStates[keyName];
}

sf::Vector2f InputManager::getScrollDelta()
{
	return scrollDelta;
}

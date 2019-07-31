#include "pch.h"
#include "InputManager.h"


InputManager* InputManager::m_Instance;
InputManager::InputManager()
{
}

InputManager* InputManager::GetInstance()
{
	if (m_Instance == nullptr)
	{
		m_Instance = new InputManager();
	}

	return m_Instance;
}

bool InputManager::ButtonPressed()
{
	return m_ButtonPressed;
}


void InputManager::Input()
{
	if (_kbhit()) {
		m_ButtonPressed = _getch();
	}
	else
		m_ButtonPressed = 0;
}

Key InputManager::GetButtonPressed()
{
	if (m_ButtonPressed == 0)
		return Key::Error;

	if (m_ButtonPressed == 'K') {
		return Key::Enter;
	}

	return Key::Any;
}

InputManager::~InputManager()
{
}



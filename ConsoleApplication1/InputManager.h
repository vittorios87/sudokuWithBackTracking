#pragma once
#include "Constants.h"

class InputManager
{
private:
	InputManager();
	static InputManager* m_Instance;
	unsigned char m_ButtonPressed;

public:
	static InputManager* GetInstance();
	bool ButtonPressed();
	Key GetButtonPressed();
	void Input();
	~InputManager();
};


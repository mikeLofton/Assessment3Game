#pragma once
#include "Component.h"
#include <raylib.h>
#include <Vector2.h>
class Bullet;

class InputComponent :
	public Component
{
public:
	/// <summary>
	/// InputComponent constructor
	/// </summary>
	/// <param name="name">Name of the input component</param>
	InputComponent(const char* name = "InputComponent") : Component::Component(name) {}

	/// <summary>
	/// The players input direction
	/// </summary>
	/// <returns>The x and y direction the player is moving</returns>
	MathLibrary::Vector2 getMoveAxis();
	bool checkActionKey();
	

private:
	//The shoot key
	RAYLIB_H::KeyboardKey m_action1Key = RAYLIB_H::KeyboardKey::KEY_SPACE;
	RAYLIB_H::KeyboardKey m_action2Key = RAYLIB_H::KeyboardKey::KEY_P;
	RAYLIB_H::KeyboardKey m_submitKey = RAYLIB_H::KeyboardKey::KEY_ENTER;
	RAYLIB_H::KeyboardKey m_cancelKey = RAYLIB_H::KeyboardKey::KEY_BACKSPACE;
};


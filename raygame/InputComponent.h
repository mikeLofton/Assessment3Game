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

	/// <summary>
	/// Checks to see if player pressed spacebar
	/// </summary>
	/// <returns>True if spacebar was pressed</returns>
	bool checkActionKey();
	

private:
	//The shoot key
	RAYLIB_H::KeyboardKey m_action1Key = RAYLIB_H::KeyboardKey::KEY_SPACE;
};


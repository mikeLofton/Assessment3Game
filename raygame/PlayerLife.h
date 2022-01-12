#pragma once
#include "Component.h"
class Lives;

class PlayerLife :
	public Component
{
public:
	/// <param name="name">Component's name</param>
	PlayerLife(const char* name = "PlayerLife") : Component::Component(name) {}

	/// <summary>
	/// Initializes the life actors an adds them to the scene
	/// </summary>
	void start() override;

	/// <summary>
	/// Removes life actor 1
	/// </summary>
	void removeLife1();

	/// <summary>
	/// Removes life actor 2
	/// </summary>
	void removeLife2();

	/// <summary>
	/// Removes life actor 3
	/// </summary>
	void removeLife3();

private:
	Lives* life1;
	Lives* life2;
	Lives* life3;
};

